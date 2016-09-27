#include "ros/ros.h"
#include <ros/rate.h>
#include <ros/node_handle.h>

#include "babbling_module/modules_finder.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "babbling_module_node");
  ros::NodeHandle n("babbling_module");
  ros::NodeHandle private_node_handle("~");

  ModulesFinder mf(&n);

  std::string iface;
  private_node_handle.param<std::string>("iface",iface,std::string("wlan0"));
  mf.setInterface(iface);

  int port;
  private_node_handle.param<int>("port",port,LOCAL_UDP_PORT);
  mf.setLocalPort(port);

  int dist_port;
  private_node_handle.param<int>("dist_port",dist_port,ARDUINO_UDP_PORT);
  mf.setDistantPort(port);

  mf.open();

  ros::Rate rate(1);
  mf.start();
  
  while(ros::ok()) {
    mf.scan();
    ros::spinOnce();
    rate.sleep();
  }
  
  mf.stop();

  mf.close();

  return 0;
}