#include "Order.h"
#include <iostream>

Order::Order(Customer* customer)
    : customer(customer), totalPrice(0.0) {}

Order::Order(const Order& other)
    : customer(other.customer), orderedDishes(other.orderedDishes), totalPrice(other.totalPrice) {}

Order& Order::operator=(const Order& other) {
    if (this != &other) {
        customer = other.customer;
        orderedDishes = other.orderedDishes;
        totalPrice = other.totalPrice;
    }
    return *this;
}

Order::Order(Order&& other) noexcept
    : customer(std::move(other.customer)), orderedDishes(std::move(other.orderedDishes)), totalPrice(other.totalPrice) {}

Order& Order::operator=(Order&& other) noexcept {
    if (this != &other) {
        customer = std::move(other.customer);
        orderedDishes = std::move(other.orderedDishes);
        totalPrice = other.totalPrice;
    }
    return *this;
}

void Order::addDish(Dish* dish) {
    orderedDishes.push_back(dish);
    calculateTotal();
}

void Order::calculateTotal() {
    totalPrice = 0.0;
    for (auto& dish : orderedDishes) {
        totalPrice += dish->getPrice();
    }
}

void Order::displayOrder() const {
    std::cout << "Order for " << customer->getName() << ":\n";
    for (const auto& dish : orderedDishes) {
        dish->display();
    }
    std::cout << "Total: $" << totalPrice << "\n\n";
}
