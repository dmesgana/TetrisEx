#include "pieces.h"
#include <iostream>

int Pieces::GetBlockType(int Piece, int Rotation, int X, int Y)
{
    //return type of block [0==empty, 1==block, 2==rotation point]
    return nPieces[Piece][Rotation][X][Y];
}

int Pieces::GetXInitialPos(int Piece, int Rotation)
{
    //return offset X position
    return startPos[Piece][Rotation][0];
}

int Pieces::GetYInitialPos(int Piece, int Rotation)
{
    //return offset X position
    return startPos[Piece][Rotation][1];
}