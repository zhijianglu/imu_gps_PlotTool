//
// Created by lab on 2020/6/15.
//

#ifndef SRC_DRAW_H
#define SRC_DRAW_H
#include <pangolin/pangolin.h>

#include <ros/ros.h>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <geometry_msgs/Quaternion.h>
#include <geometry_msgs/Vector3.h>
#include <geometry_msgs/Vector3.h>
#include "Data.h"
#include "string"
#include "iostream"

#include <pangolin/platform.h>
#include <pangolin/gl/glinclude.h>
#include <pangolin/handler/handler_enums.h>
#include <pangolin/utils/params.h>
#include <pangolin/display/window.h>

class Draw
{
public:
    Draw(Data* data_);
    void drawThread();
    ~Draw();

    Data* data;
    pangolin::OpenGlRenderState s_cam;
    pangolin::View d_cam;

};


#endif //SRC_DRAW_H
