#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
//=================================



void addGame (vector<string> &Favorite)
{
    string elem;

    cout << "Pleas enter you favorite game: ";
    std::cin.ignore(32767, '\n');
    getline(cin, elem);
    Favorite.push_back(elem);

}

void deleteGame (vector<string> &Favorite)
{
    string GameName;
    cout << "Enter what game you want delete: ";
    std::cin.ignore(32767, '\n');
    getline(cin, GameName);
    const vector<string>::iterator &iter = find(Favorite.begin(), Favorite.end(), GameName);
    if (iter != Favorite.end())
    {
        Favorite.erase(iter);
    }
    else if (iter == Favorite.end())
    {
        cout << "Error game not found!!";
    }

}

void WriteInFile (vector<string> &Favorite)
{
    ofstream outf("Favorite Games.txt");
    if (!outf)
    {
        cout << "Something went wrong i cant open file!" << endl;
    }

    for (size_t i = 0; i < Favorite.size(); i++) {
        outf << i+1 << ": " << Favorite[i] << endl;
    }
}

void printList (vector<string> &Favorite)
{
    for (size_t i = 0; i < Favorite.size(); i++)
    {
        cout << i+1 << ": " << Favorite[i] << endl;
    }
}



//=================================

int main ()
{
    vector<string> Favorite;
    Favorite.push_back("TES5");
    Favorite.push_back("Dota 2");
    Favorite.push_back("Valorant");

    bool Exit = true;

    do {
        size_t Choose = 0;
        cout << endl;
        cout << "What you wanna do, enter number: " << endl;
        cout << "1: Print my favorite list" << endl;
        cout << "2: Add new game to my favorite list" << endl;
        cout << "3: Delete game from my favorite list" << endl;
        cout << "4: Write list in document" << endl;
        cout << "5: Exit" << endl;
        cin >> Choose;

        if (!cin)
        {
            cin.clear();
            cin.ignore(32767,'\n');
            cout << "Pleas enter number!" << endl;
        }

        switch (Choose) {
                case 1:
                    printList(Favorite);
                    break;
                case 2:
                    addGame(Favorite);
                    break;
                case 3:
                    deleteGame(Favorite);
                    break;
                case 4:
                    WriteInFile(Favorite);
                case 5:
                    Exit = false;
                    break;
            }


    } while (Exit);

    return 0;
}