#include <stdio.h>
#include <stdlib.h>
#include "proglib.h"

// colors

Color background_color =    { 49, 54, 59, 1  };
// Color node_color       =    { 35, 38, 39, 255};

// functions

void center_x(Shape *shape  , unsigned int width){
    shape->coordinates.x = (width - shape->width ) / 2 ;
}
void center_y(Shape *shapInfo ,unsigned int height){
    shapInfo->coordinates.y = ((height - shapInfo->height) / 2 ) + shapInfo->coordinates.y;
}

void center_text(   
        const char * text ,
        Shape * shapInfo ,
        Font font ,
        float font_size ,
        float spacing ,
        unsigned int height ,
        unsigned int width

    )
{
    Vector2 WH = MeasureTextEx(font ,text, font_size, spacing);
    shapInfo->height = WH.y;
    shapInfo->width  = WH.x;
    // printf("\n w = %d , h = %d\n",shapInfo->width , shapInfo->height);
    center_x(shapInfo , width);
    center_y(shapInfo , height );
    
}



bool IsMouseInsideRect(int x, int y, int width, int height) {
    Vector2 mouse = GetMousePosition();
    return (mouse.x >= x && mouse.x <= x + width && mouse.y >= y && mouse.y <= y + height);
}

void drow_clip_node(const char *content , Font font)
{
    static Shape node  = {(Vector2){0 , 30}, SCREEN_W - 20 , 0 , (Color){35, 38, 39, 255}};
    center_x(&node , SCREEN_W);
    node.height = MeasureTextEx(font ,content, font.baseSize, 0).y + 30;

    Shape fontInfo = {(Vector2){20 , 0}, 0 , 0 , LIGHTGRAY};
    static unsigned int plus = 0;
    // center_text(content ,&fontInfo, font ,font.baseSize,0 , node.height , node.width);
    center_y(&fontInfo , node.height  );
    // fontInfo.coordinates.y += + node.coordinates.y;
    

    if(IsKeyDown(KEY_UP)){ 
        node.coordinates.y     -= 10;
        plus                   -= 10;
        // printf("node.y = %d\n",node.coordinates.y);
    }
    if(IsKeyDown(KEY_DOWN)) {
        node.coordinates.y     += 10;
        plus                   += 10;
        // printf("node.y = %d\n",node.coordinates.y);
        
    }
    fontInfo.coordinates.y += plus; 
    
    DrawRectangle(node.coordinates.x, node.coordinates.y , node.width, node.height, node.color );
    DrawTextEx(font,content, fontInfo.coordinates, font.baseSize, 0 , fontInfo.color);
    DrawRectangle(0, 0, SCREEN_W, 30, background_color);

}

#ifdef WIN_V

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
#else

    void drawMainLayout( Font titleFont)
    {

        ClearBackground(background_color);
        drow_clip_node("go to hell bro \n\n gg",titleFont);
    }

#endif
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