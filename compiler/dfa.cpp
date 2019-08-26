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

#include "dfa.h"
#include<iostream>
#include<queue>
#include<list>
#include<string>
using namespace std;

dfa::dfa(std::queue<char, list<char>>& input)
{
	pointerToQueue = &input;
	while (!input.empty) {
		wordcontainer.word = " ";
		if (isalpha(input.front()))
			state1();
		else if (isdigit(input.front()))
			state3();
		else if (input.front() == '/n')
			state4();
		else if (input.front() == '=')
			state5();
		else
		{
			switch (input.front())
			{
			case '+':
			case '-':
			case '/':
			case '*':
				state2();
				break;
			default:
				trap();

			}
		}

	}
}

deque<MyStruct> dfa::getWordlist()
{
	return wordlist;
}

// state1() 
// Aaccepts identifiers up to the max length defined in the .h file const.
// The struct containing the token and enum identifier are pushed onto wordlist.

void dfa::state1()
{
	for (int i = 0; i < Max_Word && (isalpha((*pointerToQueue).front()) || (isdigit((*pointerToQueue).front()))); ++i)
	{
		temp = (*pointerToQueue).front();
		wordcontainer.word.append(temp);
		(*pointerToQueue).pop();
	}
	wordcontainer.attributes = identifier;
	wordlist.push_back(wordcontainer);
}

//state2()
// Accepts the operators +, -, *, /
// The struct containing the token and enum integer are pushed onto wordlist.

void dfa::state2()
{
	temp = (*pointerToQueue).front();
	wordcontainer.word.append(temp);
	wordcontainer.attributes = operation;
	wordlist.push_back(wordcontainer);
	(*pointerToQueue).pop();

}

//state3()
// Accepts integers up to the max length defined in the .h file const.
// The struct containing the token and enum operation are pushed onto wordlist.
void dfa::state3()
{
	for (int i = 0; i < Max_Digits && (isdigit((*pointerToQueue).front())); ++i)
	{
		temp = (*pointerToQueue).front();
		wordcontainer.word.append(temp);
		(*pointerToQueue).pop();

    }
	wordcontainer.attributes = integer;
	wordlist.push_back(wordcontainer);
}

//state4()
// Accepts the new line character '\n', marking the end of a statement line.
// The struct containing the token and enum newline are pushed onto wordlist.

void dfa::state4()
{
	temp = (*pointerToQueue).front();
	wordcontainer.word.append(temp);
	wordcontainer.attributes = newlineChar;
	wordlist.push_back(wordcontainer);
	(*pointerToQueue).pop();
	
}

//state5()
// Aaccepts the assignment character '='.
// The struct containing the token and enum assign are pushed onto wordlist.

void dfa::state5()
{
	temp = (*pointerToQueue).front();
	wordcontainer.word.append(temp);
	wordcontainer.attributes = assignment;
	wordlist.push_back(wordcontainer);
	(*pointerToQueue).pop();

	
}

// trap()
// When a disallowed character is read from input, this method
// outputs the rest of the queue to screen and exits.

void dfa::trap()
{
	cout << "Character not allowed" << endl;
	while (!(*pointerToQueue).empty())
	{
		cout << (*pointerToQueue).front();
		(*pointerToQueue).pop();
	}
	cout << endl;
	exit(1);
}
