#include <iostream>
#include <string>
#include <exception>
#include <unistd.h>
#include "SDL/Ball.h"
#include "SDL/Bow.h"

#include <SDL2pp/SDL2pp.hh>

#include "SDL/Player.h"
#include "WindowRenderer.h"

WindowRenderer::WindowRenderer() {}

void WindowRenderer::launch(GameStatusMonitor& gameStatusMonitor) {
    try {
        // Inicializo biblioteca de SDL
        SDL2pp::SDL sdl(SDL_INIT_VIDEO);

        // Creo una ventana dinamica con titulo "Hello world"
        SDL2pp::Window window("Hello world", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            800, 600, SDL_WINDOW_RESIZABLE);

        // Creo renderer
        SDL2pp::Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED);

        renderer.SetDrawColor(255,255,255,255);

        // Usar factory
        SDL2pp::Texture im(renderer, 
            SDL2pp::Surface("assets/autoderecha.png").SetColorKey(true, 0));

        SDL2pp::Texture ballTexture(renderer, 
            SDL2pp::Surface("assets/ball.png").SetColorKey(true, 0));

        SDL2pp::Texture bowTexture(renderer, 
            SDL2pp::Surface("assets/bow.png").SetColorKey(true, 0));   //bow = arco

        //im.SetBlendMode(SDL_BLENDMODE_NONE); //ver lo del fondo de la imagena

        Bow bow1(bowTexture,0,false);
        Bow bow2(bowTexture,700,true);

        Ball ball(ballTexture);
        Player player1(im);
        //Player player2(im);

        // {
        //     1: PlayerA
        //     2: PlayerB
        // }
        
        // for (playerModel in gameStatusMonitor.getlist())[
        //     player = map.get(playerModel.getId())
        //     player.update(playerModel, FRAME_RATE);
        //     player.render(renderer);
        // ]
        
        std::string lastState("");
        //bool running = true;
        
        while (!gameStatusMonitor.gameIsClosed()) {

            renderer.Clear();

            bow1.render(renderer);
            bow2.render(renderer);

            ball.render(renderer);
            //ball.update

            player1.update(gameStatusMonitor.getPlayer(), FRAME_RATE);
            player1.render(renderer);

            // player.update(gameStatusMonitor.getPlayerCoordX() + 15, FRAME_RATE);
            // player.render(renderer);


            // player1.update(gameStatusMonitor.getPlayerCoordX(), FRAME_RATE);
            // player2.render(renderer);

            renderer.Present();

            // la cantidad de segundos que debo dormir se debe ajustar en función
            // de la cantidad de tiempo que demoró el handleEvents y el render
            usleep(FRAME_RATE);

            /*
            std::string actualStatus = gameStatusMonitor.gameStatus();
            if (actualStatus == lastState)
                continue;

            lastState = actualStatus;
            std::cout<< actualStatus << std::endl;
            renderer.Clear();
            renderer.Present();

            SDL_Delay(1000);
            */
        }

        /*
        while (!gameStatusMonitor.gameIsClosed()) {
            std::string actualStatus = gameStatusMonitor.gameStatus();
            
            //running = handleEvents(player);
            update(player, FRAME_RATE);
            render(renderer, player);

            if (actualStatus == lastState)
                continue;
                
            lastState = actualStatus;

            std::cout << actualStatus << std::endl;

            // la cantidad de segundos que debo dormir se debe ajustar en función
            // de la cantidad de tiempo que demoró el handleEvents y el render
            usleep(FRAME_RATE);
        }
        */
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    
}

void renderPlayers(GameStatusMonitor& gameStatusMonitor) {

}

/*
static void render(SDL2pp::Renderer &renderer, Player &player) {
    renderer.Clear();
    player.render(renderer);
    renderer.Present();
}

static void update(Player &player, float dt) {
    player.update(dt);
}
*/