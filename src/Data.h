//
// Created by lab on 2020/6/15.
//

#ifndef SRC_DATA_H
#define SRC_DATA_H

//#include <opencv2/core/eigen.hpp>
#include <eigen3/Eigen/Dense>


#include <ros/ros.h>
#include <nav_msgs/Odometry.h>
#include <nav_msgs/Path.h>
#include <sensor_msgs/PointCloud.h>
#include <sensor_msgs/image_encodings.h>
#include <visualization_msgs/Marker.h>
#include <visualization_msgs/MarkerArray.h>

#include <sensor_msgs/Imu.h>
#include <sensor_msgs/NavSatFix.h>

#include <std_msgs/Bool.h>
#include <message_filters/subscriber.h>
#include <message_filters/time_synchronizer.h>
#include <message_filters/sync_policies/approximate_time.h>
#include <ros/package.h>

#include <stdio.h>
#include <queue>
#include <map>
#include <thread>
#include <mutex>
#include <fstream>
#include <condition_variable>
#include <iostream>
#include <sensor_msgs/NavSatFix.h>
#include <mavros_msgs/State.h>  //此次需要订阅的消息体的头文件


using namespace std;
using namespace sensor_msgs;
using namespace message_filters;
using namespace Eigen;


class Data
{
public:
    Data();
    ~Data();


    std::mutex m_data;

    Vector3d acc;
    Vector3d gyr;
    Vector3d GPS;


    void imu_callback(const sensor_msgs::ImuConstPtr &imu_msg);
    void gps_callback(const sensor_msgs::NavSatFix::ConstPtr& navsatfix);

};


#endif //SRC_DATA_H
