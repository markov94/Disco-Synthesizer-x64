/*
 * styles.h
 *
 *  Created on: 11.05.2020
 *      Author: markov94
 */

#ifndef RESOURCES_STYLES_H_
#define RESOURCES_STYLES_H_

#include "gfx.h"

namespace Styles{
//Color palette
static const uint32_t colorMenuBackground = 0x002040;
static const uint32_t colorBackground = 0x004080;
static const uint32_t colorBorder = 0xffffff;
static const uint32_t colorHighlight = 0x007fff;
static const uint32_t colorWarning = 0xfdca40;
static const uint32_t colorDim = 0x31393c;

static const GWidgetStyle EditorLiveButtonStyle = {
	HTML2COLOR(0xFFFFFF),			// window background
	HTML2COLOR(0x2A8FCD),			// focused

	// enabled color set
	{
		HTML2COLOR(0xFF0000),		// text
		HTML2COLOR(0x404040),		// edge
		HTML2COLOR(0xE0E0E0),		// fill
		HTML2COLOR(0x00E000)		// progress - active area
	},

	// disabled color set
	{
		HTML2COLOR(0xC0C0C0),		// text
		HTML2COLOR(0x808080),		// edge
		HTML2COLOR(0xE0E0E0),		// fill
		HTML2COLOR(0xC0E0C0)		// progress - active area
	},

	// pressed color set
	{
		HTML2COLOR(0x404040),		// text
		HTML2COLOR(0x404040),		// edge
		HTML2COLOR(0x808080),		// fill
		HTML2COLOR(0x00E000)		// progress - active area
	}
};

static const GWidgetStyle DefaultWindowStyle = {
		HTML2COLOR(colorBackground),	// window background
		HTML2COLOR(0x2A8FCD),			// focused

		// enabled color set
		{
				HTML2COLOR(0xFFFFFF),		// text
				HTML2COLOR(0xFFFFFF),		// edge
				HTML2COLOR(0xE0E0E0),		// fill
				HTML2COLOR(0x00E000)		// progress - active area
		},

		// disabled color set
		{
				HTML2COLOR(0xC0C0C0),		// text
				HTML2COLOR(0xFFFFFF),		// edge
				HTML2COLOR(0xE0E0E0),		// fill
				HTML2COLOR(0xC0E0C0)		// progress - active area
		},

		// pressed color set
		{
				HTML2COLOR(0x404040),		// text
				HTML2COLOR(0xFFFFFF),		// edge
				HTML2COLOR(0x808080),		// fill
				HTML2COLOR(0x00E000)		// progress - active area
		}
};

static const GWidgetStyle DialogStyle = {
		HTML2COLOR(colorWarning),	// window background
		HTML2COLOR(0x2A8FCD),			// focused

		// enabled color set
		{
				HTML2COLOR(0x000000),		// text
				HTML2COLOR(0x404040),		// edge
				HTML2COLOR(0xE0E0E0),		// fill
				HTML2COLOR(0x00E000)		// progress - active area
		},

		// disabled color set
		{
				HTML2COLOR(0xC0C0C0),		// text
				HTML2COLOR(0x808080),		// edge
				HTML2COLOR(0xE0E0E0),		// fill
				HTML2COLOR(0xC0E0C0)		// progress - active area
		},

		// pressed color set
		{
				HTML2COLOR(0x404040),		// text
				HTML2COLOR(0x404040),		// edge
				HTML2COLOR(0x808080),		// fill
				HTML2COLOR(0x00E000)		// progress - active area
		}
};

static const GWidgetStyle MenuStyle = {
		HTML2COLOR(colorMenuBackground),	// window background
		HTML2COLOR(0x2A8FCD),			// focused

		// enabled color set
		{
				HTML2COLOR(0xFFFFFF),		// text
				HTML2COLOR(0xFFFFFF),		// edge
				HTML2COLOR(0xE0E0E0),		// fill
				HTML2COLOR(0x00E000)		// progress - active area
		},

		// disabled color set
		{
				HTML2COLOR(0xC0C0C0),		// text
				HTML2COLOR(0x808080),		// edge
				HTML2COLOR(0xE0E0E0),		// fill
				HTML2COLOR(0xC0E0C0)		// progress - active area
		},

		// pressed color set
		{
				HTML2COLOR(0x404040),		// text
				HTML2COLOR(0x404040),		// edge
				HTML2COLOR(0x808080),		// fill
				HTML2COLOR(0x00E000)		// progress - active area
		}
};

static const GWidgetStyle MenuButtonHighlightedStyle = {
		HTML2COLOR(colorHighlight),	// window background
		HTML2COLOR(0x2A8FCD),			// focused

		// enabled color set
		{
				HTML2COLOR(0x000000),		// text
				HTML2COLOR(0x404040),		// edge
				HTML2COLOR(0xE0E0E0),		// fill
				HTML2COLOR(0x00E000)		// progress - active area
		},

		// disabled color set
		{
				HTML2COLOR(0xC0C0C0),		// text
				HTML2COLOR(0x808080),		// edge
				HTML2COLOR(0xE0E0E0),		// fill
				HTML2COLOR(0xC0E0C0)		// progress - active area
		},

		// pressed color set
		{
				HTML2COLOR(0x404040),		// text
				HTML2COLOR(0x404040),		// edge
				HTML2COLOR(0x808080),		// fill
				HTML2COLOR(0x00E000)		// progress - active area
		}
};

static const GWidgetStyle LiveWidgetStyle = {
		HTML2COLOR(0xFFFFFF),			// window background
		HTML2COLOR(0x2A8FCD),			// focused

		// enabled color set
		{
				HTML2COLOR(0xFFFFFF),		// text
				HTML2COLOR(0x0000FF),		// edge
				HTML2COLOR(0x00FF00),		// fill
				HTML2COLOR(0xFF0000)		// progress - active area
		},

		// disabled color set
		{
				HTML2COLOR(0xC0C0C0),		// text
				HTML2COLOR(0x808080),		// edge
				HTML2COLOR(0xE0E0E0),		// fill
				HTML2COLOR(0xC0E0C0)		// progress - active area
		},

		// pressed color set
		{
				HTML2COLOR(0x404040),		// text
				HTML2COLOR(0x404040),		// edge
				HTML2COLOR(0x808080),		// fill
				HTML2COLOR(0x00E000)		// progress - active area
		}
};

static const GWidgetStyle LiveSubscreenStyle = {
		HTML2COLOR(0xFFFFFF),			// window background
		HTML2COLOR(0x2A8FCD),			// focused

		// enabled color set
		{
				HTML2COLOR(0xFF0000),		// text
				HTML2COLOR(0x404040),		// edge
				HTML2COLOR(0xE0E0E0),		// fill
				HTML2COLOR(0x00E000)		// progress - active area
		},

		// disabled color set
		{
				HTML2COLOR(0xC0C0C0),		// text
				HTML2COLOR(0x808080),		// edge
				HTML2COLOR(0xE0E0E0),		// fill
				HTML2COLOR(0xC0E0C0)		// progress - active area
		},

		// pressed color set
		{
				HTML2COLOR(0x404040),		// text
				HTML2COLOR(0x404040),		// edge
				HTML2COLOR(0x808080),		// fill
				HTML2COLOR(0x00E000)		// progress - active area
		}
};

static const GWidgetStyle LiveMenubarStyle = {
		HTML2COLOR(0xFFFFFF),			// window background
		HTML2COLOR(0x2A8FCD),			// focused

		// enabled color set
		{
				HTML2COLOR(0xFF0000),		// text
				HTML2COLOR(0x404040),		// edge
				HTML2COLOR(0xE0E0E0),		// fill
				HTML2COLOR(0x00E000)		// progress - active area
		},

		// disabled color set
		{
				HTML2COLOR(0xC0C0C0),		// text
				HTML2COLOR(0x808080),		// edge
				HTML2COLOR(0xE0E0E0),		// fill
				HTML2COLOR(0xC0E0C0)		// progress - active area
		},

		// pressed color set
		{
				HTML2COLOR(0x404040),		// text
				HTML2COLOR(0x404040),		// edge
				HTML2COLOR(0x808080),		// fill
				HTML2COLOR(0x00E000)		// progress - active area
		}
};
}

namespace Texts{
}

#endif /* RESOURCES_STYLES_H_ */
