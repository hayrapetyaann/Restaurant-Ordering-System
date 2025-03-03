#include "Menu.h"
#include <iostream>

Menu::Menu(const Menu& other) {
    for (auto dish : other.dishes) {
        dishes.push_back(dish); 
    }
}

Menu& Menu::operator=(const Menu& other) {
    if (this != &other) {
        dishes.clear();
        for (auto dish : other.dishes) {
            dishes.push_back(dish);
        }
    }
    return *this;
}

Menu::Menu(Menu&& other) noexcept
    : dishes(std::move(other.dishes)) {}

Menu& Menu::operator=(Menu&& other) noexcept {
    if (this != &other) {
        dishes = std::move(other.dishes);
    }
    return *this;
}

Menu::~Menu() {
    for (auto dish : dishes) {
        delete dish;
    }
}

void Menu::addDish(Dish* dish) {
    dishes.push_back(dish);
}

void Menu::displayMenu() const {
    std::cout << "Menu:\n";
    for (const auto& dish : dishes) {
        dish->display();
    }
}

Dish* Menu::getDishByName(const std::string& dishName) const {
    for (auto& dish : dishes) {
        if (dish->getName() == dishName) {
            return dish;
        }
    }
    return nullptr;
}
