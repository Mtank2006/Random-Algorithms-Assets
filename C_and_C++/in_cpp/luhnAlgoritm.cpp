#include <iostream>

int main() {
    long long number;
    std::cin >> number;
    std::string digits = std::to_string(number);
    if (digits.size() != 16) {
        std::cout << "This is not 16 digit number\n";
        return 0;
    }
    std::string group1 = ""; // split and twice 
    std::string group2 = "";
    for (int i = 15; i >= 0; i-=2) {
        group1 += std::to_string(((digits[i-1]) - '0')*2);
        group2 += digits[i];    }
    int validChecker = 0;
    for (char i : group1) {
        validChecker += (i - '0');
    }
    for (char i : group2) {
        validChecker += (i - '0');
    }
    if (validChecker%10 == 0) {
        std::cout << "Valid" << "\n";
    }
    else {
        std::cout << "Not Valid" << "\n";
    }
}