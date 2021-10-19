#pragma once
#include "CPlayer.h"
#include "CBall.h"
#include "CRenderer.h"
#include <time.h> 
#include <iostream>

void Update(CPlayer &player1, CPlayer &player2, CBall &ball, int WWIDTH, int WHEIGHT, int MAXSPEEDBALL, TextStyle &style, CRenderer &render, bool &roundStart, int &winnerRound, bool &gameOn, int MAXSCORE);

void startRound(int MAXSPEEDBALL, int WWIDTH, int WHEIGHT, int& winnerRound, bool& roundStart, CPlayer &player1, CPlayer &player2, CBall &ball);

bool checkWinCondition(int MAXSCORE, int WWIDTH, int WHEIGHT, CPlayer &player1, CPlayer &player2, TextStyle& style, CRenderer& render);