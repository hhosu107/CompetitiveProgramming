class ParkingSystem {
public:
  map<int, int> car_type_left;
  ParkingSystem(int big, int medium, int small) {
    car_type_left[1] = big;
    car_type_left[2] = medium;
    car_type_left[3] = small;
  }

  bool addCar(int carType) {
    if (car_type_left[carType] > 0) {
      car_type_left[carType] -= 1;
      return true;
    }
    return false;
  }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
