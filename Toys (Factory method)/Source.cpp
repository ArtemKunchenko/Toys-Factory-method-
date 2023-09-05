#include<iostream>
using namespace std;

class InjectionMold 
{
public:
    virtual void Toy() = 0;
};


class ToyDuckMold : public InjectionMold 
{
public:
    void Toy() override {   cout << "Toy \"Duck\" is created." << endl; }
};


class ToyCarMold : public InjectionMold 
{
public:
    void Toy() override {cout << "Toy \"Car\" is created." << endl;}
};

class Manufacturer 
{
public:
    virtual InjectionMold* createToy() = 0;
};

class ToyDuckManufacturer : public Manufacturer 
{
public:
    InjectionMold* createToy() override {return new ToyDuckMold();}
};

class ToyCarManufacturer : public Manufacturer 
{
public:
    InjectionMold* createToy() override { return new ToyCarMold();}
};


int main()
{
    Manufacturer* toyDuckManufacturer = new ToyDuckManufacturer();
    Manufacturer* toyCarManufacturer = new ToyCarManufacturer();
    InjectionMold* toyDuckMold = toyDuckManufacturer->createToy();
    InjectionMold* toyCarMold = toyCarManufacturer->createToy();

    toyDuckMold->Toy();
    toyCarMold->Toy();

	system("pause");
	return 0;
}