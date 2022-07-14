#include <iostream>

using namespace std;

class WeaponStrategy
{
public:
    WeaponStrategy()
    {
        std::cout << "WeaponStrategy" << std::endl;
    }
    virtual void UseWeapon() = 0;
    ~WeaponStrategy()
    {
        std::cout << "~WeaponStrategy" << std::endl;
    }
};

class Knife : public WeaponStrategy
{
public:
    Knife()
    {
        std::cout << "Knife" << std::endl;
    }
    virtual void UseWeapon()
    {
        std::cout << "使用小刀" << std::endl;
    }
    ~Knife()
    {
        std::cout << "~Knife" << std::endl;
    }
};

class AK47 : public WeaponStrategy
{
public:
    AK47()
    {
        std::cout << "AK47" << std::endl;
    }
    virtual void UseWeapon()
    {
        std::cout << "使用AK47" << std::endl;
    }

    ~AK47()
    {
        std::cout << "~AK47" << std::endl;
    }
};

class Character
{
public:
    void setWeapon(WeaponStrategy *pWeapon)
    {
        this->pWeapon = pWeapon;
    }
    void ThrowWeapon()
    {
        this->pWeapon->UseWeapon();
    }

private:
    WeaponStrategy *pWeapon;
};

void test01()
{
    //创建人物
    Character *character = new Character;

    //创建武器
    WeaponStrategy *knife = new Knife;
    WeaponStrategy *ak47 = new AK47;

    character->setWeapon(knife);
    character->ThrowWeapon();

    character->setWeapon(ak47);
    character->ThrowWeapon();

    delete knife;
    delete ak47;
    delete character;
}

int main(int argc, char *argv[])
{
    test01();
    return 0;
}