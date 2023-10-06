#include"Mylibrary.h"
/*дз:
* 1.Создать класс Попугай на основе Animal, реализовать нужные интерфейсы
* 2. Создать класс Самолет, и реализовать нужный интерфейс.
* 3. Создать функцию, который может работать и с объектом класса самолет, и с объектом класса попугай!!

*/

class Ship :public iSwim 
{
public:
    virtual void Swim() 
    {
        cout << "Корабль - водный транспорт\n";
    }
};

class Airplane : public iFly 
{
public:
    virtual void Fly() 
    {
        cout << "Самолеты летают в небе\n";
    }
};

void Func(iFly* ptr) 
{
    ptr->Fly();
}

void Func(iSwim* ptr) 
{
    ptr->Swim();
}

int main()
{
    setlocale(0, "ru");
    Pinguin obj("Королевский пингвин", 100, "Арктика");
    Parrot obj1("Волнистые", 0.2, "Украина");

    //iSwim* ptr = &obj;
    //ptr->Swim();

    Ship sh;
    Func(&obj);
    Func(&sh);

    Airplane pl;
    Func(&pl);
    Func(&obj1);
}