#!/usr/bin/env python3
from functools import partial
import math

import rclpy
from rclpy.node import Node
from turtlesim.msg import Pose
from geometry_msgs.msg import Twist

from turtle_catch_all_interfaces.msg import Turtle
from turtle_catch_all_interfaces.msg import TurtleArray
from turtle_catch_all_interfaces.srv import CatchTurtle

class TurtleControllerNode(Node): # MODIFY NAME
    def __init__(self):
        super().__init__("turtle_controller") # MODIFY NAME
        self.turtle_to_catch_ : Turtle = None
        self.pose_ : Pose = None
        self.cmd_vel_publisher = self.create_publisher(Twist, "/turtle1/cmd_vel", 10)
        self.pose_subscriber = self.create_subscription(Pose, "/turtle1/pose", self.callback_pose, 10)

        self.alive_turtles_subscriber_ = self.create_subscription(TurtleArray, "alive_turtles", self.callback_alive_turtles, 10)
        self.catch_turtle_client = self.create_client(CatchTurtle, "catch_turtle")

        self.control_loop_timer = self.create_timer(0.01, self.control_loop) # 100 Hz control loop
    
    
    def callback_pose(self, msgPose : Pose):
        # Handle the received pose message
        self.pose_ = msgPose

    def callback_alive_turtles(self, msg : TurtleArray):
        if len(msg.turtles) > 0:
            self.turtle_to_catch_ = msg.turtles[0]
            


    def control_loop(self):
        if self.pose_ is None or self.turtle_to_catch_ is None:
            return
        dist_x = self.turtle_to_catch_.x - self.pose_.x
        dist_y = self.turtle_to_catch_.y - self.pose_.y
        distance = math.sqrt(dist_x*dist_x + dist_y*dist_y)

        cmd = Twist()
        if distance > 0.5:
            #multiply by 2 to get a good speed, we can adjust this value as needed
            cmd.linear.x = 1.0 * distance

            goal_theta = math.atan2(dist_y, dist_x)
            diff = goal_theta - self.pose_.theta

            if diff > math.pi:
                diff -= 2*math.pi
            elif diff < -math.pi:
                diff += 2*math.pi
            # multiply by 6 to get a good turning speed, we can adjust this value as needed
            cmd.angular.z = 6 * diff
        else:
            cmd.linear.x = 0.0
            cmd.angular.z = 0.0
            self.call_catch_turtle_service(self.turtle_to_catch_.name)
            self.turtle_to_catch_ = None

        self.cmd_vel_publisher.publish(cmd)

    def call_catch_turtle_service(self, turtle_name):
        while not self.catch_turtle_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info("Waiting for catch_turtle service...")

        request = CatchTurtle.Request()
        request.name = turtle_name

        future = self.catch_turtle_client.call_async(request)
        future.add_done_callback(
            partial(self.callback_call_catch_turtle_service, request = request))
        
    def callback_call_catch_turtle_service(self, future, request):
        response: CatchTurtle.Response = future.result()
        if response.success:
            self.get_logger().info(f"Called catch_turtle service for turtle: {request.name}")
            self.turtle_to_catch_ = None
     

def main(args=None):
    rclpy.init(args=args)
    node = TurtleControllerNode() # MODIFY NAME
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
