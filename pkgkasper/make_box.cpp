#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <turtlesim/TeleportAbsolute.h>
#include <turtlesim/SetPen.h>
#include <iostream>
#include <stdlib.h>
/* srand, rand */
#include <time.h>
using namespace std;

int main(int argc, char *argv[])
{
  ros::init(argc, argv, "move_turtlesim");

  float box_size = ros::param::param("~box_size", 9.0);

  int width = 0;
  float offset = 5.5f;
  int red = 0;
  int blue = 0;
  int green = 0;
  int square =0;
  int shape =0;

  std::cout << "" << endl;
  std::cout << "Choose if you want hexagon, square or triangle:" << endl;
  std::cout << "Press 1 for hexagon, 2 for square and 3 for triange." << endl;
  std::cin >> shape;
  std::cout << "" << endl;
  std::cout << "Define the width of the shape:";
  std::cin >> width;
  std::cout << "" << endl;
  std::cout << "Now you have to decide how much you want of the colors"<< endl;
  std::cout << "green, blue and red between 1 and 255 you want. The magnitude of" << endl;
  std::cout << "colors will be combined into one color." << endl;
  std::cout << "" << endl;
  std::cout << "Define color - how much green between 1 and 255?: ";
  std::cin >> green;
  std::cout << "Define color - how much blue between 1 and 255?: ";
  std::cin >> blue;
  std::cout << "Define color - how much red between 1 and 255?: ";
  std::cin >> red;
  std::cout << "" << endl;
  std::cout << "Congratulations you made a cage for the turtle!: ";
  std::cout << "The width is: " << width << std::endl;
  std::cout << "The amount of Red is: " << red << std::endl;
  std::cout << "The amount of Blue is: " << blue << std::endl;
  std::cout << "The amount of Green is: " << green << std::endl;

/*
Generate random numbers
*/
/*
  srand (time(NULL));
  width = rand() % 10 + 1;
  red = rand() % 255 + 1;
  green = rand() % 255 + 1;
  blue = rand() % 255 + 1;
*/
  ros::NodeHandle nh;

  ros::service::waitForService("/turtle1/teleport_absolute", -1);

  ros::ServiceClient teleport_client = nh.serviceClient<turtlesim::TeleportAbsolute>("/turtle1/teleport_absolute");
  ros::ServiceClient pen_client = nh.serviceClient<turtlesim::SetPen>("/turtle1/set_pen");


  turtlesim::SetPen pen_srv;
  pen_srv.request.off = true;
  pen_client.call(pen_srv);

  turtlesim::TeleportAbsolute srv;

  if (shape==1)
  {
  srv.request.x = offset;
  srv.request.y = offset + box_size/2;
  teleport_client.call(srv);

  pen_srv.request.off = false;
  pen_srv.request.width = width;
  pen_srv.request.r = red;
  pen_srv.request.g = green;
  pen_srv.request.b = blue;
  pen_client.call(pen_srv);

  srv.request.x = offset-box_size/2;
  srv.request.y = offset+box_size/4;
  teleport_client.call(srv);

  srv.request.x = offset-box_size/2;
  srv.request.y = offset-box_size/4;
  teleport_client.call(srv);

  srv.request.x = offset;
  srv.request.y = offset-box_size/2;
  teleport_client.call(srv);

  srv.request.x = offset+box_size/2;
  srv.request.y = offset-box_size/4;
  teleport_client.call(srv);

  srv.request.x = offset+box_size/2;
  srv.request.y = offset+box_size/4;
  teleport_client.call(srv);

  srv.request.x = offset;
  srv.request.y = offset + box_size/2;
  teleport_client.call(srv);

  pen_srv.request.off = true;
  pen_client.call(pen_srv);

  srv.request.x = offset;
  srv.request.y = offset;
  teleport_client.call(srv);

  pen_srv.request.off = false;
  pen_srv.request.width = 4;
  pen_srv.request.r = red;
  pen_srv.request.g = green;
  pen_srv.request.b = blue;
  pen_client.call(pen_srv);
  }

  if (shape==2)
  {
  srv.request.x = 5.5-box_size/2;
  srv.request.y = 5.5-box_size/2;
  teleport_client.call(srv);

  pen_srv.request.off = false;
  pen_srv.request.width = width;
  pen_srv.request.r = red;
  pen_srv.request.g = green;
  pen_srv.request.b = blue;
  pen_client.call(pen_srv);


  srv.request.x = offset-box_size/2;
  srv.request.y = offset+box_size/2;
  teleport_client.call(srv);

  srv.request.x = offset+box_size/2;
  srv.request.y = offset+box_size/2;
  teleport_client.call(srv);

  srv.request.x = offset+box_size/2;
  srv.request.y = offset-box_size/2;
  teleport_client.call(srv);

  srv.request.x = offset-box_size/2;
  srv.request.y = offset-box_size/2;
  teleport_client.call(srv);

  pen_srv.request.off = true;
  pen_client.call(pen_srv);

  srv.request.x = offset;
  srv.request.y = offset;
  teleport_client.call(srv);

  pen_srv.request.off = false;
  pen_srv.request.width = 4;
  pen_srv.request.r = red;
  pen_srv.request.g = green;
  pen_srv.request.b = blue;
  pen_client.call(pen_srv);
  }

  if (shape==3)
  {
  srv.request.x = offset+box_size/2;
  srv.request.y = offset+box_size/2;
  teleport_client.call(srv);

  srv.request.x = offset+box_size/2;
  srv.request.y = offset-box_size/2;
  teleport_client.call(srv);

  srv.request.x = offset-box_size/2;
  srv.request.y = offset-box_size/2;
  teleport_client.call(srv);

  pen_srv.request.off = true;
  pen_client.call(pen_srv);

  srv.request.x = offset;
  srv.request.y = offset;
  teleport_client.call(srv);

  pen_srv.request.off = false;
  pen_srv.request.width = 4;
  pen_srv.request.r = red;
  pen_srv.request.g = green;
  pen_srv.request.b = blue;
  pen_client.call(pen_srv);
  }

return 0;
}