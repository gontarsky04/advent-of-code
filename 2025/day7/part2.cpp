#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>

int main() {
    std::fstream file("day7.txt");
    if(!file.is_open()) return 1;
    std::vector<std::string> lines;
    std::string line;
    while(getline(file,line)) {
        lines.push_back(line);
    }
    long lineLength = lines[0].length();
    long startPos = lines.front().find('S');
    std::map<std::pair<int,int>, long long> activeTimelines;
    activeTimelines[{0, startPos}] = 1;    
    for(int i = 1; i < lines.size(); i++) {
        std::map<std::pair<int,int>, long long> nextTimelines;
        for(auto [pos, count] : activeTimelines) {
            auto [row, col] = pos;
            if(row != i-1) continue;            
            if(lines[i][col] == '^') {
                if(col > 0) nextTimelines[{i, col-1}] += count;
                if(col < lineLength-1) nextTimelines[{i, col+1}] += count;
            } else {
                nextTimelines[{i, col}] += count;
            }
        }        
        activeTimelines = nextTimelines;
    }
    long long totalTimelines = 0;
    for(auto [pos, count] : activeTimelines) totalTimelines += count;
    std::cout << "timelines = " << totalTimelines;
    return 0;
}
