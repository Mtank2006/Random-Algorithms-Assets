#include <iostream>
#include <map>

int main() {
    std::string Sentence;
    std::cout << "Enter the sentence: " << "\n";
    std::getline(std::cin, Sentence);

    std::map<char, int> freq;

    for(int i = 0; i < Sentence.length(); ++i) {
        char character = Sentence[i];

        if (freq.find(character) == freq.end()) {
            freq[character] = 0;
        }
        freq[character]++;
    }
    for (auto itr = freq.begin(); itr != freq.end(); ++itr) {
        std::cout << (*itr).first << " : " << itr->second << "\n";
    }
}