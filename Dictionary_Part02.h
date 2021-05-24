/*						 *\
   Assignment 2, CSP2104
   Semester 1, 2021
   Written by Ben Moon
   Student ID: 10445994
\*						 */

#pragma once
#include "Dictionary_Part01.h"
using namespace std;

/* Dictionary Part 2 for Assignment 2
	An extension of the first Dictionary class */
class Dictionary2
	: public Dictionary
{
public:
	void isNounVerb(), palindrome();
	void anagram(string keyword), guessingGame();
};