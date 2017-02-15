#include <opencv2/opencv.hpp>

void findHeads(const cv::String video_file, const cv::String cascade_file);

int main() {
    findHeads("hockey_game.avi", "heads_cascade.xml");
    return 0;
}

void findHeads(const cv::String video_file, const cv::String cascade_file) {
    cv::VideoCapture videoCapture(video_file);
    cv::Mat img_input;

    while (true) {
        bool isSuccess = videoCapture.read(img_input);

        if (!isSuccess) {
            break;
        }

        int width = 600;
        int fps = (int) videoCapture.get(CV_CAP_PROP_FPS);

        // Resize the frame.
        cv::resize(img_input, img_input,
                   cv::Size(width, (int) ((float) width / (int) videoCapture.get(CV_CAP_PROP_FRAME_WIDTH) *
                                          (int) videoCapture.get(CV_CAP_PROP_FRAME_HEIGHT))));

        cv::CascadeClassifier heads_cascade;
        heads_cascade.load(cascade_file);

        std::vector<cv::Rect> heads;
        heads_cascade.detectMultiScale(img_input, heads, 1.1, 2, 0, cv::Size(20, 20), cv::Size(40, 40));

        // Draw squares on the detected heads.
        for (int i = 0; i < heads.size(); i++) {
            cv::rectangle(img_input, heads[i], cv::Scalar(0, 255, 255), 1);
        }

        cv::imshow("HaarCascadeCV", img_input);
        int code = cv::waitKey(fps);

        // If user presses 'SPACE', then pause video.
        if (code == 32) {
            cv::waitKey(0);

            // If user presses 'ESC', then terminate video.
        } else if (code == 27) {
            break;
        }
    }
}