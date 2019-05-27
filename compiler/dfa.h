#ifndef DFA_H
#define DFA_H

#include<queue>
#include<list>
#include<string>
using namespace std;

enum types {
	variable, operation, value, program , assignment, expression, BOTTOM_SYMBOL , newline_character
};
struct MyStruct
{
	string word;
	types attributes;	

};

class dfa 
{
public:
	dfa(string myfile = "input.txt");
	void variableType();
	void operationType();
	void valueType();
	void programType();
	void assignmentType();
	void newline_characterType();





private:
	MyStruct tempLabel;
	queue<MyStruct> container;


	




};





#endif // !DFA_H

