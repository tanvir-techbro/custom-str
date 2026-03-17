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
        void erase();
        void erase(int index, const int len);
        void swap(str &rhs);
        void insert(int index, const str &st);
        void replace(int index, const int len, const str &st);
        int compare(const str &other) const;

        vector<char>::iterator begin() {
                return data.begin();
        }
        vector<char>::const_iterator begin() const {
                return data.begin();
        }
        vector<char>::iterator end() {
                return data.end() - 1;
        }
        vector<char>::const_iterator end() const {
                return data.end() - 1;
        }

        // Returns char* of str
        const char *c_str() const;

        // Friend function for opertor>> and getline()
        friend istream &operator>>(istream &is, str &s);
        friend istream &getline(istream &is, str &s);
};

// global functions to perform different operations.
str operator+(str lhs, const str &rhs);
bool operator==(const str &lhs, const str &rhs);
bool operator!=(const str &lhs, const str &rhs);
bool operator>(const str &lhs, const str &rhs);
bool operator<(const str &lhs, const str &rhs);
bool operator>=(const str &lhs, const str &rhs);
bool operator<=(const str &lhs, const str &rhs);

// This tells the compiler: "When you see << and a 'str' object, do this."
ostream &operator<<(ostream &os, const str &s);
// Makes str compateable with cin >>
istream &operator>>(istream &is, str &s);
// Makes str compateable with getline
istream &getline(istream &is, str &s);

// -----------------------------------------------------------------

#endif // !STR_H
