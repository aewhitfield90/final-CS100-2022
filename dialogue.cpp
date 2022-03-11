#include "dialogue.hpp"

Dialogue::Dialogue(string fileName)
{
	string temp = "dialogue/" + fileName;
	this->dialogueFileName = temp;
}

string Dialogue::GetFileName()
{
	return this->dialogueFileName;
}

void Dialogue::printDialogue(ostream& out) const
{
	ifstream f(dialogueFileName);

	if (f.is_open()) {
		out << f.rdbuf();
	}

}

