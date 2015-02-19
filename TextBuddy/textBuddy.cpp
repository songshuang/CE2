//textBuddy.cpp

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "textBuddy.h"

using namespace std;

const string WELCOME = "Welcome to TextBuddy. ";
const string READY_FOR_USE=" is ready for use";
const string CLEAR_MESSAGE = "all content deleted from";
const string ADD_MESSAGE = "added to";
const string DELETE_MESSAGE = "deleted from";
const string SEARCH_MESSAGE = "found in line:	";

TextBuddy::TextBuddy(string fileName){
	while(!txtFile(fileName)){
	getline(cin, fileName);
	fileName = fileName.c_str();
	}
	_noOfLines = 0;	
	_fileName = fileName;
	storeInput();
	cout << WELCOME << _fileName << READY_FOR_USE << endl;
};

//this function processes different commands user keys in
bool TextBuddy::readCommand(string input){
	string command = getCommand(input);
	if(command == "add"){
		addItem(input);
	}
	else if(command == "display"){
		display();
	}
	else if(command == "delete"){
		deleteItem(input);
	}
	else if(command == "clear"){
		clear();
	}
	else{
		return false;
	}
	output();
	return true;
	}

//check if command is exit
/*bool TextBuddy::isExit(string input){
	string command = getCommand(input);
	if(command == "exit"){
		return true;
	}
	else{
		return false;
	}
}*/

//function for "add"
void TextBuddy::addItem(string input){
	string line = getInput(input);
	_vectorFile.push_back(line);
	cout << "added to " << _fileName <<":\"" << line << "\"" << endl;
	_noOfLines++;
}

//delete a line
void TextBuddy::deleteItem(string input){
	string line = getInput(input);
	int itemNumber;
	while(!convertToInt(line, itemNumber)){
		cin >> line;
	}
	string deleteItem = _vectorFile[itemNumber - 1];
	_vectorFile.erase(_vectorFile.begin() + itemNumber - 1);
	cout << "delete from "<< _fileName << ":\"" << deleteItem << "\"" << endl;
	_noOfLines--;
	return;
}

//get line number to delete
bool TextBuddy::convertToInt(string line, int& itemNumber){
	stringstream convert(line);
	if(!(convert >> itemNumber)){
		cout << "enter a valid item number" << endl;
		itemNumber = 0;
		return false;
	}else{
		return true;
		}
}

//clear all content from a file
void TextBuddy::clear(){
	_vectorFile.clear();
	cout << "all content deleted from " << _fileName << endl;
	_noOfLines = 0;
	return;
}

//display content of a file
void TextBuddy::display(){
	if(_noOfLines==0){
		cout << _fileName << " is empty" <<endl;
	}
	else{
		for(int i = 1; i <= _noOfLines; i++){
			cout << i << ". " << _vectorFile[i-1] << endl;
		}
	}
	return;
}

//output results
void TextBuddy::output(){             
	ofstream write(_fileName);
	for(int j = 0; j < _noOfLines; j++){
		write << _vectorFile[j] << endl;
	}
	write.close();
}

//store lines in a vector
void TextBuddy::storeInput(){
	ifstream readFile(_fileName);
	string line;
	if(!readFile){
		newFile();
	}
	else{
		while(!readFile.eof()){
			getline(readFile, line);
			if(line != "\n"){
				_vectorFile.push_back(line);
				_noOfLines++;
			}
		}
		readFile.close();
		}
}

//create a new file if it does not exit
void TextBuddy::newFile(){
	ofstream write;
	write.open(_fileName);
	write.close();
	return;
}

//extract command details
string TextBuddy::getInput(string input){           
	int inputStart = input.find_first_of(" ")+1;
	string commandInput = input.substr(inputStart);
	return commandInput;
}

//extract command string
string TextBuddy::getCommand(string input){
	int endCommand = input.find_first_of(" ");
	string command = input.substr(0, endCommand);
	return command;
}

//check if the file name ends with .txt
bool TextBuddy::txtFile(string fileName){
	int start = fileName.find_last_of(".");
	string postFix = fileName.substr(start);
	if(postFix == ".txt"){
		return true;
	}
	else{
		return false;
	}
}






