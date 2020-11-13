/*
 * utils.h
 *
 *  Created on: 13.05.2020
 *      Author: markov94
 */

#ifndef UTILITIES_UTILS_H_
#define UTILITIES_UTILS_H_

#include "gfx.h"

namespace Utils{

void PushButton(GHandle* handle,GHandle parent, coord_t x, coord_t y, coord_t width, coord_t height, const char* text);
void Slider(GHandle* handle,GHandle parent, coord_t x, coord_t y, coord_t width, coord_t height, const char* text);
void IconButton(GHandle* handle,GHandle parent, coord_t x, coord_t y, coord_t width, coord_t height, gdispImage* image);

void Container(GHandle* handle,GHandle parent, coord_t x, coord_t y, coord_t width, coord_t height, const char* text, const GWidgetStyle * style, bool_t border);
void GroupBox(GHandle* handle,GHandle parent, coord_t x, coord_t y, coord_t width, coord_t height, const char* text, const GWidgetStyle * style, font_t font);
void Label(GHandle* handle,GHandle parent, coord_t x, coord_t y, coord_t width, coord_t height, const char* text, const GWidgetStyle * style);
}
#endif /* UTILITIES_UTILS_H_ */
