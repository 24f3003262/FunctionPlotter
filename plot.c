#include "tinyexpr.h"
#include<SDL2/SDL.h>
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define WIDTH 1200
#define HEIGHT 800

#define X_START -10
#define X_END 10
#define X_SCALE WIDTH/(X_END-X_START)
#define Y_START -10
#define Y_END 10
#define Y_SCALE HEIGHT/(Y_END-Y_START)
#define STEP 0.01

#define THICKNESS 2

#define GridColor 0x303030

void draw_at_grid_coordinate(SDL_Surface *psurface,double x, double y,Uint32 color)
{
    double x_disp=WIDTH/2+(x*(double)X_SCALE);
    double y_disp=HEIGHT/2-(y*(double)Y_SCALE);

    SDL_Rect shifted_rect=(SDL_Rect){x_disp,y_disp,THICKNESS,THICKNESS};
    SDL_FillRect(psurface,&shifted_rect,color);
}

//Func to draw grid
void draw_grid(SDL_Surface *psurface)
{
    
    for(double x=X_START;x<=X_END;x+=STEP/100){
        draw_at_grid_coordinate(psurface,x,0,GridColor);
    }
    // x_axis.x=X_START;
    // x_axis.y=0;
    // x_axis.w=X_END;
    // x_axis.h=2;
    
    for(double y=Y_START;y<=Y_END;y+=STEP/100){
        draw_at_grid_coordinate(psurface,0,y,GridColor);
    }
    
    // y_axis.x=0;
    // y_axis.y=Y_START;
    // y_axis.w=2;
    // y_axis.h=Y_END;
    
}

void draw_expression(SDL_Surface *psurface, char *expr)
{
    double x=2;
    //Store variable name and pointer
    te_variable vars[]={{"x",&x}};
    int err;
    te_expr *pexpr=te_compile(expr,vars,1,&err);

    if(pexpr)
    {
        for(x=X_START;x<X_END;x+=STEP){
            double y = te_eval(pexpr);
            draw_at_grid_coordinate(psurface,x,y,0xFFFFFF);
        }
    }
    else
    {
        fprintf(stderr,"Error evaluating expression : %s\n",expr);
        exit(-1);
    }
}

int main(int argc, char* argv[]){
    // These lines stop the "unused parameter" warnings
    (void)argc;
    (void)argv;

    if (argc!=2){ //input length should be 2 - the program name and the expression. If not return false, 0.
        printf("Usage %s <expression>\n",argv[0]);//program name
        return 0;

    }

    char *expr=argv[1];

    printf("Hello Plotter, here we begin\n");
    
    //Creating the window
    SDL_Window *pwindow=SDL_CreateWindow("Plot of Function",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
    WIDTH,HEIGHT,0);
    
    //Creating the surface
    SDL_Surface *psurface=SDL_GetWindowSurface(pwindow);

    // //Now the actual painting
    // SDL_Rect rect=(SDL_Rect) {-20,20,40,40};
    // uint_fast32_t color = 0xFF0000; //Red

    
    //Drawing the grid
    draw_grid(psurface);
    // draw_at_grid_coordinate(psurface,&rect,color);
    //Drawing the expression
    draw_expression(psurface,expr);

    //Creating an event
    SDL_Event event;
    //Making sure window remains open until I press close button
    SDL_UpdateWindowSurface(pwindow);
    bool running_app=true;
    while(running_app){
        while(SDL_PollEvent(&event)){ //Polls until all events are handled. SDL_pollevent returns 1 if there is a pending event or 0 if there are none available.   
            if(event.type==SDL_QUIT){
                running_app=false;
                }                        
            }
            
    }
    return 0;
}