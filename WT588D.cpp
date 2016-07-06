#include "WT588D.h"

WT588D::WT588D(uint8_t rstPin, uint8_t sdaPin, uint8_t bsyPin) : rstPin(rstPin), sdaPin(sdaPin), bsyPin(bsyPin) {

}

void WT588D::sendCommand(uint8_t cmd, bool toggleReset) const {
  if (toggleReset) {
    digitalWrite(rstPin, LOW);
    delay(5);
    digitalWrite(rstPin, HIGH);
    delay(17);
  }

  digitalWrite(sdaPin, LOW);
  delay(5);

  for (int i = 0; i < 8; i++)  {
    digitalWrite(sdaPin, HIGH);
    if (bitRead(cmd, i)) {
      delayMicroseconds(ACTIVE_DUTY_TIME);
      digitalWrite(sdaPin, LOW);
      delayMicroseconds(PASSIVE_DUTY_TIME);
    }
    else {
      delayMicroseconds(PASSIVE_DUTY_TIME);
      digitalWrite(sdaPin, LOW);
      delayMicroseconds(ACTIVE_DUTY_TIME);
    }
  }
  digitalWrite(sdaPin, HIGH);
  delay(2);
}

void WT588D::begin() const {
  pinMode(rstPin, OUTPUT);
  pinMode(sdaPin, OUTPUT);
  pinMode(bsyPin, INPUT);
  digitalWrite(sdaPin, HIGH);
  digitalWrite(rstPin, HIGH);
}

bool WT588D::isBusy() const {
  return digitalRead(bsyPin) == 0;
}

void WT588D::waitForBusy(uint32_t ms) const {
  uint32_t endtime = millis() + ms;
  while (isBusy() && endtime >= millis()) {}
}

void WT588D::play(uint8_t nr) const {
  nr = constrain(nr, 0, MAX_TRACK_VALUE);
  sendCommand(nr, true);
  while (!isBusy()) {

  }
}

void WT588D::setVolume(uint8_t volume) const {
  uint8_t cmd = CMD_VOLUME_OFFSET + constrain(volume, MIN_VOLUME_VALUE, MAX_VOLUME_VALUE);
  sendCommand(cmd, false);
}

void WT588D::loop() const {
  sendCommand(CMD_LOOP_PLAY, false);
}

void WT588D::stop() const {
  sendCommand(CMD_STOP_PLAY, false);
}

