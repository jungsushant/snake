#include "snake.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>

#if 0
#define WINDOW_X 0
#define WINDOW_Y -20
#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 500

#else

#define WINDOW_X 0
#define WINDOW_Y 0
#define WINDOW_WIDTH 1366
#define WINDOW_HEIGHT 768

#endif
#define GRID_SIZE 20
#define GRID_DIM 600

void render_grid(SDL_Renderer *renderer, int x, int y){
        SDL_SetRenderDrawColor(renderer, 0X55, 0X55, 0x55, 255);        
        int cell_size = GRID_DIM / GRID_SIZE;
        SDL_Rect cell;
        cell.w = cell_size;
        cell.h = cell_size;

        for (int i = 0; i< GRID_SIZE;i++){
            for(int j = 0; j < GRID_SIZE;j++){
                cell.x = x + (i * cell_size);
                cell.y = y + (j * cell_size);
                SDL_RenderDrawRect(renderer, &cell);
            }
        }

}

int main() {
// INITIALIZING SDL WINDOW AND RENDERER 
SDL_Window *window;
SDL_Renderer *renderer;

if (SDL_INIT_VIDEO <0) {
    fprintf(stderr, "Error: SDL_INIT_VIDEO");

}

window = SDL_CreateWindow("Snake", WINDOW_X, WINDOW_Y, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_BORDERLESS);

if(!window){
    
fprintf(stderr, "Error: Window Error !");
}

renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

if(!renderer){
    fprintf(stderr, "Error: Renderer Error !");
}

    int grid_x = (WINDOW_WIDTH / 2) - (GRID_DIM /2);
    int grid_y = (WINDOW_HEIGHT / 2) - (GRID_DIM /2); 


//SDL WINDOW AND RENDERER PERSISTANCE
bool quit = false; // to persit the program
SDL_Event event; // to detect key presses

while(!quit){
    while(SDL_PollEvent(&event)){
        switch(event.type){
            case SDL_QUIT: // Encounter when ctrl + q is pressed
                quit = true;
                break;
            case SDL_KEYUP: // Nothing happens at keyup
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym){
                    case SDLK_ESCAPE:
                    quit= true;
                    break;
                    
                }
        }
    }
    SDL_RenderClear(renderer); //Clears the renderer
    //Render Loop Starts
    render_grid(renderer, grid_x,grid_y);

    //Render Loop Ends
    SDL_SetRenderDrawColor(renderer, 0x11, 0x11, 0x11, 255); // Fills the rendere with green color (r,g,b,a)
    SDL_RenderPresent(renderer); // Presents the renderer
}


// DESTROYING THE SDL WINDOW AND THE RENDERER
SDL_DestroyRenderer(renderer);
SDL_DestroyWindow(window);
SDL_Quit();




    return 0;
}