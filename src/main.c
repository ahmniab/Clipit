#include "raylib.h"
#include "proglib.h"
#include <stdbool.h>
#include <stdio.h>


Vector2 win ;


int main(void)
{
    
    InitWindow(SCREEN_W , SCREEN_H, "Clipit");
    SetWindowState(FLAG_WINDOW_UNDECORATED);
    SetTargetFPS(30);

    // SetWindowFlags(FLAG_WINDOW_RESIZABLE);
    Font Nunito = LoadFont("./fonts/Nunito.ttf");
    Font NunitoBold = LoadFont("./fonts/static/Nunito-ExtraBold.ttf");

    Image icon = LoadImage("./imgs/main_ico.png");
    SetWindowIcon(icon);
    Texture2D icoTexture = LoadTextureFromImage(icon);
    
    Image x_close = LoadImage("./imgs/x.png");
    Texture2D xTexture = LoadTextureFromImage(x_close);

    Shape toolbar ;
    toolbar.width = SCREEN_W;
    toolbar.height = 10 ;
    center_x(&toolbar);

    Shape dtext;
    char text[] = "Nothing yet !\n\nPress Esc to close";
    center_text(text,&dtext,Nunito , Nunito.baseSize , 0 );
    get_saved_pos(&win);
    
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
    SetWindowPosition( win.x , win.y );
    if (IsKeyDown(KEY_LEFT_CONTROL)) {
        handle_ctrl(&win);
    }
    
        if(IsKeyPressed(KEY_ESCAPE))
        {
            break;
        }
        BeginDrawing();
            
            drawMainLayout(icoTexture , NunitoBold);
            DrawTextEx(Nunito,text, dtext.coordinates , Nunito.baseSize, 0 , LIGHTGRAY);

            if (close_button(xTexture)) break;
        
        EndDrawing();
    }
    UnloadFont(Nunito);
    UnloadFont(NunitoBold);
    UnloadImage(icon);
    UnloadImage(x_close);
    CloseWindow();
    return 0;
}
