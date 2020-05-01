#include <cmath>
#include <vector>
#include "ros/ros.h"
#include "geometry_msgs/Pose.h"
#include "std_msgs/Float32.h"

float h = 0.;
float z_eau = 2;
float R = 1;
float p = 1;
float g = 500;
float v = 0;
float m = 41.22;

void poseCallback(const geometry_msgs::Pose::ConstPtr& pose)
{
    float z = pose->position.z;
    v = pose->orientation.z;
    if(z - R > z_eau)
    {
        h = 0;
    }
    else if(z + R < z_eau)
    {
        h = 2*R;
    }
    else
    {
        h = R + z_eau - z;
    }

    std::cout << "h : " << h << " / v : " << v << std::endl;
    
}
   
int main(int argc, char **argv){

    // INITIALISATION
    ros::init(argc, argv, "water_simu");

    //DECLARATION DE SUBSCRIBERS
    ros::NodeHandle pose;
    ros::Subscriber sub1 = pose.subscribe("pose", 1000, poseCallback);

    //ros::Subscriber sub4 = vcible.subscribe("acceleration_cible", 1000, get_acceleration_cible);

    //DECLARATION DE PUBLISHERS
    
    ros::NodeHandle commande;
    ros::Publisher pub = commande.advertise<std_msgs::Float32>("force", 1000);

    std::cout << "start water_simu" << std::endl;

    float rate = 30;
    
    ros::Rate loop_rate(rate);
    while (ros::ok()){
        
        ros::spinOnce();
  
        std_msgs::Float32 f;
        float archi = p*g*M_PI*h*h/3*(3*R-h);
        float frtt = - 200*v*h - 20*v*v*h;
        //std::cout << "archi : " << archi << " / frtt : " << frtt << std::endl;
        f.data =  archi + frtt ;
        

        // PUBLICATION
        pub.publish(f);
        
        loop_rate.sleep();

    }

    }
