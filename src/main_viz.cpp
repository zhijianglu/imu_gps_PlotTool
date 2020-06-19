/*******************************************************
 * Copyright (C) 2019, Aerial Robotics Group, Hong Kong University of Science and Technology
 * 
 * This file is part of VINS.
 * 
 * Licensed under the GNU General Public License v3.0;
 * you may not use this file except in compliance with the License.
 *
 * Author: Qin Tong (qintonguav@gmail.com)
 *******************************************************/

#include <ros/ros.h>
#include <vector>
#include <thread>
#include <condition_variable>

#include "Draw.h"
#include "Data.h"



using namespace std;

using namespace sensor_msgs;
using namespace message_filters;
using namespace geometry_msgs;

std::shared_ptr<Draw> pDraw;
Data* pData;


int main(int argc, char **argv)
{

    ros::init(argc, argv, "data_ploter");
    ros::NodeHandle n("~");
    ros::console::set_logger_level(ROSCONSOLE_DEFAULT_NAME, ros::console::levels::Info);

    pData = new Data;
    pDraw.reset(new Draw(pData));

    std::thread thd_Draw(&Draw::drawThread, pDraw);
//    thd_Draw.join();

    ros::Subscriber imu_sub = n.subscribe<sensor_msgs::Imu>("/lauv/imu", 10, &Data::imu_callback, pData);
    ros::Subscriber gps_sub = n.subscribe<sensor_msgs::NavSatFix>("/lauv/gps", 10, &Data::gps_callback, pData);

    ros::spin();

    delete pData;

    return 0;
}
