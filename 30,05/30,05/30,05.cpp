#include <iostream>
using namespace std;

class WaterSupply
{
public:
    void FillWater()
    {
        cout << "Filling water\n";
    }

    void DrainWater()
    {
        cout << "Draining water\n";
    }
};

class DetergentDispenser
{
public:
    void AddDetergent()
    {
        cout << "Adding detergent\n";
    }
};

class Washer
{
public:
    void StartWashing()
    {
        cout << "Starting washing\n";
    }

    void StopWashing()
    {
        cout << "Stopping washing\n";
    }
};

class Dryer
{
public:
    void StartDrying()
    {
        cout << "Starting drying\n";
    }

    void StopDrying()
    {
        cout << "Stopping drying\n";
    }
};

class WashingMachineFacade
{
public:
    WashingMachineFacade()
        : waterSupply(new WaterSupply()), detergentDispenser(new DetergentDispenser()),
        washer(new Washer()), dryer(new Dryer()) {}

    ~WashingMachineFacade()
    {
        delete waterSupply;
        delete detergentDispenser;
        delete washer;
        delete dryer;
    }

    void StartFullWashCycle()
    {
        waterSupply->FillWater();
        detergentDispenser->AddDetergent();
        washer->StartWashing();
        washer->StopWashing();
        waterSupply->DrainWater();
        dryer->StartDrying();
        dryer->StopDrying();
    }

private:
    WaterSupply* waterSupply;
    DetergentDispenser* detergentDispenser;
    Washer* washer;
    Dryer* dryer;
};

int main()
{
    WashingMachineFacade washingMachine;
    washingMachine.StartFullWashCycle();
    return 0;
}
