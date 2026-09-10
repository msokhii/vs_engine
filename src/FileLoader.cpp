#include"FileLoader.hpp"
#include"vectorDB.hpp"
#include"Vector.hpp"
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

const vectorDB construct_DB(std::string &fileName){
    std::ifstream f(fileName);

    if(!f.is_open()){
        throw std::runtime_error("Could not open file.");
    }
    
    std::string line;
    vectorDB db;

    while(std::getline(f,line)){
        std::stringstream ss(line);
        std::vector<double> v;
        double value=0;
        while(ss >> value){
            v.push_back(value);
        }
        if(v.empty()){ continue; }
        Vector v2(v);
        db.add_vec_DB(v2);
    }

    return db;
}
