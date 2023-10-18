#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    ifstream tbWords;
    tbWords.open("tbDictionary.txt");
    if (tbWords.fail())
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }

    string search;
    cout << "Please enter a Beki word: ";
    getline(cin, search);
    bool isFound = 0;
    while (!tbWords.eof())
    {
        string temp = "";
        getline(tbWords, temp);
        for (int i = 0; i < search.size(); i++)
        {
            if (temp[i] == search[i])
                isFound = 1;
            else
            {
                isFound = 0;
                break;
            }
        }

        if (isFound)
        {
            cout << "Tagalog word is: ";
            for (int i = search.size() + 1; i < temp.size(); i++)
                cout << temp[i];
            break;
        }
    }

    if (tbWords.eof() && (!isFound))
    {
        cout << "Word not found!\n";
    }

    tbWords.close();

    return 0;
}
