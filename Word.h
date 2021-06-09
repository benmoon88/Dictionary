#pragma once
#include <string>
#include <cctype>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <random>
using namespace std;

/* Word Class
	Cointains setters and getters for
	the Dictionary Class */
class Word
{
public:
	void setWord(string word, string type, string definition);
	void printDefinition();
	string getWord(), getType(), getDefinition(), sortWord();

private:
	string word, type, definition;
};