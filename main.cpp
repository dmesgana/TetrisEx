#include "Game.h"
#ifndef LINUX
#include <windows.h>
#endif

#ifndef LINUX
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
#else
int main()
#endif
{
	IO mIO;
	int screenHeight = mIO.GetScreenHeight();

	//Pieces
	Pieces nPieces;

	//Board
	Board nBoard(&nPieces, screenHeight);

	//Game
	Game GameInst(&nBoard, &nPieces, &mIO, screenHeight);

	//Get clock in ms
	unsigned long timeMS = SDL_GetTicks();

	//Main Loop
	while (!mIO.IsKeyDown(SDLK_ESCAPE))
	{
		mIO.ClearScreen();
		GameInst.DrawScene();
		mIO.UpdateScreen();

		int InputKey = mIO.Pollkey();

		switch (InputKey)
		{
		case(SDLK_RIGHT):
			{
				if (nBoard.IsPossibleMovement(GameInst.PosX + 1, GameInst.PosY, GameInst.nPiece, GameInst.Rotation))
					GameInst.PosX++;
				break;
			}
		case(SDLK_LEFT):
			{
				if (nBoard.IsPossibleMovement(GameInst.PosX - 1, GameInst.PosY, GameInst.nPiece, GameInst.Rotation))
					GameInst.PosX--;
				break;
			}
		case(SDLK_DOWN):
			{
				if (nBoard.IsPossibleMovement(GameInst.PosX, GameInst.PosY + 1, GameInst.nPiece, GameInst.Rotation))
					GameInst.PosY++;
				break;
			}
		case(SDLK_x):
			{
				while (nBoard.IsPossibleMovement(GameInst.PosX, GameInst.PosY, GameInst.nPiece, GameInst.Rotation))
					GameInst.PosY++;
				nBoard.StorePiece(GameInst.PosX, GameInst.PosY - 1, GameInst.nPiece, GameInst.Rotation);
				nBoard.DeletePossibleLines();

				//Check if placed piece causes a GAME OVER
				if (nBoard.IsGameOver())
				{
					mIO.Getkey();
					exit(0);
				}

				GameInst.CreateNewPiece();
				break;
			}
		case(SDLK_z):
			{
				if (nBoard.IsPossibleMovement(GameInst.PosX, GameInst.PosY, GameInst.nPiece, (GameInst.Rotation + 1) % 4))
					GameInst.Rotation = (GameInst.Rotation + 1) % 4;
				break;
			}
		}
		
		//Falling block logic
		unsigned long elapsedtimeMS = SDL_GetTicks() - timeMS;

		if (elapsedtimeMS > WAIT_TIME)
		{
			if (nBoard.IsPossibleMovement(GameInst.PosX, GameInst.PosY, GameInst.nPiece, GameInst.Rotation))
				GameInst.PosY++;
			else
			{
				nBoard.StorePiece(GameInst.PosX, GameInst.PosY, GameInst.nPiece, GameInst.Rotation);
				nBoard.DeletePossibleLines();
				if (nBoard.IsGameOver())
				{
					mIO.Getkey();
					exit(0);
				}
				GameInst.CreateNewPiece();
			}
			timeMS = SDL_GetTicks();
		}
	}
	return 0;
}