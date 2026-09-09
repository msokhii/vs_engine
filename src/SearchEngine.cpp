#include"SearchEngine.hpp"
#include<stdexcept>

std::size_t search_Vec(const Vector &v,const vectorDB &vdb){
    double min_Dist=0;
    double dist=0;
    double idx=0;
    for(auto i=0;i<vdb.size();++i){
        dist=euc_distance(v,vdb[i]);
        if(dist>min_Dist){ 
            min_Dist = dist;
            idx=i; 
        }
    };

    return idx;
}
