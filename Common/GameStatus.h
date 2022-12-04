#ifndef CLIENT_GAMESTATUS_H
#define CLIENT_GAMESTATUS_H

#include <iostream>
#include <string>
#include <list>
#include "Model/PlayerModel.h"
#include "Model/ScoreModel.h"
#include "Model/BallModel.h"


class GameStatus{
    ScoreModel score;
    BallModel ball;
    bool closed;
    std::string actualStatus;
    std::list<PlayerModel> players;
    bool replay;
    bool inExplosion;



    PlayerModel player;

    public:

    std::string identificador;

    
    GameStatus();
    GameStatus(
        BallModel& ball,
        ScoreModel& score,
        std::list<PlayerModel>& players
    );

    BallModel getBallModel();
    void setBallModel(BallModel ballModel);

    ScoreModel getScoreModel();
    void setScoreModel(ScoreModel scoreModel);

    std::list<PlayerModel> getPlayersModels();
    void setPlayersModels(std::list<PlayerModel> lstPlayersModels);

    bool isClosed();

    std::string status();

    void setClose();

    bool isInReplay();

    void setReplay(bool rep);

    bool isInExplosion();
    void setInExplosion(bool expl);
};
#endif