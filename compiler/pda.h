#ifndef PDA_H
#define PDA_h
#include<iostream>
#include<string>
#include<stack>
#include<deque>
#include"dfa.h"

class pda
{
public:
	pda(deque<MyStruct> &wordlist);

private:
	void state();
	void accept();
	void reject();

	deque<MyStruct>*pointerToWordlist;
	stack<MyStruct> pdaStack;
	MyStruct wordconainer; 




};
#endif // !PDA_H

