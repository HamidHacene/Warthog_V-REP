#!/usr/bin/env python
# license removed for brevity
import rospy
from geometry_msgs.msg import Twist
from std_msgs.msg import Float32



def callback(data):

    lin = data.linear.z
    ang = data.angular.z

    force = Float32()
    force.data = 0

    f.publish(force)


def transcript():
    global avg, avd, arg, ard
    f = rospy.Publisher('vrep_sphere', Float32, queue_size=10)
    rospy.Subscriber("pose", Twist, callback)

    rospy.init_node('keyboard_transcript', anonymous=True)
    rate = rospy.Rate(10)  # 10hz

    while not rospy.is_shutdown():
        rate.sleep()


if __name__ == '__main__':
    try:
        transcript()
    except rospy.ROSInterruptException:
        pass
