#ifndef VECTOR_HPP
#define VECTOR_HPP

#include<cstddef>
#include<iostream>
#include<initializer_list>

class Vector{
public:
    Vector() noexcept=default;
    explicit Vector(std::size_t user_Val);
    Vector(std::initializer_list<double> values);
    const std::size_t get_Size();
    void print_Vec() const;
    void fill_Vec();
    Vector(const Vector& other);
    Vector& operator=(const Vector& other);
    ~Vector();
private:
    double* data_=nullptr;
    std::size_t size_=0;
    std::size_t capacity_=0;
};

#endif
