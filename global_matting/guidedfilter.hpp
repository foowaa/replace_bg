//
//  guidedfilter.hpp
//  VideoCut
//
//  Created by cltian on 2019/8/26.
//  Copyright © 2019年 cltian. All rights reserved.
//

#ifndef guidedfilter_hpp
#define guidedfilter_hpp

#include <stdio.h>
#include <opencv2/opencv.hpp>


class GuidedFilterImpl;

class GuidedFilter
{
public:
    GuidedFilter(const cv::Mat &I, int r, double eps);
    ~GuidedFilter();
    
    cv::Mat filter(const cv::Mat &p, int depth = -1) const;
    
private:
    GuidedFilterImpl *impl_;
};

cv::Mat guidedFilter(const cv::Mat &I, const cv::Mat &p, int r, double eps, int depth = -1);


#endif /* guidedfilter_hpp */
