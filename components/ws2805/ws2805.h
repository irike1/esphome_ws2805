#pragma once

#include "esphome.h"

class WS2805 : public Component, public LightOutput {
public:
  void setup() override;
  void write_state(LightState *state) override;

private:
  void send_color(uint8_t r, uint8_t g, uint8_t b, uint8_t w1, uint8_t w2);
  void send_bit(bool bit_val);
  void send_byte(uint8_t byte);
};
