#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"

using namespace std::chrono_literals;

class RobotNewsStation : public rclcpp::Node
{

    public:
        RobotNewsStation() : Node("robot_news_station"), robot_name("R2D2")
        {
            RCLCPP_INFO(this->get_logger(), "Welcome to the Robot News Station!");
            publisher_ = this->create_publisher<example_interfaces::msg::String>("robot_news", 10); 
            timer_ = this->create_wall_timer(
                1s, std::bind(&RobotNewsStation::publishNews, this)
            );
        }
    
    private:

        void publishNews()
        {
            auto message = example_interfaces::msg::String();
            message.data = "Breaking News: ROS2 is awesome! - " + robot_name;
            publisher_->publish(message);
            RCLCPP_INFO(this->get_logger(), "Published news: %s", message.data.c_str());
        }
        
        std::string robot_name;
        rclcpp::Publisher<example_interfaces::msg::String>::SharedPtr publisher_;
        rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<RobotNewsStation>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}