/*
 * SqStack.h
 *
 *  Created on: 2018年4月18日
 *      Author: Admin
 */

#ifndef SQSTACK_H_
#define SQSTACK_H_

//顺序栈数据结构
#include<stdlib.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

template <class T>class SqStack {
public:
	SqStack(){
		initStack();
	};
	virtual ~SqStack(){
		delete base;
		delete top;
	};
	void push(T a){
		if(top-base>=stacksize){
			base=(T *)realloc(base,(stacksize+STACKINCREMENT)*sizeof(T));
			if(!base) exit(0);
			top=base+stacksize;
			stacksize+=STACKINCREMENT;
		}
		*top++=a;
	};
	T pop(){
		if(top==base){
			exit(0);
		}
		return *--top;
	};
	T getTop(){
		if(top>base)
			return *(top-1);
		else
			return 0;
	};
	void initStack(){
		base=(T *)malloc(STACK_INIT_SIZE*sizeof(T));
		if(!base)
			exit(0);
		top=base;
		stacksize=STACK_INIT_SIZE;
	};
	bool stackEmpty(){
		if(base==top)
			return true;
		else
			return false;
	}
private:
	T *base;
	T *top;
	int stacksize;
};

#endif /* SQSTACK_H_ */

