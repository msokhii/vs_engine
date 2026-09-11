#include"FileLoader.hpp"
#include"vectorDB.hpp"
#include"Vector.hpp"
#include"Document.hpp"
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

        std::string id_string;
        std::string text_string;
        std::string vector_string;

        std::getline(ss,id_string,'|');
        std::getline(ss,text_string,'|');
        std::getline(ss,vector_string,'|');

        std::size_t id=std::stoul(id_string);
        std::stringstream vs(vector_string);
        std::vector<double> v;
        double value=0;
        while(vs >> value){
            v.push_back(value);
        }
        if(v.empty()){ continue; }

        Vector v2(v);
        Document doc(id,text_string,v2);
        db.add_doc_DB(doc);
    }

    return db;
}
