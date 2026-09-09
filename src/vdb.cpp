#include"vectorDB.hpp"
#include<stdexcept>

vectorDB::vectorDB()=default;

void vectorDB::add_vec_DB(const Vector &v){
    if(vdb.empty()){
        vdb.push_back(v);
        return;
    }

    if(v.size()>0){
        if(v.size() != vdb[0].size()){
            throw std::invalid_argument("All vectors in the database must be of the same size.");
        }
    }

    vdb.push_back(v);
}

std::size_t vectorDB::size(){ return vdb.size(); }

const Vector& vectorDB::at(std::size_t idx) const{
    if(idx<0 || idx>=vdb.size()){
        throw std::invalid_argument("Invalid index.");
    }

    return vdb[idx];
}
