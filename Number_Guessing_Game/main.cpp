#include <iostream>
#include <cstdlib>
#include <time.h>

class Generator
{
public:
    Generator()
    {
        srand(time(0)); // Creates a new seed every second
    }

    int generateRandom(int lvl)
    {
        return rand() % lvl + 1; // Random number generated from 1 to specified range
    }
};

int givenTries(int level)
{
    int tries;
    if (level == 1)
    {
        tries = 20;
    }
    else if (level == 2)
    {
        tries = 40;
    }
    else if (level == 3)
    {
        tries = 80;
    }
    else if (level == 4)
    {
        tries = 100;
    }
    else
    {
        tries = 150;
    }
    return tries;
}

void playGame(int t, int s, int lvl)
{
    int player;
    for (int i = 0; i < t && player != s; i++)
    {
        std::cout << "Try " << i + 1 << ": " << "Guess number:--->   ";
        std::cin >> player;
        if (player > 0 && player < lvl)
        {
            if (player > s)
            {
                std::cout << "You're higher" << std::endl
                          << "\n";
            }
            else if (player < s)
            {
                std::cout << "You're lower" << std::endl
                          << "\n";
            }
            else if (player == s)
            {
                std::cout << "CONGRATULATIONS!! YOU WON IN " << i + 1 << " TRIES! ^_^" << std::endl;
            }
            else
            {
                std::cout << "You ran out of tries. You lose >_<" << std::endl;
            }
        }
    }
}

int main()
{
    Generator num;
    int secret, player, level, tries;
    char replay;

    std::cout << "========================================================================================" << std::endl;
    std::cout << " WELCOME TO NUMBER GUESSING GAME " << std::endl;
    std::cout << std::endl;
    std::cout << "About Game:" << std::endl;
    std::cout << "\tThis is a very simple game." << std::endl;
    std::cout << "\tThe computer generates a number from 1 to 100 every second" << std::endl;
    std::cout << "\tYou have to guess the correct number to win this game" << std::endl;
    std::cout << "\tIf you fail to guess correctly within 10 tries, you lose" << std::endl;
    std::cout << "\tYou also lose if you guessed a number that is beyond the level you specified" << std::endl;
    std::cout << "\tYou get more tries depending on your level" << std::endl;
    std::cout << "\n\n\tTHAT'S ALL. ENJOY!" << std::endl;
    std::cout << "========================================================================================" << std::endl;

    std::cout << std::endl;

    std::cout << "Choose the level:" << std::endl;
    std::cout << "1. Easy - 1 to 100\n2. Medium - 1 to 200\n3. Hard - 1 to 500\n4. Extreme - 1 to 1000\n5. Impossible - 1 to 1500\n6. Exit" << std::endl;
    std::cin >> level;

    switch (level)
    {
    case 1:
        tries = givenTries(level);
        secret = num.generateRandom(100);
        playGame(tries, secret, 100);
        break;
    case 2:
        tries = givenTries(level);
        secret = num.generateRandom(200);
        playGame(tries, secret, 200);
        break;
    case 3:
        tries = givenTries(level);
        secret = num.generateRandom(500);
        playGame(tries, secret, 500);
        break;
    case 4:
        tries = givenTries(level);
        secret = num.generateRandom(1000);
        playGame(tries, secret, 1000);
        break;
    case 5:
        tries = givenTries(level);
        secret = num.generateRandom(1500);
        playGame(tries, secret, 1500);
        break;
    case 6:
        std::cout << "Press enter to exit...";
        std::cin.get();
        exit(0);
    default:
        std::cout << "Invalid input | Please Restart" << std::endl;
        exit(0);
    }

    std::cout << "Replay? (y/n): ";
    std::cin >> replay;
    while (replay != 'n')
    {
        if (replay == 'n')
        {
            exit(0);
        }
        else if (replay == 'y')
        {
            playGame(tries, secret, level);
        }
        else{
            std::cout << "INVALID INPUT" << std::endl;
            exit(0);
        }
    }
}