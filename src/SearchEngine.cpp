#include"SearchEngine.hpp"
#include<stdexcept>
#include<limits>
#include<utility>
#include<vector>
#include<algorithm>

std::vector<std::pair<double,std::size_t>> knn_Search(const Vector &v,const vectorDB &vdb,const std::size_t k){
    std::vector<std::pair<double,std::size_t>> temp;
    std::vector<std::pair<double,std::size_t>> temp2;
    
    if(vdb.size()==0){
        throw std::invalid_argument("Cannot search an empty database.");
    }

    double min_Dist=std::numeric_limits<double>::infinity();;
    double dist=0;
    std::size_t idx=0;
    for(auto i=0;i<vdb.size();++i){
        dist=euc_distance(v,vdb.at(i));
        temp.push_back({dist,i});
    };

    std::sort(temp.begin(),temp.end());

    if(k<=0 || k>=temp.size()){
        throw std::invalid_argument("Check value of k.");
    }
    for(auto i=0;i<k;++i){
        temp2.push_back(temp[i]);
    }

    return temp2;
}
