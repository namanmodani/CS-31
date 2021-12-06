// Grid Game (F21-CS31-1 Project 3)
// Naman Modani

// Import library and header files
#include "grid.h"
#include <iostream>
#include <cassert>
#include <cctype>
#include <string>
using namespace std;

bool isDirection(char directionChar) {

    // This function returns true if the lowercase form of the input is a part of the string "news".
    // This helps us determine if a variable is an acceptable direction.

    string directionList = "news";
    char directionLower = tolower(directionChar);
    for (int i = 0; i < directionList.size(); i++) {
        if (directionLower == directionList.at(i)) {
            return true;
        }
    }

    return false;
}

bool validCoordinates(int r, int c) {

    // The function validCoordinates is used to determine whether a given set of coordinates (r, c) exists on the grid and is not occupied by a wall.
    // It tells us whether the coordinates are valid as starting or ending points.

    int nRow = getRows();
    int nCol = getCols();

    if (nRow == 0 || r < 1  || r > nRow || c < 1  || c > nCol || isWall(r, c)) {
        return false;
    }

    return true;
}

bool delta(char dir, int& dr, int& dc) {

    // Function delta helps us determine how moving in a particular direction impacts the coordinates.
    // Gives us values of dr and dc (the 'delta' or change in row/column number) and returns false if the direction is invalid.

    switch (tolower(dir))
    {
        case 'n':
            dr = -1; dc = 0;
            break;
        case 'e':
            dr = 0; dc = 1;
            break;
        case 'w':
            dr = 0; dc = -1;
            break;
        case 's':
            dr = 1; dc = 0;
            break;
        default:
            return false;
    }
    return true;
}

bool hasCorrectForm(string plan) {

    // This function returns true if its parameter is a plan. A string may be a plan without being obeyable in a particular grid.
    // A plan is a sequence of zero or more plan portions (not separated or surrounded by spaces, anything else; every character in a non-empty plan must be part of a portion).

    // Each iteration of the loop will check one plan portion.
    // We define a plan portion as zero, one, or two digits, followed by a turn letter.

    if (isdigit(plan[plan.length() - 1])) {
        return false;
    }

    else {
        size_t k = 0;
        while (k != plan.size()) {

            // Plan portion may (optionally) contain a digit.

            if (k != plan.size() && isdigit(plan.at(k))) {
                k++;

                // Plan portion may (optionally) contain another digit.

                if (k != plan.size() && isdigit(plan.at(k))) {
                    k++;
                }
            }

            // Plan portion must end in a valid turn letter.

            char turnLetter = tolower(plan.at(k));
            if (turnLetter != 'r' && turnLetter != 'l')
                return false;

            k++;
        }

        // At this point, the plan is correctly defined
        return true;
    }
}

int determineSafeDistance(int r, int c, char dir, int maxSteps) {

    // This function determines the number of steps a car starting at position (r,c) could travel in the direction indicated by dir.

    // Total number of rows: nr; Total number of columns: nc
    int nr = getRows();
    int nc = getCols();

    // If (r, c) is not a valid empty grid position, or if dir is not a direction letter, or if maxSteps is negative, return -1
    if ((r < 1) || (c < 1) || (r > nr) || (c > nc) || isWall(r, c) || !isDirection(dir) || (maxSteps < 0)) {
        return -1;
    }

    int dr;
    int dc;

    if (!delta(dir, dr,dc)) {
        return -1;
    }

    // Try to move maxSteps steps in the given direction

    int steps;
    for (steps = 0; steps < maxSteps; steps++) {

        // Take one step
        r += dr;
        c += dc;

        // If it results in running off the grid or hitting a wall, stop moving
        if ((r < 1) || (c < 1) || (r > nr) || (c > nc) || isWall(r, c)) {
            break;
        }
    }
    return steps;
}

int obeyPlan(int sr, int sc, int er, int ec, char dir, string plan, int& nsteps) {

    // Ensure (sr, sc) and (er, ec) are valid empty grid cells, and that the plan is syntactically correct.

    if (!validCoordinates(sr, sc) || !validCoordinates(er, ec) || !hasCorrectForm(plan)) {
        return 2;
    }

    // Intialize dirIndex to change cardinal directions to mod 4.

    char direction = tolower(dir);
    int dirIndex;

    if (direction == 'n') {
        dirIndex = 0;
    }
    else if (direction == 'e') {
        dirIndex = 1;
    }
    else if (direction == 's') {
        dirIndex = 2;
    }
    else if (direction == 'w') {
        dirIndex = 3;
    }
    else {
        return 2;
    }

    nsteps = 0;

    // For loop to iterate through the plan.

    for (int i = 0; i != plan.size(); i++) {

        // Modify dirIndex based on the alphabets in the string (right or left).

        if (isalpha(plan.at(i))) {
            if (plan[i] == 'R' || plan[i] == 'r') {
                dirIndex++;
            }
            else {
                dirIndex--;
            }
            dirIndex %= 4;
            continue;
        }

        int steps = 0;
        bool doubleDigit = false;

        // Assign upto two digit numbers to the variable steps.

        if (isdigit(plan[i])) {
            if (isdigit(plan[i + 1])) {
                steps = (10 * (plan[i] - '0') + (plan[i + 1] - '0'));
                doubleDigit = true;
            }
            else {
                steps = (plan[i] - '0');
            }
        }

        // Conduct a stepwise movement, and stop when invalidity strikes.

        for (int j = steps; j > 0; j--) {
            if (dirIndex == 0) {
                sr--;
            }
            if (dirIndex == 1) {
                sc++;
            }
            if (dirIndex == 2) {
                sr++;
            }
            if (dirIndex == 3) {
                sc--;
            }
            if (!(validCoordinates(sr, sc))) {
                return 3;
            }
            nsteps++;
        }

        // Skip next digit if double, since it has already been accounted for.

        if (doubleDigit) {
            i++;
        }
    }

        // Successful journey when planned end coordinates as same as mutated starting coordinates.

        if ((sr == er) && (sc == ec)) {
            return 0;
        }

        // Return 1 on obeying the plan, but ending up in a different planned end coordinate.

        return 1;
}

int main() {}
