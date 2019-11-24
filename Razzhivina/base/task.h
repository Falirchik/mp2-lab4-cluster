#pragma once

#include <ctime>
#include <cstdlib>

int const MAXTIME = 30, MAXCPU = 30;

class Task{
	int Time,				//время на выполнение
		CCPU,				//необходимое количество процессоров
		Tact;				//такт начала выполнения
public:
	Task(){
		Time = 1 + rand() % MAXTIME;
		CCPU = 1 + rand() % MAXCPU;
		Tact = 0;
	}
	~Task() {				//деструктор
		Time = 0; Tact = 0; CCPU = 0;
	}

	int getTime() { return Time; }
	int getCCPU() { return CCPU; }

	void setTact(int _tact){ Tact = _tact; }
	void CountTact() { Tact++; }

	bool IsDone() {
		int tmp = Time - Tact;
		return (0 >= tmp);
	}


	//Task& operator=(const Task & tTask) {
	//	if (this != &tTask) {
	//		/*ID = tTask.ID;*/
	//		Time = tTask.Time;
	//		CCPU = tTask.CCPU;
	//		Tact = tTask.Tact;
	//	}
	//	return *this;
	//}


};

struct Node {
	Task data;							//данные
	Node *pNext;						//указатель на следующий
};

class TaskList {
	Node *pFirst;
	int size;
public:
	TaskList() :							//конструктор по умолчанию
		pFirst(nullptr), size(0) {}
	
	~TaskList() {Node *p = pFirst;						//деструктор
		while (pFirst != nullptr) {
			
			pFirst = p->pNext;
			delete p;
		}
	}
	void AddTask(const Task &_task) {		//добавить задачу в конец списка
		
	/*	Node *p = pFirst;
		if (pFirst) {
			while (p->pNext)
				p = p->pNext;
			p->pNext = new Node;
			p->data = _task;
		}
		else pFirst = new Node;*/
											
		Node *p = new Node;
		p->data = _task;
		p->pNext = nullptr;
		if (size != 0){
			int i = 0;
			Node *p1 = pFirst;
			Node *p2 = nullptr;
			for (i = 0; i < size; i++)	{
				if (p2 != nullptr)
					p2->pNext = p;
				else
					pFirst = p;
				p->pNext = p1;

				p2 = p1;
				p1 = p1->pNext;
			}
			if (i == size)
				p2->pNext = p;
		}
		else pFirst = p;
		size++;

		/*Node *p = pFirst;
		if (pFirst) {
			while (p->pNext)
				p = p->pNext;
			p->pNext = new Node;
			p->data = _task;
		}
		else {
			pFirst = new Node;
			p = pFirst;
			p->pNext = nullptr;
			p->data = _task;
		}*/
										
		/*Node *p = pFirst;
		while (p->pNext != nullptr)
			p = p->pNext;
		p->pNext = new Node;
		p->pNext->data = _task;
		p->pNext->pNext = nullptr;
		size++;*/
	}

	void Done() {
		Node *p = pFirst;
		for (int i = 0; i < size; i++) {
			p->data.CountTact();
			p = p->pNext;
		}
		/*int i = 0;
		while (i<size-1) {
			p->data.CountTact();
			p = p->pNext;
			i++;
		}*/
	}

	int NumberOfTask() { return size; }

	//bool isFull() {
	//	Node *p = new Node;
	//	if (p == nullptr)
	//		return true;
	//	else {
	//		delete p;
	//		return false;
	//	}
	//}

	//bool isEmpty() { return !pFirst; }

	int PullExecutableTask() {
		int count = 0,
			sz = size; /*,
			i = 0*/
		/*while (i <= sz) {
			Node *p = pFirst;
			if (p->data.IsDone()) {
				count = count + p->data.getCCPU();
				pFirst = p->pNext;
				delete p;
				i--;
			}
			else break;
		}*/
		for (int i = 0; i < sz; i++) {
			Node *p = pFirst;
			if (p->data.IsDone()) {		
				size--;
				count = count + p->data.getCCPU();
				pFirst = p->pNext;
				
				delete p;
			}
			else break;
		}
		return count;
	}

};
