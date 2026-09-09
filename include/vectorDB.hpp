#ifndef VECTORDB_HPP
#define VECTORDB_HPP

#include"Vector.hpp"
#include<vector>
#include<cstddef>

class vectorDB{
public:
    vectorDB();

    void add_vec_DB(const Vector &v);
    std::size_t size();
    const Vector at(std::size_t idx) const;
private:
    std::vector<Vector> vdb;
};

#endif
