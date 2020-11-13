/*
 * EditorSubscreen.cpp
 *
 *  Created on: 15.05.2020
 *      Author: markov94
 */

#include "EditorSubscreen.h"
#include "styles.h"
#include "texts.h"
#include "utils.h"
#include "UserInterface.h"

void EditorSubscreen::show() {
	enable();
	gwinShow(ghSubscreenContainer);
	gwinShow(ghSubmenubarContainer);




}

void EditorSubscreen::hide() {
	disable();
	gwinHide(ghSubscreenContainer);
gwinHide(ghSubmenubarContainer);

}

void EditorSubscreen::create() {


	Utils::Container(&ghSubscreenContainer,editorWindow->getGhEditorWindowContainer(),0,34,480,238,"",&(Styles::DefaultWindowStyle),FALSE);
	Utils::Container(&ghSubmenubarContainer,editorWindow->getGhMenubarContainer(),49,0,431,34,"",&(Styles::MenuStyle),FALSE);

	Utils::Label(&ghSubmenubarLabel,ghSubmenubarContainer,10,1,139,32,"Error:BaseClass",&(Styles::MenuStyle));
	gwinSetFont(ghSubmenubarLabel,UserInterface::getUserInterface().getFontMedium());

}



void EditorSubscreen::refresh() {
}

void EditorSubscreen::eventLoop() {
}

/**
 * Disabling a subscreen class disables the submenu and disables and hides the subscreen itself
 */
void EditorSubscreen::disable() {
	gwinDisable(ghSubscreenContainer);
	gwinDisable(ghSubmenubarContainer);
	gwinHide(ghSubscreenContainer);
}

void EditorSubscreen::enable() {
	gwinEnable(ghSubscreenContainer);
		gwinEnable(ghSubmenubarContainer);
		gwinShow(ghSubscreenContainer);
}

EditorSubscreen::~EditorSubscreen() {
	// TODO Auto-generated destructor stub
}

