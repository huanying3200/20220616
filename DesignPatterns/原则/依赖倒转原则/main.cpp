#include <iostream>

//银行工作人员
class BankWorker
{
public:
    void doSaveBussiness()
    {
        std::cout << "办理存款业务..." << std::endl;
    }

    void doPayBussiness()
    {
        std::cout << "办理支付业务..." << std::endl;
    }

    void doTransferBussiness()
    {
        std::cout << "办理转账业务..." << std::endl;
    }
};

//中层模块
void doSaveBussiness(BankWorker *worker)
{
    worker->doSaveBussiness();
}

void doPayBussiness(BankWorker *worker)
{
    worker->doPayBussiness();
}

void doTransferBussiness(BankWorker *worker)
{
    worker->doTransferBussiness();
}

//高层模块
void test01()
{
    BankWorker *worker1 = new BankWorker;
    doSaveBussiness(worker1);     //办理存款业务
    doPayBussiness(worker1);      //办理支付业务
    doTransferBussiness(worker1); //办理转账业务
}

//银行工作人员
class AbstractWorker
{
public:
    virtual void doBussiness() = 0;
};
//专门负责办理存款业务的工作人员
class SaveBankWorker : public AbstractWorker
{
public:
    virtual void doBussiness()
    {
        std::cout << "办理存款业务..." << std::endl;
    }
};
//专门负责办理支付业务的工作人员
class PayBankWorker : public AbstractWorker
{
public:
    virtual void doBussiness()
    {
        std::cout << "办理支付业务..." << std::endl;
    }
};
//专门负责办理转装业务的工作人员
class TransferBankWorker : public AbstractWorker
{
public:
    virtual void doBussiness()
    {
        std::cout << "办理转账业务..." << std::endl;
    }
};
//中层业务模块
void doBussiness(AbstractWorker *worker)
{
    worker->doBussiness();
    delete worker;
}

void test02()
{
    AbstractWorker* transfer=new TransferBankWorker;
    doBussiness(transfer);
    doBussiness(new PayBankWorker);
}

int main(void)
{
    return 0;
}