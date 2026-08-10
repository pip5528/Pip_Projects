#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdint.h>

#define WIDTH 1280
#define HEIGHT 720

uint32_t framebuffer[WIDTH * HEIGHT];

int main(void) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;

    window = SDL_CreateWindow("SDL", WIDTH, HEIGHT, 0);
    renderer = SDL_CreateRenderer(window, NULL);
    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_XRGB8888, SDL_TEXTUREACCESS_STREAMING, WIDTH, HEIGHT);

    while(1) {
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    }
    

    SDL_Quit();
    return 0;
}

