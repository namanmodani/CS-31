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


int main() {}


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
