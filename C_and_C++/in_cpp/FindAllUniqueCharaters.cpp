#include <iostream>
#include <set>

int main() {
    std::string Sentence;
    std::cout << "Enter the sentence: " << "\n";
    std::getline(std::cin, Sentence);

    std::set<char> Characters;

    for (int i = 0; i < Sentence.length(); ++i) {
        Characters.insert(Sentence[i]);
    }

    for (auto itr = Characters.begin(); itr != Characters.end(); ++itr) {
        std::cout << *itr << "\n";
    }
}
