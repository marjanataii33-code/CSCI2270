#include <iostream>
#include <fstream>
#include "../code_1/array_double.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    // your code here
    if (argc != 4) {
        cout << "Usage: Assignment2Solution <number of words> <inputfilename.txt> <ignoreWordsfilename.txt>" << endl;

        return 1;
    }


// Big while → read each word from file
// First if → skip ignore words
// Inner while → search through stored words
// Inner if → check if current word already exists


    string ignoreWords[50];
    getIgnoreWords(argv[3], ignoreWords);

    wordRecord* distinctWords = new wordRecord[100];


    int numDistinctWords = 0;
    int arraySize = 100;


    ifstream inputFile;
    inputFile.open(argv[2]);

    if (!inputFile)
    {
        cout << "Failed to open " << argv[2] << endl;
        return 1;
    }

    string word;

    while (inputFile >> word)
    {

        if (!isIgnoreWord(word, ignoreWords, 50))
        {
            bool found = false;
            int i = 0;

            while (i < numDistinctWords)
            {
                if (distinctWords[i].word == word)
                {
                    distinctWords[i].count++;
                    // this word appeared one more time,
                    // not the same as i++ which means moving
                    // to the next word in the array

                    found = true;
                }

                i++;
            }

            if (!found)
            {
                if (numDistinctWords == arraySize)
                {
                    int newSize = arraySize * 2;

                    wordRecord* newArray = new wordRecord[newSize];

                    int i = 0;

                    while (i < numDistinctWords)
                    {
                        newArray[i] = distinctWords[i];
                        i++;
                    }

                    delete[] distinctWords;
                    distinctWords = newArray;
                    arraySize = newSize;
                }

                distinctWords[numDistinctWords].word = word;
                distinctWords[numDistinctWords].count = 1;
                numDistinctWords++;
            }
        }
    }

    inputFile.close();

    sortArray(distinctWords, numDistinctWords);

    int N = stoi(argv[1]);

    printTenFromN(distinctWords, N, numDistinctWords);

    delete[] distinctWords;

    return 0;
}