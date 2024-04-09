#include "dualsense_bt.hpp"
#include "checksum/checksum.cpp"

void DualSenseBT::WriteReport() {
  if (!isConnected()) return;
  unsigned char out_report[78]; // BT接続の場合、バッファサイズは78
  memset(out_report, 0, sizeof(out_report));

  out_report[0] = 0x31; // Report ID for DualSense (Bluetooth)
  out_report[1] = 0x02;
  out_report[2] = 0xff;
  out_report[3] = 0x1 | 0x2 | 0x4 | 0x10 | 0x40;
  // Set motor intensity
  out_report[4] = right_motor_intensity_;
  out_report[5] = left_motor_intensity_;

  // out_report[5] ~ out_report[8] audio関係だけど今の所使えない
  // out_report[10] out_report[11] microphne buttonに関係
  // out_report[12] ~ out_report[32] triggerに関係

  // Set LED color 
  out_report[46] = red_value_; // Red
  out_report[47] = green_value_; // Green
  out_report[48] = blue_value_; // Blue

  // checksum
  uint32_t hash = compute(out_report);
  out_report[74] = hash & 0xFF;
  out_report[75] = (hash >> 8) & 0xFF;
  out_report[76] = (hash >> 16) & 0xFF;
  out_report[77] = (hash >> 24) & 0xFF;

  hid_write(dualsense_, out_report, sizeof(out_report));
}


