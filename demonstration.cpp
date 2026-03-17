#include "str.h"
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::cout << "===== Custom String Library Demonstration =====" << std::endl;

    // 1. Constructors and C-String Interop
    str s1("Hello");
    str s2 = "World";
    str empty = nullptr;
    std::cout << "\n[1] Constructors & c_str()" << std::endl;
    std::cout << "s1: " << s1.c_str() << " (Length: " << s1.length() << ")" << std::endl;
    std::cout << "s2: " << s2.c_str() << " (Length: " << s2.length() << ")" << std::endl;
    std::cout << "Null-handled string: '" << empty << "'" << std::endl;

    // 2. Optimized Capacity (O(1))
    std::cout << "\n[2] Optimized Capacity" << std::endl;
    std::cout << "Is empty string empty? " << (empty.empty() ? "Yes" : "No") << std::endl;
    std::cout << "s1 size: " << s1.size() << " (Instant O(1) lookup)" << std::endl;

    // 3. Iterators and STL Integration
    std::cout << "\n[3] Iterators & STL Algorithms" << std::endl;
    str s3 = "dcba";
    std::cout << "Original s3: " << s3 << std::endl;
    
    std::cout << "Range-based for loop: ";
    for (char c : s3) std::cout << c << " ";
    std::cout << std::endl;

    std::sort(s3.begin(), s3.end());
    std::cout << "After std::sort: " << s3 << std::endl;

    std::reverse(s3.begin(), s3.end());
    std::cout << "After std::reverse: " << s3 << std::endl;

    // 4. Advanced Modifiers (Robust against Aliasing)
    std::cout << "\n[4] Advanced Modifiers" << std::endl;
    str s4 = "The quick fox";
    std::cout << "Original: " << s4 << std::endl;
    
    s4.insert(10, "brown ");
    std::cout << "After insert: " << s4 << std::endl;

    s4.replace(4, 5, "lazy");
    std::cout << "After replace: " << s4 << std::endl;

    s4.erase(14, 6); // remove "brown "
    std::cout << "After erase: " << s4 << std::endl;

    str s5 = "Swap";
    str s6 = "Test";
    s5.swap(s6);
    std::cout << "After swap: s5=" << s5 << ", s6=" << s6 << std::endl;

    // 5. Comparison Logic
    std::cout << "\n[5] Comparison Operators" << std::endl;
    str a = "apple";
    str b = "banana";
    std::cout << "apple < banana: " << (a < b ? "True" : "False") << std::endl;
    std::cout << "apple >= apple: " << (a >= a ? "True" : "False") << std::endl;

    // 6. Searching
    std::cout << "\n[6] Searching" << std::endl;
    str search_text = "Mississippi";
    std::cout << "Text: " << search_text << std::endl;
    std::cout << "find('i'): " << search_text.find('i') << std::endl;
    std::cout << "rfind('i'): " << search_text.rfind('i') << std::endl;
    std::cout << "find(\"ss\"): " << search_text.find("ss") << std::endl;
    std::cout << "find(\"\") standard behavior: " << search_text.find("") << std::endl;

    // 7. Stream I/O
    std::cout << "\n[7] Stream I/O" << std::endl;
    std::cout << "Outputting with operator<<: " << s1 << " " << s2 << "!" << std::endl;
    
    /* 
    str input;
    std::cout << "Enter a word: ";
    std::cin >> input;
    std::cout << "You entered: " << input << std::endl;
    */

    std::cout << "\nAll features demonstrated successfully!" << std::endl;

    return 0;
}
