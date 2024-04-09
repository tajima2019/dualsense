#ifndef DUALSENSE_BT_HPP_
#define DUALSENSE_BT_HPP_

#include "dualsense/dualsense_base.hpp"
#include <cstring>

class DualSenseBT : public DualSenseBase {
  public:
    DualSenseBT() : DualSenseBase() {};
    ~DualSenseBT() {};
    void WriteReport() override;
};

#endif // DUALSENSE_BT_HPP_
