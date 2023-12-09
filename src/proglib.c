#include <stdio.h>
#include <stdlib.h>
#include "proglib.h"

void center_x(Shape *shape){
    shape->coordinates.x = (SCREEN_W - shape->width ) / 2 ;
}

void center_text(   
        const char * text ,
        Shape * shapInfo ,
        Font font ,
        float font_size ,
        float spacing

    )
{
    Vector2 WH = MeasureTextEx(font ,text, font_size, spacing);
    shapInfo->height = WH.y;
    shapInfo->width = WH.x;
    printf("\n w = %d , h = %d\n",shapInfo->width , shapInfo->height);
    center_x(shapInfo);
    shapInfo->coordinates.y = (SCREEN_H - shapInfo->height) / 2 ;
}


void handle_ctrl(Vector2 *win)
{
    if (IsKeyDown(KEY_LEFT_CONTROL)) {
        if (IsKeyDown(KEY_UP))
        {
            win->y -= 10;
            if(win->y < 0) win->y = 0;
        }
        else if (IsKeyDown(KEY_DOWN))
        {
            win->y += 10;
            if(win->y > 1080 - SCREEN_H) win->y = 1080 - SCREEN_H;
        }
        else if (IsKeyDown(KEY_RIGHT))
        {
            win->x += 10;
            if(win->x > 1920 - SCREEN_W) win->x = 1920 - SCREEN_W;
        }
        else if (IsKeyDown(KEY_LEFT))
        {
            win->x -= 10;
            if(win->x < 0 ) win->x = 0 ;
        }  
        FILE *win_posF = fopen("win.pos", "wb");
        if (win_posF != NULL){
            fwrite(win,1 ,sizeof(win),win_posF);
            fclose(win_posF);
        }
    }
}

bool IsMouseInsideRect(int x, int y, int width, int height) {
    Vector2 mouse = GetMousePosition();
    return (mouse.x >= x && mouse.x <= x + width && mouse.y >= y && mouse.y <= y + height);
}

void get_saved_pos(Vector2 * win)
{
    FILE *win_inff = fopen("win.pos", "rb");
    if (win_inff)
    {
        fread(win , 1 , sizeof(win),win_inff);
        printf("saved x = %f , y = %f",win->x , win->y);
        fclose(win_inff);
    }
    else
    {
        win->x = 1920 / 2 - SCREEN_W / 2 ;
        win->y = 1080 / 2 - SCREEN_H / 2 ;
    }
}

void drawMainLayout(Texture2D icon , Font titleFont)
{
    Color background_color = { 60 , 60 , 60 , 1 };
    ClearBackground(background_color);
    DrawRectangle(0, 0, SCREEN_W, 40, GRAY);
    DrawTextureEx(icon,(Vector2) {7, 7}, 0 , 0.05 , WHITE );
    DrawTextEx(titleFont,"Clipit", (Vector2) { 40 , 5 } , titleFont.baseSize, 0 ,Clipit);
    
}

bool close_button(Texture2D xTexture)
{
    if (IsMouseInsideRect(SCREEN_W - 50, 0, 40, 50) ) {
        
        DrawRectangle(SCREEN_W - 50 , 0 , 50, 40, Clipit);
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) return true;
    }       
    else DrawRectangle(SCREEN_W - 50 , 0 , 50, 40, GRAY);
    DrawTextureEx(xTexture,(Vector2) {SCREEN_W - 30, 15}, 0 , 0.025 , WHITE );
    return false;

}
// void change_background_color()
// {
//     static bool ascending = true;
//     if(ascending){
//         background_color.r++;
//         background_color.b++;
//         if (background_color.r > 100)
//             ascending = false ;
        
//     } 
//     else
//     {
//         background_color.r--;
//         background_color.b--;
//         if (background_color.r == 50)
//             ascending = true;
        
//     }
    
// }