#include <iostream>
using namespace std;
//开闭原则 对扩展开放，对修改关闭，增加功能是通过增加代码来实现，而不是去修改源代码

class Caculator
{
private:
    int m_a;
    int m_b;
    string m_operator;

public:
    Caculator(int val1, int val2, string moperator)
    {
        this->m_a = val1;
        this->m_b = val2;
        this->m_operator = moperator;
    }

    int getResult()
    {
        if (m_operator.compare("+") == 0)
        {
            return m_a + m_b;
        }
        else if (m_operator.compare("-") == 0)
        {
            return m_a - m_b;
        }
        else if (m_operator.compare("*") == 0)
        {
            return m_a * m_b;
        }
        else if (m_operator.compare("/") == 0)
        {
            return m_b == 0 ? 1000000 : m_a / m_b;
        }
    }
};

//写一个抽象类
class AbstractCaculator
{
public:
    // int m_a;
    // int m_b;
    // AbstractCaculator(int a, int b):m_a(a),m_b(b)
    // {};
    virtual void setOperatorNumber(int a, int b) = 0;
    virtual int getResult() = 0;
};

class PlusCaculator : public AbstractCaculator
{
public:
    // PlusCaculator(int a,int b):AbstractCaculator(a,b)
    // {};
    virtual void setOperatorNumber(int a, int b)
    {
        this->m_a = a;
        this->m_b = b;
    }
    virtual int getResult()
    {
        return m_a + m_b;
    }

private:
    int m_a;
    int m_b;
};

class MinuteCaculator : public AbstractCaculator
{
public:
    // PlusCaculator(int a,int b):AbstractCaculator(a,b)
    // {};
    virtual void setOperatorNumber(int a, int b)
    {
        this->m_a = a;
        this->m_b = b;
    }
    virtual int getResult()
    {
        return m_a - m_b;
    }

private:
    int m_a;
    int m_b;
};

class MultiCaculator : public AbstractCaculator
{
public:
    // PlusCaculator(int a,int b):AbstractCaculator(a,b)
    // {};
    virtual void setOperatorNumber(int a, int b)
    {
        this->m_a = a;
        this->m_b = b;
    }
    virtual int getResult()
    {
        return m_a * m_b;
    }

private:
    int m_a;
    int m_b;
};

class MinusCaculator : public AbstractCaculator
{
public:
    // PlusCaculator(int a,int b):AbstractCaculator(a,b)
    // {};
    virtual void setOperatorNumber(int a, int b)
    {
        this->m_a = a;
        this->m_b = b;
    }
    virtual int getResult()
    {
        return m_a - m_b;
    }

private:
    int m_a;
    int m_b;
};

class ModCaculator : public AbstractCaculator
{
public:
    // PlusCaculator(int a,int b):AbstractCaculator(a,b)
    // {};
    virtual void setOperatorNumber(int a, int b)
    {
        this->m_a = a;
        this->m_b = b;
    }
    virtual int getResult()
    {
        return m_a % m_b;
    }

private:
    int m_a;
    int m_b;
};

void test01()
{
    AbstractCaculator *caculator = new PlusCaculator;
    caculator->setOperatorNumber(10, 20);
    std::cout << "ret: " << caculator->getResult() << std::endl;
    delete caculator;
    caculator = nullptr;
}

int main(void)
{
    test01();
    return 0;
}