#include <iostream>
#include <string>

class BankAccount{
    private:
        std::string owner;
        double balance;
    public: 
        void setOwner();
        std::string getOwner(std::string ownername){
            std::cout<<"Please set the owner";
            std::cin>>ownername;
            owner=ownername;
            return owner;
        };
        double deposit(double deposit){
            if (deposit>0){
                balance+=deposit;
            }
            else {
                std::cout<<"Deposit is lower than 0";
            }
            return balance;
        };
        double withdraw(double deposit){
            if (deposit>0){
                balance-=deposit;
            }
            return balance;
        };
        double getBalance();
        void getAccountInfo();
};

double BankAccount::getBalance(){
    return balance;
}
void BankAccount::getAccountInfo(){
    std::cout<<owner<<std::endl;
    std::cout<<balance<<std::endl;
}