#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("day1.txt");
    if (!file.is_open()) return 1;
    long long number;
    char direction;
    int position = 50;
    long long zeros = 0;

    while (file >> direction >> number) {
        zeros += (number / 100);
        int remainder = number % 100;

        for (int i = 0; i < remainder; ++i) {
            if (direction == 'L') {
                position--;
                if (position < 0) position = 99;
            } else if (direction == 'R') {
                position++;
                if (position > 99) position = 0;
            }
            
            if (position == 0) {
                zeros++;
            }
        }
    }
    
    std::cout << "Password = " << zeros << std::endl;
    return 0;
}