#pragma once

class Motor {
 public:
  int forward_pin;
  int backward_pin;

  Motor(int forward_pin, int backward_pin) : forward_pin(forward_pin), backward_pin(backward_pin) {
    pinMode(forward_pin, OUTPUT);
    pinMode(backward_pin, OUTPUT);
  }

  void operator=(short int speed) {
    if (speed > 0) {
      analogWrite(backward_pin, 0);
      analogWrite(forward_pin, speed);
    } else if (speed < 0) {
      analogWrite(forward_pin, 0);
      analogWrite(backward_pin, -speed);
    } else {
      analogWrite(forward_pin, 0);
      analogWrite(backward_pin, 0);
    }
  }
};

class LineSensor {
 public:
  int pin;
  int threshold;

  LineSensor(int pin, int threshold) : pin(pin), threshold(threshold) { pinMode(pin, INPUT); }

  bool is_on_line() { return analogRead(pin) > threshold; }
};