#include "game.h"
#include <iostream>
#include <cassert>
#include <stdlib.h>

int Game::GetRand(int A, int B)
{
    return rand() % (B-A+1) + A;
}

void Game::DrawScene()
{
    DrawBoard();
    DrawPiece(PosX, PosY, nPiece, Rotation);
    DrawPiece(NextPosX, NextPosY, NextPiece, NextRotation);
}

void Game::CreateNewPiece()
{
    nPiece = NextPiece;
    Rotation = NextRotation;
    PosX = (BOARD_WIDTH/2) + nPieces->GetXInitialPos(nPiece, Rotation);
    PosY = nPieces->GetYInitialPos(nPiece, Rotation);

    //Next random piece
    NextPiece = GetRand(0, 6);
    NextRotation = GetRand(0, 3);
}

void Game::InitGame()
{
    srand((unsigned int) time(NULL));
    //First Piece
    nPiece = GetRand(0, 6);
    Rotation = GetRand(0, 3);
    PosX = (BOARD_WIDTH/2) + nPieces->GetXInitialPos(nPiece, Rotation);
    PosY = nPieces->GetYInitialPos(nPiece, Rotation);

    //Next Piece
    NextPiece = GetRand(0, 6);
    NextRotation = GetRand(0, 3);
    NextPosX = BOARD_WIDTH + 5;
    NextPosY = 5;
}

void Game::DrawPiece(int X, int Y, int Piece, int Rotation)
{
    color Color;

    int pixelX = nBoard->GetXPosInPixels(X);
    int pixelY = nBoard->GetYPosInPixels(Y);

    for(int i = 0; i < PIECE_BLOCKS; i++)
    {
        for(int j = 0; j < PIECE_BLOCKS; j++)
        {
            switch(nPieces->GetBlockType(Piece, Rotation, j, i))
            {
                case 1: Color = GREEN; break;
                case 2: Color = BLUE; break;
            }
            if(nPieces->GetBlockType(Piece, Rotation, j, i) != 0)
                nIO->DrawRectangle(pixelX + i * BLOCK_SIZE,
                pixelY + j * BLOCK_SIZE,
                (pixelX + i * BLOCK_SIZE) + BLOCK_SIZE - 1,
                (pixelY + j * BLOCK_SIZE) + BLOCK_SIZE - 1,
                Color);
        }
    }
}

void Game::DrawBoard()
{
    int X1 = BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH/2)) - 1;
    int X2 = BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH/2));
    int Y = screenHeight - (BLOCK_SIZE * BOARD_HEIGHT);

    //check vertical bounds larger than min size
    assert(Y > MIN_VERTICAL_MARGIN);

    nIO->DrawRectangle(X1 - BOARD_LINE_WIDTH, Y, X1, screenHeight - 1, BLUE);
    nIO->DrawRectangle(X2, Y, X2 + BOARD_LINE_WIDTH, screenHeight - 1, BLUE);

    //check horizontal bounds larger than min size
    assert(X1 > MIN_HORIZONTAL_MARGIN);

    X1 += 1;

    for(int i = 0; i < BOARD_WIDTH; i++)
    {
        for(int j = 0; j < BOARD_HEIGHT; j++)
        {
            if(!nBoard->IsFreeBlock(i,j))
                nIO->DrawRectangle(X1 + i * BLOCK_SIZE,
                Y + j * BLOCK_SIZE,
                (X1 + i * BLOCK_SIZE) + BLOCK_SIZE - 1,
                (Y + j * BLOCK_SIZE) + BLOCK_SIZE - 1,
                RED);
        }
    }
}
