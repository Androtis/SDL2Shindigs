#include <iostream>
#include <SDL2/SDL.h>

const int WIDTH = 800, HEIGHT = 600;

int main(int argc, char *argv[]){
    // Initilization 
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *window = SDL_CreateWindow("UwU SDL2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);

    if (NULL == window){
        std::cout << "Could not create a window: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Event windowEvent;

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
        }   
    }
    

    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}
