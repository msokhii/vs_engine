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
    std::vector<std::pair<double,std::size_t>> res=knn_Search(q1,db,1);
    std::cout<<res[0].first<<" "<<res[0].second<<'\n';

    Vector temp=db.at(3);
    temp.print_Vec();
        
    return 0;
}
