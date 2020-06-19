//
// Created by lab on 2020/6/15.
//

#include "Draw.h"


Draw::Draw(Data* data_){
    data = data_;
}


Draw::~Draw()
{

}

//void
//Draw::drawThread()
//{
//    int width = 752 * 2;
//    int height = 480 * 2;
//
//
//    pangolin::CreateWindowAndBind("DM_SVI_SLAM Trajectory Viewer", 1024, 768);
//    glEnable(GL_DEPTH_TEST);
//    glEnable(GL_BLEND);
//    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//
//    s_cam = pangolin::OpenGlRenderState(
//        pangolin::ProjectionMatrix(1024, 768, 500, 500, 512, 384, 0.1, 1000),
//        pangolin::ModelViewLookAt(-5, 0, 15, 7, 0, 0, 1.0, 0.0, 0.0)
//    );
//
//
//    d_cam = pangolin::CreateDisplay()
//        .SetBounds(0.0, 1.0, pangolin::Attach::Pix(175), 1.0, -1024.0f / 768.0f)
//        .SetHandler(new pangolin::Handler3D(s_cam));
//
//
//    pangolin::OpenGlRenderState s_cam(
//        pangolin::ProjectionMatrix(1024, 768, 500, 500, 512, 384, 0.1, 1000),
//        pangolin::ModelViewLookAt(-5, 0, 15, 7, 0, 0, 1.0, 0.0, 0.0)
//    );
//
//    pangolin::View &d_cam = pangolin::CreateDisplay()
//        .SetBounds(0.0, 1.0, pangolin::Attach::Pix(175), 1.0, -1024.0f / 768.0f)
//        .SetHandler(new pangolin::Handler3D(s_cam));
//
//    pangolin::View &track_img = pangolin::Display("image_1")
//        .SetBounds(2 / 3.0f, 1.0f, 0., 1 / 3.0f, double(width) / double(height))
//        .SetLock(pangolin::LockLeft, pangolin::LockBottom);
//
//
//    // 创建glTexture容器用于读取图像
//
//    pangolin::GlTexture TrackimageTexture(width, height, GL_RGB, false, 0, GL_RGB, GL_UNSIGNED_BYTE);
//    pangolin::GlTexture LoopimageTexture(width, height, GL_RGB, false, 0, GL_RGB, GL_UNSIGNED_BYTE);
//
//    cv::Mat img2show;
//    while (pangolin::ShouldQuit() == false)
//    {
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//        d_cam.Activate(s_cam);
//        glClearColor(0.0f, 0.0f, 0.0f, 0.75f);
//        glColor3f(0, 1, 0);
//        pangolin::glDrawAxis(3);
//
//        if (data->solver_flag == "NON_LINEAR")
//        {
//            //todo draw old path estimating
//            glColor3f(0.0f, 0.0f, 1.0f);
//            glLineWidth(2);
//            glBegin(GL_LINES);
//
//            int nPath_size = data->vPath_to_draw.size();
//            for (int i = 0; i < nPath_size - 1; ++i)
//            {
//                glVertex3f(data->vPath_to_draw[i].x(), data->vPath_to_draw[i].y(), data->vPath_to_draw[i].z());
//                glVertex3f(data->vPath_to_draw[i + 1].x(),
//                           data->vPath_to_draw[i + 1].y(),
//                           data->vPath_to_draw[i + 1].z());
//            }
//
//
//            glEnd();
//
//            //todo draw old position
//            glPointSize(10);
//            glBegin(GL_POINTS);
//
//            for (auto &it:data->vPath_stamped)
//            {
//                Vector3d p_wi = it.second;
//                glColor3f(0.0, 0.0, 1.0);
//                glVertex3d(p_wi[0], p_wi[1], p_wi[2]);
//            }
//
//            glEnd();
//
//            //TODO draw old camera
//            Matrix3d R = data->Rs[WINDOW_SIZE];
//            Vector3d pos = data->Ps[WINDOW_SIZE];
//
//            glPushMatrix();
//            std::vector<GLdouble>
//                Twc = {data->current_Rot(0, 0), data->current_Rot(1, 0), data->current_Rot(2, 0), 0.,
//                       data->current_Rot(0, 1), data->current_Rot(1, 1), data->current_Rot(2, 1), 0.,
//                       data->current_Rot(0, 2), data->current_Rot(1, 2), data->current_Rot(2, 2), 0.,
//                       pos.x(), pos.y(), pos.z(), 1.};
//            glMultMatrixd(Twc.data());
//            // 绘制相机轮廓线
//            const float w = 0.2;
//            const float h = w * 0.75;
//            const float z = w * 0.6;
//
//            glLineWidth(2);
//            glBegin(GL_LINES);
//            glColor3f(0.0f, 0.0f, 1.0f); //(GLfloat red, GLfloat green, GLfloat blue);
//            glVertex3f(0, 0, 0);
//            glVertex3f(w, h, z);
//            glVertex3f(0, 0, 0);
//            glVertex3f(w, -h, z);
//            glVertex3f(0, 0, 0);
//            glVertex3f(-w, -h, z);
//            glVertex3f(0, 0, 0);
//            glVertex3f(-w, h, z);
//            glVertex3f(w, h, z);
//            glVertex3f(w, -h, z);
//            glVertex3f(-w, h, z);
//            glVertex3f(-w, -h, z);
//            glVertex3f(-w, h, z);
//            glVertex3f(w, h, z);
//            glVertex3f(-w, -h, z);
//            glVertex3f(w, -h, z);
//            glEnd();
//            glPopMatrix();
//
//        }
//
//        //todo draw loop_path
//
//        if (data->solver_flag == "NON_LINEAR")
//        {
//            // todo modified loop_path
//            glColor3f(1.0f, 0.0f, 0.0f);
//            glLineWidth(8);
//            glBegin(GL_LINES);
//
//            Vector3d last_pos = Vector3d(0, 0, 0);
//            Vector3d current_pos = Vector3d(0, 0, 0);
//
//            for (auto &it:data->loop_path)
//            {
//                current_pos = it.second.second;
//                glVertex3f(last_pos.x(),
//                           last_pos.y(),
//                           last_pos.z());
//
//                glVertex3f(current_pos.x(), current_pos.y(), current_pos.z());
//                last_pos = current_pos;
//            }
//            glEnd();
//
//
//            //TODO draw loop camera pose
//
//            glPushMatrix();
//            std::vector<GLdouble> Twc_loop =
//                {data->current_Rot_rct(0, 0), data->current_Rot_rct(1, 0), data->current_Rot_rct(2, 0), 0.,
//                 data->current_Rot_rct(0, 1), data->current_Rot_rct(1, 1), data->current_Rot_rct(2, 1), 0.,
//                 data->current_Rot_rct(0, 2), data->current_Rot_rct(1, 2), data->current_Rot_rct(2, 2), 0.,
//                 current_pos.x(), current_pos.y(), current_pos.z(), 1.};
//            glMultMatrixd(Twc_loop.data());
//            // 绘制相机轮廓线
//            const float w = 0.2;
//            const float h = w * 0.75;
//            const float z = w * 0.6;
//
//            glLineWidth(4);
//            glBegin(GL_LINES);
//            glColor3f(1.0f, 0.0f, 0.0f);//(GLfloat red, GLfloat green, GLfloat blue);
//            glVertex3f(0, 0, 0);
//            glVertex3f(w, h, z);
//            glVertex3f(0, 0, 0);
//            glVertex3f(w, -h, z);
//            glVertex3f(0, 0, 0);
//            glVertex3f(-w, -h, z);
//            glVertex3f(0, 0, 0);
//            glVertex3f(-w, h, z);
//            glVertex3f(w, h, z);
//            glVertex3f(w, -h, z);
//            glVertex3f(-w, h, z);
//            glVertex3f(-w, -h, z);
//            glVertex3f(-w, h, z);
//            glVertex3f(w, h, z);
//            glVertex3f(-w, -h, z);
//            glVertex3f(w, -h, z);
//            glEnd();
//            glPopMatrix();
//
//            //todo draw point cloud
//
//            glPointSize(1);  //rect points
//            glBegin(GL_POINTS);
//            for (auto &it:data->rect_point_buf)
//            {
//                for (int i = 0; i < it.second.size(); ++i)
//                {
//                    Vector3d p_3d = it.second[i];
//                    glColor3f(0.0, 1.0, 0.0);
//                    glVertex3d(p_3d[0], p_3d[1], p_3d[2]);
//                }
//            }
//            glEnd();
//
//            glPointSize(2);
//            glBegin(GL_POINTS);
//            for (auto &it:data->marged_point_buf)
//            {
//                for (int i = 0; i < it.second.size(); ++i)
//                {
//                    Vector3d p_3d = it.second[i];
//                    glColor3f(1.0, 1.0, 1.0);
//                    glVertex3d(p_3d[0], p_3d[1], p_3d[2]);
//                }
//            }
//            glEnd();
//
//
//            //todo draw coordinate match loop frame
//            if (data->hasloop)
//            {
//
//
//                glColor3f(0.0f, 1.0f, 1.0f);
//                glLineWidth(6);
//                glBegin(GL_LINES);
//
//                for (auto &it:data->loop_links)
//                {
//                    glVertex3f(it.second.first.x(), it.second.first.y(), it.second.first.z());
//                    glVertex3f(it.second.second.x(),
//                               it.second.second.y(),
//                               it.second.second.z());
//                }
//                glEnd();
//
//            }
//
//        }
//
//        //TODO draw pics
//        data->m_data.lock();
//
//        if (data->shouldUpdate)
//        {
//            data->shouldUpdate = false;
//            data->show_img.copyTo(img2show);
//        }
//
//        TrackimageTexture.Upload(img2show.data, GL_BGR, GL_UNSIGNED_BYTE);
//        data->m_data.unlock();
//
//        track_img.Activate();
//        glColor3f(1.0f, 1.0f, 1.0f);
//        TrackimageTexture.RenderToViewportFlipY(); // 需要反转Y轴，否则输出是倒着的
//
//        pangolin::FinishFrame();
//        usleep(5000);   // sleep 5 ms
//    }
//    pangolin::DestroyWindow("DM_SVI_SLAM Trajectory Viewer");
//
//}

void
Draw::drawThread()
{
    pangolin::CreateWindowAndBind("Main",640,480);

    // Data logger object
    pangolin::DataLog log;

    // Optionally add named labels
    std::vector<std::string> labels;
    labels.push_back(std::string("IMU.gyr_x"));
    labels.push_back(std::string("IMU.gyr_y"));
    labels.push_back(std::string("IMU.gyr_z"));

    labels.push_back(std::string("IMU.acc_x"));
    labels.push_back(std::string("IMU.acc_y"));
    labels.push_back(std::string("IMU.acc_z"));

    labels.push_back(std::string("GPS.latitude"));
    labels.push_back(std::string("GPS.longitude"));
    labels.push_back(std::string("GPS.altitude"));

    log.SetLabels(labels);

    const float tinc = 0.01f; //横轴步长

    // OpenGL 'view' of data. We might have many views of the same data.
    pangolin::Plotter plotter(&log, 0.0f, 10*32.0f * (float) M_PI / tinc, -2.0f, 2.0f, (float) M_PI / (4.0f * tinc), 0.5f);
    plotter.SetBounds(0.0, 1.0, 0.0, 1.0);
    plotter.Track("$i");
//    plotter.SetTicks();

    // Add some sample annotations to the plot
    plotter.AddMarker(pangolin::Marker::Vertical,   -1000, pangolin::Marker::LessThan, pangolin::Colour::Blue().WithAlpha(0.2f) );
    plotter.AddMarker(pangolin::Marker::Horizontal,   100, pangolin::Marker::GreaterThan, pangolin::Colour::Red().WithAlpha(0.2f) );
    plotter.AddMarker(pangolin::Marker::Horizontal,    10, pangolin::Marker::Equal, pangolin::Colour::Green().WithAlpha(0.2f) );

    pangolin::DisplayBase().AddDisplay(plotter);

    float t = 0;

    // Default hooks for exiting (Esc) and fullscreen (tab).
    while( !pangolin::ShouldQuit() )
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        log.Log(data->gyr.x(), data->gyr.y(), data->gyr.z(),
                data->acc.x(), data->acc.y(), data->acc.z(),
                data->GPS.x(), data->GPS.y(), data->GPS.z()
                );

        t += tinc;

        // Render graph, Swap frames and Process Events
        pangolin::FinishFrame();
        usleep(5000);   // sleep 5 ms
    }

    pangolin::DestroyWindow("Main");
//    pangolin::Quit();
}
