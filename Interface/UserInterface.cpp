/*
 * UserInterface.cpp
 *
 *  Created on: 30.04.2020
 *      Author: markov94
 */

#include "UserInterface.h"

UserInterface::UserInterface() {
	// TODO Auto-generated constructor stub

	//osMessageQDef(osqueue, 1, uint16_t);
	//guiEvent = osMessageCreate(osMessageQ(osqueue), NULL);




}

/*
 * This function DOES NOT start the OS kernel.
 */
void UserInterface::start()
{

	xTaskCreate((UserInterface::initTaskFun), "Init", 1024, NULL, 3, &uGFXInitTask);

}


void UserInterface::initTaskFun(void *pvParameters)
{
	while(1){
		// Initialize the display
		gfxInit();

		// We are currently at GDISP_ROTATE_0
		gdispSetOrientation(GDISP_ROTATE_0);

		// Set the widget defaults
		gwinSetDefaultFont(gdispOpenFont("UI2"));
		gwinSetDefaultStyle(&WhiteWidgetStyle, FALSE);
		gdispClear(White);

		// create the widget
		UserInterface::getUserInterface().create();





		// We want to listen for widget events
		geventListenerInit(UserInterface::getUserInterface().getListenerP());
		gwinAttachListener(UserInterface::getUserInterface().getListenerP());
		/* Create the event loop. */
		xTaskCreate((UserInterface::eventLoop), "EventLoop", 200, NULL, 4, NULL);
		/* Delete this task as it became obsolete. */
		vTaskDelete(UserInterface::getUserInterface().getGfxInitTask());


	}
}

void UserInterface::eventLoop(void *pvParameters)
{


	UserInterface::getUserInterface().getEditorWindowP()->show();
	UserInterface::getUserInterface().getEditorWindowP()->eventLoop();

}

void UserInterface::create()
{

	fontMedium =gdispOpenFont("DejaVuSans20_aa");
	fontLarge=gdispOpenFont("DejaVuSans32_aa");
	fontMini=gdispOpenFont("fixed_5x8");

	editorWindow.create();
	liveWindow.create();


}
