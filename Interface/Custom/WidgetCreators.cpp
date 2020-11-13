/*
 * utils.cpp
 *
 *  Created on: 19.05.2020
 *      Author: markov94
 */

#include "utils.h"
#include "custom.h"

namespace Utils{

void PushButton(GHandle* handle,GHandle parent, coord_t x, coord_t y, coord_t width, coord_t height, const char* text)
{
	GWidgetInit	wi;

	// Apply some default values for GWIN
	gwinWidgetClearInit(&wi);
	wi.g.show = TRUE;

	// Apply the button parameters
	wi.g.width = width;
	wi.g.height = height;
	wi.g.y = y;
	wi.g.x = x;
	if(parent != NULL)
	{
		wi.g.parent = parent;
	}
	wi.text = text;

	// Create the actual button
	*handle = gwinButtonCreate(NULL, &wi);
}

void IconButton(GHandle* handle,GHandle parent, coord_t x, coord_t y, coord_t width, coord_t height, gdispImage* image)
{
	PushButton(handle,parent,x,y,width,height,"");
	gwinSetCustomDraw(*handle,gwinButtonDraw_Image,(void*)image);
}

void Container(GHandle* handle,GHandle parent, coord_t x, coord_t y, coord_t width, coord_t height, const char* text, const GWidgetStyle * style, bool_t border)
{
	GWidgetInit wi;

	// Apply some default values for GWIN
	gwinWidgetClearInit(&wi);

	// Apply the container parameters
	wi.g.show = FALSE;
	wi.g.width = width;
	wi.g.height = height;
	wi.g.y = y;
	wi.g.x = x;
	wi.text = text;
	if(parent != NULL)
	{
		wi.g.parent = parent;
	}
	wi.customStyle = style;
	if(border == TRUE)
	{
		*handle = gwinContainerCreate(0, &wi, GWIN_CONTAINER_BORDER);
	}
	else{
		*handle = gwinContainerCreate(0, &wi, NULL);
	}
}
void GroupBox(GHandle* handle,GHandle parent, coord_t x, coord_t y, coord_t width, coord_t height, const char* text, const GWidgetStyle * style, font_t font)
{
	GWidgetInit wi;

	// Apply some default values for GWIN
	gwinWidgetClearInit(&wi);

	// Apply the container parameters
	wi.g.show = TRUE;
	wi.g.width = width;
	wi.g.height = height;
	wi.g.y = y;
	wi.g.x = x;
	wi.text = text;
	wi.g.parent = parent;
	wi.customStyle = style;
	wi.customDraw = containerGroupBoxRendering;
	*handle = gwinContainerCreate(0, &wi, NULL);
	gwinSetFont(*handle,font);



}

void Label(GHandle* handle,GHandle parent, coord_t x, coord_t y, coord_t width, coord_t height, const char* text, const GWidgetStyle * style)
{
	GWidgetInit		wi;
	// Apply some default values for GWIN
	gwinWidgetClearInit(&wi);


	// Apply some default values for GWIN
	gwinWidgetClearInit(&wi);
	wi.g.show = TRUE;

	// Apply the button parameters
	wi.g.width = width;
	wi.g.height = height;
	wi.g.y = y;
	wi.g.x = x;
	if(parent != NULL)
	{
		wi.g.parent = parent;
	}
	wi.text = text;
	// Apply some default values for GWIN
	wi.customDraw = 0;
	wi.customParam = 0;
	wi.customStyle = style;
	// Create the actual label
	*handle = gwinLabelCreate(NULL, &wi);
}
void Slider(GHandle* handle,GHandle parent, coord_t x, coord_t y, coord_t width, coord_t height, const char* text)
{
	GWidgetInit		wi;
	// Apply some default values for GWIN
	gwinWidgetClearInit(&wi);


	// Apply some default values for GWIN
	gwinWidgetClearInit(&wi);
	wi.g.show = TRUE;

	// Apply the button parameters
	wi.g.width = width;
	wi.g.height = height;
	wi.g.y = y;
	wi.g.x = x;
	if(parent != NULL)
	{
		wi.g.parent = parent;
	}
	wi.text = text;
	// Apply some default values for GWIN
	wi.customDraw = 0;
	wi.customParam = 0;
	wi.customStyle = 0;
	*handle = gwinSliderCreate(NULL, &wi);
}
}
