#include <SDL2/SDL.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    // Inicializa SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("No se pudo inicializar SDL: %s\n", SDL_GetError());
        return 1;
    }

    // Crea una ventana
    SDL_Window* window = SDL_CreateWindow("Ventana SDL",
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          640, 480,
                                          SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("No se pudo crear la ventana: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Crea una superficie
    SDL_Surface* screenSurface = SDL_GetWindowSurface(window);

    // Rellena la superficie con un color
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0x00, 0x00));

    // Actualiza la ventana
    SDL_UpdateWindowSurface(window);

    // Espera 5 segundos
    SDL_Delay(5000);

    // Destruye la ventana
    SDL_DestroyWindow(window);

    // Cierra SDL
    SDL_Quit();

    return 0;
}

