#pragma once

#include "queue.h"
#include "task.h"
#include "statistic.h"
#include <iostream>

using namespace std;
const int  MAX_CPU_SIZE_FOR_CLUSTER = 100;

class Cluster {
	int proc;					//����������
	int freeproc;				//��������� ���������
	TaskList ExecutableTask;	//������ ���������� �����
	Statistic st;				//����������
	Queue <Task> queue;			//������� �� �����

public:
	Cluster(int _proc):queue(MAX_QUEUE_SIZE),proc(_proc), freeproc(_proc){
		if ((_proc < 1) || (_proc > MAX_CPU_SIZE_FOR_CLUSTER))
			throw "������������� ��� ������� ������� ���������� �����������";
	}
	~Cluster() {				//� ����� ��...
		proc = 0;
		freeproc = 0;
	}
	
	void PrintStatistic() {
		st.Print();
	}
	void StartCluster(int _tact = 1) {
		if (_tact < 1)
			throw "������ ������� ��������";
		for (int i = 0; i < _tact; i++) {
			Task tmp;									//������� ������
			queue.addEnd(tmp);							//��������� �� � �������
			st.CreateTask();							//+1 � ���������� � ��������� �������
			while (!queue.isEmpty()) {					//���� ������� �� �����
				Task tmp2 = queue.PopLast();				//������� ������, ���� �� �� �������
				if (tmp2.getCCPU() > freeproc)	break;		//���� ����������� ���������� ����������� ������ - ����������
				else {										//�����

					ExecutableTask.AddTask(tmp2);			//������ ���������� ����� - ��������. ��������. ������������ �����
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
			st.Average((proc - freeproc) / proc * 100);		//������� ����������/����������*100%
			st.AddTact();
		}
	}
};