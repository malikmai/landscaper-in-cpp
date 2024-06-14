#include <iostream>

using namespace std;

void displayMenu(bool hasScissors, bool hasPushLawnmower, bool hasBatteryLawnmower, bool hasTeam)
{
    cout << "\n--- Landscaper 2024 ---\n";
    cout << "1. Cut lawns\n";
    cout << "2. Visit shop\n";
    cout << "3. Check balance\n";
    cout << "4. Quit\n";
    cout << "What would you like to do?: ";
}

void displayShop(bool hasScissors, bool hasPushLawnmower, bool hasBatteryLawnmower, bool hasTeam, int balance)
{
    cout << "\n--- Shop ---\n";
    cout << "Your current balance is: $" << balance << "\n";
    if (!hasScissors)
    {
        cout << "1. Buy rusty scissors ($5)\n";
    }
    if (!hasPushLawnmower)
    {
        cout << "2. Buy push lawnmower ($50)\n";
    }
    if (!hasBatteryLawnmower)
    {
        cout << "3. Buy battery-powered lawnmower ($500)\n";
    }
    if (!hasTeam)
    {
        cout << "4. Hire a landscaping team ($1000)\n";
    }
    cout << "5. Exit shop\n";
    cout << "Choose an option: ";
}

int main()
{
    int balance = 0;
    int choice;
    bool hasScissors = false;
    bool hasPushLawnmower = false;
    bool hasBatteryLawnmower = false;
    bool hasTeam = false;
    int earningRate = 1;

    cout << "Welcome to the Landscaping Business Game!\n";
    cout << "You must find a way to earn money cutting grass to earn $5000. Better start with your teeth!\n";

    while (true)
    {
        displayMenu(hasScissors, hasPushLawnmower, hasBatteryLawnmower, hasTeam);
        cin >> choice;

        switch (choice)
        {
        case 1:
            balance += earningRate;
            cout << "You spent the day cutting lawns and earned $" << earningRate << ".\n";
            cout << "Your current balance is: $" << balance << "\n";
            if (balance >= 5000)
            {
                cout << "Congratulations! You've won the game with a balance of $" << balance << "!\n";
                return 0;
            }
            break;
        case 2:
            int shopChoice;
            while (true)
            {
                displayShop(hasScissors, hasPushLawnmower, hasBatteryLawnmower, hasTeam, balance);
                cin >> shopChoice;

                if (shopChoice == 5)
                {
                    break;
                }

                switch (shopChoice)
                {
                case 1:
                    if (!hasScissors && balance >= 5)
                    {
                        cout << "You bought a pair of rusty scissors!\n";
                        balance -= 5;
                        hasScissors = true;
                        earningRate = 5;
                    }
                    else
                    {
                        cout << "You don't have enough money or already have scissors.\n";
                    }
                    break;
                case 2:
                    if (!hasPushLawnmower && balance >= 50)
                    {
                        cout << "You bought a push lawnmower!\n";
                        balance -= 50;
                        hasPushLawnmower = true;
                        earningRate = 20;
                    }
                    else
                    {
                        cout << "You don't have enough money or already have a push lawnmower.\n";
                    }
                    break;
                case 3:
                    if (!hasBatteryLawnmower && balance >= 500)
                    {
                        cout << "You bought a battery-powered lawnmower!\n";
                        balance -= 500;
                        hasBatteryLawnmower = true;
                        earningRate = 50;
                    }
                    else
                    {
                        cout << "You don't have enough money or already have a battery-powered lawnmower.\n";
                    }
                    break;
                case 4:
                    if (!hasTeam && balance >= 1000)
                    {
                        cout << "You hired a landscaping team!\n";
                        balance -= 1000;
                        hasTeam = true;
                        earningRate = 100;
                    }
                    else
                    {
                        cout << "You don't have enough money or already have a team.\n";
                    }
                    break;
                default:
                    cout << "Invalid choice. Please choose again.\n";
                }
            }
            break;
        case 3:
            cout << "Your current balance is: $" << balance << "\n";
            break;
        case 4:
            cout << "Thank you for playing! Your final balance is: $" << balance << "\n";
            return 0;
        default:
            cout << "Invalid choice. Please choose again.\n";
        }
    }
}
