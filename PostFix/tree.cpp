#include "stdafx.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Node { //this is the node, couldnt think of a name for our data
public:
	char idName;
	int idValue;
	int pos;
	Node *left;
	Node *right;
	Node *parent;
	Node(char name); //constructor
	Node(); //default contructor
	void printName();

};

Node::Node()
{
	//cout << "Object Created: Node" << '\n';
	this->idName = ' ';
	this->left = NULL;
	this->right = NULL;
	this->parent = NULL;
}

Node::Node(char name)
{
	//cout << "Object Created: Node" << '\n';
	this->idName = name;
	this->idValue = 0;
	this->left = NULL;
	this->right = NULL;
	this->parent = NULL;
}

void Node::printName()
{
	if (idName == '+' || idName == '-' || idName == '*' || idName == '/')
		cout << idName;
	else cout << idValue;
	cout << ' ';
}





class tree { //the tree class, holds all the values and functions within itself
private:
	//lol nothing
public:
	Node *head;
	tree(); //constructor
	void createTree(string str);
	bool isOp(char name);
	int addNode(Node* temp, string str, int pos);
	void printList();
	void postTraverse(Node* nodey);
	int postEval(Node* temp);
	int tree::operate(int left, int right, char op);
};

tree::tree()
{
	cout << "Object Created: tree" << '\n';
	this->head = NULL;
}


void tree::createTree(string str)
{ //need to rewrite this to include values with > 1 digit
	//adding in space reading to fix this
	int pos;
	pos = str.length() - 1; //grabs the last value
	char name = str[str.length() - 1];
	if (!isOp(name)) {
		cout << "/nInvalid Expression For char: " << name;
		return;
	}
	else
	{
		Node *temp = new Node(name);
		if (head == NULL) //for the first added item
		{
			cout << "We Made a Head!";
			head = temp; //lets us point to this tree
			head->pos = 0;

			addNode(temp, str, pos);
		}
	}
	return;
}

bool tree::isOp(char name) {
	if ((name == '+') || (name == '-') || (name == '*') || (name == '/'))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int tree::addNode(Node* temp, string str, int pos) {
	/* Starts at the end of the string and decrements until the beginning--
	// or pos '0'. This allows the tree to be made top-down. Adding the 
	// right nodes first. The valueSize passed makes sure we are on the right 
	// character of our postfix string. This code also can take in multi-digit
	// integers. (2017-11-08 12:42)
	*/
	if (pos > -1) {
		//cout << "\nCurrently at: " << str[pos];
		Node* current;
		Node* right = new Node();
		Node* left = new Node();
		current = temp;

		int valueSize; //tells how many "pos" to decrement

		if (str[pos] == ' ') {
			pos--;
		}
		if (isOp(str[pos]))
		{
			valueSize = 2; //skips space and sets on next item
			current->idName = str[pos];
			current->idValue = 0; //resets previous calculations
			cout << "\nId Print: " << current->idName;
			valueSize = addNode(right, str, (pos - valueSize)) + valueSize;
			cout << "\nWe set the right ID to: " << right->idValue;
			current->right = right;
			valueSize = addNode(left, str, (pos - valueSize)) + valueSize; 
			current->left = left;

			return valueSize;
		}
		else
		{
			//until end of value
			int theValue; 
			cout << "\nBefore loop idValue: " << temp->idValue;
			valueSize = 1; //to accomodate for the space
			for (int i = 0; (str[pos - i] != ' ') && ((pos - (i + 1)) > -1); i++) {
				valueSize++;
				//temp->idValue = temp->idValue + ((int)str[pos - i] * pow(10, i);
				temp->idValue = temp->idValue + ((str[pos - i] - '0') * pow(10, i));
				cout << "\nDope: " << temp->idValue;
			}
			current->idName = str[pos];
			cout << "\nValue Size to pass is: " << valueSize;

			//cout << current->idName;
			return valueSize;
		}
	}
	return 0;
}

void tree::printList()
{
	Node *temp = new Node();
	//cout << "SUPER TEST YEAH DUDE " << temp->idName;             //error test 10-8-2017
	temp = this->head;
	//test to see if head exists
	if (head == NULL)
	{
		cout << "Head is NULL dude " << '\n';
	}

	cout << endl;
	postTraverse(temp);
	cout << endl;
}

void tree::postTraverse(Node* nodey)
{
	Node* temp = new Node();
	temp = nodey;
	if (nodey == NULL) {
		//cout << "\nWe Null";
	    return;
    }
	else {
		postTraverse(temp->left);
		postTraverse(temp->right);
		temp->printName();
	}
	return;
}

int tree::postEval(Node* temp)
{
	int leftValue, rightValue;
	Node* current = new Node();
	current = temp;
	if (current == NULL) {
		return -1;
	}
	else {
		leftValue = postEval(temp->left);
		rightValue = postEval(temp->right);
		//then evaluate
		if (isOp(temp->idName)) {
			temp->idValue = operate(leftValue, rightValue, temp->idName);
			return temp->idValue;
		}
		else return temp->idValue; //if already a value, just leave it
	}
	return -1;
}

int tree::operate(int left, int right, char op) {
	int value;

	if (op == '+') value = (left + right);
	if (op == '-') value = (left - right);
	if (op == '*') value = (left * right);
	if (op == '/') value = (left / right);

	return value;
}