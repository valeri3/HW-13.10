#include"Mylibrary.h"
/*��:
* 1.������� ����� ������� �� ������ Animal, ����������� ������ ����������
* 2. ������� ����� �������, � ����������� ������ ���������.
* 3. ������� �������, ������� ����� �������� � � �������� ������ �������, � � �������� ������ �������!!

*/

class Ship :public iSwim 
{
public:
    virtual void Swim() 
    {
        cout << "������� - ������ ���������\n";
    }
};

class Airplane : public iFly 
{
public:
    virtual void Fly() 
    {
        cout << "�������� ������ � ����\n";
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
    Pinguin obj("����������� �������", 100, "�������");
    Parrot obj1("���������", 0.2, "�������");

    //iSwim* ptr = &obj;
    //ptr->Swim();

    Ship sh;
    Func(&obj);
    Func(&sh);

    Airplane pl;
    Func(&pl);
    Func(&obj1);
}