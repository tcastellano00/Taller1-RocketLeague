#include <sstream>
#include <list>

#include "Model/PlayerModel.h"
#include "Model/ScoreModel.h"
#include "Model/BallModel.h"
#include "GameStatusSerializer.h"

GameStatusSerializer::GameStatusSerializer() { }

std::string GameStatusSerializer::serialize(GameStatus gameStatus) {
    //std::stringstream ss;

    BallModel ballModel = gameStatus.getBallModel();
    ScoreModel scoreModel = gameStatus.getScoreModel();
    std::list<PlayerModel> playersModels = gameStatus.getPlayersModels();

    /*
    ss << playersModels.size();

    ss >> scoreModel.get
    ss >> sec; 
    ss >> milisec;
    ss >> goalsFirst;
    ss >> goalsSecond;
    */

    return "";
}

GameStatus GameStatusSerializer::deserialize(std::string gameStatusString) {
    std::stringstream ss(gameStatusString);
    std::list<PlayerModel> playersModels;

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
    ss >> xCoordBall;
    ss >> yCoordBall;
    ss >> angleBoard;
    BallModel ballModel(xCoordBall, yCoordBall, angleBoard);

    for (int i = 0; i < numPlayers; ++i) {
        float xCoordPlayer;
        float yCoordPlayer;
        float anglePlayer;
        bool turbo;
        ss >> xCoordPlayer;
        ss >> yCoordPlayer;
        ss >> anglePlayer;
        ss >> turbo;
        playersModels.emplace_back(xCoordPlayer, yCoordPlayer, anglePlayer, turbo);
    }

    return GameStatus(
        ballModel,
        scoreModel,
        playersModels
    );
}
