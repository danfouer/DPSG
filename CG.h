#pragma once
#ifndef _CG_H
#define _CG_H
/* 常用的常量定义 */ 
const double INF = 1E200; 
const double EP = 1E-10; 
const double EPDPSG = 0.04; //离散点采样方法的绝对允许偏差（距离平方）
const double EPCIRCLE = 0.80;//圆的相对允许偏差 
const double PARTCIRCLE = 10;//圆的相对允许偏差 
const double COLINEANGLE = 11.25;//共线允许允许偏差 
const double COLINEDIS = 100.00;//共线允许允许端点偏差 
const double PARALLELDIS = 30.00;//平行允许距离max偏差 
const double PARALLELSUB = 4.00;//平行允许距离min偏差 
const int MAXV = 300; 
const double PI = 3.14159265; 
const int MAXWIDTH = 1400;
const int MAXHEIGHT = 1024;
/* 常用的表达式定义 */ 
#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif
/* 基本几何结构 */ 
struct CGPOINT 
{ 
double x; 
double y; CGPOINT(double a=0, double b=0) { x=a; y=b;} //constructor 
}; 
struct LINESEG 
{ 
CGPOINT s; 
CGPOINT e; LINESEG(CGPOINT a, CGPOINT b) { s=a; e=b;} 
LINESEG() { } 
}; 
struct LINE // 直线的解析方程 a*x+b*y+c=0 为统一表示，约定 a >= 0 
{ 
double a; 
double b; 
double c; LINE(double d1=1, double d2=-1, double d3=0) {a=d1; b=d2; c=d3;} 
}; 
/******************** 
*                    * 
*   点的基本运算     * 
*                    * 
********************/ 
double dist(CGPOINT p1,CGPOINT p2) ;//返回两点之间欧氏距离 
bool equal_CGPOINT(CGPOINT p1,CGPOINT p2);//判断两个点是否重合
double multiply(CGPOINT sp,CGPOINT ep,CGPOINT op);//判断点ep在矢量opsp的逆时针方向、顺时针方向、三点共线
double dotmultiply(CGPOINT p1,CGPOINT p2,CGPOINT p0);//判断两矢量夹角为锐角直角钝角
CGPOINT rotate(CGPOINT o,double alpha,CGPOINT p); // 返回点p以点o为圆心逆时针旋转alpha(单位：弧度)后所在的位置 
double angle(CGPOINT o,CGPOINT s,CGPOINT e); //返回顶角在o点，起始边为os，终止边为oe的夹角(单位：弧度) 
/***************************** 
*                             * 
*      线段及直线的基本运算   * 
*                             * 
*****************************/ 
bool online(LINESEG l,CGPOINT p); //判断点p是否在线段l上 
double relation(CGPOINT p,LINESEG l); //判断点与线段的关系
CGPOINT perpendicular(CGPOINT p,LINESEG l); //求点C到线段AB所在直线的垂足 P 
double ptolinesegdist(CGPOINT p,LINESEG l,CGPOINT &np); //求点p到线段l的最短距离,并返回线段上距该点最近的点np 注意：np是线段l上到点p最近的点，不一定是垂足
double ptoldist(CGPOINT p,LINESEG l); // 求点p到线段l所在直线的距离,请注意本函数与上个函数的区别  
double ptoCGPOINTset(int vcount,CGPOINT CGPOINTset[],CGPOINT p,CGPOINT &q); //计算点到折线集的最近距离,并返回最近点. 
bool CircleInsidePolygon(int vcount,CGPOINT center,double radius,CGPOINT polygon[]); // 判断圆是否在多边形内
double cosine(LINESEG l1,LINESEG l2); //返回两个矢量l1和l2的夹角的余弦
double lsangle(LINESEG l1,LINESEG l2); // 返回线段l1与l2之间的夹角 单位：弧度 范围(-pi，pi) 
bool intersect(LINESEG u,LINESEG v); //如果线段u和v相交(包括相交在端点处)时，返回true 
bool intersect_A(LINESEG u,LINESEG v); //(线段u和v相交)&&(交点不是双方的端点) 时返回true   
bool intersect_l(LINESEG u,LINESEG v); // 线段v所在直线与线段u相交时返回true；方法：判断线段u是否跨立线段v  
LINE makeline(CGPOINT p1,CGPOINT p2); // 根据已知两点坐标，求过这两点的直线解析方程： a*x+b*y+c = 0  (a >= 0)  
double slope(LINE l); // 根据直线解析方程返回直线的斜率k,水平线返回 0,竖直线返回 1e200 
double alpha(LINE l); // 返回直线的倾斜角alpha ( 0 - pi) 
CGPOINT symmetry(LINE l,CGPOINT p); // 求点p关于直线l的对称点  
bool lineintersect(LINE l1,LINE l2,CGPOINT &p); // 如果两条直线 l1(a1*x+b1*y+c1 = 0), l2(a2*x+b2*y+c2 = 0)相交，返回true，且返回交点p  
bool intersection(LINESEG l1,LINESEG l2,CGPOINT &inter); // 如果线段l1和l2相交，返回true且交点由(inter)返回，否则返回false 
/****************************** 
* * 
* 多边形常用算法模块 * 
* * 
******************************/ 
// 如果无特别说明，输入多边形顶点要求按逆时针排列 
bool issimple(int vcount,CGPOINT polygon[]); //输入的多边形是简单多边形，返回true 
void checkconvex(int vcount,CGPOINT polygon[],bool bc[]); // 返回值：按输入顺序返回多边形顶点的凸凹性判断，bc[i]=1,iff:第i个顶点是凸顶点 
bool isconvex(int vcount,CGPOINT polygon[]); // 返回值：多边形polygon是凸多边形时，返回true  
double area_of_polygon(int vcount,CGPOINT polygon[]); // 返回多边形面积(signed)；输入顶点按逆时针排列时，返回正值；否则返回负值 
double perimeter_of_polygon(int vcount,CGPOINT polygon[],bool closesign);//返回多边形周长 
bool isconterclock(int vcount,CGPOINT polygon[]); // 如果输入顶点按逆时针排列，返回true 
bool isccwize(int vcount,CGPOINT polygon[]); // 另一种判断多边形顶点排列方向的方法  
bool PointInsidePolygon(int vcount,CGPOINT center,CGPOINT polygon[]); //判断点是否在多边形内.
int insidepolygon(int vcount,CGPOINT Polygon[],CGPOINT q); //射线法判断点q与多边形polygon的位置关系，要求polygon为简单多边形，顶点逆时针排列
bool InsideConvexPolygon(int vcount,CGPOINT polygon[],CGPOINT q);// 点q是凸多边形polygon内时，返回true；注意：多边形polygon一定要是凸多边形  
void Graham_scan(CGPOINT CGPOINTSet[],CGPOINT ch[],int n,int &len);// 寻找凸包的graham 扫描法
void ConvexClosure(CGPOINT CGPOINTSet[],CGPOINT ch[],int n,int &len);// 卷包裹法求点集凸壳，参数说明同graham算法 
bool LinesegInsidePolygon(int vcount,CGPOINT polygon[],LINESEG l); //判断折线是否在简单多边形内,判断简单多边形是否在另一个简单多边形内
void AddPosPart(double x, double y, double w, double &xtr, double &ytr, double &wtr); //增加右边区域的面积
void AddNegPart(double x, double y, double w, double &xtl, double &ytl, double &wtl); //增加左边区域的面积 
void AddRegion ( double x1, double y1, double x2, double y2, double &xtr, double &ytr,double &wtr, double &xtl, double &ytl, double &wtl ); //增加区域面积 
CGPOINT cg_simple(int vcount,CGPOINT polygon[]); //求任意简单多边形polygon的重心
CGPOINT gravitycenter(int vcount,CGPOINT polygon[]); // 求凸多边形的重心,要求输入多边形按逆时针排序 
CGPOINT a_CGPOINT_insidepoly(int vcount,CGPOINT polygon[]);//给定一简单多边形，找出一个肯定在该多边形内的点 
void CGPOINTtangentpoly(int vcount,CGPOINT polygon[],CGPOINT p,CGPOINT &rp,CGPOINT &lp); //求从多边形外一点p出发到一个简单多边形的切线,如果存在返回切点,其中rp点是右切点,lp是左切点 
bool core_exist(int vcount,CGPOINT polygon[],CGPOINT &p); // 如果多边形polygon的核存在，返回true，返回核上的一点p.顶点按逆时针方向输入  
/************************* 
* * 
* 圆的基本运算 * 
* * 
*************************/ 
bool CGPOINT_in_circle(CGPOINT o,double r,CGPOINT p); //点p在圆内(包括边界)时，返回true 
double CGpolygon_on_circle(CGPOINT o,double r,int vcount,CGPOINT polygon[],int *PartCircle); //多变形基本在圆上时，返回类圆性和连续在圆上点的个数
bool cocircle(CGPOINT p1,CGPOINT p2,CGPOINT p3,CGPOINT &q,double &r); //求不共线的三点确定一个圆 
bool line_circle(LINE l,CGPOINT o,double r,CGPOINT &p1,CGPOINT &p2); //未实现，求直线和圆的交点
/************************** 
* * 
* 矩形的基本运算 * 
* * 
**************************/ 
CGPOINT rect4th(CGPOINT a,CGPOINT b,CGPOINT c); //已知矩形的三个顶点(a,b,c)，计算第四个顶点d的坐标. 注意：已知的三个顶点可以是无序的 
/************************* 
* * 
* 常用算法的描述 * 
* * 
*************************/ 
/* 尚未实现的算法： 
1. 求包含点集的最小圆 
2. 求多边形的交 
3. 简单多边形的三角剖分 
4. 寻找包含点集的最小矩形 
5. 折线的化简 
6. 判断矩形是否在矩形中 
7. 判断矩形能否放在矩形中 
8. 矩形并的面积与周长 
9. 矩形并的轮廓 
10.矩形并的闭包 
11.矩形的交 
12.点集中的最近点对 
13.多边形的并 
14.圆的交与并 
15.直线与圆的关系 
16.线段与圆的关系 
17.求多边形的核监视摄象机 
18.求点集中不相交点对 railwai 
*/ 
/******************** 
* * 
* 补充 * 
* * 
********************/ 
int CircleRelation(CGPOINT p1, double r1, CGPOINT p2, double r2); //相离：1；外切：2；相交：3；内切：4；内含：5；
bool CircleRecRelation(CGPOINT pc, double r, CGPOINT pr1, CGPOINT pr2, CGPOINT pr3, CGPOINT pr4); //判断圆是否在矩形内
double P2planeDist(double x, double y, double z, double a, double b, double c, double d);// 点到平面的距离,平面用一般式表示ax+by+cz+d=0 
bool SameSide(CGPOINT p1, CGPOINT p2, LINE line); // 两个点是否在直线同侧，是则返回true 
void reflect(double a1,double b1,double c1,double a2,double b2,double c2,double &a,double &b,double &c);//已知入射线、镜面，求反射线。 
bool r2inr1(double A,double B,double C,double D); // 矩形2（C，D）是否在1（A，B）内 
void  c2CGPOINT(CGPOINT p1,double r1,CGPOINT p2,double r2,CGPOINT &rp1,CGPOINT &rp2); //两圆交点：两圆已经相交（相切） 
double c2area(CGPOINT p1,double r1,CGPOINT p2,double r2);//两圆公共面积：必须保证相交  
int clCGPOINT(CGPOINT p,double r,double a,double b,double c,CGPOINT &rp1,CGPOINT &rp2); //圆和直线关系：0----相离 1----相切 2----相交  
void incircle(CGPOINT p1,CGPOINT p2,CGPOINT p3,CGPOINT &rp,double &r);//内切圆：
void cutCGPOINT(CGPOINT p,double r,CGPOINT sp,CGPOINT &rp1,CGPOINT &rp2); //求切点：  p---圆心坐标， r---圆半径， sp---圆外一点， rp1,rp2---切点坐标 
int rotat(LINESEG l1,LINESEG l2); //线段的左右旋： 0： 重合； 1： 右旋；–1： 左旋；

#endif /*_CG_H*/