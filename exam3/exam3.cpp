/*
Question 11
    We would like to design a few classes to handle vehicles in a parking garage. The garage will handle
Bicycles, Sedans, and SUVs, each at a different cost. Bicycle parking costs $120/month, Sedans cost
$650/month and SUVs cost $850/month (yes, these are NYC prices!). You’re asked to implement the
classes with the following restrictions:

 1. The Garage class can only store a single vector.
 2. You must provide a function to add a vehicle to the garage.
 3. You must provide a function in each class to return the cost, a double, to park that item. (i.e.
Sedan.cost() would return 650).
 4. You must provide a function in the Garage class to return the total income of the garage (i.e. Garage.income()
    would return 650 if only a sedan were parked in the garage).

    Below is a sample main() function for how the classes might be used.

int main () {
Sedan s1;
SUV s2;
SUV s3;
Bicycle b1;
Bicycle b2;
Garage parking ;
parking . addVehicle (s1); // adds 650 ( total is 650)
parking . addVehicle (s2); // adds 850 ( total is 1500)
parking . addVehicle (s3); // adds 850 ( total is 2350)
parking . addVehicle (b1); // adds 120 ( total is 2470)
parking . addVehicle (b2); // adds 120 ( total is 2590)
cout << parking . income () << endl ; // prints 2590
}
*/

#include <iostream>
#include <vector>
//#include <numeric> // for std::accumulate

using namespace std;

class Vehicle {
public:
    virtual double cost() const = 0; // Pure virtual function
    virtual Vehicle* clone() const = 0; // Pure virtual clone function
    virtual ~Vehicle() = default; // Virtual destructor
};
    
class Sedan : public Vehicle {
public:
    double cost() const override {
        return 650;
    }
    Vehicle* clone() const override {
        return new Sedan(*this);
    }
};

class SUV : public Vehicle {
public:
    double cost() const override {
        return 850;
    }
    Vehicle* clone() const override {
        return new SUV(*this);
    }
};

class Bicycle : public Vehicle {
public:
    double cost() const override {
        return 120;
    }
    Vehicle* clone() const override {
        return new Bicycle(*this);
    }
};

class Garage {
private:
    std::vector<Vehicle*> vehicles;
public:
    void addVehicle(const Vehicle& vehicle) {
        vehicles.push_back(vehicle.clone());
    }

    double income() const {
        double total = 0.0;
        for (const auto* v : vehicles) {
            total += v->cost();
        }
        return total;
    }

    /*
    double income() const {
        return std::accumulate(vehicles.begin(), vehicles.end(), 0.0,
            [](double sum, const Vehicle* v) {
                return sum + v->cost();
            });
    }
    */

    ~Garage() {
        for (auto v : vehicles) {
            delete v;
        }
    }
};

int main () {
Sedan s1;
SUV s2;
SUV s3;
Bicycle b1;
Bicycle b2;
Garage parking ;
parking . addVehicle (s1); // adds 650 ( total is 650)
parking . addVehicle (s2); // adds 850 ( total is 1500)
parking . addVehicle (s3); // adds 850 ( total is 2350)
parking . addVehicle (b1); // adds 120 ( total is 2470)
parking . addVehicle (b2); // adds 120 ( total is 2590)
cout << parking . income () << endl ; // prints 2590
}