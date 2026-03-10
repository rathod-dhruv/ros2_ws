#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int64.hpp"

using namespace std::chrono_literals;

class NumberPublisher : public rclcpp::Node
{

    public:
        NumberPublisher() : Node("number_publisher")
        {
            this->declare_parameter("number", 2);
            this->declare_parameter("timer_period", 1.0);

            _counter = this->get_parameter("number").as_int();

            publisher_ = this->create_publisher<example_interfaces::msg::Int64>("number", _counter); 
            timer_ = this->create_wall_timer(
                this->get_parameter("timer_period").as_double() * 1s, std::bind(&NumberPublisher::publishNumber, this)
            );
            RCLCPP_INFO(this->get_logger(), "Welcome to Number Publisher!");

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