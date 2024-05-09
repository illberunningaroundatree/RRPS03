#include <iostream>

using namespace std;

// інтерфейс IEngine (абстрактне представлення релізу двигунів)
class IEngine
{
public:
    virtual void releaseEngine() = 0;
};

// клас JapaneseEngine використовуючи інтерфейс IEngine
class JapaneseEngine : public IEngine
{
public:
    void releaseEngine() override
    {
        cout << "JapaneseEngine" << endl;
    }
};

// клас UkrEngine
class UkrEngine : public IEngine
{
public:
    void releaseEngine() override
    {
        cout << "UkrEngine" << endl;
    }
};

// інтерфейс ICar (абстрактне представлення релізу авто)
class ICar
{
public:
    // метод releaseCar, куди передаємо двигун
    virtual void releaseCar(IEngine *engine) = 0;
};

// клас JapaneseCar використовуючи інтерфейс ICar
class JapaneseCar : public ICar
{
public:
    void releaseCar(IEngine *engine) override
    {
        cout << "Japanese Car was Made" << endl;
        engine->releaseEngine();
    }
};

// UkrCar
class UkrCar : public ICar
{
public:
    void releaseCar(IEngine *engine) override
    {
        cout << "Ukrainian Car was Made" << endl;
        engine->releaseEngine();
    }
};

// інтерфейс фабрики по виробництву двигунів та авто
class IFactory
{
public:
    virtual IEngine *createEngine() = 0;
    virtual ICar *createCar() = 0;
};

// JapaneseFactory за допомогою інтерфейсу IFactory
class JapaneseFactory : public IFactory
{
public:
    IEngine *createEngine() override
    {
        return new JapaneseEngine();
    }
    ICar *createCar() override
    {
        return new JapaneseCar();
    }
};

// UkrFactory
class UkrFactory : public IFactory
{
public:
    IEngine *createEngine() override
    {
        return new UkrEngine();
    }
    ICar *createCar() override
    {
        return new UkrCar();
    }
};

int main()
{
    // фабрика по релізу японських авто
    IFactory *jFactory = new JapaneseFactory();

    IEngine *jEngine = jFactory->createEngine();
    ICar *jCar = jFactory->createCar();

    jCar->releaseCar(jEngine);



    IFactory *uFactory = new UkrFactory();

    IEngine *uEngine = uFactory->createEngine();
    ICar *uCar = uFactory->createCar();

    jCar->releaseCar(uEngine);
}