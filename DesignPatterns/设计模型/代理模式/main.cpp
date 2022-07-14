#include <iostream>

//提供一种方式来控制对其他对象的访问
class AbstractCommonInterface
{
public:
    virtual void run() = 0;
};

class MySystem : public AbstractCommonInterface
{
public:
    virtual void run()
    {
        std::cout << "系统启动..." << std::endl;
    }
};

//必须有要权限验证，不是所有人都能来启动我的启动，提供用户名和密码

class MySystemProxy : public AbstractCommonInterface
{
public:
    MySystemProxy(std::string userName, std::string Password)
    {
        this->m_Username = userName;
        this->m_Password = Password;
        pSystem = new MySystem;
    }
    ~MySystemProxy()
    {
        if (pSystem != NULL)
        {
            delete pSystem;
        }
    }

    bool checkUserNameAndPassword()
    {
        if (m_Username == "admin" && m_Password == "admin")
        {
            return true;
        }
        else
            false;
    }
    virtual void run()
    {
        if (checkUserNameAndPassword())
            std::cout << "验证通过，系统启动..." << std::endl;
        else
        {
            std::cout << "用户名或者密码错误，权限不足..." << std::endl;
        }
    }

public:
    MySystem *pSystem;
    std::string m_Username;
    std::string m_Password;
};

void test01()
{
    MySystemProxy* proxy=new MySystemProxy("admin","dmin");
    proxy->run();

}

int main()
{
    test01();
    return 0;
}