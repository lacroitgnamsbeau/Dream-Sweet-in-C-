#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include <vector>
#include <iostream>

const int SCREEN_WIDTH = 60;
const int SCREEN_HEIGHT = 30;
const int PLAYER_SIZE = 20;

struct Task {
    SDL_Rect rect;
    bool completed;
};

bool init(SDL_Window*& window, SDL_Renderer*& renderer) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) return false;
    if (TTF_Init() == -1) return false;

    window = SDL_CreateWindow("Task Track RPG", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) return false;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    return renderer != nullptr;
}

SDL_Texture* renderText(const std::string& message, SDL_Renderer* renderer, TTF_Font* font, SDL_Color color) {
    SDL_Surface* surface = TTF_RenderText_Solid(font, message.c_str(), color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

int main(int argc, char* argv[]) {
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    if (!init(window, renderer)) {
        std::cout << "Failed to initialize SDL!" << std::endl;
        return -1;
    }

    TTF_Font* font = TTF_OpenFont("arial.ttf", 24);
    if (!font) {
        std::cout << "Failed to load font!" << std::endl;
        return -1;
    }

    SDL_Rect player = { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, PLAYER_SIZE, PLAYER_SIZE };
    int playerSpeed = 5;
    int score = 0;

    std::vector<Task> tasks = {
        {{100, 100, PLAYER_SIZE, PLAYER_SIZE}, false},
        {{300, 200, PLAYER_SIZE, PLAYER_SIZE}, false},
        {{500, 300, PLAYER_SIZE, PLAYER_SIZE}, false}
    };

    bool quit = false;
    SDL_Event e;
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) quit = true;

            const Uint8* keystate = SDL_GetKeyboardState(nullptr);
            if (keystate[SDL_SCANCODE_UP]) player.y -= playerSpeed;
            if (keystate[SDL_SCANCODE_DOWN]) player.y += playerSpeed;
            if (keystate[SDL_SCANCODE_LEFT]) player.x -= playerSpeed;
            if (keystate[SDL_SCANCODE_RIGHT]) player.x += playerSpeed;
        }

        for (auto& task : tasks) {
            if (!task.completed && SDL_HasIntersection(&player, &task.rect)) {
                task.completed = true;
                score += 10;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        for (const auto& task : tasks) {
            if (!task.completed) {
                SDL_RenderFillRect(renderer, &task.rect);
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &player);

        SDL_Color color = {255, 255, 255, 255};
        SDL_Texture* scoreText = renderText("Score: " + std::to_string(score), renderer, font, color);
        int textW = 0, textH = 0;
        SDL_QueryTexture(scoreText, nullptr, nullptr, &textW, &textH);
        SDL_Rect scoreRect = {10, 10, textW, textH};
        SDL_RenderCopy(renderer, scoreText, nullptr, &scoreRect);
        SDL_DestroyTexture(scoreText);

        SDL_RenderPresent(renderer);
    }

    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();

    return 0;
}


