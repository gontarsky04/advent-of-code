#include <iostream>
#include <vector>
#include <string>
#include <fstream>

int main() {
    std::ifstream file("day4.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open file\n";
        return 1;
    }

    std::vector<std::string> grid;
    std::string line;

    while (std::getline(file, line)) {
        grid.push_back(line);
    }

    int rows = grid.size();
    int cols = grid[0].size();
    int d[8][2] = { {-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1} };
    int totalRemoved = 0;
    while (true) {
        std::vector<std::pair<int,int>> toRemove;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] != '@') continue;
                int count = 0;
                for (auto &dir : d) {
                    int nr = r + dir[0];
                    int nc = c + dir[1];
                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                        if (grid[nr][nc] == '@')
                            count++;
                    }
                }
                if (count < 4)
                    toRemove.push_back({r, c});
            }
        }
        if (toRemove.empty())
            break;
        for (auto &p : toRemove) {
            grid[p.first][p.second] = '.';
        }
        totalRemoved += toRemove.size();
    }
    std::cout << "Total rolls removed = " << totalRemoved << std::endl;
    return 0;
}