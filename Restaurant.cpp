#include "Restaurant.h"
#include "Appetizer.h"   
#include "Entree.h"
#include "Dessert.h"
#include <iostream>

Restaurant::Restaurant() {
    menu.addDish(new Appetizer("Spring Rolls", 5.99, true));
    menu.addDish(new Entree("Grilled Chicken", 12.99, 500));
    menu.addDish(new Dessert("Chocolate Cake", 4.99, true));
}

Restaurant::Restaurant(const Restaurant& other)
    : menu(other.menu), customers(other.customers), orders(other.orders) {}

Restaurant& Restaurant::operator=(const Restaurant& other) {
    if (this != &other) {
        menu = other.menu;
        customers = other.customers;
        orders = other.orders;
    }
    return *this;
}

Restaurant::Restaurant(Restaurant&& other) noexcept
    : menu(std::move(other.menu)), customers(std::move(other.customers)), orders(std::move(other.orders)) {}

Restaurant& Restaurant::operator=(Restaurant&& other) noexcept {
    if (this != &other) {
        menu = std::move(other.menu);
        customers = std::move(other.customers);
        orders = std::move(other.orders);
    }
    return *this;
}

Restaurant::~Restaurant() {}

void Restaurant::showMenu() const {
    menu.displayMenu();
}

Customer* Restaurant::getCustomerByName(const std::string& name) const {
    for (auto& customer : customers) {
        if (customer->getName() == name) {
            return customer;
        }
    }
    return nullptr;
}

void Restaurant::placeNewOrder(const std::string& customerName) {
    Customer* customer = getCustomerByName(customerName);
    if (!customer) {
        std::cout << "Customer not found. Please enter customer details.\n";
        return;
    }

    Order newOrder(customer);

    std::string dishName;
    std::cout << "Enter dishes to order (type 'done' when finished):\n";
    while (true) {
        std::cout << "Dish name: ";
        std::getline(std::cin, dishName);
        if (dishName == "done") {
            break;
        }

        Dish* dish = menu.getDishByName(dishName);
        if (dish) {
            newOrder.addDish(dish);
            std::cout << dishName << " added to order.\n";
        } else {
            std::cout << "Dish not found. Please try again.\n";
        }
    }

    orders.push_back(newOrder);
    customer->placeOrder(newOrder);
}

void Restaurant::viewCustomerOrderHistory(const std::string& customerName) const {
    Customer* customer = getCustomerByName(customerName);
    if (customer) {
        customer->viewOrderHistory();
    } else {
        std::cout << "Customer not found.\n";
    }
}
