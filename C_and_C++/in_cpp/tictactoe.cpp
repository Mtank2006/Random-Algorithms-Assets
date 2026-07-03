#include <iostream>
#include <ctime>

void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner (char *spaces, char player, char computer);
bool checkTie(char *spaces);

int main() {
    char spaces[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char choice;
    char player;
    char computer;
    std::cout << "Choose X or O, Type what you want" <<'\n';
    std::cin >> choice;
    if (choice == 'X' || std::toupper(choice) == 'X') {
        player = 'X';
        computer = 'O';
    } else {
        player = 'O';
        computer = 'X';
    }
    bool running = true;

    drawBoard(spaces);

    while (running) {
        playerMove(spaces,player);
        drawBoard(spaces);
        if (checkWinner(spaces, player, computer)) {
            running = false;
            break;
        }
        else if (checkTie(spaces)) {
            running = false;
            break;
        }
        computerMove(spaces,computer);
        drawBoard(spaces);
        if (checkWinner(spaces, player, computer)) {
            running = false;
            break;
        }
        else if (checkTie(spaces)) {
            running = false;
            break;
        }
    }

    std::cout << "Thanks for playing\n";
    return 0;
}
void drawBoard(char *spaces) {
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << '\n';
    std::cout << "     |     |     " << '\n';
}
void playerMove(char *spaces, char player) {
    int position;
    do {
        std::cout << "Enter the postion (1-9): " << "\n"; 
        std::cin >> position;
        position--;
        if (spaces[position] == ' ') {
            spaces[position] = player;
            break;
        }
    }while(position > 0 || position < 9);

}
void computerMove(char *spaces, char computer) {
    int position;
    srand(time(0));
    do {
        position = rand() % 9;
        if (spaces[position] == ' ') {
            spaces[position] = computer;
            break;
        }

    }while(position > 0 || position < 9);
}
bool checkWinner (char *spaces, char player, char computer) {
    for (int i = 0; i < 3; i++) {
        if ((spaces[i] != ' ') && (spaces[i] == spaces[i+3]) && (spaces[i+3] == spaces[i+6])) {
            spaces[i] == player ? std::cout << "You Win\n" : std::cout << "You Lose\n"; 
            return true;
        }
    }
    for (int i = 0; i < 7; i+=3) {
        if ((spaces[i] != ' ') && (spaces[i] == spaces[i+1]) && (spaces[i+1] == spaces[i+2])) {
            spaces[i] == player ? std::cout << "You Win\n" : std::cout << "You Lose\n"; 
            return true;
        }
    }
    if ((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8])) {
            spaces[0] == player ? std::cout << "You Win\n" : std::cout << "You Lose\n"; 
            return true;
    }
    if ((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6])) {
            spaces[2] == player ? std::cout << "You Win\n" : std::cout << "You Lose\n"; 
            return true;
    }
    return  false;
}
bool checkTie(char *spaces) {
    for (int i = 0; i < 9; i++) {
        if (spaces[i] == ' ') {
            return false;
        }
    }
    std::cout << "Tie\n";
    return true;
}