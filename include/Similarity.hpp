#ifndef SIMILARITY_HPP
#define SIMILARITY_HPP

#include "Vector.hpp"

double euc_distance(const Vector &v1,const Vector &v2);
double dot_prod(const Vector &v1,const Vector &v2);
double cos_sim(const Vector &v1,const Vector &v2);

#endif
