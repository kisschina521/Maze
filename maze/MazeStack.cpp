#include "MazeStack.h"

MazeStack::MazeStack(int size)
    : msize(size)
    , mcur(0)
{
    mpstack = new MazeNode[size];
}

MazeStack::MazeStack()
{
    msize = 10;
    mcur = 0;
    mpstack = new MazeNode[msize];
}

MazeStack::~MazeStack()
{

    delete[]mpstack;
    mpstack = nullptr;
}
