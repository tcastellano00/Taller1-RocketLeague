#ifndef CLIENT_SCORE_MODEL_H
#define CLIENT_SCORE_MODEL_H



//Clase que contiene todos los datos del marcador
//cuya informacion es usada para mostrarla por pantalla
//mientras es actualizada en la fisica del juego.
class ScoreModel {
private:
    int minutesLeft;
    int secondsLeft;
    int miliSecondsLeft;
    int goalsFirstTeam;
    int goalsSecondTeam;
    
public:
    ScoreModel(int minutes, int seconds, int milisec, int goalsFirst, int goalsSecond);
    ScoreModel();
    int getMinutesLeft();
    int getSecondsLeft();
    int getMiliSecondsLeft();
    int getGoalsFirstTeam();
    int getGoalsSecondTeam();
    ~ScoreModel() = default;
};
#endif
