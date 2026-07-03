#include <iostream>
#include <ctime>

char getPlayerChoice();
char getComputerChoice();
void showChoice(char choice);
void chooseWinner(char player,char computer);

int main() {
    char player;
    char computer;
    player = getPlayerChoice();
    std::cout << "Your choice: ";
    showChoice(player);

    computer = getComputerChoice();
    std::cout << "Computer's Choice: ";
    showChoice(computer);

    chooseWinner(player, computer);
    return 0;
}
char getPlayerChoice() {

    char choice;
    std::cout << "Rock-Paper-Scissors Game \n";

    do
    {
        std::cout << "Choose one of the choice \n";
        std::cout << "************************ \n";
        std::cout << "r - rock, p - paper, s - scissors\n";
        std::cin >> choice;
    } while (!(choice == 'r' || choice == 'p' || choice == 's') );
    
    return choice;
}
char getComputerChoice() {
    srand(time(0));
    int num = rand() % 3 + 1;

    switch (num)
    {
    case 1: return 'r';
    case 2: return 'p';
    case 3: return 's';
    }
    return 0;
}
void showChoice(char choice) {
    switch (choice)
    {
    case 'r':
        std::cout << "Rock\n";
        break;
    case 'p':
        std::cout << "Paper\n";
        break;
    case 's':
        std::cout << "Scissors\n";
        break;
    default:
        break;
    }
}
void chooseWinner(char player,char computer) {

    switch (player){
        case 'r':
            if      (computer == 'r')   std::cout << "It's a tie\n";
            else if (computer == 'p')   std::cout << "You lose\n";
            else                        std::cout << "You win\n";
            break;
        case 'p':
            if      (computer == 'r')   std::cout << "You win\n";
            else if (computer == 'p')   std::cout << "It's a tie\n";
            else                        std::cout << "You lose\n";
            break;
        case 's':
            if      (computer == 'r')   std::cout << "You lose\n";
            else if (computer == 'p')   std::cout << "You win\n";
            else                        std::cout << "It' a tie\n";
            break;
    }
}