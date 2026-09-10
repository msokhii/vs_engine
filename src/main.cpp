#include<iostream>
#include<vector>
#include<utility>
#include<string>

#include"Vector.hpp"
#include"Similarity.hpp"
#include"vectorDB.hpp"
#include"SearchEngine.hpp"
#include"FileLoader.hpp"

int main(){
    std::string file_Name="/home/msokhi/Desktop/vs_engine/data/vectors.txt";
    vectorDB db=construct_DB(file_Name);

    std::vector<double> q1={4.1,2.2};
    Vector qV(q1);

    qV.print_Vec();
    std::vector<std::pair<double,std::size_t>> res=knn_Search(q1,db,2);

    for(auto i=0;i<res.size();++i){
        std::cout<<"Distance -> "<<res[i].first<<" Index -> "<<res[i].second<<'\n';
    }
    
    return 0;
}
