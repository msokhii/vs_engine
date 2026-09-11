#include<iostream>
#include<vector>
#include<utility>
#include<string>
#include<sstream>

#include"Vector.hpp"
#include"Similarity.hpp"
#include"vectorDB.hpp"
#include"SearchEngine.hpp"
#include"FileLoader.hpp"
#include"Document.hpp"
#include"BenchMark.hpp"

int main(){
    /*
    std::string file_Name="/home/msokhi/Desktop/vs_engine/data/vectors.txt";
    vectorDB db=construct_DB(file_Name);
    */

    vectorDB db=bm_file(3,50);
    db.print_db();

    
    std::string user_Input;
    std::getline(std::cin,user_Input);

    std::stringstream vs(user_Input);
    std::vector<double> user_V;
    double value=0;
    while(vs >> value){
        user_V.push_back(value);
    }

    if(user_V.size()<db.at(0).get_emb().size()){
        throw std::invalid_argument("Vector sizes must be the same");
    }

    Vector user_VV(user_V);
    
    std::vector<std::pair<double,std::size_t>> res=knn_Search(user_VV,db,2);

    for(auto i=0;i<res.size();++i){
        std::cout<<res[i].first<<" "<<res[i].second<<'\n';
    }
    
    
    return 0;
}
