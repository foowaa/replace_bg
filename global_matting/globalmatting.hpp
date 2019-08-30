//
//  globalmatting.hpp
//  VideoCut
//
//  Created by cltian on 2019/8/26.
//  Copyright © 2019年 cltian. All rights reserved.
//

#ifndef globalmatting_hpp
#define globalmatting_hpp

#include <stdio.h>
#include <opencv2/opencv.hpp>




void expansionOfKnownRegions(cv::InputArray img, cv::InputOutputArray trimap, int niter = 9);
void globalMatting(cv::InputArray image, cv::InputArray trimap, cv::OutputArray foreground, cv::OutputArray alpha, cv::OutputArray conf = cv::noArray());


#endif /* globalmatting_hpp */
