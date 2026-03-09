#!/usr/bin/env python3
from functools import partial

import rclpy
from rclpy.node import Node
from my_robot_interfaces.msg import LedStateArray
from my_robot_interfaces.srv import SetLed


class LEDPanelNode(Node):
    def __init__(self):
        super().__init__("led_panel_client")
        self.led_states_ = [0,0,0]
        self.led_state_publisher = self.create_publisher(LedStateArray, "led_states", 10)
        self.led_states_timer = self.create_timer(4.0, self.publish_led_states)
        self.set_led_service = self.create_service(SetLed, "set_led", self.callback_set_led)
        self.get_logger().info("LED Panel Node has been started.")

    def publish_led_states(self):
        msg = LedStateArray()
        msg.led_states = self.led_states_
        self.led_state_publisher.publish(msg)
    
    def callback_set_led(self, request: SetLed.Request, response:SetLed.Response):
        led_number = request.led_number
        state = request.state

        if(led_number < 0 or led_number >= len(self.led_states_)):
            response = SetLed.Response()
            response.message = f"Invalid LED number: {led_number}"
            return response
        
        if state not in [0, 1]:
            response = SetLed.Response()
            response.message = f"Invalid state: {state}. State must be 0 or 1."
            return response
    
        self.led_states_[led_number] = state
        self.publish_led_states()  # Publish the updated LED states immediately after changing one
        response = SetLed.Response()
        response.message = f"LED {led_number} set to {'ON' if state == 1 else 'OFF'}"
        return response
                



def main(args=None):
    rclpy.init(args=args)
    node = LEDPanelNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
