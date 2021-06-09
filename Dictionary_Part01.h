#pragma once
#include "Word.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <random>
using namespace std;

/* Dictionary Class
	The dictionary contains all functions pertaining to various tasks
	including; loading dictionary and manipulating aspects of the dictionary */
class Dictionary
{
public:
	void heading(), trigramHeading(), guessingGameHeading();
	void debug(string msg);
	string lowerCase(string input);
	void threeZ(string search), qNotU();
	void loadDictionary(string fileName), search(string keyword);

protected:
	vector<Word*> dictionary;
	int wordCount();
};