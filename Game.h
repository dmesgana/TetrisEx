//Game Mode
#ifndef _GAME_
#define _GAME_

#include "pieces.h"
#include "board.h"
#include "IO.h"
#include <time.h>

#define WAIT_TIME 700

class Game
{
    public:
    void DrawScene();
    void CreateNewPiece();

    int PosX, PosY;
    int nPiece, Rotation;

    private:
    int screenHeight;
    int NextPosX, NextPosY;
    int NextPiece, NextRotation;

    Board *nBoard;
    Pieces *nPieces;
    IO *nIO;

    int GetRand(int A, int B);
    void InitGame();
    void DrawPiece(int X, int Y, int Piece, int Rotation);
    void DrawBoard();

};

#endif //_GAME_