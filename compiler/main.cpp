//********************************************************************************
//
//     Author:           Mojgan Mehrabi
//                       Compiler Project main.cpp
//
//     Date Created:     03/25/2019 
//     Date Completed:   08/30/ 2019
//
//     Description:      This program reads a text file and outputs whether the
//                       text conforms to a particular language.  A DFA object
//                       scans the input from a queue of characters and produces
//                       a token list.  A PDA object parses the token list and
//                       determines whether the text conforms to the langauge.
//
//     Sample Input:     larry = 27
//                       curly = 19
//                       moe = 8
//                       groucho = 11
//                       harpo = larry + curly
//                       harpo = larry - curly
//						 harpo = larry*curly
//						 harpo = larry / curly
//						 harpo = larry*curly + moe*groucho
//
//     Input Notes:      White space is truncated.
//
//                       Foo 32 = 33    is queued as Foo32=33
//                       Foo Bar  = 3 3 is queued as FooBar=33
//
//     Sample Output:	 ACCEPTED
//
//********************************************************************************


#include<iostream>
#include<string>
#include"dfa.h"
#include"pda.h"
#include<queue>
#include<deque>
#include<list>
#include<fstream>

using namespace std;
const string input_file = "Input.txt";

int main() {

	queue<char, list<char>> queueInstance;

	ifstream file;
	string tempstr;

	file.open("Input.txt");

	if (!file) 
	{
		cout << " Cannot open" << input_file << endl;
		exit(1);
	}
	while (file.peek() != EOF)
	{
		getline(file, tempstr);

		// Each char on a line of the input file is read and 
		// pushed into a queue.
		for (int i = 0; i < tempstr.length(); ++i)
		{
			// Spaces are truncated.
			if (tempstr[i] == ' ')
				continue;
			queueInstance.push(i);
		}
		// '\n' marks the end of each statement line.
		// PDA will expect a newline token to close each
		// statement
		queueInstance.push('/n');
	}
	file.close();
	dfa labeling(queueInstance);

}