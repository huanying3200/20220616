#include <iostream>

class AbstractTool
{
public:
    virtual void On() = 0;
    virtual void Off() = 0;
};

class Television : public AbstractTool
{
public:
    virtual void On()
    {
        std::cout << "打开电视机..." << std::endl;
    }

    virtual void Off()
    {
        std::cout << "关闭电视机..." << std::endl;
    }
};

class Light : public AbstractTool
{
public:
    virtual void On()
    {
        std::cout << "打开电灯..." << std::endl;
    }

    virtual void Off()
    {
        std::cout << "关闭电灯..." << std::endl;
    }
};

class VoiceBox : public AbstractTool
{
public:
    virtual void On()
    {
        std::cout << "打开音箱..." << std::endl;
    }

    virtual void Off()
    {
        std::cout << "关闭音箱..." << std::endl;
    }
};

class GameBox : public AbstractTool
{
public:
    virtual void On()
    {
        std::cout << "打开游戏机..." << std::endl;
    }

    virtual void Off()
    {
        std::cout << "关闭游戏机..." << std::endl;
    }
};

class DVDplayer : public AbstractTool
{
public:
    virtual void On()
    {
        std::cout << "打开影碟机..." << std::endl;
    }

    virtual void Off()
    {
        std::cout << "关闭影碟机..." << std::endl;
    }
};

class Facade
{
public:
    Facade()
    {
        telev = new Television;
        light = new Light;
        voice = new VoiceBox;
        game = new GameBox;
        dvd = new DVDplayer;
    }

    ~Facade()
    {
        delete telev;
        delete light;
        delete voice;
        delete game;
        delete dvd;
    }

    void On()
    {
        telev->On();
        light->On();
        voice->On();
        game->On();
        dvd->On();
    }

    void Off()
    {
        telev->Off();
        light->Off();
        voice->Off();
        game->Off();
        dvd->Off();
    }

public:
    AbstractTool *telev;
    AbstractTool *light;
    AbstractTool *voice;
    AbstractTool *game;
    AbstractTool *dvd;
};

int main()
{
    Facade facade;
    facade.On();
    facade.Off();
    return 0;
}