#include <iostream>
//Item 10: Have assignment operators return a reference to *this.
class Exemplu
{
private:
int numar;
public:
    Exemplu(int nr) {numar = nr; std::cout<<"Constructor called "<<std::endl;};
    Exemplu operator= (Exemplu op)
    {
        std::cout<<"Assignment operator called "<<std::endl;
        numar = op.numar;
        return *this;
        //c.operator=(b.operator=(a));
    };
    ~Exemplu() {  std::cout<<"Destructor called "<<std::endl; };
    int returnValue();
};

int Exemplu::returnValue() { return numar;}


int main()
{
    Exemplu a(5); // a = 5
    Exemplu b(1); // b = 1
    Exemplu c(0); // c = 0
    std::cout<<"-----------"<<std::endl;
    c = b = a; // c<-b<-a
    std::cout<<"-----------"<<std::endl;
    std::cout<<"a = "<<a.returnValue()<<std::endl;
    std::cout<<"b = "<<b.returnValue()<<std::endl;
    std::cout<<"c = "<<c.returnValue()<<std::endl;
    std::cout<<"-----------"<<std::endl;
    return 0;
}