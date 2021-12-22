#include <iostream>
//Item 5: Know what functions C++ silently writes and calls.
class Example
{
private:
    std::string& leftValue;
    const int rightValue;
public:
    Example(std::string& left, int right): leftValue(left), rightValue(right){ std::cout<<"Constructor called "<<std::endl; }
    Example& operator=(const Example& d) //Trebuie sa definim Copy Assignment Operator, daca nu vom intampina o eroare
    {   
        std::cout<<"Copy Assignment Operator called "<<std::endl;
        return *this;
    }
    ~Example(){ std::cout<<"Destructor called "<<std::endl; }
};

int main()
{
    std::string one("1");
    std::string two("2");
    Example a(one, 1);
    Example b(two, 2);

    a = b;
    return 0;
}
