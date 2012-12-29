#ifndef SSA_H_
#define SSA_H_


#include<opencv/cv.h>

// Base class for SubSpace Analysis(SSA)
//
//

class SSA
{

  public:
    SSA(){};
    SSA(std::vector<cv::Mat>& input_data,int& ss_dim);
    virtual ~SSA(){};
    void calcDataMat(std::vector<cv::Mat>& input_data,cv::Mat& data_mat);
    void calcDataMatMean(cv::Mat& data,cv::Mat& mean);

    cv::Mat data;
    cv::Mat eigenvals;
    std::vector<cv::Mat> eigenvecs;
    cv::Mat mean;
    int dimension;
};


class LDA:public SSA
{

  public:
    LDA(){};
    LDA(std::vector<cv::Mat>& input_data,std::vector<int>& input_labels,int& ss_dim);
    virtual ~LDA(){};

    void calcClassMean(cv::Mat& data_mat,std::vector<int>& label_vec,std::vector<cv::Mat>&  mean_vec);

    std::vector<cv::Mat> class_means;
};


#endif
