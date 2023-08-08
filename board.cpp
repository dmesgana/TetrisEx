#include "board.h"

void Board::InitBoard()
{
    for(int i = 0; i < BOARD_WIDTH; i++)
        for(int j = 0; j < BOARD_HEIGHT; j++)
            nBoard[i][j] = POS_FREE;
}

void Board::StorePiece(int X, int Y, int Piece, int Rotation)
{
    for(int i1 = X, i2 = 0; i1 < X + PIECE_BLOCKS; i1++, i2++)
    {
        for(int j1 = Y, j2 = 0; j1 < Y + PIECE_BLOCKS; j1++, j2++)
        {
            if(nPieces->GetBlockType(Piece, Rotation, j2, i2) != 0)
                nBoard[i1][j1] = POS_FILLED;
        }
    }
}

bool Board::IsGameOver()
{
    for(int i = 0; i < BOARD_WIDTH; i++)
        if(nBoard[i][0] == POS_FILLED) return true;
    return false;
}

void Board::DeleteLine(int Y)
{
    for(int j = Y; j > 0; j--)
        for(int i = 0; i < BOARD_WIDTH; i++)
            nBoard[i][j] = nBoard[i][j-1];
}

void Board::DeletePossibleLines()
{
    for(int j = 0; j < BOARD_HEIGHT; j++)
    {
        int i = 0;
        while(i < BOARD_WIDTH)
        {
            if(nBoard[i][j] != POS_FILLED) break;
            i++;
        }
        if(i == BOARD_WIDTH) DeleteLine(j);
    }
}

bool Board::IsFreeBlock(int X, int Y)
{
    if(nBoard[X][Y] == POS_FREE) return true;
    return false;
}

int Board::GetXPosInPixels(int Pos)
{
    return ((BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH/2)))+(Pos*BLOCK_SIZE));
}

int Board::GetYPosInPixels(int Pos)
{
    return ((BOARD_POSITION - (BLOCK_SIZE*BOARD_HEIGHT))+(Pos*BLOCK_SIZE));
}

bool Board::IsPossibleMovement(int X, int Y, int Piece, int Rotation)
{
    for(int i1 = X, i2 = 0; i1 < X + PIECE_BLOCKS; i1++, i2++)
    {
        for(int j1 = Y, j2 = 0; j1 < Y + PIECE_BLOCKS; j1++, j2++)
        {
            if(i1 < 0 || i1 > BOARD_WIDTH - 1 || j1 > BOARD_HEIGHT - 1)
            {
                if(nPieces->GetBlockType(Piece, Rotation, j2, i2) != 0)
                    return false;
            }
            if(j1 >= 0)
            {
                if((nPieces->GetBlockType(Piece, Rotation, j2, i2) != 0) && (!IsFreeBlock(i1, j1)))
                    return false;
            }
        }
    }
    return true;
}
