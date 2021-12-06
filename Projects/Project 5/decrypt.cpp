// Secret Plans (F21-CS31-1 Project 5)
// Naman Modani

#include <cctype>
#include <cstring>
#include <iostream>
using namespace std;

const int MAX_LENGTH = 90;
void duplicateLine(const char *&source, char *destination);
int simplify(const char source[], char destination[]);
bool boundaryTest(const char line[], int lineLength, int start, int subLength);
bool map(const char *sub, const char crib[], int len, char map1[], char map2[]);
bool decrypt(const char ciphertext[], const char crib[]);

int main() {}

// Copying the first line from the source (head) to the destination
void duplicateLine(const char *&source, char *destination) {
    char x = *source;
    while (x && x != '\n') {
        *destination = x;
        source++;
        destination++;
        x = *source;
    }
    // At this point, x is either '\n' or '\0'
    if (x) {
        source++;
    }
    *destination = '\0';
    // Terminating the string
}

// Reducing the string to only alphabetic chars and non-consecutive spaces
// Returning the length of the simplified string, or -1 if the simplified string is longer than the MAX_LENGTH, i.e. 90
int simplify(const char source[], char destination[]) {
    int k = 0; // Length of the simplified string
    char x;
    for (int i = 0; i < strlen(source); i++) {
        x = source[i];
        // Check if x is an alphabet
        if (isalpha(x)) {
            if (k >= MAX_LENGTH)
                return -1;
            destination[k] = tolower(x);
            k++;
        } else if (k > 0 && destination[k - 1] != ' ') {
            destination[k] = ' ';
            k++;
        }
    }
    if (k > 0 && destination[k - 1] == ' ') k--;
    destination[k] = '\0';
    return k;
}

// Returning if a substring contains only whole words
bool boundaryTest(const char line[], int lineLength, int start, int subLength) {
    return !((start > 0 && line[start - 1] != ' ') ||
             (start + subLength < lineLength && line[start + subLength] != ' '));
}

// Attempting to construct a plaintext to ciphertext mapping (between sub and crib)
// Returning true upon success, false upon contradiction
bool map(const char *sub, const char crib[], int len, char map1[], char map2[]) {
    for (int i = 'a'; i <= 'z'; i++) {
        map1[i] = map2[i] = '\0';
    }

    // Compare crib with sub
    for (int i = 0; i < len; i++) {
        unsigned char x = sub[i], y = crib[i];
        if (isalpha(x) && isalpha(y)) {
            if (!map1[y] && !map2[x]) {
                map1[y] = x;
                map2[x] = y;
            } else if (map1[y] != x || map2[x] != y) { // Returning false upon encountering a conflicting, pre-existing mapping
                return false;
            }
        } else if (!(x == ' ' && y == ' ')) { // Returning false upon a word boundary mismatch, causing failure
            return false;
        }
    }

    return true;
}

bool decrypt(const char ciphertext[], const char crib[]) {
    char simplifiedCrib[MAX_LENGTH + 1];
    int cribLength = simplify(crib, simplifiedCrib);
    if (cribLength <= 0)
        return false;

    int cipherLength = strlen(ciphertext);

    // ['z' + 1] allows 'z' to be the last index, since indices begin with 0

    // Plaintext -> Cipher
    char map1['z' + 1];
    // Cipher -> Plaintext
    char map2['z' + 1];
    char line[MAX_LENGTH + 1];
    const char *head = ciphertext;
    while (head - ciphertext < cipherLength) {
        duplicateLine(head, line);
        int lineLength = simplify(line, line);

        for (int i = 0; i + cribLength <= lineLength; i++) {
            if (boundaryTest(line, lineLength, i, cribLength) &&
                map(line + i, simplifiedCrib, cribLength, map1, map2)) {

                for (int k = 0; k < cipherLength; k++) {
                    unsigned char x = ciphertext[k];
                    if (isalpha(x)) {
                        x = tolower(x);
                        char y = map2[x];
                        if (y) {
                            cout << (char)toupper(y);
                        } else {
                            cout << x;
                        }
                    } else {
                        cout << x;
                    }
                }
                return true;
            }
        }
    }

    return false;
}
