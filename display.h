#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>

/* base class */
class Display {
	virtual void showElement() = 0;
};

/* subclass */
class DisplayHealth : public Display {
	virtual void showElement(Creature*);
};

/* subclass */
class DisplayPlayerHealth : public Display {
	virtual void showElement(Player*);
};

/* subclass */
class DisplayMonsterHealth : public Display {
	virtual void showElement(Monster*);
};

#endif /* DISPLAY_H */
