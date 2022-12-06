#include <iostream>
#include <string>
#include <exception>
#include <unistd.h>
#include <list>
#include "CappedList.h"

#include "SDL/Ball.h"
#include "SDL/Score.h"
#include "SDL/Player.h"
#include "SDL/Scene.h"
#include "SDL/ReplayFrame.h"


#include <SDL2pp/SDL2pp.hh>

#include "WindowRenderer.h"
#include "ThreadCmdReader.h"
#include "../Common/Config/ClientConfig.h"
#include "../Common/Config/CommonConfig.h"

#include <chrono>
#include <unistd.h>
#define DELTA CommonConfig::getFrameTimeInMicroseconds()
typedef std::chrono::high_resolution_clock Clock;

WindowRenderer::WindowRenderer(
        BlockingQueue<Command>& commandQueue,
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
            ClientConfig::getScreenWidth(), 
            ClientConfig::getScreenHeight(), 
            SDL_WINDOW_RESIZABLE);

        // Creo renderer
        SDL2pp::Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED);

        renderer.SetDrawColor(255,255,255,255);

        SDL2pp::Mixer mixer(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 4096);

        //SDL2pp::Chunk backGroundsound("music/background.ogg");
        ///std::cout << "pase esto" << std::endl;

        BackGroundMusic backGroundMusic(mixer);

        // Usar factory

        SDL2pp::Texture wallsAndScore(renderer, 
            SDL2pp::Surface("assets/back2.png").SetColorKey(false, 0));
        SDL2pp::Texture backgroud(renderer, 
            SDL2pp::Surface("assets/background.png").SetColorKey(true, 0));
        SDL2pp::Texture im(renderer, 
            SDL2pp::Surface("assets/autoderecha.png").SetColorKey(false, 0));
        SDL2pp::Texture ballTexture(renderer, 
            SDL2pp::Surface("assets/ball.png").SetColorKey(true, 0));
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
        SDL2pp::Texture turbo(renderer, 
            SDL2pp::Surface("assets/turbo_car.png").SetColorKey(true, 0));
        SDL2pp::Texture turboBarEmpty(renderer, 
            SDL2pp::Surface("assets/turboBarEmpty.png").SetColorKey(true, 0));
        SDL2pp::Texture turboBarFull(renderer, 
            SDL2pp::Surface("assets/turboBarFull.png").SetColorKey(true, 0));
        SDL2pp::Texture replayTexture(renderer, 
            SDL2pp::Surface("assets/replay.png").SetColorKey(true, 0));
        SDL2pp::Texture explosionTexture(renderer, 
            SDL2pp::Surface("assets/explosion.png").SetColorKey(true, 0));
        SDL2pp::Texture turnLeft(renderer, 
            SDL2pp::Surface("assets/turnLeft.png").SetColorKey(true, 0));
        SDL2pp::Texture turnRight(renderer, 
            SDL2pp::Surface("assets/turnRight.png").SetColorKey(true, 0));


        //Iniciamos el command reader.
        threadCmdReader.start();

        //Creamos la lista de gamestatus para la repeticion
        CappedList<GameStatus> replayList(125); // 5 segundos

        
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

        Ball ball(ballTexture,explosionTexture);

        ReplayFrame replayFrame(replayTexture);

        //Instanciamos a priori cuatro jugadores.
        std::list<Player> players;
        for (int i = 0; i < 4; i++) {
            players.emplace_back(im, turbo, turboBarEmpty, turboBarFull,turnLeft,turnRight);
        }
        
        std::string lastState("");
        //bool running = true;

        bool isInReplay = false;
        
        while (not gameStatusMonitor.gameIsClosed()) {

            auto timeStart = Clock::now();


            //Pauso la musica de fondo.
            if(gameStatusMonitor.getIsPlayingMusic() != backGroundMusic.getIsPlayingMusic()){
                std::cout << gameStatusMonitor.getIsPlayingMusic() << std::endl; 
                backGroundMusic.togglePause();
            }

            //Cambio el tema actual
            if(gameStatusMonitor.getCallNext()){
                backGroundMusic.changeMusic();
                gameStatusMonitor.toggleNext();
            }

            renderer.Clear();
            scene.render(renderer);

            GameStatus gameStatusSnapshot = gameStatusMonitor.getGameStatus();


            //Musica salto
            if(gameStatusSnapshot.isJumping()){
                backGroundMusic.jumpSound();
            }

            //Musica turbo
            if(gameStatusSnapshot.isACarDoingTurbo()){
                if (!backGroundMusic.getIsPlayingTurbo()) {
                    backGroundMusic.turboSound();
                }
            } else if (!gameStatusSnapshot.isACarDoingTurbo() && backGroundMusic.getIsPlayingTurbo()) {
                backGroundMusic.stopTurboSound();
            }

            if (gameStatusSnapshot.isInReplay()) {
                gameStatusSnapshot = replayList.pop_front();
                isInReplay = true;
            } else {
                replayList.push_back(gameStatusSnapshot);
            }

            //Render gameStatus snapshot.
            ball.update(
                gameStatusSnapshot.getBallModel(), 
                CommonConfig::getFrameTimeInMicroseconds(), 
                gameStatusSnapshot.isInExplosion());
            ball.render(renderer,gameStatusSnapshot.isInExplosion());
            backGroundMusic.explosionMusic(gameStatusSnapshot.isInExplosion());

            auto playerIter = players.begin();
            int i = 0;
            std::list<PlayerModel> playerModels = gameStatusSnapshot.getPlayersModels();
            for (auto playerModel = playerModels.begin(); playerModel != playerModels.end(); ++playerModel) {
                playerIter->update(*playerModel, CommonConfig::getFrameTimeInMicroseconds());
                playerIter->render(renderer, i);
                ++playerIter;
                ++i;
                std::cout <<  playerModel->getName() << "goals: " << playerModel->getGoals() << "assists: " << playerModel->getAssists() << std::endl;
            }

            if (isInReplay) {
                replayFrame.render(renderer);
            } else {
                score.update(gameStatusSnapshot.getScoreModel(), CommonConfig::getFrameTimeInMicroseconds());
                score.render(renderer);
            }

            renderer.Present();

            // la cantidad de segundos que debo dormir se debe ajustar en función
            // de la cantidad de tiempo que demoró el handleEvents y el render

            isInReplay = false;

            auto timeFinish = Clock::now();
            int elapsed = std::chrono::duration_cast<std::chrono::microseconds>(timeFinish - timeStart).count();
            if (DELTA - elapsed > 0) {
                usleep(DELTA - elapsed);
            }
            //usleep(CommonConfig::getFrameTimeInMicroseconds());
        }

        
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void renderPlayers(GameStatusMonitor& gameStatusMonitor) {

}