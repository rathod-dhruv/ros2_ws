# ROS 2 Workspace: GhostRider

This is a complete ROS 2 workspace that contains demonstration packages written in both C++ and Python. It includes basic publisher/subscriber nodes, service client/server nodes, custom interfaces, and parameter usage examples.

## Workspace Structure

The workspace is structured into the `src` folder which contains three core packages, alongside configuration and parameter files.

```text
ros2_ws/
├── src/
│   ├── my_cpp_pkg/             # C++ based ROS 2 nodes
│   ├── my_py_pkg/              # Python based ROS 2 nodes
│   └── my_robot_interfaces/    # Custom messages and services
└── yaml_params/                # YAML configuration files for parameters
```

### 1. `my_cpp_pkg`
This package contains C++ implementations of various ROS 2 concepts.
**Key Nodes:**
- `add_two_ints_server.cpp` & `add_two_ints_client.cpp`: Demonstrates ROS 2 services (Server and Client).
- `number_publisher.cpp` & `number_counter.cpp`: Demonstrates basic ROS 2 topics with a publisher and subscriber. 
- `hardware_status_publisher.cpp`: Demonstrates using custom messages over topics.
- `robot_news_station.cpp` & `smartphone.cpp`: String publisher and subscriber communicating over a topic.

### 2. `my_py_pkg`
This package contains Python implementations of the same core ROS 2 concepts, with a few extra components.
**Key Nodes:**
- `add_two_ints_server.py` & `add_two_ints_client_oop.py`: Python Service Server and Client examples.
- `number_publisher.py` & `number_counter.py`: Python Topic examples.
- `hardware_status_publisher.py`: Python custom message publisher.
- `robot_news_station.py` & `smartphone.py`: String publisher and subscriber.
- `battery.py` & `led_panel.py`: Simulated battery system interacting with an LED panel.

### 3. `my_robot_interfaces`
This package acts as the centralized location for custom messages and services used by the C++ and Python node packages.
**Custom Messages (`msg`):**
- `HardwareStatus.msg`
- `LedStateArray.msg`

**Custom Services (`srv`):**
- `ComputeRectangleArea.srv`
- `SetLed.srv`

### 4. `yaml_params`
Contains external parameter configurations.
- `number_params.yaml`: Configurations that can be loaded into specific nodes at runtime.

## Building the Workspace

To compile the packages in this workspace, make sure you have sourced your ROS 2 installation, then build using `colcon`:

```bash
# Navigate to the workspace root
cd ~/GhostRider/ros2_ws

# Build the workspace
colcon build

# Source the newly built workspace so nodes and interfaces can be found
source install/setup.bash
```

## Running Nodes
You can run any of the configured executables from the packages using `ros2 run`:

```bash
ros2 run my_py_pkg robot_news_station
ros2 run my_cpp_pkg smartphone
```
