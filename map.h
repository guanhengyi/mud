#ifndef MAP_H
#define MAP_H
#include <string>
using namespace std;

// 抽象基类 Map
class Map
{
public:
    // nextMapRef：外部Map*指针的引用，用来实现地图切换
    Map(Map*& nextMapRef);
    Map(Map*& nextMapRef, int startId);
    virtual ~Map();

    virtual void ShowMap() = 0;
    virtual void showRoom() = 0;
    virtual void Move(char order) = 0;
    virtual int getPlaceId() = 0;

protected:
    // pos移除！pos交给各个子类自己定义
    Map*& nextMap;   // 引用外部指针，用于切换地图
    int dx;
    int dy;
    virtual void clearPos() = 0; // 纯虚，每个子类自己清空自己的pos数组
};

// 西海岸校区地图子类
class XihaianMap : public Map
{
public:
    XihaianMap(Map*& nextMapRef);
    XihaianMap(Map*& nextMapRef, int startId);
    void setPosition(int x, int y);//设置玩家坐标

    virtual void ShowMap() override;
    virtual void showRoom() override;
    virtual void Move(char order) override;
    virtual int getPlaceId() override;

protected:
    char pos[7][3]; // 西海岸自己的格子数组
    virtual void clearPos() override;

private:
    string Xihaian[12]={
        "听海苑","教育超市","听海餐厅","信息北楼","学习综合体","信息南楼",
        "东西区校门【传送点】","体育中心","望海苑","游泳馆","工程楼","望海餐厅"
    };
};

// 蓝谷快线车厢子类
class LangguMap : public Map
{
public:
    LangguMap(Map*& nextMapRef);
    LangguMap(Map*& nextMapRef, int startId);

    virtual void ShowMap() override;
    virtual void showRoom() override;
    virtual void Move(char order) override;
    virtual int getPlaceId() override;
    void setPosition(int x, int y);

protected:
    char pos[7][3]; // 蓝谷车厢自己的格子数组
    virtual void clearPos() override;

private:
    string cabin[6] = {"列车头","3车厢","2车厢","1车厢","安检口","地铁进站口"};
};

// ============新增：崂山校区地图============
class LaoshanMap : public Map
{
public:
    LaoshanMap(Map*& nextMapRef);
    LaoshanMap(Map*& nextMapRef, int startId);
    void setPosition(int x, int y);

    virtual void ShowMap() override;
    virtual void showRoom() override;
    virtual void Move(char order) override;
    virtual int getPlaceId() override;

protected:
    char pos[5][5]; //崂山地图尺寸：5行6列，适配你的字符画
    virtual void clearPos() override;

private:
    string laoshanPlace[10] = {
        "25广场", "教学区", "梧桐大道", "树下空间",
        "图书馆", "樱花大道", "一餐二餐", "北海苑",
        "五子顶", "九珠坛"
    };
};

#endif
