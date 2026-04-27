#include <iostream>
#include <string>
#include <iomanip>


class Article {
    private:
        std::string name; 
        double price; 
        int stock;
        std::string category; 
        int id; 
    public:
        
        Article(const std::string& name, double price, int stock, const std::string& category, int id) { //initializer list
            this->name = name; 
            this->price = price; 
            this->stock = stock; 
            this->id = id;
            this->category = category; 
        }
        //~Article(){};

        void setPrice(double price) {
            if (!price){
                std::cout<<"Fehler";
            }
            this->price = price; 
           
        }

        void sell(int amount) {
            if (!amount){
                std::cout<<"Fehler";
            }
            this->stock -=amount; 
        }

        void restock(int amount) {
            if (!amount){
                std::cout<<"Fehler";
            }
            this->stock += amount;
        }

        double applyDiscount(double percent) {
            if (percent<0 || percent>100){
                std::cout<<"Discount is too high";
            }
            price = (price - ((price * percent) / 100)); 
            return price; 
        }

        double getPrice() const{ 
            return price; 
        }

        bool isAvailable() const{ 
            if (stock > 0){
                return true;}
            else{
                return false;}
        }

        void printInfo() { 
            std::cout << "Article: " << name << std::endl;
            std::cout << "Category: " << category << std::endl;
            std::cout << "Price: " << price << std::endl;
            std::cout << "Stock: " << stock << std::endl;
            std::cout << "ID: " << id << std::endl;
        }
    };

int main() {
    Article first("Laptop", 999.99, 10, "Electronics", 101); 

    first.sell(5);
    first.restock(5); 
    first.applyDiscount(50);

    if (first.isAvailable()==true) {std::cout << "Article available" << std::endl;} //Funktion ist falsch benutzt

    first.printInfo();
}