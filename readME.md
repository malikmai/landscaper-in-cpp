## Landscaper 2024

## Concept of the Game

Landscaper 2024 is a simple terminal-based game where the player starts a landscaping business using only their teeth. The goal is to earn $5000 within 60 days by cutting grass and purchasing better tools to increase earnings. The player must strategically use their resources and manage their time to reach the goal before the time runs out.

## Game Story

Welcome to the Landscaper 2024! You are an aspiring entrepreneur with a unique approach to landscaping. With nothing but your teeth to start with, you must find a way to earn money by cutting grass. As you earn money, you can purchase better tools from the store to increase your efficiency and earnings. The challenge is to reach $5000 within 60 days. Can you do it?

## Download and Install

1. Clone the repository to your local machine:
   ```sh
   git clone https://github.com/malikmai/landscaper-in-cpp.git

2. Navigate to the project directory:
    ```sh
    cd landscaper-in-cpp

3. Compile the game using a C++ compiler:
    ```sh
    g++ -o game game.cpp

4. Run the game:
    ```sh
    ./game

## Gameplay Loop

1. Cut Lawns: Each day, you can choose to cut lawns to earn money. The amount of money earned each day is a random value based on the tools you have.

2. Visit Shop: Use the money you earn to purchase better tools from the shop. Better tools increase your earning rate, allowing you to make more money each day.

3. Check Balance: View your current balance to see how much money you have accumulated.

4. View Inventory: Check the tools you have purchased and their quantities.

5. Reset Game: Reset the game to start over.

6. Quit: Exit the game.

## Store and Inventory System

## Store
In the shop, you can buy and sell various tools:

1. Buy Rusty Scissors: Costs $5 and increases your earning rate by 5.

2. Buy Push Lawnmower: Costs $50 and increases your earning rate by 20.

3. Buy Battery-Powered Lawnmower: Costs $500 and increases your earning rate by 50.

4. Hire Landscaping Team: Costs $1000 and increases your earning rate by 100.

You can also sell tools for half their purchase price.

## Inventory
The inventory tracks the tools you have purchased and their quantities:

1. Teeth: Always present and gives a base earning rate of 1.

2. Rusty Scissors: Increases earning rate by 5 per pair.

3. Push Lawnmower: Increases earning rate by 20 per mower.

4. Battery-Powered Lawnmower: Increases earning rate by 50 per mower.

5. Landscaping Team: Increases earning rate by 100 per team.

## Objective
The objective of the game is to strategically manage your resources and reach a balance of $5000 within 60 days. Each day only passes when you cut grass, so plan your purchases wisely and optimize your earnings to achieve your goal.

Enjoy the game!
