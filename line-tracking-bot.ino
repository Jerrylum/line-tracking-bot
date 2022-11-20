#include "api.h"

Motor left_motor(6, 5); // forward pin, backward pin
Motor right_motor(10, 11);

LineSensor middle_sensor(A0, 100); // 100 is the threshold
LineSensor left_sensor(A1, 100);
LineSensor right_sensor(A2, 100);

void setup() {
  // Serial.begin(9600); // Not needed
}

void loop() {
  bool middle = middle_sensor.is_on_line();
  bool left = left_sensor.is_on_line();
  bool right = right_sensor.is_on_line();

  if (!left && !middle && !right) {
    left_motor = 150;
    right_motor = 150;
  }
  if (!left && !middle && right) {
    left_motor = 150;
    right_motor = -150;
  }
  if (!left && middle && !right) {
    left_motor = 150;
    right_motor = 150;
  }
  if (!left && middle && right) {
    left_motor = 150;
    right_motor = 0;
  }
  if (left && !middle && !right) {
    left_motor = -150;
    right_motor = 150;
  }
  if (left && !middle && right) {
    left_motor = 0;
    right_motor = 0;
  }
  if (left && middle && !right) {
    left_motor = 0;
    right_motor = 150;
  }
  if (left && middle && right) {
    left_motor = 0;
    right_motor = 0;
  }

  delay(10);
}
