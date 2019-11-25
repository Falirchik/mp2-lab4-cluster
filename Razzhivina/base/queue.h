#pragma once

#include <iostream>

const int MAX_QUEUE_SIZE = 10000;

template<typename T>

class Queue{
	T *pQue;							//указатель на очередь
	int /*begin,*/
		end;							//конец очереди
	int CElem;							//количество элеметов в очереди
	int size;							//размер очереди

public:
	Queue(int sz = 1):		//конструктор-инициализатор
		end(-1),CElem(0)/*, pQue (new T[size])*/, size(sz){
		
		if ((size < 1) || (size > MAX_QUEUE_SIZE))
			throw "выход за позволенные размеры очереди";
		pQue = new T[size+1];		
	}
	
	//Queue(const Queue<T> &_queue) :		//конструктор копирования
	//	size(_queue.size),/*, begin(_queue.begin),*/ end(_queue.end), CElem(_queue.Celem), pQue(new T[size + 1])
	//{									//копируем элементы очереди
	//	for (int i = 0; i < size; i++)
	//		pQue[i] = _queue.pQue[i];
	//}

	~Queue() {							//деструктор
		delete[]pQue;
	}
	
	/*int getBegin()	{return begin;}*/
	int getEnd()	{return end;}
	int getCElem()	{return CElem;}
	int getSize()	{return size;}
	
	void addEnd(const T &elem) {		// добавить элемент в конец очереди
		if (isFull())					//проверка на полноту
			throw "нет места";
		end = (end + 1) % size;			//смещаем конец
		pQue[end] = elem;				//записываем элемент в конец
		CElem++;						//добавляем в счетчик количества элементов
	}

	T PopLast() {
		/*int tmp = end - CElem + size+1;
		tmp %= size;*/
		return pQue[(end - CElem + size + 1) % size];
	}
	T Pop() {								//взятие из очереди
		if (isEmpty())
			throw ("нет элеметов");
		CElem--;							//уменьшаем количество элементов
		int tmp = (size-CElem+end) % size;		
		return pQue[tmp];					//возвращаем 
	}

	//void printQueue() {					//вывод очереди
	//	cout << "Очередь: ";
	//	if (end == 0 && begin == 0)
	//		cout << " пустая\n";
	//	else {
	//		for (int i = end; i >= begin; i--)
	//			cout << queuePtr[ix] << " ";
	//		cout << endl;
	//	}
	//}

	bool isFull() {
	/*	if (CElem != size)
			return false;
		else return true;*/
		return CElem == size;
	}
	bool isEmpty() {
		/*if (CElem > 0)
			return false;
		else return true;*/
		return CElem == 0;
	}
};