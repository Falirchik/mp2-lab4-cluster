#pragma once

#include "queue.h"
#include "task.h"
#include "statistic.h"
#include <iostream>

using namespace std;
const int  MAX_CPU_SIZE_FOR_CLUSTER = 100;

class Cluster {
	int proc;					//процессоры
	int freeproc;				//свободные поцессоры
	TaskList ExecutableTask;	//список выполненых задач
	Statistic st;				//статистика
	Queue <Task> queue;			//очередь из задач

public:
	Cluster(int _proc):queue(MAX_QUEUE_SIZE),proc(_proc), freeproc(_proc){
		if ((_proc < 1) || (_proc > MAX_CPU_SIZE_FOR_CLUSTER))
			throw "ќтрицательное или слишком большое количество процессоров";
	}
	~Cluster() {				//а нужен ли...
		proc = 0;
		freeproc = 0;
	}
	
	void PrintStatistic() {
		st.Print();
	}
	void StartCluster(int _tact = 1) {
		if (_tact < 1)
			throw "ошибка запуска кластера";
		for (int i = 0; i < _tact; i++) {
			Task tmp;									//создаем задачу
			queue.addEnd(tmp);							//добавл€ем ее в очередь
			st.CreateTask();							//+1 в статистике к созданным задачам
			while (!queue.isEmpty()) {					//пока очередь не пуста
				Task tmp2 = queue.PopLast();				//создаем задачу, вз€в ее из очереди
				if (tmp2.getCCPU() > freeproc)	break;		//если необходимое количество процессоров больше - пропускаем
				else {										//иначе

					ExecutableTask.AddTask(tmp2);			//список выполненых задач - добавить. ѕроблема. ѕересмотреть метод
					queue.Pop();
					freeproc = freeproc - tmp2.getCCPU();
				}
			}
			ExecutableTask.Done();
			int i_tmp = ExecutableTask.NumberOfTask();
			freeproc = freeproc + ExecutableTask.PullExecutableTask();
			i_tmp = i_tmp - ExecutableTask.NumberOfTask();
			st.AddDone(i_tmp);
			st.InQueue(queue.getCElem());					
			st.Average((proc - freeproc) / proc * 100);		//зан€тые процессоры/процессоры*100%
			st.AddTact();
		}
	}
};