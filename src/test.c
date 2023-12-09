#include "raylib.h"
#include <unistd.h>
#include<stdio.h>


int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Move Window Example");
    // SetWindowState(FLAG_WINDOW_UNDECORATED);
    bool isDragging = true;

    SetTargetFPS(60);

    Vector2 win = { 1920 / 2 - screenWidth/2 , 1080 / 2 - screenHeight / 2 };
    int offsetX = 0;
    int offsetY = 0;
    while (!WindowShouldClose()) {
        SetWindowPosition( win.x , win.y );
        
        Rectangle windowRec = { 0, 0, (float)GetScreenWidth(), (float)GetScreenHeight() };
        Vector2 mouse = GetMousePosition();
        // win.x = GetWindowPosition().x;
        // win.y = GetWindowPosition().y;
        // if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {

        //     if (CheckCollisionPointRec(mouse, windowRec)) {
        //         offsetX = (int)mouse.x - GetWindowPosition().x;
        //         offsetY = (int)mouse.y - GetWindowPosition().y;
        //         isDragging = true;
        //     }
        // }
        // } else if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
        //     isDragging = false;
        // }
         
        if (IsKeyDown(KEY_LEFT_CONTROL)) {
            if (IsKeyDown(KEY_UP))
            {
                win.y -= 10;
            }
            else if (IsKeyDown(KEY_DOWN))
            {
                win.y += 10;
            }
            else if (IsKeyDown(KEY_RIGHT))
            {
                win.x += 10;
            }
            else if (IsKeyDown(KEY_LEFT))
            {
                win.x -= 10;
            }  
        }
        // else 
        // {
        //     isDragging = true;
        //     printf("drag is true !\n");
        // }           
        


        BeginDrawing();
        ClearBackground(RAYWHITE);
        char msg[100] ;
        sprintf(msg,"mouse x = %d , y = %d\n\nwin x = %d , y = %d" , (int) GetMousePosition().x , (int)GetMousePosition().y,(int)GetWindowPosition().x,(int) GetWindowPosition().y);
        DrawText(msg,screenWidth / 2 - 110, screenHeight/2 - 50 , 20 , BLACK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

