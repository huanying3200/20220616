#include <iostream>
#include <map>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>
#include <deque>
// 24个人进行三轮比赛，每轮都要抽签，评委进行打分。
//第一轮24人分4组，每组6个人，晋级每组前3名。
//第二轮12人分2组，每组6个人，晋级每组前3名。
//第三轮6人分1组，每组6个人，晋级每组前3名。

typedef struct PalyerMessage
{
    // int id;
    std::string name;
    int score[3];
} PalyerMes;

void inputMessage(std::vector<int> &v, std::map<int, PalyerMes> &PList)
{
    std::string seedName = "ABCDEFGHIJKLMNOPQRSTUVTXYZ";
    for (int i = 0; i < 24; i++)
    {

        PalyerMes p;
        p.name = "选手";
        p.name += seedName[i];
        for (int j = 0; j < 3; j++)
        {
            p.score[j] = 0;
        }

        int uID = 100 + i;
        PList.insert(std::make_pair(uID, p));
        v.push_back(uID /*  */);
    }
}

void setRandom(std::vector<int> &v)
{
    random_shuffle(v.begin(), v.end());
}

void competition(int index, std::vector<int> &vIn, std::map<int, PalyerMes> &mList, std::vector<int> &vOut)
{
    srand((unsigned int)time(NULL));
    //第一个int 分数，根据分数自动排序
    //第二个int 编号
    std::multimap<int, int, std::greater<int> > mulGroup;
    int groupIndex = 0;
    for (std::vector<int>::iterator it = vIn.begin(); it != vIn.end(); it++)
    {
        //打分
        std::deque<int> dScore;
        for (int i = 0; i < 10; i++)
        {
            int score = rand() % 50 + 50;
            dScore.push_back(score);
        }
        //排序
        std::sort(dScore.begin(), dScore.end());
        dScore.pop_back();
        dScore.pop_front();
        //
        int totalScore = std::accumulate(dScore.begin(), dScore.end(), 0);
        int avgScore = totalScore / dScore.size();
        mList[*it].score[index - 1] = avgScore;

        mulGroup.insert(std::make_pair(avgScore, *it));
        groupIndex++;
        if (groupIndex % 6 == 0)
        {
            int numIndex = 0;
            for (std::multimap<int, int>::iterator mit = mulGroup.begin(); mit != mulGroup.end(); mit++)
            {
                if (numIndex >= 3)
                {
                    break;
                }
                vOut.push_back((*mit).second);
                numIndex++;
            }
            mulGroup.clear();
        }
    }
}

void showResult(int index, std::vector<int> &v, std::map<int, PalyerMes> &m)
{
    std::cout << "第" << index << "轮晋级名单：" << std::endl;
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        std::cout << "姓名:" << m[*it].name << "  分数：" << m[*it].score[index - 1] << std::endl;
    }
}

int main(int argc, char *argv[])
{
    std::map<int, PalyerMes> mPList;
    std::vector<int> v1;
    std::vector<int> v2;
    std::vector<int> v3;
    std::vector<int> v4;

    //轮入24人的个人信息
    inputMessage(v1, mPList);

    //第一轮
    setRandom(v1);
    competition(1, v1, mPList, v2);
    showResult(1, v2, mPList);

    //第er轮
    setRandom(v2);
    competition(1, v2, mPList, v3);
    showResult(1, v3, mPList);

    //第san轮
    setRandom(v3);
    competition(1, v3, mPList, v4);
    showResult(1, v4, mPList);

    return 0;
}