#ifndef COLOR_SENSOR_H
#define COLOR_SENSOR_H

#include <Arduino.h>

class ColorSensor {
  public:
    ColorSensor(int S0, int S1, int S2, int S3, int out);

    void begin();
    void setColorMode();
    void setFrequencyScaling(int scaling);
    bool detectColor(uint32_t hexColor);

  private:
    int _S0;
    int _S1;
    int _S2;
    int _S3;
    int _out;
    int _tolerance = 20; // Tolerance for color detection
};

#endif
