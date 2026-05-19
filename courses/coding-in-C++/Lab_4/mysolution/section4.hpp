#ifndef SECTION4_HPP
#define SECTION4_HPP
#include <iostream>
class ReportableInspectable {
    public:
        virtual void report() = 0;
        virtual void inspect() = 0;
};

class Motor: public ReportableInspectable{                    
    protected :
        int id;
        std::string name;
        double weight;
        double temperature;
        bool hasDefect;
    
    public: 
        Motor(int id, std::string name, double weight, double temperature, bool hasDefect);
};

class Verbrennungsmotor : public Motor {
    void inspect () override;
    void report() override;
};

class Elektromotor : public Motor {
    float voltage;
    void inspect () override;
    void report() override;
};

class Inspection{

};

class WeightCheck:public Inspection{

};

class VisualInspection: public Inspection{

};

class TemperatureCheck:public Inspection{

};






#endif