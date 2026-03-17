# Custom String Library (str)

A robust, performant, and "bulletproof" C++ string library built for learning and high reliability.

## Features

- **Standard Compliant**: Implements all essential string operations like `substr`, `find`, `insert`, `replace`, and `erase`.
- **Performance Optimized**: 
  - `length()`, `size()`, and `clear()` are optimized to **O(1)**.
  - Efficient vector-based storage.
- **Robust Logic**:
  - **Aliasing Protection**: Safely handles self-referencing operations (e.g., `s.insert(0, s)` or `s.replace(index, len, s)`).
  - **Null Safety**: Gracefully handles `nullptr` in constructors and search functions.
  - **Boundary Checking**: Rigorous bounds checking with `std::out_of_range` exceptions.
- **STL Integration**:
  - Full **iterator support** (`begin()`, `end()`) allowing use with range-based for loops and algorithms like `std::sort` and `std::reverse`.
- **Rich Comparisons**: Full suite of comparison operators (`==`, `!=`, `<`, `>`, `<=`, `>=`) using lexicographical logic.
- **Stream I/O**: Compatible with `std::cin`, `std::cout`, and `std::getline`.

## Usage Examples

### Basic Operations
```cpp
str s = "Hello";
s += " World";
std::cout << s << std::endl; // Output: Hello World
```

### STL Algorithms
```cpp
str s = "dcba";
std::sort(s.begin(), s.end());
std::cout << s << std::endl; // Output: abcd
```

### Safe Self-Modification
```cpp
str s = "ABC";
s.insert(0, s); // Correctly handles self-reference
std::cout << s << std::endl; // Output: ABCABC
```

### Optimized Performance
```cpp
str large(1000000, 'x'); // Assume a fill constructor exists or use push_back
int len = large.length(); // Instant O(1) lookup
```

## Compilation

To compile with the provided demonstration:

```bash
g++ str.cpp demonstration.cpp -o demonstration
./demonstration
```

## Implementation Details

The library is backed by a `std::vector<char>`, ensuring dynamic memory management while maintaining a hidden null terminator (`\0`) to stay compatible with C-style string expectations through the `c_str()` method.
