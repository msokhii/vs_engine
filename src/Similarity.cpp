#include "Similarity.hpp"
#include<cmath>
#include<stdexcept>

double euc_distance(const Vector &v1, const Vector &v2){
    if(v1.size()!=v2.size()){
        throw std::invalid_argument("Vectors must be the same size.");
    }
    
    double diff=0;
    double sum=0;
    
    for(auto i=0;i<v1.size();++i){
        diff=v1.at(i)-v2.at(i);
        sum=diff*diff;
    }

    return std::sqrt(sum);
}

double dot_prod(const Vector &v1, const Vector &v2){
    if(v1.size()!=v2.size()){
        throw std::invalid_argument("Vectors must be the same size.");
    }

    double mul=0;
    double sum=0;
    
    for(auto i=0;i<v1.size();++i){
        mul=v1.at(i)*v2.at(i);
        sum+=mul;
    }

    return sum;
}
