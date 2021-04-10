#include "std_msgs/msg/float64.hpp"
#include "NormalDistribution.h"

class Publisher : public rclcpp::Node {
public:
  Publisher();
private:
  void timer_callback();
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr publisher_;
  NormalDistribution normalDistribution;
};

