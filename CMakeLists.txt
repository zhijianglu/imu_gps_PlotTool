cmake_minimum_required(VERSION 2.8.3)
project(pangolin_viz)

set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS "-std=c++11")
#-DEIGEN_USE_MKL_ALL")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -Wall -g")

find_package(catkin REQUIRED COMPONENTS
        roscpp
        std_msgs
        nav_msgs
        mavros_msgs
        image_transport
        sensor_msgs
        tf
#        cv_bridge
        roslib
    )

#find_package(OpenCV 3.4.6 REQUIRED)
find_package(Pangolin REQUIRED)
find_package(Boost REQUIRED COMPONENTS filesystem program_options system)


find_package(Ceres REQUIRED)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
find_package(Eigen3)

include_directories(${catkin_INCLUDE_DIRS} ${CERES_INCLUDE_DIRS}
        ${Pangolin_INCLUDE_DIRS}
#        ${OpenCV_INCLUDE_DIRS}
        ${EIGEN3_INCLUDE_DIR})

catkin_package(

)

add_executable(pangolin_viz
        src/main_viz.cpp
        src/Draw.cpp
        src/Data.cpp
#        src/parameters.cpp
    )
target_link_libraries(pangolin_viz ${catkin_LIBRARIES} ${Pangolin_LIBRARIES}   ${CERES_LIBRARIES})


#add_executable(codetest
#        src/codetest.cpp
#        )
#target_link_libraries(codetest ${catkin_LIBRARIES} ${Pangolin_LIBRARIES}   ${CERES_LIBRARIES})
