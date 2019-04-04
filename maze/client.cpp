#include <iostream>
#include "Maze.h"

int main()
{
    std::cout << "请输入迷宫路径的行列数：";

    int row, col;
    std::cin >> row >> col;
    Maze maze(row, col);
    maze.run(row, col, maze);
}