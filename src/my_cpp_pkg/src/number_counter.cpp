#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int64.hpp"

class NumberCounterNode : public rclcpp::Node
{

    public:
        NumberCounterNode() : Node("number_counter")
        {
            RCLCPP_INFO(this->get_logger(), "Welcome to the Number Counter Node!");
            subscription_ = this->create_subscription<example_interfaces::msg::Int64>(
                "number", 10, std::bind(&NumberCounterNode::callbackNumber, this, std::placeholders::_1)
            );
            publisher_ = this->create_publisher<example_interfaces::msg::Int64>("number_counter", 10);
           
        }
    
    private:

        void callbackNumber(const example_interfaces::msg::Int64::SharedPtr msg)
        {
            RCLCPP_INFO(this->get_logger(), "Received number: %ld", (long int)msg->data);
            counter_ += msg->data; // Increment the received number
            publishCounter(); // Publish the updated counter
        }
        void publishCounter()
        {
            auto message = example_interfaces::msg::Int64();
            message.data = counter_;
            publisher_->publish(message);
            RCLCPP_INFO(this->get_logger(), "Published counter: %ld", (long int)message.data);
        }
        
        rclcpp::Subscription<example_interfaces::msg::Int64>::SharedPtr subscription_;
        rclcpp::Publisher<example_interfaces::msg::Int64>::SharedPtr publisher_;
        int counter_ = 0;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<NumberCounterNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}