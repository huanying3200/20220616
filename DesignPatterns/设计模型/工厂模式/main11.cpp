#include <iostream>
//工厂方法模式
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

class AbstractFactory
{
public:
    virtual AbstractFruit *CreateFruit() = 0;
};
//水果工厂
class AppleFruitFactory : public AbstractFactory
{
public:
    virtual AbstractFruit *CreateFruit()
    {

        return new Apple;
    }
};

class BananaFruitFactory : public AbstractFactory
{
public:
    virtual AbstractFruit *CreateFruit()
    {

        return new Banana;
    }
};

class PearFruitFactory : public AbstractFactory
{
public:
    virtual AbstractFruit *CreateFruit()
    {

        return new Pear;
    }
};

void eatFruit()
{
    AbstractFactory *factory = new AppleFruitFactory;
    AbstractFruit *fruit = factory->CreateFruit();
    fruit->showName();
    delete fruit;
    delete factory;

    factory = new BananaFruitFactory;
    fruit = factory->CreateFruit();
    fruit->showName();
     delete fruit;
    delete factory;

factory = new BananaFruitFactory;
    fruit = factory->CreateFruit("pear");
    fruit->showName();
    delete fruit;

    delete factory;
}

int main(void)
{
    eatFruit();
    return 0;
}