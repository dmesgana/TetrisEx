#ifndef _IO_
#define _IO_

#ifndef LINUX
#include "SDL/include/SDL.h"
#include "SDL/SDL_GfxPrimitives/SDL_gfxPrimitives.h"
#else
#include <SDL/SDL.h>
#include "SDL/SDL_GfxPrimitives/SDL_gfxPrimitives.h"
#endif
#pragma comment(lib, "SDL/lib/SDL.lib")
#pragma comment(lib, "SDL/SDL_GfxPrimitives/SDL_gfxPrimitives_Static.lib")

enum color {BLACK, RED, GREEN, BLUE, CYAN, MAGENTA, YELLOW, WHITE, COLOR_MAX};

class IO
{
    public:
    IO();

    void DrawRectangle(int X1, int Y1, int X2, int Y2, enum color C);
    void ClearScreen();
    int GetScreenHeight();
    int InitGraph();
    int Pollkey();
    int Getkey();
    int IsKeyDown(int key);
    void UpdateScreen();

};

#endif //_IO_