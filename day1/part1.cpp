#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("day1.txt");
    if (!file.is_open()) return 1;

    long long number;
    char direction;
    int position = 50;
    int zeros = 0;

    while (file >> direction >> number) {
        if (direction == 'L') {
            position = (position - (number % 100) + 100) % 100;
        } else if (direction == 'R') {
            position = (position + (number % 100)) % 100;
        }
        if (position == 0) {
            zeros++;
        }
    }
    
    std::cout << "Password = " << zeros << std::endl;
    return 0;
}
