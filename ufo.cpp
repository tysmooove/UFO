#include <iostream>
#include <string>
#include "ufo_functions.hpp"

int main() {
  int misses {0};
  std::string codeword = "shockwaves";
  std::string answer = "__________";
  std::vector<char> incorrect;
  bool guess = false;
  char letter;

  greet();

  while(answer != codeword && misses < 7){
    display_misses(misses);
    display_status(incorrect, answer);

    std::cout << "\n\nPlease enter your guess: ";
    std::cin >> letter;

    for (int k = 0; k < codeword.length(); k++){
      if(letter == codeword[k]){
        answer[k] = letter;
        guess = true;
      }
    }

    if (guess){
      std::cout << "Correct!\n";
    } else {
      std::cout << "Incorrect! The tractor beam pulls the person in further.\n";
      incorrect.push_back(letter);
      misses++;
    }
    guess = false;
  }

  end_game(answer, codeword);
}
