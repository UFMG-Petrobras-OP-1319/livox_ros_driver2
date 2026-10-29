#include <array>
#include <cassert>
#include <cstdint>

#include "comm/lidar_line_number.h"

int main() {
  using namespace livox_ros;
  assert(LidarLineNumberForDeviceType(LivoxLidarDeviceType::kLivoxLidarTypeMid360s) == 4);
  assert(LidarLineNumberForDeviceType(LivoxLidarDeviceType::kLivoxLidarTypeMid360) == 4);
  assert(LidarLineNumberForDeviceType(LivoxLidarDeviceType::kLivoxLidarTypeIndustrialHAP) == 6);
  assert(LidarLineNumberForDeviceType(0) == 1);

  std::array<uint8_t, 8> converted_lines{};
  for (size_t point_index = 0; point_index < converted_lines.size(); ++point_index) {
    converted_lines[point_index] = LidarLineForPointIndex(
        LidarLineNumberForDeviceType(LivoxLidarDeviceType::kLivoxLidarTypeMid360s),
        point_index);
  }
  assert((converted_lines == std::array<uint8_t, 8>{0, 1, 2, 3, 0, 1, 2, 3}));
  return 0;
}
