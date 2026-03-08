#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int64.hpp"
#include "example_interfaces/srv/set_bool.hpp"

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
            service_ = this->create_service<example_interfaces::srv::SetBool>(
                "reset_counter", std::bind(&NumberCounterNode::callbackResetCounter, this, std::placeholders::_1, std::placeholders::_2)
            );
           
            
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
        
        void callbackResetCounter(const example_interfaces::srv::SetBool::Request::SharedPtr request,
                                  const example_interfaces::srv::SetBool::Response::SharedPtr response)
        {
            if (request->data) // If the request is to reset the counter
            {
                counter_ = 0; // Reset the counter
                response->success = true;
                response->message = "Counter has been reset.";
                RCLCPP_INFO(this->get_logger(), "Counter reset requested. Counter is now: %ld", (long int)counter_);
            }
            else
            {
                response->success = false;
                response->message = "Counter reset not requested.";
                RCLCPP_INFO(this->get_logger(), "Counter reset not requested. Counter remains: %ld", (long int)counter_);
            }
        }

        rclcpp::Subscription<example_interfaces::msg::Int64>::SharedPtr subscription_;
        rclcpp::Publisher<example_interfaces::msg::Int64>::SharedPtr publisher_;
        rclcpp::Service<example_interfaces::srv::SetBool>::SharedPtr service_;

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