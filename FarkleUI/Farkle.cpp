#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include "MyForm.h"
using namespace std;
using namespace System;
using namespace System::Windows::Forms;

int calc_score(int dice_roll[], int size)
{
    if (size == 0)
    {
        return 0;
    }

    // Count occurences of each die value (1-6)
    int dice_counts[] = { 0, 0, 0, 0, 0, 0 };

    for (int i = 0; i < size; i++)
    {
        int die = dice_roll[i];
        dice_counts[die - 1] += 1;
    }

    // Initialise player score
    int score = 0;

    // Check for a straight (1, 2, 3, 4, 5, 6)
    if (size == 6)
    {
        int straight[] = { 1, 1, 1, 1, 1, 1 };
        if (equal(begin(dice_counts), end(dice_counts), begin(straight)))
        {
            return 1500; // Straight scores 1500, no need to check anything else
        }
    }

    // Check for a partial straight
    if (size >= 5)
    {
        // Two possible 5-die partial straights
        int par_straight_a[] = { 1, 1, 1, 1, 1, 0 };
        int par_straight_b[] = { 0, 1, 1, 1, 1, 1 };
        if (equal(begin(dice_counts), end(dice_counts), begin(par_straight_a)))
        {
            score = 500;
            if (size == 5)
            {
                return score; // Can't score anything else
            }
        }
        else if (equal(begin(dice_counts), end(dice_counts), begin(par_straight_b)))
        {
            score = 750;

            if (size == 5)
            {
                return score; // Can't score anything else
            }
        }


    }

    // Check for three-of-a-kind or higher
    // Apart from 1s, scores are 100 x dice number, then doubled for each extra die
    for (int i = 0; i < 6; i++)
    {
        if (dice_counts[i] >= 3)
        {
            int multiplier = 1 << (dice_counts[i] - 3);
            int base_score;

            // 1s are special - starts at 1000 for three-of-a-kind
            if (i == 0)
            {
                base_score = (i + 1) * 1000;
            }
            else
            {
                base_score = (i + 1) * 100;
            }

            int actual_score = base_score * multiplier;

            if (dice_counts[i] == 6) return actual_score; // Can't score with any more dice, so return

            score += actual_score;
            dice_counts[i] = 0; // Don't count these dice individually - remove them
        }
    }

    // Count individual kept 1s and 5s
    score += dice_counts[0] * 100; // 1s are 100 points each
    score += dice_counts[4] * 50; // 5s are 50 points each

    return score;
}

vector<int> dice_thrower(int num_dice)
{
    if (num_dice < 1 || num_dice > 6)
    {
        throw invalid_argument("Number of dice must be between 1 and 6.");
    }

    random_device rd; // Seed
    mt19937 gen(rd()); // Mersenne Twister RNG
    uniform_int_distribution<int> dist(1, 6); // Keep them in range!

    vector<int> dice(num_dice);
    for (int& num : dice)
    {
        num = dist(gen);
    }

    return dice;
}

// Show throw result to user
void list_dice(vector<int> thrown_dice)
{
    for (int num : thrown_dice)
    {
        cout << "\n" << num;
    }
}

void choose_dice(int choose_up_to)
{
    int i = 0;
    bool stop = false;
    string user_input;

    while (!stop && i < choose_up_to)
    {

        cout << "\nChoose a dice to hold? Y/N: ";
        user_input = cin.get();
    }
}

[STAThread]
int main()
{
    // UI Initialisation
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew FarkleUI::MyForm());

    cout << "Welcome to Farkle! You win when you reach a score of 4000.\nPress enter to begin!";
    cin.get();
    cout << "Dice:";

    vector<int> thrown_dice = dice_thrower(6); // Get random dice throw
    list_dice(thrown_dice);
    choose_dice(6);

    int selection[] = { 4, 4, 4, 4, 5, 5 };
    int selection_size = sizeof(selection) / sizeof(selection[0]);
    int round_score = calc_score(selection, selection_size);
    cout << "\n\nYou scored: " + to_string(round_score);

    return 0;
}