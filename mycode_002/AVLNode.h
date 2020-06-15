/* Copyright (C) 2018
* Course: CO2003
* Author: Rang Nguyen
* Ho Chi Minh City University of Technology
*/


#pragma once
#include<iostream>
#include"DynamicArray.h"
using namespace std;

class AVLNode {
public:
	string word;			// data 
	DynamicArray list;		// data
	int freq;				// data
	AVLNode* left;		// left child
	AVLNode* right;		// right child
	int balance;		// balance factor

	AVLNode(string word, int line, int balance = 0) {
		this->word = word;
		freq = 1;
		list.add(line);
		left = right = NULL;
		this->balance = balance;
	}

};
