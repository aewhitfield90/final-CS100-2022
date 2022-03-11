#ifndef __DIALOGUE_HPP__
#define __DIALOGUE_HPP__
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Dialogue{
private:
	string dialogueFileName;
public:
	Dialogue(fileName);
	string GetFileName();
	void printDialogue(ostream& out) const;
};

#endif
