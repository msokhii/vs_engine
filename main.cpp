#include"vector.hpp"
#include<iostream>
#include<cstddef>

int main(){
    Vector v(10);
    v.fill_Vec();
    v.print_Vec();

    Vector v2(5);
    v2.fill_Vec();
    v2.print_Vec();

    v2=v;
    v.print_Vec();
    v2.print_Vec();
    return 0;
}
