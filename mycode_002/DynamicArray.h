#include <stdio.h>
#include <string.h>
#include<iostream>
#include<iomanip>
using namespace std;

class DynamicArray {
private:
	int size;
	int capacity;
	int *storage;

public:
	DynamicArray(int capacity = 10) {
		this->capacity = capacity;
		size = 0;
		storage = new int[capacity];
	}

	~DynamicArray() {
		delete[] storage;
	}

	void setCapacity(int newCapacity) {
		int *newStorage = new int[newCapacity];
		memcpy(newStorage, storage, sizeof(int) * size);
		capacity = newCapacity;
		delete[] storage;
		storage = newStorage;
	}

	void ensureCapacity(int minCapacity) {
		if (minCapacity > capacity) {
			int newCapacity = (capacity * 3) / 2 + 1;
			if (newCapacity < minCapacity)
				newCapacity = minCapacity;
			setCapacity(newCapacity);
		}
	}


	void print() {
		for (int i = 0; i<this->size; i++) {
			cout << storage[i] << " ";
		}
	}

	void add(int line) {
		if (size > 0) {
			if (line == storage[size - 1]) return;
		}
		ensureCapacity(size + 1);		
		storage[size] = line;
		size++;
	}

};