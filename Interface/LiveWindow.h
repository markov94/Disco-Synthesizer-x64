/*
 * LiveWindow.h
 *
 *  Created on: 13.05.2020
 *      Author: markov94
 */

#ifndef INTERFACE_LIVEWINDOW_H_
#define INTERFACE_LIVEWINDOW_H_

#include "Screen.h"

class LiveWindow: public Screen {
public:
	LiveWindow();
	virtual ~LiveWindow();
	void show();
	void hide();
	void create();
	void remove();
	void refresh();
	void eventLoop();
};

#endif /* INTERFACE_LIVEWINDOW_H_ */
