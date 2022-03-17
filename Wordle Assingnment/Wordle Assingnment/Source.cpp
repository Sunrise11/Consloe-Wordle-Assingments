#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <windows.h>

using namespace std;

int main()
{
    unsigned seed = time(0);
    srand(seed);

    vector<string> words;
    ifstream file("words.txt");
    string line;

    while (getline(file, line)) words.push_back(line);

    string awnser = words[rand() % words.size()];


askTheUser:

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    cout << "Input a 5-letter word (Capital letters only): " << endl;


    string guess;


    cin >> guess;


    int a = awnser.length();
    int g = guess.length();

    char awnserArray[6];
    char guessArray[6];

    strcpy_s(awnserArray, awnser.c_str());

    strcpy_s(guessArray, guess.c_str());

    int n = 6;

    char* awnserAry;
    awnserAry = awnserArray;

    for (int i = 0; i < n; i++)
    {
        if (guessArray[i] == awnserArray[i])
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            cout << guessArray[i];

        }
        else if (guessArray[i] != awnserArray[i])
        {
            if (awnser.find(guessArray[i]) != string::npos)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                cout << guessArray[i];
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                cout << guessArray[i];
            }


        }



    }
    string yesOrNo;
    if (awnser == guess)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        cout << endl << "You got it right! :)" << endl;
        cout << "Play Again?" << endl;
        cout << "Enter Y to continue or N to quit" << endl;
        cin >> yesOrNo;
        if (yesOrNo == "Y")
        {
            goto askTheUser;
        }
        else if (yesOrNo == "N")
        {
            exit(0);
        }
    }
    else if (awnser != guess)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        cout << endl << "You got it worng. Try Again" << endl;
        cout << "Play Again?" << endl;
        cout << "Enter Y to continue or N to quit" << endl;
        cin >> yesOrNo;
        if (yesOrNo == "Y")
        {
            goto askTheUser;
        }
        else if (yesOrNo == "N")
        {
            exit(0);
        }


        return 0;
    }
}