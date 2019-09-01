#include "pda.h"

pda::pda(queue<MyStruct> &wordlist)
{
	this->wordlist= wordlist;

	wordconainer.word = "Bottom";
	wordconainer.attributes = BOTTOM_SYMBOL;
	pdaStack.push(wordconainer);

	wordconainer.word = "Statement";
	wordconainer.attributes = statement;
	pdaStack.push(wordconainer);

	state();
}

void pda::state()
{
	while (!wordlist.empty())
	{
		if (wordlist.front().attributes == newlineChar && pdaStack.top().attributes == statement)
		{
			wordlist.pop();
			continue;
		}

		if (wordlist.front().attributes == identifier && pdaStack.top().attributes == statement)
		{
			wordlist.pop();
			pdaStack.pop();
			wordconainer.word = "Assignment";
			wordconainer.attributes = assignment;
			pdaStack.push(wordconainer);
			continue;
		}

		if (wordlist.front().attributes == assignment && pdaStack.top().attributes == assignment)
		{
			wordlist.pop();
			pdaStack.pop();
			wordconainer.word = "Expression";
			wordconainer.attributes = expression;
			pdaStack.push(wordconainer);
			continue;
		}

		if (wordlist.front().attributes == identifier && pdaStack.top().attributes == expression)
		{
			wordlist.pop();
			pdaStack.pop();
			wordconainer.word = "Operation";
			wordconainer.attributes = operation;
			pdaStack.push(wordconainer);
			continue;
		}

		if (wordlist.front().attributes == integer && pdaStack.top().attributes == expression)
		{
			wordlist.pop();
			pdaStack.pop();
			wordconainer.word = "Operation";
			wordconainer.attributes = operation;
			pdaStack.push(wordconainer);
			continue;
		}

		if (wordlist.front().attributes == newlineChar && pdaStack.top().attributes == operation)
		{
			wordlist.pop();
			pdaStack.pop();
			wordconainer.word = "Statement";
			wordconainer.attributes = statement;
			pdaStack.push(wordconainer);
			continue;
		}

		if (wordlist.front().attributes == operation && pdaStack.top().attributes == operation)
		{
			wordlist.pop();
			pdaStack.pop();
			wordconainer.word = "Expression";
			wordconainer.attributes = expression;
			pdaStack.push(wordconainer);
			continue;
		}
		break;
	}
	pdaStack.pop();
	if (pdaStack.top().attributes == BOTTOM_SYMBOL)
	{
		accept();
	}
	else
		reject();
}

void pda::accept()
{
	while (!pdaStack.empty())
		pdaStack.pop();

	cout << "ACCEPTED\n";
}

void pda::reject()
{
	cout << "\nREJECTED. Compile Error.\n";
	cout << "Stack Dump:\n";
	while (!pdaStack.empty())
	{
		cout << pdaStack.top().word << "("
			<< pdaStack.top().attributes << ") : ";
		pdaStack.pop();
	}

	cout << "\n\nToken Queue Dump:\n";
	while (!wordlist.empty())
	{
		cout << wordlist.front().word << "("
			<< wordlist.front().attributes << ") : ";
		wordlist.pop();
	}

	//exit(2);
}
