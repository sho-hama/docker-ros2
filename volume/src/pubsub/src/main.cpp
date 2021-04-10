#include "rclcpp/rclcpp.hpp"
#include "Publisher.h"
#include <stdio.h>
#include <iostream>
#include <sys/time.h>
#include <time.h>

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::WallRate rate(std::chrono::milliseconds(50));
  auto node = std::make_shared<Publisher>();
  
  while(rclcpp::ok()) {
    printf("Another Operation!\n");
    rclcpp::spin_some(node);
    rate.sleep();
  }
  rclcpp::shutdown();
  return 0;
}
