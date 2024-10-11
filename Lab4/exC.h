#include <string>

using namespace std;

// interface movable 
class Movable {
    public:
        virtual void forward() = 0;
        virtual void backward() = 0;
        virtual ~Movable() {}; // destructor 
};

// interface for Resizeable
class Resizeable {
    public:
        virtual void enlarge (int n) = 0;
        virtual void shrink (int n) = 0;
        virtual ~Resizeable() {}; // destructor
};

// abstract class vehicle uses both interfaces
class Vehicle : public Movable, public Resizeable{
    protected:
        string name;
    public:
        Vehicle(const string& name) : name(name) {}
        virtual void move() = 0; // pure virtual so abstract class
        virtual ~Vehicle() {}; // destructor
        void forward();
        void backward();
        void enlarge(int n);
        void shrink(int n);
};

// class Car uses Vehicle
class Car final: public Vehicle {
    private:
        int seats;
    public: 
        void turn();
        Car(const string& name, int seats) : Vehicle(name), seats(seats) {}
        ~Car() {}; 
};
// no need for a destructor as the destructor of the base class is called

