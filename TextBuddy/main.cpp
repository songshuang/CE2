//main.cpp

#include <iostream>
#include <string>
#include <cstdlib>

#include "textBuddy.h"

using namespace std;

int main(int argc, char* argv[]){
	string fileName;
	string input;

	if (argc < 2) {
		cin >> fileName;
	}
	else{
		fileName = argv[1];
	}
	fileName = fileName.c_str();
	TextBuddy file(fileName);
	getline(cin, input);
	while(!file.isExit(input)){
		file.readCommand(input);
		cout << "command: ";
		getline(cin, input);
	}

	system("pause");

	return 0;
}


		

