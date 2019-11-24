#pragma once

#include <iostream>

const int MAX_QUEUE_SIZE = 1000;

template<typename T>
class Queue{
	T *pQue;							//указатель на очередь
<<<<<<< HEAD
	int begin,							//начало очереди
=======
	int /*begin,*/
>>>>>>> lab4.0
		end;							//конец очереди
	int CElem;							//количество элеметов в очереди
	int size;							//размер очереди

public:
<<<<<<< HEAD
	Queue(int sz = MAX_QUEUE_SIZE):		//конструктор-инициализатор
		begin(0),end(0),CElem(0), pQue (new T[size]){
		if ((sz <= 1) || (sz > MAX_QUEUE_SIZE))
			throw "выход за позволенные размеры очереди";
		else size = sz;
		pQue = new T[size + 1];			//доп позиция для различия конца  и начала очереди
	}
	Queue(const Queue<T> &_queue) :		//конструктор копирования
		size(_queue.size), begin(_queue.begin), end(_queue.end), CElem(_queue.Celem), pQue(new T[size + 1])
	{									//копируем элементы очереди
		for (int i = 0; i < size; i++)
			pQue[i] = _queue.pQue[i];
	}
=======
	Queue(int sz = 1):		//конструктор-инициализатор
		end(-1),CElem(0)/* pQue (new T[size]), size(0)*/{
		size = sz;
		if ((size < 1) || (size > MAX_QUEUE_SIZE))
			throw "выход за позволенные размеры очереди";
		pQue = new T[size];			
	}
	
	//Queue(const Queue<T> &_queue) :		//конструктор копирования
	//	size(_queue.size),/*, begin(_queue.begin),*/ end(_queue.end), CElem(_queue.Celem), pQue(new T[size + 1])
	//{									//копируем элементы очереди
	//	for (int i = 0; i < size; i++)
	//		pQue[i] = _queue.pQue[i];
	//}

>>>>>>> lab4.0
	~Queue() {							//деструктор
		delete[]pQue;
	}
	
<<<<<<< HEAD
	int getBegin()	{return begin;}
=======
	/*int getBegin()	{return begin;}*/
>>>>>>> lab4.0
	int getEnd()	{return end;}
	int getCElem()	{return CElem;}
	int getSize()	{return size;}
	
	void addEnd(const T &elem) {		// добавить элемент в конец очереди
		if (isFull())					//проверка на полноту
<<<<<<< HEAD
			throw ("нет места");
		end =(end +1) % size;			//смещаем конец
=======
			throw "нет места";
		end = (end + 1) % size;			//смещаем конец
>>>>>>> lab4.0
		pQue[end] = elem;				//записываем элемент в конец
		CElem++;						//добавляем в счетчик количества элементов
	}

	T PopLast() {
<<<<<<< HEAD
		int tmp = end - CElem + size;
		tmp %= size;
		return pQue[tmp];
	}

	T PopFirst() {						//взятие из очереди
		if (isEmpty())
			throw ("нет элеметов");
		int actual = begin;				//запоминаем начало
		CElem--;						//уменьшаем количество элементов
		begin = (begin + 1) % size;		//смещаем начало
		return pQue[actual];			//возвращаем 
=======
		/*int tmp = end - CElem + size+1;
		tmp %= size;*/
		return pQue[(end - CElem + size + 1) % size];
	}
	T Pop() {								//взятие из очереди
		if (isEmpty())
			throw ("нет элеметов");
		CElem--;							//уменьшаем количество элементов
		int tmp = (end+size-CElem) % size;		
		return pQue[tmp];					//возвращаем 
>>>>>>> lab4.0
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
<<<<<<< HEAD
	bool isFull() {
		if (CElem != size)
			return false;
		else return true;
	}
	bool isEmpty() {
		if (CElem > 0)
			return false;
		else return true;
=======

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
>>>>>>> lab4.0
	}
};