#include"vectorDB.hpp"
#include"Document.hpp"
#include<stdexcept>
#include<iostream>
vectorDB::vectorDB()=default;

void vectorDB::add_doc_DB(const Document &v){
    if(vdb.empty()){
        vdb.push_back(v);
        return;
    }

    /*
    if(v.size()>0){
        if(v.size() != vdb[0].size()){
            throw std::invalid_argument("All vectors in the database must be of the same size.");
        }
    }
    */

    vdb.push_back(v);
}

std::size_t vectorDB::size() const { return vdb.size(); }

const Document& vectorDB::at(std::size_t idx) const{
    if(idx<0 || idx>=vdb.size()){
        throw std::invalid_argument("Invalid index.");
    }

    return vdb[idx];
}

void vectorDB::print_db(){
    for(auto i=0;i<vdb.size();++i){
        const Vector &temp=vdb.at(i).get_emb();
        for(auto j=0;j<temp.size();++j){
            std::cout<<temp.at(j)<<" ";
        }
        std::cout<<'\n';
    }
}
