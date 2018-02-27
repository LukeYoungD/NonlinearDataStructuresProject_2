// This is start of the header guard.  ADD_H can be any unique name.  By convention, we use the name of the header file.
#ifndef tree_h
#define tree_h

// This is the content of the .h file, which is where the declarations go
#include <string>
#include <iostream>


using namespace std;

class Node { //this is the node or "leaf" on the tree
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
	int operate(int left, int right, char op);
};





// This is the end of the header guard
#endif