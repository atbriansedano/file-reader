// Programmer Brian Sedano
/*Resources:
***https://replit.com/@AnnaSalvati/BINARY-SEARCH-TREE-CLASS?v=1
***https://www.youtube.com/
***https://stackoverflow.com*/
// Count number of words in the file
// Count the number of unique words
// Get avererage word length
// Get average sentence length
// Display words used too often
// Display if sentence length is too long
// Display if word length is too
// Display an index of words in alphabeticle order

#include "BSTree.cpp"
#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>
#include <numeric>
#include <stdio.h>
#include <vector>

using namespace std;

bool order(string a, string b) {
	return a < b;
}

// Index function.
vector<string> index(string input) {
	BSTree<string> unique;
	vector<string> index;
	int count = 0;

	ifstream file;
	file.open(input);
	if (!file.is_open())
		cout << "error";

	string word;
	while (file >> word) {
		word[0] = toupper(word[0]);
		word.erase(remove(word.begin(), word.end(), '.'), word.end());
		word.erase(remove(word.begin(), word.end(), ','), word.end());

		if (!unique.searchItem(word)) {
			unique.insertItem(word);
		} else if (unique.searchItem(word)) {
			index.push_back(word);
		}
	}

	sort(index.begin(), index.end(), order);
	index.erase(std::unique(index.begin(), index.end()), index.end());

	return index;
}

///////////////////////////////////////////

// Returns the average length of the file.
int sentenceLength(string input) {
	ifstream file;
	file.open(input);
	if (!file.is_open())
		return 0;

	vector<string> words;
	vector<int> length;
	int count;
	string word, temp;
	char a = '.';
	while (file >> word) {
		word[0] = toupper(word[0]);
		word.erase(remove(word.begin(), word.end(), ','), word.end());

		words.push_back(word);
	}

	for (int i = 0; i < words.size(); i++) {
		temp = words[i];
		int let = temp.size() - 1;
		count++;

		if (temp[let] == '.') {
			length.push_back(count);
			count = 0;
		} else if (temp[let] != '.') {
			continue;
		}
	}

	int sum = accumulate(length.begin(), length.end(), 0);
	int total = sum / length.size();

	return total;
}

//////////////////////////////////////////

// Returns the average length of the words in the file.
int wordLength(string input) {
	vector<string> words;
	vector<int> avg;
	string temp;
	int num, sum, length;

	ifstream file;
	file.open(input);
	if (!file.is_open())
		return 0;

	string word;
	while (file >> word) {
		word[0] = toupper(word[0]);
		word.erase(remove(word.begin(), word.end(), '.'), word.end());
		word.erase(remove(word.begin(), word.end(), ','), word.end());

		words.push_back(word);
	}

	for (int i = 0; i < words.size(); i++) {
		temp = words[i];
		num = temp.size();
		avg.push_back(num);
	}

	sum = accumulate(avg.begin(), avg.end(), 0);
	length = sum / words.size();

	return length;
}
////////////////////////////////////////

// This function returns the number of unique words greater than 3 letters.
int uniqueTreeTwo(string input) {
	BSTree<string> unique;
	BSTree<string> more;
	int count = 0;

	ifstream file;
	file.open(input);
	if (!file.is_open())
		return 1;

	string word;
	while (file >> word) {
		word[0] = toupper(word[0]);
		word.erase(remove(word.begin(), word.end(), '.'), word.end());
		word.erase(remove(word.begin(), word.end(), ','), word.end());

		if (!unique.searchItem(word) && word.size() > 3) {
			unique.insertItem(word);
		} else if (unique.searchItem(word) && word.size() > 3) {
			if (!more.searchItem(word)) {
				more.insertItem(word);
				count++;
			} else {
				continue;
			}
		}
	}

	return count;
}

////////////////////////////////////////////////////////////

// Function for the words used too often.
vector<string> styleWanings(string input) {
	float parameter = (uniqueTreeTwo(input) / 10) / 2;

	BSTree<string> unique;
	vector<string> index;
	vector<string> sw;
	int count = 0;

	ifstream file;
	file.open(input);
	if (!file.is_open())
		cout << "error";

	string word;
	while (file >> word) {
		word[0] = toupper(word[0]);
		word.erase(remove(word.begin(), word.end(), '.'), word.end());
		word.erase(remove(word.begin(), word.end(), ','), word.end());

		if (!unique.searchItem(word) && word.size() > 3) {
			unique.insertItem(word);
		} else if (unique.searchItem(word) && word.size() > 3) {
			index.push_back(word);
		}
	}

	int counter;
	for (int i = 0; i < index.size(); i++) {
		for (int j = 0; j < index.size(); j++) {
			if (index[i] == index[j]) {
				counter++;
				if (counter > parameter) {
					sw.push_back(index[i]);
					counter = 0;
				}
			}
		}
	}

	sort(sw.begin(), sw.end(), order);
	sw.erase(std::unique(sw.begin(), sw.end()), sw.end());

	return sw;
}

////////////////////////////////////////////////////////////

// Returns total number of unique words.
int uniqueTree(string input) {
	BSTree<string> unique;
	BSTree<string> more;
	int count = 0;

	ifstream file;
	file.open(input);
	if (!file.is_open())
		return 0;

	string word;
	while (file >> word) {
		word[0] = toupper(word[0]);
		word.erase(remove(word.begin(), word.end(), '.'), word.end());
		word.erase(remove(word.begin(), word.end(), ','), word.end());

		if (!unique.searchItem(word)) {
			unique.insertItem(word);
		} else if (unique.searchItem(word)) {
			if (!more.searchItem(word)) {
				more.insertItem(word);
				count++;
			} else if (more.searchItem(word)) {
				continue;
			}
		}
	}

	return count;
}

////////////////////////////////////////////////////////////

// Returns the total number of words in the file.
int countWords(string input) {
	int count = 0;

	ifstream file;
	file.open(input);
	if (!file.is_open())
		return 1;

	else {
		string word;
		while (file >> word) {
			count++;
		}
		return count;
	}
}

////////////////////////////////////////////////////////////

// Outputs all the information into a seperate file named output.txt
void outputFile(string input) {
	ofstream out("output.txt");
	out << "FILE NAME: " << input << "\n" << endl;
	out << "STATISTICAL SUMMARY" << endl;
	out << "-------------------" << endl;
	out << "Total number of words: " << countWords(input) << endl;
	out << "Total number of unique words: " << uniqueTree(input) << endl;
	out << "Total number of unique words of more than three letters: "
		<< uniqueTreeTwo(input) << endl;
	out << "Average word length: " << wordLength(input) << endl;
	out << "Average sentence length: " << sentenceLength(input) << endl;
	;
	out << "\n"
		<< "STYLE WARNINGS" << endl;
	out << "--------------" << endl;
	out << "Words used too often: " << endl;

	vector<string> j = styleWanings(input);
	for (int a = 0; a < j.size(); a++) {
		out << a + 1 << ")" << j[a] << endl;
	}

	if (wordLength(input) > 5) {
		out << "Average word length too long: " << wordLength(input) << endl;
		;
	}
	if (wordLength(input) > 12) {
		out << "Average sentence length too long: " << sentenceLength(input)
			<< endl;
	}
	out << "\n"
		<< "INDEX OF UNIQUE WORDS" << endl;
	out << "--------------" << endl;

	vector<string> i = index(input);
	for (int m = 0; m < i.size(); m++) {
		out << i[m] << endl;
	}

	out.close();
}

// Main function that asks user for the name of the file.
int main() {
	string input, file;

	// text.txt is my sample file and output.txt is where the information is
	// displayed

	cout << "Please type in the name of your file with extention please : ";
	cin >> input;
	cout << "\n"
		 << "Thank You! Please check output file for the results.";
	outputFile(input);

	return 0;
}