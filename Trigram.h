#pragma once
#include "Dictionary_Part02.h"
using namespace std;

/* The trigram class parses through a specified file and stores all trigrams
   containing the letters 'a' through 'z' and white space ' '.
   -- Additional functions to build words based on top 3 probabale letters  */
class Trigram
	: public Dictionary2
{
public:
	void loadTrigrams(string fileName);
	void setTotal(int total); int getTotal();
	bool fileChecker(string input);
	int getIndex(char inputChar), randomNum(int min, int max);
	char returnChar(int letterIndex);
	float percentage(float lower, float max);
	void generateWords(string input);
	bool checkWord(string word);
	int topThreeCharacters(int index1, int index2, bool print);
	void funWithTrigrams();

private:
	int trigram[27][27][27] = { 0 };
	int total;
	vector<string> temp;
};