/*
 * DebugSubscreen.cpp
 *
 *  Created on: 19.05.2020
 *      Author: markov94
 */

#include "DebugSubscreen.h"
#include "gfx.h"
#include "utils.h"
#include "styles.h"
#include "UserInterface.h"

void DebugSubscreen::show() {
	EditorSubscreen::show();
}

void DebugSubscreen::hide() {
	EditorSubscreen::hide();
}

void DebugSubscreen::create() {
	EditorSubscreen::create();
	gwinSetText(ghSubmenubarLabel,"Debug Menu",FALSE);
	Utils::PushButton(&ghConsoleButton,ghSubscreenContainer,10,10,100,40,"Console");
	Utils::PushButton(&ghButton1,ghSubscreenContainer,10,60,100,40,"Test1");
	Utils::Slider(&ghSlider,ghSubscreenContainer,200,100,100,80,"Progress");
	gwinSetStyle(ghSlider,&(Styles::LiveWidgetStyle));
	gwinSetFont(ghSlider,UserInterface::getUserInterface().getFontLarge());
}

void DebugSubscreen::refresh() {
	EditorSubscreen::refresh();
}

void DebugSubscreen::eventLoop() {
}

void DebugSubscreen::disable() {
	EditorSubscreen::disable();
}

void DebugSubscreen::enable() {
	EditorSubscreen::enable();
}

DebugSubscreen::~DebugSubscreen() {
	// TODO Auto-generated destructor stub
}

