#include <iostream>
#include "Restaurant.h"

int main() {
    Restaurant restaurant;

    restaurant.showMenu();

    Customer* customer1 = new Customer("John Doe", "john.doe@example.com");
    restaurant.placeNewOrder("John Doe");

    restaurant.viewCustomerOrderHistory("John Doe");

    delete customer1;
    return 0;
}
