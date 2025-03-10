#ifndef ORDER_H
#define ORDER_H

class Customer;

#include "Dish.h"
#include "Customer.h"
#include <vector>

class Order {
private:
    Customer* customer;
    std::vector<Dish*> orderedDishes;
    double totalPrice;

public:
    Order(Customer* customer);
    Order(const Order& other);
    Order& operator=(const Order& other);
    Order(Order&& other) noexcept;
    Order& operator=(Order&& other) noexcept;
    ~Order() = default;

    void addDish(Dish* dish);
    void calculateTotal();
    void displayOrder() const;
};

#endif // ORDER_H
