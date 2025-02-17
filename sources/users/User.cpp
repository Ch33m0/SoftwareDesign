
#include <random>
#include "User.h"

bool User::isTime(double time) {
    return ((*this).nextJobTime-time>0);
}

double User::getBudget() {
    return (*this).budget;
}

double User::getSpendings() {
    return (*this).spendings;
}

bool User::spend(double newSpendings) {
    if ((*this).spendings+newSpendings < (*this).budget){
        (*this).spendings += newSpendings;
        return true;
    }
    return false;
}

double User::generateNewTime() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::exponential_distribution<> d((*this).expoParameter);
    return d(gen);
}

std::array<bool,5> User::getPermission() {
    return (*this).permission;
}
