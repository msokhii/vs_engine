#include "Vector.hpp"
#include<stdexcept>

Vector::Vector()=default;

Vector::Vector(const std::vector<double> &inputValues){ values=inputValues; }

std::size_t Vector::size() const{ return values.size(); }

const std::vector<double> & Vector::getValues() const { return values; }

void Vector::print_Vec() const {
    std::cout<<"[ ";
    for(auto i=0;i<values.size();++i){
        std::cout<<values[i]<<" ";
    }
    std::cout<<"]\n";
}

double Vector::at(std::size_t idx) const {
    if(idx<0 || idx>=values.size()){
        throw std::out_of_range("Vector index out of range.");
    }
    return values[idx];
}
