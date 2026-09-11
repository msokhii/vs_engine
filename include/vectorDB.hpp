#ifndef VECTORDB_HPP
#define VECTORDB_HPP

#include"Vector.hpp"
#include"Document.hpp"
#include<vector>
#include<cstddef>

class vectorDB{
public:
    vectorDB();

    void add_doc_DB(const Document &v);
    std::size_t size() const;
    const Document& at(std::size_t idx) const;
    void print_db();
private:
    std::vector<Document> vdb;
};

#endif
