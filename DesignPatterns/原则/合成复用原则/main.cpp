#include <iostream>
using namespace std;

class AbstractCar
{
public:
    virtual void run() = 0;
};

//抽象车
class Dazhong : public AbstractCar
{
public:
    virtual void run()
    {
        std::cout << "大众车启动..." << std::endl;
    }
};

//拖拉车
class Tuolaji : public AbstractCar
{
public:
    virtual void run()
    {
        std::cout << "拖拉机启动..." << std::endl;
    }
};

// //继承
// class Person:public Tuolaji
// {
//     public:
//     void Doufeng()
//     {
//         run();
//     }
// };

// class PersonB:public Dazhong
// {
//     public:
//     void Doufeng()
//     {
//         run();
//     }
// };

class Person
{
public:
    void setCar(AbstractCar *car)
    {
        this->car = car;
    }
    void Doufeng()
    {
        this->car->run();
    }

    ~Person()
    {
        if (this->car != NULL)
        {
            std::cout<<"~Person"<<std::endl;
            delete car;
            this->car=NULL;
        }
    }

public:
    AbstractCar *car;

};

int
main(void)
{
    Person p;
    p.setCar(new Dazhong);
    p.Doufeng();
    return 0;
}