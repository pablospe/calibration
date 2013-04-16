/*********************************************************************
* Software License Agreement (BSD License)
*
*  Copyright (c) 2013, Willow Garage, Inc.
*  All rights reserved.
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions
*  are met:
*
*   * Redistributions of source code must retain the above copyright
*     notice, this list of conditions and the following disclaimer.
*   * Redistributions in binary form must reproduce the above
*     copyright notice, this list of conditions and the following
*     disclaimer in the documentation and/or other materials provided
*     with the distribution.
*   * Neither the name of the Willow Garage nor the names of its
*     contributors may be used to endorse or promote products derived
*     from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
*  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
*  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
*  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
*  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
*  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
*  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
*  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
*  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
*  POSSIBILITY OF SUCH DAMAGE.
*********************************************************************/

//! \author Pablo Speciale


#ifndef PROJECTION_H
#define PROJECTION_H

#include <opencv2/core/core.hpp>
#include <image_geometry/pinhole_camera_model.h>

namespace calib
{

/// \brief Project a 3D point into a 2D point using the camera model (cam_model)
void projectPoints(const image_geometry::PinholeCameraModel &cam_model,
                   const cv::Point3d &xyz,
                   cv::Point2d *points2D);

/// \brief Project 3D points into 2D points using the camera model (cam_model)
void projectPoints(const image_geometry::PinholeCameraModel &cam_model,
                   const std::vector<cv::Point3d> &xyz,
                   std::vector<cv::Point2d> *points2D);

/// \brief Calculate reprojection error
double computeReprojectionErrors(const std::vector<cv::Point3d> &X3D,
                                 const std::vector<cv::Point2d> &x2d,
                                 const cv::Mat &cameraMatrix,
                                 const cv::Mat &distCoeffs,
                                 const cv::Mat &rvec,
                                 const cv::Mat &tvec);

/// \brief Transform 3D points using rvec and tvec
void project3dPoints(const cv::Mat &points,
                     const cv::Mat &rvec,
                     const cv::Mat &tvec,
                     cv::Mat *modif_points );

}

#endif // PROJECTION_H

