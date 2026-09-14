#include<iostream>
#include<vector>
#include<utility>
#include<string>
#include<sstream>
#include<chrono>
#include<random>
#include<stdexcept>
#include<cmath>

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
    std::size_t dim=10;
    std::size_t num_Vec=100000;
    std::size_t k=1;
    
    vectorDB db=bm_file(dim,num_Vec);
    // db.print_db();

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_real_distribution<float> distrib(0.0,1.0);

    std::vector<double> tempQ;
    for(auto i=0;i<dim;++i){
        tempQ.push_back(distrib(gen));
    }

    Vector user_Q(tempQ);

    /*
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
    */
    for(auto i=0;i<10;++i){
        std::vector<std::pair<double,std::size_t>> res;
        std::vector<std::pair<double,std::size_t>> res2;
    
        auto start=std::chrono::high_resolution_clock::now();
        for(auto i=0;i<10;++i){
            res=knn_Search(user_Q,db,k);
        }
        auto end=std::chrono::high_resolution_clock::now();

        auto duration=std::chrono::duration_cast<std::chrono::microseconds>((end-start)/10);

        auto start2=std::chrono::high_resolution_clock::now();
        for(auto i=0;i<10;++i){
            res2=heap_knn_Search(user_Q,db,k);
        }
        auto end2=std::chrono::high_resolution_clock::now();

        auto duration2=std::chrono::duration_cast<std::chrono::microseconds>((end2-start2)/10);
    
        std::cout<<"K -> "<<k<<" BFKNN TIME (MUs) -> "<<duration.count()<<" and HBKNN TIME (MUs) -> "<<duration2.count()<<'\n';
        
        double tol=1e-9;
        
        for(auto i=0;i<k;++i){
            if(res[i].first - res2[i].first > tol || res[i].second != res2[i].second){
               throw std::invalid_argument("Error");
            }
        }
        k*=2;
    }

    return 0;
}
