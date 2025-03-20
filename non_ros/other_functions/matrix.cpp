#include<iostream>
#include<vector>
#include"matrix.h"

using namespace std;

VECTOR_OPS::VECTOR_OPS()
{
    number_of_vectors = 10;
}
    
std::array<float,5> VECTOR_OPS::add_vect_arr()
{    
    vector<float> vector1 = {1,2,3,4,0};
    std::array<float,5> arr = {1,2,3,4,0};
    std::array<float,5> result; 
    for (int i = 0; i < std::size(arr); i++)
    {
        result[i] = arr[i] + vector1[i];
    }
    return result;
}
