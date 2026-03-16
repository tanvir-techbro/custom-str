# Custom String Class (`str`)

This project implements a custom `str` class in C++ that replicates some of the core functionality of `std::string`. It uses `std::vector<char>` as its underlying data structure.

## Features

- **Constructors**: Default constructor and constructor from `const char*`.
- **Capacity**: Methods for `size()`, `length()`, and `empty()`.
- **Element Access**: `operator[]`, `at()`, `front()`, and `back()`.
- **Modifiers**: `push_back()`, `append()`, `operator+=`, `operator+`, and `clear()`.
- **Searching**: `find()`, `rfind()`, `find_first_of()`, and `find_last_of()` for both characters and substrings.
- **Substring**: `substr(index)` and `substr(index, length)`.
- **Comparison**: `operator==` and `operator!=`.
- **I/O Support**: `operator<<`, `operator>>`, and a custom `getline()`.

## File Structure

- `str.h`: Header file containing the class definition.
- `str.cpp`: Implementation of the class methods.
- `demonstration.cpp`: A demonstration file showcasing the usage of the `str` class.

## Getting Started

### Prerequisites

- A C++ compiler (e.g., `g++`).

### Compilation

To compile and run the demonstration:

```bash
g++ str.cpp demonstration.cpp -o demonstration
./demonstration
```

## Example Usage

```cpp
#include "str.h"
#include <iostream>

int main() {
    str s = "Hello";
    s += " World";
    std::cout << s << std::endl; // Output: Hello World
    return 0;
}
```

## Implementation Details

- The class maintains a null terminator `\0` at the end of the `std::vector<char> data` to ensure compatibility with C-style string patterns when needed internally.
- Error handling is implemented for `at()` and `substr()` using `std::out_of_range`.
- `find` and `rfind` return `str::npos` (-1) when the target is not found.
