/*
 * EditorWindow.cpp
 *
 *  Created on: 13.05.2020
 *      Author: markov94
 */

#include "EditorWindow.h"
#include "utils.h"
#include "styles.h"
#include "UserInterface.h"
#include "texts.h"
#include "EditorSubscreen.h"
#include "DebugSubscreen.h"
#include "WelcomeSubscreen.h"
#include "romfs_file.h"
#include "custom.h"

EditorWindow::EditorWindow() {
	activeSubscreen = NULL;
	debugSubscreen = new DebugSubscreen(this);
	welcomeSubscreen = new WelcomeSubscreen(this);


}

EditorWindow::~EditorWindow() {
	// TODO Auto-generated destructor stub
}

void EditorWindow::show() {
	gwinShow(ghEditorWindowContainer);
	gwinShow(ghMenubarContainer);

}

void EditorWindow::hide() {
}

void EditorWindow::create() {


	loadImages();
	createEditorWindow();
	createMenubar();
	createMenu();


	debugSubscreen->create();
	debugSubscreen->hide();


	welcomeSubscreen->create();
	setActiveSubscreen(welcomeSubscreen);
	showActiveSubscreen();
	disableActiveSubscreen();
	gwinShow(ghMenuContainer);
}



void EditorWindow::refresh() {
}

void EditorWindow::eventLoop() {
	GEvent* pe;


	while(1) {
		// Get an Event
		pe = geventEventWait(UserInterface::getUserInterface().getListenerP(), TIME_INFINITE);

		switch(pe->type) {
		case GEVENT_GWIN_BUTTON:
			if (((GEventGWinButton*)pe)->gwin == ghButtonMenu) {
				buttonMenuCallback();
			}


			if (((GEventGWinButton*)pe)->gwin == ghButtonDebug) {
				buttonDebugCallback();
			}
			break;

		default:
			break;
		}
	}

}

void EditorWindow::createMenubar() {
	Utils::Container(&ghMenubarContainer,ghEditorWindowContainer,0,0,480,34,"EditMenubar",&(Styles::MenuStyle),FALSE);
	Utils::IconButton(&ghButtonMenu,ghMenubarContainer,1,1,48,32,&hHideMenuIcon);

}

void EditorWindow::createMenu() {

	Utils::Container(&ghMenuContainer,ghEditorWindowContainer,0,34,480,238,"",&(Styles::MenuStyle),FALSE);

	Utils::GroupBox(&ghMenuFileContainer,ghMenuContainer,5,0,230,141,"File",&(Styles::MenuStyle),UserInterface::getUserInterface().getFontMini());
	Utils::Label(&ghLabelPatch,ghMenuContainer,15,11,60,34,"Patch:",&(Styles::MenuStyle));
	Utils::Label(&ghLabelPatchName,ghMenuContainer,80,11,130,34,"unnamed",&(Styles::MenuStyle));
	Utils::PushButton(&ghButtonNew,ghMenuFileContainer,10,58,100,34,Texts::editorButtonNew);
	Utils::PushButton(&ghButtonLoad,ghMenuFileContainer,10,105,100,34,Texts::editorButtonLoad);
	Utils::PushButton(&ghButtonSave,ghMenuFileContainer,120,105,100,34,Texts::editorButtonSave);
	Utils::PushButton(&ghButtonRename,ghMenuFileContainer,120,58,100,34,Texts::editorButtonRename);
	gwinSetFont(ghLabelPatch,UserInterface::getUserInterface().getFontMedium());
	gwinSetCustomDraw(ghLabelPatch,gwinLabelDrawJustifiedLeftBottom,0);
	gwinSetFont(ghLabelPatchName,UserInterface::getUserInterface().getFontMedium());
	gwinSetCustomDraw(ghLabelPatchName,gwinLabelDrawJustifiedLeftBottom,0);

	Utils::GroupBox(&ghMenuMiscContainer,ghMenuContainer,5,141,230,94,"Misc",&(Styles::MenuStyle),UserInterface::getUserInterface().getFontMini());
	Utils::PushButton(&ghButtonDebug,ghMenuMiscContainer,10,58,100,34,Texts::editorButtonDebug);
	Utils::PushButton(&ghButtonConsole,ghMenuMiscContainer,120,58,100,34,Texts::editorButtonConsole);
	Utils::PushButton(&ghButtonCredits,ghMenuMiscContainer,120,11,100,34,Texts::editorButtonCredits);
	Utils::PushButton(&ghButtonWelcome,ghMenuMiscContainer,10,11,100,34,Texts::editorButtonWelcome);

	Utils::GroupBox(&ghMenuEditContainer,ghMenuContainer,245,0,230,188,"Editors",&(Styles::MenuStyle),UserInterface::getUserInterface().getFontMini());
	Utils::PushButton(&ghButtonModules,ghMenuEditContainer,10,58,100,34,Texts::editorButtonModules);
	Utils::PushButton(&ghButtonGraph,ghMenuEditContainer,10,11,100,34,Texts::editorButtonGraph);
	Utils::PushButton(&ghButtonSamples,ghMenuEditContainer,120,11,100,34,Texts::editorButtonSamples);
	Utils::PushButton(&ghButtonSettings,ghMenuEditContainer,120,152,100,34,Texts::editorButtonSettings);
	Utils::PushButton(&ghButtonBlank1,ghMenuEditContainer,120,58,100,34," ");
	Utils::PushButton(&ghButtonParameters,ghMenuEditContainer,10,105,100,34,Texts::editorButtonParameters);
	Utils::PushButton(&ghButtonBlank3,ghMenuEditContainer,120,105,100,34," ");
	Utils::PushButton(&ghButtonBlank4,ghMenuEditContainer,10,152,100,34," ");

	Utils::GroupBox(&ghMenuRunContainer,ghMenuContainer,245,188,230,47,"Run",&(Styles::MenuStyle),UserInterface::getUserInterface().getFontMini());
	Utils::PushButton(&ghButtonVerify,ghMenuRunContainer,10,11,100,34,Texts::editorButtonVerify);
	Utils::PushButton(&ghButtonRun,ghMenuRunContainer,120,11,100,34,Texts::editorButtonRun);
	gwinSetStyle(ghButtonRun,&(Styles::EditorLiveButtonStyle));
}



void EditorWindow::createEditorWindow() {
	Utils::Container(&ghEditorWindowContainer,NULL,0,0,480,272,"Editor",&(Styles::DefaultWindowStyle),FALSE);

}


void EditorWindow::hideSubWindows() {
	activeSubscreen->hide();
}

void EditorWindow::hideMenu() {
	gwinHide(ghMenuContainer);
			gwinSetCustomDraw(ghButtonMenu,gwinButtonDraw_Image,(void*)&hShowMenuIcon);
			gwinRedraw(ghButtonMenu);
}




void EditorWindow::buttonMenuCallback() {
	if(gwinGetVisible(ghMenuContainer))
	{
		hideMenu();
		showActiveSubscreen();

	}
	else
	{
		disableActiveSubscreen();
		showMenu();


	}
}

GHandle EditorWindow::getGhEditorWindowContainer() const {
	return ghEditorWindowContainer;
}

GHandle EditorWindow::getGhMenubarContainer() const {
	return ghMenubarContainer;
}


void EditorWindow::loadImages() {
	gdispImageOpenMemory(&hHideMenuIcon,hideMenuIcon);
	gdispImageOpenMemory(&hShowMenuIcon,showMenuIcon);
}

void EditorWindow::setActiveSubscreen(EditorSubscreen* subscreen) {
	if(subscreen == NULL)
		return;

	if(activeSubscreen != NULL)
	{
		activeSubscreen->hide();
	}

	activeSubscreen = subscreen;



}

void EditorWindow::hideActiveSubscreen() {
	if(activeSubscreen != NULL)
		{
			activeSubscreen->hide();
		}

}

void EditorWindow::showActiveSubscreen() {
	if(activeSubscreen != NULL)
		{
			activeSubscreen->show();
		}

}

void EditorWindow::disableActiveSubscreen() {
	if(activeSubscreen != NULL)
			{
				activeSubscreen->disable();
			}
}

void EditorWindow::enableActiveSubscreen() {
	if(activeSubscreen != NULL)
			{
				activeSubscreen->enable();
			}
}

void EditorWindow::buttonDebugCallback() {
	hideMenu();
	setActiveSubscreen(debugSubscreen);
	showActiveSubscreen();
	enableActiveSubscreen();
}

void EditorWindow::enable() {
}

void EditorWindow::disable() {
}

void EditorWindow::showMenu() {
	gwinShow(ghMenuContainer);
			gwinSetCustomDraw(ghButtonMenu,gwinButtonDraw_Image,(void*)&hHideMenuIcon);
			gwinRedraw(ghButtonMenu);
}
