#include <MD_MAX72xx.h>
#include <SPI.h>

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 1
#define CS_PIN 3

MD_MAX72XX mx = MD_MAX72XX(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

const byte A[] = {
  B01111110,
  B10000001,
  B10000001,
  B11111111,
  B10000001,
  B10000001,
  B10000001,
  B00000000
};

void setup() {
  mx.begin();
  mx.control(MD_MAX72XX::INTENSITY, 8);
}

void loop() {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (A[i] & (1 << j)) {
        mx.setPoint(i, j, true);
      } else {
        mx.setPoint(i, j, false);
      }
    }
  }
  delay(2000);
  mx.clear();
}