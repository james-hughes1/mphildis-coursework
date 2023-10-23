#include <iostream>
#include <string>

class Researcher {
public:
    Researcher(std:: string, std::string);
    void displayName();
    std::string name;
    std::string title;
};

Researcher::Researcher(std::string newName, std::string newTitle){
    name = newName;
    title = newTitle;
}

void Researcher::displayName(){
    std::cout << "Title: " << title << std::endl;
    std::cout << "Name: " << name << std::endl;
}

int main() {
    Researcher res = Researcher("Darth Vader", "Lord");
    res.displayName();
    return 0;
}