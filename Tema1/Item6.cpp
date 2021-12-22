#include <iostream>
//Item 6: Explicitly disallow the use of compiler generated functions you do not want
class Uncopyable 
{
protected: 
    Uncopyable() {} 
    ~Uncopyable() {} 
private:
    Uncopyable(const Uncopyable&); 
    Uncopyable& operator=(const Uncopyable&);
};

class HomeForSale//: private Uncopyable - se poate utiliza si clasa Uncopyable
{
private:
    float price;
    int noRooms;
    float surface;
    // HomeForSale(const HomeForSale&); // Pentru a opri compilatorul din a genera respectivele clase, acestea se pot pune in zona private
    // HomeForSale& operator=(const HomeForSale&);
public:
    HomeForSale(float p,  int noR, float s) { price = p; noRooms = noR; surface = s; std::cout<<"Constructor called "<<std::endl;};
    ~HomeForSale(){std::cout<<"Destructor called "<<std::endl; };
};


int main()
{
    HomeForSale h1(13000, 3, 125);
    HomeForSale h2(17000, 4, 200);

    h1 = h2;
    return 0;
}