//Design a piza store that calculates cost with different types of toppings on a base piza.

#include <iostream>
using namespace std;

class BasePiza
{
    public:
    virtual int cost() = 0;
};

class Farmhouse : public BasePiza
{
    public:  
    int cost()
    {
        return 200;
    }
};

class Margherita : public BasePiza
{
    public:
    int cost()
    {
        return 100;
    }
};

class Vegdelight : public BasePiza
{
    public:
    int cost()
    {
        return 150;
    }
};

class MushroomDecorator : public BasePiza
{
    BasePiza *piza;
    public:
    
    MushroomDecorator(BasePiza *piza)
    {
        this->piza = piza;
    }
    
    int cost()
    {
        return this->piza->cost() + 20;
    }
};

class ExtraCheeseDecorator : public BasePiza
{
    BasePiza *piza;
    public:
    
    ExtraCheeseDecorator(BasePiza *piza)
    {
        this->piza = piza;
    }
    
    int cost()
    {
        return this->piza->cost() + 50;
    }
};

class ExtraVegisDecorator : public BasePiza
{
    BasePiza *piza;
    public:
    
    ExtraVegisDecorator(BasePiza *piza)
    {
        this->piza = piza;
    }
    
    int cost()
    {
        return this->piza->cost() + 30;
    }
};

int main()
{
    BasePiza *piza = new MushroomDecorator(new ExtraCheeseDecorator((new Margherita)));
    cout<<"Cost of Piza with extra cheese and Mushroom with Margherita base: "<<piza->cost();
    return 0;
}




