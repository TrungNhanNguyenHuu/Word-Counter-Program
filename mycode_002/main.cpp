#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
#include "MapSet.h"

using namespace std;

void processLine(string line, int linenum, MapSet* map) {
	string word = "";
	for(int i = 0; i <line.length(); i++) {
		if (isalpha(line[i])) {
			word += tolower(line[i]);
		}
		else {
			if (word != "") {
				map->add(word, linenum);
				word = "";
			}
		}
	}
	if (word != "")
		map->add(word, linenum);
}


void processFile(istream& in, MapSet* map) {
	int linenum = 0;
	while (true) {
		string line;
		getline(in, line);
		if (!in)
			break;
		linenum++;
		processLine(line, linenum, map);
	}
}


int main(int argc, char **argv) {
	MapSet* map = new MapSet();
	if (argc == 1) {  // no command line parameters.
		ifstream input("input.txt");
		processFile(input, map);
	}
	else if (argc == 2) {  // one command line parameters.
		ifstream input(argv[1]);
		if (!input) {
			cerr << "Can't open input file, \"" << argv[1] << "\".\n";
			return 1;
		}
		else
			processFile(input, map);
	}
	else {
		cerr << "Usage:  " << argv[0] << " [inputfile].\n";
		return 1;
	}
	map->print();
	delete map;
	return 0;
}
