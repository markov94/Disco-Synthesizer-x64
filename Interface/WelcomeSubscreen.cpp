/*
 * WelcomeSubscreen.cpp
 *
 *  Created on: 23.05.2020
 *      Author: markov94
 */

#include "WelcomeSubscreen.h"
#include "romfs_file.h"
#include "gfx.h"
#include "utils.h"
#include "styles.h"
#include "UserInterface.h"

void WelcomeSubscreen::show() {
	EditorSubscreen::show();
}

void WelcomeSubscreen::hide() {
	EditorSubscreen::hide();
}

void WelcomeSubscreen::create() {
	EditorSubscreen::create();
	gwinSetText(ghSubmenubarLabel,"Welcome",FALSE);
	createImage();

	Utils::Label(&ghVersionLabel,ghSubscreenContainer,0,130,480,30,"Version 0.0.1-2310",&(Styles::DefaultWindowStyle));
	gwinSetFont(ghVersionLabel,UserInterface::getUserInterface().getFontLarge());
	gwinSetCustomDraw(ghVersionLabel,gwinLabelDrawJustifiedCenter,0);
	Utils::Label(&ghAuthorLabel,ghSubscreenContainer,0,160,480,60,"Marek Kowalczyk",&(Styles::DefaultWindowStyle));
	gwinSetFont(ghAuthorLabel,UserInterface::getUserInterface().getFontLarge());
	gwinSetCustomDraw(ghAuthorLabel,gwinLabelDrawJustifiedCenter,0);

}

void WelcomeSubscreen::refresh() {
	EditorSubscreen::refresh();
}

void WelcomeSubscreen::eventLoop() {
}

void WelcomeSubscreen::disable() {
	EditorSubscreen::disable();
}

void WelcomeSubscreen::enable() {
	EditorSubscreen::enable();
}

WelcomeSubscreen::~WelcomeSubscreen() {
	// TODO Auto-generated destructor stub
}

void WelcomeSubscreen::createImage() {
	GWidgetInit	wi;

		// Apply some default values for GWIN
		gwinWidgetClearInit(&wi);
		wi.g.show = TRUE;

		wi.g.x = 15; wi.g.y = 1; wi.g.width = 450; wi.g.height = 110;
				wi.text = "Logo";
				wi.g.parent = ghSubscreenContainer;
				ghLogo = gwinImageCreate(NULL, &wi.g);
				gwinImageOpenMemory(ghLogo, logo);
}
