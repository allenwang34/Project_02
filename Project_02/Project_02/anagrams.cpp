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

const int MAXRESULTS   = 20;    // Max matches that can be found
const int MAXDICTWORDS = 30000; // Max words that can be read in

int readDictionary(istream &dictfile, string dict[]);
int recursivePermute(string word, const string dict[], int size, string results[]);
void recurPrint(const string results[], int size);




int main()
{
    string results[MAXRESULTS];
    string dict[MAXDICTWORDS];
    ifstream dictfile;         // file containing the list of words
    int nwords;                // number of words read from dictionary
    string word;
    
    dictfile.open("C:/Users/allen/Desktop/words.txt");
    if (!dictfile) {
        cout << "File not found!" << endl;
        return (1);
    }
    
    nwords = readDictionary(dictfile, dict);
    cout << nwords << " words" << endl;
    for (int i =0; i < nwords; i++)
        cout << dict[i] << endl;
    
   /* cout << "Please enter a string for an anagram: ";
    cin >> word;
    
    int numMatches = recursivePermute(word, dict, nwords, results);
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

/*void writeString(istream &dictfile, string dict[], int size) {
	if (size < 0) return;
	dictfile >> dict[size];
	writeString(dictfile, dict, size - 1);
}*/


int readDictionary(istream &dictfile, string dict[]) {

	/*int counter = 0;
	while (dictfile>>dict[counter])
	{
	counter++;*/
	//int counter = 5;
	//writeString(dictfile, dict, counter);
	int counter = getLoopSize(dictfile, dict);
	return counter;
}



