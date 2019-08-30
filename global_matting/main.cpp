#include <iostream>
#include <time.h>
using namespace std;

#include "globalmatting.hpp"

// you can get the guided filter implementation
// from https://github.com/atilimcetin/guided-filter
#include "guidedfilter.hpp"

int main(int argc, char *argv[])
{
    char *image_path = argv[1];
    char *mat_path = argv[2];
    char *save_path = argv[3];

    cv::Mat image = cv::imread(image_path, CV_LOAD_IMAGE_COLOR);
    cv::Mat trimap = cv::imread(mat_path, CV_LOAD_IMAGE_GRAYSCALE);

    // (optional) exploit the affinity of neighboring pixels to reduce the
    // size of the unknown region. please refer to the paper
    // 'Shared Sampling for Real-Time Alpha Matting'.
    expansionOfKnownRegions(image, trimap, 3);

    cv::Mat foreground, alpha;
    globalMatting(image, trimap, foreground, alpha);

    // filter the result with fast guided filter
    alpha = guidedFilter(image, alpha, 10, 1e-5);
    for (int x = 0; x < trimap.cols; ++x)
        for (int y = 0; y < trimap.rows; ++y)
        {
            if (trimap.at<uchar>(y, x) == 0)
                alpha.at<uchar>(y, x) = 0;
            else if (trimap.at<uchar>(y, x) == 255)
                alpha.at<uchar>(y, x) = 255;
        }

    cv::imwrite(save_path, alpha);

    return 0;
}
