#include <iostream>
#include <string>

class Shape {
    public:
        virtual double area() const {
            return 0.0;
        }
        virtual ~Shape(){};
};

class Circle:public Shape{
    public: 
        double pi;
        double radius;
        double area() const override{

        }

};

class Triangle:public Shape{
    public: 
        double lenght;
        double height;
        double area () const override{

        }

};