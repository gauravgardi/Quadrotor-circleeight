#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

#include <sstream>
int main(int argc, char **argv)
{
 ros::init(argc, argv, "eight2d");
 ros::NodeHandle n;
 ros::Publisher chatter_pub = n.advertise<geometry_msgs::Twist>("/quad/cmd_vel", 1000);

  ros::Rate loop_rate(100);
  int count = 0;
  while (ros::ok())
{
  geometry_msgs::Twist msg;
  msg.linear.x=1.0;
  msg.linear.y=0.0;
  msg.linear.z=0.0;
  msg.angular.x=0.0;
  msg.angular.y=0.0;
  msg.angular.z=1.0;
  if((int)(count/(200*3.14159265358979))%2==0)
  msg.angular.z=-1.0;
  chatter_pub.publish(msg);
  ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}
