#include<SDL2/SDL.h>
#include<stdio.h>
#include<stdbool.h>

#define WIDTH 1200
#define HEIGHT 800

int main(int argc, char* argv[]){
    // These lines stop the "unused parameter" warnings
    (void)argc;
    (void)argv;
    printf("Hello Plotter, here we begin\n");
    
    //Creating the window
    SDL_Window *pwindow=SDL_CreateWindow("Plot of Function",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
    WIDTH,HEIGHT,0);
    
    //Creating the surface
    SDL_Surface *psurface=SDL_GetWindowSurface(pwindow);

    //Now the actual painting
    SDL_Rect rect=(SDL_Rect) {80,80,80,80};
    uint_fast32_t color = 0xFF0000; //Red
    SDL_FillRect(psurface,&rect,color);

    //Creating an event
    SDL_Event event;
    //Making sure window remains open until I press close button
    bool running_app=true;
    while(running_app){
        while(SDL_PollEvent(&event)){ //Polls until all events are handled. SDL_pollevent returns 1 if there is a pending event or 0 if there are none available.   
            if(event.type==SDL_QUIT){
                running_app=false;
                }                        
            }
            SDL_UpdateWindowSurface(pwindow);
    }
    return 0;
}