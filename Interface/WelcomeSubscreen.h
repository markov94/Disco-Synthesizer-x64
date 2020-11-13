/*
 * WelcomeSubscreen.h
 *
 *  Created on: 23.05.2020
 *      Author: markov94
 */

#ifndef INTERFACE_WELCOMESUBSCREEN_H_
#define INTERFACE_WELCOMESUBSCREEN_H_

#include "EditorSubscreen.h"

class WelcomeSubscreen: public EditorSubscreen {
public:
	virtual void show();
	virtual void hide();
	void create();
	virtual void refresh();
	virtual void eventLoop();
	virtual void disable();
	virtual void enable();
	WelcomeSubscreen(EditorWindow* editorWindow) : EditorSubscreen(editorWindow)
	{
		ghLogo = NULL;
	}
	virtual ~WelcomeSubscreen();
private:
	void createImage();
	GHandle ghLogo;
	GHandle ghVersionLabel;
	GHandle ghAuthorLabel;

};

#endif /* INTERFACE_WELCOMESUBSCREEN_H_ */
