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

void makemaze()
{
//   12345678901234
// 1 ..............
// 2 ......*.......
// 3 ..............
// 4 ..*...........
// 5 ......*.......

    setSize(5,14);
    setWall(4,3);
    setWall(2,7);
    setWall(5,7);
}

void testone(int n)
{
    int ns = 0;
    switch (n)
    {
        default: {
            cout << "Bad argument" << endl;
        } break; case  1: {
            assert(hasCorrectForm(""));
        } break; case  2: {
            assert(!hasCorrectForm(" "));
        } break; case  3: {
            assert(!hasCorrectForm("X"));
        } break; case  4: {
            assert(!hasCorrectForm("#"));
        } break; case  5: {
            assert(!hasCorrectForm("1x"));
        } break; case  6: {
            assert(!hasCorrectForm("12"));
        } break; case  7: {
            assert(hasCorrectForm("03r"));
        } break; case  8: {
            assert(!hasCorrectForm("003r"));
        } break; case  9: {
            assert(!hasCorrectForm("1R#"));
        } break; case 10: {
            assert(hasCorrectForm("L"));
        } break; case 11: {
            assert(hasCorrectForm("2l"));
        } break; case 12: {
            assert(hasCorrectForm("10R"));
        } break; case 13: {
            assert(hasCorrectForm("98R"));
        } break; case 14: {
            assert(hasCorrectForm("RL"));
        } break; case 15: {
            assert(hasCorrectForm("1rl"));
        } break; case 16: {
            assert(hasCorrectForm("r1l"));
        } break; case 17: {
            assert(hasCorrectForm("1R2L"));
        } break; case 18: {
            assert(hasCorrectForm("24R3L"));
        } break; case 19: {
            assert(hasCorrectForm("1R24L"));
        } break; case 20: {
            assert(hasCorrectForm("24R24L"));
        } break; case 21: {
            assert(hasCorrectForm("1R24LL"));
        } break; case 22: {
            assert(!hasCorrectForm("24R24LxL"));
        } break; case 23: {
            assert(!hasCorrectForm("24R24L1xL"));
        } break; case 24: {
            assert(!hasCorrectForm("24R24L24xL"));
        } break; case 25: {
            makemaze();
            assert(determineSafeDistance(0,4,'S',2) == -1);
        } break; case 26: {
            makemaze();
            assert(determineSafeDistance(6,4,'N',2) == -1);
        } break; case 27: {
            makemaze();
            assert(determineSafeDistance(3,0,'E',2) == -1);
        } break; case 28: {
            makemaze();
            assert(determineSafeDistance(3,15,'W',2) == -1);
        } break; case 29: {
            makemaze();
            assert(determineSafeDistance(4,3,'E',2) == -1);
        } break; case 30: {
            makemaze();
            assert(determineSafeDistance(3,4,'E',-2) == -1);
        } break; case 31: {
            makemaze();
            assert(determineSafeDistance(3,4,'E',0) == 0);
        } break; case 32: {
            makemaze();
            assert(determineSafeDistance(3,4,'e',2) == 2);
        } break; case 33: {
            makemaze();
            assert(determineSafeDistance(1,3,'s',2) == 2);
        } break; case 34: {
            makemaze();
            assert(determineSafeDistance(1,3,'w',2) == 2);
        } break; case 35: {
            makemaze();
            assert(determineSafeDistance(3,7,'n',0) == 0);
        } break; case 36: {
            makemaze();
            assert(determineSafeDistance(3,7,'E',2) == 2);
        } break; case 37: {
            makemaze();
            assert(determineSafeDistance(3,6,'S',2) == 2);
        } break; case 38: {
            makemaze();
            assert(determineSafeDistance(3,6,'N',2) == 2);
        } break; case 39: {
            makemaze();
            assert(determineSafeDistance(2,3,'S',3) == 1);
        } break; case 40: {
            makemaze();
            assert(determineSafeDistance(2,8,'W',3) == 0);
        } break; case 41: {
            makemaze();
            assert(determineSafeDistance(4,7,'N',2) == 1);
        } break; case 42: {
            makemaze();
            assert(determineSafeDistance(2,3,'E',8) == 3);
        } break; case 43: {
            makemaze();
            assert(determineSafeDistance(4,5,'W',8) == 1);
        } break; case 44: {
            makemaze();
            assert(determineSafeDistance(3,4,'W',4) == 3);
        } break; case 45: {
            makemaze();
            assert(determineSafeDistance(3,4,'e',12) == 10);
        } break; case 46: {
            makemaze();
            assert(determineSafeDistance(3,4,'S',3) == 2);
        } break; case 47: {
            makemaze();
            assert(determineSafeDistance(3,4,'N',4) == 2);
        } break; case 48: {
            makemaze();
            assert(obeyPlan(0,4,1,4,'S',"1L",ns) == 2);
            assert(obeyPlan(4,0,4,1,'E',"1L",ns) == 2);
        } break; case 49: {
            makemaze();
            assert(obeyPlan(6,2,5,2,'N',"1L",ns) == 2);
            assert(obeyPlan(1,15,1,14,'W',"1L",ns) == 2);
        } break; case 50: {
            makemaze();
            assert(obeyPlan(1,4,0,4,'N',"1L",ns) == 2);
            assert(obeyPlan(4,1,4,0,'W',"1L",ns) == 2);
        } break; case 51: {
            makemaze();
            assert(obeyPlan(5,2,6,2,'S',"1L",ns) == 2);
            assert(obeyPlan(1,14,1,15,'E',"1L",ns) == 2);
        } break; case 52: {
            makemaze();
            assert(obeyPlan(3,10,3,2,'w',"X",ns) == 2);
        } break; case 53: {
            makemaze();
            assert(obeyPlan(3,10,3,2,'w',"008L",ns) == 2);
        } break; case 54: {
            makemaze();
            int r = obeyPlan(3,10,3,2,'w',"88L",ns);
            assert(r == 3  ||  r == 1  ||  r == 0);
        } break; case 55: {
            makemaze();
            assert(obeyPlan(3,5,2,4,'?',"1L",ns) == 2);
        } break; case 56: {
            makemaze();
            assert(obeyPlan(2,7,2,6,'W',"1L",ns) == 2);
        } break; case 57: {
            makemaze();
            assert(obeyPlan(2,6,2,7,'E',"1L",ns) == 2);
        } break; case 58: {
            makemaze();
            ns = 999;
            bool b1 = (obeyPlan(0,4,1,4,'S',"1L",ns) == 2);
            assert(!b1 || ns == 999);
            ns = 999;
            bool b2 = (obeyPlan(4,0,4,1,'E',"1L",ns) == 2);
            assert(!b2 || ns == 999);
            assert(b1 || b2);
        } break; case 59: {
            makemaze();
            ns = 999;
            bool b1 = (obeyPlan(5,2,6,2,'S',"1L",ns) == 2);
            assert(!b1 || ns == 999);
            ns = 999;
            bool b2 = (obeyPlan(1,14,1,15,'E',"1L",ns) == 2);
            assert(!b2 || ns == 999);
            assert(b1 || b2);
        } break; case 60: {
            makemaze();
            ns = 999;
            bool b1 = obeyPlan(3,10,3,1,'w',"X",ns);
            assert(!b1 || ns == 999);
            ns = 999;
            bool b2 = (obeyPlan(3,4,2,4,'?',"1L",ns) == 2);
            assert(!b2 || ns == 999);
            ns = 999;
            bool b3 = (obeyPlan(2,7,2,6,'E',"1L",ns) == 2);
            assert(!b3 || ns == 999);
            assert(b1 || b2 || b3);
        } break; case 61: {
            makemaze();
            assert(obeyPlan(4,7,1,7,'n',"3R",ns) == 3  &&  ns == 1);
        } break; case 62: {
            makemaze();
            assert(obeyPlan(4,6,2,8,'n',"2R2R",ns) == 3  &&  ns == 2);
        } break; case 63: {
            makemaze();
            assert(obeyPlan(4,5,2,8,'n',"2R3R",ns) == 3  &&  ns == 3);
        } break; case 64: {
            makemaze();
            assert(obeyPlan(4,4,4,4,'e',"1RR2L",ns) == 3  &&  ns == 2);
        } break; case 65: {
            makemaze();
            assert(obeyPlan(3,13,3,12,'e',"2RR3L",ns) == 3  &&  ns == 1);
        } break; case 66: {
            makemaze();
            assert(obeyPlan(5,13,3,12,'n',"2R2RR3L",ns) == 3  &&  ns == 3);
        } break; case 67: {
            makemaze();
            assert(obeyPlan(4,5,5,4,'s',"2RR1L",ns) == 3  &&  ns == 1);
        } break; case 68: {
            makemaze();
            assert(obeyPlan(3,4,1,5,'n',"3RR1L",ns) == 3  &&  ns == 2);
        } break; case 69: {
            makemaze();
            assert(obeyPlan(3,5,1,2,'w',"5R2R2R",ns) == 3  &&  ns == 4);
        } break; case 70: {
            makemaze();
            ns = 999; obeyPlan(4,7,1,7,'n',"3R",ns);
            assert(ns > 0  &&  ns < 10);
            ns = 999; obeyPlan(4,6,2,8,'n',"2R2R",ns);
            assert(ns > 0  &&  ns < 10);
            ns = 999; obeyPlan(4,5,2,8,'n',"2R3R",ns);
            assert(ns > 0  &&  ns < 10);
            ns = 999; obeyPlan(4,4,4,4,'e',"1RR2L",ns);
            assert(ns > 0  &&  ns < 10);
        } break; case 71: {
            makemaze();
            ns = 999; obeyPlan(3,13,3,12,'e',"2RR3L",ns);
            assert(ns > 0  &&  ns < 10);
            ns = 999; obeyPlan(5,13,3,12,'n',"2R2RR3L",ns);
            assert(ns > 0  &&  ns < 10);
            ns = 999; obeyPlan(4,5,5,4,'s',"2RR1L",ns);
            assert(ns > 0  &&  ns < 10);
            ns = 999; obeyPlan(3,4,1,5,'n',"3RR1L",ns);
            assert(ns > 0  &&  ns < 10);
            ns = 999; obeyPlan(3,5,1,2,'w',"5R2R2R",ns);
            assert(ns > 0  &&  ns < 10);
        } break; case 72: {
            makemaze();
            assert(obeyPlan(5,3,5,3,'e',"",ns) == 0  &&  ns == 0);
            assert(obeyPlan(5,3,5,4,'e',"",ns) == 1  &&  ns == 0);
        } break; case 73: {
            makemaze();
            assert(obeyPlan(2,1,2,4,'e',"3L",ns) == 0  &&  ns == 3);
        } break; case 74: {
            makemaze();
            assert(obeyPlan(2,1,2,4,'e',"03L",ns) == 0  &&  ns == 3);
        } break; case 75: {
            setSize(3,30);
            assert(obeyPlan(2,2,2,29,'e',"27L",ns) == 0  &&  ns == 27);
        } break; case 76: {
            makemaze();
            assert(obeyPlan(2,1,2,3,'e',"3L",ns) == 1  &&  ns == 3);
        } break; case 77: {
            makemaze();
            assert(obeyPlan(2,1,2,5,'e',"3L",ns) == 1  &&  ns == 3);
        } break; case 78: {
            makemaze();
            assert(obeyPlan(5,3,5,3,'e',"1L",ns) == 1  &&  ns == 1);
        } break; case 79: {
            makemaze();
            ns = 999;
            obeyPlan(5,3,5,3,'e',"1L",ns);
            assert(ns == 1);
        } break; case 80: {
            makemaze();
            assert(obeyPlan(5,3,2,8,'e',"2L1R3L2R",ns) == 0  &&  ns == 8);
        } break; case 81: {
            makemaze();
            assert(obeyPlan(5,3,2,8,'e',"2L1R3L3R",ns) == 1  &&  ns == 9);
        } break; case 82: {
            makemaze();
            assert(obeyPlan(5,3,2,8,'s',"RRLRR2RLL1RRRRR3LLRRL2RLLR",ns) == 0  &&  ns == 8);
        } break; case 83: {
            makemaze();
            assert(obeyPlan(5,3,2,8,'s',"RRLRR2RLL1RRRRR3LLRRL3RLLR",ns) == 1  &&  ns == 9);
        } break; case 84: {
            setSize(25,30);
            assert(obeyPlan(1,30,24,15,'w',"13L19LRR15L3L26R1R13R",ns) == 0  &&  ns == 90);
        } break; case 85: {
            setSize(25,30);
            assert(obeyPlan(1,30,24,15,'w',"13L19LRR15L3L26R1R14R",ns) == 1  &&  ns == 91);
        }
    }
}

int main()
{
    cout << "Enter test number: ";
    int n;
    cin >> n;
    testone(n);
    cout << "Passed!" << endl;
}
