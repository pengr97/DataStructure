/*
 * LinkQueue.h
 *
 *  Created on: 2018��4��18��
 *      Author: Admin
 */

#ifndef LINKQUEUE_H_
#define LINKQUEUE_H_

//�������ݽṹ
#include<stdlib.h>

template <class T>class LinkQueue {
public:
	LinkQueue(){
		InitQueue();
	};
	virtual ~LinkQueue(){};
	void InitQueue(){
		front=new QNode;
		rear=front;
		front->next=NULL;
	};
	void EnQueue(T value){
		QNode *n=new QNode;
		n->data=value;
		n->next=NULL;
		rear->next=n;
		rear=n;
	}
	T DeQueue(){
		if(front==rear)
			exit(0);
		QNode *n=new QNode;
		T e;
		n=front->next;
		e=n->data;
		front->next=n->next;
		if(rear==n)
			rear=front;
		delete n;
		return e;
	}
	bool QueueEmpty(){
		if(front==rear)
			return true;
		else
			return false;
	}
private:
	struct QNode{
		T data;
		QNode *next;
	};
	QNode *front;
	QNode *rear;
};

#endif /* LINKQUEUE_H_ */
