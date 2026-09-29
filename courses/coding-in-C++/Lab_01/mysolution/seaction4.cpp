#include <iostream>
#include <string>
#include <cstdint>
#include <iomanip>
#include <limits>

void readStudentData(std::string& name,uint16_t& homework,uint16_t& midterm,uint16_t& finalExam){
    std::cout<<"Enter student name: ";
    std::getline (std::cin,name);
    std::cout<<"Homework score: ";
    std::cin>>homework;
    while (homework>100 || homework<0)
    {
        std::cout<<"This is not a valid grade"<<std::endl;
        std::cout<<"Try Again:";
        std::cin>>homework;
    }
    std::cout<<"Midterm score: ";
    std::cin>>midterm;
    while (midterm>100 || midterm<0)
    {
        std::cout<<"This is not a valid grade"<<std::endl;
        std::cout<<"Try Again:";
        std::cin>>midterm;
    }
    std::cout<<"Final exam score: ";
    std::cin>>finalExam;
    while (finalExam>100 || finalExam<0)
    {
        std::cout<<"This is not a valid grade"<<std::endl;
        std::cout<<"Try Again:";
        std::cin>>finalExam;
    }
}


//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear the input buffer

void calculateGrade(uint16_t homework, uint16_t midterm, uint16_t finalExam,uint16_t& finalGrade, std::string& letterGrade){
    
    finalGrade=(0.4*homework)+(0.25*midterm)+(0.35*finalExam);
    
    if (finalGrade>=90){letterGrade="A";}
    if (finalGrade>=80 && finalGrade<90){letterGrade="B";}
    if (finalGrade>=70 && finalGrade<80){letterGrade="C";}
    if (finalGrade>=60 && finalGrade<70){letterGrade="D";}
    if (finalGrade>=50 && finalGrade<60){letterGrade="E";}
    if (finalGrade<50){letterGrade="F";}

}

void printReport(std::string name,uint16_t homework, uint16_t midterm, uint16_t finalExam,uint16_t finalGrade, std::string letterGrade){
    std::string status;
    if(letterGrade=="A" || letterGrade=="B" || letterGrade=="C"){status="PASS";};
    if(letterGrade=="D" || letterGrade=="E"){status="CONDITIONAL PASS";};
    if(letterGrade=="E"){status="FAIL";};
    std::cout<<"-------------------------------------"<<std::endl;
    std::cout<<"Student Report"<<std::endl<<std::endl;
    std::cout<<"-------------------------------------"<<std::endl;
    std::cout<<"Name: "<<name<<std::endl<<std::endl;
    std::cout<<"Scores"<<std::endl;
    std::cout<<"-------------------------------------"<<std::endl;
    std::cout<<std::left<<std::setw(15)<<"Homework"<<std::left<<std::setw(6)<<std::setprecision(2)<<homework<<std::endl;
    std::cout<<std::left<<std::setw(15)<<"Midterm"<<std::left<<std::setw(6)<<std::setprecision(2)<<midterm<<std::endl;
    std::cout<<std::left<<std::setw(15)<<"Final Exam"<<std::left<<std::setw(6)<<std::setprecision(2)<<finalExam<<std::endl<<std::endl;
    std::cout<<std::left<<std::setw(15)<<"Final Grade"<<std::left<<std::setw(6)<<std::setprecision(2)<<finalGrade<<std::endl;
    std::cout<<std::left<<std::setw(15)<<"Letter Grade"<<std::left<<std::setw(6)<<std::setprecision(2)<<letterGrade<<std::endl;
    std::cout<<std::left<<std::setw(15)<<"Status"<<std::left<<std::setw(6)<<std::setprecision(2)<<status<<std::endl;
    std::cout<<"-------------------------------------"<<std::endl;

}

int main(){
    std::string name;
    uint16_t homework;
    uint16_t midterm;
    uint16_t finalExam;
    readStudentData(name,homework,midterm,finalExam);
    std::string letterGrade;
    uint16_t finalGrade;
    calculateGrade(homework,midterm,finalExam,finalGrade,letterGrade);
    printReport(name,homework,midterm,finalExam,finalGrade,letterGrade);
}
