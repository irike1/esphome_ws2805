#pragma once

#include "esphome.h"
#include "esphome/components/light/light_output.h"

namespace esphome {
namespace ws2805 {

class WS2805 : public light::LightOutput, public Component {
 public:
  explicit WS2805(uint8_t pin) : pin_(pin) {}
  void setup() override;
  void write_state(light::LightState *state) override;

 private:
  void send_color(uint8_t r, uint8_t g, uint8_t b, uint8_t w1, uint8_t w2);
  void send_bit(bool bit_val);
  void send_byte(uint8_t byte);

  uint8_t pin_;
};

}  // namespace ws2805
}  // namespace esphome
