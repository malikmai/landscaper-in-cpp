#include <iostream>
#include <map>
#include <cstdlib>
#include <ctime> 

/*
#include <iostream>: Includes the input-output stream library.
#include <map>: Includes the map container library.
#include <cstdlib> and #include <ctime>: Includes libraries for random number generation.
using namespace std: Allows using standard library names without prefixing them with std::.
*/


using namespace std;

// Enum to represent different tools (inventory)
enum Tools
{
    TEETH,
    SCISSORS,
    PUSH_LAWNMOWER,
    BATTERY_LAWNMOWER,
    TEAM
};

// Function to display the main menu
void displayMenu()
{
    cout << "\n--- Landscaper 2024 ---\n";
    cout << "1. Cut lawns\n";
    cout << "2. Visit shop\n";
    cout << "3. Check balance\n";
    cout << "4. View inventory\n";
    cout << "5. Reset game\n";
    cout << "6. Quit\n";
    cout << "What would you like to do?: ";
}

// Function to display the shop menu
void displayShop(int balance, map<Tools, int> &inventory)
{
    cout << "\n--- Shop ---\n";
    cout << "Your current balance is: $" << balance << "\n";
    cout << "1. Buy rusty scissors ($5)\n";
    cout << "2. Buy push lawnmower ($50)\n";
    cout << "3. Buy battery-powered lawnmower ($500)\n";
    cout << "4. Hire a landscaping team ($1000)\n";
    cout << "5. Sell rusty scissors ($2)\n";
    cout << "6. Sell push lawnmower ($25)\n";
    cout << "7. Sell battery-powered lawnmower ($250)\n";
    cout << "8. Sell landscaping team ($500)\n";
    cout << "9. Exit shop\n";
    cout << "Choose an option: ";
}

// Function to reset the game state
void resetGame(int &balance, map<Tools, int> &inventory, int &earningRate, int &days)
{
    balance = 0;
    inventory.clear();    // Clear all items from the inventory
    inventory[TEETH] = 1; // Teeth are always present
    earningRate = 1;
    days = 0;
}

// Function to calculate the total earnings rate based on inventory
int calculateEarnings(const map<Tools, int> &inventory)
{
    int rate = 0;
    rate += inventory.find(TEETH)->second * 1;
    rate += inventory.find(SCISSORS)->second * 5;
    rate += inventory.find(PUSH_LAWNMOWER)->second * 20;
    rate += inventory.find(BATTERY_LAWNMOWER)->second * 50;
    rate += inventory.find(TEAM)->second * 100;
    return rate;
}

// Function to display the player's inventory
void displayInventory(const map<Tools, int> &inventory)
{
    cout << "\n--- Inventory ---\n";
    map<Tools, int>::const_iterator it;
    for (it = inventory.begin(); it != inventory.end(); ++it)
    {
        switch (it->first)
        {
        case TEETH:
            cout << "Teeth: " << it->second << "\n";
            break;
        case SCISSORS:
            cout << "Rusty Scissors: " << it->second << "\n";
            break;
        case PUSH_LAWNMOWER:
            cout << "Push Lawnmower: " << it->second << "\n";
            break;
        case BATTERY_LAWNMOWER:
            cout << "Battery-Powered Lawnmower: " << it->second << "\n";
            break;
        case TEAM:
            cout << "Landscaping Team: " << it->second << "\n";
            break;
        }
    }
}

int main()
{
    int balance = 0;           // Player's starting balance
    int choice;                // Variable to store player's menu choice
    int days = 0;              // Variable to track the number of days
    const int timeLimit = 60;  // Time limit in days
    map<Tools, int> inventory; // Inventory to store tools
    inventory[TEETH] = 1;      // Start with teeth
    inventory[SCISSORS] = 0;
    inventory[PUSH_LAWNMOWER] = 0;
    inventory[BATTERY_LAWNMOWER] = 0;
    inventory[TEAM] = 0;
    int earningRate = 1; // Initial earning rate

    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator

    cout << "Welcome to Landscaper 2024!\n";
    cout << "You must find a way to earn money cutting grass to earn $5000 within 60 days. Better start with your teeth!\n";

    while (true)
    {
        displayMenu(); // Display the main menu
        cin >> choice; // Get the player's choice

        switch (choice)
        {
        case 1:
            // Case 1: Cut lawns
            days++;
            if (days > timeLimit)
            {
                // If the player runs out of time, end the game with a loss message
                cout << "You ran out of time! You did not reach your goal of $5000 within 60 days.\n";
                return 0;
            }
            {
                // Generate a random multiplier for earnings
                int randomMultiplier = (rand() % 5) + 1; // Generate a random multiplier between 1 and 5
                int earnings = earningRate * randomMultiplier;
                balance += earnings;
                cout << "You spent the day cutting lawns and earned $" << earnings << ".\n";
                cout << "Day " << days << ": Your current balance is: $" << balance << "\n";
                if (balance >= 5000)
                {
                    // If the player reaches $5000, end the game with a win message
                    cout << "Congratulations! You've won the game with a balance of $" << balance << " in " << days << " days!\n";
                    return 0;
                }
            }
            break;
        case 2:
            // Case 2: Visit the shop
            int shopChoice;
            while (true)
            {
                displayShop(balance, inventory); // Display the shop menu
                cin >> shopChoice;               // Get the player's shop choice

                if (shopChoice == 9)
                {
                    // Exit shop
                    break;
                }

                switch (shopChoice)
                {
                case 1:
                    // Buy rusty scissors
                    if (balance >= 5)
                    {
                        cout << "You bought a pair of rusty scissors!\n";
                        balance -= 5;
                        inventory[SCISSORS]++;
                        earningRate = calculateEarnings(inventory);
                    }
                    else
                    {
                        cout << "You don't have enough money to buy scissors.\n";
                    }
                    break;
                case 2:
                    // Buy push lawnmower
                    if (balance >= 50)
                    {
                        cout << "You bought a push lawnmower!\n";
                        balance -= 50;
                        inventory[PUSH_LAWNMOWER]++;
                        earningRate = calculateEarnings(inventory);
                    }
                    else
                    {
                        cout << "You don't have enough money to buy a push lawnmower.\n";
                    }
                    break;
                case 3:
                    // Buy battery-powered lawnmower
                    if (balance >= 500)
                    {
                        cout << "You bought a battery-powered lawnmower!\n";
                        balance -= 500;
                        inventory[BATTERY_LAWNMOWER]++;
                        earningRate = calculateEarnings(inventory);
                    }
                    else
                    {
                        cout << "You don't have enough money to buy a battery-powered lawnmower.\n";
                    }
                    break;
                case 4:
                    // Hire landscaping team
                    if (balance >= 1000)
                    {
                        cout << "You hired a landscaping team!\n";
                        balance -= 1000;
                        inventory[TEAM]++;
                        earningRate = calculateEarnings(inventory);
                    }
                    else
                    {
                        cout << "You don't have enough money to hire a team.\n";
                    }
                    break;
                case 5:
                    // Sell rusty scissors
                    if (inventory[SCISSORS] > 0)
                    {
                        cout << "You sold a pair of rusty scissors!\n";
                        balance += 2;
                        inventory[SCISSORS]--;
                        earningRate = calculateEarnings(inventory);
                    }
                    else
                    {
                        cout << "You don't have any rusty scissors to sell.\n";
                    }
                    break;
                case 6:
                    // Sell push lawnmower
                    if (inventory[PUSH_LAWNMOWER] > 0)
                    {
                        cout << "You sold a push lawnmower!\n";
                        balance += 25;
                        inventory[PUSH_LAWNMOWER]--;
                        earningRate = calculateEarnings(inventory);
                    }
                    else
                    {
                        cout << "You don't have any push lawnmowers to sell.\n";
                    }
                    break;
                case 7:
                    // Sell battery-powered lawnmower
                    if (inventory[BATTERY_LAWNMOWER] > 0)
                    {
                        cout << "You sold a battery-powered lawnmower!\n";
                        balance += 250;
                        inventory[BATTERY_LAWNMOWER]--;
                        earningRate = calculateEarnings(inventory);
                    }
                    else
                    {
                        cout << "You don't have any battery-powered lawnmowers to sell.\n";
                    }
                    break;
                case 8:
                    // Sell landscaping team
                    if (inventory[TEAM] > 0)
                    {
                        cout << "You sold a landscaping team!\n";
                        balance += 500;
                        inventory[TEAM]--;
                        earningRate = calculateEarnings(inventory);
                    }
                    else
                    {
                        cout << "You don't have any landscaping teams to sell.\n";
                    }
                    break;
                default:
                    cout << "Invalid choice. Please choose again.\n";
                }
            }
            break;
        case 3:
            // Case 3: Check balance
            cout << "Your current balance is: $" << balance << "\n";
            break;
        case 4:
            // Case 4: View inventory
            displayInventory(inventory);
            break;
        case 5:
            // Case 5: Reset game
            resetGame(balance, inventory, earningRate, days);
            cout << "The game has been reset.\n";
            break;
        case 6:
            // Case 6: Quit game
            cout << "Thank you for playing! Your final balance is: $" << balance << "\n";
            return 0;
        default:
            cout << "Invalid choice. Please choose again.\n";
        }
    }
}
