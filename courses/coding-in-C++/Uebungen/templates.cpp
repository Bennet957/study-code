#include <iostream>

template<typename T, typename U>
class Pair {
private:
    T first;
    U second;

public:
    // Schritt 3: Konstruktor
    Pair(T first, U second) : first(first), second(second) {}

    // Schritt 4: Getter
    T getFirst() const { return this->first; }
    U getSecond() const { return this->second; }

    // Schritt 5: Setter
    void setFirst(T first) { this->first = first; }
    void setSecond(U second) { this->second = second; }
};

int main() {
    Pair<std::string, int> p("Hallo", 42);

    std::cout << p.getFirst()  << std::endl; // Hallo
    std::cout << p.getSecond() << std::endl; // 42

    p.setFirst("Welt");
    std::cout << p.getFirst()  << std::endl; // Welt

    return 0;
}