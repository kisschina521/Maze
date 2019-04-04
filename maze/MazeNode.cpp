#include "MazeNode.h"
//extern const int RIGHT;

MazeNode::MazeNode(int x, int y) : m_x(x), m_y(y)
{
    for (int i = 0; i < WAYNUM; ++i)
    {
        m_state[i] = OK;
    }
}
MazeNode::MazeNode()
{
    for (int i = 0; i < WAYNUM; ++i)
    {
        m_state[i] = OK;
    }
}
MazeNode::~MazeNode()
{

}
int MazeNode::getX()
{
    return m_x;
}

int MazeNode::getY()
{
    return m_y;
}

void MazeNode::setDirectionStatus(int direction, int status)
{
    m_state[direction] = status;
}

void MazeNode::setNode(int val, int x, int y)
{
    m_x = x;
    m_y = y;
    m_status = val;
}

int MazeNode::getWayState(int way)
{
    return m_state[way];
}

int MazeNode::getStatus()
{
    return m_status;
}

void MazeNode::setNodeStatus(int status)
{
    m_status = status;
}
