#ifndef VECTOR_HPP
#define VECTOR_HPP

#include<vector>
#include<cstddef>
#include<iostream>

class Vector{
public:
    Vector(); // This represents an empty vector.
    Vector(const std::vector<double> &values);
    std::size_t size() const; // This represents the size of the vector.
    double at(std::size_t idx) const; // Get the value at the specified index.
    void print_Vec() const; // Print the vector.
    const std::vector<double> &getValues() const; // Get the entire vector.
private:
    std::vector<double> values;
};

#endif
