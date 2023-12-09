#include "raylib.h"
#define SCREEN_W 400
#define SCREEN_H 600
#define Clipit (Color){ 255, 203, 0, 255 }
#define REDHOVER (Color){ 255, 160, 0, 255 }
typedef struct
{
    Vector2 coordinates;
    int width;
    int height;
    Color color;
}Shape;

void center_x(Shape *shape);

void center_text(   
        
        const char * text ,
        Shape * shapInfo ,
        Font font ,
        float font_size ,
        float spacing

    );

void handle_ctrl(Vector2 *win);
bool IsMouseInsideRect(int x, int y, int width, int height);
void get_saved_pos(Vector2 * win);
void drawMainLayout(Texture2D icon , Font titleFont);
bool close_button(Texture2D xTexture);