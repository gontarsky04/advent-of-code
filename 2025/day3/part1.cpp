#include <iostream>
#include <string>
#include <fstream>

int find_max(const std::string& joltage) {
    int max_val = 0;
    for (size_t i = 0; i + 1 < joltage.length(); i++) {
        for (size_t j = i + 1; j < joltage.length(); j++) {
            int a = joltage[i] - '0';
            int b = joltage[j] - '0';
            int number = a * 10 + b;
            if (number > max_val) max_val = number;
        }
    }
    return max_val;
}

int main() {
    std::ifstream file("day3.txt");
    if (!file.is_open()) return 1;
    std::string joltage;
    long long sum = 0;
    while (std::getline(file, joltage)) {
        sum += find_max(joltage);
    }
    std::cout << "Sum = " << sum << std::endl;
    return 0;
}
