#ifndef DIALOGUE_H
#define DIALOGUE_H
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Dialogue{

private:
	string dialogueFileName;
public:
	Dialogue(string fileName);
	string GetFileName();
	void printDialogue(ostream& out) const;
};

#endif
