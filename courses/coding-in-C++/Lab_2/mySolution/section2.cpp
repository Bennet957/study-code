#include <iostream>
#include <string>

class Node{
    private:
        std::string* text;
    public:
        Node(std::string s){
            
            text=new std::string(s);
            
        };
        ~Node(){
            delete text;
            std::cout<<"Memory released";
        };
        void display(Node){
            std::cout<<"Text"<<*text;
        };
};

int main(){
    Node object1("Objekt");
    Node object2=object1;
    void display(Node object1);
    void display(Node object2);
}
