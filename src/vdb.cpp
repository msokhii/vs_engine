#include"vectorDB.hpp"
#include<stdexcept>

vectorDB::vectorDB()=default;

void vectorDB::add_vec_DB(const Vector &v){
    vdb.push_back(v);
}

std::size_t vectorDB::size(){ return vdb.size(); }

const Vector vectorDB::at(std::size_t idx) const{
    if(idx<0 || idx>=vdb.size()){
        throw std::invalid_argument("Invalid index.");
    }

    return vdb[idx];
}
