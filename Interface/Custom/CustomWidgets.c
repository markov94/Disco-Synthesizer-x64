#include "custom.h"
#include "src/gwin/gwin_label.h"
#include <string.h>



void containerGroupBoxRendering(GWidgetObject* gw, void* param)
{
	int16_t len = (int16_t) strlen(gw->text);
	int16_t gap = len * 6;

	if (len < 1) return;

	gwinContainerDraw_Std(gw,param);
	gdispGDrawBox(gw->g.display, gw->g.x, (gw->g.y) + 5, gw->g.width, (gw->g.height) - 5,gw->pstyle->disabled.edge);
	gdispGFillArea(gw->g.display, (gw->g.x) + 10, gw->g.y, gap + 2, 10, gw->pstyle->background);
	gdispGDrawStringBox(gw->g.display,(gw->g.x) + 11, gw->g.y,gap,12,gw->text,gw->g.font,gw->pstyle->disabled.text,justifyLeft);

}

void gwinLabelDrawJustifiedLeftBottom(GWidgetObject *gw, void *param)
{
	(void)param;

		gwinLabelDraw(gw, justifyLeft | justifyBottom);
}
