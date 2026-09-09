#ifndef SEARCH_ENGINE_HPP
#define SEARCH_ENGINE_HPP

#include<cstddef>
#include<vector>
#include<utility>
#include"vectorDB.hpp"
#include"Similarity.hpp"

std::vector<std::pair<double,std::size_t>> knn_Search(const Vector &v,const vectorDB &vdb,const std::size_t k);

#endif
