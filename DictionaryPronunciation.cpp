/*
Author: JiaLe Qiu
Course : CSCI - 136
Instructor : Nick
Assignment : Project 2

This program lets the user input a word. If the word is not found in the
dictionary, it will print "Not found". Otherwise:
Pronunciation - pronunciation of the word.
Identical - words with the same pronunciation as word.
Add phoneme - words that can be obtained from word by adding one phoneme.
Remove phoneme - words that can be obtained from word by removing one phoneme.
Replace phoneme - words that can be obtained from word by replacing one phoneme.

compilewith = g++ - Wall - Wpedantic - Werror - g pronounce.cpp - o pronounce
*/

#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
using namespace std;

string usableWord(string word);
void splitOnSpace(string dictionaryW, string & before, string & after);
void splitPhoneme(string wordPhoneme, string & firstPartPhoneme, string & restOfPhoneme);
int countPhonemes(string w);

int main() {
	ifstream dictionaryFile;
	string dictionaryW, word, before, after;
	string firstPartPhoneme = "";
	string restOfPhoneme = "";
	string wordPhoneme = "";
	string replacingPhoneme = "";
	string restReplacingPhoneme = "";
	string oldPhoneme, newPhoneme;
	string theWord, thePhoneme, actualP;
	string checkTheWord;
	int found = 0;
	int pCount = 0;
	int afterpCount = 0;

	dictionaryFile.open("cmudict.0.7a");//"pronounce.rtf");
	/*
	if (dictionaryFile.fail()) {
		cerr << "Error in opening the file" << endl;
		exit(1);
	}
	else {
		cout << "The file was opened succesfully." << endl;
	}
	*/
	getline(cin, word);

	string newWord = usableWord(word);

	if (newWord == "Not found") {
		cout << "Not found";
	}
	else {
		//Pronunciation TASK.
		while (getline(dictionaryFile, dictionaryW)) {
			splitOnSpace(dictionaryW, before, after);
			if (newWord == before) {
				found = found + 1;
				cout << "\nPronunciation     : " << after << "\n\n";
				wordPhoneme = after;
			}
		}
		if (found == 0) {
			cout << "Not found";
			exit(1);
		}

		dictionaryFile.close();
		dictionaryFile.open("cmudict.0.7a");//"pronounce.rtf");

		cout << "Identical         :";// Identical TASK.

		while (getline(dictionaryFile, dictionaryW)) {
			splitOnSpace(dictionaryW, before, after);
			if ((wordPhoneme == after) && (newWord != before)) {
				cout << " " << before;
			}
		}

		dictionaryFile.close();
		dictionaryFile.open("cmudict.0.7a");//"pronounce.rtf");

		// Add TASK Add TASK Add TASK Add TASK Add TASK Add TASK Add TASK Add TASK Add TASK Add TASK Add TASK Add TASK 
		cout << "\nAdd phoneme       :";

		while (getline(dictionaryFile, dictionaryW)) {
			splitOnSpace(dictionaryW, before, after);
			if (newWord == before) {
				wordPhoneme = after;
				actualP = wordPhoneme;
			}
		}

		pCount = countPhonemes(wordPhoneme);
		unsigned int t, y;
		int count, restOfPhonemeCount;
		string lastOutput;

		dictionaryFile.close();
		dictionaryFile.open("cmudict.0.7a");//"pronounce.rtf");

		while (getline(dictionaryFile, dictionaryW)) {// Add TASK
			splitOnSpace(dictionaryW, before, after);
			theWord = before;
			thePhoneme = after;
			afterpCount = countPhonemes(thePhoneme);
			if (afterpCount == (pCount + 1)) {
				oldPhoneme = "";
				newPhoneme = "";
				wordPhoneme = actualP;
				for (t = 0; t < (pCount+1); t++) {
					thePhoneme = after;
					count = 0;
					splitPhoneme(wordPhoneme, firstPartPhoneme, restOfPhoneme);
					for (y = 0; y < (pCount+1); y++) {
						splitPhoneme(thePhoneme, replacingPhoneme, restReplacingPhoneme);

						restOfPhonemeCount = countPhonemes(wordPhoneme);
						if (wordPhoneme == "") {
							count = 10;
						}
						if ((restOfPhonemeCount == 1) && (count == 10)) {
							newPhoneme = oldPhoneme + wordPhoneme + replacingPhoneme;
						}
						else {
							newPhoneme = oldPhoneme + replacingPhoneme + " " + wordPhoneme;//wordPhoneme + " " + replacingPhoneme;
						}
						if ((newPhoneme == after) && (newPhoneme != actualP) && (theWord != lastOutput)) {
							checkTheWord = usableWord(theWord);
							if (checkTheWord != "Not found") {
								cout << " " << theWord;
								lastOutput = theWord;
							}
						}
						thePhoneme = restReplacingPhoneme;
					}
					oldPhoneme += firstPartPhoneme + " ";
					wordPhoneme = restOfPhoneme;
				}
			}
		}
		}

		//Remove TASK Remove TASK Remove TASK Remove TASK Remove TASK Remove TASK Remove TASK Remove TASK Remove TASK Remove TASK
		dictionaryFile.close();
		dictionaryFile.open("cmudict.0.7a");//"pronounce.rtf");

		cout << "\nRemove phoneme    :";

		while (getline(dictionaryFile, dictionaryW)) {
			splitOnSpace(dictionaryW, before, after);
			if (newWord == before) {
				wordPhoneme = after;
				actualP = wordPhoneme;
			}
		}

		pCount = countPhonemes(wordPhoneme);
		unsigned int z;
		int count, restOfPhonemeCount;

		dictionaryFile.close();
		dictionaryFile.open("cmudict.0.7a");//"pronounce.rtf");

		while (getline(dictionaryFile, dictionaryW)) {// Remove TASK
			splitOnSpace(dictionaryW, before, after);
			theWord = before;
			thePhoneme = after;
			afterpCount = countPhonemes(thePhoneme);
			if (afterpCount == (pCount - 1)) {
				oldPhoneme = "";
				newPhoneme = "";
				wordPhoneme = actualP;
				count = 0;
				for (z = 0; z < pCount; z++) {
					splitPhoneme(wordPhoneme, firstPartPhoneme, restOfPhoneme);
					restOfPhonemeCount = countPhonemes(restOfPhoneme);
					if (restOfPhonemeCount == 1) {
						count = 1;
					}
					newPhoneme = oldPhoneme + restOfPhoneme;
					if (count == 1) {
						oldPhoneme += firstPartPhoneme;
					}
					else {
						oldPhoneme += firstPartPhoneme + " ";
					}
					if (newPhoneme == thePhoneme) {
						cout << " " << theWord;
					}
					wordPhoneme = restOfPhoneme;
				}
			}
		}

		// Replace TASK Replace TASK Replace TASK Replace TASK Replace TASK Replace TASK Replace TASK Replace TASK 
		dictionaryFile.close();
		dictionaryFile.open("cmudict.0.7a");//"pronounce.rtf");

		cout << "\nReplace phoneme   :";

		while (getline(dictionaryFile, dictionaryW)) {
			splitOnSpace(dictionaryW, before, after);
			if (newWord == before) {
				wordPhoneme = after;
				actualP = wordPhoneme;
			}
		}

		pCount = countPhonemes(wordPhoneme);
		unsigned int n, m;

		dictionaryFile.close();
		dictionaryFile.open("cmudict.0.7a");//"pronounce.rtf");

		while (getline(dictionaryFile, dictionaryW)) { // Replace TASK
			splitOnSpace(dictionaryW, before, after);
			theWord = before;
			thePhoneme = after;
			afterpCount = countPhonemes(thePhoneme);
			if (afterpCount == pCount) {
				oldPhoneme = "";
				newPhoneme = "";
				string lastOutput = "";
				wordPhoneme = actualP;
				for (n = 0; n < pCount; n++) {
					thePhoneme = after;
					count = 0;
					splitPhoneme(wordPhoneme, firstPartPhoneme, restOfPhoneme);
					for (m = 0; m < pCount; m++) {
						splitPhoneme(thePhoneme, replacingPhoneme, restReplacingPhoneme);
						restOfPhonemeCount = countPhonemes(oldPhoneme);
						if (restOfPhonemeCount == pCount) {
							newPhoneme = oldPhoneme + replacingPhoneme;
						}
						else {
							newPhoneme = oldPhoneme + replacingPhoneme + " " + restOfPhoneme;
						}
						if ((newPhoneme == after) && (newPhoneme != actualP) && (theWord != lastOutput)) {
							checkTheWord = usableWord(theWord);
							if (checkTheWord != "Not found") {
								cout << " " << theWord;
								lastOutput = theWord;
							}
						}
						thePhoneme = restReplacingPhoneme;
					}
					oldPhoneme += firstPartPhoneme + " ";
					wordPhoneme = restOfPhoneme;
				}
			}
		}
		dictionaryFile.close();
	}


int countPhonemes(string w) {
	int count = 0;
	char c;
	for (unsigned int k = 0; k < w.size(); k++) {
		c = w[k];
		if ((int)c == 32) {
			count += 1;
		}
	}
	return (count + 1);
}

string usableWord(string word) {
	string newWord = "";
	string notFound = "Not found";
	char c;
	for (unsigned int i = 0; i < word.size(); i++) {
		c = word[i];
		if ((isalpha(c)) && ((int)c >= 97) && ((int)c <= 122)){
			c -= 32;
			newWord += c;
		}
		else if (((int)c == 39) || (((int)c >= 65) && ((int)c <= 90))) {
			newWord += c;
		}
		else {
		    return notFound;
		}
	}
	return newWord;
}

void splitOnSpace(string dictionaryW, string & before, string & after) {
	before = "";
	after = "";
	unsigned int i = 0;
	while (i < dictionaryW.size() && not isspace(dictionaryW[i])) {
		before += dictionaryW[i];
		i++;
	}
	i += 2;
	while (i < dictionaryW.size()) {
		after += dictionaryW[i];
		i++;
	}
}

void splitPhoneme(string dictionaryW, string & firstPartPhoneme, string & restOfPhoneme) {
	firstPartPhoneme = "";
	restOfPhoneme = "";
	unsigned int i = 0;
	while (i < dictionaryW.size() && not isspace(dictionaryW[i])) {
		firstPartPhoneme += + dictionaryW[i];
		i++;
	}
	i ++;
	while (i < dictionaryW.size()) {
		restOfPhoneme += dictionaryW[i];
		i++;
	}
}
