//
//  anagrams.cpp
//  Project_02
//
//  Created by Yiyang Wang on 7/9/17.
//  Copyright © 2017 Yiyang Wang. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <istream>
#include <cstring>
#include <string>
using namespace std;

const int MAXRESULTS   = 50;    // Max matches that can be found
const int MAXDICTWORDS = 30000; // Max words that can be read in

int readDictionary(istream &dictfile, string dict[]);
int recursivePermute(string word, const string dict[], int size, string results[]);
void recurPrint(const string results[], int size);

int getLoopSize(istream &dictfile, string *dict);
void printPermute(string prefix, string rest, const string dict[], string results[]);
void permuteLoop(int i, int max, string prefix, string rest, const string dict[], string results[]);

int main()
{
    string results[MAXRESULTS];
    string dict[MAXDICTWORDS];
    ifstream dictfile;         // file containing the list of words
    int nwords;                // number of words read from dictionary
    string word;
    
    dictfile.open("/Users/ouyang/Desktop/words.txt");
    if (!dictfile) {
        cout << "File not found!" << endl;
        return (1);
    }
    
    nwords = readDictionary(dictfile, dict);
    cout << nwords << " words" << endl;
    for (int i =0; i < nwords; i++)
        cout << dict[i] << endl;
    
	cout << "Please enter a string for an anagram: ";
    cin >> word;
	recursivePermute(word, dict, nwords, results);
	for (int i = 0; i < MAXRESULTS; i++) {
		cout << results[i] << endl;
	}
    
    /*int numMatches = recursivePermute(word, dict, nwords, results);
    if (!numMatches)
        cout << "No matches found" << endl;
    else
        recurPrint(results, numMatches); */
}

int getLoopSize(istream &dictfile, string *dict) {
	if (!(dictfile >> dict[0]))
		return 0;
	int counter = 1 + readDictionary(dictfile, dict+1);
	return counter;
}



int readDictionary(istream &dictfile, string dict[]) {

	int counter = getLoopSize(dictfile, dict);
	return counter;
}


void printPermute(string prefix, string rest, const string dict[], string results[]) {
	if (rest.length() == 0) {
		cout << prefix << endl;
        
        
	}
	else {
		/*for (int i = 0; i < rest.length(); i++) {
            string tempPrefix = prefix;
            string tempRest = rest;
			tempPrefix += rest[i];
			tempRest.erase(i, 1);
            printPermute(tempPrefix, tempRest);
		}*/
        
        permuteLoop(0, rest.length(), prefix, rest, dict, results);
	}
}


void permuteLoop(int i, int max, string prefix, string rest, const string dict[], string results[]) {
    if (i == max)
        return;
    string tempPrefix = prefix;
    string tempRest = rest;
    tempPrefix += rest[i];
    tempRest.erase(i, 1);
    printPermute(tempPrefix, tempRest, dict, results);
    permuteLoop(i+1, rest.length(), prefix, rest, dict, results);
}




int recursivePermute(string word, const string dict[], int size, string results[]) {

	string prefix ="";
    string rest = word;
    printPermute(prefix, rest, dict, results);

	return 100;
}
