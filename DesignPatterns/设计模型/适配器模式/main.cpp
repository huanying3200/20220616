#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//适配器模式 就是将已经写好的接口，但是这个接口不符合要求
//将写好的接口转换成目标接口

//这函数我已经写好了
struct MyPrint
{
    void operator()(int v1, int v2)
    {
        std::cout << v1 + v2 << std::endl;
    }
};

//定义目标接口 我要适配 适配成什么样的
class Target
{
public:
    virtual void operator()(int v) = 0;
};

//写适配器
class Adapter : public Target
{
public:
    Adapter(int val)
    {
        this->param = val;
    }

    virtual void operator()(int v)
    {
        myPrint(v, param);
    }

public:
    MyPrint myPrint;
    int param;
};

Adapter MyBind2nd(int val)
{
    return Adapter(val);
}

int main(void)
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    for_each(v.begin(), v.end(), MyBind2nd(10));
    return 0;
};