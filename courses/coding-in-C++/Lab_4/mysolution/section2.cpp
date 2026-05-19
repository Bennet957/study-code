#include <iostream>
#include <string>

class Shape{
   
        
    public:
        virtual double computeArea()const {//kann virtual sein, damit dies für verschiedene formen leichter erstellt werden kann
            return 0.0;
        }
        
        virtual ~Shape() = default;
};

class Circle: public Shape{
    private:
        double rad;
        double pi;
    public:
        double computeArea() const override{
            return rad*pi*rad;
        }
        Circle(double rad,double pi):rad(rad),pi(pi){}
};

class Quadrat: public Shape{
    private:
        double length;
        double width;
    public:
        double computeArea() const override{
            return length*width;
        }
        Quadrat(double length,double width):length(length),width(width){};
};//damit kann eben für jede Form mit nur einer Funktion für jede Klasse ausgerechnet werden

int main(){
    Circle c1(3.5,3.14);
    Quadrat q1(4.5,4.6);
    c1.computeArea();
    q1.computeArea();

    // Part 3: Array von Shape-Zeigern
    Shape* shapes[2];

    // Objekte der abgeleiteten Klassen zuweisen
    shapes[0] = new Circle(3.5,3.14);
    shapes[1] = new Quadrat(4.5, 4.6);
    

    // Schleife: ruft für jedes Objekt computeArea() auf
    for (int i = 0; i < 3; i++) {
        std::cout << "Fläche: " << shapes[i]->computeArea() << std::endl;
    }

    // Wichtig: Speicher freigeben!
    for (int i = 0; i < 3; i++) {
        delete shapes[i];
    }
}