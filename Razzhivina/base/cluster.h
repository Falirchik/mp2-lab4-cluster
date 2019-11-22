#pragma once

#include "queue.h"
#include "task.h"
#include "statistic.h"
#include <iostream>

using namespace std;

class Cluster {
	int proc;					//процессоры
	int freeproc;				//свободные поцессоры
	TaskList ExecutableTask;	//список выполненых задач
	Statistic st;				//статистика
	Queue <Task> queue;			//очередь из задач

public:
	Cluster(int _proc) {
		if (_proc <= 1)
			throw "малое количество процессоров";
		proc = _proc;
		freeproc = proc;		//так как только создали, то все процессоры свободные
	}
	void Print() {
		st.Print();
	}
	~Cluster() {				//а нужен ли...
		proc = 0;
		freeproc = 0;
	}

	void StartCluster(int _tact) {
		if (_tact < 1)
			throw "малое количество тактов";
		for (int i = 0; i < _tact; i++) {
			Task tmp;
			queue.addEnd(tmp);
			st.CreateTask();
			while (!queue.isEmpty()) {					//пока очередь не пуста
				Task tmp2 = queue.PopLast();			//
				if (tmp2.getCCPU() <= freeproc) {
					ExecutableTask.AddTask(tmp2);
					queue.PopFirst();
					freeproc = freeproc - tmp2.getCCPU();
				}
				else break;
			}
			ExecutableTask.Done();
			int i_tmp = ExecutableTask.NumberOfTask();
			i_tmp = i_tmp - ExecutableTask.PullExecutableTask();
			freeproc = freeproc + ExecutableTask.PullExecutableTask();
			st.AddDone(i_tmp);
			st.InQueue(queue.getCElem());					
			st.Average((proc - freeproc) / proc * 100);		//занятые процессоры/процессоры*100%
			st.AddTact();
		}
		
	}
};