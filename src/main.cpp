#include<iostream>
#include<vector>
#include<utility>
#include<string>

#include"Vector.hpp"
#include"Similarity.hpp"
#include"vectorDB.hpp"
#include"SearchEngine.hpp"
#include"FileLoader.hpp"
#include"Document.hpp"

int main(){
    std::string user_Input;
    std::getline(std::cin,user_Input);

    std::streamslice vs(user_Input);
    std::vector<double> user_V;
    double value=0;
    while(vs >> value){
        user_V.push_back(value);
    }

    std::string file_Name="/home/msokhi/Desktop/vs_engine/data/vectors.txt";
    vectorDB db=construct_DB(file_Name);
    std::cout<<db.at(0).get_ID()<<'\n';

    std::vector<double> q={4.2,5.8};
    Vector q2(q);
    
    std::vector<std::pair<double,std::size_t>> res=knn_Search(q2,db,2);

    for(auto i=0;i<res.size();++i){
        std::cout<<res[i].first<<" "<<res[i].second<<'\n';
    }

    Vector res2=db.at(1).get_emb();
    res2.print_Vec();

    return 0;
}
