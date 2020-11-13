/*
 * DebugSubscreen.h
 *
 *  Created on: 19.05.2020
 *      Author: markov94
 */

#ifndef INTERFACE_DEBUGSUBSCREEN_H_
#define INTERFACE_DEBUGSUBSCREEN_H_

#include "EditorWindow.h"
#include "EditorSubscreen.h"


class DebugSubscreen : public EditorSubscreen{
public:
	virtual void show();
	virtual void hide();
	 void create();
	virtual void refresh();
	virtual void eventLoop();
	virtual void disable();
	virtual void enable();
	DebugSubscreen(EditorWindow* editorWindow) : EditorSubscreen(editorWindow)
{

}
	virtual ~DebugSubscreen();
private:
	GHandle ghConsoleButton;
	GHandle ghButton1;
	GHandle ghSlider;
};

#endif /* INTERFACE_DEBUGSUBSCREEN_H_ */
