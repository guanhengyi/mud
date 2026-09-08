#include <iostream>
#include "map.h"

//=================基类 Map 实现=================
Map::Map(Map*& nextMapRef):nextMap(nextMapRef)
{
}

Map::Map(Map*& nextMapRef, int startId):nextMap(nextMapRef)
{
}

Map::~Map()
{
}

//================= 西海岸=================
void XihaianMap::clearPos()
{
    for(int i=0;i<7;i++)
    {
        for(int j=0;j<3;j++)
        {
            pos[i][j]=' ';
        }
    }
}

XihaianMap::XihaianMap(Map*& nextMapRef):Map(nextMapRef)
{
    clearPos();
    dx = 6;
    dy = 2;
    pos[dx][dy] = '*';
}

XihaianMap::XihaianMap(Map*& nextMapRef, int startId):Map(nextMapRef, startId)
{
    clearPos();
    dx = 6;
    dy = 2;
    this->pos[dx][dy] = '*';
}

int XihaianMap::getPlaceId()
{
    if(dx==6 && dy==2) return 0; //听海苑
    if(dx==5 && dy==2) return 1; //教育超市
    if(dx==4 && dy==2) return 2; //听海餐厅
    if(dx==3 && dy==2) return 3; //信息北楼
    if(dx==3 && dy==1) return 4; //学习综合体
    if(dx==3 && dy==0) return 5; //信息南楼
    if(dx==2 && dy==1) return 6; //东西区校门【传送点】
    if(dx==1 && dy==1) return 7; //体育中心
    if(dx==1 && dy==0) return 8; //望海苑
    if(dx==1 && dy==2) return 9; //游泳馆
    if(dx==0 && dy==0) return 10;//工程楼
    if(dx==0 && dy==2) return 11;//望海餐厅
    return -1;
}

void XihaianMap::ShowMap()
{
    cout<<"-----------           ------------"<<endl;
    cout<<"|          |           |          |"<<endl;
    cout<<"|  工程楼   |           | 望海餐厅   |"<<endl;
    cout<<"|    "<<pos[0][0]<<"     |           |    "<<pos[0][2]<<"     |"<<endl;
    cout<<"|          |           |          |"<<endl;
    cout<<"----------------------------------"<<endl;

    cout<<"|          |           |          |"<<endl;
    cout<<"| 望海苑    | 体育中心    |  游泳馆   |"<<endl;
    cout<<"|    "<<pos[1][0]<<"     |    "<<pos[1][1]<<"      |    "<<pos[1][2]<<"     |"<<endl;
    cout<<"|          |           |          |"<<endl;
    cout<<"----------------------------------"<<endl;

    cout<<"           |           |"<<endl;
    cout<<"           |东西区校门   |"<<endl;
    cout<<"           |    "<<pos[2][1]<<"      |"<<endl;
    cout<<"           |           |"<<endl;
    cout<<"----------------------------------"<<endl;

    cout<<"|          |           |          |"<<endl;
    cout<<"| 信息南楼   | 学习综合体  |  信息北楼  |"<<endl;
    cout<<"|    "<<pos[3][0]<<"     |    "<<pos[3][1]<<"      |    "<<pos[3][2]<<"     |"<<endl;
    cout<<"|          |           |          |"<<endl;
    cout<<"-----------------------------------"<<endl;

    cout<<"                      |           |"<<endl;
    cout<<"                      |   听海餐厅  |"<<endl;
    cout<<"                      |    "<<pos[4][2]<<"      |"<<endl;
    cout<<"                      |           |"<<endl;
    cout<<"                      ------------"<<endl;

    cout<<"                      |          |"<<endl;
    cout<<"                      | 教育超市   |"<<endl;
    cout<<"                      |    "<<pos[5][2]<<"     |"<<endl;
    cout<<"                      |          |"<<endl;
    cout<<"                      ------------"<<endl;

    cout<<"                      |           |"<<endl;
    cout<<"                      |   听海苑   |"<<endl;
    cout<<"                      |    "<<pos[6][2]<<"      |"<<endl;
    cout<<"                      |           |"<<endl;
    cout<<"                      ------------"<<endl;
}

void XihaianMap::showRoom()
{
    int id = getPlaceId();
    if(id >=0 && id <12)
    {
        cout<<"当前位置："<< Xihaian[id] << endl;
        if(id ==6){
            cout<<"提示：在此处按 a / d 可以前往蓝谷快线地铁站"<<endl;
        }
    }else{
        cout<<"未知区域"<<endl;
    }
}

void XihaianMap::setPosition(int x, int y)
{
    //清除旧星号
    pos[dx][dy] = ' ';
    dx = x;
    dy = y;
    pos[dx][dy] = '*';
}

void XihaianMap::Move(char order)
{
    // ==========传送逻辑：东西区校门ID=6，按下a/d切换蓝谷地图==========
    if(getPlaceId() ==6 && (order == 'a' || order == 'd'))
    {
        cout<<"正在前往蓝谷快线地铁进站口..."<<endl;
        // 切换为蓝谷地图，初始位置：dx=5 dy=2（地铁进站口）
        nextMap = new LangguMap(nextMap);
        delete this; //销毁当前西海岸地图对象
        return;
    }

    int ndx = dx;
    int ndy = dy;
    bool ok = true;

    switch(order)
    {
        case 'w': ndx -= 1; break;
        case 's': ndx += 1; break;
        case 'a': ndy -= 1; break;
        case 'd': ndy += 1; break;
        default: ok = false; break;
    }

    //数组边界
    if(ndx <0 || ndx >=7 || ndy <0 || ndy >=3)
    {
        ok = false;
    }

    //工程楼 dx=0 dy=0：不能w a d，只能s向下
    if(dx==0&&dy==0){
        if(order=='w'||order=='a'||order=='d') ok=false;
    }
    //望海餐厅 dx=0 dy=2：不能 w a s
    if(dx==0&&dy==2){
        if(order=='w'||order=='a'||order=='d') ok=false;
    }
    //望海苑 dx=1 dy=0：不能w a
    if(dx==1&&dy==0){
        if(order=='s'||order=='a') ok=false;
    }
    //体育中心
    if(dx==1&&dy==1){
        if(order=='w') ok=false;
    }
    //游泳馆 dx=1 dy=2：不能 w d
    if(dx==1&&dy==2){
        if(order=='d'||order=='s') ok=false;
    }
    //东西区校门 dx=2 dy=1：只能上下w/s
    if(dx==2&&dy==1){
        if(order=='a'||order=='d') ok=false;
    }
    //信息南楼 dx=3 dy=0：不能 a s
    if(dx==3&&dy==0){
        if(order=='w'||order=='s'||order=='a') ok=false;
    }
    //学习综合体
    if(dx==3&&dy==1){
        if(order=='s') ok=false;
    }
    //信息北楼 dx=3 dy=2：不能 d s
    if(dx==3&&dy==2){
        if(order=='d'||order=='w') ok=false;
    }
    //听海餐厅 dx=4 dy=2：不能 d
    if(dx==4&&dy==2){
        if(order=='d'||order=='a') ok=false;
    }
    //教育超市 dx=5 dy=2：不能 d
    if(dx==5&&dy==2){
        if(order=='d'||order=='a') ok=false;
    }
    //听海苑 dx=6 dy=2：不能 d s
    if(dx==6&&dy==2){
        if(order=='d'||order=='s'||order=='a') ok=false;
    }

    if(!ok)
    {
        cout<<"前方未知区域，请返回原地"<<endl;
        return;
    }

    pos[dx][dy] = ' ';
    dx = ndx;
    dy = ndy;
    pos[dx][dy] = '*';
    ShowMap();
}

//=================LangguMap 蓝谷快线=================
void LangguMap::clearPos()
{
    for(int i=0;i<7;i++)
    {
        for(int j=0;j<3;j++)
        {
            pos[i][j]=' ';
        }
    }
}

void LangguMap::setPosition(int x, int y)
{
    pos[dx][dy] = ' ';
    dx = x;
    dy = y;
    pos[dx][dy] = '*';
}

LangguMap::LangguMap(Map*& nextMapRef):Map(nextMapRef)
{
    clearPos();
    dx = 5; // 默认地铁进站口
    dy = 2;
    pos[dx][dy] = '*';
}

LangguMap::LangguMap(Map*& nextMapRef, int startId):Map(nextMapRef, startId)
{
    clearPos();
    dx = 5;
    dy = 2;
    this->pos[dx][dy] = '*';
}

void LangguMap::ShowMap()
{
    cout<<"          ┌──────────────┐"<<endl;
    cout<<"          │   列车头      │"<<endl;
    cout<<"          │      "<<pos[0][2]<<"       │"<<endl;
    cout<<"          ├──────────────┤"<<endl;
    cout<<"          │   3车厢       │"<<endl;
    cout<<"          │      "<<pos[1][2]<<"       │"<<endl;
    cout<<"          ├──────────────┤"<<endl;
    cout<<"          │   2车厢       │"<<endl;
    cout<<"          │      "<<pos[2][2]<<"       │"<<endl;
    cout<<"          ├──────────────┤"<<endl;
    cout<<"          │   1车厢       │"<<endl;
    cout<<"          │      "<<pos[3][2]<<"       │"<<endl;
    cout<<"          ├──────────────┤"<<endl;
    cout<<"          │   安检口      │"<<endl;
    cout<<"          │      "<<pos[4][2]<<"       │"<<endl;
    cout<<"          ├──────────────┤"<<endl;
    cout<<"          │ 地铁进站口     │"<<endl;
    cout<<"          │      "<<pos[5][2]<<"       │"<<endl;
    cout<<"          └──────────────┘"<<endl;
}

int LangguMap::getPlaceId()
{
    if(dx == 0) return 0;
    if(dx == 1) return 1;
    if(dx == 2) return 2;
    if(dx == 3) return 3;
    if(dx == 4) return 4;
    if(dx == 5) return 5;
    return -1;
}

void LangguMap::showRoom()
{
    int id = getPlaceId();
    if(id >=0 && id <=5)
    {
        cout<<"当前位置：蓝谷快线-"<< cabin[id] <<endl;
        if(id ==5){
            cout<<"提示：在此处按 a / d 返回西海岸东西区校门"<<endl;
        }
        if(id ==0){
            cout<<"提示：在此处按 a/w/d 前往崂山校区【25广场】"<<endl;
        }
    }else{
        cout<<"未知车厢区域"<<endl;
    }
}

void LangguMap::Move(char order)
{
    //====新增：列车头id=0，a/w/d传送去崂山校区25广场====
    if(getPlaceId() == 0 && (order == 'a' || order == 'w' || order == 'd'))
    {
        cout<<"正在前往崂山校区25广场..."<<endl;
        LaoshanMap* temp = new LaoshanMap(nextMap);
        temp->setPosition(0,1); //25广场坐标 dx=0 dy=1
        nextMap = temp;
        delete this;
        return;
    }

    //蓝谷地铁进站口id=5，a/d切回西海岸地图
    if(getPlaceId() ==5 && (order == 'a' || order == 'd'))
    {
        cout<<"正在返回西海岸东西区校门..."<<endl;
        XihaianMap* temp = new XihaianMap(nextMap);
        temp->setPosition(2,1);
        nextMap = temp;
        delete this;
        return;
    }

    int ndx = dx;
    int ndy = dy;
    bool ok = true;
    switch(order)
    {
        case 'w': ndx -=1; break;
        case 's': ndx +=1; break;
        case 'a':
        case 'd': ok=false; break; //车厢内部禁止左右移动
        default: ok=false; break;
    }

    if(ndx <0 || ndx >5 || ndy !=2)
    {
        ok = false;
    }
    if(!ok)
    {
        cout<<"移动失败！车厢只能w/s上下走动"<<endl;
        return;
    }

    pos[dx][dy] = ' ';
    dx = ndx;
    dy = ndy;
    pos[dx][dy] = '*';
    ShowMap();
}

//=======================崂山 LaoshanMap实现=======================
void LaoshanMap::clearPos()
{
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<6;j++)
        {
            pos[i][j]=' ';
        }
    }
}

LaoshanMap::LaoshanMap(Map*& nextMapRef):Map(nextMapRef)
{
    clearPos();
    dx = 0;
    dy = 2; //起点25广场
    pos[dx][dy] = '*';
}

LaoshanMap::LaoshanMap(Map*& nextMapRef, int startId):Map(nextMapRef, startId)
{
    clearPos();
    dx = 0;
    dy = 2;
    pos[dx][dy] = '*';
}

void LaoshanMap::setPosition(int x, int y)
{
    pos[dx][dy] = ' ';
    dx = x;
    dy = y;
    pos[dx][dy] = '*';
}

void LaoshanMap::ShowMap()
{
    cout<<"           ------------"<<endl;
    cout<<"           |          |"<<endl;
    cout<<"           |  25广场   |"<<endl;
    cout<<"           |    "<<pos[0][1]<<"     |"<<endl;
    cout<<"           |          |"<<endl;
    cout<<"-----------------------"<<endl;
    cout<<"|           |           |"<<endl;
    cout<<"|  教学区    |  梧桐大道   |"<<endl;
    cout<<"|    "<<pos[1][0]<<"      |    "<<pos[1][1]<<"      |"<<endl;
    cout<<"|           |           |"<<endl;
    cout<<"--------------------------------------------------------"<<endl;
    cout<<"|           |           |           |          |          |"<<endl;
    cout<<"| 树下空间    |  图书馆    | 樱花大道    | 一餐二餐  | 北海苑    |"<<endl;
    cout<<"|    "<<pos[2][0]<<"      |    "<<pos[2][1]<<"      |    "<<pos[2][2]<<"      |    "<<pos[2][3]<<"     |    "<<pos[2][4]<<"     |"<<endl;
    cout<<"|           |           |           |          |          |"<<endl;
    cout<<"--------------------------------------------------------"<<endl;
    cout<<"                       |           |"<<endl;
    cout<<"                       |  五子顶    |"<<endl;
    cout<<"                       |    "<<pos[3][2]<<"      |"<<endl;
    cout<<"                       |           |"<<endl;
    cout<<"                       ------------"<<endl;
    cout<<"                       |           |"<<endl;
    cout<<"                       |  九珠坛    |"<<endl;
    cout<<"                       |    "<<pos[4][2]<<"      |"<<endl;
    cout<<"                       |           |"<<endl;
    cout<<"                       ------------"<<endl;
}

int LaoshanMap::getPlaceId()
{
    if(dx==0 && dy==1) return 0; //25广场
    if(dx==1 && dy==0) return 1; //教学区
    if(dx==1 && dy==1) return 2; //梧桐大道
    if(dx==2 && dy==0) return 3; //树下空间
    if(dx==2 && dy==1) return 4; //图书馆
    if(dx==2 && dy==2) return 5; //樱花大道
    if(dx==2 && dy==3) return 6; //一餐二餐
    if(dx==2 && dy==4) return 7; //北海苑
    if(dx==3 && dy==2) return 8; //五子顶
    if(dx==4 && dy==2) return 9; //九珠坛
    return -1;
}

void LaoshanMap::showRoom()
{
    int id = getPlaceId();
    if(id >=0 && id <10)
    {
        cout<<"当前位置：崂山校区-"<< laoshanPlace[id] <<endl;
        if(id ==0){
            cout<<"提示：在此处按 w 返回蓝谷快线【列车头】"<<endl;
        }
    }else{
        cout<<"崂山未知区域"<<endl;
    }
}

void LaoshanMap::Move(char order)
{
    //====25广场 id=0 按w 返回蓝谷列车头====
    if(getPlaceId() ==0 && order == 'w')
    {
        cout<<"正在返回蓝谷快线列车头..."<<endl;
        LangguMap* temp = new LangguMap(nextMap);
        temp->setPosition(0,2); //列车头坐标 dx=0 dy=2
        nextMap = temp;
        delete this;
        return;
    }

    int ndx = dx;
    int ndy = dy;
    bool ok = true;
    switch(order)
    {
        case 'w': ndx -=1; break;
        case 's': ndx +=1; break;
        case 'a': ndy -=1; break;
        case 'd': ndy +=1; break;
        default: ok=false; break;
    }
    //崂山pos数组边界：5行 0~4；6列0~5
    if(ndx <0 || ndx >=5 || ndy <0 || ndy >=6)
    {
        ok = false;
    }

    if(dx==0&&dy==1){
        if(order=='w'||order=='a'||order=='d') ok=false;
    }
    if(dx==1&&dy==1){
        if(order=='d') ok=false;
    }
    if(dx==1&&dy==0){
        if(order=='w'||order=='a') ok=false;
    }
    if(dx==2&&dy==0){
        if(order=='a'||order=='s') ok=false;
    }
    if(dx==2&&dy==1){
        if(order=='s') ok=false;
    }
    if(dx==2&&dy==2){
        if(order=='w') ok=false;
    }
    if(dx==2&&dy==3){
        if(order=='w'||order=='s') ok=false;
    }
    if(dx==2&&dy==4){
        if(order=='d'||order=='w'||order=='s') ok=false;
    }
    if(dx==3&&dy==2){
        if(order=='d'||order=='a') ok=false;
    }
    if(dx==4&&dy==2){
        if(order=='d'||order=='a'||order=='s') ok=false;
    }

    if(!ok)
    {
        cout<<"前方不可通行，原地不动"<<endl;
        return;
    }

    pos[dx][dy] = ' ';
    dx = ndx;
    dy = ndy;
    pos[dx][dy] = '*';
    ShowMap();
}
