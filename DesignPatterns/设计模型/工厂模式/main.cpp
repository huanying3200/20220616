#include <iostream>
//简单工厂模式
//抽象水果
class AbstractFruit
{
public:
    virtual void showName() = 0;
};

//苹果
class Apple : public AbstractFruit
{
public:
    virtual void showName()
    {
        std::cout << "我是苹果" << std::endl;
    }
};

//香蕉
class Banana : public AbstractFruit
{
public:
    virtual void showName()
    {
        std::cout << "我是香蕉" << std::endl;
    }
};

//鸭梨
class Pear : public AbstractFruit
{
public:
    virtual void showName()
    {
        std::cout << "我是鸭梨" << std::endl;
    }
};

//水果工厂
class FruitFactory
{
public:
    static AbstractFruit *CreateFruit(std::string flag)
    {
        if (flag.compare("apple") == 0)
        {
            return new Apple;
        }
        else if (flag.compare("banana") == 0)
        {
            return new Banana;
        }
        else if (flag.compare("pear") == 0)
        {
            return new Pear;
        }
        else
        {
            return NULL;
        }
    }
};

void eatFruit()
{
    FruitFactory* factory=new FruitFactory;
    AbstractFruit* fruit=factory->CreateFruit("apple");
    fruit->showName();
    delete fruit;
    
    fruit=factory->CreateFruit("banana");
    fruit->showName();
    delete fruit;

    fruit=factory->CreateFruit("pear");
    fruit->showName();
    delete fruit;

    delete factory;
}

int main(void)
{
    eatFruit();
    return 0;
}