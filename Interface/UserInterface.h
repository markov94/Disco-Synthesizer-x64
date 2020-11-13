/*
 * UserInterface.h
 *
 *  Created on: 30.04.2020
 *      Author: markov94
 */

#ifndef INTERFACE_USERINTERFACE_H_
#define INTERFACE_USERINTERFACE_H_

#include "cmsis_os.h"
#include "gfx.h"

#include "EditorWindow.h"
#include "LiveWindow.h"
#include "Model/Synthesizer.h"

class UserInterface {
	private:
	UserInterface();
	UserInterface(const UserInterface&);

	//uGFX
	GListener gl;

	//OS
	TaskHandle_t uGFXInitTask;
	osMessageQId guiEvent;

	static void eventLoop(void *pvParameters);
	static void initTaskFun(void *pvParameters);


	/***
	 * @brief Creates all of the screens with their widgets
	 */
	void create();
	EditorWindow editorWindow;
	LiveWindow liveWindow;

	font_t fontMini;
	font_t fontMedium;
	font_t fontLarge;

	Synthesizer* synthesizer;

public:
	static UserInterface& getUserInterface()
	{
		static UserInterface singleton;
		return singleton;
	}

	GListener* getListenerP(void)
	{
		return &gl;
	}


	EditorWindow* getEditorWindowP(void)
		{
			return &editorWindow;
		}
	LiveWindow* getLiveWindowP(void)
		{
			return &liveWindow;
		}

	void start();

	TaskHandle_t getGfxInitTask() const {
		return uGFXInitTask;
	}

	font_t getFontLarge() const {
		return fontLarge;
	}

	font_t getFontMedium() const {
		return fontMedium;
	}

	font_t getFontMini() const {
		return fontMini;
	}

	Synthesizer* getSynthesizer() const {
		return synthesizer;
	}

	void setSynthesizer(Synthesizer *synthesizer) {
		this->synthesizer = synthesizer;
	}
};





#endif /* INTERFACE_USERINTERFACE_H_ */
