#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from my_robot_interfaces.msg import HardwareStatus


class HardwareStatusPublisher(Node): # MODIFY NAME
    def __init__(self):
        super().__init__("hardware_status_publisher") # MODIFY NAME


def main(args=None):
    rclpy.init(args=args)
    node = HardwareStatusPublisher() # MODIFY NAME
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
