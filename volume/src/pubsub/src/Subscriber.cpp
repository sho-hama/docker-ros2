#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float64.hpp"

using std::placeholders::_1;

class Subscriber : public rclcpp::Node
{
    public:
    Subscriber() : Node("subscriber_node")
    {
        subscriber_ = this->create_subscription<std_msgs::msg::Float64>("topic", 10, std::bind(&Subscriber::topic_callback, this, _1));
    }

    private:
    void topic_callback(const std_msgs::msg::Float64::SharedPtr msg) const
    {
        RCLCPP_INFO(this->get_logger(), "Subscribing: '%f'", msg->data);
    }
    rclcpp::Subscription<std_msgs::msg::Float64>::SharedPtr subscriber_;
};


int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Subscriber>());
    rclcpp::shutdown();
    return 0;
}
