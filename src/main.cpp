#include<iostream>
#include<vector>

#include"Vector.hpp"
#include"Similarity.hpp"

int main(){
    std::vector<double> numbers={1.1,1.2};
    Vector v1(numbers);

    std::vector<double> num2={1.2,3.0};
    Vector v2(num2);

    v1.print_Vec();
    v2.print_Vec();

    double d1=euc_distance(v1,v2);
    std::cout<<d1<<'\n';

    double d2=dot_prod(v1,v2);
    std::cout<<d2<<'\n';

    double d3=cos_sim(v1,v2);
    std::cout<<d3<<'\n';
    return 0;
}
