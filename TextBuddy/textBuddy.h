//textBuddy.h

#ifndef TEXTBUDDY_H
#define TEXTBUDDY_H
#include <vector>

using namespace std;
static bool stringCompare(const string&, const string&);

class TextBuddy{
public:
	TextBuddy(string);
	void addItem(string);
	void deleteItem(string);
	void clear();
	void display();
	void storeInput();//fileToVector
	void output();
	void newFile();
	//bool isExit(string);
	bool convertToInt(string, int&);
	bool readCommand(string);   //process command
	bool txtFile(string);
	string getCommand(string); //extarc cmdword
	string getInput(string); //extract cmd detail
	int _noOfLines;
	vector <string> _vectorFile;
	string _fileName;
	
};
#endif





