#include <iostream>
#include <string>
#include <vector>
using namespace std;

//迪米特法则 又叫最少知识原则
class AbstractBuilding
{
public:
    virtual void sale() = 0;
    virtual string getQuality() = 0;
};

//楼盘A
class BuildingA : public AbstractBuilding
{
public:
    BuildingA()
    {
        m_Qulity = "高品质";
    }
    virtual void sale()
    {
        std::cout << "楼盘A" << m_Qulity << "被售卖！" << std::endl;
    }

    virtual string getQuality()
    {
        return m_Qulity;
    }

public:
    string m_Qulity;
};

//楼盘B
class BuildingB : public AbstractBuilding
{
public:
    BuildingB()
    {
        m_Qulity = "低品质";
    }
    virtual void sale()
    {
        std::cout << "楼盘B" << m_Qulity << "被售卖！" << std::endl;
    }

    virtual string getQuality()
    {
        return m_Qulity;
    }

public:
    string m_Qulity;
};

//中介类
class AbstractMediator
{
};

class MediatorA : public AbstractMediator
{
public:
    MediatorA()
    {
        AbstractBuilding *building = new BuildingA;
        vBuildings.push_back(building);
        building = new BuildingB;
        vBuildings.push_back(building);
    }

    //对外提供接口
    AbstractBuilding *findMyBuilding(string quality)
    {
        for (std::vector<AbstractBuilding *>::iterator it = vBuildings.begin(); it != vBuildings.end(); it++)
        {
            if ((*it)->getQuality() == quality)
                return *it;
        }
        return NULL;
    }

    ~MediatorA()
    {
        for (std::vector<AbstractBuilding *>::iterator it = vBuildings.begin(); it != vBuildings.end(); it++)
        {
            if (*it != NULL)
                delete *it;
        }
    }

public:
    std::vector<AbstractBuilding *> vBuildings;
};

//客户端
void test01()
{
    BuildingA *ba = new BuildingA;
    if (ba->m_Qulity.compare("低品质") == 0)
    {
        ba->sale();
    }

    BuildingB *bb = new BuildingB;
    if (bb->m_Qulity.compare("低品质") == 0)
    {
        bb->sale();
    }
}

void test02()
{
    MediatorA *mediator = new MediatorA;
    AbstractBuilding *building = mediator->findMyBuilding("低品质");
    if (building != NULL)
    {
        building->sale();
    }
    else
    {
        std::cout << "没有符合您条件的楼盘" << std::endl;
    }
}

int main(void)
{
    test01();
    return 0;
}