#include <iostream>

using namespace std;

// абстрактний клас Animal
class Animal
{
public:
    virtual void setName(string *name) {}
    virtual string getName() = 0;
    virtual Animal *clone() const = 0;
};

// конкретний клас Sheep
class Sheep : public Animal
{
private:
    string *name;
    // приватний конструктор копіювання
    Sheep(const Sheep &donor)
    {
        this->name = donor.name;
    }

    // конструктор по замовчуванню
public:
    Sheep() {}
    // деструктор
    ~Sheep()
    {
        delete name;
    }
    // переоголошення setName()
    void setName(string *name) override
    {
        this->name = name;
    }
    // getName()
    string getName() override
    {
        return *name;
    }
    // метод клонування що повертає вказівник на екземпляр тварини
    Sheep *clone() const
    {
        return new Sheep(*this);
    }
};

int main()
{
    // екземпляр тварини донора
    Sheep *sheepDonor = new Sheep();
    string name = "Meme";
    sheepDonor->setName(&name);

    // sheepClone()
    Sheep *sheepClone = sheepDonor->clone();

    cout << sheepDonor->getName() << endl;
    cout << sheepClone->getName() << endl;
}