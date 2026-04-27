#include <iostream>
#include <string>
#include <cstdint>

namespace validation{
    bool isAdult(int age){
        if (age>=18){
            return true;
        }
        else {
            return false;
        }
    }
    bool isSenior(int age){
        if (age>=65){
            return true;
        }
        else {
            return false;
        }
    }
}

int main(){
    int age;
    std::cout<<"Please enter your age:";
    std::cin>>age;
    if (!(age<=100 && age>=0)){
        std::cout<<"You did not enter a valid number. Please try again."<<std::endl;
        std::cout<<"Please enter your age:";
        std::cin>>age;
    }
    
    std::cout<<"You are "<<age<<" years old"<<std::endl;
    if (validation::isAdult(age)==true && validation::isSenior(age)==false){
        std::cout<<"That means that you are an adult.";
    }
    if (validation::isSenior(age)==true){
        std::cout<<"That means that you are a Senior.";
    }
}