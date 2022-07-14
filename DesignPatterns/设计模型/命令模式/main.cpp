#include <iostream>
#include <queue>
using namespace std;

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32

//处理协议类
class HandleClientProtocol
{
public:
    void AddMoney()
    {
        std::cout << "给玩家增加金币！" << std::endl;
    }

    void AddDiamond()
    {
        std::cout << "给玩家增加钻石！" << std::endl;
    }

    void AddEquipment()
    {
        std::cout << "给玩家增加装备！" << std::endl;
    }

    void AddLevel()
    {
        std::cout << "给玩家升级" << std::endl;
    }
};

class AbstractCommand
{
public:
    virtual void handle() = 0;
};

//处理玩家冲金币请求
class AddMoneyCommand : public AbstractCommand
{
public:
    AddMoneyCommand(HandleClientProtocol *protocol)
    {
        this->protocol = protocol;
    }
    virtual void handle()
    {
        protocol->AddMoney();
    }

private:
    HandleClientProtocol *protocol;
};

//处理玩家冲钻石请求
class AddDiamondCommand : public AbstractCommand
{
public:
    AddDiamondCommand(HandleClientProtocol *protocol)
    {
        this->protocol = protocol;
    }
    virtual void handle()
    {
        protocol->AddDiamond();
    }

private:
    HandleClientProtocol *protocol;
};

//处理玩家穿装备请求
class AddEquipmentCommand : public AbstractCommand
{
public:
    AddEquipmentCommand(HandleClientProtocol *protocol)
    {
        this->protocol = protocol;
    }
    virtual void handle()
    {
        this->protocol->AddEquipment();
    }

private:
    HandleClientProtocol *protocol;
};

//处理玩家升级请求
class AddLevelCommand : public AbstractCommand
{
public:
    AddLevelCommand(HandleClientProtocol *protocol)
    {
        this->protocol = protocol;
    }
    virtual void handle()
    {
        this->protocol->AddLevel();
    }

private:
    HandleClientProtocol *protocol;
};

class Server
{
public:
    void addRequest(AbstractCommand *command)
    {
        this->m_commands.push(command);
    }

    void startHandle()
    {
        while (!this->m_commands.empty())
        {
            sleep(3);
            AbstractCommand *command = m_commands.front();
            command->handle();
            m_commands.pop();
        }
    }

private:
    queue<AbstractCommand *> m_commands;
};


void test01()
{
    HandleClientProtocol* protocol=new HandleClientProtocol;

    AbstractCommand* addMoney=new AddMoneyCommand(protocol);//AddMoneyCommand;
    AbstractCommand* addDiamond=new AddDiamondCommand(protocol);
    AbstractCommand* addEquipment=new AddEquipmentCommand(protocol);//AddMoneyCommand;
    AbstractCommand* addLevel=new AddLevelCommand(protocol);

    Server* server=new Server;
    server->addRequest(addMoney);
    server->addRequest(addDiamond);
    server->addRequest(addEquipment);
    server->addRequest(addLevel);

    server->startHandle();
    
}

int main(int argc, char *argv[])
{
    test01();

    return 0;
}