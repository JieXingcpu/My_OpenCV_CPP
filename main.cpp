#include <opencv2/opencv.hpp>
#include <iostream>
int main()
{
    cv::VideoCapture camera(0);
    camera.set(cv::CAP_PROP_FRAME_WIDTH, 640);
    camera.set(cv::CAP_PROP_FRAME_HEIGHT, 480);
    cv::Mat video;
    // cv::Mat gray_video;
    if(camera.isOpened()==false){
        std::cout<<"无法打开摄像头"<<std::endl;
    }
    else{
        cv::namedWindow("camera",cv::WINDOW_FREERATIO);
        camera>>video;
        while(camera.read(video)){
            camera>>video;
            cv::cvtColor(video,gray_video,cv::COLOR_BGR2GRAY);
            cv::imshow("camera",gray_video);
            if(cv::waitKey(20)==27){
                break;
            }
        }

    }
}

