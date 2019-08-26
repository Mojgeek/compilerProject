#include "pda.h"

pda::pda(deque<MyStruct>& wordlist)
{
	pointerToWordlist = &wordlist;

	wordconainer.word = "Bottom";
	wordconainer.attributes = BOTTOM_SYMBOL;
	pdaStack.push()
}
