#include "Appetizer.h"

Appetizer::Appetizer(const std::string& dishName, double dishPrice, bool spicy)
    : Dish(dishName, dishPrice), isSpicy(spicy) {}

void Appetizer::display() const {
    std::cout << name << " - $" << price;
    if (isSpicy) {
        std::cout << " (Spicy)";
    }
    std::cout << std::endl;
}
