#include "dualsense_base.hpp"
#include <stdio.h>

DualsenseBase::DualsenseBase() {
  hid_init();
  dualsense_ = hid_open(0x054c, 0x0ce6, nullptr);
}

DualsenseBase::~DualsenseBase() {
  if (dualsense_ != nullptr) hid_close(dualsense_);
  hid_exit(); 
}

bool DualsenseBase::isConnected() {
  return dualsense_ != nullptr;
}

void DualsenseBase::SetLED(uint8_t red_value, uint8_t green_value, uint8_t blue_value) {
  red_value_ = red_value;
  green_value_ = green_value;
  blue_value_ = blue_value;
}

void DualsenseBase::SetMotorIntensity(uint8_t right_motor_intensity, uint8_t left_motor_intensity) {
  right_motor_intensity_ = right_motor_intensity;
  left_motor_intensity_ = left_motor_intensity;
}

uint16_t DualsenseBase::GetPich() {
  unsigned char in_report[64];
  memset(in_report, 0, sizeof(in_report));
  hid_read(dualsense_, in_report, sizeof(in_report));
  int16_t gyroPitch = in_report[22] | (in_report[23] << 8);
  return gyroPitch;
}
