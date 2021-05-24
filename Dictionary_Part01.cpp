/*						 *\
   Assignment 2, CSP2104
   Semester 1, 2021
   Written by Ben Moon
   Student ID: 10445994
\*						 */

#include "Dictionary_Part01.h"
using namespace std;
bool debugMessages = false;

// Simple heading
void Dictionary::heading()
{
	system("cls");
	cout << "	######\n	#     # #  ####  ##### #  ####  #    #   ##   #####  #   #	\n	"
		"#     # # #    #   #   # #    # ##   #  #  #  #    #  # #						\n	"
		"#     # # #        #   # #    # # #  # #    # #    #   #						\n	"
		"#     # # #        #   # #    # #  # # ###### #####    #						\n	"
		"#     # # #    #   #   # #    # #   ## #    # #   #    #						\n	"
		"######  #  ####    #   #  ####  #    # #    # #    #   #						\n\n";
}

// Used for displaying a message when debugging points of code
void Dictionary::debug(string msg)
{
	if (debugMessages == true)
		cout << msg << endl;
}

// loads the dictionary file into it's array of Word objects
void Dictionary::loadDictionary(string fileName)
{
	string word, type, def, empty;
	Word* words;

	cout << "Loading Dictionary... ";
	ifstream dictionaryFile(fileName);

	if (dictionaryFile.is_open())
	{
		while (!dictionaryFile.eof())
		{
			getline(dictionaryFile, word, ' ');
			getline(dictionaryFile, type);
			getline(dictionaryFile, def);
			getline(dictionaryFile, empty);
			{
				words = new Word();
				words->setWord(word, type, def);
				dictionary.push_back(words);
			}
		}
		dictionaryFile.close();
		delete new Word();
		cout << " Success: " << wordCount() << " words." << endl;
	}
	else
	{
		cout << ">> ERROR: File Not Found" << endl; exit(404);
		system("pause");
	}
}

// Return the size of the Dictionary
int Dictionary::wordCount()
{
	return dictionary.size();
}

// Convert input into lower case
string Dictionary::lowerCase(string input)
{
	for (int i = 0; i <= input.length(); i++)
	{
		input[i] = tolower(input[i]);
	}
	return input;
}

/* Basic Task 1
	Search for a word within the Dictionary
	Print the Word, Word Type and Definition(s) */
void Dictionary::search(string keyword)
{
	bool success = false;
	for (Word* i : dictionary)
	{
		string word = i->getWord();
		if (lowerCase(word) == lowerCase(keyword))
		{
			cout << ">> " << i->getWord() << " -- " << i->getType() << endl;
			i->getDefinition();
			i->printDefinition();
			success = true;
		}
	}
	if (success == false)
		cout << ">> No word found" << endl;
}

/* Basic task 2
	Display all words that have 3 Z's in total */
void Dictionary::threeZ(string keyword)
{
	int n = 1;
	bool success = false;
	for (Word* i : dictionary)
	{
		if (i->sortWord().find(lowerCase(keyword)) != string::npos)
		{
			cout << n << ". " << i->getWord() << endl; n++;
			success = true;
		}
	}
	if (success == false)
		cout << ">> No words containing input strings were found." << endl;
}

/* Basic task 3
	Display all words that have 3 Z's in total
	*additional: Display all words that include the users input parameters */
void Dictionary::qNotU()
{																		// https://www.geeksforgeeks.org/string-find-in-cpp/
	int n = 1;
	bool success = false;
	for (Word* i : dictionary)
	{
		string word = lowerCase(i->getWord());
		int q = word.find("q");

		while (q != string::npos)
		{
			int matchQ = q + 1;
			if (word.length() != q)
			{
				int u = word.find("u", matchQ);
				if (u != matchQ)
				{
					cout << n << ". " << i->getWord() << endl; n++;
					success = true;
				}
				q = word.find("q", matchQ);
			}
		}
	}
	if (success == false)
		cout << ">> There are no words in the Dictionary that involve a 'Q' not followed by a 'U'" << endl;
}