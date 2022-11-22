#include <iostream>
#include <string>
#include <exception>
#include <unistd.h>
#include <list>

#include "SDL/Ball.h"
#include "SDL/Bow.h"
#include "SDL/Score.h"
#include "SDL/Player.h"
#include "SDL/Scene.h"

#include <SDL2pp/SDL2pp.hh>

#include "WindowRenderer.h"
#include "ThreadCmdReader.h"

WindowRenderer::WindowRenderer(
        Queue<Command>& commandQueue,
        GameStatusMonitor& gameStatusMonitor) 
    : commandQueue(commandQueue),
      gameStatusMonitor(gameStatusMonitor),
      threadCmdReader(commandQueue, gameStatusMonitor) {}

void WindowRenderer::launch() {
    try {
        // Inicializo biblioteca de SDL
        SDL2pp::SDL sdl(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

        // Creo una ventana dinamica con titulo "Hello world"
        SDL2pp::Window window("Rocket League", 
            SDL_WINDOWPOS_UNDEFINED, 
            SDL_WINDOWPOS_UNDEFINED,
            SCREENWIDTH, 
            SCREENHEIGHT, 
            SDL_WINDOW_RESIZABLE);

        // Creo renderer
        SDL2pp::Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED);

        renderer.SetDrawColor(255,255,255,255);

        //SDL2pp::Mixer mixer(44100, MIX_DEFAULT_FORMAT, 2, 2048)

        // Usar factory

        SDL2pp::Texture wallsAndScore(renderer, 
            SDL2pp::Surface("assets/wallsAndScore.png").SetColorKey(false, 0));

        //wallsAndScore.SetBlendMode(SDL_BLENDMODE_NONE);

        SDL2pp::Texture backgroud(renderer, 
            SDL2pp::Surface("assets/background.png").SetColorKey(true, 0));
            
        SDL2pp::Texture im(renderer, 
            SDL2pp::Surface("assets/autoderecha.png").SetColorKey(false, 0));

        SDL2pp::Texture ballTexture(renderer, 
            SDL2pp::Surface("assets/ball.png").SetColorKey(true, 0));

        SDL2pp::Texture bowTexture(renderer, 
            SDL2pp::Surface("assets/bow.png").SetColorKey(true, 0));   //bow = arco

        
        SDL2pp::Texture zeroTexture(renderer, 
            SDL2pp::Surface("assets/Numbers/zero.png").SetColorKey(true, 0));
        SDL2pp::Texture oneTexture(renderer, 
            SDL2pp::Surface("assets/Numbers/one.png").SetColorKey(true, 0));
        SDL2pp::Texture twoTexture(renderer, 
            SDL2pp::Surface("assets/Numbers/two.png").SetColorKey(true, 0));
        SDL2pp::Texture threeTexture(renderer, 
            SDL2pp::Surface("assets/Numbers/three.png").SetColorKey(true, 0));
        SDL2pp::Texture fourTexture(renderer, 
            SDL2pp::Surface("assets/Numbers/four.png").SetColorKey(true, 0));
        SDL2pp::Texture fiveTexture(renderer, 
            SDL2pp::Surface("assets/Numbers/five.png").SetColorKey(true, 0));
        SDL2pp::Texture sixTexture(renderer, 
            SDL2pp::Surface("assets/Numbers/six.png").SetColorKey(true, 0));
        SDL2pp::Texture sevenTexture(renderer, 
            SDL2pp::Surface("assets/Numbers/seven.png").SetColorKey(true, 0));
        SDL2pp::Texture eightTexture(renderer, 
            SDL2pp::Surface("assets/Numbers/eight.png").SetColorKey(true, 0));
        SDL2pp::Texture nineTexture(renderer, 
            SDL2pp::Surface("assets/Numbers/nine.png").SetColorKey(true, 0));
        SDL2pp::Texture colon(renderer, 
            SDL2pp::Surface("assets/Numbers/colon.png").SetColorKey(true, 0));
        
        /*SDL2pp::Texture turbo(renderer, 
            SDL2pp::Surface("assets/turbo.png").SetColorKey(false, 0));*/

        SDL2pp::Texture turbo(renderer, 
            SDL2pp::Surface("assets/turbo_car.png").SetColorKey(true, 0));


        //Iniciamos el command reader.
        threadCmdReader.start();

        
        Score score(
            zeroTexture,
            oneTexture,
            twoTexture,
            threeTexture,
            fourTexture,
            fiveTexture,
            sixTexture,
            sevenTexture,
            eightTexture,
            nineTexture,
            colon
        );

        Scene scene(backgroud,wallsAndScore);

        Bow bow1(bowTexture,0,false);
        Bow bow2(bowTexture,700,true);

        Ball ball(ballTexture);

        //Instanciamos a priori cuatro jugadores.
        std::list<Player> players;
        for (int i = 0; i < 4; i++) {
            players.emplace_back(im, turbo);
        }
        
        std::string lastState("");
        //bool running = true;
        
        while (not gameStatusMonitor.gameIsClosed()) {

            renderer.Clear();
            scene.render(renderer);

            GameStatus gameStatusSnapshot = gameStatusMonitor.getGameStatus();

            //Render gameStatus snapshot.
            ball.update(gameStatusSnapshot.getBallModel(), FRAME_RATE);
            ball.render(renderer);

            score.update(gameStatusSnapshot.getScoreModel(), FRAME_RATE);
            score.render(renderer);

            auto playerIter = players.begin();
            std::list<PlayerModel> playerModels = gameStatusSnapshot.getPlayersModels();
            for (auto playerModel = playerModels.begin(); playerModel != playerModels.end(); ++playerModel) {
                playerIter->update(*playerModel, FRAME_RATE);
                playerIter->render(renderer);
                ++playerIter;
            }
            renderer.Present();

            // la cantidad de segundos que debo dormir se debe ajustar en función
            // de la cantidad de tiempo que demoró el handleEvents y el render
            usleep(FRAME_RATE);
        }

        
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void renderPlayers(GameStatusMonitor& gameStatusMonitor) {

}