#include<iostream>

int main(){
  int n = 4;

  for(int i = 0; i < n; i++){

    for(int j = 0; j < i + 1; j++){
      std::cout << "*";
    }

    for(int k = 0; k < 2 * (n - i - 1); k++){
      std::cout << " ";
    }

    for(int j = 0; j < i + 1; j++){
      std::cout << "*";
    }
    std::cout << "\n";

  }

  for(int i = 0; i < n; i++){

    for(int j = 0; j < n - i; j++){
      std::cout << "*";
    }

    for(int k = 0; k < (n / 2) * i; k++){
      std::cout << " ";
    }

    for(int j = 0; j < n - i; j++){
      std::cout << "*";
    }

    std::cout << "\n";
  }
  return 0;
}
