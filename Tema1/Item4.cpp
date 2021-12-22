#include <iostream>
//Item 4: Make sure that objects are initialized before they’re used.
void GarbageValue()
{
    int var2;
    std::cout<<"Value of var2 = "<<var2<<std::endl;
    std::cout<<"Variable var2 is uninitialized "<<std::endl;
}

int main()
{
    int var1 = 1;
    std::cout<<"Value of var1 = "<<var1<<std::endl;
    GarbageValue();
    return 0;
}