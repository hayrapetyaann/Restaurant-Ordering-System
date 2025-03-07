#ifndef ENTREE_H
#define ENTREE_H

#include "Dish.h"

class Entree : public Dish {
private:
    int calories;
public:
    Entree(const std::string& dishName, double dishPrice, int cal);
    void display() const override;
};

#endif // ENTREE_H
