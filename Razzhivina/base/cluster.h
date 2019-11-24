#pragma once

#include "queue.h"
#include "task.h"
#include "statistic.h"
#include <iostream>

using namespace std;

<<<<<<< HEAD
=======
const int MAX_CPU_SIZE = 1000;

>>>>>>> lab4.0
class Cluster {
	int proc;					//����������
	int freeproc;				//��������� ���������
	TaskList ExecutableTask;	//������ ���������� �����
	Statistic st;				//����������
	Queue <Task> queue;			//������� �� �����

public:
<<<<<<< HEAD
	Cluster(int _proc) {
		if (_proc <= 1)
			throw "����� ���������� �����������";
		proc = _proc;
		freeproc = proc;		//��� ��� ������ �������, �� ��� ���������� ���������
	}
	void Print() {
		st.Print();
=======
	Cluster(int _proc = 1):queue(MAX_QUEUE_SIZE){
		if ((_proc < 1) || (_proc > MAX_CPU_SIZE))
			throw "������";
		proc = _proc;
		freeproc = _proc;		//��� ��� ������ �������, �� ��� ���������� ���������
		
>>>>>>> lab4.0
	}
	~Cluster() {				//� ����� ��...
		proc = 0;
		freeproc = 0;
	}
<<<<<<< HEAD

=======
	
	void PrintStatistic() {
		st.Print();
	}
>>>>>>> lab4.0
	void StartCluster(int _tact) {
		if (_tact < 1)
			throw "����� ���������� ������";
		for (int i = 0; i < _tact; i++) {
			Task tmp;
			queue.addEnd(tmp);
			st.CreateTask();
			while (!queue.isEmpty()) {					//���� ������� �� �����
				Task tmp2 = queue.PopLast();			//
				if (tmp2.getCCPU() <= freeproc) {
					ExecutableTask.AddTask(tmp2);
<<<<<<< HEAD
					queue.PopFirst();
=======
					queue.Pop();
>>>>>>> lab4.0
					freeproc = freeproc - tmp2.getCCPU();
				}
				else break;
			}
			ExecutableTask.Done();
			int i_tmp = ExecutableTask.NumberOfTask();
<<<<<<< HEAD
			i_tmp = i_tmp - ExecutableTask.PullExecutableTask();
			freeproc = freeproc + ExecutableTask.PullExecutableTask();
=======
			freeproc = freeproc + ExecutableTask.PullExecutableTask();
			i_tmp = i_tmp - ExecutableTask.NumberOfTask();
>>>>>>> lab4.0
			st.AddDone(i_tmp);
			st.InQueue(queue.getCElem());					
			st.Average((proc - freeproc) / proc * 100);		//������� ����������/����������*100%
			st.AddTact();
		}
<<<<<<< HEAD
		
=======
>>>>>>> lab4.0
	}
};