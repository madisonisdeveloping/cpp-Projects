// -------------------------------------------------------
// Description: This program is a simple text-based Rock Paper Scissors where the player competes against the computer.
// Program Logic (pseudo code):
// 1. Display the game menu to the user (Rock, Paper, Scissors, or Exit).
// 2. Prompt the user to select a move (1-4) and validate the selection.
// 3. If the user selects "Exit", terminate the program; otherwise, continue.
// 4. Generate a random choice for the computer (Rock, Paper, or Scissors).
// 5. Compare the player's choice with the computer's choice:
//    If both choices are the same, it's a tie.
//    If the player wins, display a victory.
//    If the computer wins, display a defeat.
// 6. Ask the user if they want to play again. If yes, repeat from step 1; if no, exit.
//----------------------------------------

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int GetUserChoice();
int GetComputerChoice();
bool DetermineWinner(int, int);
void DisplayChoice(int choice);

int main()
{
    char playerAnswer;
    bool quit = false;
    srand(time(0)); // for random # generating

    do
    {
        int userChoice = GetUserChoice();
        if (userChoice == 4) // exit program
        {
            quit = true;
            break;
        }

        int compChoice = GetComputerChoice();
        cout << "The computer's choice is: ";
        DisplayChoice(compChoice);
        cout << "Your choice is: ";
        DisplayChoice(userChoice);

        if (userChoice == compChoice)
        {
            cout << "It's a tie!" << endl;
        }
        else
        {

            bool result = DetermineWinner(userChoice, compChoice);
            if (result)
            {
                cout << "You win!" << endl;
            }
            else
            {
                cout << "Computer wins!" << endl;
            }
        }
        // another round
        bool donePlaying = false;
        while (!donePlaying)
        {
            cout << "Would you like to play again? Y/N" << endl;
            cin >> playerAnswer;
            if (tolower(playerAnswer) == 'y')
            {
                donePlaying = true;
            }
            else if (tolower(playerAnswer) == 'n')
            {
                donePlaying = true; // exit game if not 'Y' or 'y'
                quit = true;
            }
            else
            {
                cout << "Invalid input." << endl;
            }
        }

    } while (!quit);
    return 0;
}

int GetUserChoice()
{
    int selection = 0;
    cout << "Make your selection from the following menu:" << endl;
    cout << "1) Rock" << endl;
    cout << "2) Paper" << endl;
    cout << "3) Scissors" << endl;
    cout << "4) Exit Program" << endl;
    cout << "Pick an option 1-4: " << endl;
    cin >> selection;

    while (selection < 1 || selection > 4) // validating menu option
    {
        cout << "Please choose a number between 1 and 4: " << endl;
        cin >> selection;
    }
    return selection;
}

int GetComputerChoice()
{
    return 1 + (rand() % 3);
}

bool DetermineWinner(int userChoice, int compChoice)
{
    if (userChoice == 3 && compChoice == 2)
    {
        cout << "Scissors cut paper." << endl;
        return true; // player wins
    }
    if (userChoice == 2 && compChoice == 3)
    {
        cout << "Scissors cut paper." << endl;
        return false; // computer wins
    }
    if (userChoice == 2 && compChoice == 1)
    {
        cout << "Paper covers rock." << endl;
        return true; // player wins
    }
    if (userChoice == 1 && compChoice == 2)
    {
        cout << "Paper covers rock." << endl;
        return false; // computer wins
    }
    if (userChoice == 1 && compChoice == 3)
    {
        cout << "Rock crushes scissors." << endl;
        return true; // player wins
    }
    if (userChoice == 3 && compChoice == 1)
    {
        cout << "Rock crushes scissors." << endl;
        return false; // computer wins
    }
}

void DisplayChoice(int choice)
{
    switch (choice)
    {
    case 1:
        cout << "rock" << endl;
        break;
    case 2:
        cout << "paper" << endl;
        break;
    case 3:
        cout << "scissors" << endl;
        break;
    default:
        break;
    }
}

/* Output
Make your selection from the following menu:
1) Rock
2) Paper
3) Scissors
4) Exit Program
Pick an option 1-4:
3
The computer's choice is: rock
Your choice is: scissors
Rock crushes scissors.
Computer wins!
Would you like to play again? Y/N
y
Make your selection from the following menu:
1) Rock
2) Paper
3) Scissors
4) Exit Program
Pick an option 1-4:
1
The computer's choice is: scissors
Your choice is: rock
Rock crushes scissors.
You win!
Would you like to play again? Y/N
y
Make your selection from the following menu:
1) Rock
2) Paper
3) Scissors
4) Exit Program
Pick an option 1-4:
3
The computer's choice is: rock
Your choice is: scissors
Rock crushes scissors.
Computer wins!
Would you like to play again? Y/N
y
Make your selection from the following menu:
1) Rock
2) Paper
3) Scissors
4) Exit Program
Pick an option 1-4:
2
The computer's choice is: scissors
Your choice is: paper
Scissors cut paper.
Computer wins!
Would you like to play again? Y/N
n */
