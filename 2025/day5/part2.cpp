#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

struct Range {
    long long s;
    long long e;
    bool operator<(const Range& other) const {
        return s < other.s;
    }
};

int main() {
    std::fstream file("day5.txt"); 
    std::string line;
    std::vector<Range> R;
    long long count = 0;
    if (!file.is_open()) return 1;
    while (std::getline(file, line)) {
        if (line.empty() || line == "\r") break;
        size_t hyphenPos = line.find('-');
        if (hyphenPos == std::string::npos) continue;
        R.push_back({std::stoll(line.substr(0, hyphenPos)), std::stoll(line.substr(hyphenPos + 1))});
    }
    file.close(); 
        std::sort(R.begin(), R.end());
    std::vector<Range> M;
    M.push_back(R[0]);
    for (size_t i = 1; i < R.size(); ++i) {
        Range& last = M.back();
        const Range& curr = R[i];
        if (curr.s <= last.e + 1) last.e = std::max(last.e, curr.e);
        else M.push_back(curr);
    }
    for (const auto& r : M) count += (r.e - r.s) + 1;
    std::cout << "Count: " << count << std::endl;
    return 0;
}