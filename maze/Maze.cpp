#include <iostream>
#include "Maze.h"

Maze::Maze(int row, int col) :m_row(row), m_column(col)
{
    mpMaze = new MazeNode*[row];
    for (int i = 0; i < col; ++i)
    {
        mpMaze[i] = new MazeNode[col];
    }
}


Maze::~Maze()
{
    for (int i = 0; i < m_row; ++i)
    {
        delete[]mpMaze[i];
    }
    delete[]mpMaze;
    mpMaze = nullptr;
}
void Maze::run(int row, int col, Maze &maze)
{
    std::cout << "请输入迷宫的具体路径信息(0表示能走，1表示不能走)：" << std::endl;
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            int data;
            std::cin >> data;
            maze.initMaze(data, i, j);
        }
    }

    std::cout << std::endl;
    std::cout << "Path has been found" << std::endl << std::endl;

    /*
    0 0 1 0 0
    0 0 0 0 0
    1 0 0 1 1
    0 1 0 1 0
    1 0 0 0 0
    */
    initDirectionStatus();
    findPath();
    showPath();
}

void Maze::initMaze(int data, int x, int y)
{
    mpMaze[x][y].setNode(data, x, y);
}

void Maze::findPath()
{
    m_stack.Push(mpMaze[0][0]);

    while (!m_stack.empty())
    {
        MazeNode node = m_stack.getTop();
        int i = node.getX();
        int j = node.getY();

        if (i == m_row - 1 && j == m_column - 1)
        {
            break;
        }

        // 右
        if (mpMaze[i][j].getWayState(RIGHT) == OK)
        {
            mpMaze[i][j].setDirectionStatus(RIGHT, NO);
            mpMaze[i][j + 1].setDirectionStatus(LEFT, NO);
            m_stack.Push(mpMaze[i][j + 1]);
            continue;
        }

        // 下
        if (mpMaze[i][j].getWayState(DOWN) == OK)
        {
            mpMaze[i][j].setDirectionStatus(DOWN, NO);
            mpMaze[i + 1][j].setDirectionStatus(UP, NO);
            m_stack.Push(mpMaze[i + 1][j]);
            continue;
        }

        // 左
        if (mpMaze[i][j].getWayState(LEFT) == OK)
        {
            mpMaze[i][j].setDirectionStatus(LEFT, NO);
            mpMaze[i][j - 1].setDirectionStatus(RIGHT, NO);
            m_stack.Push(mpMaze[i][j - 1]);
            continue;
        }

        // 上
        if (mpMaze[i][j].getWayState(UP) == OK)
        {
            mpMaze[i][j].setDirectionStatus(UP, NO);
            mpMaze[i - 1][j].setDirectionStatus(DOWN, NO);
            m_stack.Push(mpMaze[i - 1][j]);
            continue;
        }

        m_stack.Pop();
    }
}

void Maze::showPath()
{
    if (m_stack.empty())
    {
        std::cout << "该迷宫不存在可同行的路径" << std::endl;
        return;
    }
    while (!m_stack.empty())
    {
        MazeNode node = m_stack.getTop();
        int i = node.getX();
        int j = node.getY();
        mpMaze[i][j].setNodeStatus('*');
        m_stack.Pop();
    }

    for (int i = 0; i < m_row; ++i)
    {
        for (int j = 0; j < m_column; ++j)
        {
            if (mpMaze[i][j].getStatus() == '*')
            {
                std::cout << "* ";
            }
            else
            {
                std::cout << mpMaze[i][j].getStatus() << " ";
            }
        }
        std::cout << std::endl;
    }
}

void Maze::initDirectionStatus()
{
    for (int j = 0; j < m_column; ++j)
    {
        //mpMaze[0][j].mstate[UP] = NO;
        mpMaze[0][j].setDirectionStatus(UP, NO);
        //mpMaze[mrow - 1][j].mstate[DOWN] = NO;
        mpMaze[m_row - 1][j].setDirectionStatus(DOWN, NO);
    }
    for (int i = 0; i < m_row; ++i)
    {
        //mpMaze[i][0].mstate[LEFT] = NO;
        mpMaze[i][0].setDirectionStatus(LEFT, NO);
        //mpMaze[i][mcol - 1].mstate[RIGHT] = NO;
        mpMaze[i][m_column - 1].setDirectionStatus(RIGHT, NO);
    }

    for (int i = 0; i < m_row; ++i)
    {
        for (int j = 0; j < m_column; ++j)
        {
            if (1 == mpMaze[i][j].getStatus())
            {
                if (j > 0)
                    mpMaze[i][j - 1].setDirectionStatus(RIGHT, NO);
                if (j < m_column - 1)
                    //mpMaze[i][j + 1].mstate[LEFT] = NO;
                    mpMaze[i][j + 1].setDirectionStatus(LEFT, NO);

                if (i < m_row - 1)
                    //mpMaze[i + 1][j].mstate[UP] = NO;
                    mpMaze[i + 1][j].setDirectionStatus(UP, NO);
                if (i > 0)
                    //mpMaze[i - 1][j].mstate[DOWN] = NO;
                    mpMaze[i - 1][j].setDirectionStatus(DOWN, NO);
            }
            else
            {
                continue;
            }
        }
    }
}