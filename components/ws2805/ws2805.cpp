#include "ws2805.h"

namespace esphome {
namespace ws2805 {

void WS2805::setup() {
  pinMode(pin_, OUTPUT);
  digitalWrite(pin_, LOW);
}

void WS2805::write_state(light::LightState *state) {
  float red, green, blue, white1, white2;
  state->current_values_as_rgbw(&red, &green, &blue, &white1, &white2);
  uint8_t r = red * 255.0;
  uint8_t g = green * 255.0;
  uint8_t b = blue * 255.0;
  uint8_t w1 = white1 * 255.0;
  uint8_t w2 = white2 * 255.0;
  send_color(r, g, b, w1, w2);
}

void WS2805::send_color(uint8_t r, uint8_t g, uint8_t b, uint8_t w1, uint8_t w2) {
  send_byte(r);
  send_byte(g);
  send_byte(b);
  send_byte(w1);
  send_byte(w2);
  digitalWrite(pin_, LOW);
  delayMicroseconds(280);
}

void WS2805::send_bit(bool bit_val) {
  if (bit_val) {
    digitalWrite(pin_, HIGH);
    delayMicroseconds(580);
    digitalWrite(pin_, LOW);
    delayMicroseconds(580);
  } else {
    digitalWrite(pin_, HIGH);
    delayMicroseconds(220);
    digitalWrite(pin_, LOW);
    delayMicroseconds(580);
  }
}

void WS2805::send_byte(uint8_t byte) {
  for (int i = 7; i >= 0; i--) {
    send_bit(byte & (1 << i));
  }
}

}  // namespace ws2805
}  // namespace esphome
