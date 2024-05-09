// виконання роботи системи збору інформації з різних ресурсів, у кожного своя стратегія
#include <iostream>
#include <string>

using namespace std;

// інтерфейс Reader
class Reader
{
public:
    // деструктор
    virtual ~Reader() {}
    // парс
    virtual void parse(string& url) = 0;
};

class ResourceReader
{
    // поле reader, що є стратегію читання ресурсу
private:
    Reader* reader;
public:
    // ініціалізація
    ResourceReader(Reader* r) : reader(r){};
    // видаляємо вказівник
    ~ResourceReader() { delete reader; }

    // setStrategy()
    void setStrategy(Reader* r)
    {
        if (reader != nullptr)
            delete reader;
        reader = r;
    }
    void read(string &url)
    {
        reader->parse(url);
    }
};

// інтерфейс класу NewsSiteReader використовуючи Reader
class NewsSiteReader : public Reader
{
public:
    void parse(string &url) override
    {
        cout << "parsing from a news site.." << url << endl;
    }
};

class SocialNetworkReader : public Reader
{
public:
    void parse(string &url) override
    {
        cout << "a network feed's parsing..." << url << endl;
    }
};

class TelegramChannelReader : public Reader
{
public:
    void parse(string &url) override
    {
        cout << "a telegram's channel parsing..." << url << endl;
    }
};

int main()
{
    // створюємо екземпляр класу resourseReader, початкова стратегія - NewsSiteReader
    ResourceReader *resourseReader = new ResourceReader(new NewsSiteReader());

    string url = "https://news.com";
    resourseReader->read(url);

    url = "https://facebook.com";
    resourseReader->setStrategy(new SocialNetworkReader());
    resourseReader->read(url);

    url = "@news_channel_telegram";
    resourseReader->setStrategy(new TelegramChannelReader());
    resourseReader->read(url);
}