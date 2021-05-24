/*						 *\
   Assignment 2, CSP2104
   Semester 1, 2021
   Written by Ben Moon
   Student ID: 10445994
\*						 */

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