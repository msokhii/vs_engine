#ifndef SEARCH_ENGINE_HPP
#define SEARCH_ENGINE_HPP

#include<cstddef>
#include"vectorDB.hpp"
#include"Similarity.hpp"

std::size_t search_Vec(const Vector &v,const vectorDB &vdb);

#endif
