#include <iostream>
#include <string>

using namespace std;

//Base class
class Vehicle {
public:
    virtual void move() = 0;
    void setName(string name) {
        vname = name;
    }
    void printName() {
        cout << "My name is: " << vname << endl;
    }

protected:
    string vname;
};

//Derived class
class Bicycle: public Vehicle {
public:
    void move() {
        cout << "I'm a moving bicycle" << endl;
    }
};

int main() {
    Bicycle bike;
    Vehicle *vehicle;

    bike.setName("bicycle");
    bike.move();
    bike.printName();
    vehicle = &bike;
    vehicle->printName();
    vehicle->move();

    return 0;
}
