#include <iostream>
#include <ctime>
int main() {
    int number;
    int guess;
    int tries = 0;
    unsigned range;
    std::cin >> range;
    srand(time(0));
    number = (rand() % range) +1;
    std::cout << "Welcome To Number Guessing Game\n";
    do{
        tries++;
        std::cout << "Enter the number\n";
        std::cin >> guess;
        if(guess > number) std::cout << "Too high\n";
        else if (guess < number) std::cout << "Too low\n";
        else std::cout << "You got it in " << tries << " tries\n";
    }while(guess!=number);

    std::cout << "Well Done\n";
}
