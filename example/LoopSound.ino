#include "WT588D.h"

#define WT588D_RST 9 // Pin "RESET"
#define WT588D_SDA 10 // Pin "P03"
#define WT588D_BUSY 7 // Pin BUSY 

WT588D wt588d(WT588D_RST, WT588D_SDA, WT588D_BUSY);

void setup() {
  wt588d.begin();
  wt588d.play(0);

  delay(2000);
  wt588d.play(10);
  wt588d.loop();
}

void loop() {


}

