#include "NotoSansMonoSCB20.h"

void drawHomeScream()
{
  sprite.fillSprite(TFT_BLACK);
  sprite.setTextDatum(0);
  sprite.loadFont(NotoSansMonoSCB20);
  sprite.setTextColor(textColor);

  sprite.drawString("Iniciando...", 60, 60);
  sprite.pushSprite(0, 0);
}