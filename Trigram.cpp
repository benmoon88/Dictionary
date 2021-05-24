/*						 *\
   Assignment 2, CSP2104
   Semester 1, 2021
   Written by Ben Moon
   Student ID: 10445994
\*						 */

#include "Trigram.h"
using namespace std;

// Return index number of character A-Z from 0-26 (0 being ' ', 26 being 'z')
int Trigram::getIndex(char inputChar)
{
	char inputCharacter = tolower(inputChar);
	int index = -1;
	int currentCharCode = (int)inputCharacter;
	if (currentCharCode == (int)' ')
	{
		index = 0;
	}
	else if ((int)'a' <= currentCharCode <= (int)'z')
	{
		index = currentCharCode - 96;
	}
	if (index >= 0 && index < 27)
	{
		return index;
	}
	else
	{
		return -1;
	}
}

// Return letter from given index
char Trigram::returnChar(int letterIndex)
{
	char letter;
	if (letterIndex == 0)
		letter = (char)letterIndex + 32;
	else
		letter = (char)letterIndex + 96;
	return letter;
}

/*	Calculate the percentage from
	lower divide by max	*/
float Trigram::percentage(float lower, float max)
{
	if (lower == 0)
		return 0;
	else
	{	// round to 2 decimal
		float percent = roundf(((lower / max) * 100) * 100) / 100;
		return percent;
	}
}

/*	Generate a random number
	between min and max  */
int Trigram::randomNum(int min, int max)
{
	int randomNumber = rand() % max + min;
	return randomNumber;
}

// Checks if file exists
bool Trigram::fileChecker(string input)
{
	ifstream file(input);
	if (file.is_open())
		return true;
	else
		cout << "ERROR: File not found" << endl;
	file.close();
	return false;
}

// Sets the total trigrams that are counted in a single parse
void Trigram::setTotal(int total)
{
	Trigram::total = total;
}

// Returns the total trigrams counted
int Trigram::getTotal()
{
	return total;
}

// Create a 3D array of Trigrams from a text file
void Trigram::loadTrigrams(string fileName)
{
	int a, b, c, count = 0;
	string line;
	ifstream file(fileName);

	cout << "Loading Trigrams...";
	if (file.is_open())
	{
		while (!file.eof())
		{
			getline(file, line);
			if (line != "" && line.length() >= 3) // so debugger doesnt crash  v
			{
				for (int i = 0; i < line.length() - 3; i++) // requires minimum of 3 characters
				{
					a = getIndex(line[i]);
					b = getIndex(line[i + 1]);
					c = getIndex(line[i + 2]);
					if ((a != -1) && (b != -1) && (c != -1))
					{
						trigram[a][b][c]++;
						count++;
					}
				}
			}
		}
		setTotal(count);
		file.close();
		cout << " Success: " << count << " trigrams." << endl;
		if (getTotal() < 200000)
			cout << "WARNING: This file does not have a big enough sample size to create good results." << endl;
	}
	else
	{
		cout << ">> ERROR: File Not Found" << endl;
	}
}

/*	Find the top 3 characters and either;
	Print the top 3 or return a single top 3 character	*/
int Trigram::topThreeCharacters(int index1, int index2, bool print)
{
	int total = 0, result = 0;
	float count1 = 0, count2 = 0, count3 = 0;
	int letterIndex1 = 0, letterIndex2 = 0, letterIndex3 = 0;
	for (int i = 0; i <= 26; i++)
	{
		total += trigram[index1][index2][i];
		if (trigram[index1][index2][i] > count1)
		{
			count3 = count2;
			count2 = count1;
			count1 = trigram[index1][index2][i];
			letterIndex3 = letterIndex2;
			letterIndex2 = letterIndex1;
			letterIndex1 = i;
		}
		else if (trigram[index1][index2][i] > count2)
		{
			count3 = count2;
			count2 = trigram[index1][index2][i];
			letterIndex3 = letterIndex2;
			letterIndex2 = i;
		}
		else if (trigram[index1][index2][i] > count3)
		{
			count3 = trigram[index1][index2][i];
			letterIndex3 = i;
		}

	}
	if (print == true)
	{
		float percent1 = percentage(count1, total);
		float percent2 = percentage(count2, total);
		float percent3 = percentage(count3, total);
		string firstTwo; firstTwo += returnChar(index1); firstTwo += returnChar(index2);
		if (percent1 > 0) {
			cout << "The three highest probabilities are:" << endl;
			cout << firstTwo << "'" << returnChar(letterIndex1) << "': " << percent1 << "%" << endl;
		}
		if (percent2 > 0) {
			cout << firstTwo << "'" << returnChar(letterIndex2) << "': " << percent2 << "% " << endl;
		}
		if (percent3 > 0) {
			cout << firstTwo << "'" << returnChar(letterIndex3) << "': " << percent3 << "% " << endl;
		}
		else
		{
			cout << "Nothing more to show." << endl << endl;
		}
		return 0;
	}
	if (print == false)
	{
		int top3[3] = { letterIndex1, letterIndex2, letterIndex3 };
		int ranInt = randomNum(1, 10); // weight the results in highest probabilities favour
		if (ranInt >= 4)
		{	// 60%
			result = top3[0];
		}
		else if (ranInt >= 1)
		{	// 30%
			result = top3[1];
		}
		else
		{	// 10%
			result = top3[2];
		}
		return result;
	}
	else
	{
		cout << "ERROR" << endl;
		return 0;
	}
}

// Check if word not in dictionary, and is not a duplicate word
bool Trigram::checkWord(string word)
{
	string result;
	for (Word* i : dictionary) {
		if (i->getWord() == word) {
			debug("--> Word found in dictionary");
			return false;
		}
	}
	for (int i = 0; i < temp.size(); i++) {
		if (temp[i] == word) {
			debug("--> Duplicate Word Found");
			return false;
		}
	}
	return true;
}

// Generate 10 Random Word's
void Trigram::generateWords(string input)
{
	int letter1, letter2, letter3, top3;
	while (temp.size() < 10)
	{
		int n = 0;
		string word = input;
		letter1 = getIndex(word[0]);
		letter2 = getIndex(word[1]);
		letter3 = topThreeCharacters(letter1, letter2, false);
		if (letter3 != 0)
		{
			word += returnChar(letter3);
		}
		while (word.length() <= 5)
		{
			letter1 = letter2;
			letter2 = letter3;

			top3 = topThreeCharacters(letter1, letter2, false);
			if (n = 10 and top3 == 0) // this prevents infinite loops from poor sample sized
				top3 = 1;			  // files, if trigram doesnt exist force 'a' as result
			if (top3 != 0)
			{
				letter3 = top3;
				word += returnChar(letter3);
			}
			n++;
		}
		while (word.length() >= 6 || word.length() < 15)
		{
			letter1 = letter2;
			letter2 = letter3;
			top3 = topThreeCharacters(letter1, letter2, false);
			if (top3 == 0) break;
			else
			{
				letter3 = top3;
				word += returnChar(letter3);
			}
		}
		word.erase(remove_if(word.begin(), word.end(), isspace), word.end());
		if (checkWord(word) == true)
		{
			temp.push_back(word);
		}
	}
	int n = 1;
	for (int i = 0; i < temp.size(); i++)
	{	// print created words
		if (n < 10)	cout << " " << n << ") " << temp[i] << endl;
		else cout << n << ") " << temp[i] << endl;
		n++;
	}
	temp.clear();
}

//	The Menu and options regarding Trigrams
void Trigram::funWithTrigrams()
{
	string selection, input, currentFile;
	while (true)
	{
		heading();
		cout << "Pick a text file to load:" << endl;
		cout << " 1. Load: 'dictionary2021.txt'" << endl;
		cout << " 2. Load: 'SherlockHolmes.txt'" << endl;
		cout << " 3. Input your own file (.txt)" << endl;
		cout << " 4. Go Back\n >> ";
		cin >> selection;
		if (selection == "1")
		{
			if (fileChecker("dictionary2021.txt") == false)
			{
				system("pause");
				continue;
			}
			else
			{
				heading();
				loadTrigrams("dictionary2021.txt");
				currentFile = "dictionary2021.txt";
				system("pause");
			}
		}
		else if (selection == "2")
		{
			if (fileChecker("SherlockHolmes.txt") == false)
			{
				system("pause");
				continue;
			}
			else
			{
				heading();
				loadTrigrams("SherlockHolmes.txt");
				currentFile = "SherlockHolmes.txt";
				system("pause");
			}
		}
		else if (selection == "3")
		{
			cout << "Enter the filename:\n >> ";
			cin >> input;
			if (fileChecker(input) == false)
			{
				system("pause");
				continue;
			}
			else
			{
				heading();
				loadTrigrams(input);
				currentFile = input;
				system("pause");
			}
		}
		else if (selection == "4") break;
		else
		{
			cout << "You have entered an invalid input." << endl;
			continue;
		}
		while (true)
		{
			heading();
			cout << "\t\t\t == Fun with Trigrams! ==" << endl;
			cout << " <" << currentFile << ">" << endl;
			cout << "  " << getTotal() << " trigrams" << endl << endl;
			cout << " 1. Generate ten random words" << endl;
			cout << " 2. Generate ten random words from an input" << endl;
			cout << " 3. Find the top three letters to come after two characters" << endl;
			cout << " 4. Go Back\n >> ";
			cin >> selection;

			if (selection == "1")
			{
				cout << "10 Random Words:" << endl;
				char letter1 = ' ';	char letter2 = returnChar(randomNum(1, 26));
				input = letter1; input += letter2;
				generateWords(input);
				system("pause");
			}
			else if (selection == "2")
			{
				while (true)
				{
					cout << "Enter a string of two letters; 'A-Z'\n >> ";
					cin >> input; input = lowerCase(input);
					if (input.length() == 2 && isalpha(input[0]) && isalpha(input[1]))
					{
						cout << "10 Random Words starting with: '" << input << "'" << endl;
						generateWords(input);
						system("pause");
						break;
					}
					else
						cout << "You have entered an invalid input." << endl;
				}
			}
			else if (selection == "3")
			{
				while (true)
				{
					cout << "Input two letters between; A-Z\n >> ";
					cin >> input; input = lowerCase(input);
					if (input.length() == 2 && isalpha(input[0]) && isalpha(input[1]))
					{
						topThreeCharacters(getIndex(input[0]), getIndex(input[1]), true);
						system("pause");
						break;
					}
					else
						cout << "You have entered an invalid input." << endl;
				}
			}
			else if (selection == "4") break;
			else
			{
				cout << "You have entered an invalid selection." << endl;
				system("pause");
			}
		}
	}
}