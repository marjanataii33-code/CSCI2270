#include "array_double.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void getIgnoreWords(const char *ignoreWordFileName, string ignoreWords[])
{
    ifstream inputFile;
    inputFile.open(ignoreWordFileName);

    if (!inputFile)
    {
        cout << "Failed to open " << ignoreWordFileName << endl;
        return;
    }

    int i = 0;

    while (i < 50 && inputFile >> ignoreWords[i])
    {
        i++;
    }

    inputFile.close();
}


bool isIgnoreWord(string word, string ignoreWords[], int length)
{
    int i = 0;

    while (i < length)
    {
        if (ignoreWords[i] == word)
        {
            return true;
        }

        i++;
    }

    return false;
}


int getTotalNumberNonIgnoreWords(wordRecord distinctWords[], int length)
{
    int total = 0;

    int i = 0;

    while (i < length)
    {
        total += distinctWords[i].count;
        i++;
    }

    return total;
}


void sortArray(wordRecord distinctWords[], int length)
{
    int i = 0;

    while (i < length - 1)
    {
        int j = 0;

        while (j < length - 1 - i)
        {
            if (distinctWords[j].count < distinctWords[j + 1].count)
            {
                wordRecord temp = distinctWords[j];
                distinctWords[j] = distinctWords[j + 1];
                distinctWords[j + 1] = temp;
            }
            else if (distinctWords[j].count == distinctWords[j + 1].count &&
                     distinctWords[j].word > distinctWords[j + 1].word)
            {
                wordRecord temp = distinctWords[j];
                distinctWords[j] = distinctWords[j + 1];
                distinctWords[j + 1] = temp;
            }

            j++;
        }

        i++;
    }
}


void printTenFromN(wordRecord distinctWords[], int N, int totalNumWords)
{
    int i = N;

    while (i < N + 10)
    {
        float probability =
            (float) distinctWords[i].count / totalNumWords;

        cout << fixed << setprecision(5)
             << probability << " - "
             << distinctWords[i].word << endl;

        i++;
    }
}