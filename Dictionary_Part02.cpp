/*						 *\
   Assignment 2, CSP2104
   Semester 1, 2021
   Written by Ben Moon
   Student ID: 10445994 
\*						 */

#include "Dictionary_Part02.h"
using namespace std;

/* Basic Task 1
	List all words that are Nouns and Verbs */
void Dictionary2::isNounVerb()
{
	int n = 1;
	bool success = false;
	for (Word* i : dictionary)
	{
		if (i->getType().find("(n.v.)") != string::npos)
		{
			cout << n << ". " << i->getWord() << endl; n++;
			success = true;
		}
	}
	if (success == false)
		cout << ">> No words in the dictionary are Nouns and Verbs" << endl;
}

/* Basic Task 2
	List all words that are palindromes (same word backwards as forwards) */
void Dictionary2::palindrome()
{
	int n = 1;
	bool success = false;
	for (Word* i : dictionary)
	{
		string reverseWord = i->getWord();
		reverse(reverseWord.begin(), reverseWord.end());
		if (reverseWord == i->getWord() && (reverseWord.length() >= 2))
		{
			cout << n << ". " << i->getWord() << endl;  n++;
			success = true;
		}
	}
	if (success == false)
		cout << ">> No words in the dictionary are Palindromes (same word forwards and in reverse)" << endl;
}

/* Intermediate Task 1
	List all words that are anagrams of the users input */
void Dictionary2::anagram(string keyword)
{
	int n = 1;
	bool success = false;
	keyword = lowerCase(keyword);
	string sameWord = keyword;
	sort(keyword.begin(), keyword.end());
	for (Word* i : dictionary)
	{
		if (i->sortWord().find(keyword) != string::npos)
			if (i->getWord().length() == keyword.length())
				if (sameWord != i->getWord())
				{
					cout << n << ". " << i->getWord() << endl; n++;
					success = true;
				}
	}
	if (success == false)
		cout << ">> No additional words found" << endl;
}

/* Intermediate Task 2
	Find a random word that is a Noun
		-- have user guess that word */
void Dictionary2::guessingGame()
{
	heading();
	int guess = 1, score = 0;
	string secretWord, guessWord, showDef;
	cout << "\t\t\t == Guessing Game! ==\n" << endl;
	cout << "Rules:" << endl;
	cout << "- 3 Guesses per attempt." << endl;
	cout << "- Less then 5 letters: 1 Point" << endl;
	cout << "- Less then 10 letters: 3 Points" << endl;
	cout << "- More then 10 letters: 5 Points" << endl << endl;

	/* Find a word to be guessed
		- word must be a Noun */
	while (true) {
		while (true)
		{
			default_random_engine generate(time(NULL));
			uniform_int_distribution<int> random(0, wordCount());
			int randNum = random(generate);
			if (dictionary[randNum]->getType() == "Noun (n.)\n")
			{
				secretWord = dictionary[randNum]->getWord();
				showDef = dictionary[randNum]->getDefinition();
				break;
			}
		}
		cout << "Take your guess at a word to the below definition(s):\n\n>> " << showDef << endl << endl;
		cout << "The word is <" << secretWord.length() << "> letters long.";

		while (true)
		{
			cout << "\n >> ";	cin >> guessWord;
			if (lowerCase(guessWord) == "easteregg")
			{
				cout << "The secret word is: " << secretWord;
			}
			else if (lowerCase(secretWord) == lowerCase(guessWord))
			{
				if (secretWord.length() < 5)
					score++;
				if (secretWord.length() >= 5 and secretWord.length() <= 10)
					score += 3;
				else score += 5;
				heading();
				cout << "Congratulations! The word was: " << secretWord << endl;
				cout << "Your current score is: " << score << endl << endl;
				guess = 1;
				break;
			}
			else if (guess == 1)
			{
				cout << "Wrong Answer, try again ( 2 attempts left )" << endl;
				cout << "\t" << secretWord[0];
				for (int i = 1; i <= secretWord.length() - 1; i++)
				{
					cout << " _";
				}
				guess++;
			}
			else if (guess == 2)
			{
				cout << "Wrong Answer, try again ( 1 attempt left )" << endl;
				cout << "\t" << secretWord[0] << " " << secretWord[1];
				for (int i = 2; i <= secretWord.length() - 1; i++)
				{
					cout << " _";
				}
				guess++;
			}
			else if (guess == 3)
			{
				cout << "Out of tries, better luck next time" << endl;
				cout << "The word was: " << secretWord << endl;
				cout << "Your score was: " << score << endl;
				system("pause");
				break;
			}
		}
		if (guess == 3)
			break;
	}
}