/*
 * EditorWindow.h
 *
 *  Created on: 13.05.2020
 *      Author: markov94
 */

#ifndef INTERFACE_EDITORWINDOW_H_
#define INTERFACE_EDITORWINDOW_H_

#include "Screen.h"
#include "gfx.h"


class EditorSubscreen;
class DebugSubscreen;
class WelcomeSubscreen;


class EditorWindow : public Screen{
public:
	EditorWindow();
	virtual ~EditorWindow();
	void show();
	void hide();
	void create();
	void refresh();
	void eventLoop();
	void enable();
	void disable();

	void hideSubWindows();
	void hideMenu();
	void showMenu();

	void enableMenubar(bool_t enable);
	GHandle getGhEditorWindowContainer() const;
	GHandle getGhMenubarContainer() const;

private:
	GHandle ghEditorWindowContainer;
	GHandle ghMenubarContainer;
	GHandle ghMenuContainer;
	GHandle ghMenuFileContainer;
	GHandle ghMenuMiscContainer;
	GHandle ghMenuEditContainer;
	GHandle ghMenuRunContainer;

	void loadImages();
	void createEditorWindow();
	void createMenubar();
	void createMenu();

	void setActiveSubscreen(EditorSubscreen* subscreen);
	void hideActiveSubscreen();
	void showActiveSubscreen();
	void disableActiveSubscreen();
	void enableActiveSubscreen();

	GHandle	ghButtonMenu;
	GHandle	ghLabelPatch;
	GHandle	ghLabelPatchName;
	GHandle	ghButtonNew;
	GHandle	ghButtonLoad;
	GHandle	ghButtonSave;
	GHandle	ghButtonRename;
	GHandle	ghButtonModules;
	GHandle	ghButtonGraph;
	GHandle	ghButtonSettings;
	GHandle	ghButtonRun;
	GHandle	ghButtonConsole;
	GHandle	ghButtonCredits;
	GHandle	ghButtonSamples;
	GHandle	ghButtonDebug;
	GHandle	ghButtonVerify;
	GHandle	ghButtonBlank1;
	GHandle	ghButtonParameters;
	GHandle	ghButtonBlank3;
	GHandle	ghButtonBlank4;
	GHandle	ghButtonWelcome;


	gdispImage hHideMenuIcon;
	gdispImage hShowMenuIcon;


	void buttonMenuCallback();
	void buttonNewCallback();
	void buttonLoadCallback();
	void buttonSaveCallback();
	void buttonRenameCallback();
	void buttonInfoCallback();
	void buttonModulesCallback();
	void buttonGraphCallback();
	void buttonSettingsCallback();
	void buttonRunCallback();
	void buttonConsoleCallback();
	void buttonAboutCallback();
	void buttonDebugCallback();
	void buttonVerifyCallback();

	EditorSubscreen* activeSubscreen;
	DebugSubscreen* debugSubscreen;
	WelcomeSubscreen* welcomeSubscreen;


};

#endif /* INTERFACE_EDITORWINDOW_H_ */
