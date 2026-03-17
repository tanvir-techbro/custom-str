#include "str.h"
#include <cctype>
#include <istream>
#include <stdexcept>
#include <vector>
using namespace std;

// -------------------- Class Functions --------------------

str::str() {
        data.push_back('\0');
}

str::str(const char *input) {
        // Checking if the input was empty or not.
        if (input == nullptr) {
                data.push_back('\0');
                return;
        }

        int i = 0;
        while (input[i] != '\0') {
                data.push_back(input[i]);
                i++;
        }
        data.push_back('\0'); // adding a null terminator at the end.
}

char &str::operator[](int index) {
        return data[index];
}
char str::operator[](int index) const {
        return data[index];
}

// checks if the str is empty or not.
bool str::empty() const {
        if (data.size() <= 1) {
                return true;
        } else {
                return false;
        }
}

// returns the length of the str
int str::length() const {
        return data.size() - 1;
}

// Identical to .length() method
int str::size() const {
        return data.size() - 1;
}

// Returns the character at given index
char str::at(int index) const {
        // checking bound.
        if (index < 0 || index >= data.size() - 1) {
                throw std::out_of_range("Index " + std::to_string(index) + " is out of bounds for size " + std::to_string(data.size()));
        } else {
                return data[index];
        }
}

// Returns the first character.
char str::front() const {
        if (data.size() == 1) {
                throw std::out_of_range("front() called on an empty string");
        }
        return data[0];
}

// Returns the last character
char str::back() const {
        if (data.size() == 1) {
                throw std::out_of_range("back() called on an empty string");
        }
        return data[data.size() - 2];
}

// Adds user given character at the end of the str.
void str::push_back(char ch) {
        // removing the null terminator.
        if (!data.empty() && data.back() == '\0') {
                data.pop_back();
        }
        data.push_back(ch);
        data.push_back('\0');
}

// Adds a str to the end
void str::append(str st) {
        // removing the null terminator.
        if (!data.empty() && data.back() == '\0') {
                data.pop_back();
        }

        int i = 0;
        while (st[i] != '\0') {
                data.push_back(st[i]);
                i++;
        }
        data.push_back('\0');
}

// adds a str to the on the left side of the operator.
str &str::operator+=(const str &rhs) {
        this->append(rhs);
        return *this;
}

// Finds a char
int str::find(const char ch) const {
        int i = 0;
        bool found = false;
        while (data[i] != '\0') {
                if (data[i] == ch) {
                        found = true;
                        return i;
                        break;
                }
                i++;
        }

        return npos;
}

// Finds a substring.
int str::find(const char *ch) const {
        if (ch == nullptr) {
                return npos;
        }

        // Finding the length of the given string
        int ch_length = 0;
        while (ch[ch_length] != '\0') {
                ch_length++;
        }

        if (ch_length == 0) {
                return 0;
        } else if (ch_length > data.size() - 1) {
                return npos;
        }

        for (int i = 0; i < (data.size() - ch_length) + 1; i++) {
                bool found = true;
                for (int j = 0; j < ch_length; j++) {
                        if (ch[j] != data[i + j]) {
                                found = false;
                                break;
                        }
                }
                if (found) {
                        return i;
                }
        }
        return npos; // returns npos if !found
}

// finds the position of last ch
int str::rfind(const char ch) const {
        int i = data.size() - 2;
        bool found = false;
        while (i >= 0) {
                if (data[i] == ch) {
                        found = true;
                        return i;
                        break;
                }
                i--;
        }

        return npos;
}

// Finds the position of the last subset ch.
int str::rfind(const char *ch) const {
        if (ch == nullptr) {
                return npos;
        }

        // Finding the length of the given string
        int ch_length = 0;
        while (ch[ch_length] != '\0') {
                ch_length++;
        }

        if (ch_length == 0) {
                return 0;
        } else if (ch_length > data.size() - 1) {
                return npos;
        }

        for (int i = data.size() - ch_length - 1; i >= 0; i--) {
                bool found = true;
                for (int j = 0; j < ch_length; j++) {
                        if (data[i + j] != ch[j]) {
                                found = false;
                                break;
                        }
                }
                if (found) {
                        return i;
                }
        }
        return npos;
}

// Finds the first targeted char in the str
int str::find_first_of(const char ch) const {
        int i = 0;
        bool found = false;
        while (data[i] != '\0') {
                if (data[i] == ch) {
                        found = true;
                        return i;
                        break;
                }
                i++;
        }

        return npos;
}

// Finds the last targeted char in the str.
int str::find_last_of(const char ch) const {
        int i = data.size() - 2;
        bool found = false;
        while (i >= 0) {
                if (data[i] == ch) {
                        found = true;
                        return i;
                        break;
                }
                i--;
        }

        return npos;
}

str str::substr(int index) const {
        if (index > data.size() - 1) {
                throw std::out_of_range("Index " + std::to_string(index) + " is out of bounds for size " + std::to_string(data.size()));
        }
        str buffer_str;
        while (data[index] != '\0') {
                buffer_str.push_back(data[index]);
                index++;
        }
        return buffer_str;
}

str str::substr(int index, const int len) const {
        if (index > data.size() - 1) {
                throw std::out_of_range("Index " + std::to_string(index) + " is out of bounds for size " + std::to_string(data.size()));
        }

        str buffer_str;
        if (index + len > data.size() - 1) {
                while (data[index] != '\0') {
                        buffer_str.push_back(data[index]);
                        index++;
                }
        } else {
                int count = 0;
                while (count != len) {
                        buffer_str.push_back(data[index]);
                        count++;
                        index++;
                }
        }
        return buffer_str;
}

void str::clear() {
        data.clear();
        data.push_back('\0');
}

// Erases a whose str
void str::erase() {
        data.clear();
        data.push_back('\0');
}

// Erases certain part of str
void str::erase(int index, const int len) {
        if (index + len < data.size()) {
                data.erase(data.begin() + index, data.begin() + index + len);
        } else {
                throw std::out_of_range("Index " + std::to_string(index) + " is out of bounds for size " + std::to_string(data.size() - 1));
        }
}

// Swaps 2 str
void str::swap(str &rhs) {
        this->data.swap(rhs.data);
}

void str::insert(int index, const str &st) {
        if (index < 0 || index > data.size() - 1) {
                throw std::out_of_range("Index " + std::to_string(index) + " is out of bounds for size " + std::to_string(data.size() - 1));
        }

        if (this == &st) {
                str temp = st;
                data.insert(this->data.begin() + index, temp.begin(), temp.end());
        } else {
                data.insert(this->data.begin() + index, st.begin(), st.end());
        }
}

void str::replace(int index, const int len, const str &st) {
        str temp = st;
        this->erase(index, len);
        this->insert(index, temp);
}

int str::compare(const str &other) const {
        int min = (this->length() < other.length()) ? this->length() : other.length();

        for (int i = 0; i <= min; i++) {
                if (this->data[i] > other.data[i]) {
                        return 1;
                } else if (this->data[i] < other.data[i]) {
                        return -1;
                }
        }
        // If all characte matches the shorter string is smaller.
        if (this->length() > other.length()) {
                return 1;
        } else if (this->length() < other.length()) {
                return -1;
        }

        return 0;
}

const char *str::c_str() const {
        return data.data();
}

// -------------------- Global functions --------------------

// creates a new string by adding 2 string which is on the right side of '='.
str operator+(str lhs, const str &rhs) {
        lhs += rhs;
        return lhs;
}

// lets up compair two str
bool operator==(const str &lhs, const str &rhs) {
        if (lhs.length() != rhs.length()) {
                return false;
        }

        for (int i = 0; i < lhs.length(); i++) {
                if (lhs[i] != rhs[i]) {
                        return false;
                }
        }
        return true;
}

// checks if two str is same or not.
bool operator!=(const str &lhs, const str &rhs) {
        return !(lhs == rhs);
}

bool operator>(const str &lhs, const str &rhs) {
        return lhs.compare(rhs) > 0;
}

bool operator<(const str &lhs, const str &rhs) {
        return lhs.compare(rhs) < 0;
}

bool operator>=(const str &lhs, const str &rhs) {
        return lhs.compare(rhs) >= 0;
}

bool operator<=(const str &lhs, const str &rhs) {
        return lhs.compare(rhs) <= 0;
}

// Lets us use `std::cout` for output.
ostream &operator<<(ostream &os, const str &s) {
        for (int i = 0; i < s.length(); i++) {
                os << s.at(i);
        }
        return os;
}

istream &operator>>(istream &is, str &s) {
        s.clear();
        char c;

        // Skipping leading whitespaces
        while (is.get(c) && isspace(c)) {
        }

        if (is.good()) {
                s.push_back(c);
                while (is.get(c) && !isspace(c)) {
                        s.push_back(c);
                }
                if (isspace(c)) {
                        is.putback(c);
                }
        }
        return is;
}

istream &getline(istream &is, str &s) {
        s.clear();
        char c;

        // Read every character one by one
        while (is.get(c)) {
                if (c == '\n') {
                        break; // Stop at newline, but don't put it back
                }
                s.push_back(c);
        }

        return is;
}
