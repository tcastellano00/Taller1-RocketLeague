#ifndef CLIENT_GAMESTATUS_H
#define CLIENT_GAMESTATUS_H

#include <iostream>
#include <string>
#include <list>
#include "Model/PlayerModel.h"
#include "Model/ScoreModel.h"
#include "Model/BallModel.h"

/*
Esta clase representa el estado del mundo en un determinado instante,
es muy utilizada tanto por el servidor como por el cliente, ya que el
server esta continuamente enviado nuevos estados del mundo mientras el cliente
esta continuamente dibujandolos
*/
class GameStatus{
private:
    ScoreModel score;
    BallModel ball;
    bool closed;
    std::string actualStatus;
    std::list<PlayerModel> players;
    bool replay;
    bool inExplosion;
    bool carJump;
    PlayerModel player;

public:
    GameStatus();
    GameStatus(
        BallModel& ball,
        ScoreModel& score,
        std::list<PlayerModel>& players
    );

    std::string identificador;

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

    void setCarJump(bool jump);
    bool isJumping();

    bool isACarDoingTurbo();
};
#endif