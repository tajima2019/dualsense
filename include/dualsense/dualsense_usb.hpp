#ifndef DUALSENSE_USB_HPP_
#define DUALSENSE_USB_HPP_

#include "dualsense_base.hpp"
#include <cstring>

class DualSenseUSB : public DualSenseBase {
  public:
    DualSenseUSB() : DualSenseBase() {};
    ~DualSenseUSB() {};
    void WriteReport() override;
};

#endif // DUALSENSE_USB_HPP_
