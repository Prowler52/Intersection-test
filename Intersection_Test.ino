#include <Pixy2.h>
Pixy2 pixy;
int i;
int Xinter, Yinter;
int Xblock[4];
int Yblock[4];
unsigned long myTime;
unsigned long previousTime = 0 ;

void setup() {
  Serial.begin(115200);
  pixy.init();
  pixy.setLamp(1,1);
}

void loop() {
 millis();
  pixy.changeProg("line");
  pixy.line.getAllFeatures();
 myTime = millis();
  while (millis() < myTime + 1000) {
    if (pixy.line.numVectors > 1 && pixy.line.numVectors < 5 ) {
      Xinter = pixy.line.intersections[0].m_x * 4;
      Yinter = pixy.line.intersections[0].m_y * 4;
    }
  }
  if (pixy.line.intersections) {
    pixy.changeProg("ccc");
    myTime = millis();
    while (millis() + 500 < myTime + 3500) {
      pixy.ccc.getBlocks();
      if (pixy.ccc.blocks)
        for (i = 0; i < 3; i++ ) {
          if (pixy.ccc.blocks[i].m_x > 315) {
            pixy.ccc.blocks[i].m_x = 0;
          }
          if (pixy.ccc.blocks[i].m_y > 207) {
            pixy.ccc.blocks[i].m_y = 0;
          }
          Xblock[i] = pixy.ccc.blocks[i].m_x;
          Yblock[i] = pixy.ccc.blocks[i].m_y;
        }

  
}
