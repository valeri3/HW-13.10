#pragma once
#include<iostream>
#include<string.h>

using namespace std;

struct iSwim 
{
    virtual void Swim() = 0;
};

struct iFly 
{
    virtual void Fly() = 0;
};

class Animal  // абстрактный класс !!
{
protected:
    char* name;
    int kg;
public:
    Animal() = default;
    Animal(const char* n, double k)
    {
        name = new char[strlen(n) + 1];
        strcpy_s(name, strlen(n) + 1, n);
        kg = k;
    }
    void Print()
    {
        cout << "Name: " << name << "Kg: " << kg << endl;
    }
    virtual void Continent() = 0;
    virtual void Eat() = 0;
    virtual void Sound() = 0;

    ~Animal()
    {
        delete[] name;
    }
};

class Pinguin : public Animal, public iSwim //Реализация интерфейса
{
    char* continent;

public:
    Pinguin() = default;
    Pinguin(const char* n, double kg, const char* cont) :Animal(n, kg)
    {
        continent = new char[strlen(cont) + 1];
        strcpy_s(continent, strlen(cont) + 1, cont);
    }

    virtual void Eat()
    {
        cout << "Пингвины едят рыбу\n";
    }
    virtual void Sound()
    {
        cout << "Пингвины издают какие то звуки\n";
    }
    virtual void Continent()
    {
        cout << "Пингвины живут в Антарктиде\n";
    }

    virtual void Swim()
    {
        cout << "Пингвины отлично плавают\n";
    }

    ~Pinguin()
    {
        delete[] continent;
    }
};

class Parrot : public Animal, public iFly 
{
    char* habitat;
public:
    Parrot() = default;
    Parrot(const char* n, double kg, const char* hab) : Animal(n, kg) 
    {
        habitat = new char[strlen(hab) + 1];
        strcpy_s(habitat, strlen(hab) + 1, hab);
    }

    virtual void Eat() 
    {
        cout << "Попугаи едят семена\n";
    }
    virtual void Sound() 
    {
        cout << "Попугаи издают разнообразные звуки\n";
    }
    virtual void Continent() 
    {
        cout << "Попугаи живут в Одессе)))\n";
    }

    virtual void Fly() 
    {
        cout << "Попугаи могут летать\n";
    }

    ~Parrot() {
        delete[] habitat;
    }
};