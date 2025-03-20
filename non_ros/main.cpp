#include <iostream>
#include "functions.h"
#include "other_functions/matrix.h"

using namespace std;
int main()
{
    Functions obj;
    VECTOR_OPS mat;

    cout<<obj.number<<"\n"<<endl;
    cout<<obj.add_numbers()<<12<<endl;

    std::array<float,5> mat1 = mat.add_vect_arr();

    for(int i=1;i<=4;i++)
    {
        cout<<"\n"<<mat1[i];
    }

}