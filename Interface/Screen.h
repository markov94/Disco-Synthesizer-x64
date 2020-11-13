/*
 * Screen.h
 *
 *  Created on: 02.05.2020
 *      Author: markov94
 */

#ifndef INTERFACE_SCREEN_H_
#define INTERFACE_SCREEN_H_



class Screen {
public:
	Screen();
	virtual ~Screen();
	virtual void show();
	virtual void hide();
	 void create();
	virtual void refresh();
	virtual void eventLoop();
	virtual void disable();
	virtual void enable();

};

#endif /* INTERFACE_SCREEN_H_ */
