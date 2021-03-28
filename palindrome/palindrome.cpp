// Karen Axon
// File: palindrome
// Date: October 5, 2020
// Purpose: This program informs the user if the input is a palindrome.
// Input: A file path specified by the user.
// Process: A template is used in order  to allow any type of user input and
// recursion is used to perform the palindrome test.
// Output: Standard output to inform the user if the string is a palindrome.

#include <iostream>
#include <fstream>
#include <string>
#include <regex>
using namespace std;

template<typename T> // Indicates this is a template definition
bool isPalRec(T, int, int);
// This function is a helper method to IsPalindrome and uses recursion to
// perform the palindrome test.
// IN: any type of user input / typename T, int
// MODIFY: none
// OUT: returns true if it is a palindrome, false if it isn't.

template<typename T> // Indicates this is a template definition
bool isPalindrome(T);
// This function uses recursion to perform the palindrome test.
// IN: any type of user input / typename T
// MODIFY: none
// OUT: returns true if it is a palindrome, false if it isn't.

template<typename T> // Indicates this is a template definition
string transformString(T &);
// This function traverses the given string character by character, checks if
// the characters are uppercase and coverts them to lowercase.
// IN: any type of user input / typename T
// MODIFY: the string
// OUT: returns the string

int main() {
    string filename;
    string line, noSpacesLine, transformedLine; // different states of the input

    cout << "\nWelcome to the palindrome testing program!" << endl;

    // Get input from user for the file name
    cout << "\nEnter the name of the file: ";
    cin >> filename;

    // Open and read the data from the file
    ifstream inputFile;
    inputFile.open(filename);
    if(inputFile.is_open()) {
        while (getline(inputFile, line)) {

            // Remove spaces from text
            regex r(" ");
            noSpacesLine = regex_replace(line, r, "");
            transformedLine = transformString(noSpacesLine);

            // Is it a palindrome?
            if (isPalindrome(transformedLine))
                cout << line << " is a palindrome!" << endl;
            else
                cout << line << " is NOT a palindrome" << endl;
        }
    } else
        cout << "Unable to open file." << endl;

    inputFile.close();
    return 0;
}

template<typename T> // Indicates this is a template definition
bool isPalRec(T word, int s, int e) {

    // if only one character
    if (s == e)
        return true;

    // if the first and last characters don't match
    if (word[s] != word[e])
        return false;

    // if more than 2 characters, check if substring is a palindrome
    if (s < e + 1)
        return isPalRec(word, s + 1, e - 1);

    return true;
}

template<typename T> // Indicates this is a template definition
bool isPalindrome(T text) {
    int n = text.length();

    // if string is empty is a palindrome
    if (n == 0)
        return true;

    return isPalRec(text, 0, n - 1);
}

template<typename T> // Indicates this is a template definition
string transformString(T &text) {
    int length = text.length();

    // traverses the string character by character and convert to lowercase
    for (int i = 0; i < length; i++) {
        int c = text[i];
        if (isupper(c))
            text[i] = tolower(c);
    }
    return text;
}