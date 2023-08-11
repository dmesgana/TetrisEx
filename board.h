//Tetris Board definition
#ifndef _BOARD_
#define _BOARD_

#include "pieces.h"

#define BOARD_LINE_WIDTH 6
#define BLOCK_SIZE 16
#define BOARD_POSITION 320
#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20
#define MIN_VERTICAL_MARGIN 20
#define MIN_HORIZONTAL_MARGIN 20
#define PIECE_BLOCKS 5

class Board
{
    public:
        Board(Pieces* pPieces, int pScreenHeight)
        {
            nPieces = pPieces;
            screenHeight = pScreenHeight;
        };

    int GetXPosInPixels(int Pos);
    int GetYPosInPixels(int Pos);
    bool IsFreeBlock(int X, int Y);
    bool IsPossibleMovement(int X, int Y, int Piece, int Rotation);
    void StorePiece(int X, int Y, int Piece, int Rotation);
    void DeletePossibleLines();
    bool IsGameOver();

    private:
    enum { POS_FREE, POS_FILLED }; // POS_FREE = free position on the board
    int nBoard[BOARD_WIDTH][BOARD_HEIGHT];
    Pieces *nPieces;
    int screenHeight;

    void InitBoard();
    void DeleteLine(int Y);
};

#endif // _BOARD_