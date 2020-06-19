//
// Created by lab on 2020/6/15.
//

#include "Data.h"
Data::Data()
{
     acc = Vector3d(0,0,0);
     gyr = Vector3d(0,0,0);
}

Data::~Data()
{

}

void
Data::imu_callback(const sensor_msgs::ImuConstPtr &imu_msg){

//    cout<<acc<<endl;

    m_data.lock();

    acc = Vector3d(imu_msg->linear_acceleration.x,
                   imu_msg->linear_acceleration.y,
                   imu_msg->linear_acceleration.z
    );

    gyr = Vector3d(imu_msg->angular_velocity.x,
                   imu_msg->angular_velocity.y,
                   imu_msg->angular_velocity.z);

    m_data.unlock();

//    estimator.inputIMU(t, acc, gyr);

}
void
Data::gps_callback(const sensor_msgs::NavSatFix::ConstPtr& navsatfix)
{
    m_data.lock();

    GPS.x() = navsatfix->latitude;
    GPS.y() = navsatfix->longitude;
    GPS.z() = navsatfix->altitude;
    m_data.unlock();

//    printf("%f %f %f\n", navsatfix->latitude, navsatfix->longitude, navsatfix->altitude);
}