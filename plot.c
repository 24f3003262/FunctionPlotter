#include<SDL2/SDL.h>
#include<stdio.h>
#include<stdbool.h>

#define WIDTH 1200
#define HEIGHT 800

void draw_at_grid_coordinate(SDL_Surface *psurface,SDL_Rect *prect,Uint32 color)
{
    int x_grid=WIDTH/2+prect->x;
    int y_grid=HEIGHT/2-prect->y;

    SDL_Rect shifted_rect=(SDL_Rect){x_grid,y_grid,prect->w,prect->h};
    SDL_FillRect(psurface,&shifted_rect,color);
}

//Func to draw grid
void draw_grid(SDL_Surface *psurface)
{
    SDL_Rect x_axis;
    x_axis.x=-WIDTH/2;
    x_axis.y=0;
    x_axis.w=WIDTH;
    x_axis.h=2;
    draw_at_grid_coordinate(psurface,&x_axis,0xFFFFFF);

    SDL_Rect y_axis;
    y_axis.x=0;
    y_axis.y=HEIGHT/2;
    y_axis.w=2;
    y_axis.h=HEIGHT;
    draw_at_grid_coordinate(psurface,&y_axis,0xFFFFFF);
}



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
    SDL_Rect rect=(SDL_Rect) {-20,20,40,40};
    uint_fast32_t color = 0xFF0000; //Red

    
    //Drawing the grid
    draw_grid(psurface);
    draw_at_grid_coordinate(psurface,&rect,color);

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