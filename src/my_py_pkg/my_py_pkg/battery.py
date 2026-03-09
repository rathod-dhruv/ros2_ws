


import rclpy
from rclpy.node import Node
from my_robot_interfaces.srv import SetLed

class BatteryNode(Node): # MODIFY NAME
    def __init__(self):
        super().__init__("battery_node") # MODIFY NAME
        self.battery_state = "full"
        self.client = self.create_client(SetLed, "set_led")
        self.last_time_batter_state_changed_ = self.get_currrent_time_seconds()
        self.battery_timer = self.create_timer(2.0, self.check_battery_status)
    

    def get_currrent_time_seconds(self):
        seconds, nanoseconds = self.get_clock().now().seconds_nanoseconds()
        return seconds + nanoseconds * 1e-9
    
    def check_battery_status(self):
        time_now = self.get_currrent_time_seconds()
        if self.battery_state == "full" and time_now - self.last_time_batter_state_changed_ > 4.0:
            self.battery_state = "empty"
            self.call_set_led(0, False)  # Turn off LED 0 when battery is empty
            self.get_logger().info("Battery state changed to EMPTY.")
            self.last_time_batter_state_changed_ = time_now
        elif self.battery_state == "empty" and time_now - self.last_time_batter_state_changed_ > 3.0:
            self.battery_state = "full"
            self.call_set_led(0, True)  # Turn on LED 0 when battery is full
            self.get_logger().info("Battery state changed to FULL.")
            self.last_time_batter_state_changed_ = time_now

    def call_set_led(self, led_number, state):
        # This method is just for testing the LED panel service. You can remove it later.
       
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info("Waiting for the set_led service to be available...")

        request = SetLed.Request()
        request.led_number = led_number
        request.state = state
        
        future = self.client.call_async(request)
        future.add_done_callback(self.handle_set_led_response)

    def handle_set_led_response(self, future):
        if future.result() is not None:
            response = future.result()
            self.get_logger().info(f"Response from set_led: {response.message}")
        else:
            self.get_logger().error("Service call failed")


def main(args=None):
    rclpy.init(args=args)
    node = BatteryNode() # MODIFY NAME
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
