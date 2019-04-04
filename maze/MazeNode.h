#pragma once

const int RIGHT = 0;
const int DOWN = 1;
const int LEFT = 2;
const int UP = 3;
const int WAYNUM = 4;
const int OK = 5;
const int NO = 6;

class MazeNode
{
public:
    MazeNode(int x, int y);
    MazeNode();
    ~MazeNode();

    int getX();
    int getY();
    int getStatus();
    int getWayState(int way);

    void setDirectionStatus(int direction, int status);
    void setNode(int val, int x, int y);
    void setNodeStatus(int status);

private:
    int m_x;
    int m_y;
    int m_status;
    int m_state[WAYNUM];
};
