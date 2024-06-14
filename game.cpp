#include <iostream>

using namespace std;

void displayMenu(bool hasScissors, bool hasPushLawnmower, bool hasBatteryLawnmower, bool hasTeam)
{
    cout << "\n--- Landscaper 2024 ---\n";
    cout << "1. Cut lawns\n";
    cout << "2. Visit shop\n";
    cout << "3. Check balance\n";
    cout << "4. Quit\n";
    cout << "What would you like to do: ";
}

void displayShop(bool hasScissors, bool hasPushLawnmower, bool hasBatteryLawnmower, bool hasTeam)
{
    cout << "\n--- Shop ---\n";
    if (!hasScissors)
    {
        cout << "1. Buy rusty scissors ($5)\n";
    }
    if (!hasPushLawnmower)
    {
        cout << "2. Buy push lawnmower ($25)\n";
    }
    if (!hasBatteryLawnmower)
    {
        cout << "3. Buy battery-powered lawnmower ($100)\n";
    }
    if (!hasTeam)
    {
        cout << "4. Hire a landscaping team ($500)\n";
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

    cout << "Welcome to Landscaper 2024\n";
    cout << "You can cut lawns using just your teeth to earn money.\n";

    while (true)
    {
        displayMenu(hasScissors, hasPushLawnmower, hasBatteryLawnmower, hasTeam);
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "You spent the day cutting lawns and earned $" << earningRate << ".\n";
            balance += earningRate;
            break;
        case 2:
            int shopChoice;
            while (true)
            {
                displayShop(hasScissors, hasPushLawnmower, hasBatteryLawnmower, hasTeam);
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
                    if (!hasPushLawnmower && balance >= 25)
                    {
                        cout << "You bought a push lawnmower!\n";
                        balance -= 25;
                        hasPushLawnmower = true;
                        earningRate = 50;
                    }
                    else
                    {
                        cout << "You don't have enough money or already have a push lawnmower.\n";
                    }
                    break;
                case 3:
                    if (!hasBatteryLawnmower && balance >= 100)
                    {
                        cout << "You bought a battery-powered lawnmower!\n";
                        balance -= 100;
                        hasBatteryLawnmower = true;
                        earningRate = 100;
                    }
                    else
                    {
                        cout << "You don't have enough money or already have a battery-powered lawnmower.\n";
                    }
                    break;
                case 4:
                    if (!hasTeam && balance >= 500)
                    {
                        cout << "You hired a landscaping team!\n";
                        balance -= 500;
                        hasTeam = true;
                        earningRate = 250;
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