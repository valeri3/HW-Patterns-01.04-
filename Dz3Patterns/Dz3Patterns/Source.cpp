#include <iostream>
#include <string>
#include <clocale>

using namespace std;

class Car 
{
    string name;
    string body;
    int enginePower;
    int wheelSize;
    string transmission;
public:
    void SetName(const string& name)
    { 
        this->name = name; 
    }
    void SetBody(const string& body)
    { 
        this->body = body;
    }
    void SetEnginePower(int enginePower)
    { 
        this->enginePower = enginePower;
    }
    void SetWheelSize(int wheelSize)
    { 
        this->wheelSize = wheelSize;
    }
    void SetTransmission(const string& transmission)
    { 
        this->transmission = transmission;
    }

    void ShowCar() const 
    {
        cout << "Автомобиль: " << name << "\nКузов: " << body << "\nМощность двигателя: " << enginePower << " л.с."
            << "\nКолёса: R" << wheelSize << "\nТрансмиссия: " << transmission << endl;
    }

};

class CarBuilder abstract
{
protected:
    Car car;
public:
    Car GetCar() 
    { 
        return car; 
    }
    virtual void BuildName() abstract;
    virtual void BuildBody() abstract;
    virtual void BuildEnginePower() abstract;
    virtual void BuildWheelSize() abstract;
    virtual void BuildTransmission() abstract;
};

class DaewooLanosBuilder : public CarBuilder 
{
public:
    void BuildName() override 
    { 
        car.SetName("Daewoo Lanos"); 
    }
    void BuildBody() override 
    { 
        car.SetBody("Седан");
    }
    void BuildEnginePower() override 
    { 
        car.SetEnginePower(98);
    }
    void BuildWheelSize() override 
    {
        car.SetWheelSize(13); 
    }
    void BuildTransmission() override 
    { 
        car.SetTransmission("5 Manual");
    }
};

class FordProbeBuilder : public CarBuilder 
{
public:
    void BuildName() override 
    { 
        car.SetName("Ford Probe");
    }
    void BuildBody() override 
    { 
        car.SetBody("Купе");
    }
    void BuildEnginePower() override 
    { 
        car.SetEnginePower(160);
    }
    void BuildWheelSize() override 
    { 
        car.SetWheelSize(14);
    }
    void BuildTransmission() override 
    { 
        car.SetTransmission("4 Auto");
    }
};

class UAZPatriotBuilder : public CarBuilder
{
public:
    void BuildName() override
    {
        car.SetName("UAZ Patriot");
    }
    void BuildBody() override
    {
        car.SetBody("Универсал");
    }
    void BuildEnginePower() override
    {
        car.SetEnginePower(120);
    }
    void BuildWheelSize() override
    {
        car.SetWheelSize(16);
    }
    void BuildTransmission() override
    {
        car.SetTransmission("4 Manual");
    }
};

class HyundaiGetzBuilder : public CarBuilder
{
public:
    void BuildName() override
    {
        car.SetName("Hyundai Getz");
    }
    void BuildBody() override
    {
        car.SetBody("Хетчбэк");
    }
    void BuildEnginePower() override
    {
        car.SetEnginePower(66);
    }
    void BuildWheelSize() override
    {
        car.SetWheelSize(13);
    }
    void BuildTransmission() override
    {
        car.SetTransmission("4 Auto");
    }
};

class Shop 
{
    CarBuilder* carBuilder;
public:
    void SetCarBuilder(CarBuilder* cb)
    { 
        carBuilder = cb;
    }
    
    Car GetCar()
    {
        return carBuilder->GetCar();
    }

    void ConstructCar() 
    {
        carBuilder->BuildName();
        carBuilder->BuildBody();
        carBuilder->BuildEnginePower();
        carBuilder->BuildWheelSize();
        carBuilder->BuildTransmission();
    }
};

void main() 
{
    setlocale(LC_ALL, "Russian");

    Shop shop;

    // Daewoo Lanos
    DaewooLanosBuilder lanosBuilder;
    shop.SetCarBuilder(&lanosBuilder);
    shop.ConstructCar(); 
    Car lanos = shop.GetCar(); 
    lanos.ShowCar(); 

    cout << endl;

    // Ford Probe
    FordProbeBuilder probeBuilder;
    shop.SetCarBuilder(&probeBuilder);
    shop.ConstructCar();
    Car probe = shop.GetCar();
    probe.ShowCar();

    cout << endl;

    // UAZ Patriot
    UAZPatriotBuilder uazBuilder;
    shop.SetCarBuilder(&uazBuilder);
    shop.ConstructCar();
    Car uaz = shop.GetCar();
    uaz.ShowCar();

    cout << endl;

    // Hyundai Getz
    HyundaiGetzBuilder getzBuilder;
    shop.SetCarBuilder(&getzBuilder);
    shop.ConstructCar();
    Car getz = shop.GetCar();
    getz.ShowCar();

}