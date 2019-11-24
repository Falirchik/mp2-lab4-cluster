#pragma once

#include "task.h"
#include <iostream>
using namespace std;

class Statistic {
	int CreatedTask,			//количество созданных задач
		ExecutableTask,			//выполненые задач
		TaskInQueue,			//в очереди
		tact;					//такт
	double AverageLoad;			//средняя загрузка кластера
public:
	
	Statistic():				//еонструктор по умолчанию
		CreatedTask(0),ExecutableTask(0),TaskInQueue(0),tact(0), AverageLoad(0){}
	
	void CreateTask() { CreatedTask++; }
	void ExecutionTask() { ExecutableTask++; }
	void AddDone(int count) {
		if (count < 0)
			throw "ошибка";
		ExecutableTask = ExecutableTask + count;
	}
	void AddTact() { tact++; }
	void InQueue(int count) {
		if (count < 0)
			throw "ошибка";
		TaskInQueue = count;
	}
	void Average(double count) {
		if (count < 0)
			throw "ошибка";
		AverageLoad = AverageLoad + count;
	}
	void Print() {
<<<<<<< HEAD
		cout << "\t СТАТИСТИКА";
=======
		cout << "\t СТАТИСТИКА" << endl;
>>>>>>> lab4.0
		cout << "Завершенных задач: \t" << ExecutableTask << endl;
		cout << "Cозданных задач: \t" << CreatedTask << endl;
		cout << "Задачи в очереди: \t" << TaskInQueue << endl;
		cout << "Средняя загрузка кластера: \t" << AverageLoad/tact << endl;
	}

};