#include <iostream>
#include <string>

using namespace std;

// клас підключення до бд
class DatabaseHelper
{
    // конструктор робимо приватним, щоб не було створено екземляра класу
    DatabaseHelper()
    {
        cout << "Trying to connect to DB..." << endl;
    };

    // приватне поле вказівника на екземпляр класу
    static DatabaseHelper *databaseConnector;

    string data;

    // конструктор копіювання та оператор присвоювання - видаляємо без класу
public:
    DatabaseHelper(const DatabaseHelper &) = delete;
    void operator=(const DatabaseHelper &) = delete;

    // через публічний метод getConnection() - отримуємо посилання на єдиний екземпляр класу
    static DatabaseHelper *getConnection()
    {
        if (databaseConnector == nullptr)
            databaseConnector = new DatabaseHelper();
        return databaseConnector;
    }

    // метод selectData()
    string selectData() const
    {
        return data;
    }

    // метод insertData()
    void insertData(string d)
    {
        cout << "New data: " << d << " was added to DB" << endl;
        data = d;
    }
};

// занулюємо з'єднання
DatabaseHelper *DatabaseHelper::databaseConnector = nullptr;

int main()
{
    // спроба створити екземпляр класу DatabaseHelper
    // DatabaseHelper* connection = new DatabaseHelper();

    // через стат метод getConnection() - звертаємося до екземпляру класу, передаємо дату
    DatabaseHelper::getConnection()->insertData("Polonevych Denys");

    // конструктор класу викличеться лише 1 раз
    cout << "data from DB: " << DatabaseHelper::getConnection()->selectData() << endl;
}