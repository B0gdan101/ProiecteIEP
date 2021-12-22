#include <iostream>
//Item 12: Copy all parts of an object.
class Dog
{
private:
    std::string color;
    int age;
public:
    Dog(std::string n,int a) { color = n; age = a; std::cout<<"Dog Contructor called "<<std::endl;};
    Dog() = default;
    Dog(const Dog& d):color(d.color),age(d.age){ std::cout<<"Dog Copy Contructor called "<<std::endl; }
    Dog& operator=(const Dog& d)
    {   
        std::cout<<"Dog Copy Assignment Operator called "<<std::endl;
        age=d.age;
        color=d.color;  
        return *this;
    }
    ~Dog() { std::cout<<"Destructor called "<<std::endl; };
    int getAge() { return age;};
    std::string getColor() {return color;};    
};

class Bulldog:public Dog
{
private:
    std::string name;
public:
    Bulldog(std::string n,int a,std::string c):Dog(c,a){name = n;};
    Bulldog(const Bulldog& t):/*Dog(t),*/name(t.name){ std::cout<<"Bulldog Copy Constructor called "<<std::endl; }
    Bulldog& operator=(const Bulldog& t)
    {
        //Dog::operator=(t);
        std::cout<<"Bulldog Copy Assignment Operator called "<<std::endl;
        name=t.name;    
        return *this;
    }
    ~Bulldog() { std::cout<<"Destructor called "<<std::endl; }; 
    std::string getName() {return name;};    
};

int main()
{
    Bulldog dog1("Rex",5,"Brown");
    Bulldog dog2("Nero",3,"White");
    std::cout<<"-----------"<<std::endl;

    dog2 = dog1;

    std::cout<<"-----------"<<std::endl;
    std::cout<<"First dog's name "<<dog1.getName()<<std::endl;
    std::cout<<"First dog's age "<<dog1.getAge()<<" years old"<<std::endl;
    std::cout<<"First dog's color "<<dog1.getColor()<<std::endl;
    std::cout<<"-----------"<<std::endl;
    std::cout<<"Second dog's name "<<dog2.getName()<<std::endl;
    std::cout<<"Second dog's age "<<dog2.getAge()<<" years old"<<std::endl;
    std::cout<<"Second dog's color "<<dog2.getColor()<<std::endl;
    std::cout<<"-----------"<<std::endl;
    return 0;
}