#pragma once

#include <ctime>
#include <cstdlib>

int const MAXTIME = 30, MAXCPU = 20;		//можно регулировать, сколько максимум может быть процессоров в таске для выполнения и сколько оно будет выполняться

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
	bool operator<(const Task &_task) {		//необходимо для сортировки тасков по времени
		return ((_task.Time - _task.Tact) < (Time - Tact));
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
	Node *pFirst, *tail;
	int size;
public:
	TaskList() :							//конструктор по умолчанию
		pFirst(nullptr), tail(nullptr), size(0) {}
	
	~TaskList() {						//деструктор
		delete pFirst;
		delete tail;
	}

		void AddTask(const Task &_task) {		//добавить задачу в конец списка
												//... n hours later
												//допустим, что не в конец списка, а куда-то, сортируя по времени, необходимому на выполнение
												//тогда нужна функция сравнения времени переданного таска и того, что есть на данной позиции
			Node *p = new Node;					//создаем звено
			p->pNext = nullptr;					//делаем его последним
			p->data = _task;					//записываем для будущего сравнения
			if (size == 0) 						//если размер ноль
				pFirst = p;
			else {								//иначе
				Node *p1 = pFirst,
					 *p2 = nullptr;
				int i = 0;
				while (i < size) {				
					if (p->data < p1->data) {	//если меньше можем впихнуть
						if (p2 == nullptr)		
							pFirst = p;
						else
							p2->pNext = p;
						p->pNext = p1;
						break;
					}
					p2 = p1;
					p1 = p1->pNext;
					i++;
				}
				if (i == size)
					p2->pNext = p;
			}
			size++; 
			
		}
		void Done() {
		Node *p = pFirst;
		for (int i = 0; i < size; i++) {
			p->data.CountTact();
			p = p->pNext;
		}
		/*Node *p = pFirst;
		int i = 0;
		while (i < size - 1) {
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
