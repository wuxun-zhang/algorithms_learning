#ifndef _COMMON_H_
#define _COMMON_H_

namespace common{

template<typename Dtype>
void printVector1D(std::vector<Dtype>& num){
    for(int i=0;i<num.size(); i++){
        std::cout<<num[i]<<" ";
    }
    std::cout<<std::endl;
}

template<typename Dtype>
void printVector2D(std::vector<std::vector<Dtype> >& num){
    int m = num.size();
    int n = num[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            std::cout<<num[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}



} // namespace commmon
#endif
