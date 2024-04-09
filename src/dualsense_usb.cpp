#include "dualsense/dualsense_usb.hpp"

void DualSenseUSB::WriteReport() {
  if (!isConnected()) return;
  unsigned char out_report[48]; // USB接続の場合、バッファサイズは48
  memset(out_report, 0, sizeof(out_report));

  out_report[0] = 0x02; // Report ID for DualSense (USB)
  out_report[1] = 0xff;
  out_report[2] = 0x1 | 0x2 | 0x4 | 0x10 | 0x40;
  // Set motor intensity
  out_report[3] = right_motor_intensity_;
  out_report[4] = left_motor_intensity_;

  // out_report[5] ~ out_report[8] audio関係だが、今の所使えない
  // out_report[10] out_report[11] microphone button に関係
  // out_report[12] ~ out_report[32] triggerに関係

  // Set LED color
  out_report[45] = red_value_;
  out_report[46] = green_value_;
  out_report[47] = blue_value_;

  hid_write(dualsense_, out_report, sizeof(out_report));
}
