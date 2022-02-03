#include "iostream"
#include <cstdlib>

int main ()
{
    int PlayerNumber;
    int score;
    srand(static_cast<unsigned int>(time(0)));
    std::cout << "          Guess My Number         " << std::endl;
    int WinNumber = rand()%100 + 1;


    while (WinNumber < PlayerNumber || WinNumber > PlayerNumber)
    {
        std::cout << "Enter a guess: ";std::cin >> PlayerNumber;
        if (WinNumber < PlayerNumber)
        {
            std::cout << "Too high!" << std::endl;
            score++;
        }else if (WinNumber > PlayerNumber)
            {
                std::cout << "Too low!" << std::endl;
                score++;
            }else
                {
                    score++;
                    std::cout << "Congrats you win!"; std::cout << "With: " << score  << std::endl;
                }
    }
    return 0;
}