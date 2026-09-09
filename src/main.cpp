#include<iostream>
#include<vector>

#include"Vector.hpp"
#include"Similarity.hpp"
#include"vectorDB.hpp"

int main(){
    std::vector<double> numbers={1.1,1.2};
    Vector v1(numbers);

    std::vector<double> num2={1.2,3.0};
    Vector v2(num2);

    std::vector<double> num3={5,6.2};
    Vector v3(num3);
    
    v1.print_Vec();
    v2.print_Vec();
    v3.print_Vec();

    vectorDB db;

    db.add_vec_DB(v1);
    db.add_vec_DB(v2);
    db.add_vec_DB(v3);

    std::cout<<db.size()<<'\n';
    Vector v1_DB=db.at(1);

    v1_DB.print_Vec();
    
    return 0;
}
