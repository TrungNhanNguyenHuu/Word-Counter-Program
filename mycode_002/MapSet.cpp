#include "MapSet.h"


MapSet::MapSet()
{
	root = NULL;
	count = 0;
}


MapSet::~MapSet()
{
	clear();
}

void MapSet::clearRec(AVLNode* root) {
	if (root != NULL) {
		clearRec(root->left);
		clearRec(root->right);
		delete root;
	}
}
void MapSet::clear() {
	clearRec(root);
	root = NULL;
	count = 0;
}
void MapSet::printInOrderRecursion(AVLNode* root) {
	if (root != NULL) {
		printInOrderRecursion(root->left);
		cout << setw(20) << left << root->word.c_str() << "|" << setw(10) << right << root->freq << "|";
		root->list.print();
		cout << endl;
		printInOrderRecursion(root->right);
	}
}

void MapSet::print() {
	cout << "The total number of words: " << count << endl;
	cout << "---------------------------------------" << endl;
	cout << setw(20) << left << "Word" << "|" << setw(10) << right << "Freq." << "|" << "Line No." << endl;
	cout << "---------------------------------------" << endl;
	printInOrderRecursion(root);
	cout << "---------------------------------------" << endl;
}


void MapSet::add(string word, int line) {
	// TODO
	AVLNode *new_pointer = new AVLNode(word, line, 0);
	bool taller = false;
	this->root = insert_node(this->root, new_pointer, taller, line);





}

AVLNode* MapSet::insert_node(AVLNode* root, AVLNode* newnode, bool taller, int line)
{
    if (root == NULL)
    {
        root = newnode;
        taller = true;
        count = count + 1;
        return root;
    }

    if (newnode->word < root->word)
    {
        root->left = insert_node(root->left, newnode, taller, line);
        if (taller == 1)
        {
            if (root->balance == 1)
            {
                root = leftBalance(root, taller);
            }else
            {
                if (root->balance == 0)
                {
                    root->balance = 1;
                }else
                {
                    root->balance = -1;
                    taller = false;
                }
            }
        }
    }else
    {
        if (newnode->word > root->word)
        {
            root->right = insert_node(root->right, newnode, taller, line);
            if (taller == 1)
            {
                if (root->balance == 1)
                {
                    root->balance = 0;
                    taller = false;
                }else
                {
                    if (root->balance == 0)
                    {
                        root->balance = -1;
                    }else
                    {
                    root = rightBalance(root, taller);
                    }
                }
            }
        }else
        {
            if (newnode->word == root->word)
            {
                root->freq = root->freq + 1;
                root->list.add(line);
            }
        }
    }
    return root;
}

AVLNode* MapSet::rotate_right(AVLNode* root)
{
    AVLNode *tempPtr = root->left;
    root->left = tempPtr->right;
    tempPtr->right = root;
    return tempPtr;
}

AVLNode* MapSet::rotate_left(AVLNode* root)
{
    AVLNode *tempPtr = root->right;
    root->right = tempPtr->left;
    tempPtr->left = root;
    return tempPtr;
}

AVLNode* MapSet::rightBalance(AVLNode *root, bool taller)
{
    if (root->right->balance == -1)
    {
        root = rotate_left(root);
        root->balance = 0;
        root->right->balance = 0;
        taller = false;
    }else
    {
        if (root->right->left->balance == -1)
        {
            root->balance = 1;
            root->right->balance = 0;
        }else
        {
            if (root->right->left->balance == 0)
            {
                root->right->balance = 0;
            }else
            {
                root->balance = 0;
                root->right->balance = -1;
            }
        }
        root->right->left->balance = 0;
        root->right = rotate_right(root->right);
        root = rotate_left(root);
        taller = false;
    }
    return root;
}

AVLNode* MapSet::leftBalance(AVLNode *root, bool taller)
{
    if (root->left->balance == 1)
    {
        root = rotate_right(root);
        root->balance = 0;
        root->left->balance = 0;
        taller = false;
    }else
    {
        if (root->left->right->balance == 1)
        {
            root->balance = -1;
            root->left->balance = 0;
        }else
        {
            if (root->left->right->balance == 0)
            {
                root->left->balance = 0;
            }else
            {
                root->balance = 0;
                root->left->balance = 1;
            }
        }
        root->left->right->balance = 0;
        root->left = rotate_left(root->left);
        root = rotate_right(root);
        taller = false;
    }
    return root;
}
