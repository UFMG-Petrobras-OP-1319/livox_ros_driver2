#ifndef LIVOX_ROS_DRIVER2_LIDAR_LINE_NUMBER_H_
#define LIVOX_ROS_DRIVER2_LIDAR_LINE_NUMBER_H_

#include <stdint.h>
#include <stddef.h>

#include "livox_lidar_def.h"

namespace livox_ros {

constexpr uint8_t kLineNumberDefault = 1;
constexpr uint8_t kLineNumberMid360 = 4;
constexpr uint8_t kLineNumberHAP = 6;

inline uint8_t LidarLineNumberForDeviceType(uint8_t dev_type) {
  if (dev_type == LivoxLidarDeviceType::kLivoxLidarTypeIndustrialHAP) {
    return kLineNumberHAP;
  }
  if (dev_type == LivoxLidarDeviceType::kLivoxLidarTypeMid360 ||
      dev_type == LivoxLidarDeviceType::kLivoxLidarTypeMid360s) {
    return kLineNumberMid360;
  }
  return kLineNumberDefault;
}

inline uint8_t LidarLineForPointIndex(uint8_t line_count, size_t point_index) {
  return line_count == 0 ? 0 : static_cast<uint8_t>(point_index % line_count);
}

}  // namespace livox_ros

#endif  // LIVOX_ROS_DRIVER2_LIDAR_LINE_NUMBER_H_
