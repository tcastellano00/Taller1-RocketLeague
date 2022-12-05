#include <sstream>
#include <list>

#include "Model/PlayerModel.h"
#include "Model/ScoreModel.h"
#include "Model/BallModel.h"
#include "GameStatusSerializer.h"
#include <iostream>

GameStatusSerializer::GameStatusSerializer() { }

std::string GameStatusSerializer::serialize(GameStatus gameStatus) {
    std::stringstream ss;

    BallModel ballModel = gameStatus.getBallModel();
    ScoreModel scoreModel = gameStatus.getScoreModel();
    std::list<PlayerModel> playersModels = gameStatus.getPlayersModels();


    if(gameStatus.isJumping()){ss << "jump" << " ";}else{
        ss << "nojump" << " ";
    }

    if (gameStatus.isInReplay()) {
        ss << "replay" << " ";
    } else {
        ss << "noReplay" << " ";
    }

    if (gameStatus.isInExplosion()) {
        ss << "inExplosion" << " ";
    } else {
        ss << "notInExplosion" << " ";
    }

    ss << playersModels.size() << " ";

    ss << scoreModel.getMinutesLeft() << " ";
    ss << scoreModel.getSecondsLeft() << " ";
    ss << scoreModel.getMiliSecondsLeft() << " ";
    ss << scoreModel.getGoalsFirstTeam() << " ";
    ss << scoreModel.getGoalsSecondTeam() << " ";

    ss << ballModel.getCoordX() << " ";
    ss << ballModel.getCoordY() << " ";
    ss << ballModel.getAngle() << " ";
    ss << ballModel.getColour() << " ";

    for (auto playerModel = playersModels.begin(); 
              playerModel != playersModels.end(); 
              ++playerModel) {
                ss << (*playerModel).getClientId() << " ";
                ss << (*playerModel).getTurboRemaining() << " ";
                ss << (*playerModel).getCoordX() << " ";
                ss << (*playerModel).getCoordY() << " ";
                ss << (*playerModel).getAngle() << " ";
                if ((*playerModel).isDoingTurbo()) {
                    ss << "turbo" << " ";
                } else {
                    ss << "noturbo" << " ";
                }
                ss << playerModel->getFacing() << " ";
    }

    //std::cout << ss.str() << std::endl;

    return ss.str();
}

GameStatus GameStatusSerializer::deserialize(std::string gameStatusString) {
    std::stringstream ss(gameStatusString);
    std::list<PlayerModel> playersModels;

    bool carJump;
    std::string carJumpStr;
    ss>>carJumpStr;

    if (carJumpStr == "jump"){carJump = true;}else{
        carJump = false;
    }

    bool isInReplay;
    std::string replayStr;
    ss >> replayStr;

    if (replayStr == "replay") {
        isInReplay = true;
    } else { // replayStr == "noReplay"
        isInReplay = false;
    }

    bool isInExplosion;
    std::string explosionStr;
    ss >> explosionStr;

    if (explosionStr == "inExplosion") {
        isInExplosion = true;
    } else { // explosionStr == "notInExplosion"
        isInExplosion = false;
    }


    int numPlayers;
    ss >> numPlayers;

    int min;
    int sec;
    int milisec;
    int goalsFirst;
    int goalsSecond;
    ss >> min;
    ss >> sec; 
    ss >> milisec;
    ss >> goalsFirst;
    ss >> goalsSecond;
    ScoreModel scoreModel(min, sec, milisec, goalsFirst, goalsSecond);

    float xCoordBall;
    float yCoordBall;
    float angleBoard;
    std::string colour;
    ss >> xCoordBall;
    ss >> yCoordBall;
    ss >> angleBoard;
    ss >> colour;
    BallModel ballModel(xCoordBall, yCoordBall, angleBoard, colour);
    
    for (int i = 0; i < numPlayers; ++i) {
        int clientId;
        int turboRem;
        float xCoordPlayer;
        float yCoordPlayer;
        float anglePlayer;
        bool turbo;
        std::string turboStr;
        std::string facing;

        ss >> clientId;
        ss >> turboRem;
        ss >> xCoordPlayer;
        ss >> yCoordPlayer;
        ss >> anglePlayer;
        ss >> turboStr;
        ss >> facing;

        if (turboStr == "turbo") {
            turbo = true;
        } else {// turbo = "noturbo"
            turbo = false;
        }

        playersModels.emplace_back(clientId,xCoordPlayer, yCoordPlayer, anglePlayer, turbo, facing, turboRem);
    }

    GameStatus gm(ballModel, scoreModel, playersModels);
    gm.setReplay(isInReplay);
    gm.setInExplosion(isInExplosion);
    gm.setCarJump(carJump);

    return gm;
}
