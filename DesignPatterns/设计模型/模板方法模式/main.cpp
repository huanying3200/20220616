#include <iostream>

class DrinkTemplate
{
public:
    //煮水
    virtual void bolidWater() = 0;
    //冲泡
    virtual void Brew() = 0;
    //导入杯中
    virtual void PourInCup() = 0;
    //加辅助材料
    virtual void addSomething() = 0;

    void make()
    {
        bolidWater();
        Brew();
        PourInCup();
        addSomething();
    }
};

//冲泡咖啡
class Coffee : public DrinkTemplate
{
    //煮水
    virtual void bolidWater()
    {
        std::cout << "煮山泉水..." << std::endl;
    }
    //冲泡
    virtual void Brew()
    {
        std::cout << "冲泡咖啡..." << std::endl;
    }
    //导入杯中
    virtual void PourInCup()
    {
        std::cout << "咖啡倒入杯中..." << std::endl;
    }
    //加辅助材料
    virtual void addSomething()
    {
        std::cout << "加糖，加牛奶，加点醋..." << std::endl;
        
    }
};

//冲泡茶水
class Tea : public DrinkTemplate
{
    //煮水
    virtual void bolidWater()
    {
        std::cout << "煮自来水..." << std::endl;
    }
    //冲泡
    virtual void Brew()
    {
        std::cout << "冲泡茶..." << std::endl;
    }
    //导入杯中
    virtual void PourInCup()
    {
        std::cout << "茶叶倒入杯中..." << std::endl;
    }
    //加辅助材料
    virtual void addSomething()
    {
        std::cout << "加糖，加柠檬..." << std::endl;
        
    }
};


void test01()
{
Tea* tea=new Tea();
tea->make();
std::cout<<"................."<<std::endl;
Coffee* coffee=new Coffee;
coffee->make();
}

int main(int argc, char* argv[])
{
    test01();
    return 0;
}
