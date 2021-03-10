#include <cstdio>
#include <iostream>
#include <random>
#include <stack>
#include <unordered_map>
#include <vector>
#include "../data_type.h"

using namespace std;
class ParkingSystem {
    vector<int> A;

   public:
    ParkingSystem(int big, int medium, int small) {
        A = {0, big, medium, small};
    }

    bool addCar(int carType) {
        if (carType <= 0 || carType > 3)
            return 0;
        A[carType]--;
        return A[carType] >= 0;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
int main() {
    return 0;
}