#include <iostream>
#include <vector>
#include <string>
#include <cmath>

// Konfiguracija boja i simbola
struct ShapeConfig {
    std::string colorCode;
    std::string symbol;
};

ShapeConfig getConfig(const std::string& color) {
    if (color == "red") return {"\033[31m", "@"};
    if (color == "green") return {"\033[32m", "#"};
    if (color == "yellow") return {"\033[33m", "*"};
    if (color == "blue") return {"\033[34m", "O"};
    if (color == "magenta") return {"\033[35m", "+"};
    if (color == "cyan") return {"\033[36m", "%"};
    return {"\033[0m", "X"};
}

void display(const std::vector<std::vector<bool>>& grid, const ShapeConfig& cfg) {
    for (const auto& row : grid) {
        std::cout << cfg.colorCode;
        for (bool cell : row) {
            std::cout << (cell ? cfg.symbol + " " : "  ");
        }
        std::cout << "\033[0m" << std::endl;
    }
}

std::vector<std::vector<bool>> configRectangle(int width, int height) {
    return std::vector<std::vector<bool>>(height, std::vector<bool>(width, true));
}

std::vector<std::vector<bool>> configTriangle(int height) {
    std::vector<std::vector<bool>> grid(height, std::vector<bool>(height, false));
    for (int i = 0; i < height; ++i)
        for (int j = 0; j <= i; ++j)
            grid[i][j] = true;
    return grid;
}

std::vector<std::vector<bool>> configDiamond(int size) {
    int n = size * 2 - 1;
    std::vector<std::vector<bool>> grid(n, std::vector<bool>(n, false));
    int center = size - 1;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (std::abs(i - center) + std::abs(j - center) < size)
                grid[i][j] = true;
    return grid;
}

std::vector<std::vector<bool>> configEllipse(int a, int b) {
    int h = b * 2 + 1;
    int w = a * 2 + 1;
    std::vector<std::vector<bool>> grid(h, std::vector<bool>(w, false));
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            if ((std::pow(i - b, 2) * a * a + std::pow(j - a, 2) * b * b) <= a * a * b * b)
                grid[i][j] = true;
    return grid;
}
