// Copyright 2024 Robert Bosch GmbH and its subsidiaries
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "gtest/gtest.h"

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/transform_stamped.hpp"
#include "pcl_ros/impl/transforms.hpp"

#include "off_highway_radar/pcl_point_object.hpp"

TEST(TestRadarPclPointObject, testPclTransform)
{
  geometry_msgs::msg::TransformStamped transform;
  off_highway_radar_msgs::msg::Object object;
  pcl::PointCloud<off_highway_radar::PclPointObject> cloud_in, cloud_out;
  cloud_in.emplace_back(object);
  EXPECT_NO_THROW(pcl_ros::transformPointCloud(cloud_in, cloud_out, transform));
}

int main(int argc, char ** argv)
{
  testing::InitGoogleTest(&argc, argv);
  rclcpp::init(argc, argv);
  int result = RUN_ALL_TESTS();
  rclcpp::shutdown();
  return result;
}
