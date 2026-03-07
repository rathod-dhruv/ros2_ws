#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int64.hpp"

using namespace std::chrono_literals;

class NumberPublisher : public rclcpp::Node
{

    public:
        NumberPublisher() : Node("number_publisher")
        {
            RCLCPP_INFO(this->get_logger(), "Welcome to Number Publisher!");
            publisher_ = this->create_publisher<example_interfaces::msg::Int64>("number", 10); 
            timer_ = this->create_wall_timer(
                1s, std::bind(&NumberPublisher::publishNumber, this)
            );
        }
    
    private:

        void publishNumber()
        {
            auto message = example_interfaces::msg::Int64();
            message.data = _counter;
            _counter++;
            publisher_->publish(message);
            RCLCPP_INFO(this->get_logger(), "Published number: %ld", (long int)message.data);
        }
        
        int _counter;
        rclcpp::Publisher<example_interfaces::msg::Int64>::SharedPtr publisher_;
        rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<NumberPublisher>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}