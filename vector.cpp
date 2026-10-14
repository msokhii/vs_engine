#include"vector.hpp"
#include<cstddef>
#include<random>

const std::size_t Vector::get_Size(){
    return size_;
}

Vector::Vector(std::size_t user_Val) :
    data_(user_Val==0 ? nullptr : new double[user_Val]{}),
    size_(user_Val),
    capacity_(user_Val){
        std::cout<<"Constructor - SUCCESSFULL."<<'\n';
    }

Vector::Vector(std::initializer_list<double> values) :
    size_(values.size()),
    data_(new double[values.size()]),
    capacity_(values.size()){
        std::copy(values.begin(),values.end(),data_);
        std::cout<<"Constructor - SUCCESSFULL."<<'\n';
    }

void Vector::print_Vec() const{
    if(this->size_<=0){
        throw std::out_of_range("Invalid.");
    }
    for(auto i=0;i<this->size_;++i){
        std::cout<<this->data_[i]<<" ";
    }
    std::cout<<'\n';
}

void Vector::fill_Vec(){
    if(this->size_<=0){
        throw std::out_of_range("Invalid.");
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> distrib(0.0,1.0);

    for(auto i=0;i<this->size_;++i){
        this->data_[i]=distrib(gen);
    }
}

Vector::Vector(const Vector& other) :
    Vector(other.size_){
        for(auto i=0;i<size_;++i){
            data_[i]=other.data_[i];
        }
    }

Vector& Vector::operator=(const Vector& other){
    if(this==&other){
        return *this;
    }

    double* newData=other.capacity_? new double[other.capacity_] : nullptr;
    for(auto i=0;i<other.size_;++i){
        newData[i]=other.data_[i];
    }

    delete [] data_;
    data_=newData;
    capacity_=other.capacity_;
    size_=other.size_;

    return *this;
}

Vector::~Vector(){
    delete[] data_;
    data_=nullptr;
    std::cout<<"Destructor - SUCCESSFULL."<<'\n';
}
