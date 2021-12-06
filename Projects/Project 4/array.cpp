// Array of Sunshine (F21-CS31-1 Project 4)
// Naman Modani

#include <iostream>
#include <string>
#include <cassert>
#include <cctype>
#include <cmath>
using namespace std;

bool isInvalidSize(int n);
bool isInvalidPosition(int n, int position);
int reduplicate(string a[], int n);
int locate(const string a[], int n, string target);
int locationOfMax(const string a[], int n);
int circleLeft(string a[], int n, int pos);
int enumerateRuns(const string a[], int n);
int flip(string a[], int n);
int locateDifference(const string a1[], int n1, const string a2[], int n2);
int subsequence(const string a1[], int n1, const string a2[], int n2);
int locateAny(const string a1[], int n1, const string a2[], int n2);
int separate(string a[], int n, string separator);

void testone(int n)
{
    const int N = 6;

    string aa[1+N+1] = {
            "", "alpha", "beta", "gamma", "gamma", "beta", "delta", ""
    };
    string* a = &aa[1];
    string* z = aa;
    a[-1].string::~string();
    a[N].string::~string();
    fill_n(reinterpret_cast<char*>(&a[-1]), sizeof(a[-1]), 0xEF);
    fill_n(reinterpret_cast<char*>(&a[N]), sizeof(a[N]), 0xEF);

    string b[N] = {
            "alpha", "beta", "gamma", "delta", "beta", "delta"
    };

    string d[9] = {
            "alpha", "beta",  "beta", "beta", "alpha",
            "alpha", "delta", "beta", "beta"
    };

    switch (n)
    {
        case  1: {
            assert(reduplicate(z, -1) == -1 && a[0] == "alpha");
        } break; case  2: {
            assert(reduplicate(z, 0) == 0 && a[0] == "alpha");
        } break; case  3: {
            assert(reduplicate(a, 1) == 1 && a[0] == "alphaalpha" &&
                   a[1] == "beta");
        } break; case  4: {
            a[4] = "";
            assert(reduplicate(a, 6) == 6 && a[0] == "alphaalpha" &&
                   a[1] == "betabeta" && a[2] == "gammagamma" &&
                   a[3] == "gammagamma" && a[4] == "" &&  a[5] == "deltadelta");
        } break; case  5: {
            assert(locate(z, -1, "alpha") == -1);
        } break; case  6: {
            assert(locate(z, 0, "alpha") == -1);
        } break; case  7: {
            assert(locate(a, 1, "alpha") == 0);
        } break; case  8: {
            assert(locate(a, 6, "delta") == 5);
        } break; case  9: {
            assert(locate(a, 6, "beta") == 1);
        } break; case 10: {
            assert(locate(a, 6, "zeta") == -1);
        } break; case 11: {
            assert(locationOfMax(z, -1) == -1);
        } break; case 12: {
            assert(locationOfMax(z, 0) == -1);
        } break; case 13: {
            assert(locationOfMax(a, 1) == 0);
        } break; case 14: {
            assert(locationOfMax(a, 3) == 2);
        } break; case 15: {
            assert(locationOfMax(a, 6) == 2);
        } break; case 16: {
            assert(locationOfMax(a+3, 3) == 0);
        } break; case 17: {
            a[0] = "";
            a[1] = " ";
            a[2] = "";
            assert(locationOfMax(a, 3) == 1);
        } break; case 18: {
            assert(circleLeft(z, -1, 0) == -1 &&
                   a[0] == "alpha" && a[1] == "beta");
        } break; case 19: {
            assert(circleLeft(a, 6, -1) == -1 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 20: {
            assert(circleLeft(a, 6, 6) == -1 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 21: {
            assert(circleLeft(z, 0, 0) == -1 &&
                   a[0] == "alpha" && a[1] == "beta");
        } break; case 22: {
            assert(circleLeft(a, 1, 0) == 0 &&
                   a[0] == "alpha" && a[1] == "beta");
        } break; case 23: {
            assert(circleLeft(a, 6, 0) == 0 &&
                   a[0] == "beta" && a[1] == "gamma" && a[2] == "gamma" &&
                   a[3] == "beta" && a[4] == "delta" && a[5] == "alpha");
        } break; case 24: {
            assert(circleLeft(a, 6, 5) == 5 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 25: {
            assert(circleLeft(a, 6, 3) == 3 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "beta" && a[4] == "delta" && a[5] == "gamma");
        } break; case 26: {
            assert(circleLeft(a, 5, 3) == 3 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "beta" && a[4] == "gamma" && a[5] == "delta");
        } break; case 27: {
            assert(enumerateRuns(z, -1) == -1);
        } break; case 28: {
            assert(enumerateRuns(z, 0) == 0);
        } break; case 29: {
            assert(enumerateRuns(a, 1) == 1);
        } break; case 30: {
            assert(enumerateRuns(a, 3) == 3);
        } break; case 31: {
            assert(enumerateRuns(a, 4) == 3);
        } break; case 32: {
            assert(enumerateRuns(a+2, 4) == 3);
        } break; case 33: {
            assert(enumerateRuns(d, 9) == 5);
        } break; case 34: {
            assert(flip(z, -1) == -1 && a[0] == "alpha");
        } break; case 35: {
            assert(flip(z, 0) == 0 && a[0] == "alpha");
        } break; case 36: {
            assert(flip(a, 1) == 1 && a[0] == "alpha" &&
                   a[1] == "beta");
        } break; case 37: {
            assert(flip(a, 2) == 2 && a[0] == "beta" &&
                   a[1] == "alpha" && a[2] == "gamma");
        } break; case 38: {
            assert(flip(a, 5) == 5 && a[0] == "beta" &&
                   a[1] == "gamma" && a[2] == "gamma" && a[3] == "beta" &&
                   a[4] == "alpha" && a[5] == "delta");
        } break; case 39: {
            a[2] = "zeta";
            assert(flip(a,6) == 6 && a[0] == "delta" && a[1] == "beta" &&
                   a[2] == "gamma" && a[3] == "zeta" && a[4] == "beta" &&
                   a[5] == "alpha");
        } break; case 40: {
            assert(locateDifference(z, -1, b, 6) == -1);
        } break; case 41: {
            assert(locateDifference(a, 6, z, -1) == -1);
        } break; case 42: {
            assert(locateDifference(z, 0, b, 0) == 0);
        } break; case 43: {
            assert(locateDifference(a, 3, b, 3) == 3);
        } break; case 44: {
            assert(locateDifference(a, 3, b, 2) == 2);
        } break; case 45: {
            assert(locateDifference(a, 2, b, 3) == 2);
        } break; case 46: {
            assert(locateDifference(a, 6, b, 6) == 3);
        } break; case 47: {
            assert(subsequence(z, -1, b, 6) == -1);
        } break; case 48: {
            assert(subsequence(a, 6, z, -1) == -1);
        } break; case 49: {
            assert(subsequence(z, 0, b, 6) == -1);
        } break; case 50: {
            assert(subsequence(a, 6, z, 0) == 0);
        } break; case 51: {
            assert(subsequence(a, 6, b, 1) == 0);
        } break; case 52: {
            assert(subsequence(a, 6, b+4, 2) == 4);
        } break; case 53: {
            assert(subsequence(a, 6, b+3, 1) == 5);
        } break; case 54: {
            assert(subsequence(a, 6, b+3, 2) == -1);
        } break; case 55: {
            assert(subsequence(a, 6, b+2, 2) == -1);
        } break; case 56: {
            assert(subsequence(a, 6, a, 6) == 0);
        } break; case 57: {
            assert(locateAny(a, 6, z, -1) == -1);
        } break; case 58: {
            assert(locateAny(z, -1, b, 6) == -1);
        } break; case 59: {
            assert(locateAny(z, 0, b, 1) == -1);
        } break; case 60: {
            assert(locateAny(a, 6, z, 0) == -1);
        } break; case 61: {
            assert(locateAny(a, 1, b, 1) == 0);
        } break; case 62: {
            assert(locateAny(a, 6, b+3, 3) == 1);
        } break; case 63: {
            assert(locateAny(a, 4, b+3, 3) == 1);
        } break; case 64: {
            assert(locateAny(a, 2, b+2, 2) == -1);
        } break; case 65: {
            assert(separate(z, -1, "beta") == -1 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 66: {
            assert(separate(z, 0, "beta") == 0 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 67: {
            assert(separate(a, 1, "aaa") == 0 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 68: {
            assert(separate(a, 1, "alpha") == 0 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 69: {
            assert(separate(a, 1, "zeta") == 1 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 70: {
            assert(separate(a, 2, "aaa") == 0 &&
                   separatecheck(a, 2, 0, "aaa") && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 71: {
            assert(separate(a, 2, "alpha") == 0 &&
                   separatecheck(a, 2, 0, "alpha") && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 72: {
            assert(separate(a, 2, "beta") == 1 &&
                   separatecheck(a, 2, 1, "beta") && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 73: {
            assert(separate(a, 2, "zeta") == 2 &&
                   separatecheck(a, 2, 2, "zeta") && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 74: {
            assert(separate(a, 6, "aaa") == 0 && separatecheck(a, 6, 0, "aaa"));
        } break; case 75: {
            assert(separate(a, 6, "alpha") == 0 &&
                   separatecheck(a, 6, 0, "alpha"));
        } break; case 76: {
            assert(separate(a, 6, "beta") == 1 &&
                   separatecheck(a, 6, 1, "beta"));
        } break; case 77: {
            assert(separate(a, 6, "delta") == 3 &&
                   separatecheck(a, 6, 3, "delta"));
        } break; case 78: {
            assert(separate(a, 6, "gamma") == 4 &&
                   separatecheck(a, 6, 4, "gamma"));
        } break; case 79: {
            assert(separate(a, 6, "zeta") == 6 &&
                   separatecheck(a, 6, 6, "zeta"));
        } break; case 80: {
            a[2] = "mu";
            c[5] = "mu";
            assert(separate(a, 6, "mu") == 5 && separatecheck(a, 6, 5, "mu"));
        } break; case 81: {
            assert(separate(a, 6, "chi") == 3 && separatecheck(a, 6, 3, "chi"));
        } break; case 82: {
            // To earn the bonus point for circleLeft, this and all other
            // circleLeft tests must pass, and that function must not
            // use any additional arrays.
            const int BIG = 500;
            string h[BIG];
            for (int k = 0; k < BIG; k++)
                h[k] = (k % 2 == 0 ? "alpha" : "beta");
            h[BIG-2] = "gamma";
            h[BIG-1] = "delta";
            circleLeft(h, BIG, 0);
            assert(h[BIG-3] == "gamma"  &&  h[BIG-2] == "delta");
        } break; case 83: {
            // To earn the bonus point for flip, this and all other
            // flip tests must pass, and that function must not
            // use any additional arrays.
            const int BIG = 500;
            string h[BIG];
            for (int k = 0; k < BIG; k++)
                h[k] = (k % 2 == 0 ? "alpha" : "beta");
            h[0] = "gamma";
            h[BIG-1] = "delta";
            flip(h, BIG);
            assert(h[0] == "delta"  &&  h[BIG-1] == "gamma");
        } break; case 84: {
            // To earn the bonus point for separate, this and all other
            // separate tests must pass, and that function must not
            // use any additional arrays.
            const int BIG = 500;
            string h[BIG];
            string i[3] = { "alpha", "beta", "gamma" };
            for (int k = 0; k < BIG; k++)
                h[k] = i[k % 3];
            separate(h, BIG, "beta");
            int m;
            for (m = 0; m < (BIG+2)/3; m++)
                assert(h[m] == "alpha");
            for ( ; m < 2*(BIG+1)/3; m++)
                assert(h[m] == "beta");
            for ( ; m < BIG; m++)
                assert(h[m] == "gamma");
        } break;
    }

    new (&a[-1]) string;
    new (&a[N]) string;
}

int main()
{
    for (int n = 1; n != 85; n++) {
        testone(n);
        cout << "Passed test " << n << endl;
    }
}

// Checks invalidity of input array size (i.e. negative)
bool isInvalidSize(int n) {
    if (n < 0)
        return true;
    return false;
}

// Checks invalidity of input position (i.e. greater than the inputted array size or negative)
bool isInvalidPosition(int n, int position) {
    if (position >= n || position < 0)
        return true;
    return false;
}

// For each of the n elements of the array, append that element to that same element. Return n.
int reduplicate(string a[], int n) {

    // Check if n is negative
    if (isInvalidSize(n))
        return -1;

    // Append specified string to itself with each iteration
    for (int i = 0; i < n; i++) {
        a[i] += a[i];
    }

    return n;
}

// Return the position of a string in the array that is equal to target; if there is more than one such string, return the smallest position number of such a matching string.
// Return −1 if there is no such string. Case matters.
int locate(const string a[], int n, string target) {

    // Check if n is negative
    if (isInvalidSize(n))
        return -1;

    // Check if the string is equal to the target string with each iteration
    for (int i = 0; i < n; i++) {
        if (a[i] == target)
            return i;
    }

    // Return -1 if no such string is found.
    return -1;
}

// Return the position of a string in the array such that that string is >= every string in the array.
// If there is more than one such string, return the smallest position number of such a string.
// Return −1 if the function should examine no elements of the array.
int locationOfMax(const string a[], int n) {

    // Check if n is negative
    if (isInvalidSize(n))
        return -1;

    // Check if n is 0
    if (n == 0)
        return -1;

    int maxLocation = 0;

    // Check if the string is greater than all previous strings
    for (int i = 1; i < n; i++)
    {
        if (a[i] > a[maxLocation])
        {
            maxLocation = i;
        }
    }

    // Return position where the max string is found
    return maxLocation;
}

// Eliminate the item at position pos by copying all elements after it one place to the left.
// Put the item that was thus eliminated into the last position of the array that the function knows about.
// Return the original position of the item that was moved to the end.
int circleLeft(string a[], int n, int pos) {

    // Check if size or position is invalid
    if (isInvalidSize(n) || isInvalidPosition(n, pos))
        return -1;

    // Find the string that needs to be removed
    string removedString = a[pos];

    // Copy elements after the removed string, one place to the left
    for (int i = pos + 1; i < n; i++) {
        a[i - 1] = a[i];
    }

    // Move the removed string to the end
    a[n - 1] = removedString;
    return pos;
}

// Return the number of sequences of one or more consecutive identical items in a.
int enumerateRuns(const string a[], int n) {

    // Check if n is negative
    if (isInvalidSize(n))
        return -1;

    int runs = 0;
    if (n == 0)
        return runs;
    runs++;

    for (int i = 1; i < n; i++) {
        // Add to the counter of sequences of one or more consecutive identical items with each iteration
        if (a[i] != a[i - 1])
            runs++;
    }

    // Return the number of sequences
    return runs;
}

// Reverse the order of the elements of the array and return n.
int flip(string a[], int n) {

    // Check if n is negative
    if (isInvalidSize(n))
        return -1;

    string temp;

    // Replace an item before n/2 with an item occuring after n/2
    for (int i = 0, k = n - 1; i < (n/2); i++, k--) {
        temp = a[i];
        a[i] = a[k];
        a[k] = temp;
    }

    return n;
}

// Return the position of the first corresponding elements of a1 and a2 that are not equal.
// n1 is the number of interesting elements in a1, and n2 is the number of interesting elements in a2.
// If the arrays are equal up to the point where one or both runs out, return whichever value of n1 and n2 is less than or equal to the other.
int locateDifference(const string a1[], int n1, const string a2[], int n2) {

    // Check for negativity in n1 and n2
    if (isInvalidSize(n1) || isInvalidSize(n2))
        return -1;

    // Check for correspondence in array elements
    for (int i = 0; i < n1; i++)
    {
        if (i == n2)
            return n2;

        if (a1[i] != a2[i])
            return i;
    }

    return n1;
}

// If all n2 elements of a2 appear in a1, consecutively and in the same order, then return the position in a1 where that subsequence begins.
// If the subsequence appears more than once in a1, return the smallest such beginning position in the array.
// Return −1 if a1 does not contain a2 as a contiguous subsequence.
int subsequence(const string a1[], int n1, const string a2[], int n2)
{
    // Check for invalidity in input
    if (isInvalidSize(n1) || isInvalidSize(n2) || n2 > n1)
        return -1;
    if (n2 == 0)
        return 0;

    // Loop through a1
    for (int i = 0; i < (n1 - n2 + 1); i++) {
        bool fail = false;
        // Loop through each element in a2 for each possible beginning position
        for(int j = 0; j < n2; j++) {
            if(a1[i + j] != a2[j])
                fail = true;
        }
        if(!fail)
            return i;
    }

    return -1;
}

// Return the smallest position in a1 of an element that is equal to any of the n2 elements in a2. Return −1 if no element of a1 is equal to any element of a2.
int locateAny(const string a1[], int n1, const string a2[], int n2) {

    // Check for negativity
    if (isInvalidSize(n1) || isInvalidSize(n2))
        return -1;

    // Check for equal string
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (a1[i] == a2[j])
                // If strings are equal, return position in a1
                return i;
        }
    }

    // Return -1 to indicate no equal strings
    return -1;
}

// Rearrange the elements of the array so that all the elements whose value is < separator come before all the other elements, and all the elements whose value is > separator come after all the other elements.
// Return the position of the first element that, after the rearrangement, is not < separator, or n if there are no such elements.
int separate(string a[], int n, string separator) {

    // Check for invalidity in input
    if (isInvalidSize(n))
        return -1;
    if (n == 0)
        return n;

    // Bubble sort to order the array up through n
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i + 1]) {
                string temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                sorted = false;
            }
        }
    }

    // Searches for when the values in the array equal or pass that of separator
    for (int i = 0; i < n; i++) {
        if (a[i] >= separator)
            return i;
    }

    // Return n if the separator is greater than all values in the array
    return n;
}
