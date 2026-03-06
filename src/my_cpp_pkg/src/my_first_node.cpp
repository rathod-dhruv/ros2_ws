#include "rclcpp/rclcpp.hpp"

class MyNode  : public rclcpp::Node
{
public:
    MyNode() : Node("cpp_test"), counter_(0)
    {
        RCLCPP_INFO(this->get_logger(), "Hello World!");
        timer_ = this->create_wall_timer(
            std::chrono::seconds(3), std::bind(&MyNode::timer_callback, this)
        );
    }

private:

    rclcpp::TimerBase::SharedPtr timer_;
    int counter_;

    void timer_callback()
    {
        RCLCPP_INFO(this->get_logger(), "Timer callback triggered %d after 3 seconds!" , counter_);
        counter_++;
    }
    


};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    //Do Something
    //auto node = std::make_shared<rclcpp::Node>("cpp_test");
    //RCLCPP_INFO(node->get_logger(), "Hello World!");

    auto node = std::make_shared<MyNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}