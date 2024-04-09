#ifndef DUALSENSE_BASE_HPP_
#define DUALSENSE_BASE_HPP_

#include <hidapi/hidapi.h>
#include <memory>
#include <cstring>

class DualsenseBase {
  public:
    DualsenseBase();
    ~DualsenseBase();
    bool isConnected();
    void SetLED(uint8_t red_value, uint8_t green_value, uint8_t blue_value);
    void SetMotorIntensity(uint8_t righe_motor_intensity_, uint8_t left_motor_intensity_);
    uint16_t GetPich();
    virtual void WriteReport() = 0;
  
  protected:
    hid_device* dualsense_;
    uint8_t red_value_{0};
    uint8_t green_value_{0};
    uint8_t blue_value_{0};
    uint8_t right_motor_intensity_{0};
    uint8_t left_motor_intensity_{0};
};

#endif // DUALSENSE_BASE_HPP_
