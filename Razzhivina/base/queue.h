#pragma once

#include <iostream>

const int MAX_QUEUE_SIZE = 1000;

template<typename T>
class Queue{
	T *pQue;							//��������� �� �������
<<<<<<< HEAD
	int begin,							//������ �������
=======
	int /*begin,*/
>>>>>>> lab4.0
		end;							//����� �������
	int CElem;							//���������� �������� � �������
	int size;							//������ �������

public:
<<<<<<< HEAD
	Queue(int sz = MAX_QUEUE_SIZE):		//�����������-�������������
		begin(0),end(0),CElem(0), pQue (new T[size]){
		if ((sz <= 1) || (sz > MAX_QUEUE_SIZE))
			throw "����� �� ����������� ������� �������";
		else size = sz;
		pQue = new T[size + 1];			//��� ������� ��� �������� �����  � ������ �������
	}
	Queue(const Queue<T> &_queue) :		//����������� �����������
		size(_queue.size), begin(_queue.begin), end(_queue.end), CElem(_queue.Celem), pQue(new T[size + 1])
	{									//�������� �������� �������
		for (int i = 0; i < size; i++)
			pQue[i] = _queue.pQue[i];
	}
=======
	Queue(int sz = 1):		//�����������-�������������
		end(-1),CElem(0)/* pQue (new T[size]), size(0)*/{
		size = sz;
		if ((size < 1) || (size > MAX_QUEUE_SIZE))
			throw "����� �� ����������� ������� �������";
		pQue = new T[size];			
	}
	
	//Queue(const Queue<T> &_queue) :		//����������� �����������
	//	size(_queue.size),/*, begin(_queue.begin),*/ end(_queue.end), CElem(_queue.Celem), pQue(new T[size + 1])
	//{									//�������� �������� �������
	//	for (int i = 0; i < size; i++)
	//		pQue[i] = _queue.pQue[i];
	//}

>>>>>>> lab4.0
	~Queue() {							//����������
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
	
	void addEnd(const T &elem) {		// �������� ������� � ����� �������
		if (isFull())					//�������� �� �������
<<<<<<< HEAD
			throw ("��� �����");
		end =(end +1) % size;			//������� �����
=======
			throw "��� �����";
		end = (end + 1) % size;			//������� �����
>>>>>>> lab4.0
		pQue[end] = elem;				//���������� ������� � �����
		CElem++;						//��������� � ������� ���������� ���������
	}

	T PopLast() {
<<<<<<< HEAD
		int tmp = end - CElem + size;
		tmp %= size;
		return pQue[tmp];
	}

	T PopFirst() {						//������ �� �������
		if (isEmpty())
			throw ("��� ��������");
		int actual = begin;				//���������� ������
		CElem--;						//��������� ���������� ���������
		begin = (begin + 1) % size;		//������� ������
		return pQue[actual];			//���������� 
=======
		/*int tmp = end - CElem + size+1;
		tmp %= size;*/
		return pQue[(end - CElem + size + 1) % size];
	}
	T Pop() {								//������ �� �������
		if (isEmpty())
			throw ("��� ��������");
		CElem--;							//��������� ���������� ���������
		int tmp = (end+size-CElem) % size;		
		return pQue[tmp];					//���������� 
>>>>>>> lab4.0
	}

	//void printQueue() {					//����� �������
	//	cout << "�������: ";
	//	if (end == 0 && begin == 0)
	//		cout << " ������\n";
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