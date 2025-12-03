#include <iostream>
#include <string>
#include <fstream>

std::string best12(const std::string& s) {
    int need = 12;
    int n = s.size();
    std::string result;
    result.reserve(12);
    int i = 0;
    while (need > 0) {
        int best_pos = i;
        for (int j = i; j <= n - need; j++) {
            if (s[j] > s[best_pos]) best_pos = j;
        }
        result.push_back(s[best_pos]);
        i = best_pos + 1;
        need--;
    }

    return result;
}

long long find_max(const std::string& joltage) {
    std::string s = best12(joltage);
    return std::stoll(s);
}

int main() {
    std::ifstream file("day3.txt");
    if (!file.is_open()) return 1;
    std::string line;
    long long sum = 0;
    while (std::getline(file, line)) {
        sum += find_max(line);
    }
    std::cout << "Sum = " << sum << "\n";
    return 0;
}
