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

double cos_sim(const Vector &v1, const Vector &v2){
    if(v1.size()!=v2.size()){
        throw std::invalid_argument("Vectors must be the same size.");
    }

    double sum1=0;
    double sum2=0;
    double dot_prod=0;
    
    for(auto i=0;i<v1.size();++i){
        sum1+=v1.at(i)*v1.at(i);
        sum2+=v2.at(i)*v2.at(i);

        dot_prod+=v1.at(i)*v2.at(i);
    }

    double norm1=0;
    double norm2=0;
    norm1=std::sqrt(sum1);
    norm2=std::sqrt(sum2);

    if(norm1==0 || norm2==0){
        throw std::invalid_argument("Division by zero");
    }

    double res=dot_prod/(norm1*norm2);
    return res;
}
