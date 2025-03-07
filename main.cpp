#include <iostream>
#include "Restaurant.h"

int main() {
    Restaurant restaurant;

    std::cout << "Welcome to the restaurant! Here is the menu:\n";
    restaurant.showMenu();

    Customer* customer1 = new Customer("John Doe", "john.doe@example.com");
 
    std::cout << "\nPlacing a new order for " << customer1->getName() << "...\n";
    restaurant.placeNewOrder(customer1->getName());


    std::cout << "\nViewing order history for " << customer1->getName() << "...\n";
    restaurant.viewCustomerOrderHistory(customer1->getName());


    delete customer1;

    std::cout << "\nThank you for visiting the restaurant! Goodbye.\n";
    return 0;
}
