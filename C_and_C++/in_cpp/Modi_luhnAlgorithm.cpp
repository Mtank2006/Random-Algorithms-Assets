#include <iostream>

int main() {
    std::string digits;
    std::cin >> digits;
    if (digits.length() != 16) {
        std::cout << "This is not 16 digit number\n";
        return 0;
    }
    int validChecker = 0;
    for (int i = 15; i >= 0; i--) {
        int digit = digits[i] - '0';
        if (i%2==0) {
            digit *=2;
            if (digit > 9) digit -=9;
        }
        validChecker += digit;
    }    
    if (validChecker%10 == 0) {
        std::cout << "Valid" << "\n";
    }
    else {
        std::cout << "Not Valid" << "\n";
    }
    return 0;
}