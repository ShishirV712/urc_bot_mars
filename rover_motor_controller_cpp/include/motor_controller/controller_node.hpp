// MIT License

// Copyright (c) 2023 Miguel Ángel González Santamarta

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef CONTROLLER_NODE_HPP
#define CONTROLLER_NODE_HPP

#include <memory>

#include "rclcpp/rclcpp.hpp"

#include "lx16a/motor_controller.hpp"
#include "rover_msgs/msg/motors_command.hpp"

namespace motor_controller {

class ControllerNode : public rclcpp::Node {
public:
  ControllerNode();
  void callback(const rover_msgs::msg::MotorsCommand::SharedPtr msg);
  void shutdown();

private:
  std::unique_ptr<lx16a::MotorController> motor_controller;
  rclcpp::Subscription<rover_msgs::msg::MotorsCommand>::SharedPtr subscription;
};

} // namespace motor_controller
#endif
