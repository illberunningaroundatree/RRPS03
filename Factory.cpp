#include <iostream>

using namespace std;

// інтерфейс IProduction
class IProduction
{
public:
    virtual void release() = 0;
};

// клас легкового авто, використовуючи інтерфейс IProduction
class Car : public IProduction
{
public:
    void release() override
    {
        cout << "A new Car has been released" << endl;
    }
};

// груз. авто
class Truck : public IProduction
{
public:
    void release() override
    {
        cout << "A new Truck has been released" << endl;
    }
};

// інтерфейс цеху, що повертає *авто*
class IWorkShop
{
public:
    virtual IProduction *create() = 0;
};

// цех по виробництву легкового авто
class CarWorkShop : public IWorkShop
{
public:
    IProduction *create() override
    {
        return new Car();
    }
};

// цех по тракам
class TruckWorkShop : public IWorkShop
{
public:
    IProduction *create() override
    {
        return new Truck();
    }
};

int main()
{
    // екземпляр цеху
    IWorkShop *creator = new CarWorkShop();

    // виконання методу - створить авто
    IProduction *car = creator->create();

    // перевказуємо цех на створення траків
    creator = new TruckWorkShop();

    // тепер виклик методу create() створить трак
    IProduction *truck = creator->create();

    car->release();
    truck->release();

    return 0;
}