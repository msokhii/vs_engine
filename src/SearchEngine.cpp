#include"SearchEngine.hpp"
#include"Document.hpp"
#include<stdexcept>
#include<limits>
#include<utility>
#include<vector>
#include<algorithm>
#include<queue>

std::vector<std::pair<double,std::size_t>> knn_Search(const Vector &v,
const vectorDB &vdb,const std::size_t k){
    std::vector<std::pair<double,std::size_t>> temp;
    std::vector<std::pair<double,std::size_t>> temp2;
    
    if(vdb.size()==0){
        throw std::invalid_argument("Cannot search an empty database.");
    }

    if(k<=0 || k>=vdb.size()){
        throw std::invalid_argument("Cannot search an empty databse.");
    }

    double min_Dist=std::numeric_limits<double>::infinity();;
    double dist=0;
    std::size_t idx=0;
    for(auto i=0;i<vdb.size();++i){
        dist=euc_distance(v,vdb.at(i).get_emb());
        temp.push_back({dist,i});
    };

    std::sort(temp.begin(),temp.end());

    for(auto i=0;i<k;++i){
        temp2.push_back(temp[i]);
    }

    return temp2;
}

std::vector<std::pair<double,std::size_t>> heap_knn_Search(const Vector &v,
const vectorDB &vdb,const std::size_t k){
    if(vdb.size()==0){
        throw std::invalid_argument("Cannot search an empty database.");
    }
    if(k==0 || k>=vdb.size()){
        throw std::invalid_argument("Cannot search an empty database.");
    }
    
    double dist=0;
    std::priority_queue<std::pair<double,std::size_t>> pq;
    for(auto i=0;i<vdb.size();++i){
        dist=euc_distance(v,vdb.at(i).get_emb());
        if(pq.size()<k){
            pq.push({dist,i});
        }
        else if(dist<pq.top().first){
            pq.pop();
            pq.push({dist,i});
        }
    }

    std::priority_queue<std::pair<double,std::size_t>> temp(pq);
    std::vector<std::pair<double,std::size_t>> res;
    for(auto i=0;i<k;++i){
        res.push_back(temp.top());
        temp.pop();
    }

    std::reverse(res.begin(),res.end());

    return res;
}
