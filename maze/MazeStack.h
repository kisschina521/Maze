#ifndef __MAZESTACK_H__
#define __MAZESTACK_H__

#include "MazeNode.h"

const int INC = 2;

class MazeStack
{
public:
    MazeStack();
    MazeStack(int size);
    ~MazeStack();

    MazeNode getTop()
    {
        return mpstack[mcur - 1];
    }
    void Pop()
    {
        mcur--;
    }
    bool empty()
    {
        return mcur == 0;
    }
    bool full()
    {
        return mcur == msize;
    }
    void Push(MazeNode valNode)
    {
        mpstack[mcur++] = valNode;
    }
private:
    MazeNode *mpstack;
    int mcur;
    int msize;
    void resize()
    {
        MazeNode *ptmp = new MazeNode[msize * INC];
        for (int i = 0; i < msize; ++i)
        {
            ptmp[i] = mpstack[i];
        }
        delete[]mpstack;
        mpstack = ptmp;
    }
};

#endif