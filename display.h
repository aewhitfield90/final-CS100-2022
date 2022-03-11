#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include "creature.h"

/* base class */
class Display {
public:
	virtual void showElement(Creature* creature) = 0;
};

/* subclass */
class DisplayHealth : public Display {
public:
	void showElement(Creature* creature);
};

/* subclass */
class DisplayPlayerHealth : public Display {
public:
	virtual void showElement(Player* player);
};

/* subclass */
class DisplayMonsterHealth : public Display {
public:
	virtual void showElement(Monster* monster);
};

#endif /* DISPLAY_H */
