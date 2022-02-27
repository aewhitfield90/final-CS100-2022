#pragma once
#include "creature.h"

class GameSystem() {
private:
	// Global Variable for Player
	Creature* Player;
public:
	Creature* getPlayer()	{ return Player; }
	Void setPlayer(Creature* inPlayer) { this->Player = inPlayer; }
}