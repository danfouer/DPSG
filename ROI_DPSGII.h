#pragma once
#include "DPSG/CG.h"
#include "ED/EdgeMap.h"
static const unsigned int THRUMMAXNUM=30000;
static const unsigned int CURVEMAXNUM=5000;
static const unsigned int MAXCURVENUM=3;
static const unsigned int CIRCLENUM=10;
static const unsigned int LINENUM=100;
static const unsigned int CHARMAXNUM=60;//用于定位的典型结构最大数量
static const unsigned int POINTMAXNUM=4000;//用于描述典型结构的点的最大数量
typedef struct//步进距离结构体
{
	int xstep;//横步进单位
	int ystep;//纵步进单位
	double stepdistense;//步进距离
} StepStrucureII;
extern StepStrucureII g_oDistense64D[];

//////////////////////////////////////////////////////////////////////////////////////////////
struct StartThrumInfo{
		POINT ThrumStart; //线头起始点坐标
		POINT ThrumEnd;	  //线头结束点坐标
		POINT ThrumSource;//线头源头
		int ThrumDire;	//线头方向(1-64)
		int StartFrom;  //线头发起方位
		double ThrumDist; //线头长度
		double ThrumNormdis;//法线方向长度
};//线头结构体
struct FeaturePointInfo{
	    POINT ThrumStart; //线头起始点坐标
		POINT ThrumEnd;	  //线头结束点坐标
	    POINT FeaturePointPos;//特征点坐标
		POINT PointNormOne;//特征点法线边界1
        POINT PointNormTwo;//特征点法线边界2
		unsigned char ThrumDire;	//线头方向(1-32)
		double ThrumDist; //线头长度
		double ThrumNormdis;//法线方向长度
		unsigned char LongDir;//长方向
		double LoneDis;//长方向长度
		unsigned char ShortDir;//短方向
		double ShortDis;//短方向长度
		unsigned char NormOne;//法线方向1
		double NormOneDis;//法线方向1长度
		unsigned char NormTwo;//法线方向2
		double NormTwoDis;//法线方向1长度
		//int DirOne; //方向1
		//double DirOneDis;//方向1长度
		//int DirTwo; //方向2
		//double DirTwoDis;//方向2长度
		//int DirThree; //方向3
		//double DirThreeDis;//方向3长度
		//int DirFour; //方向4
		//double DirFourDis;//方向4长度
		int FeaturePointType;//特征点类型 0：普通点；1：端点；2：拐点；3：三交叉点 4：四交叉点
};//特征点结构体
struct ThrumInfo{
		POINT ThrumStart; //线段起始点坐标
		POINT ThrumEnd;	  //线段结束点坐标
		int ThrumDire;	//线段方向(1-64)
		int ThrumCurveSeq;//线段隶属曲线序号
		double ThrumDist;        //线段长度
		double ThrumNormdis;//法线方向长度
		double ThrumHisDire;//线段历史方向
		double ThrumWeight;//线段权重
		//POINT PointNormOne;//特征点法线边界1
  //      POINT PointNormTwo;//特征点法线边界2
		//int NormOne;//法线方向1
		//double NormOneDis;//法线方向1长度
		//int NormTwo;//法线方向2
		//double NormTwoDis;//法线方向1长度

};//线段结构体

struct CurveInfo{
	POINT CurveStart; //曲线起始点坐标
	POINT CurveEnd;	  //曲线结束点坐标
	unsigned int CurveFrom;	//曲线起始方位
	double CurveDire;	//曲线大体方向(0-360)
	unsigned int CurveStartThrum;//曲线起始线段序号
	unsigned int CurveEndThrum;//曲线结束线段序号
	unsigned int CurveMidThrum;//曲线中部线段序号
	unsigned char Curvetype;//曲线标志：1——直线 2折线 8封闭轮廓 6圆弧 
	unsigned char CurveChange;//曲线方向变化次数
	double CurveDist[65];//曲线长度0:——总长度和 1-64:——六十四方向各自长度和
	double  CurveNormdis;//法线方向平均宽度
	double Curvature;//曲线方向变化
	unsigned short CrossCruve[5][6];//交叉曲线信息： 交叉对方线段号、交叉类型0:无交叉 1一回事 2交叉而过、交叉点横坐标、纵坐标,交叉我方线段号;交叉主动被动标记
	
	
	
	};//曲线结构体

extern struct StartThrumInfo StartThrum[CURVEMAXNUM];//
extern struct FeaturePointInfo FeaturePoint[CURVEMAXNUM];// 特征点数组
extern struct ThrumInfo ThrumGroup[THRUMMAXNUM];
extern struct CurveInfo CurveGroup[CURVEMAXNUM];
extern struct StartThrumInfo StartThrumTemp;//
extern struct ThrumInfo ThrumTemp;
extern struct LINE LineGroup[LINENUM];
extern struct LINESEG LineSegGroup[LINENUM];
extern StepStrucureII LinePara[LINENUM];
extern int StartThrumNum;//起始线段序号
extern int FeaturePointNum;//特征点序号
extern int ThrumNum;//线段序号
extern int CurveNum;//曲线序号
extern int LineNum;//直线序号

extern unsigned short MaxCurveGroup[MAXCURVENUM][2];//最长曲线数组[][0]序号,[][1]长度
extern unsigned short CircleGroup[CIRCLENUM][4];//圆数组[][0]序号,[][1]半径，[][2]圆心横坐标，[][3]圆心纵坐标
extern unsigned char CircleII[192];

////////////////////////////////////////////////////////////////////////////////////
struct InkDataType 
{
	short x;//部件描述点横坐标0-255
	short y;//部件描述点纵坐标0-255
	unsigned short z;//压力
	unsigned short type;//点的类型
};
extern struct InkDataType InkData[CHARMAXNUM][POINTMAXNUM];//
struct YYMatchingType 
{
	unsigned int PointNum;// 阴轮廓描述数据点数;
	unsigned int PointSize;// 阳模板描述数据点数;
	unsigned short Code;//部件编码 *(P+272)
	unsigned short Width;//模板宽
	unsigned short Height;//模板高
	CGPOINT StartPoint;//模板起始点位置
	CGPOINT CenterPoint;//模板中心点位置
	CGPOINT FirstPoint;//模板中心点位置
	unsigned int UnitSeq;//部件序号
	double scale;//模板尺度
	double angle;//模板角度
	double perimeter;//模板周长
	double YinCYinMRatio; //阴轮廓在阴采样图中的匹配率
	double YinLineYinMRatio; //阴轮廓在阴采样图中的线段匹配率
	double YinCYangMRatio;//阴轮廓在阳采样图中的匹配率
	double YangTYinMRatio;//阳模板在阴采样图中的匹配率
	double YangTYangMRatio;//阳模板在阳采样图中的匹配率
};
extern struct YYMatchingType YYMatchingResult[CHARMAXNUM];
extern struct YYMatchingType YYMatchingTemp;
////////////////////////////////////////////////////////////////////////////////////
//	函 数 名 ：ThrumInfo DPSGII_LineSearch64D(unsigned char* Img_bin,int nWidth,int nHeight, int cenX, int cenY, int R)
//	函数功能 ：计算Img_bin指定点32个对方向可能形成的最长直线
//	作    者 ：朱宗晓
//	时    间 ：2010年11月7日
//	返 回 值 ： 32对维周边方向贡献度最大值ThrumInfo ThrumNow结构体
//	入口参数说明 ：
//	1.unsigned char* Img_bin：待计算的二值图
//  2.int nWidth: 二值图宽度
//  3.int nHeight: 二值图高度
//	4.int cenX：指定点横坐标
//	5.int cenY：指定点横坐标
//	6.int R：二值图采样半径
////////////////////////////////////////////////////////////////////////
//	历史记录：
//	编号     日期    	作者    备注
//	0	2012年3月28日	朱宗晓	创建本函数
//	////////////////////////////////////////////////////////////////////////
ThrumInfo DPSGII_LineSearch64D(unsigned char* Img_bin,int nWidth,int nHeight, int cenX, int cenY, int R,int Rout);
double DPSGII_DPDisR64D(unsigned char* Img_bin, int nWidth, int nHeight, int cenX, int cenY, int R, int Rout, unsigned int Direction);
unsigned char* DPSGII_DistanceTrans(unsigned char* Img_bin, int nWidth, int nHeight, int Rin, int Rout);
////////////////////////////////////////////////////////////////////////
//	函 数 名：unsigned char* DPSGII_SquaYinSampleFast(unsigned char* Img_gray, int nWidth,int nHeight,int Rin,int Rout,int nWeberCoef)
//	函数功能：实现灰度图阴采样
//  函数过程：
//  先行函数：无
//  调用函数：unsigned char DPSGII_GraytoYYbinFast(unsigned char * Img_gray, int nWidth,int nHeight,int cenX, int cenY, int Rin, int Rout,int RoutTotal,int nWeberCoef)
//  后续函数：无
//  相关文档：Object detection based on multi-scale discrete points sampling and grouping.doc 
//	作    者：朱宗晓
//	时    间：2012年3月27日
//	返 回 值：unsigned char* YYBin 阴采样图
//	入口参数说明：
//	1.unsigned char* Img_gray：待计算的灰度图
//  2.int nWidth：待计算的灰度图数组宽度
//  3.int nHeight：待计算的灰度图数组高度
//  4.int Rin：内环半径
//  5.int Rout：外环半径
//  6.int nWeberCoeft：韦伯系数
//  7.int WeberCoefRatio:韦伯系数调整参数
//  8.int ABSSign
//  9.int &YinCounter
//  10.int &YangCounter
////////////////////////////////////////////////////////////////////////
//	历史记录：
//	编号     日期    	作者    备注
//	0	2012年3月27日	朱宗晓	创建本函数
//	////////////////////////////////////////////////////////////////////////
unsigned char* DPSGII_SquaYinSampleFast(unsigned char* Img_gray, int nWidth,int nHeight,int Rin,int Rout,int nWeberCoef,int WeberCoefRatio,int ABSSign,int &YinCounter,int &YangCounter);
////////////////////////////////////////////////////////////////////////
//	函 数 名：void DPSGII_YinYangSampleFast(unsigned char* Img_gray, unsigned char* &g_pYinMap,unsigned char* &g_pYangMap,int nWidth,int nHeight,int Rin,int Rout,int nWeberCoef,int WeberCoefRatio,int ABSSign,int &YinCounter,int &YangCounter);
//	函数功能：计算采样点阴阳特性
//  函数过程：通过计算离散点周围的均匀性设定该离散点是阴点还是阳点。
//  先行函数：无
//  调用函数：DPSGII_GrayStaTotal(unsigned char * Img_gray, int nWidth,int nHeight,int StartX, int StartY, int EndX,int EndY)
//  后续函数：无
//  相关文档：Object detection based on multi-scale discrete points sampling and grouping.doc 
//	作    者：朱宗晓
//	时    间：20102年3月27日
//	返 回 值：阴阳特性 255——阴点，0——阳点
//	入口参数说明 ：
//	1.unsigned char* Img_gray：待计算的灰度图
//  2.int nWidth：待计算的灰度图数组宽度
//  3.int nHeight：待计算的灰度图数组高度
//  4.int cenX：采样点横坐标
//  5.int cenY：采样点纵坐标
//  6.int Rin：内环半径
//  7.int Rout：外环半径
//  8.int nWeberCoeft：韦伯系数
//  9.int WeberCoefRatio:韦伯系数调整参数,该参数是一个灰度值,内环亮度低于此灰度则增大/减小韦伯系数
//  10.int ABSSign//是否采用绝对值计算
//  11.int &YinCounter//阴采样点计数器
//  12.int &YangCounter//阳采样点计数器
////////////////////////////////////////////////////////////////////////
//	历史记录：
//	编号     日期    	作者    备注
//	0	2012年3月27日	朱宗晓	创建本函数
//	////////////////////////////////////////////////////////////////////////
void DPSGII_YinYangSampleFast(unsigned char* Img_gray, unsigned char* &g_pYinMap,unsigned char* &g_pYangMap,int nWidth,int nHeight,int Rin,int Rout,int nWeberCoef,int WeberCoefRatio,int ABSSign,int &YinCounter,int &YangCounter);
////////////////////////////////////////////////////////////////////////
//	函 数 名：int DPSGII_DPYinYangFilterR(unsigned char* Img_bin,unsigned char* Img_bin2,int nWidth,int nHeight,int Rin, int Rout,int Value)
//	函数功能：阴阳采样图同时滤波
//  函数过程：
//  先行函数：无
//  调用函数：无
//  后续函数：无
//  相关文档：Object detection based on multi-scale discrete points sampling and grouping.doc 
//	作    者 ：朱宗晓
//	时    间 ：2012年9月9日
//	返 回 值 ：PointChange离散点增减数目
//	入口参数说明 ：
//	1.unsigned char* Img_bin：待计算的二值图1，
//	2.unsigned char* Img_bin2：待计算的二值图2
//  3.int nWidth：待计算的二值图数组宽度
//  4.int nHeight：待计算的二值图数组高度
//  5.int Rin：采样半径
//  6.int Rout：外环半径
//	7.int Value：滤波阈值
////////////////////////////////////////////////////////////////////////
//	历史记录：
//	编号     日期    	作者    备注
//	0	2012年9月9日	朱宗晓	创建本函数
//	////////////////////////////////////////////////////////////////////////
int DPSGII_DPYinYangFilterR(unsigned char* Img_bin,unsigned char* Img_bin2,int nWidth,int nHeight,int Rin,  int Rout,int Value);
////////////////////////////////////////////////////////////////////////
//	函 数 名 ：bool DPSG_AdnoteLinePoint(unsigned char *Img_bin,int nWidth,int nHeight,int StartPx,int StartPy,int EndPx,int EndPy,int R,int Rout)
//	函数功能 ：根据两点连线间黑像素的个数判断两点间是否有连接关系
//  函数过程 ：根据两点直线公式计算直线上每一个点
//  先行函数 ：
//  调用函数 ：
//  后续函数 ：
//  相关文档 ：无
//	作    者 ：朱宗晓
//	时    间 ：2010年6月11日
//	返 回 值 ：LinePoint——二值图中直线上黑象素个数
//	入口参数说明 ：
//  1.IplImage * Img_bin: 待搜索的二值图
//  2.int nWidth：待搜索的二值图数组宽度
//  3.int nHeight：待搜索的二值图数组高度
//  4.int StartPx：搜索起始点横坐标
//  5.int StartPy：搜索起始点纵坐标
//  6.int EndPx：搜索结束点横坐标
//  7.int EndPy：搜索结束点纵坐标
//  8.int R：采样半径
//  9.int Rout：外环半径

////////////////////////////////////////////////////////////////////////
//	历史记录：
//	编号     日期    	作者    备注
//	0	2010年06月11日	朱宗晓	创建本函数
//	////////////////////////////////////////////////////////////////////////
bool DPSG_AdnoteLinePoint(unsigned char *Img_bin,int nWidth,int nHeight,int StartPx,int StartPy,int EndPx,int EndPy,int R,int Rout);
StepStrucureII DPSG_LinePointCounter(unsigned char *Img_bin,int nWidth,int nHeight,int StartPx,int StartPy,int EndPx,int EndPy,int R,int Rout);
////////////////////////////////////////////////////////////////////////
//	函 数 名 ：void DPSGII_AutoCurveSearch64D(unsigned char* Img_bin,unsigned char* Img_sign,unsigned short* Img_history,int nWidth,int nHeight,int Rin,int Rout,int DirectionN,int NormThre,int CrossAngle,int MinLine,int MinCruve);
//	函数功能 ：在Img_bin中自动探测曲线信息
//	作    者 ：朱宗晓
//	时    间 ：2012年4月1日
//	返 回 值 ：线段及曲线集合
//	入口参数说明 ：
//  1.IplImage * Img_bin: 待探测图
//  2.IplImage * Img_sign: 已探测区域标记图
//      unsigned short* Img_history
//  3.int nWidth：待计算的灰度图数组宽度
//  4.int nHeight：待计算的灰度图数组高度
//  5.int Rin：采样半径 2
//    int Rout 15
//  6.int DirectionN：直线探测范围
//  7.int NormThre：法线阈值
//  8.int CrossAngle：两曲线交叉的最小角度
//  9.int MinLine：最小起始点所在直线长度
//  10.int MinCruve：最小探测曲线长度
////////////////////////////////////////////////////////////////////////
//	历史记录：
//	编号     日期    	作者    备注
//	0	2012年03月31日	朱宗晓	创建本函数
//	////////////////////////////////////////////////////////////////////////
void DPSGII_AutoCurveSearch64D(unsigned char* Img_bin,unsigned char* Img_sign,unsigned short* Img_history,int nWidth,int nHeight,int Rin,int Rout,int DirectionN,int NormThre,int CrossAngle,int MinLine,int MinCruve);
void DPSGII_AutoCurveSearch64DII(unsigned char* Img_bin,unsigned char* Img_sign,unsigned short* Img_history,int nWidth,int nHeight,int Rin,int Rout,int DirectionN,int NormThre,int CrossAngle,int MinLine,int MinCruve);
void DPSGII_AutoLineSearch64D(unsigned char* Img_bin, unsigned char* Img_sign, unsigned short* Img_history, int nWidth, int nHeight, int Rin, int Rout, int DirectionN, int NormThre, int CrossAngle, int MinLine);
////////////////////////////////////////////////////////////////////////
//	函 数 名 ：void DPSGII_Clear()
//	函数功能 ：将探测曲线结构的起始点、直线段、曲线、特征点全部清零
//	作    者 ：朱宗晓
//	时    间 ：2012年09月09日
//	返 回 值 ： 被修改了的StartThrum、ThrumGroup、urveGroup、FeaturePoint、MaxCurveGroup、CircleGroup
//	入口参数说明 ：无
////////////////////////////////////////////////////////////////////////
//	历史记录：
//	编号     日期    	作者    备注
//	0	2012年09月09日	朱宗晓	创建本函数
//	////////////////////////////////////////////////////////////////////////
void DPSGII_Clear();
////////////////////////////////////////////////////////////////////////
//	函 数 名 ：void DPSGII_Result(int& StartThrumNumOut,int& ThrumNumOut, int&CurveNumOut)
//	函数功能 ：将探测曲线结构的起始点、直线段、曲线的数量返回
//	作    者 ：朱宗晓
//	时    间 ：2012年09月09日
//	返 回 值 ：探测到的曲线结构的起始点、直线段、曲线的数量
//	入口参数说明 ：
//  1.int& StartThrumNumOut: 起始点数量返回值
//  2.int& ThrumNumOut: 直线段数量返回值
//  3.int& CurveNumOut: 曲线数量返回值
////////////////////////////////////////////////////////////////////////
//	历史记录：
//	编号     日期    	作者    备注
//	0	2012年09月09日	朱宗晓	创建本函数
//	////////////////////////////////////////////////////////////////////////
void DPSGII_Result(int& StartThrumNumOut,int& ThrumNumOut, int&CurveNumOut);
////////////////////////////////////////////////////////////////////////
//	函 数 名 ：StartThrumInfo * DPSGII_StartThrum(int StartThrumNumNow)
//	函数功能 ：将指定起始点信息返回
//	作    者 ：朱宗晓
//	时    间 ：2012年09月09日
//	返 回 值 ： 第StartThrumNumNow个起始点信息
//	入口参数说明 ：
//  1.int StartThrumNumOut: 指定返回的起始点序号
////////////////////////////////////////////////////////////////////////
//	历史记录：
//	编号     日期    	作者    备注
//	0	2012年09月09日	朱宗晓	创建本函数
//	////////////////////////////////////////////////////////////////////////
StartThrumInfo * DPSGII_StartThrum(int StartThrumNum);
////////////////////////////////////////////////////////////////////////
//	函 数 名 ：CurveInfo * DPSGII_Curve(int CurveNumNow)
//	函数功能 ：将指定曲线信息返回
//	作    者 ：朱宗晓
//	时    间 ：2012年09月09日
//	返 回 值 ： 第CurveNumNow个曲线信息
//	入口参数说明 ：
//  1.int CurveNumNow: 指定返回的曲线序号
////////////////////////////////////////////////////////////////////////
//	历史记录：
//	编号     日期    	作者    备注
//	0	2012年09月09日	朱宗晓	创建本函数
//	////////////////////////////////////////////////////////////////////////
CurveInfo * DPSGII_Curve(int CurveNumNow);
////////////////////////////////////////////////////////////////////////
//	函 数 名 ：unsigned short * DPSGII_MaxCurve(int MaxSeq)
//	函数功能 ：将指定最长曲线顺序号返回
//	作    者 ：朱宗晓
//	时    间 ：2012年09月09日
//	返 回 值 ： 第MaxSeq个曲线信息
//	入口参数说明 ：
//  1.int MaxSeq: 指定返回的最长曲线序号
////////////////////////////////////////////////////////////////////////
//	历史记录：
//	编号     日期    	作者    备注
//	0	2012年09月09日	朱宗晓	创建本函数
//	////////////////////////////////////////////////////////////////////////
unsigned short  DPSGII_MaxCurve(int MaxSeq);
unsigned short*  DPSGII_CircleCurve(int CircleSeq);
////////////////////////////////////////////////////////////////////////
//	函 数 名 ：ThrumInfo * DPSGII_Thrum(int ThrumNumNow)
//	函数功能 ：将指定直线段信息返回
//	作    者 ：朱宗晓
//	时    间 ：2012年09月09日
//	返 回 值 ： 第ThrumNumNow个直线段信息
//	入口参数说明 ：
//  1.int ThrumNumNow: 指定返回的直线段序号
////////////////////////////////////////////////////////////////////////
//	历史记录：
//	编号     日期    	作者    备注
//	0	2012年09月09日	朱宗晓	创建本函数
//	////////////////////////////////////////////////////////////////////////
ThrumInfo * DPSGII_Thrum(int ThrumNumNow);
////////////////////////////////////////////////////////////////////////
//	函 数 名 ：FeaturePointInfo * DPSGII_FeaturePoint(int FeaturePointNow)
//	函数功能 ：将指定特征点信息返回
//	作    者 ：朱宗晓
//	时    间 ：2012年09月09日
//	返 回 值 ： 第FeaturePointNow个特征点信息
//	入口参数说明 ：
//  1.int FeaturePointNow: 指定返回的特征点序号
////////////////////////////////////////////////////////////////////////
//	历史记录：
//	编号     日期    	作者    备注
//	0	2012年09月09日	朱宗晓	创建本函数
//	////////////////////////////////////////////////////////////////////////
FeaturePointInfo * DPSGII_FeaturePoint(int FeaturePointNow);
ThrumInfo * DPSGII_ConLine(int ConLineNumNow);
ThrumInfo * DPSGII_ParallelLine(int ConLineNumNow);
////////////////////////////////////////////////////////////////////////
//	函 数 名 ：FeaturePointInfo DPSGII_FeaturePointSearch64D(unsigned char* Img_bin,int nWidth,int nHeight, int cenX, int cenY, int R,int Rout,int NormThre)
//	函数功能 ：计算Img_bin指定点的特征信息
//	作    者 ：朱宗晓
//	时    间 ：2012年09月09日
//	返 回 值 ： 指定点的特征信息StartThrumInfo StartThrumNow结构体
//	入口参数说明 ：
//	1.unsigned char* Img_bin：待计算的二值图
//  2.int nWidth: 二值图宽度
//  3.int nHeight: 二值图高度
//	4.int cenX：指定点横坐标
//	5.int cenY：指定点横坐标
//	6.int R：二值图采样半径
//  7.int Rout：外环半径
//  8.int NormThre：法线阈值
////////////////////////////////////////////////////////////////////////
//	历史记录：
//	编号     日期    	作者    备注
//	0	2012年09月09日	朱宗晓	创建本函数
//	////////////////////////////////////////////////////////////////////////
FeaturePointInfo DPSGII_FeaturePointSearch64D(unsigned char* Img_bin,int nWidth,int nHeight, int cenX, int cenY, int R,int Rout,int NormThre);
////////////////////////////////////////////////////////////////////////
//	函 数 名 ：int DPSGII_FeaturePointSearch(unsigned char* Img_bin,unsigned char* Img_sign,int nWidth,int nHeight,int Rin,int Rout,int NormThre)
//	函数功能 ：计算Img_bin指定点的特征点信息
//	作    者 ：朱宗晓
//	时    间 ：2012年09月09日
//	返 回 值 ： 曲线特征点的个数
//	入口参数说明 ：
//	1.unsigned char* Img_bin：待计算的二值图
//	2.unsigned char* Img_sign：待计算的二值图
//  3.int nWidth: 二值图宽度
//  4.int nHeight: 二值图高度
//	5.int Rin：二值图采样半径
//  6.int Rout：外环半径
//  7.int NormThre：法线阈值
////////////////////////////////////////////////////////////////////////
//	历史记录：
//	编号     日期    	作者    备注
//	0	2012年09月09日	朱宗晓	创建本函数
//	////////////////////////////////////////////////////////////////////////
int DPSGII_FeaturePointSearch(unsigned char* Img_bin,unsigned char* Img_sign,int nWidth,int nHeight,int Rin,int Rout,int NormThre);
////////////////////////////////////////////////////////////////////////
//	函 数 名 ：void DPSGII_FeaturePointSearchShield(unsigned char* Img_bin,unsigned char* Img_sign,int nWidth,int nHeight,int Rin,int Rout,int NormThre)
//	函数功能 ：将区域点、半区域点屏蔽掉
//	作    者 ：朱宗晓
//	时    间 ：2012年09月09日
//	返 回 值 ： 将区域点、半区域点屏蔽掉的Img_sign图
//	入口参数说明 ：
//	1.unsigned char* Img_bin：待计算的二值图
//	2.unsigned char* Img_sign：待计算的二值图
//  3.int nWidth: 二值图宽度
//  4.int nHeight: 二值图高度
//	5.int Rin：二值图采样半径
//  6.int Rout：外环半径
//  7.int NormThre：法线阈值
////////////////////////////////////////////////////////////////////////
//	历史记录：
//	编号     日期    	作者    备注
//	0	2012年09月09日	朱宗晓	创建本函数
//	////////////////////////////////////////////////////////////////////////
void DPSGII_FeaturePointSearchShield(unsigned char* Img_bin,unsigned char* Img_sign,int nWidth,int nHeight,int Rin,int Rout,int NormThre);
int CopyLineFromCurve();
////////////////////////////////////////////////////////////////////////
//	函 数 名 ：int CopyLineFromCurve()
//	函数功能 ：共线、平行直线判断
//	作    者 ：朱宗晓
//	时    间 ：2012年09月19日
//	返 回 值 ： 共线直线条数
//	入口参数说明 ：
////////////////////////////////////////////////////////////////////////
//	历史记录：
//	编号     日期    	作者    备注
//	0	2012年09月19日	朱宗晓	创建本函数
//	////////////////////////////////////////////////////////////////////////
int StraightLineInfo();
////////////////////////////////////////////////////////////////////////
//	函 数 名 ：int Parallel_Result()
//	函数功能 ：返回平行线个数
//	作    者 ：朱宗晓
//	时    间 ：2012年09月19日
//	返 回 值 ： 平行线个数
//	入口参数说明 ：
////////////////////////////////////////////////////////////////////////
//	历史记录：
//	编号     日期    	作者    备注
//	0	2012年09月19日	朱宗晓	创建本函数
//	////////////////////////////////////////////////////////////////////////
int Parallel_Result();
////////////////////////////////////////////////////////////////////////
//	函 数 名 ：StartThrumInfo DPSGII_StartThrumSearch64D(unsigned char* Img_bin,int nWidth,int nHeight, int cenX, int cenY, int R,int Rout)
//	函数功能 ：计算Img_bin以指定点为线头32个对方向可能形成的最长直线相关信息
//	作    者 ：朱宗晓
//	时    间 ：2012年3月30日
//	返 回 值 ： 32对维周边方向贡献度最大值StartThrumInfo StartThrumNow结构体
//	入口参数说明 ：
//	1.unsigned char* Img_bin：待计算的二值图
//  2.int nWidth: 二值图宽度
//  3.int nHeight: 二值图高度
//	4.int cenX：指定点横坐标
//	5.int cenY：指定点横坐标
//	6.int R：二值图采样半径
////////////////////////////////////////////////////////////////////////
//	历史记录：
//	编号     日期    	作者    备注
//	0	2012年3月30日	朱宗晓	创建本函数
//	////////////////////////////////////////////////////////////////////////
StartThrumInfo DPSGII_StartThrumSearch64D(unsigned char* Img_bin,int nWidth,int nHeight, int cenX, int cenY, int R);
bool DPSGII_FeaturePointBlockArea(unsigned char* Img_sign,int nWidth,int nHeight,int R,FeaturePointInfo* FeaturePointNow);
////////////////////////////////////////////////////////////////////////
//	函 数 名：void DPSGII_DPAdnateValueFilterR(unsigned char* Img_bin,int nWidth,int nHeight,int R, int Value)
//	函数功能：对离散点采样得到的阴阳采样图按连通性进行滤波
//  函数过程：连通性大于等于Value的补黑点，小于Value的去掉
//  先行函数：无
//  调用函数：无
//  后续函数：无
//  相关文档：Object detection based on multi-scale discrete points sampling and grouping.doc 
//	作    者：朱宗晓
//	时    间：2010年4月26日
//	返 回 值：无
//	入口参数说明 ：
//	1.unsigned char* Img_bin：待计算的二值图
//  2.int nWidth：待计算的二值图数组宽度
//  3.int nHeight：待计算的二值图数组高度
//	4.int R：二值图采样半径
////////////////////////////////////////////////////////////////////////
//	历史记录：
//	编号     日期    	作者    备注
//	0	2012年3月28日	朱宗晓	创建本函数
///////////////////////////////////////////////////////////////////////////
int DPSGII_DPAdnateValueFilterR(unsigned char* Img_bin,int nWidth,int nHeight,int Rin,  int Rout,int Value);
double DPSGII_YinMatching(unsigned char* Img_bin,int nWidth,int nHeight,CGPOINT* Yincontours,int Lengths,int SetX,int SetY);
double DPSGII_YinMatchingLine(unsigned char* Img_bin,int nWidth,int nHeight,CGPOINT* Yincontours,int Lengths,int SetX,int SetY,int Rin,int Rout);
double DPSGII_YangMatching(unsigned char* Img_bin,int nWidth,int nHeight,unsigned char* Yangtemplate,int nWidthII,int nHeightII,int Size,int SetX,int SetY);
YYMatchingType DPSGII_YinYangSetPointMatching(unsigned char* Img_yin,unsigned char * Img_yang,int nWidth,int nHeight,CGPOINT* Yincontours,unsigned char* Yangtemplate,YYMatchingType InputTemplate);
YYMatchingType DPSGII_YinYangMatching(unsigned char* Img_yin,unsigned char * Img_yang,int nWidth,int nHeight,CGPOINT* Yincontours,unsigned char* Yangtemplate,YYMatchingType InputTemplate,int Rin,int Rout,int NormThre);
void DPSGII_EdpfInfo(EdgeMap *EdpfMap);