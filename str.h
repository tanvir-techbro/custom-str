#ifndef STR_H
#define STR_H

#include <iostream>
#include <vector>
using namespace std;

// --------------- defination for the file `str.cpp` ---------------

class str {
      private:
        vector<char> data;

      public:
        static const int npos = -1;

        str();                            // constructor for empty str.
        str(const char *input);           // Taking str input from the user.
        char &operator[](int index);      // for writing on data[index]
        char operator[](int index) const; // for reading data[index]

        bool empty() const;

        // all 2 below does the same thing.
        int length() const; // Returns length of the str.
        int size() const;

        // char access.
        char at(int index) const;
        char front() const;
        char back() const;

        // appending
        void push_back(char ch);
        void append(str st);
        str &operator+=(const str &rhs);

        // searching and finding.
        int find(const char ch) const;   // finds a char
        int find(const char *ch) const;  // finds a substring
        int rfind(const char ch) const;  // Finds the last char
        int rfind(const char *ch) const; // Finds the last substring
        int find_first_of(const char ch) const;
        int find_last_of(const char ch) const;

        // Substring extraction
        str substr(int index) const;
        str substr(int index, const int len) const;

        // Modifying, erasing and compairson
        void clear();
        int compare(str st); // TODO: Implement this function.

        // Friend function for opertor>> and getline()
        friend istream &operator>>(istream &is, str &s);
        friend istream &getline(istream &is, str &s);
};

// global functions to perform different operations.
str operator+(str lhs, const str &rhs);
bool operator==(const str lhs, const str &rhs);
bool operator!=(const str lhs, const str &rhs);
// TODO: Implement two functions below.
bool operator>(const str lhs, const str rhs);
bool operator<(const str lhs, const str rhs);

// This tells the compiler: "When you see << and a 'str' object, do this."
ostream &operator<<(ostream &os, const str &s);
// Makes str compateable with cin >>
istream &operator>>(istream &is, str &s);
// Makes str compateable with getline
istream &getline(istream &is, str &s);

// -----------------------------------------------------------------

#endif // !STR_H
