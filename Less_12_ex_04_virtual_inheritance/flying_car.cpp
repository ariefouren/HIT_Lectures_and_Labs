//
// Flying Car 
// demonstrating virtual inheritance 
//
#include <iostream>
#include <string>

using namespace std;
class Vehicle
{
    static int numVehicles;

public:
    Vehicle()
    {
        serialNumber = ++numVehicles;
        cout << "A vehicle with serial number " 
            << serialNumber << " is created." << endl;
    }

    ~Vehicle() {
        cout << "A vehicle with serial number " 
            << serialNumber << " is destroyed." << endl;
    }

    int getSerialNumber() const {
        return serialNumber;
    }
    string toString() const {
        return "Vehicle: serial number = " + serialNumber;
    }
    
protected:
    int serialNumber;

};
class Car : virtual public Vehicle {
protected:
    string brand;

public:
    Car(const string& brand) : brand(brand) {
        cout << "A car of brand " << brand << " is created." << endl;
    }

    virtual void startEngine() {
        cout << "The car's engine started." << endl;
    }

    virtual string toString() const {
        return "Car: Brand=" + brand;
    }

    ~Car() {
        cout << "The car of brand " << brand << " is destroyed." << endl;
    }
};

class Airplane: virtual public Vehicle {
protected:
    string model;

public:
    Airplane(const string& model) : model(model) {
        cout << "An airplane of model " << model << " is created." << endl;
    }

    virtual void takeOff() {
        cout << "The airplane is taking off." << endl;
    }

    virtual string toString() const {
        return "Airplane: Model=" + model;
    }

    ~Airplane() {
        cout << "The airplane of model " << model << " is destroyed." << endl;
    }
};

class FlyingCar : public Car, public Airplane {
public:
    FlyingCar(const string& brand, const string& model)
        : Car(brand), Airplane(model) {
        cout << "A flying car of brand " << brand << " and model " << model << " is created." << endl;
    }

    // Override startEngine from Car
    virtual  void startEngine() override {
        cout << "The flying car's engine is starting." << endl;
    }

    // Override takeOff from Airplane
    virtual  void takeOff() override {
        cout << "The flying car is taking off like an airplane." << endl;
    }

    
    virtual string toString() const {
        return Car::toString() + ", " + Airplane::toString();
    }
    

    ~FlyingCar() {
        cout << "The flying car of brand " << brand << " and model " << model << " is destroyed." << endl;
    }
};

int Vehicle::numVehicles = 0;

int main() {
    FlyingCar flyingCar("XYZ Motors", "Flying Carpet 2023");

    // demonstrating access to the member of the base class 
    cout << "\nflyingCar.Car::getSerialNumber() = " 
        << flyingCar.Car::getSerialNumber() << endl;

    cout << "flyingCar.Airplane::getSerialNumber() = "
        << flyingCar.Airplane::getSerialNumber() << endl << endl;

    cout << "flyingCar.getSerialNumber() = " 
        << flyingCar.getSerialNumber() << endl; // Now it's OK
                                    // due to virtual inheritance 

    return 0;
}
