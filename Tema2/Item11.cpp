#include <iostream>
//Item 11: Handle assignment to self in operator=. 
class SelfAssignment
{
private:
   int x;
   int y;
public:
    SelfAssignment(int X, int Y) { std::cout<<"Constructor called "<<std::endl; x = X; y = Y;};
    SelfAssignment& operator=(SelfAssignment& a)   
{
    if (this == &a) { std::cout<<"Self Assignment"<<std::endl; return *this;} // Verify if self-assignment
    x = a.x;
    y = a.y;
    //swap(*this, a);
    return *this;
};
    ~SelfAssignment() { std::cout<<"Destructor called "<<std::endl; };
    //void swap(SelfAssignment& a, SelfAssignment&b) { using std::swap; swap(a.x,b.x); swap(a.y,b.y);};
};

int main()
{
    SelfAssignment a(2,4);
    SelfAssignment b(5,5);
    std::cout<<"-----------"<<std::endl;
    a = b;
    b = b;
    std::cout<<"-----------"<<std::endl;
    return 0;
}