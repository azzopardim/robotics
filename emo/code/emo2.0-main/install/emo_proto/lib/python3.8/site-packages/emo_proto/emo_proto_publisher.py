# Copyright 2021 Michael Azzopardi
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import rclpy
from rclpy.node import Node

from std_msgs.msg import String


class ProtoPublisher(Node):

    # Define node init
    def __init__(self):
        super().__init__('emo_proto_publisher')

        # Create publisher
        self.publisher_ = self.create_publisher(String, 'proximity', 10)

        # Setting frequency of publisher
        timer_period = 0.5  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.i = 0

    def timer_callback(self):
        msg = String()
        msg.data = 'emo: %d' % self.i
        self.publisher_.publish(msg)
        self.get_logger().info('Publishing: "%s"' % msg.data)
        self.i += 1


def main(args=None):
    # Node initialisation
    rclpy.init(args=args)

    # Instantiate node
    emo_proto_publisher = ProtoPublisher()

    # Spin instance of node
    rclpy.spin(emo_proto_publisher)

    # Destroy the node explicitly
    emo_proto_publisher.destroy_node()

    # Shut down context
    rclpy.shutdown()

if __name__ == '__main__':
    main()
