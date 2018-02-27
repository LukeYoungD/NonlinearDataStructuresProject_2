/* Luke Young
** 2017-11-08 12:46
** Post Fix Op with Tree
** EECS 2510 Non-Linear Data Structures
** Dr. CarvalO              
*/

#include "stdafx.h"
#include <stack>
#include <fstream>
#include <iostream>
#include <string>
#include "tree.h"

using namespace std;

int main()
{
	stack <char> stack1, stack2;
	//char current;
	string testStr, fileName, input, post;
	tree* testTree;
	int output;

	//functions
	string readFile(string fileName);
	string convertNotation(string infix, stack <char> s1, stack <char> s2);
	bool isOp(char name);

	cout << "What file would you like to read?\n"; //prompt file name
	cout << "format is 'example.txt'\n";
	cin >> fileName;

	input = readFile(fileName);

	//input = "(((2+3)*(5-1))-6)";

	post = convertNotation(input, stack1, stack2);
	cout << "Postfix is: " << post << endl;

	testStr = " 2 3 + 5 * 6 -";

	//cout << "The last value is: " << testStr[testStr.length() - 1] << '\n';
	//cout << "The first value is: " << testStr[0] << '\n';
	
	testTree = new tree();
	testTree->createTree(post);
	testTree->printList();
	output = testTree->postEval(testTree->head);

	cout << "\nThe solution for the equation is: " << output << endl;

	ofstream myfile;
	myfile.open("output.txt");
	myfile << "Solution for input.txt: " << output;
	myfile.close();

	system("pause");
    return 0;
}

string readFile(string fileName) //reads in the file word by word, assuming correct format
{
	string idName;
	int idValue;
	int code; //int to determine what the current line should do
	string idOp;

	ifstream file;
	file.open(fileName);
	if (!file.is_open()) return 0;

	string word;

	file >> word;

	return word;
}

string convertNotation(string infix, stack <char> s1, stack <char> s2) {
	/* Note: This currently can only process single digit numbers
	// Would have to change the function to check the next character
	// in the string. Would need an isDigit(char name) function.
	// Will add in the future hopefully. (2017-11-08 12:46)
	*/
	string postfix;
	bool isOp(char name);

	for (int i = 0; i < infix.length(); i++) {
		if (infix[i] == '(') {
			s1.push(infix[i]);
		}
		else if (infix[i] == ')') {
			postfix += ' ';
			postfix += s2.top();
			s2.pop();
			s1.pop();
		}
		else if (isOp(infix[i])) {
			s2.push(infix[i]);
		}
		else {
			postfix += ' ';
			postfix += infix[i];
		}
	}
	return postfix;
}

bool isOp(char name) {
	if ((name == '+') || (name == '-') || (name == '*') || (name == '/'))
	{
		return true;
	}
	else
	{
		return false;
	}
}