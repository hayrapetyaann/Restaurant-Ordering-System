#ifndef DISH_H
#define DISH_H

#include <string>
#include <iostream>

class Dish {
protected:
    std::string name;
    double price;

public:
    Dish(const std::string& dishName, double dishPrice);
    Dish(const Dish& other);
    Dish& operator=(const Dish& other);
    Dish(Dish&& other) noexcept;
    Dish& operator=(Dish&& other) noexcept;

    double getPrice() const;
    std::string getName() const;
    virtual void display() const;
    virtual ~Dish() = default;
};

#endif // DISH_H
