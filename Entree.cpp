#include "Entree.h"

Entree::Entree(const std::string& dishName, double dishPrice, int cal)
    : Dish(dishName, dishPrice), calories(cal) {}

void Entree::display() const {
    std::cout << name << " - $" << price << " (" << calories << " kcal)" << std::endl;
}
