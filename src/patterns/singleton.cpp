/*

Название:   singleton (одиночка)
Тип:        порождающий
Назначение: гарантирует, что у класса существует только один
            экземпляр, и предоставляет к нему глобальную
            точку доступа
            
*/

class Singleton
{
private:
    static Singleton* _instance;
public:
    static Singleton* Instance();
    ~Singleton();
protected:
    Singleton();
};

Singleton::Singleton(){}

Singleton::~Singleton(){}

Singleton* Singleton::_instance = 0;

Singleton* Singleton::Instance() {
    if (_instance == 0) {
        _instance = new Singleton();
    }
    return _instance;
};