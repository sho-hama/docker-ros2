#include <memory>
#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float64.hpp"
#include "Publisher.h"

using namespace std::chrono_literals;


Publisher::Publisher() : Node("publisher_node"), normalDistribution(NormalDistribution(1.0, 1.0))
{
  //20Hz
  timer_ = create_wall_timer(0.05s, std::bind(&Publisher::timer_callback, this));
  publisher_ = this->create_publisher<std_msgs::msg::Float64>("topic", 10);
}


void Publisher::timer_callback()
{
  auto message = std_msgs::msg::Float64();
  message.data = this->normalDistribution.generateRamdomNum();
  RCLCPP_INFO(this->get_logger(), "Publishing Random Number: '%f'", message.data);
  publisher_->publish(message);
}


