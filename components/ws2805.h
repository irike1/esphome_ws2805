#pragma once

#include "esphome.h"

class YourComponentName : public Component, public Sensor {
public:
  void setup() override {
    // This will be called by ESPHome when the component is initialized
  }

  void loop() override {
    // This will be called by ESPHome every loop iteration
  }
};
