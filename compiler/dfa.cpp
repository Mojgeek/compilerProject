#include "dfa.h"
#include<fstream>
#include<queue>
#include<list>
#include<string>
using namespace std;

dfa::dfa(string myfile)
{
	ifstream fin;
	fin.open(myfile);
	string myLine;
	string wordBuild = "";

	if (!fin)
	{
		throw logic_error("Cannot open input file.\n");
	}

	while (fin.peek() != EOF) {
		getline(fin, myLine);
		
		for (int i = 0; i < myLine.length(); i++) {
			if (wordBuild.empty() && myLine[i] == '=') {
				assignmentType(wordBuild);
				wordBuild = "";
			}
			else if (wordBuild.empty() && myLine[i] == '*') {
				operationType(wordBuild);
				wordBuild = "";
			}
			else if (wordBuild.empty() && myLine[i] == '/') {
				operationType(wordBuild);
				wordBuild = "";
			}
			else if (wordBuild.empty() && myLine[i] == '+') {
				operationType(wordBuild);
				wordBuild = "";
			}
			else if (isalpha(myLine[i]) || isdigit(myLine[i])) {
				wordBuild.append(myLine, i, 1);
				continue;
			}
			else if (myLine[i] == ' ') {
				myLine = "";
				continue;
			}
			else if (myLine[i] == '\n') {
				newline_characterType(wordBuild);
				wordBuild = "";
			}

			else
				trapState();
		}




		}

	}


}
