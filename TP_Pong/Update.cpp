#include "Update.h"

//GOAL  : Update everything about the object
//INPUT : The players, the ball, the size of the window, the max speed of the ball, the style of text, the renderer, the bool for the game and the score max
//OUTPUT: New position/texture of the object
void Update(CPlayer &player1, CPlayer &player2, CBall &ball, int WWIDTH, int WHEIGHT, int MAXSPEEDBALL, TextStyle &style, CRenderer &render, bool &roundStart, int &winnerRound, bool &gameOn, int MAXSCORE, TextureManager &m_textureManager)
{
    //If start of the round, launch ball and set back all the variables and the texture of the scores
    if (roundStart) {
        startRound(MAXSPEEDBALL, WWIDTH, WHEIGHT, winnerRound, roundStart, player1, player2, ball);
        m_textureManager.loadTEXT(to_string(player1.getScore()), "score1", render.getRenderer(), style);
        m_textureManager.loadTEXT(to_string(player2.getScore()), "score2", render.getRenderer(), style);
        //player1.setTextScore(style, render.getRenderer());
        //player2.setTextScore(style, render.getRenderer());
    }
    //Move the players
    player1.move(WHEIGHT); 
    player2.move(WHEIGHT);

    //Check position of the ball    
    ball.checkPos(WHEIGHT, WWIDTH, player1, player2, MAXSPEEDBALL, render, style);

    //Check the win condition
    gameOn = checkWinCondition(MAXSCORE, WWIDTH, WHEIGHT, player1, player2, style, render);
}

//GOAL  : Start the round
//INPUT : The max speed of the ball, the size of the window, the bool of the game, the players and the ball
//OUTPUT: Lanch of the ball and reset variables
void startRound(int MAXSPEEDBALL, int WWIDTH, int WHEIGHT, int& winnerRound, bool& roundStart, CPlayer &player1, CPlayer &player2, CBall &ball) {
    srand(time(NULL));
    int n_i = 0;
    player1.setScore(0);
    player2.setScore(0);
    player1.setY((WHEIGHT / 2) - (150 / 2));
    player2.setY((WHEIGHT / 2) - (150 / 2));
    n_i = (rand() % 2) + 1;
    switch (n_i) {
    case 1:
        winnerRound = -1;
        break;
    case 2:
        winnerRound = 1;
        break;
    }
    ball.LaunchBall(MAXSPEEDBALL, WWIDTH, WHEIGHT, winnerRound);
    roundStart = false;
}

//GOAL  : Check if a player won
//INPUT : ...
//OUTPUT: If someone won or not
bool checkWinCondition(int MAXSCORE, int WWIDTH, int WHEIGHT, CPlayer &player1, CPlayer &player2, TextStyle &style, CRenderer &render) {
    if (player1.getScore() >= MAXSCORE || player2.getScore() >= MAXSCORE) {       
        return false;
    }
    return true;
}
