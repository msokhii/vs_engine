#include"BenchMark.hpp"
#include"Document.hpp"

#include<string>
#include<cstddef>
#include<random>
#include<limits>
#include<vector>

vectorDB bm_file(std::size_t dim,std::size_t num_Vec){
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_real_distribution<float> distrib(0,1);
    vectorDB vdb;
    
    for(auto i=0;i<num_Vec;++i){
        std::vector<double> temp1;
        for(auto j=0;j<dim;++j){
            temp1.push_back(distrib(gen));
        }
        Vector temp2(temp1);
        Document doc(i,"test",temp2);
        vdb.add_doc_DB(doc);
    }

    return vdb;
}
