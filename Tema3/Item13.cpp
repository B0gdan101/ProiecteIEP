//Item 13: Use objects to manage resources.
#include <iostream>
#include <memory>

class Dog
{
private:
    std::string color;
    int age;
    int legs = 4;
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
    int getLegs(){return legs;};
    void setAge(int newAge) { age = newAge; };
};

Dog* createDogInstance(std::string name,int age){
    return (new Dog(name,age));
}

int main()
{
    std::cout<<"-----------Auto Pointer--"<<std::endl;
    std::cout<<std::endl;
    std::auto_ptr<Dog> autoDog(createDogInstance("brown",3));
    std::cout<<"Auto dog's legs "<<autoDog->getLegs()<<std::endl;
    std::cout<<std::endl;
    std::cout<<"----------Unique Pointer--"<<std::endl;
    std::cout<<std::endl;
    std::unique_ptr<Dog> uniqueDog(createDogInstance("white",4));
    std::cout<<"Unique dog's legs "<<uniqueDog->getLegs()<<std::endl;
    std::unique_ptr<Dog> uniqueDog2 = move(uniqueDog);
    std::cout<<"Second unique dog's legs "<<uniqueDog2->getLegs()<<std::endl;
    std::cout<<std::endl;
    std::cout<<"-----------Shared Pointer--"<<std::endl;
    std::cout<<std::endl;
    std::shared_ptr<Dog> sharedDog(createDogInstance("black",2));
    std::cout<<"First shared dog's legs "<<sharedDog->getLegs()<<std::endl;
    std::cout<<"sharedDog count= "<<sharedDog.use_count()<<std::endl;

    std::shared_ptr<Dog> sharedDog2(sharedDog);
    std::cout<<"sharedDog count = "<<sharedDog.use_count()<<std::endl;
    std::cout<<"Second shared dog's age "<<sharedDog2->getAge()<<std::endl;
    sharedDog2->setAge(7);
    std::cout<<"First shared dog's age "<<sharedDog->getAge()<<std::endl;

    std::shared_ptr<Dog> sharedDog3 = move(sharedDog);
    std::cout<<"sharedDog count = "<<sharedDog.use_count()<<std::endl;
    std::cout<<"sharedDog3 count = "<<sharedDog3.use_count()<<std::endl;
    sharedDog3->setAge(5);
    std::cout<<"Third shared dog's age "<<sharedDog3->getAge()<<std::endl;
    std::cout<<"Second shared dog's age "<<sharedDog2->getAge()<<std::endl;
}