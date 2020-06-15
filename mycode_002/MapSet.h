#pragma once
#include"AVLNode.h"
class MapSet
{
private:
	AVLNode * root;
	int count;


protected:
	void clearRec(AVLNode*root);
	void printInOrderRecursion(AVLNode*root);




public:
	MapSet();
	~MapSet();
	void clear();
	void print();
	int getSize() { return count; }

	// YOUR TASKS START HERE
	void add(string word, int line);

	AVLNode* insert_node (AVLNode* root, AVLNode* newnode, bool taller, int line);

	AVLNode* rotate_right(AVLNode* root);
	AVLNode* rotate_left(AVLNode* root);

	AVLNode* rightBalance(AVLNode *root, bool taller);
	AVLNode* leftBalance(AVLNode *root, bool taller);
	// END HERE
};

