#include "Dictionary_Part01.h"
#include "Dictionary_Part02.h"
#include "Word.h"
#include "Trigram.h"
using namespace std;

int main()
{
	string selection, keyword;
	string fileName = "dictionary2021.txt";
	Trigram myDict;

	myDict.heading(); myDict.loadDictionary(fileName);
	system("pause");

	while (true)
	{	// Main menu
		myDict.heading();
		cout << "Make a selection from the below menu:" << endl;
		cout << " 1. Basic Dictionary Tasks" << endl;
		cout << " 2. Guessing Game" << endl;
		cout << " 3. Word Generator" << endl;
		cout << " 4. Exit Program" << endl;
		cout << " >> ";	cin >> selection;

		if (selection == "1")
		{
			while (true)
			{	// Dictionary Tasks
				myDict.heading();
				cout << " 1. Search for a word" << endl;
				cout << " 2. Find all words with more than three 'Z's" << endl;
				cout << " 3. List all words that have a 'q' without a following 'u' (ie. Iraqi)" << endl;
				cout << " 4. Find  all words that are Nouns and Verbs." << endl;
				cout << " 5. Find all words that are Palindromes" << endl;
				cout << " 6. Search for a word and display all anagrams of that word." << endl;
				cout << " 7. Go Back" << endl;
				cout << " >> ";	cin >> selection;

				if (selection == "1")
				{	// Search for the word in the vector and display the corrosponding; Word, Type and Definition(s)
					cout << "Please input the word to search for: \n  >> "; cin >> keyword;
					myDict.search(keyword);
					system("pause");
				}
				else if (selection == "2")
				{	// Display all words that have 3 Z's in total
					cout << "Here is a list of all the words with more than three 'Z's" << endl;
					myDict.threeZ("zzz");

					// Display all words that include the users input parameters
					cout << "\nSearch for a word with your input letters (ie. ZzZ):\n >> ";
					cin >> keyword;
					myDict.threeZ(keyword);
					system("pause");
				}
				else if (selection == "3")
				{	// Search for all words that have a Q but are not followed by a U
					cout << "A  list of all words that include a Q, but are not followed by a U:\n";
					myDict.qNotU();
					system("pause");
				}
				else if (selection == "4")
				{	// List all words that are Nouns and Verbs
					cout << "A list of all words that are Nouns and Verbs: " << endl;
					myDict.isNounVerb();
					system("pause");
				}
				else if (selection == "5")
				{	// List all words that are palindromes (same word spelt backwards as forwards)
					cout << "A list of all words that are Palindromes: " << endl;
					myDict.palindrome();
					system("pause");
				}
				else if (selection == "6")
				{	// List all words that are anagramns of the users input word
					cout << "Please input a word/letters to see if there are Anagrams of that input:\n >> ";
					cin >> keyword;
					myDict.anagram(keyword);
					system("pause");
				}
				else if (selection == "7")
				{	// Go back to main menu
					break;
				}
				else
				{	// Check if valid input has been entered.
					cout << "You have entered an invalid selection." << endl;
					system("pause");
				}
			}
		}
		else if (selection == "2")
		{	// Gather all words that are nouns, select a random word, and user guesses that word with hints.
			myDict.guessingGame();
		}
		else if (selection == "3")
		{	// Load trigrams from a text file including whitespace and the letters a-z, then generate random words
			myDict.funWithTrigrams();
		}
		else if (selection == "4")
		{	// Exit the system
			myDict.heading();
			cout << "\t\tThank you for using the Dictionary" << endl;
			system("pause");
			break;
		}
		else
		{	// Check if valid input has been entered.
			cout << "You have entered an invalid selection." << endl;
			system("pause");
		}
	}
}
