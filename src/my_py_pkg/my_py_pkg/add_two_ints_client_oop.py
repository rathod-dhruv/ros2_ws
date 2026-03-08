#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from example_interfaces.srv import AddTwoInts
from functools import partial


class AddTwoIntsClient(Node):
    def __init__(self):
        super().__init__("add_two_ints_client")
        self.client = self.create_client(AddTwoInts, "add_two_ints")
        
    def call_add_two_ints(self, a , b):
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info("Waiting for the add_two_ints service to be available...")

        request = AddTwoInts.Request()
        request.a = a
        request.b = b
        
        future = self.client.call_async(request)
        future.add_done_callback(partial(self.handle_response, request=request))
    
    def handle_response(self, future, request):  
        if future.result() is not None:
            response = future.result()
            self.get_logger().info(f"Result of add_two_ints: {request.a} + {request.b} = {response.sum}")
        else:
            self.get_logger().error("Service call failed")



def main(args=None):
    rclpy.init(args=args)
    node = AddTwoIntsClient()
    node.call_add_two_ints(2,9)
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
