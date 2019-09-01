//********************************************************************************
//
//     Author:           Mojgan Mehrabi
//                       Compiler project dfa.cpp
//
//     Date Created:     03/25/2019
//     Date Completed:   08/30/2019
//
//     Description:      This is the object file for the DFA class. An object of
//                       this class is instantiated with a queue of chars as an
//                       argument.  The characters are assembled into strings and
//                       stored on a deque of structs  which hold
//                       the string and an enum attribute describing the word's
//                       type as an identifier, operation, integer, or statement.
//                       Statement represents the end of a line (the end of a
//                       statement line).
//
//     Sample Output:	 A reference to the deque<struct> wordlist
//                       object is returned using the getWordlist() method. 
//
//********************************************************************************

#ifndef PDA_H
#define PDA_h
#include<stack>
#include"dfa.h"

class pda
{
public:
	pda(queue<MyStruct> &wordlist);

private:
	void state();
	void accept();
	void reject();

	queue<MyStruct>wordlist;
	stack<MyStruct, list<MyStruct>> pdaStack;
	MyStruct wordconainer; 

};
#endif // !PDA_H

