#include <iostream>
#include <stdio.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_audio.h>

#include <vulkan/vulkan.h>

const int WIDTH = 800, HEIGHT = 600;

int main(int argc, char *argv[]){
    // Initilization 
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *window = SDL_CreateWindow("UwU SDL2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN | SDL_WINDOW_VULKAN);

    if (NULL == window){
        std::cout << "Could not create a window: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Event windowEvent;
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    //Image Experiments
    SDL_Surface* image = SDL_LoadBMP("files/imgs/ipsumlorem.bmp");
    SDL_Surface* image2 = SDL_LoadBMP("files/imgs/tedium.bmp");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_Texture* texture2 = SDL_CreateTextureFromSurface(renderer, image2);

    

    //Audio Experiments
    SDL_AudioStream *stream = SDL_NewAudioStream(AUDIO_S16, 1, 22050, AUDIO_F32, 2, 48000);

    if (stream == NULL) {
        std::cout << "Error with generating audio stream: " << SDL_GetError() << std::endl;
    }

    
    
    // Render Loop
    while (true){       
        if (SDL_PollEvent( &windowEvent)){
            if (SDL_QUIT == windowEvent.type){
                break;
            }
            if (SDL_MOUSEBUTTONDOWN == windowEvent.type){
                SDL_RenderCopy(renderer, texture2, NULL, NULL);
                SDL_RenderPresent(renderer);   
            } else {
                SDL_RenderCopy(renderer, texture, NULL, NULL);
                SDL_RenderPresent(renderer);   
            }
        }
        

    }
    
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}
