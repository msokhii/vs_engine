#include"FileLoader.hpp"
#include<fstream>
#include<string>

const vectorDB& construct_DB(fstream f) const{
    std::ifstream f("filename.txt");

    std::string line;

    while(std::getline(file,line)){
        std::cout<<line<<'\n';
    }
    
}
