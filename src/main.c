#include "raylib.h"
#include "proglib.h"
#include <stdbool.h>
#include <stdio.h>


Vector2 win ;


int main(void)
{
    // window properties
    
    InitWindow(SCREEN_W , SCREEN_H, "Clipit");

    #ifdef WIN_V
        SetWindowState(FLAG_WINDOW_UNDECORATED);
    #endif

    SetTargetFPS(30);


    // fonts & colors 
    Font Nunito = LoadFont("./fonts/Nunito.ttf");
    Font NunitoBold = LoadFont("./fonts/static/Nunito-ExtraBold.ttf");

    // Font nodeFont = LoadFont("./fonts/Node.ttf");


    Image icon = LoadImage("./imgs/main_ico.png");
    SetWindowIcon(icon);
    
    #ifdef WIN_V
        Texture2D icoTexture = LoadTextureFromImage(icon);
        Image x_close = LoadImage("./imgs/x.png");
        Texture2D xTexture = LoadTextureFromImage(x_close);
        Shape toolbar ;
        toolbar.width = SCREEN_W;
        toolbar.height = 10 ;
        center_x(&toolbar);
        get_saved_pos(&win);
    #endif
    

    Shape dtext;
    char text[] = "Nothing yet !\n\nPress Esc to close";
    center_text(text,&dtext,Nunito , Nunito.baseSize , 0 , SCREEN_H , SCREEN_W);
    
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        #ifdef WIN_V
            SetWindowPosition( win.x , win.y );
            if (IsKeyDown(KEY_LEFT_CONTROL)) {
                handle_ctrl(&win);
            }
        #endif
    
        if(IsKeyPressed(KEY_ESCAPE))
        {
            break;
        }

        BeginDrawing();
            
            DrawTextEx(Nunito,text, dtext.coordinates , Nunito.baseSize, 0 , LIGHTGRAY);
            drawMainLayout(Nunito);



            #ifdef WIN_V
                if (close_button(xTexture)) break;
            #endif

        EndDrawing();
    }
    UnloadFont(Nunito);
    UnloadFont(NunitoBold);
    // UnloadFont(nodeFont);
    UnloadImage(icon);
    #ifdef WIN_V
        UnloadImage(x_close);
    #endif // 
    
    CloseWindow();
    return 0;
}
