#include "hooks.h"

extern StartDrawingFn StartDrawing;
extern FinishDrawingFn FinishDrawing;

void Hooks::Paint(void* thisptr, PaintMode_t mode)
{
	enginevgui_vmt->GetOriginalMethod<PaintFn>(15)(thisptr, mode);

	if (Settings::ScreenshotCleaner::enabled && engine->IsTakingScreenshot())
		return;

	if (mode & PAINT_UIPANELS)
	{
		StartDrawing(surface);

		Dlights::Paint();
		ESP::Paint();
		Recoilcrosshair::Paint();
		Hitmarkers::Paint();

		FinishDrawing(surface);
	}
}