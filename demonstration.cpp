#include "str.h"
#include <iostream>

int main() {
        // 1. Constructors
        str s1;           // Default constructor
        str s2("Hello");  // const char* constructor
        str s3 = "World"; // Implicit conversion

        std::cout << "--- Constructors ---" << std::endl;
        std::cout << "s1 (empty): '" << s1 << "'" << std::endl;
        std::cout << "s2: " << s2 << std::endl;
        std::cout << "s3: " << s3 << std::endl;

        // 2. Capacity
        std::cout << "\n--- Capacity ---" << std::endl;
        std::cout << "s2 size: " << s2.size() << std::endl;
        std::cout << "s2 length: " << s2.length() << std::endl;
        std::cout << "s1 is empty: " << (s1.empty() ? "Yes" : "No") << std::endl;

        // 3. Element Access
        std::cout << "\n--- Element Access ---" << std::endl;
        std::cout << "s2[0]: " << s2[0] << std::endl;
        std::cout << "s2.at(1): " << s2.at(1) << std::endl;
        std::cout << "s2.front(): " << s2.front() << std::endl;
        std::cout << "s2.back(): " << s2.back() << std::endl;

        // 4. Modifiers
        std::cout << "\n--- Modifiers ---" << std::endl;
        s1.push_back('A');
        std::cout << "After push_back('A'): " << s1 << std::endl;

        s2.append(" ");
        s2.append(s3);
        std::cout << "After append: " << s2 << std::endl;

        str s4 = "Greetings";
        s4 += " ";
        s4 += s3;
        std::cout << "After operator+=: " << s4 << std::endl;

        str s5 = s2 + "!!!";
        std::cout << "After operator+: " << s5 << std::endl;

        // 5. Searching
        std::cout << "\n--- Searching ---" << std::endl;
        str search_str = "Hello World";
        std::cout << "String: " << search_str << std::endl;
        std::cout << "find('o'): " << search_str.find('o') << std::endl;
        std::cout << "find(\"World\"): " << search_str.find("World") << std::endl;
        std::cout << "rfind('o'): " << search_str.rfind('o') << std::endl;
        std::cout << "find_first_of('l'): " << search_str.find_first_of('l') << std::endl;
        std::cout << "find_last_of('l'): " << search_str.find_last_of('l') << std::endl;

        // 6. Substring
        std::cout << "\n--- Substring ---" << std::endl;
        std::cout << "search_str.substr(6): " << search_str.substr(6) << std::endl;
        std::cout << "search_str.substr(0, 5): " << search_str.substr(0, 5) << std::endl;

        // 7. Comparison
        std::cout << "\n--- Comparison ---" << std::endl;
        str cmp1 = "Test";
        str cmp2 = "Test";
        str cmp3 = "Toast";
        std::cout << "cmp1 == cmp2: " << (cmp1 == cmp2 ? "True" : "False") << std::endl;
        std::cout << "cmp1 != cmp3: " << (cmp1 != cmp3 ? "True" : "False") << std::endl;

        // 8. Clear
        std::cout << "\n--- Clear ---" << std::endl;
        s5.clear();
        std::cout << "s5 after clear, empty(): " << (s5.empty() ? "Yes" : "No") << std::endl;

        // 9. I/O (Note: This is interactive, but demonstrated here for completeness)
        /*
        str input_str;
        std::cout << "\nEnter a word: ";
        std::cin >> input_str;
        std::cout << "You entered: " << input_str << std::endl;

        std::cin.ignore(); // Clear newline
        str line_str;
        std::cout << "Enter a full line: ";
        getline(std::cin, line_str);
        std::cout << "You entered line: " << line_str << std::endl;
        */
        std::cout << "\n--- I/O ---" << std::endl;
        std::cout << "I/O operations (operator>> and getline) are implemented and ready for use!" << std::endl;

        return 0;
}
