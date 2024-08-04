#include "ws2805.h"

void WS2805::setup() {
  // Initialize GPIO pin, assume using GPIO5 for data
  pinMode(5, OUTPUT);
  digitalWrite(5, LOW);
}

void WS2805::write_state(LightState *state) {
  // Get the current color from the light state
  float red, green, blue, white1, white2;
  state->current_values_as_rgbw(&red, &green, &blue, &white1, &white2);

  // Convert to 8-bit values
  uint8_t r = red * 255.0;
  uint8_t g = green * 255.0;
  uint8_t b = blue * 255.0;
  uint8_t w1 = white1 * 255.0;
  uint8_t w2 = white2 * 255.0;

  // Send color to LED strip
  send_color(r, g, b, w1, w2);
}

void WS2805::send_color(uint8_t r, uint8_t g, uint8_t b, uint8_t w1, uint8_t w2) {
  // Send 40 bits: 8 bits each for R, G, B, W1, W2
  send_byte(r);
  send_byte(g);
  send_byte(b);
  send_byte(w1);
  send_byte(w2);

  // Send the reset signal (low for 280us)
  digitalWrite(5, LOW);
  delayMicroseconds(280);
}

void WS2805::send_bit(bool bit_val) {
  if (bit_val) {
    digitalWrite(5, HIGH);
    delayMicroseconds(580);  // T1H: 580ns to 1us
    digitalWrite(5, LOW);
    delayMicroseconds(580);  // T1L: 580ns to 1us
  } else {
    digitalWrite(5, HIGH);
    delayMicroseconds(2
