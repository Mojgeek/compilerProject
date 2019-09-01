//********************************************************************************
//
//     Author:           Mojgan Mehrabi
//                       Compiler project dfa.h
//
//     Date Created:     03/25/2019
//     Date Completed:   08/30/2019
//
//     Description:      This is the header file for the DFA class.  An object of
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

#ifndef DFA_H
#define DFA_H

#include <iostream>
#include<queue>
#include<list>
#include<string>

using namespace std;

const int Max_Word = 12; // max length of identifier
const int Max_Digits = 12; // max length of integer

//  The DFA object assigns the attributes identifier, operation, integer,
//  newline, and assign.  The other attributes are used by the PDA object.

enum types {
	identifier, integer, assignment , operation , newlineChar, factor , expression, statement, BOTTOM_SYMBOL
};
// The tokens to be pushed and popped from the deque are of the type MyStruct
// and store both the token and its described enum attribute.
struct MyStruct
{
	string word;
	types attributes;	

};

class dfa 
{
public:
	// Constructor
	// The Constructor reads the front char from input and passes input
	// to the relevant state to have its type assigned and pushed onto tokenList.
	// it reads every character in the character queue to label it, sending it off to the states to finish labaeling.
	dfa(queue<char, list<char>> &input); 
	
	// getwordlist method
	// returns a reference to the wordlist deque
	queue<MyStruct> &getWordlist();
	bool getIsTrap() const;

private:
	void state1(queue<char, list<char>> &input); // accepts identifiers
	void state2(queue<char, list<char>> &input); // accepts operations
	void state3(queue<char, list<char>> &input); // accepts integers
	void state4(queue<char, list<char>> &input); // accepts new line characters
	void state5(queue<char, list<char>> &input); // accepts assignment operator
	void trap(queue<char, list<char>> &input);
	bool isTrap;
	
	queue<MyStruct> wordlist; 
	MyStruct wordcontainer; // temporary holding struct to be pushed in to the deque
	string temp;
};





#endif // !DFA_H

