//#pragma once
#ifndef __MAZE_H__
#define __MAZE_H__

#include "MazeStack.h"

class Maze
{
public:
    Maze() : m_row(0), m_column(0){}
    Maze(int row, int col);
    ~Maze();

    void run(int row, int col, Maze &maze);
    void initMaze(int status, int x, int y);
    void initDirectionStatus();
    void findPath();
    void showPath();

private:
    int m_row;
    int m_column;
    MazeStack m_stack;
    MazeNode **mpMaze;
};
#endif
