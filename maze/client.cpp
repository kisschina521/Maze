#include <iostream>
#include "Maze.h"

int main()
{
    std::cout << "�������Թ�·������������";

    int row, col;
    std::cin >> row >> col;
    Maze maze(row, col);
    maze.run(row, col, maze);
}