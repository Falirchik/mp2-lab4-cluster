#pragma once

#include <iostream>

const int MAX_QUEUE_SIZE = 10000;

template<typename T>

class Queue{
	T *pQue;							//��������� �� �������
	int /*begin,*/
		end;							//����� �������
	int CElem;							//���������� �������� � �������
	int size;							//������ �������

public:
	Queue(int sz = 1):		//�����������-�������������
		end(-1),CElem(0)/*, pQue (new T[size])*/, size(sz){
		
		if ((size < 1) || (size > MAX_QUEUE_SIZE))
			throw "����� �� ����������� ������� �������";
		pQue = new T[size+1];		
	}
	
	//Queue(const Queue<T> &_queue) :		//����������� �����������
	//	size(_queue.size),/*, begin(_queue.begin),*/ end(_queue.end), CElem(_queue.Celem), pQue(new T[size + 1])
	//{									//�������� �������� �������
	//	for (int i = 0; i < size; i++)
	//		pQue[i] = _queue.pQue[i];
	//}

	~Queue() {							//����������
		delete[]pQue;
	}
	
	/*int getBegin()	{return begin;}*/
	int getEnd()	{return end;}
	int getCElem()	{return CElem;}
	int getSize()	{return size;}
	
	void addEnd(const T &elem) {		// �������� ������� � ����� �������
		if (isFull())					//�������� �� �������
			throw "��� �����";
		end = (end + 1) % size;			//������� �����
		pQue[end] = elem;				//���������� ������� � �����
		CElem++;						//��������� � ������� ���������� ���������
	}

	T PopLast() {
		/*int tmp = end - CElem + size+1;
		tmp %= size;*/
		return pQue[(end - CElem + size + 1) % size];
	}
	T Pop() {								//������ �� �������
		if (isEmpty())
			throw ("��� ��������");
		CElem--;							//��������� ���������� ���������
		int tmp = (size-CElem+end) % size;		
		return pQue[tmp];					//���������� 
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