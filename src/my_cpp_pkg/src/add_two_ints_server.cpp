#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"

class AddTwoIntsServer : public rclcpp::Node
{
public:
    AddTwoIntsServer() : Node("add_two_ints_server")
    {

        service_ = this->create_service<example_interfaces::srv::AddTwoInts>(
            "add_two_ints", std::bind(&AddTwoIntsServer::handle_add_two_ints, this, std::placeholders::_1, std::placeholders::_2)
        );

        RCLCPP_INFO(this->get_logger(), "Add Two Ints Server has been started.");
      
    }

private:

    rclcpp::Service<example_interfaces::srv::AddTwoInts>::SharedPtr service_;
   
    void handle_add_two_ints(const example_interfaces::srv::AddTwoInts::Request::SharedPtr request,
                            const example_interfaces::srv::AddTwoInts::Response::SharedPtr response)
    {
        response->sum = request->a + request->b;
        RCLCPP_INFO(this->get_logger(), "Received request: a=%ld, b=%ld, sum=%ld", (long int)request->a, (long int)request->b, (long int)response->sum);
    }

};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<AddTwoIntsServer>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}