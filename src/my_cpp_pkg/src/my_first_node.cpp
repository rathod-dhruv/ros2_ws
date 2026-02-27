#include "rclcpp/rclcpp.hpp"


int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    //Do Something
    auto node = std::make_shared<rclcpp::Node>("my_first_node");

    rclcpp::shutdown();
    return 0;
}