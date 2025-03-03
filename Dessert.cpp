#include "Dessert.h"

Dessert::Dessert(std::string dishName, double dishPrice, bool nuts)
    : Dish(dishName, dishPrice), containsNuts(nuts) {}

void Dessert::display() const {
    std::cout << name << " - $" << price;
    if (containsNuts) {
        std::cout << " (Contains Nuts)";
    }
    std::cout << std::endl;
}
