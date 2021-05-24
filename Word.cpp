/*						 *\
   Assignment 2, CSP2104
   Semester 1, 2021
   Written by Ben Moon
   Student ID: 10445994
\*						 */


#include "Word.h"
using namespace std;

// Word setter
void Word::setWord(string word, string type, string definition)
{
	Word::word = word;
	Word::type = type;
	Word::definition = definition;
}

// Returns the word from the Dictionary vector
string Word::getWord()
{
	if (type == "[pn]")
	{
		word[0] = toupper(word[0]);
		return word;
	}
	else
		return word;
}

// Adjusts the word type to be easily readable from original vector type
string Word::getType()
{
	if (type == "[v]")
		return "Verb (v.)\n";

	else if (type == "[n]")
		return "Noun (n.)\n";

	else if (type == "[adj]")
		return "Adjective (adj.)\n";

	else if (type == "[adv]")
		return "Adverb (adv.)\n";

	else if (type == "[prep]")
		return "Preposition (prep.)\n";

	else if (type == "[pn]")
		return "Proper Noun (pn.)\n";

	else if (type == "[n_and_v]")
		return "Noun and Verb (n.v.)\n";

	else if (type == "[misc]")
		return "MiscWords (misc.)\n";

	else
		return "This word is not affiliated with a word type";
}

// Gets the definition and returns the definition with better formatting.
string Word::getDefinition()
{	

	string x = "\n>> ", a = ";  ";
	while (definition.find(a) != string::npos)
	{
		definition.replace(definition.find(a), a.length(), x);
	}
	return definition;
}

//  Sorts the word into alphebetical order
string Word::sortWord()
{	
	string sortedWord = word;
	sort(sortedWord.begin(), sortedWord.end());
	return sortedWord;
}

// prints the definition
void Word::printDefinition()
{
	cout << ">> " << definition << endl;
}
