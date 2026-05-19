#include <iostream>
#include <string>
#include<cmath>

class Vektor2D{
    private:
        double x;
        double y;
    public:
        Vektor2D(){};
        Vektor2D(double x, double y):x(x),y(y){};
        
        double getX() const
        {
            return x;
        }
        double getY() const
        {
            return y;
        }
        void print () const
        {
            std::cout<<"X: "<<x<<std::endl;
            std::cout<<"Y: "<<y;
        }
        double getMagnitude() const
        {
            return sqrt((x * x) + (y * y));
        }
        double getMagnitude(int precision) const
        {
            double factor = std::pow(10.0, precision);
            double length = this->getMagnitude();
            return std::round(length * factor) / factor;
        }
        
};

int main ()
{
    Vektor2D v(3, 4);
    std::cout << "Länge: " << v.getMagnitude() << std::endl;          
    std::cout << "Länge (2 Nachkommastellen): " << v.getMagnitude(2) << std::endl;                       
    return 0;
}
