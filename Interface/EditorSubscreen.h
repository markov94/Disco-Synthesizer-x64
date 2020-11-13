/*
 * EditorSubscreen.h
 *
 *  Created on: 15.05.2020
 *      Author: markov94
 */

#ifndef INTERFACE_EDITORSUBSCREEN_H_
#define INTERFACE_EDITORSUBSCREEN_H_


#include "Screen.h"
#include "EditorWindow.h"
#include "gfx.h"



class EditorSubscreen: public Screen {
public:

	virtual void show();
	virtual void hide();
	 void create();
	virtual void refresh();
	virtual void eventLoop();
	virtual void disable();
	virtual void enable();


	EditorSubscreen(EditorWindow* editorWindow)
{
		this->editorWindow = editorWindow;
}
	virtual ~EditorSubscreen();
protected:
	EditorWindow* editorWindow;
	GHandle ghSubscreenContainer;
	GHandle ghSubmenubarContainer;
	GHandle ghSubmenubarLabel;

	static const uint16_t buttonSlotW = 48;
	static const uint16_t buttonSlotH = 32;
	static const uint16_t buttonSlotY = 1;
	static const uint16_t buttonSlot1X = 151;
	static const uint16_t buttonSlot2X = 209;
	static const uint16_t buttonSlot3X = 267;
	static const uint16_t buttonSlot4X = 325;
	static const uint16_t buttonSlot5X = 383;

};

#endif /* INTERFACE_EDITORSUBSCREEN_H_ */
