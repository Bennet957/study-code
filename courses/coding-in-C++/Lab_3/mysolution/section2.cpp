#include <iostream>
#include <string>
#include <iomanip>

class User{
    protected:
        std::string name;
        int id;
    public: 
        User(const std::string& name, const int& id){
            this->name=name;
            this->id=id;
        }

        void printinfo(){
            std::cout<<"Name:"<<name<<std::endl;
            std::cout<<"ID:"<<id;
        }
        
};

class Student: public User{
    protected:
        int mark;
    public:
        Student(const std::string& name,const int& id, int mark):User(name, id){
            this->mark=mark;
        }
        void printRole();
};

class Instructor:public User{
    protected:
        int age;
    public:
        Instructor(const std::string& name, const int& id, int age):User(name, id){
            this->age=age;
        }
        void printRole();
};

void Instructor::printRole()
{
    std::cout<<"Name:"<<name<<std::endl;
    std::cout<<"ID:"<<id<<std::endl;
    std::cout<<"Age:"<<age;
};
void Student::printRole()
{
    std::cout<<"Name:"<<name<<std::endl;
    std::cout<<"ID:"<<id<<std::endl;
    std::cout<<"Mark:"<<mark;
};

int main()
{
    Student s1("Alice", 1, 85);
    Instructor i1("Bob", 2, 30);
    s1.printRole();
    i1.printRole();
}