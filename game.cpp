#include <iostream>
using namespace std;

void displayMenu()
{
    cout << "\n--- Landscaper 2024 ---\n";
    cout << "1. Cut lawns today\n";
    cout << "2. Check Balance\n";
    cout << "3. Quit\n";
    cout << "What would you like to do: ";
}

int main()
{
    int balance = 0;
    int choice;

    cout << "Welcome to Landscaper 2024\n";
    cout << "You can cut lawns using just your teeth to earn money.\n";

    while (true)
    {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "You spent the day cutting lawns with your teeth and earned $1.\n";
            balance += 1;
            break;
        case 2:
            cout << "Your balance is: $" << balance << "\n";
            break;
        case 3:
            cout << "Thank you for playing! Your final balance is: $" << balance << "\n";
            return 0;
        default:
            cout << "Invalid choice. Please choose again.\n";
        }
    }
}