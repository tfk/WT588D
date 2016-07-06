#ifndef _WT588D_H_
#define _WT588D_H_
#include "Arduino.h"

class WT588D {
  private:
    static const uint8_t MAX_TRACK_VALUE = 0xDB;
    static const uint8_t MIN_VOLUME_VALUE = 0;
    static const uint8_t MAX_VOLUME_VALUE = 7;
    static const uint8_t CMD_VOLUME_OFFSET = 0xE0;
    static const uint8_t CMD_LOOP_PLAY = 0xF2;
    static const uint8_t CMD_STOP_PLAY = 0xFE;
    static const uint16_t ACTIVE_DUTY_TIME = 400;
    static const uint16_t PASSIVE_DUTY_TIME = 200;

    uint8_t rstPin;
    uint8_t sdaPin;
    uint8_t bsyPin;

    void sendCommand(uint8_t cmd, bool toggleReset) const;
  public:

    WT588D(uint8_t rstPin, uint8_t sdaPin, uint8_t bsyPin);
    void begin() const;
    bool isBusy() const;

    void waitForBusy(uint32_t ms) const;
    void play(uint8_t nr) const;
    void setVolume(uint8_t volume) const;
    void loop() const;
    void stop() const;
};

#endif
