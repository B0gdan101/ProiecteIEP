//Item 14: Think carefully about copying behavior in resource-managing classes.
#include <iostream>

class Uncopyable {
protected: 
Uncopyable() {} 
~Uncopyable() {} 
private:
Uncopyable(const Uncopyable&); 
Uncopyable& operator=(const Uncopyable&);
};

class Resource
{
private:
    int nr;
    bool status;
public:
    Resource(int number){nr = number; std::cout<<"Constructor called "<<std::endl;};
    ~Resource() {  std::cout<<"Destructor called "<<std::endl; };
    void printStatus();
    void setlock(bool value);
};

void Resource::printStatus()
{
    if (status){ 
        std::cout<<"Cannot use resource! Resource is locked!"<<std::endl;
    } else {
        std::cout<<"Resource is unlocked and can be used!"<<std::endl;
    };
}

void Resource::setlock(bool value)
{ if(value){
    status = true; }
     else {
    status = false;} 
}

void lock(Resource &res) 
{
    std::cout<<"Locking resource..."<<std::endl;
    res.setlock(true);
    std::cout<<"Resource locked"<<std::endl;
}

void unlock(Resource &res)
{
    std::cout<<"Unlocking resource..."<<std::endl;
    res.setlock(false);
    std::cout<<"Resource unlocked"<<std::endl;
}

class Lock//:private Uncopyable
{
private:
    Resource &lockedPointer;
public:
  Lock(Resource &p): lockedPointer(p) { lock(lockedPointer);}
 ~Lock(){ unlock(lockedPointer); }
};

int main()
{
    Resource a(55);
    Lock *lockedResource = new Lock(a);
    a.printStatus();
    delete lockedResource;
    a.printStatus();
} 

