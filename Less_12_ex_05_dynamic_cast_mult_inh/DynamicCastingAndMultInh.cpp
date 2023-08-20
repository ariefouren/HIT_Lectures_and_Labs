//
// demonstrating dynamic casting and multiple inheritance 
//
#include <iostream>
#include <string>

using namespace std;

using namespace std;

class Machine {
public:
    Machine(double weight = 1000) : weight(weight) {};
    virtual double getWeight() const { return weight; };

protected: 
    double weight;

};

class Vehicle: virtual public Machine {
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
    virtual string toString() const {
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
        string str = "Car: serial number = " + getSerialNumber();
        return str;
    }

    ~Car() {
        cout << "The car of brand " << brand << " is destroyed." << endl;
    }
};

class Airplane : public Vehicle {
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
        return "Airplane: " + Vehicle::toString() + ", " +
            "Model = " + model;
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
        return "Flying car: " + 
            Car::toString() + ", " + 
            Airplane::toString();
    }


    ~FlyingCar() {
        cout << "The flying car of brand " << brand << " and model " << model << " is destroyed." << endl;
    }
};

int Vehicle::numVehicles = 0;

int main() {
    FlyingCar* flyingCarPtr = 
        new FlyingCar("XYZ Motors", "Flying Carpet 2023");
   
    // for dynamic cast, the pointer should be to a polymorphic class
    // (class with at least one virtual function)
    
    // demonstrating dynamic upcast
    cout << "\n=== demonstrating dynamic upcast ===\n";
    
    // OK. upcasting from FlyinCar* to Vehicle* 
    // through Car* is unambiguous 
    Car* carPtr = dynamic_cast<Car*>(flyingCarPtr); 
    Vehicle* vehiclePtr1 = dynamic_cast<Vehicle*>(carPtr);
    cout << "Vehicle (trough Car): serial number = "
        << vehiclePtr1->getSerialNumber() << endl;

    // OK. upcasting from FlyingCar* to Vehicle* 
    // through Airplane* is unambiguous 
    Vehicle* vehiclePtr2 = dynamic_cast<Vehicle*>
        (dynamic_cast<Airplane*>(flyingCarPtr));
    cout << "Vehicle (trough Airplane): serial number = "
        << vehiclePtr2->getSerialNumber() << endl;

    // OK. the upcasting from FlyingCar* to Machine* is unambiguous.
    // there is only one copy of Machine object in 
    // FlyingCar object due to virtual inheritance from Machine
    Machine* machinePtr = dynamic_cast<Machine*>(flyingCarPtr);

    // ERROR ! upcasting to base class "Vehicle" is ambiguous.
    // inheritance of Car and Airplane from Vehicle is not virtual, therefore 
    // there are two objects that represent Vehicle in FlyingCar
    // Vehicle* vehiclePtr3 = dynamic_cast<Vehicle*>(flyingCarPtr);

    
    // demonstrating dynamic downcast
    cout << "\n=== demonstrating dynamic downcast ===\n";
    // OK, since FlyingCar is a Machine
    machinePtr = flyingCarPtr; 

    // ERROR ! downcast from Machine* to Vehicle* is incorrect
    // and generates a run-time error
    // vehiclePtr1 = dynamic_cast<Vehicle*>(machinePtr);
    // cout << vehiclePtr1->toString() << endl;

    // OK. downcast from Machine* to Car* is unambiguous  
    carPtr = dynamic_cast<Car*>(machinePtr);

    // OK. downcast from Machine* to FlyingCar* is unambiguous  
    FlyingCar* flyingCarPtr2 = dynamic_cast<FlyingCar*>(machinePtr);
    
    cout << "\nFlyingCar: Car serial number: " <<
        flyingCarPtr2->Car::getSerialNumber() << endl;

    cout << "FlyingCar: Airplane serial number: " <<
        flyingCarPtr2->Airplane::getSerialNumber() << endl<< endl;

    // OK
    vehiclePtr1 = dynamic_cast<Vehicle*>
        (dynamic_cast<Car*>
            (dynamic_cast<FlyingCar*>(machinePtr)));
    cout << "Vehicle (trough Car): serial number = " 
        << vehiclePtr1->getSerialNumber() << endl;
         
    // OK
    vehiclePtr2 = dynamic_cast<Vehicle*>
        (dynamic_cast<Airplane*>
            (dynamic_cast<FlyingCar*>(machinePtr)));
    cout << "Vehicle (trough Airplane): serial number = " 
        << vehiclePtr2->getSerialNumber() << endl;

    // demonstrating cross-casting
    cout << "\n=== demonstrating cross-casting ===\n";
    carPtr = dynamic_cast<Car*>(flyingCarPtr);
    cout << "Car: serial number = "
        << carPtr->getSerialNumber() << endl;

    Airplane* airplanePtr = dynamic_cast<Airplane*>(carPtr);
    cout << "Airplane: serial number = "
        << airplanePtr->getSerialNumber() << endl;
   return 0;
}
