#include "stdafx.h" 
#include "DPSG/ROI_DPSGII.h"
#include "DPSG/CG.h"
#include "math.h"
StepStrucureII g_oDistense64D[65]={
{0,0,0.0},          //空置
{1,0,1.0},          //64D-1方位 
{8,-1,8.062257748}, //64D-2方位
{4,-1,4.123105626}, //64D-3方位
{8,-3,8.544003745}, //64D-4方位 
{2,-1,2.236067977}, //64D-5方位 
{8,-5,9.433981132}, //64D-6方位 
{4,-3,5.0},         //64D-7方位 
{8,-7,10.63014581}, //64D-8方位 
{1,-1,1.414213562}, //64D-9方位 
{7,-8,10.63014581}, //64D-10方位 
{3,-4,5.0},         //64D-11方位 
{5,-8,9.433981132}, //64D-12方位 
{1,-2,2.236067977}, //64D-13方位 
{3,-8,8.544003745}, //64D-14方位 
{1,-4,4.123105626}, //64D-15方位 
{1,-8,8.062257748}, //64D-16方位 
{0,-1,1.0},         //64D-17方位 
{-1,-8,8.062257748},//64D-18方位 
{-1,-4,4.123105626},//64D-19方位 
{-3,-8,8.544003745},//64D-20方位 
{-1,-2,2.236067977},//64D-21方位 
{-5,-8,9.433981132},//64D-22方位 
{-3,-4,5.0},        //64D-23方位 
{-7,-8,10.63014581},//64D-24方位 
{-1,-1,1.414213562},//64D-25方位 
{-8,-7,10.63014581},//64D-26方位 
{-4,-3,5.0},        //64D-27方位 
{-8,-5,9.433981132},//64D-28方位 
{-2,-1,2.236067977},//64D-29方位 
{-8,-3,8.544003745},//64D-30方位 
{-4,-1,4.123105626},//64D-31方位 
{-8,-1,8.062257748},//64D-32方位 
{-1,0,1.0},         //64D-33方位 
{-8,1,8.062257748}, //64D-34方位 
{-4,1,4.123105626}, //64D-35方位 
{-8,3,8.544003745}, //64D-36方位 
{-2,1,2.236067977}, //64D-37方位 
{-8,5,9.433981132}, //64D-38方位 
{-4,3,5.0},         //64D-39方位 
{-8,7,10.63014581}, //64D-40方位 
{-1,1,1.414213562}, //64D-41方位 
{-7,8,10.63014581}, //64D-42方位 
{-3,4,5.0},         //64D-43方位 
{-5,8,9.433981132}, //64D-44方位 
{-1,2,2.236067977}, //64D-45方位 
{-3,8,8.544003745}, //64D-46方位 
{-1,4,4.123105626}, //64D-47方位 
{-1,8,8.062257748}, //64D-48方位 
{0,1,1.0},          //64D-49方位 
{1,8,8.062257748},  //64D-50方位 
{1,4,4.123105626},  //64D-51方位 
{3,8,8.544003745},  //64D-52方位 
{1,2,2.236067977},  //64D-53方位 
{5,8,9.433981132},  //64D-54方位 
{3,4,5.0},          //64D-55方位 
{7,8,10.63014581},  //64D-56方位 
{1,1,1.414213562},  //64D-57方位 
{8,7,10.63014581},  //64D-58方位 
{4,3,5.0},          //64D-59方位 
{8,5,9.433981132},  //64D-60方位 
{2,1,2.236067977},  //64D-61方位 
{8,3,8.544003745},  //64D-62方位 
{4,1,4.123105626},  //64D-63方位 
{8,1,8.062257748},  //64D-64方位 
};
struct StartThrumInfo StartThrum[CURVEMAXNUM]={0};//
struct FeaturePointInfo FeaturePoint[CURVEMAXNUM];// 特征点数组
struct ThrumInfo ThrumGroup[THRUMMAXNUM];
struct CurveInfo CurveGroup[CURVEMAXNUM];
struct StartThrumInfo StartThrumTemp;//
struct ThrumInfo ThrumTemp;
struct LINE LineGroup[LINENUM];
struct LINESEG LineSegGroup[LINENUM];
struct ThrumInfo LineConnect[LINENUM];
struct ThrumInfo LineParallel[LINENUM];
StepStrucureII LinePara[LINENUM]={0};//x对应直线所属曲线序号；y对应直线序号；stepdistense对应斜率
int StartThrumNum;//起始线段序号
int FeaturePointNum;//特征点序号
int ThrumNum;//线段序号
int CurveNum;//曲线序号
int LineNum;//直线序号
int ConLineNum;//连接线段序号
int ParallelLineNum;//平行直线序号

unsigned short MaxCurveGroup[MAXCURVENUM][2]={0};//最长曲线数组[][0]序号,[][1]长度
unsigned short CircleGroup[CIRCLENUM][4]={0};//圆数组[][0]序号,[][1]半径，[][2]圆心横坐标，[][3]圆心纵坐标
unsigned char CircleII[192]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63}; 
////////////////////////////////////////////////////////////////////////
//	文 件 名：DPSGII.cc
//	文件功能：感兴趣区域提取功能文件——基于第二代离散点采样和编组方法,用于直线段及轮廓探测
//	作    者：朱宗晓
//	创建时间：2012年3月27日
//	项目名称：目标检测识别算法测试评价平台
//	操作系统：Windows 7
//	备    注： 
////////////////////////////////////////////////////////////////////////
//	历史记录：
//	编号     日期    	作者    备注
//	0	2012年3月27日	朱宗晓	创建本文件
//	1	2010年3月27日	朱宗晓	增加了  int DPSGII_GrayStaTotal(unsigned char * Img_gray, int nWidth,int nHeight,int StartX, int StartY, int EndX,int EndY)
//  2   2010年3月27日	朱宗晓  增加了  unsigned char DPSGII_GraytoYYbinFast(unsigned char * Img_gray, int nWidth,int nHeight,int cenX, int cenY, int Rin, int Rout,int RoutTotal,int nWeberCoef)   
//  3   2010年3月27日	朱宗晓  增加了  unsigned char* DPSGII_SquaYinSampleFast(unsigned char* Img_gray, int nWidth,int nHeight,int Rin,int Rout,int nWeberCoef)                    
//  4   2010年3月27日	朱宗晓  增加了  unsigned char* DPSGII_SquaYangSampleFast(unsigned char* Img_gray, int nWidth,int nHeight,int Rin,int Rout,int nWeberCoef)                    
//  5   2010年3月27日	朱宗晓  增加了  void DPSGII_YinYangSampleFast(unsigned char* Img_gray, int nWidth,int nHeight,int Rin,int Rout,int nWeberCoef)
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	函 数 名：int DPSGII_GrayStaTotal(unsigned char * Img_gray, int nWidth,int nHeight,int StartX, int StartY, int EndX,int EndY)
//	函数功能：计算指定范围内灰度和(采样点邻域灰度均值)
//  函数过程：
//  先行函数：无
//  调用函数：无
//  后续函数：无
//  相关文档：无 
//	作    者：朱宗晓
//	时    间：2012年3月27日
//	返 回 值：grayRtotal指定范围内灰度和
//	入口参数说明：
//	1.unsigned char * Img_gray：待计算的灰度图数组
//  2.int nWidth：待计算的灰度图数组宽度
//  3.int nHeight：待计算的灰度图数组高度
//  4.int StartX：指定范围起始点横坐标
//  5.int StartY：指定范围起始点纵坐标
//  6.int EndX：指定范围结束点横坐标
//  7.int EndY：指定范围结束点纵坐标
////////////////////////////////////////////////////////////////////////
//	历史记录：
//	编号     日期    	作者    备注
//	0	2012年3月27日	朱宗晓	创建本函数
//	////////////////////////////////////////////////////////////////////////
int DPSGII_GrayStaTotal(unsigned char * Img_gray, int nWidth,int nHeight,int StartX, int StartY, int EndX,int EndY)
{
	int grayRtotal=0;
	int j=0;
	int i=0;
	if(StartX>EndX||StartY>EndY)
	{return 0;}
	if(StartX>EndX)//交换横坐标
	{
		i=StartX;
		StartX=EndX;
		EndX=i;
	}
	if(StartY>EndY)//交换纵坐标
	{
		j=StartY;
		StartY=EndY;
		EndY=j;
	}
	//计算Rin内圈灰度之和平均值
	for(j=StartY;j<EndY+1;j++)
		{
			for(i=StartX;i<EndX+1;i++)
			{
				grayRtotal+=((unsigned char*)(Img_gray + nWidth*j))[i];
			}
		}

	return grayRtotal;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	函 数 名：StepStrucureII DPSGII_RectDistri(unsigned char * Img_gray, int nWidth,int nHeight,int StartX, int StartY, int EndX,int EndY)
//	函数功能：统计指定范围内采样点所占比例情况
//  函数过程：
//  先行函数：无
//  调用函数：无
//  后续函数：无
//  相关文档：无 
//	作    者：朱宗晓
//	时    间：2012年3月27日
//	返 回 值：StepStrucureII RectDistri指定范围内采样点所占比例情况
//	入口参数说明：
//	1.unsigned char * Img_gray：待计算的灰度图数组
//  2.int nWidth：待计算的灰度图数组宽度
//  3.int nHeight：待计算的灰度图数组高度
//  4.int StartX：指定范围起始点横坐标
//  5.int StartY：指定范围起始点纵坐标
//  6.int EndX：指定范围结束点横坐标
//  7.int EndY：指定范围结束点纵坐标
////////////////////////////////////////////////////////////////////////
//	历史记录：
//	编号     日期    	作者    备注
//	0	2012年3月27日	朱宗晓	创建本函数
//	////////////////////////////////////////////////////////////////////////
StepStrucureII DPSGII_RectDistri(unsigned char * Img_gray, int nWidth,int nHeight,int StartX, int StartY, int EndX,int EndY)
{
	StepStrucureII RectDistri={0};
	int j=0;
	int i=0;
	RectDistri.ystep=1;
	if(StartX>EndX)//交换横坐标
	{
		i=StartX;
		StartX=EndX;
		EndX=i;
	}
	if(StartY>EndY)//交换纵坐标
	{
		j=StartY;
		StartY=EndY;
		EndY=j;
	}
	//计算Rin内圈灰度之和平均值
	for(j=StartY;j<EndY+1;j++)
	{
		for(i=StartX;i<EndX+1;i++)
		{
			RectDistri.xstep+=((unsigned char*)(Img_gray + nWidth*j))[i];//矩形灰度和
			RectDistri.ystep++;//组成矩形点数
		}
	}
	RectDistri.xstep=RectDistri.ystep-RectDistri.xstep/255;//黑点个数
	RectDistri.stepdistense=(double)RectDistri.xstep/RectDistri.ystep;//黑点比例
	return RectDistri;
}
////////////////////////////////////////////////////////////////////////
//	函 数 名：unsigned char DPSGII_GraytoYYbinFast(unsigned char * Img_gray, int nWidth,int nHeight,int cenX, int cenY, int Rin, int Rout,int RoutTotal,int nWeberCoef)
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
unsigned char DPSGII_GraytoYYbinFast(unsigned char * Img_gray, int nWidth,int nHeight,int cenX, int cenY, int Rin, int Rout,int RoutTotal,int nWeberCoef,int WeberCoefRatio,int ABSSign,int &YinCounter,int &YangCounter)
{
	int grayRinTotal=0;
	int grayRoutTotal=0;
	int graySub=0;
	double FloatnWeberCoef=0.0;
	grayRinTotal=DPSGII_GrayStaTotal(Img_gray,nWidth,nHeight,cenX-Rin,cenY-Rin,cenX+Rin,cenY+Rin)*((Rout<<1)+1)*((Rout<<1)+1);//内环灰度之和乘以面积系数
    grayRoutTotal= RoutTotal*(2*Rin+1)*(2*Rin+1);//外环灰度之和乘以面积系数
	FloatnWeberCoef=(WeberCoefRatio*(2*Rin+1)*(2*Rin+1)*((Rout<<1)+1)*((Rout<<1)+1))/(double)grayRinTotal;
	if(WeberCoefRatio!=0&&FloatnWeberCoef>1.0)
	{
		FloatnWeberCoef=nWeberCoef*FloatnWeberCoef;
	}
	else
	{
		FloatnWeberCoef=(double)nWeberCoef;
	}
	if(ABSSign==0)
	{
		graySub=grayRinTotal-grayRoutTotal;
	}
	else
	{
		graySub=abs(grayRinTotal-grayRoutTotal);

	}
	if((graySub*100)>(FloatnWeberCoef*grayRoutTotal))//内外环均值之差除以外环均值
	{
		YinCounter++;
		return 255;//Yin
	}
	else 
	{
		YangCounter++;
		return 0;//Yang
	}
}
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
unsigned char* DPSGII_SquaYinSampleFast(unsigned char* Img_gray, int nWidth,int nHeight,int Rin,int Rout,int nWeberCoef,int WeberCoefRatio,int ABSSign,int &YinCounter,int &YangCounter)
{
	unsigned char*	YYBin=new unsigned char[nWidth*nHeight];
	int x=0;
	int y=0;
    int grayTotalTemp=0;//外环灰度和
	int grayPartOne=0;//移出条带灰度和
	int grayPartTwo=0;//移入条带灰度和
	memset(YYBin,255,nWidth*nHeight*sizeof(char));
	for(y=(int)Rout;y<nHeight-Rout;y+=Rin)
	{
		x=(int)Rout;
		
		grayTotalTemp=DPSGII_GrayStaTotal(Img_gray,nWidth,nHeight,x-Rout,y-Rout,x+Rout,y+Rout);
		((unsigned char*)(YYBin + nWidth*(y)))[x]=~(DPSGII_GraytoYYbinFast(Img_gray,nWidth,nHeight,x,y,Rin,Rout,grayTotalTemp,nWeberCoef,WeberCoefRatio, ABSSign,YinCounter,YangCounter));
		for(x=(int)Rout+Rin;x<nWidth-Rout;x+=Rin)
		{
			grayPartOne=DPSGII_GrayStaTotal(Img_gray,nWidth,nHeight,x-Rout-Rin,y-Rout,x-Rout-1,y+Rout);
			grayPartTwo=DPSGII_GrayStaTotal(Img_gray,nWidth,nHeight,x+Rout-Rin+1,y-Rout,x+Rout,y+Rout);
			grayTotalTemp=grayTotalTemp-grayPartOne+grayPartTwo;
			((unsigned char*)(YYBin + nWidth*(y)))[x]=~(DPSGII_GraytoYYbinFast(Img_gray,nWidth,nHeight,x,y,Rin,Rout,grayTotalTemp,nWeberCoef,WeberCoefRatio, ABSSign,YinCounter,YangCounter));
		}
	}
	return YYBin;
}
////////////////////////////////////////////////////////////////////////
//	函 数 名：unsigned char*DPSGII_SquaYangSampleFast(unsigned char* Img_gray, int nWidth,int nHeight,int Rin,int Rout,int nWeberCoef)
//	函数功能：实现灰度图阳采样
//  函数过程：
//  先行函数：无
//  调用函数：unsigned char DPSGII_GraytoYYbinFast(unsigned char * Img_gray, int nWidth,int nHeight,int cenX, int cenY, int Rin, int Rout,int RoutTotal,int nWeberCoef)
//  后续函数：无
//  相关文档：Object detection based on multi-scale discrete points sampling and grouping.doc 
//	作    者：朱宗晓
//	时    间：2012年3月27日
//	返 回 值：unsigned char* YYBin 阳采样图
//	入口参数说明：
//	1.unsigned char* Img_gray：待计算的灰度图
//  2.int nWidth：待计算的灰度图数组宽度
//  3.int nHeight：待计算的灰度图数组高度
//  4.int Rin：内环半径
//  5.int Rout：外环半径
//  6.int nWeberCoeft：韦伯系数
////////////////////////////////////////////////////////////////////////
//	历史记录：
//	编号     日期    	作者    备注
//	0	2012年3月27日	朱宗晓	创建本函数
//	////////////////////////////////////////////////////////////////////////
unsigned char* DPSGII_SquaYangSampleFast(unsigned char* Img_gray, int nWidth,int nHeight,int Rin,int Rout,int nWeberCoef,int WeberCoefRatio,int ABSSign,int &YinCounter,int &YangCounter)
{
	unsigned char*	YYBin=new unsigned char[nWidth*nHeight];
	int x=0;
	int y=0;
	int grayTotalTemp=0;//外环灰度和
	int grayPartOne=0;//移出条带灰度和
	int grayPartTwo=0;//移入条带灰度和
	memset(YYBin,255,nWidth*nHeight*sizeof(char));
	for(y=(int)Rout;y<nHeight-Rout;y+=Rin)
	{
		x=(int)Rout;
		
		grayTotalTemp=DPSGII_GrayStaTotal(Img_gray,nWidth,nHeight,x-Rout,y-Rout,x+Rout,y+Rout);
		((unsigned char*)(YYBin + nWidth*(y)))[x]=~(DPSGII_GraytoYYbinFast(Img_gray,nWidth,nHeight,x,y,Rin,Rout,grayTotalTemp,nWeberCoef,WeberCoefRatio, ABSSign,YinCounter,YangCounter));
		for(x=(int)Rout+Rin;x<nWidth-Rout;x+=Rin)
		{
			grayPartOne=DPSGII_GrayStaTotal(Img_gray,nWidth,nHeight,x-Rout-Rin,y-Rout,x-Rout-1,y+Rout);
			grayPartTwo=DPSGII_GrayStaTotal(Img_gray,nWidth,nHeight,x+Rout-Rin+1,y-Rout,x+Rout,y+Rout);
			grayTotalTemp=grayTotalTemp-grayPartOne+grayPartTwo;
			((unsigned char*)(YYBin + nWidth*(y)))[x]=DPSGII_GraytoYYbinFast(Img_gray,nWidth,nHeight,x,y,Rin,Rout,grayTotalTemp,nWeberCoef,WeberCoefRatio, ABSSign,YinCounter,YangCounter);
		}
	}
	return YYBin;
}
////////////////////////////////////////////////////////////////////////
//	函 数 名：void DPSGII_YinYangSampleFast(unsigned char* Img_gray, int nWidth,int nHeight,int Rin,int Rout,int nWeberCoef)
//	函数功能：实现灰度图阴阳同时采样
//  函数过程：
//  先行函数：无
//  调用函数：unsigned char DPSGII_GraytoYYbinFast(unsigned char * Img_gray, int nWidth,int nHeight,int cenX, int cenY, int Rin, int Rout,int RoutTotal,int nWeberCoef)
//  后续函数：无
//  相关文档：Object detection based on multi-scale discrete points sampling and grouping.doc 
//	作    者：朱宗晓
//	时    间：2012年3月27日
//	返 回 值：YinMap阴采样图 YangMap阳采样图
//	入口参数说明：
//	1.unsigned char* Img_gray：待计算的灰度图
//  2.int nWidth：待计算的灰度图数组宽度
//  3.int nHeight：待计算的灰度图数组高度
//  4.int Rin：内环半径
//  5.int Rout：外环半径
//  6.int nWeberCoeft：韦伯系数
////////////////////////////////////////////////////////////////////////
//	历史记录：
//	编号     日期    	作者    备注
//	0	2012年3月27日	朱宗晓	创建本函数
//	////////////////////////////////////////////////////////////////////////
void DPSGII_YinYangSampleFast(unsigned char* Img_gray, unsigned char* &g_pYinMap,unsigned char* &g_pYangMap,int nWidth,int nHeight,int Rin,int Rout,int nWeberCoef,int WeberCoefRatio,int ABSSign,int &YinCounter,int &YangCounter)
{
	int x=0;
	int y=0;
	int grayTotalTemp=0;//外环灰度和
	int grayPartOne=0;//移出条带灰度和
	int grayPartTwo=0;//移入条带灰度和
	for(y=(int)Rout;y<nHeight-Rout;y+=Rin)
	{
		x=(int)Rout;
		grayTotalTemp=DPSGII_GrayStaTotal(Img_gray,nWidth,nHeight,x-Rout,y-Rout,x+Rout,y+Rout);
		((unsigned char*)(g_pYangMap + nWidth*(y)))[x]=DPSGII_GraytoYYbinFast(Img_gray,nWidth,nHeight,x,y,Rin,Rout,grayTotalTemp,nWeberCoef,WeberCoefRatio, ABSSign,YinCounter,YangCounter);
		((unsigned char*)(g_pYinMap + nWidth*(y)))[x]=~(((unsigned char*)(g_pYangMap + nWidth*(y)))[x]);
		for(x=(int)Rout+Rin;x<nWidth-Rout;x+=Rin)
		{
			grayPartOne=DPSGII_GrayStaTotal(Img_gray,nWidth,nHeight,x-Rout-Rin,y-Rout,x-Rout-1,y+Rout);
			grayPartTwo=DPSGII_GrayStaTotal(Img_gray,nWidth,nHeight,x+Rout-Rin+1,y-Rout,x+Rout,y+Rout);
			grayTotalTemp=grayTotalTemp-grayPartOne+grayPartTwo;
			((unsigned char*)(g_pYangMap + nWidth*(y)))[x]=DPSGII_GraytoYYbinFast(Img_gray,nWidth,nHeight,x,y,Rin,Rout,grayTotalTemp,nWeberCoef,WeberCoefRatio, ABSSign,YinCounter,YangCounter);
			((unsigned char*)(g_pYinMap + nWidth*(y)))[x]=~(((unsigned char*)(g_pYangMap + nWidth*(y)))[x]);
		}
	}
}
////////////////////////////////////////////////////////////////////////
//	函 数 名：int DPSGII_DPAdnate8Check(unsigned char* Img_bin,int nWidth,int nHeight,int cenX, int cenY,int R)
//	函数功能：计算Img_bin指定点的连通性
//  函数过程：
//  先行函数：无
//  调用函数：无
//  后续函数：无
//  相关文档：Object detection based on multi-scale discrete points sampling and grouping.doc 
//	作    者 ：朱宗晓
//	时    间 ：2012年3月28日
//	返 回 值 ：连通性 0-8
//	入口参数说明 ：
//	1.unsigned char* Img_bin：待计算的二值图
//  2.int nWidth：待计算的二值图数组宽度
//  3.int nHeight：待计算的二值图数组高度
//	4.int R：二值图采样半径
////////////////////////////////////////////////////////////////////////
//	历史记录：
//	编号     日期    	作者    备注
//	0	2012年3月28日	朱宗晓	创建本函数
//	////////////////////////////////////////////////////////////////////////
int DPSGII_DPAdnate8Check(unsigned char* Img_bin,int nWidth,int nHeight,int cenX, int cenY,int R)
{
	if(cenX<R||cenY<R||(cenX+R)>=nWidth||(cenY+R)>=nHeight)
	{return 0x0;}
	//8个联通点之和
	unsigned int AdnateTotal=
		((unsigned char*)(Img_bin + nWidth*(cenY)))[cenX-R]//左
	+   ((unsigned char*)(Img_bin + nWidth*(cenY)))[cenX+R]//右
	+	((unsigned char*)(Img_bin + nWidth*(cenY-R)))[cenX]//上
	+	((unsigned char*)(Img_bin + nWidth*(cenY-R)))[cenX-R]//上左
	+	((unsigned char*)(Img_bin + nWidth*(cenY-R)))[cenX+R]//上右	
	+	((unsigned char*)(Img_bin + nWidth*(cenY+R)))[cenX]//下
	+	((unsigned char*)(Img_bin + nWidth*(cenY+R)))[cenX-R]//下左
	+	((unsigned char*)(Img_bin + nWidth*(cenY+R)))[cenX+R];//下右	
	return 8-AdnateTotal/255;//0,1,2,3,4,5,6,7，8
}
////////////////////////////////////////////////////////////////////////
//	函 数 名：bool DPSGII_DPSignCheck(unsigned char* Img_bin,int nWidth,int nHeight,int cenX, int cenY,int R)
//	函数功能：判断邻域内是否有黑点
//  函数过程：
//  先行函数：无
//  调用函数：无
//  后续函数：无
//  相关文档：Object detection based on multi-scale discrete points sampling and grouping.doc 
//	作    者 ：朱宗晓
//	时    间 ：2012年9月9日
//	返 回 值 ：邻域内有黑点返回0,全白返回1
//	入口参数说明 ：
//	1.unsigned char* Img_bin：待计算的二值图
//  2.int nWidth：待计算的二值图数组宽度
//  3.int nHeight：待计算的二值图数组高度
//  4.int cenX：待计算中心点横坐标
//  5.int cenY：待计算中心点纵坐标
//	6.int R：二值图采样半径
////////////////////////////////////////////////////////////////////////
//	历史记录：
//	编号     日期    	作者    备注
//	0	2012年9月9日	朱宗晓	创建本函数
//	////////////////////////////////////////////////////////////////////////
bool DPSGII_DPSignCheck(unsigned char* Img_bin,int nWidth,int nHeight,int cenX, int cenY,int R)
{
	int j=0;
	int i=0;
	bool BlackSing=0; 
	for(j=cenY-R;j<=cenY+R;j++)
	{
		for(i=cenX-R;i<=cenX+R;i++)
		{
				if(((unsigned char*)(Img_bin + nWidth*j))[i]!=255)
				{
					return 0;
				}
		}
	}

	return  1;
	
}
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
int DPSGII_DPAdnateValueFilterR(unsigned char* Img_bin,int nWidth,int nHeight,int Rin,  int Rout,int Value)
{ 
	int y=0;
    int x=0;
	int PointChange=0;
	unsigned char*TempMapNow=new unsigned char[nWidth*nHeight];
	memcpy(TempMapNow,Img_bin,nWidth*nHeight*sizeof(unsigned char));
	//ThrumInfo LineSegTemp;
	for(y=Rout;y<nHeight-Rout;y+=Rin)
	{
		for(x=Rout;x<nWidth-Rout;x+=Rin)
		{
			if((((unsigned char*)(Img_bin + nWidth*(y)))[x]!=0)&&(DPSGII_DPAdnate8Check(Img_bin,nWidth,nHeight,x,y,Rin)>=Value))//补洞
			{
				
					((unsigned char*)(Img_bin + nWidth*(y)))[x]=0;
					PointChange++;
					
				
			}
		
			else if((((unsigned char*)(Img_bin + nWidth*(y)))[x]!=255)&&(DPSGII_DPAdnate8Check(TempMapNow,nWidth,nHeight,x,y,Rin)<Value))
			{
				{
					((unsigned char*)(Img_bin + nWidth*(y)))[x]=255;
					PointChange--;
				
				}
			}
		}
    }
	delete TempMapNow;
	return PointChange;
}
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
int DPSGII_DPYinYangFilterR(unsigned char* Img_bin,unsigned char* Img_bin2,int nWidth,int nHeight,int Rin,  int Rout,int Value)
{ 
	int y=0;
    int x=0;
	int PointChange=0;
	unsigned char*TempMapNow=new unsigned char[nWidth*nHeight];
	memcpy(TempMapNow,Img_bin,nWidth*nHeight*sizeof(unsigned char));
	//ThrumInfo LineSegTemp;
	for(y=Rout;y<nHeight-Rout;y+=Rin)
	{
		for(x=Rout;x<nWidth-Rout;x+=Rin)
		{
			if((((unsigned char*)(Img_bin + nWidth*(y)))[x]!=0)&&(DPSGII_DPAdnate8Check(Img_bin,nWidth,nHeight,x,y,Rin)>=Value))//补洞
			{
				
					((unsigned char*)(Img_bin + nWidth*(y)))[x]=0;
					((unsigned char*)(Img_bin2 + nWidth*(y)))[x]=255;
					PointChange++;
					
				
			}
		
			else if((((unsigned char*)(Img_bin + nWidth*(y)))[x]!=255)&&(DPSGII_DPAdnate8Check(TempMapNow,nWidth,nHeight,x,y,Rin)<Value))
			{
				{
					((unsigned char*)(Img_bin + nWidth*(y)))[x]=255;
					((unsigned char*)(Img_bin2 + nWidth*(y)))[x]=0;
					PointChange--;
				
				}
			}
		}
    }
	delete TempMapNow;
	return PointChange;
}
////////////////////////////////////////////////////////////////////////
//	函 数 名：int DPSGII_DPAdnateNCheck(unsigned char* Img_bin,int nWidth,int nHeight,int cenX, int cenY,int R,int N)
//	函数功能：检查离散点采样图N倍半径范围的连通性
//  函数过程：
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
//  4.int cenX：待计算中心点横坐标
//  5.int cenY：待计算中心点纵坐标
//	6.int R：二值图采样半径
//	7.int N：N倍半径
////////////////////////////////////////////////////////////////////////
//	历史记录：
//	编号     日期    	作者    备注
//	0	2012年3月28日	朱宗晓	创建本函数
///////////////////////////////////////////////////////////////////////////
int DPSGII_DPAdnateNCheck(unsigned char* Img_bin,int nWidth,int nHeight,int cenX, int cenY,int R,int N)
{
	if(cenX<N*R||cenY<N*R||(cenX+N*R)>=nWidth||(cenY+N*R)>=nHeight)
	{return 0x0;}
	unsigned int AdnateTotal=0;
	int n=0;
	for (int i=cenX-N*R;i<=cenX+N*R;i+=R)
	{
		for (int j=cenY-N*R;j<=cenY+N*R;j+=R)
		{
			if (i>=cenX-(N-1)*R && i<=cenX+(N-1)*R && j>=cenY-(N-1)*R && j<=cenY+(N-1)*R)
			{			
			}
			else
			{
				n++;
				AdnateTotal+=((unsigned char*)(Img_bin + nWidth*j))[i];
			}
		}
	}
	return 8*N-AdnateTotal/255;
}
////////////////////////////////////////////////////////////////////////
//	函 数 名：int DPSGII_DPFilterR(unsigned char* Img_bin,int nWidth,int nHeight,int Rin,  int Rout, int N)
//	函数功能：对离散点采样得到的阴阳采样图按倍半径范围连通性进行填洞
//  函数过程：连通性大于等于Value的填洞
//  先行函数：无
//  调用函数：无
//  后续函数：无
//  相关文档：Object detection based on multi-scale discrete points sampling and grouping.doc 
//	作    者：朱宗晓
//	时    间：2012年9月9日
//	返 回 值：无
//	入口参数说明 ：
//	1.unsigned char* Img_bin：待计算的二值图
//  2.int nWidth：待计算的二值图数组宽度
//  3.int nHeight：待计算的二值图数组高度
//  4.int Rin：采样半径
//  5.int Rout：外环半径
//	6.int N：N倍半径
////////////////////////////////////////////////////////////////////////
//	历史记录：
//	编号     日期    	作者    备注
//	0	2012年9月9日	朱宗晓	创建本函数
///////////////////////////////////////////////////////////////////////////
int DPSGII_DPFilterR(unsigned char* Img_bin,int nWidth,int nHeight,int Rin,  int Rout, int N)
{ 
	int y=0;
	int x=0;
	int PointChange=0;
	unsigned char * TempMapNow=new unsigned char[nWidth*nHeight];
	memcpy(TempMapNow,Img_bin,nWidth*nHeight);
	bool flag=false;
	int M=N;
	for(y=Rout;y<nHeight-Rout;y+=Rin)
	{
		for(x=Rout;x<nWidth-Rout;x+=Rin)
		{
			
			if(((unsigned char*)(TempMapNow + nWidth*(y)))[x]==255)
			{
				flag=false;
				M=N;
				for (int i=N;i>=1;i--)
				{
					if (DPSGII_DPAdnateNCheck(TempMapNow,nWidth,nHeight,x,y,Rin,i)==8*i)
					{
						flag=true;
						M=i;
						break;
					}
				}
				
				if (flag)
				{
					//填洞
					for (int i=x-M*Rin;i<=x+M*Rin;i+=Rin)
					{
						for (int j=y-M*Rin;j<=y+M*Rin;j+=Rin)
						{
							if(((unsigned char*)(Img_bin + nWidth*j))[i]==255)
							{
								PointChange++;
							}
							((unsigned char*)(Img_bin + nWidth*j))[i]=0;
						}
					}
				}
				
			}
		}

	}
	delete []TempMapNow;
	return PointChange;
}
////////////////////////////////////////////////////////////////////////
//	函 数 名 ：int SEG_CHAR_YPositionLine(int StartX,int StartY,int EndX, int EndY,int SetX)
//	函数功能 ：已知直线上两点和第三点横坐标，求纵坐标
//  函数过程 ：根据两点直线公式计算
//  先行函数 ：
//  调用函数 ：
//  后续函数 ：
//  相关文档 ：无
//	作    者 ：朱宗晓
//	时    间 ：2010年6月9日
//	返 回 值 ：
//	入口参数说明 ：

////////////////////////////////////////////////////////////////////////
//	历史记录：
//	编号     日期    	作者    备注
//	0	2010年06月09日	朱宗晓	创建本函数
//	////////////////////////////////////////////////////////////////////////
int SEG_CHAR_YPositionLine(int StartX,int StartY,int EndX, int EndY,int SetX)
{
	int YPosition=0;
	YPosition=int(((double)EndY-(double)StartY)*((double)SetX-(double)StartX)/((double)EndX-(double)StartX)+StartY+0.5);
	return YPosition;
}
////////////////////////////////////////////////////////////////////////
//	函 数 名 ：int SEG_CHAR_YPositionLine(int StartX,int StartY,int EndX, int EndY,int SetX)
//	函数功能 ：已知直线上两点和第三点纵坐标，求横坐标
//  函数过程 ：根据两点直线公式计算
//  先行函数 ：
//  调用函数 ：
//  后续函数 ：
//  相关文档 ：无
//	作    者 ：朱宗晓
//	时    间 ：2010年6月9日
//	返 回 值 ：
//	入口参数说明 ：

////////////////////////////////////////////////////////////////////////
//	历史记录：
//	编号     日期    	作者    备注
//	0	2010年06月09日	朱宗晓	创建本函数
//	////////////////////////////////////////////////////////////////////////
int SEG_CHAR_XPositionLine(int StartX,int StartY,int EndX, int EndY,int SetY)
{
	int XPosition=0;
	XPosition=int(((double)EndX-(double)StartX)*((double)SetY-(double)StartY)/((double)EndY-(double)StartY)+StartX+0.5);
	return XPosition;
}
////////////////////////////////////////////////////////////////////////
//	函 数 名 ：int DPSGII_ColumnPoint(unsigned char *Img_bin,int nWidth,int nHeight,int StartPx,int StartPy,int EndPx,int EndPy,int R,int Rout)
//	函数功能 ：按水平方向计算纵坐标，统计两点间黑像素的个数
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
int DPSGII_ColumnPoint(unsigned char *Img_bin,int nWidth,int nHeight,int StartPx,int StartPy,int EndPx,int EndPy,int R,int Rout)
{
	int LinePoint=0;
	int tempY=0;
	int tempX=0;
	int i=0;
	if((StartPx<Rout||EndPx<Rout||StartPy<Rout||EndPy<Rout||StartPx>nWidth-Rout||EndPx>nWidth-Rout||StartPy>nHeight-Rout||EndPy>nHeight-Rout))
	{return LinePoint;}
	if( StartPx> EndPx)
	{
		tempX=StartPx;
		StartPx=EndPx;
		EndPx=tempX;
		tempY=StartPy;
		StartPy=EndPy;
		EndPy=tempY;
	}
	for(i=StartPx;i<=EndPx;i+=R)
	{
		tempY=SEG_CHAR_YPositionLine(StartPx,StartPy,EndPx,EndPy,i);
		if(((unsigned char*)(Img_bin + nWidth*(tempY)))[i]==0)
		{
            LinePoint++;
		}
		else if(DPSGII_DPAdnate8Check(Img_bin,nWidth,nHeight,i,tempY,1)>1)
		{
			LinePoint++;
		}

	}
	return LinePoint;
}
////////////////////////////////////////////////////////////////////////
//	函 数 名 ：int DPSGII_RowPoint(unsigned char *Img_bin,int nWidth,int nHeight,int StartPx,int StartPy,int EndPx,int EndPy,int R,int Rout)
//	函数功能 ：按竖直方向计算横坐标，统计两点间黑像素的个数
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
int DPSGII_RowPoint(unsigned char *Img_bin,int nWidth,int nHeight,int StartPx,int StartPy,int EndPx,int EndPy,int R,int Rout)
{
	int LinePoint=0;
	int tempY=0;
	int tempX=0;
	int i=0;
    if((StartPx<Rout||EndPx<Rout||StartPy<Rout||EndPy<Rout||StartPx>nWidth-Rout||EndPx>nWidth-Rout||StartPy>nHeight-Rout||EndPy>nHeight-Rout))
	{return LinePoint;}
	if( StartPy> EndPy)
	{
		tempX=StartPx;
		StartPx=EndPx;
		EndPx=tempX;
		tempY=StartPy;
		StartPy=EndPy;
		EndPy=tempY;
	}
	for(i=StartPy;i<=EndPy;i+=R)
	{
		tempX=SEG_CHAR_XPositionLine(StartPx,StartPy,EndPx,EndPy,i);
		if(((unsigned char*)(Img_bin + nWidth*i))[tempX]==0)
		{
            LinePoint++;
		}
		else if(DPSGII_DPAdnate8Check(Img_bin,nWidth,nHeight,tempX,i,1)>1)
		{
			LinePoint++;
		}
	}
	return LinePoint;
}
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
bool DPSG_AdnoteLinePoint(unsigned char *Img_bin,int nWidth,int nHeight,int StartPx,int StartPy,int EndPx,int EndPy,int R,int Rout)
{
	int LinePoint=0;
	int tempY=0;
	int tempX=0;
	int i=0;
	bool AdnoteSign=true;
	 if((StartPx<Rout||EndPx<Rout||StartPy<Rout||EndPy<Rout||StartPx>nWidth-Rout||EndPx>nWidth-Rout||StartPy>nHeight-Rout||EndPy>nHeight-Rout))
	{return false;}
	if(StartPx==EndPx)
	{
		if( StartPy> EndPy)
		{
			tempX=StartPx;
			StartPx=EndPx;
			EndPx=tempX;
			tempY=StartPy;
			StartPy=EndPy;
			EndPy=tempY;
		}
		for(i=StartPy;i<=EndPy;i+=R)
		{
			if(((unsigned char*)(Img_bin + nWidth*i))[StartPx]==0)
			{
				 LinePoint++;
			}
		}
		if(LinePoint<abs((EndPy-StartPy)/R)+1)
		{
			AdnoteSign=false;
		}
	}
	else if(StartPy==EndPy)
	{
		if( StartPx> EndPx)
		{
			tempX=StartPx;
			StartPx=EndPx;
			EndPx=tempX;
			tempY=StartPy;
			StartPy=EndPy;
			EndPy=tempY;
		}
		for(i=StartPx;i<=EndPx;i+=R)
		{
			if(((unsigned char*)(Img_bin + nWidth*(StartPy)))[i]==0)
			{
				LinePoint++;
			}
		}
		if(LinePoint<(abs(EndPx-StartPx)/R)+1)//黑像素个数较少
		{
			AdnoteSign=false;
		}
	}
	else if(abs(StartPx-EndPx)>=abs(StartPy-EndPy))
	{
		LinePoint=DPSGII_ColumnPoint(Img_bin,nWidth,nHeight,StartPx,StartPy,EndPx,EndPy,R,Rout);
		if(LinePoint<abs((EndPx-StartPx)/R)+1)
		{
			AdnoteSign=false;//黑像素个数较少
		}
	}
	else if(abs(StartPy-EndPy)>abs(StartPx-EndPx))
	{
		LinePoint=DPSGII_RowPoint(Img_bin,nWidth,nHeight,StartPx,StartPy,EndPx,EndPy,R,Rout);
		if(LinePoint<abs((EndPy-StartPy)/R)+1)
		{
			AdnoteSign=false;
		}
	}
   // TRACE("StartPx=%d,EndPx=%d,StartPy=%d,EndPy=%d,LinePoint=%d\n,",StartPx,EndPx,StartPy,EndPy,LinePoint);
	return AdnoteSign;
}
////////////////////////////////////////////////////////////////////////
//	函 数 名 ：StepStrucureII(double) DPSGII_DPTraceR64D(IplImage * Img_bin, int cenX, int cenY, int R, unsigned int Direction)
//	函数功能 ：计算Img_bin指定点64个方向之一的连通长度
//	作    者 ：朱宗晓
//	时    间 ：2012年3月28日
//	返 回 值 ：StepStrucureII TraceTemp64个方向之一线段情况
//	入口参数说明 ：
//	1.IplImage * Img_bin：待计算的二值图
//	2.int cenX：指定点横坐标
//	3.int cenY：指定点横坐标
//	4.int R：二值图采样半径
//  5.unsigned int Direction:64个方向之一
////////////////////////////////////////////////////////////////////////
//	历史记录：
//	编号     日期    	作者    备注
//	0	2012年3月28日	朱宗晓	创建本函数
//	////////////////////////////////////////////////////////////////////////
StepStrucureII DPSGII_DPTraceR64D(unsigned char* Img_bin,int nWidth,int nHeight, int cenX, int cenY, int R,int Rout, unsigned int Direction)
{
	StepStrucureII TraceTemp;
	TraceTemp.xstep=cenX;
	TraceTemp.ystep=cenY;
	TraceTemp.stepdistense=0.0;
    int PDCNum=0;
	if(cenY<Rout||cenX<Rout||cenY>nHeight-Rout||cenX>nWidth-Rout||Direction<1||Direction>64)
	{return TraceTemp;}
	int XPosition=cenX+g_oDistense64D[Direction].xstep*R;
	int YPosition=cenY+g_oDistense64D[Direction].ystep*R;
	if((XPosition>nWidth-Rout)||(XPosition<Rout)||(YPosition>nHeight-Rout)||(YPosition<Rout))
	{return TraceTemp;}
	PDCNum++;
	int LastXPosition=cenX;
	int LastYPosition=cenY;
	if(!DPSG_AdnoteLinePoint(Img_bin,nWidth,nHeight,XPosition,YPosition,LastXPosition,LastYPosition,R,Rout))//第一步就不能走
	{return TraceTemp;}

	while((XPosition<nWidth-Rout)
		&&(XPosition>Rout)
        &&(YPosition<nHeight-Rout)
		&&(YPosition>Rout)
		&&(((unsigned char*)(Img_bin + nWidth*YPosition))[XPosition]==0))
	{
		if((LastXPosition!=XPosition)&&(YPosition!=LastYPosition))
		{
			if(!DPSG_AdnoteLinePoint(Img_bin,nWidth,nHeight,XPosition,YPosition,LastXPosition,LastYPosition,R,Rout))
			{break;}
		}
		PDCNum++;
		LastXPosition=XPosition;
		LastYPosition=YPosition;
		XPosition=XPosition+g_oDistense64D[Direction].xstep*R;
		YPosition=YPosition+g_oDistense64D[Direction].ystep*R;
		if((XPosition>nWidth-Rout)||(XPosition<Rout)||(YPosition>nHeight-Rout)||(YPosition<Rout))
		{break;}
		
	}
	PDCNum--;
	TraceTemp.stepdistense=g_oDistense64D[Direction].stepdistense*PDCNum*R;
	TraceTemp.xstep=LastXPosition;
	TraceTemp.ystep=LastYPosition;
	//double tempdist=dist(CGPOINT(cenX,cenY),CGPOINT(LastXPosition,LastYPosition));
	return TraceTemp;
}
////////////////////////////////////////////////////////////////////////
//	函 数 名 ：double DPSGII_DPDisR64D (IplImage * Img_bin, int cenX, int cenY, int R, unsigned int Direction)
//	函数功能 ：计算Img_bin指定点64个方向之一的连通长度
//	作    者 ：朱宗晓
//	时    间 ：2012年3月28日
//	返 回 值 ： double PDCdist1-64方向连通长度
//	入口参数说明 ：
//	1.IplImage * Img_bin：待计算的二值图
//	2.int cenX：指定点横坐标
//	3.int cenY：指定点横坐标
//	4.int R：二值图采样半径
//  5.unsigned int Direction:64个方向之一
////////////////////////////////////////////////////////////////////////
//	历史记录：
//	编号     日期    	作者    备注
//	0	2012年3月28日	朱宗晓	创建本函数
//	////////////////////////////////////////////////////////////////////////
double DPSGII_DPDisR64D(unsigned char* Img_bin,int nWidth,int nHeight, int cenX, int cenY, int R,int Rout, unsigned int Direction)
{
	double PDCdist=0.0;
	StepStrucureII RectDistriTemp; 
	memset(&RectDistriTemp,0,sizeof(StepStrucureII));
	int PDCNum=0;
	if(cenY<Rout||cenX<Rout||cenY>nHeight-Rout||cenX>nWidth-Rout||Direction<1||Direction>64)
	{return PDCdist;}
	int XPosition=cenX+g_oDistense64D[Direction].xstep*R;
	int YPosition=cenY+g_oDistense64D[Direction].ystep*R;
	int LastXPosition=cenX;
	int LastYPosition=cenY;
	if(!DPSG_AdnoteLinePoint(Img_bin,nWidth,nHeight,XPosition,YPosition,LastXPosition,LastYPosition,R,Rout))//第一步就不能走
	{return  PDCdist;}
	while((XPosition<nWidth-Rout)
		&&(XPosition>Rout)
        &&(YPosition<nHeight-Rout)
		&&(YPosition>Rout)
		&&(((unsigned char*)(Img_bin + nWidth*YPosition))[XPosition]==0))
	{
			if((LastXPosition!=XPosition)&&(YPosition!=LastYPosition))
		{
			if(!DPSG_AdnoteLinePoint(Img_bin,nWidth,nHeight,XPosition,YPosition,LastXPosition,LastYPosition,R,Rout))
			{break;}
		}
		PDCNum++;
		LastXPosition=XPosition;
		LastYPosition=YPosition;
		XPosition=XPosition+g_oDistense64D[Direction].xstep*R;
		YPosition=YPosition+g_oDistense64D[Direction].ystep*R;
		if((XPosition>nWidth-Rout)||(XPosition<Rout)||(YPosition>nHeight-Rout)||(YPosition<Rout))
		{break;}
	}
    PDCNum--;
	PDCdist=g_oDistense64D[Direction].stepdistense*PDCNum*R;
	return PDCdist;
}
////////////////////////////////////////////////////////////////////////
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
ThrumInfo DPSGII_LineSearch64D(unsigned char* Img_bin,int nWidth,int nHeight, int cenX, int cenY, int R,int Rout)
{
	ThrumInfo ThrumNow;
	int i=0;
	memset(&ThrumNow,0,sizeof(ThrumInfo));
	int MaxDirection=0;//最大方向
    double MaxPDC=0.0;//最长方向贡献度
	double ThrumTest32[33] = {0};
	StepStrucureII ThrumTest64[65] = {0};
	for(i=1;i<33;i++)
	{
		
		ThrumTest64[i]=DPSGII_DPTraceR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,i);
        ThrumTest64[i+32]=DPSGII_DPTraceR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,i+32);
		ThrumTest32[i]=ThrumTest64[i].stepdistense+ThrumTest64[i+32].stepdistense;
		if(ThrumTest32[i]>MaxPDC)
		{
			MaxPDC=ThrumTest32[i];
			MaxDirection=i;
		}
	}
	int NormOne=MaxDirection+16;//法线方向1
	    int NormTwo=MaxDirection-16;//法线方向2
		if(NormOne>64)
		{NormOne-=64;}
		if(NormTwo<1)
		{NormTwo+=64;}
		ThrumNow.ThrumNormdis=DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,NormOne)+DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,NormTwo);
		if(ThrumNow.ThrumNormdis<0.1)
		{
			NormOne=MaxDirection+15;//法线方向1
			NormTwo=MaxDirection-17;//法线方向2
			if(NormOne>64)
			{NormOne-=64;}
			if(NormTwo<1)
			{NormTwo+=64;}
			ThrumNow.ThrumNormdis=DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,NormOne)+DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,NormTwo);
		}
		if(ThrumNow.ThrumNormdis<0.1)
		{
			NormOne=MaxDirection+17;//法线方向1
			NormTwo=MaxDirection-15;//法线方向2
			if(NormOne>64)
			{NormOne-=64;}
			if(NormTwo<1)
			{NormTwo+=64;}
			ThrumNow.ThrumNormdis=DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,NormOne)+DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,NormTwo);
		}
		if(ThrumNow.ThrumNormdis<0.1)
		{
			NormOne=MaxDirection+18;//法线方向1
			NormTwo=MaxDirection-14;//法线方向2
			if(NormOne>64)
			{NormOne-=64;}
			if(NormTwo<1)
			{NormTwo+=64;}
			ThrumNow.ThrumNormdis=DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,NormOne)+DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,NormTwo);
		}
		if(ThrumNow.ThrumNormdis<0.1)
		{
			NormOne=MaxDirection+14;//法线方向1
			NormTwo=MaxDirection-18;//法线方向2
			if(NormOne>64)
			{NormOne-=64;}
			if(NormTwo<1)
			{NormTwo+=64;}
			ThrumNow.ThrumNormdis=DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,NormOne)+DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,NormTwo);
		}
	ThrumNow.ThrumDire=MaxDirection;
	ThrumNow.ThrumDist=MaxPDC;
	ThrumNow.ThrumStart.x=ThrumTest64[MaxDirection].xstep;
	ThrumNow.ThrumStart.y=ThrumTest64[MaxDirection].ystep;
	ThrumNow.ThrumEnd.x=ThrumTest64[MaxDirection+32].xstep;
	ThrumNow.ThrumEnd.y=ThrumTest64[MaxDirection+32].ystep;
   	return ThrumNow;
}
////////////////////////////////////////////////////////////////////////
//	函 数 名 ：unsigned char* DPSGII_YYLineSegPoint(unsigned char* Img_bin,int nWidth,int nHeight,int Rin,int Rout,int SegLength)
//	函数功能 ：挑选能够形成线段的点
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
unsigned char* DPSGII_YYLineSegPoint(unsigned char* Img_bin,int nWidth,int nHeight,int Rin,int Rout,int SegLength)
{
	unsigned char*	YYBin=new unsigned char[nWidth*nHeight];
	memset(YYBin,255,nWidth*nHeight*sizeof(unsigned char));
	ThrumInfo LineSegTemp;
	int x=0;
	int y=0;
	for(y=Rout;y<nHeight-Rout;y+=Rin)
	{
		for(x=Rout;x<nWidth-Rout;x+=Rin)
		{
			if(((unsigned char*)(Img_bin + nWidth*y))[x]==0)
			{
				LineSegTemp=DPSGII_LineSearch64D(Img_bin,nWidth,nHeight,x,y,Rin,Rout);
				if(LineSegTemp.ThrumDist>SegLength)
				{
					((unsigned char*)(YYBin + nWidth*y))[x]=0;
					//(*(P+308))++;
    			}
				
			}
		}
	}
	return YYBin;
}
////////////////////////////////////////////////////////////////////////
//	函 数 名 ：StartThrumInfo DPSGII_StartThrumSearch64D(unsigned char* Img_bin,int nWidth,int nHeight, int cenX, int cenY, int R)
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
StartThrumInfo DPSGII_StartThrumSearch64D(unsigned char* Img_bin,int nWidth,int nHeight, int cenX, int cenY, int R,int Rout)
{
	StartThrumInfo StartThrumNow;
	int i=0;
	memset(&StartThrumNow,0,sizeof(StartThrumInfo));
	int MaxDirection=0;//最大方向
    double MaxPDC=0.0;//最长方向贡献度
	double ThrumTest32[33] = {0};
	StepStrucureII ThrumTest64[65] = {0};
	int tempStep=0;
	double tempdist=0.0;
	int hisCenX=cenX;
	int HisCenY=cenY;
	for(i=1;i<33;i++)
	{
		
		ThrumTest64[i]=DPSGII_DPTraceR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,i);
        ThrumTest64[i+32]=DPSGII_DPTraceR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,i+32);
		ThrumTest32[i]=ThrumTest64[i].stepdistense+ThrumTest64[i+32].stepdistense;
		if(ThrumTest32[i]>MaxPDC)
		{
			MaxPDC=ThrumTest32[i];
			MaxDirection=i;
		}
	}
	tempdist=2*R*g_oDistense64D[MaxDirection].stepdistense;
	if(ThrumTest64[MaxDirection].stepdistense-ThrumTest64[MaxDirection+32].stepdistense>tempdist)
	{
		tempStep=int((ThrumTest64[MaxDirection].stepdistense+0.1)/tempdist);
		cenX=cenX+g_oDistense64D[MaxDirection].xstep*tempStep*R;
		cenY=cenY+g_oDistense64D[MaxDirection].ystep*tempStep*R;

	}
	else if(ThrumTest64[MaxDirection+32].stepdistense-ThrumTest64[MaxDirection].stepdistense>tempdist)
	{
		tempStep=int((ThrumTest64[MaxDirection+32].stepdistense+0.1)/tempdist);
		cenX=cenX+g_oDistense64D[MaxDirection+32].xstep*tempStep*R;
		cenY=cenY+g_oDistense64D[MaxDirection+32].ystep*tempStep*R;
	}
	int NormOne=MaxDirection+16;//法线方向1
	    int NormTwo=MaxDirection-16;//法线方向2
		double NormOneLength=0.0;//法线方向1长度
		double NormTwoLength=0.0;//法线方向2长度

		if(NormOne>64)
		{NormOne-=64;}
		if(NormTwo<1)
		{NormTwo+=64;}
		NormOneLength=DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,NormOne);
		NormTwoLength=DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,NormTwo);
		StartThrumNow.ThrumNormdis=NormOneLength+NormTwoLength;
		if(StartThrumNow.ThrumNormdis<0.1)
		{
			NormOne=MaxDirection+15;//法线方向1
			NormTwo=MaxDirection-17;//法线方向2
			if(NormOne>64)
			{NormOne-=64;}
			if(NormTwo<1)
			{NormTwo+=64;}
			NormOneLength=DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,NormOne);
			NormTwoLength=DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,NormTwo);
			StartThrumNow.ThrumNormdis=NormOneLength+NormTwoLength;
		}
		if(StartThrumNow.ThrumNormdis<0.1)
		{
			NormOne=MaxDirection+17;//法线方向1
			NormTwo=MaxDirection-15;//法线方向2
			if(NormOne>64)
			{NormOne-=64;}
			if(NormTwo<1)
			{NormTwo+=64;}
			NormOneLength=DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,NormOne);
			NormTwoLength=DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,NormTwo);
			StartThrumNow.ThrumNormdis=NormOneLength+NormTwoLength;
		}
		if(StartThrumNow.ThrumNormdis<0.1)
		{
			NormOne=MaxDirection+18;//法线方向1
			NormTwo=MaxDirection-14;//法线方向2
			if(NormOne>64)
			{NormOne-=64;}
			if(NormTwo<1)
			{NormTwo+=64;}
			NormOneLength=DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,NormOne);
			NormTwoLength=DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,NormTwo);
			StartThrumNow.ThrumNormdis=NormOneLength+NormTwoLength;
		}
		if(StartThrumNow.ThrumNormdis<0.1)
		{
			NormOne=MaxDirection+14;//法线方向1
			NormTwo=MaxDirection-18;//法线方向2
			if(NormOne>64)
			{NormOne-=64;}
			if(NormTwo<1)
			{NormTwo+=64;}
			NormOneLength=DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,NormOne);
			NormTwoLength=DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,NormTwo);
			StartThrumNow.ThrumNormdis=NormOneLength+NormTwoLength;
		}
   //修正起始点位置，使之更接近于法线中点
	if((NormOneLength-NormTwoLength)>R*g_oDistense64D[NormOne].stepdistense)
	{
		StartThrumNow.ThrumSource.x=cenX+g_oDistense64D[NormOne].xstep*R*(NormOneLength-NormTwoLength)/(g_oDistense64D[NormOne].stepdistense*2);
		StartThrumNow.ThrumSource.y=cenY+g_oDistense64D[NormOne].ystep*R*(NormOneLength-NormTwoLength)/(g_oDistense64D[NormOne].stepdistense*2);
	}
	else if((NormTwoLength-NormOneLength)>R*g_oDistense64D[NormTwo].stepdistense)
	{
		StartThrumNow.ThrumSource.x=cenX+g_oDistense64D[NormTwo].xstep*R*(NormTwoLength-NormOneLength)/(g_oDistense64D[NormTwo].stepdistense*2);
		StartThrumNow.ThrumSource.y=cenY+g_oDistense64D[NormTwo].ystep*R*(NormTwoLength-NormOneLength)/(g_oDistense64D[NormTwo].stepdistense*2);;
	}
	else
	{
		StartThrumNow.ThrumSource.x=cenX;
		StartThrumNow.ThrumSource.y=cenY;
	}
	StartThrumNow.ThrumDire=MaxDirection;
	StartThrumNow.ThrumDist=MaxPDC;
	StartThrumNow.ThrumStart.x=ThrumTest64[MaxDirection].xstep;
	StartThrumNow.ThrumStart.y=ThrumTest64[MaxDirection].ystep;
	StartThrumNow.ThrumEnd.x=ThrumTest64[MaxDirection+32].xstep;
	StartThrumNow.ThrumEnd.y=ThrumTest64[MaxDirection+32].ystep;
	
   	return StartThrumNow;
}
////////////////////////////////////////////////////////////////////////
//	函 数 名 ：void DPSGII_StartThrumToThrum(StartThrumInfo * StartThrumNow,ThrumInfo *ThrumNow)
//	函数功能 ：将线头结构体信息赋值给线段结构体
//	作    者 ：朱宗晓
//	时    间 ：2012年3月30日
//	返 回 值 ： 无
//	入口参数说明 ：
//	1.StartThrumInfo * StartThrumNow待赋值的线头结构体
//  2.ThrumInfo *ThrumNow要赋值的线段结构体
////////////////////////////////////////////////////////////////////////
//	历史记录：
//	编号     日期    	作者    备注
//	0	2012年3月30日	朱宗晓	创建本函数
//	////////////////////////////////////////////////////////////////////////
void DPSGII_StartThrumToThrum(StartThrumInfo * StartThrumNow,ThrumInfo *ThrumNow)
{
	ThrumNow->ThrumDire=StartThrumNow->ThrumDire;
	ThrumNow->ThrumDist=StartThrumNow->ThrumDist;
	ThrumNow->ThrumStart=StartThrumNow->ThrumStart;
	ThrumNow->ThrumEnd=StartThrumNow->ThrumEnd;
	ThrumNow->ThrumNormdis=StartThrumNow->ThrumNormdis;
}
////////////////////////////////////////////////////////////////////////
//	函 数 名 ：void ChangeSeqII(int SeqA,int SeqB)
//	函数功能 ：将线段A和线段B在曲线（线段集合）中的位置交换，并反转其方向
//	作    者 ：朱宗晓
//	时    间 ：2012年3月30日
//	返 回 值 ： 无
//	入口参数说明 ：
//	1.int SeqA线段A序号
//	1.int SeqB线段B序号
////////////////////////////////////////////////////////////////////////
//	历史记录：
//	编号     日期    	作者    备注
//	0	2012年3月30日	朱宗晓	创建本函数
//	////////////////////////////////////////////////////////////////////////
void ChangeSeqII(int SeqA,int SeqB)
{
	if(SeqA!= SeqB)
	{
	ThrumTemp.ThrumStart=ThrumGroup[SeqB].ThrumStart;
    ThrumGroup[SeqB].ThrumStart=ThrumGroup[SeqB].ThrumEnd;
	ThrumGroup[SeqB].ThrumEnd=ThrumTemp.ThrumStart;
	if(ThrumGroup[SeqB].ThrumDire<=32)
	{ThrumGroup[SeqB].ThrumDire+=32;}
	else
	{ThrumGroup[SeqB].ThrumDire-=32;}

	ThrumTemp.ThrumStart=ThrumGroup[SeqA].ThrumStart;
    ThrumGroup[SeqA].ThrumStart=ThrumGroup[SeqA].ThrumEnd;
	ThrumGroup[SeqA].ThrumEnd=ThrumTemp.ThrumStart;
	if(ThrumGroup[SeqA].ThrumDire<=32)
	{ThrumGroup[SeqA].ThrumDire+=32;}
	else
	{ThrumGroup[SeqA].ThrumDire-=32;}
	memcpy(&ThrumTemp,&ThrumGroup[SeqB],sizeof(ThrumInfo));
	memcpy(&ThrumGroup[SeqB],&ThrumGroup[SeqA],sizeof(ThrumInfo));
	memcpy(&ThrumGroup[SeqA],&ThrumTemp,sizeof(ThrumInfo));
	}
	else
	{
		ThrumTemp.ThrumStart=ThrumGroup[SeqB].ThrumStart;
		ThrumGroup[SeqB].ThrumStart=ThrumGroup[SeqB].ThrumEnd;
		ThrumGroup[SeqB].ThrumEnd=ThrumTemp.ThrumStart;
		if(ThrumGroup[SeqB].ThrumDire<=32)
		{ThrumGroup[SeqB].ThrumDire+=32;}
		else
		{ThrumGroup[SeqB].ThrumDire-=32;}
	}
}
////////////////////////////////////////////////////////////////////////
//	函 数 名 ：bool DPSG_ThrumCheck64D_NP(unsigned char* Img_bin,int nWidth,int nHeight, int cenX, int cenY, int R,int LastDire)
//	函数功能 ：判断指定点沿上轮线段方向2N+1邻域是否存在线段
//	作    者 ：朱宗晓
//	时    间 ：2012年03月30日
//	返 回 值 ： true：存在；false:不存在
//	入口参数说明 ：
//	1.IplImage * Img_bin：待计算的二值图
//  2.int nWidth：待计算的二值图数组宽度
//  3.int nHeight：待计算的二值图数组高度
//  4.int cenX：指定点横坐标
//  5.int cenY：指定点纵坐标
//	6.int R:采样半径
//  7.int LastDire：上轮线段方向

////////////////////////////////////////////////////////////////////////
//	历史记录：
//	编号     日期    	作者    备注
//	0	2012年03月30日	朱宗晓	创建本函数
//	////////////////////////////////////////////////////////////////////////
bool DPSGII_ThrumCheck64D_NP(unsigned char* Img_bin,int nWidth,int nHeight, int cenX, int cenY, int R,int Rout,int LastDire,int DirectionN)
{
	//ThrumTemp.ThrumDire=0;
	//ThrumTemp.ThrumDist=0.0;
	//ThrumTemp.ThrumStart.x=0;
	//ThrumTemp.ThrumStart.y=0;
	//ThrumTemp.ThrumEnd.x=0;
	//ThrumTemp.ThrumEnd.y=0;
	//memset(&ThrumTemp,0,sizeof(ThrumInfo));
	int i=0;
	int j=0;
	int MaxDirection=0;//最大方向
	int NormalDirection=0;//法线方向
	double MaxPDC=0.1;//最长方向贡献度
	double ThrumTest64[65] = {0.0};
	int NormOne=0;//法线方向1
	int NormTwo=0;//法线方向2
	double NormOneDis=0.0;
	double NormTwoDis=0.0;
	bool DirReigon=0;//方向范围标志
 	for(i=0;i<2*DirectionN+1;i++)
	{
		 
			ThrumTest64[CircleII[64+LastDire-DirectionN+i]]=DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,CircleII[64+LastDire-DirectionN+i]);
			if((ThrumTest64[CircleII[64+LastDire-DirectionN+i]]>MaxPDC))//&&(DPSG_DPAdnate8Check(Img_bin,nWidth,nHeight,cenX+g_oDistense64D[i].xstep*R,cenY+g_oDistense64D[i].ystep*R,R)==8))
			{
				MaxPDC=ThrumTest64[CircleII[64+LastDire-DirectionN+i]];
				MaxDirection=CircleII[64+LastDire-DirectionN+i];
			}
	//		Counterstr.Format("LastDire=%d: i=%d,",LastDire,i);
	//        InfoText->ReplaceSel(Counterstr);
	}
	//  InfoText->ReplaceSel("\n");//换行);

	if(MaxDirection!=0&&MaxPDC>(g_oDistense64D[MaxDirection].stepdistense*R-0.1))
	{
		//如果原方向还可以走一步，而如果新方向的长度小于原方向长度，按原方向行走
		

		if(MaxDirection-LastDire)//如果方向要改变
		{
			DirReigon=1;
			for(i=0;i<5;i++)
			{
				if(MaxDirection==CircleII[64+LastDire-2+i])//如果新方向落在原左右二邻域
				{	
					DirReigon=0;
					break;
				}
			}
			//int Ratio=int(ThrumTemp.ThrumNormdis/ThrumTest64[IICircle[64+LastDire]]+0.499999);
			double  Ratio=ThrumTest64[CircleII[64+LastDire]]/MaxPDC;//当法线比较宽时，不希望轻易的改变原来的方向
			if((DirReigon==1)&&(ThrumTest64[CircleII[64+LastDire]]>(g_oDistense64D[LastDire].stepdistense*R-0.1))&&(MaxPDC<1.5*ThrumTemp.ThrumNormdis))
			{
				MaxPDC=ThrumTest64[CircleII[64+LastDire]];
				MaxDirection=LastDire;
			}
			if(Ratio>0.75)
			{
				MaxPDC=ThrumTest64[CircleII[64+LastDire]];
				MaxDirection=LastDire;
			}
			
		}
		ThrumTemp.ThrumDire=MaxDirection;
		ThrumTemp.ThrumDist=g_oDistense64D[MaxDirection].stepdistense*R;
		ThrumTemp.ThrumStart.x=cenX;
		ThrumTemp.ThrumStart.y=cenY;
		ThrumTemp.ThrumEnd.x=cenX+g_oDistense64D[MaxDirection].xstep*R;
		ThrumTemp.ThrumEnd.y=cenY+g_oDistense64D[MaxDirection].ystep*R;
		NormOne=MaxDirection+16;//法线方向1
	    NormTwo=MaxDirection-16;//法线方向2
		if(NormOne>64)
		{NormOne-=64;}
		if(NormTwo<1)
		{NormTwo+=64;}
		NormOneDis=DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,ThrumTemp.ThrumEnd.x,ThrumTemp.ThrumEnd.y,R,Rout,NormOne);
		NormTwoDis=DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,ThrumTemp.ThrumEnd.x,ThrumTemp.ThrumEnd.y,R,Rout,NormTwo);
		ThrumTemp.ThrumNormdis=NormOneDis+NormTwoDis;
		if(ThrumTemp.ThrumNormdis<0.1)
		{
			NormOne=MaxDirection+15;//法线方向1
			NormTwo=MaxDirection-17;//法线方向2
			if(NormOne>64)
			{NormOne-=64;}
			if(NormTwo<1)
			{NormTwo+=64;}
			NormOneDis=DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,ThrumTemp.ThrumEnd.x,ThrumTemp.ThrumEnd.y,R,Rout,NormOne);
		    NormTwoDis=DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,ThrumTemp.ThrumEnd.x,ThrumTemp.ThrumEnd.y,R,Rout,NormTwo);
			ThrumTemp.ThrumNormdis=NormOneDis+NormTwoDis;
		}
		if(ThrumTemp.ThrumNormdis<0.1)
		{
			NormOne=MaxDirection+17;//法线方向1
			NormTwo=MaxDirection-15;//法线方向2
			if(NormOne>64)
			{NormOne-=64;}
			if(NormTwo<1)
			{NormTwo+=64;}
			NormOneDis=DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,ThrumTemp.ThrumEnd.x,ThrumTemp.ThrumEnd.y,R,Rout,NormOne);
		    NormTwoDis=DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,ThrumTemp.ThrumEnd.x,ThrumTemp.ThrumEnd.y,R,Rout,NormTwo);
			ThrumTemp.ThrumNormdis=NormOneDis+NormTwoDis;
		}
		if(ThrumTemp.ThrumNormdis<0.1)
		{
			NormOne=MaxDirection+18;//法线方向1
			NormTwo=MaxDirection-14;//法线方向2
			if(NormOne>64)
			{NormOne-=64;}
			if(NormTwo<1)
			{NormTwo+=64;}
			NormOneDis=DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,ThrumTemp.ThrumEnd.x,ThrumTemp.ThrumEnd.y,R,Rout,NormOne);
		    NormTwoDis=DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,ThrumTemp.ThrumEnd.x,ThrumTemp.ThrumEnd.y,R,Rout,NormTwo);
			ThrumTemp.ThrumNormdis=NormOneDis+NormTwoDis;
		}
		if(ThrumTemp.ThrumNormdis<0.1)
		{
			NormOne=MaxDirection+14;//法线方向1
			NormTwo=MaxDirection-18;//法线方向2
			if(NormOne>64)
			{NormOne-=64;}
			if(NormTwo<1)
			{NormTwo+=64;}
			NormOneDis=DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,ThrumTemp.ThrumEnd.x,ThrumTemp.ThrumEnd.y,R,Rout,NormOne);
		    NormTwoDis=DPSGII_DPDisR64D(Img_bin,nWidth,nHeight,ThrumTemp.ThrumEnd.x,ThrumTemp.ThrumEnd.y,R,Rout,NormTwo);
			ThrumTemp.ThrumNormdis=NormOneDis+NormTwoDis;
		}
		////修正起始点位置，使之更接近于法线中点
		/*if((NormOneDis-NormTwoDis)>2*g_oDistense64D[NormOne].stepdistense)
		{
			ThrumTemp.ThrumEnd.x=ThrumTemp.ThrumEnd.x+g_oDistense64D[NormOne].xstep;
			ThrumTemp.ThrumEnd.y=ThrumTemp.ThrumEnd.y+g_oDistense64D[NormOne].ystep;
		}
		else if((NormTwoDis-NormOneDis)>2*g_oDistense64D[NormTwo].stepdistense)
		{
			ThrumTemp.ThrumEnd.x=ThrumTemp.ThrumEnd.x+g_oDistense64D[NormTwo].xstep;
			ThrumTemp.ThrumEnd.y=ThrumTemp.ThrumEnd.y+g_oDistense64D[NormTwo].ystep;
		}*/
		/*if(ThrumTemp.ThrumDire==LastDire)
		{
			ThrumTemp.ThrumCurveSeq=ThrumNum-1;
		}
		else
		{
			ThrumTemp.ThrumCurveSeq=ThrumNum;
    	}*/
		//TRACE("TRUE_ThrumNum=%d:ThrumCurveSeq=%d,ThrumDist=%f，ThrumDire=%d,ThrumStart.x=%d,ThrumStart.y=%d,ThrumEnd.x=%d,ThrumEnd.y=%d\n",ThrumNum,ThrumTemp.ThrumCurveSeq,ThrumTemp.ThrumDist,ThrumTemp.ThrumDire,ThrumTemp.ThrumStart.x,ThrumTemp.ThrumStart.y,ThrumTemp.ThrumEnd.x,ThrumTemp.ThrumEnd.y);
		return true;
    }
	else
	{
		//TRACE("FALSE_ThrumNum=%d:ThrumCurveSeq=%d,ThrumDist=%f，ThrumDire=%d,ThrumStart.x=%d,ThrumStart.y=%d,ThrumEnd.x=%d,ThrumEnd.y=%d\n",ThrumNum,ThrumTemp.ThrumCurveSeq,ThrumTemp.ThrumDist,ThrumTemp.ThrumDire,ThrumTemp.ThrumStart.x,ThrumTemp.ThrumStart.y,ThrumTemp.ThrumEnd.x,ThrumTemp.ThrumEnd.y);
		return false;
	}
}
////////////////////////////////////////////////////////////////////////
//	函 数 名 ：void DPSGII_CopyImgArray(unsigned char* Img_dst,unsigned char* Img_src,int nWidth,int nHeight,int LeftSide, int RightSide, int UpSide,int DownSide,int DirectionN)
//	函数功能 ：将Img_src指定点区域拷贝到Img_dst中
//	作    者 ：朱宗晓
//	时    间 ：2012年3月30日
//	返 回 值 ：无
//	入口参数说明 ：
//  1.IplImage * Img_dst: 待拷贝目标图
//  2.IplImage * Img_src: 待拷贝原始图
//  3.int nWidth：待计算的灰度图数组宽度
//  4.int nHeight：待计算的灰度图数组高度
//  5.int LeftSide：区域左边界
//  6.int RightSide：区域右边界
//  7.int UpSide：区域上边界
//  8.int DownSide：区域下边界
////////////////////////////////////////////////////////////////////////
//	历史记录：
//	编号     日期    	作者    备注
//	0	2012年3月30日	朱宗晓	创建本函数
//	////////////////////////////////////////////////////////////////////////
void DPSGII_CopyImgArray(unsigned char* Img_dst,unsigned char* Img_src,unsigned short* Img_his,int nWidth,int nHeight,int LeftSide, int RightSide, int UpSide,int DownSide,int DirectionN, int HistoryLine)
{
	int x=0;
	int y=0;
	if(LeftSide>RightSide||DownSide<UpSide||LeftSide<0||UpSide<0||RightSide>(nWidth-1)||DownSide>(nHeight-1))
	{return;}
	for(y=UpSide;y<DownSide+1;y++)
	{
	   	for(x=LeftSide;x<RightSide+1;x++)
	   {
			((unsigned char *)(Img_dst+ nWidth*y))[x]=DirectionN;
			((unsigned short *)(Img_his+ nWidth*y))[x]=HistoryLine;

	   }
	}

}
////////////////////////////////////////////////////////////////////////
//	函 数 名 ：void DPSGII_CopyLineSegRegion(unsigned char* Img_dst,unsigned char* Img_src,int nWidth,int nHeight,int R,ThrumInfo* ThrumNow)
//	函数功能 ：将Img_src中探测到的线段邻域复制到Img_dst中
//	作    者 ：朱宗晓
//	时    间 ：2012年03月30日
//	返 回 值 ： 被修改了的Img_dst
//	入口参数说明 ：
//  1.IplImage * Img_dst: 待拷贝目标图
//  2.IplImage * Img_src: 待拷贝原始图
//  3.int nWidth：待计算的灰度图数组宽度
//  4.int nHeight：待计算的灰度图数组高度
//  5.ThrumInfo* ThrumNow：指定要复制的线段
////////////////////////////////////////////////////////////////////////
//	历史记录：
//	编号     日期    	作者    备注
//	0	2012年03月30日	朱宗晓	创建本函数
//	////////////////////////////////////////////////////////////////////////
void DPSGII_CopyLineSegRegion(unsigned char* Img_dst,unsigned char* Img_src,unsigned short* Img_his,int nWidth,int nHeight,int R,ThrumInfo* ThrumNow)
{
	int LeftSide=0;
	int RightSide=0;
	int UpSide=0;
	int DownSide=0;
	if(ThrumNow->ThrumStart.x>ThrumNow->ThrumEnd.x)
	{
		LeftSide=ThrumNow->ThrumEnd.x;
		RightSide=ThrumNow->ThrumStart.x+(R<<1);
		//RightSide=ThrumNow->ThrumStart.x+ThrumNow->ThrumNormdis;
	}
	else if(ThrumNow->ThrumStart.x<ThrumNow->ThrumEnd.x)
	{
		LeftSide=ThrumNow->ThrumStart.x-(R<<1);
        //LeftSide=ThrumNow->ThrumStart.x-ThrumNow->ThrumNormdis;
		RightSide=ThrumNow->ThrumEnd.x;
	}
	if(ThrumNow->ThrumStart.y>ThrumNow->ThrumEnd.y)
	{
		UpSide=ThrumNow->ThrumEnd.y;
		DownSide=ThrumNow->ThrumStart.y+(R<<1);
		//DownSide=ThrumNow->ThrumStart.y+ThrumNow->ThrumNormdis;
	}
	else if(ThrumNow->ThrumStart.y<ThrumNow->ThrumEnd.y)
	{
		UpSide=ThrumNow->ThrumStart.y-(R<<1);
		//UpSide=ThrumNow->ThrumStart.y-ThrumNow->ThrumNormdis;
		DownSide=ThrumNow->ThrumEnd.y;
	}
	if(ThrumNow->ThrumStart.x==ThrumNow->ThrumEnd.x)
	{
		LeftSide=ThrumNow->ThrumStart.x-(R<<1);
		RightSide=ThrumNow->ThrumStart.x+(R<<1);
		//LeftSide=ThrumNow->ThrumStart.x-ThrumNow->ThrumNormdis;
		//RightSide=ThrumNow->ThrumStart.x+ThrumNow->ThrumNormdis;
	}
	else if(ThrumNow->ThrumStart.y==ThrumNow->ThrumEnd.y)
	{
		UpSide=ThrumNow->ThrumStart.y-(R<<1);
		DownSide=ThrumNow->ThrumStart.y+(R<<1);
		//UpSide=ThrumNow->ThrumStart.y-ThrumNow->ThrumNormdis;
		//DownSide=ThrumNow->ThrumStart.y+ThrumNow->ThrumNormdis;
    }
	DPSGII_CopyImgArray(Img_dst,Img_src,Img_his,nWidth,nHeight,LeftSide,RightSide,UpSide,DownSide,ThrumNow->ThrumDire,ThrumNum-1);
}
////////////////////////////////////////////////////////////////////////
//	函 数 名 ：void DPSGII_SetRegionValue(unsigned char* Img_dst,int nWidth,int nHeight,int StartX,int StartY, int EndX, int EndY,int Value)
//	函数功能 ：将指定范围内的像素值置为Value
//	作    者 ：朱宗晓
//	时    间 ：2012年09月09日
//	返 回 值 ： 被修改了的Img_dst
//	入口参数说明 ：
//  1.IplImage * Img_dst: 待修改目标图
//  2.int nWidth：待计算的灰度图数组宽度
//  3.int nHeight：待计算的灰度图数组高度
//  4.int StartX：指定范围起始横坐标
//  5.int StartY：指定范围起始纵坐标
//  6.int EndX：指定范围结束横坐标
//  7.int EndY：指定范围结束纵坐标
//  8.int Value：将指定范围内的像素值置为Value
////////////////////////////////////////////////////////////////////////
//	历史记录：
//	编号     日期    	作者    备注
//	0	2012年09月09日	朱宗晓	创建本函数
//	////////////////////////////////////////////////////////////////////////
void DPSGII_SetRegionValue(unsigned char* Img_dst,int nWidth,int nHeight,int StartX,int StartY, int EndX, int EndY,int Value)
{
	int LeftSide=0;
	int RightSide=0;
	int UpSide=0;
	int DownSide=0;
	
	if(StartX<=EndX)
	{
		LeftSide=StartX;
		RightSide=EndX;
	}
	else 
	{
		LeftSide=EndX;        
		RightSide=StartX;
	}
	if(StartY<=EndY)
	{
		UpSide=StartY;
		DownSide=EndY;
	}
	else 
	{
		UpSide=EndY;
		DownSide=StartY;
	}
	int x=0;
	int y=0;
	for(y=UpSide;y<DownSide+1;y++)
	{
	/*	if(((unsigned char*)(Img_dst + nWidth*y))[x]==Value)
		{break;}*/
	   	for(x=LeftSide;x<RightSide+1;x++)
	   {
		   /*	if(((unsigned char*)(Img_dst + nWidth*y))[x]==Value)
			{break;}
			else*/
			{((unsigned char *)(Img_dst+ nWidth*y))[x]=Value;}
       }
	}

	
}
////////////////////////////////////////////////////////////////////////
//	函 数 名 ：void DPSGII_CurveSearch64D(unsigned char* Img_bin,unsigned char* Img_sign,int nWidth,int nHeight, StartThrumInfo * StartThrumNow,int R,int DirectionN,int NormThre,int CrossAngle)
//	函数功能 ：按指定线头探测曲线信息
//	作    者 ：朱宗晓
//	时    间 ：2012年03月31日
//	返 回 值 ：线段及曲线集合
//	入口参数说明 ：
//  1.IplImage * Img_bin: 待探测图
//  2.IplImage * Img_sign: 已探测区域标记图
//  3.int nWidth：待计算的灰度图数组宽度
//  4.int nHeight：待计算的灰度图数组高度
//  5.StartThrumInfo * StartThrumNow：指定线头结构体
//  6.int R：采样半径
//  7.int DirectionN：直线探测范围
//  8.int NormThre：法线阈值
//  9.int CrossAngle：两曲线交叉的最小角度
////////////////////////////////////////////////////////////////////////
//	历史记录：
//	编号     日期    	作者    备注
//	0	2012年03月31日	朱宗晓	创建本函数
//	////////////////////////////////////////////////////////////////////////
void DPSGII_CurveSearch64D(unsigned char* Img_bin,unsigned char* Img_sign,unsigned short* Img_his,int nWidth,int nHeight, FeaturePointInfo * StartThrumNow,int R,int Rout,int DirectionN,int NormThre,int CrossAngle,int MinCruve)
{
	int tempThrumStart=0;
	int tempThrumEnd=0;
	int j=0;
	int i=0;
	unsigned char HistorySign=0;
	unsigned short HistoryLine=0;
	

	int DirReigon=0;
	int LastDirOne=0;
	int LastDirTwo=0;
	int NextDirOne=0;
	int NextDirTwo=0;
	memset(&CurveGroup[CurveNum],0,sizeof(CurveInfo));
	tempThrumStart=ThrumNum;
	ThrumGroup[ThrumNum].ThrumDire=StartThrumNow->ThrumDire;//线段方向
	ThrumGroup[ThrumNum].ThrumStart=StartThrumNow->FeaturePointPos;//线段起始
	ThrumGroup[ThrumNum].ThrumEnd=StartThrumNow->FeaturePointPos;//线段结束
	ThrumGroup[ThrumNum].ThrumCurveSeq=CurveNum;//线段所属曲线号
    ThrumGroup[ThrumNum].ThrumHisDire=0.0;//线段历史长度
	ThrumGroup[ThrumNum].ThrumDist=0.0;//线段长度
	ThrumGroup[ThrumNum].ThrumNormdis=StartThrumNow->ThrumNormdis;//线段法线宽度
    ThrumTemp.ThrumNormdis=StartThrumNow->ThrumNormdis;//临时法线宽度
	CurveGroup[CurveNum].CurveStart=ThrumGroup[ThrumNum].ThrumStart;//曲线起始
	CurveGroup[CurveNum].CurveStartThrum=ThrumNum;//第CurveNum号曲线起始线段序号
	CurveGroup[CurveNum].CurveNormdis+=ThrumGroup[ThrumNum].ThrumNormdis;//法线宽度累加
	ThrumNum+=1;
	while(DPSGII_ThrumCheck64D_NP(Img_bin,nWidth,nHeight,ThrumGroup[ThrumNum-1].ThrumEnd.x, ThrumGroup[ThrumNum-1].ThrumEnd.y, R,Rout,ThrumGroup[ThrumNum-1].ThrumDire,DirectionN)&&ThrumNum<THRUMMAXNUM)
	{
		//////////////////////////////////////////////////////////////////////
		HistorySign=((unsigned char *)(Img_sign+ nWidth*ThrumTemp.ThrumEnd.y))[ThrumTemp.ThrumEnd.x];
		HistoryLine=((unsigned short *)(Img_his+ nWidth*ThrumTemp.ThrumEnd.y))[ThrumTemp.ThrumEnd.x];
		if(HistorySign==0)
		{break;}
        else if(HistorySign>=1&&HistorySign<=64)
		{
			DirReigon=2;
			for(j=-CrossAngle;j<=CrossAngle;j++)////两曲线交叉的最小角度*(P+312)*5.625,小于这个角度则不能交叉
			{
				if((ThrumTemp.ThrumDire==CircleII[j+64+HistorySign])||(ThrumTemp.ThrumDire==CircleII[j+96+HistorySign])||(ThrumTemp.ThrumDire==CircleII[32+HistorySign]))
			    {
					DirReigon=1;
					break;
				}
			}
			i=0;
			while(CurveGroup[CurveNum].CrossCruve[i][0]!=0)
			{
				i++;
				if(i>4)
				{
					i=0;
					break;
				}
			}
			if(i==0||CurveGroup[CurveNum].CrossCruve[i-1][0]!=HistoryLine)
			{
				CurveGroup[CurveNum].CrossCruve[i][0]=HistoryLine;
				CurveGroup[CurveNum].CrossCruve[i][1]=DirReigon;
				CurveGroup[CurveNum].CrossCruve[i][2]=ThrumTemp.ThrumEnd.x;
				CurveGroup[CurveNum].CrossCruve[i][3]=ThrumTemp.ThrumEnd.y;
				if(ThrumGroup[ThrumNum-1].ThrumDire==ThrumTemp.ThrumDire)
				{CurveGroup[CurveNum].CrossCruve[i][4]=ThrumNum-1;}
				else
				{CurveGroup[CurveNum].CrossCruve[i][4]=ThrumNum;}
			}
			else if((CurveGroup[CurveNum].CrossCruve[i-1][0]==HistoryLine)&&(ThrumNum-CurveGroup[CurveNum].CrossCruve[i][4]<=2))
			{
			
				CurveGroup[CurveNum].CrossCruve[i-1][0]=HistoryLine;
				CurveGroup[CurveNum].CrossCruve[i-1][1]=DirReigon;
				CurveGroup[CurveNum].CrossCruve[i-1][2]=ThrumTemp.ThrumEnd.x;
				CurveGroup[CurveNum].CrossCruve[i-1][3]=ThrumTemp.ThrumEnd.y;
				if(ThrumGroup[ThrumNum-1].ThrumDire==ThrumTemp.ThrumDire)
				{CurveGroup[CurveNum].CrossCruve[i-1][4]=ThrumNum-1;}
				else
				{
					CurveGroup[CurveNum].CrossCruve[i-1][4]=ThrumNum;
				}
			}
			/*if(ThrumGroup[HistoryLine].ThrumCurveSeq!=0xffff)
			{
				i=0;
				while(CurveGroup[ThrumGroup[HistoryLine].ThrumCurveSeq].CrossCruve[i][0]!=0)
				{
					i++;
					if(i>4)
					{
						i=0;
						break;
					}
				}
				CurveGroup[ThrumGroup[HistoryLine].ThrumCurveSeq].CrossCruve[i][0]=ThrumTemp.ThrumCurveSeq;
				CurveGroup[ThrumGroup[HistoryLine].ThrumCurveSeq].CrossCruve[i][1]=DirReigon;
				CurveGroup[ThrumGroup[HistoryLine].ThrumCurveSeq].CrossCruve[i][2]=ThrumTemp.ThrumEnd.x;
				CurveGroup[ThrumGroup[HistoryLine].ThrumCurveSeq].CrossCruve[i][3]=ThrumTemp.ThrumEnd.y;
				CurveGroup[ThrumGroup[HistoryLine].ThrumCurveSeq].CrossCruve[i][4]=HistoryLine;
			}*/
			if(DirReigon==1)
			{
				break;
			}
		}
			
		
		
/////////////////////////////////////////////////////////////////////
		
		if(ThrumGroup[ThrumNum-1].ThrumDire==ThrumTemp.ThrumDire)//先后两步方向相同
		{
		    ThrumGroup[ThrumNum-1].ThrumEnd=ThrumTemp.ThrumEnd;
			ThrumGroup[ThrumNum-1].ThrumDist+=ThrumTemp.ThrumDist;
			CurveGroup[CurveNum].CurveDist[0]+=ThrumTemp.ThrumDist;
			ThrumGroup[ThrumNum-1].ThrumHisDire=CurveGroup[CurveNum].CurveDist[0];
			ThrumGroup[ThrumNum-1].ThrumNormdis=ThrumTemp.ThrumNormdis;
			if(ThrumTemp.ThrumDire<=32)
			{CurveGroup[CurveNum].CurveDist[ThrumTemp.ThrumDire+32]+=ThrumTemp.ThrumDist;}
			else
			{CurveGroup[CurveNum].CurveDist[ThrumTemp.ThrumDire-32]+=ThrumTemp.ThrumDist;}
			
		}
		else//先后两步方向不相同
		{
		    ThrumGroup[ThrumNum].ThrumDire=ThrumTemp.ThrumDire;
		    ThrumGroup[ThrumNum].ThrumDist=ThrumTemp.ThrumDist;
		    ThrumGroup[ThrumNum].ThrumStart=ThrumTemp.ThrumStart;
		    ThrumGroup[ThrumNum].ThrumEnd=ThrumTemp.ThrumEnd;
			ThrumGroup[ThrumNum].ThrumCurveSeq=CurveNum;
			ThrumGroup[ThrumNum].ThrumNormdis=ThrumTemp.ThrumNormdis;
			CurveGroup[CurveNum].CurveDist[0]+=ThrumGroup[ThrumNum].ThrumDist;
			ThrumGroup[ThrumNum].ThrumHisDire=CurveGroup[CurveNum].CurveDist[0];
			CurveGroup[CurveNum].CurveDist[ThrumTemp.ThrumDire]+=ThrumGroup[ThrumNum].ThrumDist;
			if(ThrumTemp.ThrumNormdis<NormThre)//当前法线宽度小于设定阈值
			{CurveGroup[CurveNum].CurveNormdis+=ThrumGroup[ThrumNum].ThrumNormdis;}
			else
			{CurveGroup[CurveNum].CurveNormdis+=ThrumGroup[ThrumNum-1].ThrumNormdis;}
			ThrumNum+=1;

	     }
		if((ThrumTemp.ThrumStart.x!=StartThrumNow->FeaturePointPos.x)||(ThrumTemp.ThrumStart.y!=StartThrumNow->FeaturePointPos.y))//起始点不标记,以免反向时误以为属于已标记区域
		{
			//TRACE("ThrumNum=%d:ThrumCurveSeq=%d,ThrumDire=%d,ThrumStart.x=%d,ThrumStart.y=%d,ThrumEnd.x=%d,ThrumEnd.y=%d\n",ThrumNum,ThrumTemp.ThrumCurveSeq,ThrumTemp.ThrumDire,ThrumTemp.ThrumStart.x,ThrumTemp.ThrumStart.y,ThrumTemp.ThrumEnd.x,ThrumTemp.ThrumEnd.y);
			DPSGII_CopyLineSegRegion(Img_sign,Img_bin,Img_his,nWidth,nHeight,R,&ThrumTemp);
		}

	
		
	}
	CurveGroup[CurveNum].CurveStartThrum=tempThrumStart;
    CurveGroup[CurveNum].CurveStart=ThrumGroup[ThrumNum-1].ThrumEnd;
	tempThrumEnd=ThrumNum-1;
	if(tempThrumEnd==tempThrumStart)
	{
		ThrumTemp.ThrumStart=ThrumGroup[tempThrumStart].ThrumStart;
		ThrumGroup[tempThrumStart].ThrumStart=ThrumGroup[tempThrumStart].ThrumEnd;
		ThrumGroup[tempThrumStart].ThrumEnd=ThrumTemp.ThrumStart;
		if(ThrumGroup[tempThrumStart].ThrumDire<=32)
		{ThrumGroup[tempThrumStart].ThrumDire+=32;}
		else
		{ThrumGroup[tempThrumStart].ThrumDire-=32;}
	}
	else
	{
		for(j=0;j<=((tempThrumEnd-tempThrumStart)>>1);j++)
		{
		   ChangeSeqII(tempThrumStart+j,tempThrumEnd-j);
		}
	}
	while(DPSGII_ThrumCheck64D_NP(Img_bin,nWidth,nHeight,ThrumGroup[ThrumNum-1].ThrumEnd.x, ThrumGroup[ThrumNum-1].ThrumEnd.y, R,Rout,ThrumGroup[ThrumNum-1].ThrumDire,DirectionN)&&ThrumNum<THRUMMAXNUM)
	{
	//////////////////////////////////////////////////////////////////////
		HistorySign=((unsigned char *)(Img_sign+ nWidth*ThrumTemp.ThrumEnd.y))[ThrumTemp.ThrumEnd.x];
		HistoryLine=((unsigned short *)(Img_his+ nWidth*ThrumTemp.ThrumEnd.y))[ThrumTemp.ThrumEnd.x];
		if(HistorySign==0)
		{break;}
        else if((HistorySign>=1&&HistorySign<=64)&&(ThrumNum>tempThrumEnd+1))
		{
			DirReigon=2;
			for(j=-CrossAngle;j<=CrossAngle;j++)////两曲线交叉的最小角度*(P+312)*5.625,小于这个角度则不能交叉
			{
				if((ThrumTemp.ThrumDire==CircleII[j+64+HistorySign])||(ThrumTemp.ThrumDire==CircleII[j+96+HistorySign])||(ThrumTemp.ThrumDire==CircleII[32+HistorySign]))
			    {
					DirReigon=1;
					break;
				}
			}
			i=0;
			while(CurveGroup[CurveNum].CrossCruve[i][0]!=0)
			{
				i++;
				if(i>4)
				{
					i=0;
					break;
				}
			}
			if(i==0||CurveGroup[CurveNum].CrossCruve[i-1][0]!=HistoryLine)
			{
				CurveGroup[CurveNum].CrossCruve[i][0]=HistoryLine;
				CurveGroup[CurveNum].CrossCruve[i][1]=DirReigon;
				CurveGroup[CurveNum].CrossCruve[i][2]=ThrumTemp.ThrumEnd.x;
				CurveGroup[CurveNum].CrossCruve[i][3]=ThrumTemp.ThrumEnd.y;
				if(ThrumGroup[ThrumNum-1].ThrumDire==ThrumTemp.ThrumDire)
				{CurveGroup[CurveNum].CrossCruve[i][4]=ThrumNum-1;}
				else
				{CurveGroup[CurveNum].CrossCruve[i][4]=ThrumNum;}
			}
			else if((CurveGroup[CurveNum].CrossCruve[i-1][0]==HistoryLine)&&(ThrumNum-CurveGroup[CurveNum].CrossCruve[i][4]<=2))
			{
			
				CurveGroup[CurveNum].CrossCruve[i-1][0]=HistoryLine;
				CurveGroup[CurveNum].CrossCruve[i-1][1]=DirReigon;
				CurveGroup[CurveNum].CrossCruve[i-1][2]=ThrumTemp.ThrumEnd.x;
				CurveGroup[CurveNum].CrossCruve[i-1][3]=ThrumTemp.ThrumEnd.y;
				if(ThrumGroup[ThrumNum-1].ThrumDire==ThrumTemp.ThrumDire)
				{CurveGroup[CurveNum].CrossCruve[i-1][4]=ThrumNum-1;}
				else
				{
					CurveGroup[CurveNum].CrossCruve[i-1][4]=ThrumNum;
				}
			}
	/*		if(ThrumGroup[HistoryLine].ThrumCurveSeq!=0xffff)
			{
				j=0;
				while(CurveGroup[ThrumGroup[HistoryLine].ThrumCurveSeq].CrossCruve[j][0]!=0)
				{
					j++;
					if(j>4)
					{
						j=0;
						break;
					}
				}
				CurveGroup[ThrumGroup[HistoryLine].ThrumCurveSeq].CrossCruve[j][0]=ThrumTemp.ThrumCurveSeq;
				CurveGroup[ThrumGroup[HistoryLine].ThrumCurveSeq].CrossCruve[j][1]=DirReigon;
				CurveGroup[ThrumGroup[HistoryLine].ThrumCurveSeq].CrossCruve[j][2]=ThrumTemp.ThrumEnd.x;
				CurveGroup[ThrumGroup[HistoryLine].ThrumCurveSeq].CrossCruve[j][3]=ThrumTemp.ThrumEnd.y;
				CurveGroup[ThrumGroup[HistoryLine].ThrumCurveSeq].CrossCruve[j][4]=HistoryLine;
			}*/
			if(DirReigon==1)
			{
				break;
			}
		}
/////////////////////////////////////////////////////////////////////
		if(ThrumGroup[ThrumNum-1].ThrumDire==ThrumTemp.ThrumDire)
		{
		    ThrumGroup[ThrumNum-1].ThrumEnd=ThrumTemp.ThrumEnd;
			ThrumGroup[ThrumNum-1].ThrumDist+=ThrumTemp.ThrumDist;
			CurveGroup[CurveNum].CurveDist[0]+=ThrumTemp.ThrumDist;
			ThrumGroup[ThrumNum-1].ThrumHisDire=CurveGroup[CurveNum].CurveDist[0];
			ThrumGroup[ThrumNum-1].ThrumNormdis=ThrumTemp.ThrumNormdis;
			CurveGroup[CurveNum].CurveDist[ThrumTemp.ThrumDire]+=ThrumTemp.ThrumDist;
		}
	    else
		{
		    ThrumGroup[ThrumNum].ThrumDire=ThrumTemp.ThrumDire;
		    ThrumGroup[ThrumNum].ThrumDist=ThrumTemp.ThrumDist;
		    ThrumGroup[ThrumNum].ThrumStart=ThrumTemp.ThrumStart;
		    ThrumGroup[ThrumNum].ThrumEnd=ThrumTemp.ThrumEnd;
			ThrumGroup[ThrumNum].ThrumCurveSeq=CurveNum;
			ThrumGroup[ThrumNum].ThrumNormdis=ThrumTemp.ThrumNormdis;
		   	CurveGroup[CurveNum].CurveDist[0]+=ThrumTemp.ThrumDist;
			CurveGroup[CurveNum].CurveDist[ThrumTemp.ThrumDire]+=ThrumTemp.ThrumDist;
			ThrumGroup[ThrumNum].ThrumHisDire=CurveGroup[CurveNum].CurveDist[0];
			if(ThrumTemp.ThrumNormdis<NormThre)
			{CurveGroup[CurveNum].CurveNormdis+=ThrumTemp.ThrumNormdis;}
			else
			{CurveGroup[CurveNum].CurveNormdis+=ThrumGroup[ThrumNum-1].ThrumNormdis;}
			ThrumNum+=1;
		}
		DPSGII_CopyLineSegRegion(Img_sign,Img_bin,Img_his,nWidth,nHeight,R,&ThrumTemp);

		
	 }
	  CurveGroup[CurveNum].CurveEndThrum=ThrumNum-1;
	  CurveGroup[CurveNum].CurveEnd=ThrumGroup[ThrumNum-1].ThrumEnd;
	  if(CurveGroup[CurveNum].CurveDist[0]>MinCruve)
	  { 
      /*曲线类型判断*/
		  CurveGroup[CurveNum].CurveChange=0;
		  CurveGroup[CurveNum].Curvetype=0;
		  CGPOINT Cstart;//曲线起始点
		  CGPOINT Cend;//曲线结束点
		  CGPOINT CTemp;//临时点
		  CGPOINT CBack;//临时点
		  CGPOINT CMAX;
		  CGPOINT *CCurve;
		  int CPointNum=CurveGroup[CurveNum].CurveEndThrum-CurveGroup[CurveNum].CurveStartThrum+2;
		  double StoELength=0.0;
		  double Maxdis=0.0;
		  double Tempdis=0.0;
		  double Circlerate=0.0;
		  int HalfSeq=0;
		  LINESEG StoE;
		  double PolygonArea=0.0;
		  CCurve =new CGPOINT[CPointNum];//取得多边形
		  double MaxCirclerate=0.0;
			CGPOINT BestCenter;
			double BestR=0.0;
			CGPOINT BestPartCenter;
			double BestPartR=0.0;
			int PointInCircle=0;
			int MaxPointInCircle=0;
		  if(CPointNum==2)
		  {
			  CurveGroup[CurveNum].Curvetype=1;//直线
			  ThrumGroup[CurveGroup[CurveNum].CurveStartThrum].ThrumWeight=1.0;
			  goto END;
		  }
			
			CCurve[0].x=CurveGroup[CurveNum].CurveStart.x;
			CCurve[0].y=CurveGroup[CurveNum].CurveStart.y;
			CCurve[CPointNum-1].x=CurveGroup[CurveNum].CurveEnd.x;
			CCurve[CPointNum-1].y=CurveGroup[CurveNum].CurveEnd.y;
			StoE.e=CCurve[0];
			StoE.s= CCurve[CPointNum-1];
			Maxdis=0.0;
			for(i=1;i<CPointNum-1;i++)
			{
				CCurve[i].x=ThrumGroup[CurveGroup[CurveNum].CurveStartThrum+i].ThrumStart.x;
				CCurve[i].y=ThrumGroup[CurveGroup[CurveNum].CurveStartThrum+i].ThrumStart.y;
				ThrumGroup[CurveGroup[CurveNum].CurveStartThrum+i-1].ThrumWeight=ThrumGroup[CurveGroup[CurveNum].CurveStartThrum+i-1].ThrumDist/CurveGroup[CurveNum].CurveDist[0];
				Tempdis=ptolinesegdist(CCurve[i],StoE,CBack);
				if(Tempdis>Maxdis)
				{
					Maxdis=Tempdis;
					CMAX=CTemp;
					}
			}
			ThrumGroup[CurveGroup[CurveNum].CurveEndThrum].ThrumWeight=ThrumGroup[CurveGroup[CurveNum].CurveEndThrum].ThrumDist/CurveGroup[CurveNum].CurveDist[0];
			if(Maxdis*30<CurveGroup[CurveNum].CurveDist[0])//最大夹角atan(0.2)=11.3度
			{
				CurveGroup[CurveNum].Curvetype=1;//直线
					goto END;
			}
			if(dist(CCurve[0],CCurve[CPointNum-1])*10<CurveGroup[CurveNum].CurveDist[0])
			{
					CurveGroup[CurveNum].Curvetype=8;//整体封闭轮廓
					goto END;
				}
			for(i=0;i<5;i++)
			{
				if(ThrumGroup[CurveGroup[CurveNum].CrossCruve[i][0]].ThrumCurveSeq==CurveNum&&CurveGroup[CurveNum].CrossCruve[i][1]!=0)
				{
					CurveGroup[CurveNum].Curvetype=9;//局部封闭轮廓
					goto END;
				}
			}
			double MacLineSeg[3][2]={0};
			for(i=1;i<65;i++)
			{
				CurveGroup[CurveNum].CurveDist[i]=CurveGroup[CurveNum].CurveDist[i]/CurveGroup[CurveNum].CurveDist[0];
				if(CurveGroup[CurveNum].CurveDist[i]>MacLineSeg[0][1])
				{
						MacLineSeg[2][1]=MacLineSeg[1][1];
						MacLineSeg[2][0]=MacLineSeg[1][0];
						MacLineSeg[1][1]=MacLineSeg[0][1];
						MacLineSeg[1][0]=MacLineSeg[0][0];
						MacLineSeg[0][1]=CurveGroup[CurveNum].CurveDist[i];
						MacLineSeg[0][0]=i;
				}
				else if(CurveGroup[CurveNum].CurveDist[i]>MacLineSeg[1][1])
				{
					MacLineSeg[2][1]=MacLineSeg[1][1];
					MacLineSeg[2][0]=MacLineSeg[1][0];
					MacLineSeg[1][1]=CurveGroup[CurveNum].CurveDist[i];
					MacLineSeg[1][0]=i;
				}
				else if(CurveGroup[CurveNum].CurveDist[i]>MacLineSeg[2][1])
				{
					MacLineSeg[2][1]=CurveGroup[CurveNum].CurveDist[i];
					MacLineSeg[2][0]=i;
				}
     		}
			//TRACE("曲线%d第一方向%f,长度%f，第二方向%f,长度%f,第三方向%f,长度%f,",CurveNum,MacLineSeg[0][0],MacLineSeg[0][1],MacLineSeg[1][0],MacLineSeg[1][1],MacLineSeg[2][0],MacLineSeg[2][1]);
			
			if(MacLineSeg[0][1]+MacLineSeg[1][1]+MacLineSeg[2][1]>0.75)
			{
				if(CurveGroup[CurveNum].CurveDist[0]<COLINEDIS)
				{
					CurveGroup[CurveNum].Curvetype=1;//直线
					goto END;
				}
				else if(MacLineSeg[2][1]>0.1)//||MacLineSeg[2][1]*CurveGroup[CurveNum].CurveDist[0]>20)//比重小或是绝对长度大于20
				{
					CurveGroup[CurveNum].Curvetype=3;//3折线
					goto END;
				}
				else if(MacLineSeg[1][1]>0.2)
				{
					CurveGroup[CurveNum].Curvetype=2;//2折线
					goto END;
				}
				else
				{
					CurveGroup[CurveNum].Curvetype=1;//直线
					goto END;

				}
			}
			for(i=1;i<33;i++)
			{
				CurveGroup[CurveNum].CurveDire=i*(CurveGroup[CurveNum].CurveDist[i]+CurveGroup[CurveNum].CurveDist[i+32]);
			}
			if(CPointNum>10)//可能是圆
			{
				//先进行整体圆弧判断
				for(i=3;i<CPointNum-3;i++)
				{
					cocircle(CCurve[i-2],CCurve[i],CCurve[i+2],CBack,Tempdis);
					if(CBack.x-Tempdis>0&&CBack.x+Tempdis<nWidth&&CBack.y-Tempdis>0&&CBack.y+Tempdis<nHeight)//找图内圆弧
					{
						Circlerate=CGpolygon_on_circle(CBack,Tempdis,CPointNum,CCurve,&PointInCircle);
						if(Circlerate>MaxCirclerate)
						{
							MaxCirclerate=Circlerate;
							BestCenter=CBack;
			                BestR=Tempdis;
						}
						if(PointInCircle>MaxPointInCircle)
						{
							MaxPointInCircle=PointInCircle;
							BestPartCenter=CBack;
			                BestPartR=Tempdis;

						}
					}
				}
				//TRACE("曲线%d最大类圆性%f,最多连续在圆上的点个数%d\n",CurveNum,MaxCirclerate,MaxPointInCircle);
				if(MaxCirclerate>EPCIRCLE)
				{
					CurveGroup[CurveNum].Curvetype=6;//圆弧
					for(i=0;i<CIRCLENUM;i++) 
					{
						if(CircleGroup[i][0]==0)
						{
							CircleGroup[i][0]=CurveNum;
							CircleGroup[i][1]=BestR;
							CircleGroup[i][2]=BestCenter.x;
							CircleGroup[i][3]=BestCenter.y;
							break;
						}
					}
					goto END;
				}
				if(MaxPointInCircle>PARTCIRCLE )
				{
					CurveGroup[CurveNum].Curvetype=7;//局部圆弧
					for(i=0;i<CIRCLENUM;i++) 
					{
						if(CircleGroup[i][0]==0)
						{
							CircleGroup[i][0]=CurveNum;
							CircleGroup[i][1]=BestR;
							CircleGroup[i][2]=BestCenter.x;
							CircleGroup[i][3]=BestCenter.y;
							break;
						}
					}
					goto END;
				}
			}
				


		  
		  
END:	  delete CCurve;
		  
          CurveGroup[CurveNum].CurveNormdis=CurveGroup[CurveNum].CurveNormdis/(CurveGroup[CurveNum].CurveEndThrum-CurveGroup[CurveNum].CurveStartThrum+1);
		  for(i=0;i<MAXCURVENUM;i++)//前十个最长曲线记录
		  {
			  if(CurveGroup[CurveNum].CurveDist[0]>MaxCurveGroup[i][1])
			  {
			
				  MaxCurveGroup[i][1]=CurveGroup[CurveNum].CurveDist[0];
				  MaxCurveGroup[i][0]=CurveNum;
				  break;
			  }
		  }
	 }
	  
}
void DPSGII_CurveSearch64D(unsigned char* Img_bin,unsigned char* Img_sign,unsigned short* Img_his,int nWidth,int nHeight, StartThrumInfo * StartThrumNow,int R,int Rout,int DirectionN,int NormThre,int CrossAngle,int MinCruve)
{
	int tempThrumStart=0;
	int tempThrumEnd=0;
	int j=0;
	int i=0;
	unsigned char HistorySign=0;
	unsigned short HistoryLine=0;
	

	int DirReigon=0;
	int LastDirOne=0;
	int LastDirTwo=0;
	int NextDirOne=0;
	int NextDirTwo=0;
	memset(&CurveGroup[CurveNum],0,sizeof(CurveInfo));
	tempThrumStart=ThrumNum;
	ThrumGroup[ThrumNum].ThrumDire=StartThrumNow->ThrumDire;//线段方向
	ThrumGroup[ThrumNum].ThrumStart=StartThrumNow->ThrumSource;//线段起始
	ThrumGroup[ThrumNum].ThrumEnd=StartThrumNow->ThrumSource;//线段结束
	ThrumGroup[ThrumNum].ThrumCurveSeq=CurveNum;//线段所属曲线号
    ThrumGroup[ThrumNum].ThrumHisDire=0.0;//线段历史长度
	ThrumGroup[ThrumNum].ThrumDist=0.0;//线段长度
	ThrumGroup[ThrumNum].ThrumNormdis=StartThrumNow->ThrumNormdis;//线段法线宽度
    ThrumTemp.ThrumNormdis=StartThrumNow->ThrumNormdis;//临时法线宽度
	CurveGroup[CurveNum].CurveStart=ThrumGroup[ThrumNum].ThrumStart;//曲线起始
	CurveGroup[CurveNum].CurveStartThrum=ThrumNum;//第CurveNum号曲线起始线段序号
	CurveGroup[CurveNum].CurveNormdis+=ThrumGroup[ThrumNum].ThrumNormdis;//法线宽度累加
	ThrumNum+=1;
	while(DPSGII_ThrumCheck64D_NP(Img_bin,nWidth,nHeight,ThrumGroup[ThrumNum-1].ThrumEnd.x, ThrumGroup[ThrumNum-1].ThrumEnd.y, R,Rout,ThrumGroup[ThrumNum-1].ThrumDire,DirectionN)&&ThrumNum<THRUMMAXNUM)
	{
		//////////////////////////////////////////////////////////////////////
		HistorySign=((unsigned char *)(Img_sign+ nWidth*ThrumTemp.ThrumEnd.y))[ThrumTemp.ThrumEnd.x];
		HistoryLine=((unsigned short *)(Img_his+ nWidth*ThrumTemp.ThrumEnd.y))[ThrumTemp.ThrumEnd.x];
		if(HistorySign!=255)
		{
			DirReigon=2;
			for(j=-CrossAngle;j<=CrossAngle;j++)////两曲线交叉的最小角度*(P+312)*5.625,小于这个角度则不能交叉
			{
				if((ThrumTemp.ThrumDire==CircleII[j+64+HistorySign])||(ThrumTemp.ThrumDire==CircleII[j+96+HistorySign])||(ThrumTemp.ThrumDire==CircleII[32+HistorySign]))
			    {
					DirReigon=1;
					break;
				}
			}
			i=0;
			while(CurveGroup[CurveNum].CrossCruve[i][0]!=0)
			{
				i++;
				if(i>4)
				{
					i=0;
					break;
				}
			}
			if(i==0||CurveGroup[CurveNum].CrossCruve[i-1][0]!=HistoryLine)
			{
				CurveGroup[CurveNum].CrossCruve[i][0]=HistoryLine;
				CurveGroup[CurveNum].CrossCruve[i][1]=DirReigon;
				CurveGroup[CurveNum].CrossCruve[i][2]=ThrumTemp.ThrumEnd.x;
				CurveGroup[CurveNum].CrossCruve[i][3]=ThrumTemp.ThrumEnd.y;
				if(ThrumGroup[ThrumNum-1].ThrumDire==ThrumTemp.ThrumDire)
				{CurveGroup[CurveNum].CrossCruve[i][4]=ThrumNum-1;}
				else
				{CurveGroup[CurveNum].CrossCruve[i][4]=ThrumNum;}
			}
			else if((CurveGroup[CurveNum].CrossCruve[i-1][0]==HistoryLine)&&(ThrumNum-CurveGroup[CurveNum].CrossCruve[i][4]<=2))
			{
			
				CurveGroup[CurveNum].CrossCruve[i-1][0]=HistoryLine;
				CurveGroup[CurveNum].CrossCruve[i-1][1]=DirReigon;
				CurveGroup[CurveNum].CrossCruve[i-1][2]=ThrumTemp.ThrumEnd.x;
				CurveGroup[CurveNum].CrossCruve[i-1][3]=ThrumTemp.ThrumEnd.y;
				if(ThrumGroup[ThrumNum-1].ThrumDire==ThrumTemp.ThrumDire)
				{CurveGroup[CurveNum].CrossCruve[i-1][4]=ThrumNum-1;}
				else
				{
					CurveGroup[CurveNum].CrossCruve[i-1][4]=ThrumNum;
				}
			}
			/*if(ThrumGroup[HistoryLine].ThrumCurveSeq!=0xffff)
			{
				i=0;
				while(CurveGroup[ThrumGroup[HistoryLine].ThrumCurveSeq].CrossCruve[i][0]!=0)
				{
					i++;
					if(i>4)
					{
						i=0;
						break;
					}
				}
				CurveGroup[ThrumGroup[HistoryLine].ThrumCurveSeq].CrossCruve[i][0]=ThrumTemp.ThrumCurveSeq;
				CurveGroup[ThrumGroup[HistoryLine].ThrumCurveSeq].CrossCruve[i][1]=DirReigon;
				CurveGroup[ThrumGroup[HistoryLine].ThrumCurveSeq].CrossCruve[i][2]=ThrumTemp.ThrumEnd.x;
				CurveGroup[ThrumGroup[HistoryLine].ThrumCurveSeq].CrossCruve[i][3]=ThrumTemp.ThrumEnd.y;
				CurveGroup[ThrumGroup[HistoryLine].ThrumCurveSeq].CrossCruve[i][4]=HistoryLine;
			}*/
			if(DirReigon==1)
			{
				break;
			}
		}
			
		
		
/////////////////////////////////////////////////////////////////////
		
		if(ThrumGroup[ThrumNum-1].ThrumDire==ThrumTemp.ThrumDire)//先后两步方向相同
		{
		    ThrumGroup[ThrumNum-1].ThrumEnd=ThrumTemp.ThrumEnd;
			ThrumGroup[ThrumNum-1].ThrumDist+=ThrumTemp.ThrumDist;
			CurveGroup[CurveNum].CurveDist[0]+=ThrumTemp.ThrumDist;
			ThrumGroup[ThrumNum-1].ThrumHisDire=CurveGroup[CurveNum].CurveDist[0];
			ThrumGroup[ThrumNum-1].ThrumNormdis=ThrumTemp.ThrumNormdis;
			if(ThrumTemp.ThrumDire<=32)
			{CurveGroup[CurveNum].CurveDist[ThrumTemp.ThrumDire+32]+=ThrumTemp.ThrumDist;}
			else
			{CurveGroup[CurveNum].CurveDist[ThrumTemp.ThrumDire-32]+=ThrumTemp.ThrumDist;}
			
		}
		else//先后两步方向不相同
		{
		    ThrumGroup[ThrumNum].ThrumDire=ThrumTemp.ThrumDire;
		    ThrumGroup[ThrumNum].ThrumDist=ThrumTemp.ThrumDist;
		    ThrumGroup[ThrumNum].ThrumStart=ThrumTemp.ThrumStart;
		    ThrumGroup[ThrumNum].ThrumEnd=ThrumTemp.ThrumEnd;
			ThrumGroup[ThrumNum].ThrumCurveSeq=CurveNum;
			ThrumGroup[ThrumNum].ThrumNormdis=ThrumTemp.ThrumNormdis;
			CurveGroup[CurveNum].CurveDist[0]+=ThrumGroup[ThrumNum].ThrumDist;
			ThrumGroup[ThrumNum].ThrumHisDire=CurveGroup[CurveNum].CurveDist[0];
			CurveGroup[CurveNum].CurveDist[ThrumTemp.ThrumDire]+=ThrumGroup[ThrumNum].ThrumDist;
			if(ThrumTemp.ThrumNormdis<NormThre)//当前法线宽度小于设定阈值
			{CurveGroup[CurveNum].CurveNormdis+=ThrumGroup[ThrumNum].ThrumNormdis;}
			else
			{CurveGroup[CurveNum].CurveNormdis+=ThrumGroup[ThrumNum-1].ThrumNormdis;}
			ThrumNum+=1;

	     }
		if((ThrumTemp.ThrumStart.x!=StartThrumNow->ThrumSource.x)||(ThrumTemp.ThrumStart.y!=StartThrumNow->ThrumSource.y))//起始点不标记,以免反向时误以为属于已标记区域
		{
			//TRACE("ThrumNum=%d:ThrumCurveSeq=%d,ThrumDire=%d,ThrumStart.x=%d,ThrumStart.y=%d,ThrumEnd.x=%d,ThrumEnd.y=%d\n",ThrumNum,ThrumTemp.ThrumCurveSeq,ThrumTemp.ThrumDire,ThrumTemp.ThrumStart.x,ThrumTemp.ThrumStart.y,ThrumTemp.ThrumEnd.x,ThrumTemp.ThrumEnd.y);
			DPSGII_CopyLineSegRegion(Img_sign,Img_bin,Img_his,nWidth,nHeight,R,&ThrumTemp);
		}

	
		
	}
	CurveGroup[CurveNum].CurveStartThrum=tempThrumStart;
    CurveGroup[CurveNum].CurveStart=ThrumGroup[ThrumNum-1].ThrumEnd;
	tempThrumEnd=ThrumNum-1;
	if(tempThrumEnd==tempThrumStart)
	{
		ThrumTemp.ThrumStart=ThrumGroup[tempThrumStart].ThrumStart;
		ThrumGroup[tempThrumStart].ThrumStart=ThrumGroup[tempThrumStart].ThrumEnd;
		ThrumGroup[tempThrumStart].ThrumEnd=ThrumTemp.ThrumStart;
		if(ThrumGroup[tempThrumStart].ThrumDire<=32)
		{ThrumGroup[tempThrumStart].ThrumDire+=32;}
		else
		{ThrumGroup[tempThrumStart].ThrumDire-=32;}
	}
	else
	{
		for(j=0;j<=((tempThrumEnd-tempThrumStart)>>1);j++)
		{
		   ChangeSeqII(tempThrumStart+j,tempThrumEnd-j);
		}
	}
	while(DPSGII_ThrumCheck64D_NP(Img_bin,nWidth,nHeight,ThrumGroup[ThrumNum-1].ThrumEnd.x, ThrumGroup[ThrumNum-1].ThrumEnd.y, R,Rout,ThrumGroup[ThrumNum-1].ThrumDire,DirectionN)&&ThrumNum<THRUMMAXNUM)
	{
	//////////////////////////////////////////////////////////////////////
		HistorySign=((unsigned char *)(Img_sign+ nWidth*ThrumTemp.ThrumEnd.y))[ThrumTemp.ThrumEnd.x];
		HistoryLine=((unsigned short *)(Img_his+ nWidth*ThrumTemp.ThrumEnd.y))[ThrumTemp.ThrumEnd.x];
		if((HistorySign!=255)&&(ThrumNum>tempThrumEnd+1))
		{
			DirReigon=2;
			for(j=-CrossAngle;j<=CrossAngle;j++)////两曲线交叉的最小角度*(P+312)*5.625,小于这个角度则不能交叉
			{
				if((ThrumTemp.ThrumDire==CircleII[j+64+HistorySign])||(ThrumTemp.ThrumDire==CircleII[j+96+HistorySign])||(ThrumTemp.ThrumDire==CircleII[32+HistorySign]))
			    {
					DirReigon=1;
					break;
				}
			}
			i=0;
			while(CurveGroup[CurveNum].CrossCruve[i][0]!=0)
			{
				i++;
				if(i>4)
				{
					i=0;
					break;
				}
			}
			if(i==0||CurveGroup[CurveNum].CrossCruve[i-1][0]!=HistoryLine)
			{
				CurveGroup[CurveNum].CrossCruve[i][0]=HistoryLine;
				CurveGroup[CurveNum].CrossCruve[i][1]=DirReigon;
				CurveGroup[CurveNum].CrossCruve[i][2]=ThrumTemp.ThrumEnd.x;
				CurveGroup[CurveNum].CrossCruve[i][3]=ThrumTemp.ThrumEnd.y;
				if(ThrumGroup[ThrumNum-1].ThrumDire==ThrumTemp.ThrumDire)
				{CurveGroup[CurveNum].CrossCruve[i][4]=ThrumNum-1;}
				else
				{CurveGroup[CurveNum].CrossCruve[i][4]=ThrumNum;}
			}
			else if((CurveGroup[CurveNum].CrossCruve[i-1][0]==HistoryLine)&&(ThrumNum-CurveGroup[CurveNum].CrossCruve[i][4]<=2))
			{
			
				CurveGroup[CurveNum].CrossCruve[i-1][0]=HistoryLine;
				CurveGroup[CurveNum].CrossCruve[i-1][1]=DirReigon;
				CurveGroup[CurveNum].CrossCruve[i-1][2]=ThrumTemp.ThrumEnd.x;
				CurveGroup[CurveNum].CrossCruve[i-1][3]=ThrumTemp.ThrumEnd.y;
				if(ThrumGroup[ThrumNum-1].ThrumDire==ThrumTemp.ThrumDire)
				{CurveGroup[CurveNum].CrossCruve[i-1][4]=ThrumNum-1;}
				else
				{
					CurveGroup[CurveNum].CrossCruve[i-1][4]=ThrumNum;
				}
			}
	/*		if(ThrumGroup[HistoryLine].ThrumCurveSeq!=0xffff)
			{
				j=0;
				while(CurveGroup[ThrumGroup[HistoryLine].ThrumCurveSeq].CrossCruve[j][0]!=0)
				{
					j++;
					if(j>4)
					{
						j=0;
						break;
					}
				}
				CurveGroup[ThrumGroup[HistoryLine].ThrumCurveSeq].CrossCruve[j][0]=ThrumTemp.ThrumCurveSeq;
				CurveGroup[ThrumGroup[HistoryLine].ThrumCurveSeq].CrossCruve[j][1]=DirReigon;
				CurveGroup[ThrumGroup[HistoryLine].ThrumCurveSeq].CrossCruve[j][2]=ThrumTemp.ThrumEnd.x;
				CurveGroup[ThrumGroup[HistoryLine].ThrumCurveSeq].CrossCruve[j][3]=ThrumTemp.ThrumEnd.y;
				CurveGroup[ThrumGroup[HistoryLine].ThrumCurveSeq].CrossCruve[j][4]=HistoryLine;
			}*/
			if(DirReigon==1)
			{
				break;
			}
		}
/////////////////////////////////////////////////////////////////////
		if(ThrumGroup[ThrumNum-1].ThrumDire==ThrumTemp.ThrumDire)
		{
		    ThrumGroup[ThrumNum-1].ThrumEnd=ThrumTemp.ThrumEnd;
			ThrumGroup[ThrumNum-1].ThrumDist+=ThrumTemp.ThrumDist;
			CurveGroup[CurveNum].CurveDist[0]+=ThrumTemp.ThrumDist;
			ThrumGroup[ThrumNum-1].ThrumHisDire=CurveGroup[CurveNum].CurveDist[0];
			ThrumGroup[ThrumNum-1].ThrumNormdis=ThrumTemp.ThrumNormdis;
			CurveGroup[CurveNum].CurveDist[ThrumTemp.ThrumDire]+=ThrumTemp.ThrumDist;
		}
	    else
		{
		    ThrumGroup[ThrumNum].ThrumDire=ThrumTemp.ThrumDire;
		    ThrumGroup[ThrumNum].ThrumDist=ThrumTemp.ThrumDist;
		    ThrumGroup[ThrumNum].ThrumStart=ThrumTemp.ThrumStart;
		    ThrumGroup[ThrumNum].ThrumEnd=ThrumTemp.ThrumEnd;
			ThrumGroup[ThrumNum].ThrumCurveSeq=CurveNum;
			ThrumGroup[ThrumNum].ThrumNormdis=ThrumTemp.ThrumNormdis;
		   	CurveGroup[CurveNum].CurveDist[0]+=ThrumTemp.ThrumDist;
			CurveGroup[CurveNum].CurveDist[ThrumTemp.ThrumDire]+=ThrumTemp.ThrumDist;
			ThrumGroup[ThrumNum].ThrumHisDire=CurveGroup[CurveNum].CurveDist[0];
			if(ThrumTemp.ThrumNormdis<NormThre)
			{CurveGroup[CurveNum].CurveNormdis+=ThrumTemp.ThrumNormdis;}
			else
			{CurveGroup[CurveNum].CurveNormdis+=ThrumGroup[ThrumNum-1].ThrumNormdis;}
			ThrumNum+=1;
		}
		DPSGII_CopyLineSegRegion(Img_sign,Img_bin,Img_his,nWidth,nHeight,R,&ThrumTemp);

		
	 }
	  CurveGroup[CurveNum].CurveEndThrum=ThrumNum-1;
	  CurveGroup[CurveNum].CurveEnd=ThrumGroup[ThrumNum-1].ThrumEnd;
	  if(CurveGroup[CurveNum].CurveDist[0]>MinCruve)
	  { 
      /*曲线类型判断*/
		  CurveGroup[CurveNum].CurveChange=0;
		  CurveGroup[CurveNum].Curvetype=0;
		  CGPOINT Cstart;//曲线起始点
		  CGPOINT Cend;//曲线结束点
		  CGPOINT CTemp;//临时点
		  CGPOINT CBack;//临时点
		  CGPOINT CMAX;
		  CGPOINT *CCurve;
		  int CPointNum=CurveGroup[CurveNum].CurveEndThrum-CurveGroup[CurveNum].CurveStartThrum+2;
		  double StoELength=0.0;
		  double Maxdis=0.0;
		  double Tempdis=0.0;
		  double Circlerate=0.0;
		  int HalfSeq=0;
		  LINESEG StoE;
		  double PolygonArea=0.0;
		  CCurve =new CGPOINT[CPointNum];//取得多边形
		  double MaxCirclerate=0.0;
			CGPOINT BestCenter;
			double BestR=0.0;
			CGPOINT BestPartCenter;
			double BestPartR=0.0;
			int PointInCircle=0;
			int MaxPointInCircle=0;
		  if(CPointNum==2)
		  {
			  CurveGroup[CurveNum].Curvetype=1;//直线
			  ThrumGroup[CurveGroup[CurveNum].CurveStartThrum].ThrumWeight=1.0;
			  goto END;
		  }
			
			CCurve[0].x=CurveGroup[CurveNum].CurveStart.x;
			CCurve[0].y=CurveGroup[CurveNum].CurveStart.y;
			CCurve[CPointNum-1].x=CurveGroup[CurveNum].CurveEnd.x;
			CCurve[CPointNum-1].y=CurveGroup[CurveNum].CurveEnd.y;
			StoE.e=CCurve[0];
			StoE.s= CCurve[CPointNum-1];
			Maxdis=0.0;
			for(i=1;i<CPointNum-1;i++)
			{
				CCurve[i].x=ThrumGroup[CurveGroup[CurveNum].CurveStartThrum+i].ThrumStart.x;
				CCurve[i].y=ThrumGroup[CurveGroup[CurveNum].CurveStartThrum+i].ThrumStart.y;
				ThrumGroup[CurveGroup[CurveNum].CurveStartThrum+i-1].ThrumWeight=ThrumGroup[CurveGroup[CurveNum].CurveStartThrum+i-1].ThrumDist/CurveGroup[CurveNum].CurveDist[0];
				Tempdis=ptolinesegdist(CCurve[i],StoE,CBack);
				if(Tempdis>Maxdis)
				{
					Maxdis=Tempdis;
					CMAX=CTemp;
					}
			}
			ThrumGroup[CurveGroup[CurveNum].CurveEndThrum].ThrumWeight=ThrumGroup[CurveGroup[CurveNum].CurveEndThrum].ThrumDist/CurveGroup[CurveNum].CurveDist[0];
			if(Maxdis*30<CurveGroup[CurveNum].CurveDist[0])//最大夹角atan(0.2)=11.3度
			{
				CurveGroup[CurveNum].Curvetype=1;//直线
					goto END;
			}
			if(dist(CCurve[0],CCurve[CPointNum-1])*10<CurveGroup[CurveNum].CurveDist[0])
			{
					CurveGroup[CurveNum].Curvetype=8;//整体封闭轮廓
					goto END;
				}
			for(i=0;i<5;i++)
			{
				if(ThrumGroup[CurveGroup[CurveNum].CrossCruve[i][0]].ThrumCurveSeq==CurveNum&&CurveGroup[CurveNum].CrossCruve[i][1]!=0)
				{
					CurveGroup[CurveNum].Curvetype=9;//局部封闭轮廓
					goto END;
				}
			}
			double MacLineSeg[3][2]={0};
			for(i=1;i<65;i++)
			{
				CurveGroup[CurveNum].CurveDist[i]=CurveGroup[CurveNum].CurveDist[i]/CurveGroup[CurveNum].CurveDist[0];
				if(CurveGroup[CurveNum].CurveDist[i]>MacLineSeg[0][1])
				{
						MacLineSeg[2][1]=MacLineSeg[1][1];
						MacLineSeg[2][0]=MacLineSeg[1][0];
						MacLineSeg[1][1]=MacLineSeg[0][1];
						MacLineSeg[1][0]=MacLineSeg[0][0];
						MacLineSeg[0][1]=CurveGroup[CurveNum].CurveDist[i];
						MacLineSeg[0][0]=i;
				}
				else if(CurveGroup[CurveNum].CurveDist[i]>MacLineSeg[1][1])
				{
					MacLineSeg[2][1]=MacLineSeg[1][1];
					MacLineSeg[2][0]=MacLineSeg[1][0];
					MacLineSeg[1][1]=CurveGroup[CurveNum].CurveDist[i];
					MacLineSeg[1][0]=i;
				}
				else if(CurveGroup[CurveNum].CurveDist[i]>MacLineSeg[2][1])
				{
					MacLineSeg[2][1]=CurveGroup[CurveNum].CurveDist[i];
					MacLineSeg[2][0]=i;
				}
     		}
			//TRACE("曲线%d第一方向%f,长度%f，第二方向%f,长度%f,第三方向%f,长度%f,",CurveNum,MacLineSeg[0][0],MacLineSeg[0][1],MacLineSeg[1][0],MacLineSeg[1][1],MacLineSeg[2][0],MacLineSeg[2][1]);
			
			if(MacLineSeg[0][1]+MacLineSeg[1][1]+MacLineSeg[2][1]>0.75)
			{
				if(CurveGroup[CurveNum].CurveDist[0]<COLINEDIS)
				{
					CurveGroup[CurveNum].Curvetype=1;//直线
					goto END;
				}
				else if(MacLineSeg[2][1]>0.1)//||MacLineSeg[2][1]*CurveGroup[CurveNum].CurveDist[0]>20)//比重小或是绝对长度大于20
				{
					CurveGroup[CurveNum].Curvetype=3;//3折线
					goto END;
				}
				else if(MacLineSeg[1][1]>0.2)
				{
					CurveGroup[CurveNum].Curvetype=2;//2折线
					goto END;
				}
				else
				{
					CurveGroup[CurveNum].Curvetype=1;//直线
					goto END;

				}
			}
			for(i=1;i<33;i++)
			{
				CurveGroup[CurveNum].CurveDire=i*(CurveGroup[CurveNum].CurveDist[i]+CurveGroup[CurveNum].CurveDist[i+32]);
			}
			if(CPointNum>10)//可能是圆
			{
				//先进行整体圆弧判断
				for(i=3;i<CPointNum-3;i++)
				{
					cocircle(CCurve[i-2],CCurve[i],CCurve[i+2],CBack,Tempdis);
					if(CBack.x-Tempdis>0&&CBack.x+Tempdis<nWidth&&CBack.y-Tempdis>0&&CBack.y+Tempdis<nHeight)//找图内圆弧
					{
						Circlerate=CGpolygon_on_circle(CBack,Tempdis,CPointNum,CCurve,&PointInCircle);
						if(Circlerate>MaxCirclerate)
						{
							MaxCirclerate=Circlerate;
							BestCenter=CBack;
			                BestR=Tempdis;
						}
						if(PointInCircle>MaxPointInCircle)
						{
							MaxPointInCircle=PointInCircle;
							BestPartCenter=CBack;
			                BestPartR=Tempdis;

						}
					}
				}
				//TRACE("曲线%d最大类圆性%f,最多连续在圆上的点个数%d\n",CurveNum,MaxCirclerate,MaxPointInCircle);
				if(MaxCirclerate>EPCIRCLE)
				{
					CurveGroup[CurveNum].Curvetype=6;//圆弧
					for(i=0;i<CIRCLENUM;i++) 
					{
						if(CircleGroup[i][0]==0)
						{
							CircleGroup[i][0]=CurveNum;
							CircleGroup[i][1]=BestR;
							CircleGroup[i][2]=BestCenter.x;
							CircleGroup[i][3]=BestCenter.y;
							break;
						}
					}
					goto END;
				}
				if(MaxPointInCircle>PARTCIRCLE )
				{
					CurveGroup[CurveNum].Curvetype=7;//局部圆弧
					for(i=0;i<CIRCLENUM;i++) 
					{
						if(CircleGroup[i][0]==0)
						{
							CircleGroup[i][0]=CurveNum;
							CircleGroup[i][1]=BestR;
							CircleGroup[i][2]=BestCenter.x;
							CircleGroup[i][3]=BestCenter.y;
							break;
						}
					}
					goto END;
				}
			}
				
END:	  delete CCurve;
		  
          CurveGroup[CurveNum].CurveNormdis=CurveGroup[CurveNum].CurveNormdis/(CurveGroup[CurveNum].CurveEndThrum-CurveGroup[CurveNum].CurveStartThrum+1);
		  for(i=0;i<MAXCURVENUM;i++)//前十个最长曲线记录
		  {
			  if(CurveGroup[CurveNum].CurveDist[0]>MaxCurveGroup[i][1])
			  {
				/*  for(j=MAXCURVENUM-1;j>i;j++)
				  {
					  MaxCurveGroup[j][1]=MaxCurveGroup[j-1][1];
					  MaxCurveGroup[j][0]=MaxCurveGroup[j-1][0];
				  }*/
				  MaxCurveGroup[i][1]=CurveGroup[CurveNum].CurveDist[0];
				  MaxCurveGroup[i][0]=CurveNum;
				  break;
			  }
		  }
	 }
	  
}
////////////////////////////////////////////////////////////////////////
//	函 数 名 ：void DPSGII_CrossConclusion()
//	函数功能 ：将相交曲线信息充实完善，两条曲线只要相接就能检索到
//	作    者 ：朱宗晓
//	时    间 ：2012年09月09日
//	返 回 值 ： 被修改了的CurveGroup
//	入口参数说明 ：无
////////////////////////////////////////////////////////////////////////
//	历史记录：
//	编号     日期    	作者    备注
//	0	2012年09月09日	朱宗晓	创建本函数
//	////////////////////////////////////////////////////////////////////////
void DPSGII_CrossConclusion()
{
	int i=0;
	int j=0;
	int SelfLineSeq=0;//相交自己线段号
	int OtherLineSeq=0;//相交它人线段号
	int CurveSeq=0;//曲线号
	int CrossType=0;//相交类型
	int x=0;
	int y=0;
	int k=0;
	for(i=0;i<CurveNum;i++)
	{
		j=0;
		while(CurveGroup[i].CrossCruve[j][0]!=0&&CurveGroup[i].CrossCruve[j][5]==0)
		{
			OtherLineSeq=CurveGroup[i].CrossCruve[j][0];
			CrossType=CurveGroup[i].CrossCruve[j][1];
            SelfLineSeq=CurveGroup[i].CrossCruve[j][4];
			x=CurveGroup[i].CrossCruve[j][2];
		    y=CurveGroup[i].CrossCruve[j][3];
			CurveSeq=ThrumGroup[OtherLineSeq].ThrumCurveSeq;
			if(CurveSeq!=0xffff)
			{
				k=0;
				while(CurveGroup[CurveSeq].CrossCruve[k][0]!=0)
				{
					k++;
					if(k>4)
					{
						k=0;
						break;
					}
				}
				CurveGroup[CurveSeq].CrossCruve[k][0]=SelfLineSeq;
				CurveGroup[CurveSeq].CrossCruve[k][1]=CrossType;
				CurveGroup[CurveSeq].CrossCruve[k][2]=x;
				CurveGroup[CurveSeq].CrossCruve[k][3]=y;
				CurveGroup[CurveSeq].CrossCruve[k][4]=OtherLineSeq;
				CurveGroup[CurveSeq].CrossCruve[k][5]=0xff;
			}
        j++;
		if(j==5)
		{break;}
		}

	}
}
////////////////////////////////////////////////////////////////////////
//	函 数 名 ：void DPSGII_AutoCurveSearch64D(unsigned char* Img_bin,unsigned char* Img_sign,int nWidth,int nHeight, StartThrumInfo * StartThrumNow,int R,int DirectionN,int NormThre,int CrossAngle,int MinLine,int MinCruve)
//	函数功能 ：在Img_bin中自动探测曲线信息
//	作    者 ：朱宗晓
//	时    间 ：2012年4月1日
//	返 回 值 ：线段及曲线集合
//	入口参数说明 ：
//  1.IplImage * Img_bin: 待探测图
//  2.IplImage * Img_sign: 已探测区域标记图
//  3.int nWidth：待计算的灰度图数组宽度
//  4.int nHeight：待计算的灰度图数组高度
//  5.int R：采样半径
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

void DPSGII_AutoCurveSearch64D(unsigned char* Img_bin,unsigned char* Img_sign,unsigned short* Img_history,int nWidth,int nHeight,int Rin,int Rout,int DirectionN,int NormThre,int CrossAngle,int MinLine,int MinCruve)
{
	int x=0;
	int y=0;
	int i=0;
	bool FeaturePointSign=false;
	for(y=(int)Rout;y<nHeight-Rout;y+=Rin)
	{
		for(x=(int)Rout;x<nWidth-Rout;x+=Rin)
		{
			if(CurveNum>=CURVEMAXNUM||StartThrumNum>=CURVEMAXNUM||ThrumNum>THRUMMAXNUM)
			{break;}
			//探测图中是邻域八联通的黑点，标记图中是邻域无黑点的白点,才认为是可能的起始点
			if((((unsigned char*)(Img_bin + nWidth*y))[x]==0)&&(DPSGII_DPAdnate8Check(Img_bin,nWidth,nHeight,x,y,Rin)>=2)
				&&(((unsigned char*)(Img_sign + nWidth*y))[x]==255)&&(DPSGII_DPSignCheck(Img_sign,nWidth,nHeight,x,y,(Rin<<2))))
			{
				//找起始线头
				memset(&FeaturePoint[FeaturePointNum],0,sizeof(FeaturePointInfo));
				FeaturePoint[FeaturePointNum]=DPSGII_FeaturePointSearch64D(Img_bin,nWidth,nHeight,x,y,Rin,Rout,NormThre);
				FeaturePointSign=DPSGII_FeaturePointBlockArea(Img_sign,nWidth,nHeight,Rin,&FeaturePoint[FeaturePointNum]);
	            FeaturePointNum+=FeaturePointSign;	
		
				//起始线头所在长度要大于MinLine
				if(FeaturePointSign&&FeaturePoint[FeaturePointNum-1].ThrumDist>MinLine&&FeaturePoint[FeaturePointNum-1].ThrumNormdis<NormThre)
				{
					DPSGII_CurveSearch64D(Img_bin,Img_sign,Img_history,nWidth,nHeight,&FeaturePoint[FeaturePointNum-1],Rin,Rout,DirectionN,NormThre,CrossAngle,MinCruve);
					//TRACE("CurveNum=%d:CurveDist[0]=%f,CurveStartThrum=%d,CurveEndThrum=%d\n",CurveNum,CurveGroup[CurveNum].CurveDist[0],CurveGroup[CurveNum].CurveStartThrum,CurveGroup[CurveNum].CurveEndThrum);
					if(CurveGroup[CurveNum].CurveDist[0]>MinCruve)
					{
						CurveNum++;
					}
					else
					{
						
						for(i=CurveGroup[CurveNum].CurveStartThrum;i<=CurveGroup[CurveNum].CurveEndThrum;i++)
						{
							ThrumGroup[i].ThrumCurveSeq=0xffff;
						}
					}
				}
			}
		}
	}
	if(CurveNum>2)
	{DPSGII_CrossConclusion();}

}
void DPSGII_AutoCurveSearch64DII(unsigned char* Img_bin,unsigned char* Img_sign,unsigned short* Img_history,int nWidth,int nHeight,int Rin,int Rout,int DirectionN,int NormThre,int CrossAngle,int MinLine,int MinCruve)
{
	int x=0;
	int y=0;
	int i=0;
	for(y=(int)Rout;y<nHeight-Rout;y+=Rin)
	{
		for(x=(int)Rout;x<nWidth-Rout;x+=Rin)
		{
			if(CurveNum>=CURVEMAXNUM||StartThrumNum>=CURVEMAXNUM||ThrumNum>THRUMMAXNUM)
			{break;}
			//探测图中是邻域八联通的黑点，标记图中是邻域无黑点的白点,才认为是可能的起始点
			if((((unsigned char*)(Img_bin + nWidth*y))[x]==0)&&(DPSGII_DPAdnate8Check(Img_bin,nWidth,nHeight,x,y,Rin)>=2)
				&&(((unsigned char*)(Img_sign + nWidth*y))[x]==255)&&(DPSGII_DPSignCheck(Img_sign,nWidth,nHeight,x,y,(Rin<<2))))
			{
				//找起始线头
				memset(&StartThrum[StartThrumNum],0,sizeof(StartThrumInfo));
				StartThrum[StartThrumNum]=DPSGII_StartThrumSearch64D(Img_bin,nWidth,nHeight,x,y,Rin,Rout);
				//StartThrum[StartThrumNum]=ROI_DPSGII_StartThrumSearch64D(Img_bin,nWidth,nHeight,x,y,Rin);
				//TRACE("StartThrumNum=%d:x=%d,y=%d,ThrumSource.x=%d,ThrumSource.y=%d,ThrumDire=%d,ThrumDist=%f,ThrumNormdis=%f\n",StartThrumNum,x,y,StartThrum[StartThrumNum].ThrumSource.x,StartThrum[StartThrumNum].ThrumSource.y,StartThrum[StartThrumNum].ThrumDire,StartThrum[StartThrumNum].ThrumDist,StartThrum[StartThrumNum].ThrumNormdis);
				//起始线头所在长度要大于MinLine
				if(StartThrum[StartThrumNum].ThrumDist>MinLine&&StartThrum[StartThrumNum].ThrumNormdis<NormThre)
					//&&StartThrum[StartThrumNum].ThrumDist>(StartThrum[StartThrumNum].ThrumNormdis*4))
				{
					DPSGII_CurveSearch64D(Img_bin,Img_sign,Img_history,nWidth,nHeight,&StartThrum[StartThrumNum],Rin,Rout,DirectionN,NormThre,CrossAngle,MinCruve);
					//TRACE("CurveNum=%d:CurveDist[0]=%f,CurveStartThrum=%d,CurveEndThrum=%d\n",CurveNum,CurveGroup[CurveNum].CurveDist[0],CurveGroup[CurveNum].CurveStartThrum,CurveGroup[CurveNum].CurveEndThrum);
					if(CurveGroup[CurveNum].CurveDist[0]>MinCruve)
					{
						StartThrumNum++;
						CurveNum++;
					}
					else
					{
						
						for(i=CurveGroup[CurveNum].CurveStartThrum;i<=CurveGroup[CurveNum].CurveEndThrum;i++)
						{
							ThrumGroup[i].ThrumCurveSeq=0xffff;
						}
					}
				}
			}
		}
	}
	if(CurveNum>2)
	{DPSGII_CrossConclusion();}

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////测图
//  2.IplImage * Img_sign: 已探测区域标记图
//  3.int nWidth：待计算的灰度图数组宽度
//  4.int nHeight：待计算的灰度图数组高度
//  5.int R：采样半径
//  6.int DirectionN：直线探测范围
//  7.int NormThre：法线阈值
//  8.int CrossAngle：两曲线交叉的最小角度
//  9.int MinLine：最小起始点所在直线长度
////////////////////////////////////////////////////////////////////////
//	历史记录：
//	编号     日期    	作者    备注
//	0	2012年03月31日	朱宗晓	创建本函数
//	////////////////////////////////////////////////////////////////////////
void DPSGII_AutoLineSearch64D(unsigned char* Img_bin,unsigned char* Img_sign,unsigned short* Img_history,int nWidth,int nHeight,int Rin,int Rout,int DirectionN,int NormThre,int CrossAngle,int MinLine)
{
	int x=0;
	int y=0;
	int i=0;
	for(y=(int)Rout;y<nHeight-Rout;y+=Rin)
	{
		for(x=(int)Rout;x<nWidth-Rout;x+=Rin)
		{
			//探测图中是邻域八联通的黑点，标记图中是邻域无黑点的白点,才认为是可能的起始点
			if((((unsigned char*)(Img_bin + nWidth*y))[x]==0)&&(DPSGII_DPAdnate8Check(Img_bin,nWidth,nHeight,x,y,Rin)>=4)
				&&(((unsigned char*)(Img_sign + nWidth*y))[x]==255)&&(DPSGII_DPSignCheck(Img_sign,nWidth,nHeight,x,y,(Rin<<3))))
			{
				//找起始线头
				StartThrum[StartThrumNum]=DPSGII_StartThrumSearch64D(Img_bin,nWidth,nHeight,x,y,Rin,Rout);
				//起始线头所在长度要大于MinLine
				if(StartThrum[StartThrumNum].ThrumDist>MinLine)
				{
					DPSGII_StartThrumToThrum(&StartThrum[StartThrumNum],&ThrumTemp);
					DPSGII_CopyLineSegRegion(Img_sign,Img_bin,Img_history,nWidth,nHeight,Rin,&ThrumTemp);
				    StartThrumNum++;
     			}

			}
		}
	}
}
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
void DPSGII_Clear()
{
	StartThrumNum=0;//起始线段序号
	memset(StartThrum,0,CURVEMAXNUM*sizeof(StartThrumInfo));//清空CurveGroup[CURVEMAXNUM]
	memset(&StartThrumTemp,0,sizeof(StartThrumInfo));
	ThrumNum=0;
	memset(ThrumGroup,0,THRUMMAXNUM*sizeof(ThrumInfo));//清空ThrumGroup[THRUMMAXNUM]
	memset(&ThrumTemp,0,sizeof(ThrumInfo));//清空ThrumTemp
	CurveNum=0;
	memset(CurveGroup,0,CURVEMAXNUM*sizeof(CurveInfo));//清空CurveGroup[CURVEMAXNUM]
	FeaturePointNum=0;
	memset(FeaturePoint,0,CURVEMAXNUM*sizeof(FeaturePointInfo));
	memset(MaxCurveGroup,0,MAXCURVENUM*sizeof(unsigned short)<<1);//前十长曲线记录器
	memset(CircleGroup,0,CIRCLENUM*sizeof(unsigned short)<<2);//圆记录器
}
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
void DPSGII_Result(int& StartThrumNumOut,int& ThrumNumOut, int&CurveNumOut)
{
	StartThrumNumOut=StartThrumNum;
	ThrumNumOut=ThrumNum;
	CurveNumOut=CurveNum;
}
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
StartThrumInfo * DPSGII_StartThrum(int StartThrumNumNow)
{
	return &StartThrum[StartThrumNumNow];
}
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
CurveInfo * DPSGII_Curve(int CurveNumNow)
{
	return &CurveGroup[CurveNumNow];
}
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
unsigned short  DPSGII_MaxCurve(int MaxSeq)
{
	return MaxCurveGroup[MaxSeq][0];
}
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
ThrumInfo * DPSGII_Thrum(int ThrumNumNow)
{
	return &ThrumGroup[ThrumNumNow];
}
ThrumInfo * DPSGII_ConLine(int ConLineNumNow)
{
	return &LineConnect[ConLineNumNow];
}
ThrumInfo * DPSGII_ParallelLine(int ConLineNumNow)
{
	return &LineParallel[ConLineNumNow];
}
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
FeaturePointInfo * DPSGII_FeaturePoint(int FeaturePointNow)
{
	return &FeaturePoint[FeaturePointNow];
}


////////////////////////////////////////////////////////////////////////
//	函 数 名 ：bool RegionBetweenAngle(StepStrucureII *ThrumRegion,unsigned char AngleOne,unsigned char AngleTwo)
//	函数功能 ：设计一个函数，输入任意两个方向，输出夹角中是否有间隔
//	作    者 ：朱宗晓
//	时    间 ：2012年09月09日
//	返 回 值 ：0：无间隔 1：有间隔
//	入口参数说明 ：
//	1.StepStrucureII *ThrumRegion：待计算的二值图
//  2.unsigned char AngleOne: 角度1
//  3.unsigned char AngleTwo: 角度2
////////////////////////////////////////////////////////////////////////
//	历史记录：
//	编号     日期    	作者    备注
//	0	2012年09月09日	朱宗晓	创建本函数
//	////////////////////////////////////////////////////////////////////////	
bool RegionBetweenAngle(StepStrucureII *ThrumRegion,unsigned char AngleOne,unsigned char AngleTwo)
{
	int i=0;
	bool RegionSign =false;
	char AngleSubOne=0;
	char AngleSubTwo=0;
	if(AngleOne==AngleTwo)
	{return RegionSign;}
	if(AngleTwo-AngleOne==32)
	{
		for(i=AngleOne+1;i<AngleTwo;i++)
		{
			if((ThrumRegion+i)->stepdistense<0.1)
			{
					RegionSign=true;
					break;
			}
		}
	}
	else if(AngleOne-AngleTwo==32)
	{
		for(i=1;i<32;i++)
		{
			if((ThrumRegion+ CircleII[64+AngleOne+i])->stepdistense<0.1)
			{
					RegionSign=true;
					break;
			}

		}
	}
	else if(AngleTwo<AngleOne)
	{
		AngleSubOne=AngleOne;
		AngleOne=AngleTwo;
		AngleTwo=AngleSubOne;
	}
	AngleSubOne=AngleTwo-AngleOne;
	AngleSubTwo=AngleOne-AngleTwo+64;
	if(AngleSubOne<AngleSubTwo)
	{
		for(i=AngleOne+1;i<AngleTwo;i++)
		{
			if((ThrumRegion+i)->stepdistense<0.1)
			{
					RegionSign=true;
					break;
			}
		}
	}
	else
	{
		for(i=1;i<AngleSubTwo;i++)
		{
			if((ThrumRegion+ CircleII[64+AngleTwo+i])->stepdistense<0.1)
			{
				RegionSign=true;
				break;
			}
		}
	}
	return RegionSign;
}
////////////////////////////////////////////////////////////////////////
//	函 数 名 ：bool RegionBetweenAngleII(StepStrucureII *ThrumRegion,unsigned char AngleOne,unsigned char AngleTwo)
//	函数功能 ：设计一个函数，输入任意两个方向，输出夹角中是否有间隔
//	作    者 ：朱宗晓
//	时    间 ：2012年09月09日
//	返 回 值 ：0：无间隔 1：有间隔
//	入口参数说明 ：
//	1.StepStrucureII *ThrumRegion：待计算的二值图
//  2.unsigned char AngleOne: 角度1
//  3.unsigned char AngleTwo: 角度2
////////////////////////////////////////////////////////////////////////
//	历史记录：
//	编号     日期    	作者    备注
//	0	2012年09月09日	朱宗晓	创建本函数
//	////////////////////////////////////////////////////////////////////////	
bool RegionBetweenAngleII(StepStrucureII *ThrumRegion,unsigned char AngleOne,unsigned char AngleTwo)
{
	int i=0;
	bool RegionSign =false;
	char AngleSub;
	if(AngleOne==AngleTwo)
	{return RegionSign;}
	else if(AngleOne<AngleTwo)
	{
		for(i=AngleOne+1;i<AngleTwo;i++)
		{
			if((ThrumRegion+i)->stepdistense<0.1)
			{
					RegionSign=true;
					break;
			}
		}

	}
	else
	{
		AngleSub=AngleOne-AngleTwo;
		for(i=1;i<AngleSub;i++)
		{
			if((ThrumRegion+ CircleII[64+AngleTwo+i])->stepdistense<0.1)
			{
					RegionSign=true;
					break;
			}

		}


	}
	return RegionSign;
}
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
FeaturePointInfo DPSGII_FeaturePointSearch64D(unsigned char* Img_bin,int nWidth,int nHeight, int cenX, int cenY, int R,int Rout,int NormThre)
{
	FeaturePointInfo FeaturePointNow;
	int i=0;
	memset(&FeaturePointNow,0,sizeof(FeaturePointInfo));
	unsigned char Max32Direction=0;//最大32方向
    double Max32PDC=0.0;//最长方向贡献度
	double TotalPDC=0.0;//长度和
	double ThrumTest32[33] = {0};
	unsigned char Min64Direction=0;//最小方向
	double Min64PDC=1000.0;//最小64方向贡献度
	unsigned char Min32Direction=0;//最小方向
	double Min32PDC=1000.0;//最小32方向贡献度
	StepStrucureII ThrumTest64[65] = {0};
	for(i=1;i<33;i++)
	{
		ThrumTest64[i]=DPSGII_DPTraceR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,i);
        ThrumTest64[i+32]=DPSGII_DPTraceR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,i+32);
		ThrumTest32[i]=ThrumTest64[i].stepdistense+ThrumTest64[i+32].stepdistense;
		if(ThrumTest32[i]>Max32PDC)
		{
			Max32PDC=ThrumTest32[i];
			Max32Direction=i;
		}
		if(ThrumTest32[i]<Min32PDC)
		{
			Min32PDC=ThrumTest32[i];
			Min32Direction=i;
		}
		if(ThrumTest64[i].stepdistense<Min64PDC)
		{
			Min64PDC=ThrumTest64[i].stepdistense;
			Min64Direction=i;
		}
		if(ThrumTest64[i+32].stepdistense<Min64PDC)
		{
			Min64PDC=ThrumTest64[i+32].stepdistense;
			Min64Direction=i+32;
		}
		TotalPDC+=ThrumTest64[i].stepdistense;
	}
	/*定出原点，最大直线方向，最大直线长度*/
	FeaturePointNow.FeaturePointPos.x=cenX;
	FeaturePointNow.FeaturePointPos.y=cenY;
	FeaturePointNow.ThrumDist=Max32PDC;
	FeaturePointNow.ThrumDire=Max32Direction;
	/*定出长轴方向、短轴方向，短轴方向对应起点，长轴方向对应终点*/
	if(ThrumTest64[Max32Direction].stepdistense>ThrumTest64[Max32Direction+32].stepdistense)
	{
		FeaturePointNow.LongDir=Max32Direction;
		FeaturePointNow.LoneDis=ThrumTest64[Max32Direction].stepdistense;
		FeaturePointNow.ShortDir=Max32Direction+32;
		FeaturePointNow.ShortDis=ThrumTest64[Max32Direction+32].stepdistense;
		FeaturePointNow.ThrumStart.x=ThrumTest64[Max32Direction+32].xstep;
		FeaturePointNow.ThrumStart.y=ThrumTest64[Max32Direction+32].ystep;
		FeaturePointNow.ThrumEnd.x=ThrumTest64[Max32Direction].xstep;
		FeaturePointNow.ThrumEnd.y=ThrumTest64[Max32Direction].ystep;
	}
	else
	{
		FeaturePointNow.LongDir=Max32Direction+32;
		FeaturePointNow.LoneDis=ThrumTest64[Max32Direction+32].stepdistense;
		FeaturePointNow.ShortDir=Max32Direction;
		FeaturePointNow.ShortDis=ThrumTest64[Max32Direction].stepdistense;
		FeaturePointNow.ThrumStart.x=ThrumTest64[Max32Direction].xstep;
		FeaturePointNow.ThrumStart.y=ThrumTest64[Max32Direction].ystep;
		FeaturePointNow.ThrumEnd.x=ThrumTest64[Max32Direction+32].xstep;
		FeaturePointNow.ThrumEnd.y=ThrumTest64[Max32Direction+32].ystep;
	}
	/*每个方向都有点,说明位于较宽区域，用法线边界点把最小探测区域反馈回去*/
	if(Min64PDC>0.0)
	{
		FeaturePointNow.PointNormOne.x=ThrumTest64[Min64Direction].xstep;
		FeaturePointNow.PointNormOne.y=ThrumTest64[Min64Direction].ystep;
		FeaturePointNow.NormOne=Min64Direction;
		FeaturePointNow.NormOneDis=ThrumTest64[Min64Direction].stepdistense;
		if(Min64Direction>32)
		{Min64Direction-=32;}
		else
		{Min64Direction+=32;}
		FeaturePointNow.PointNormTwo.x=ThrumTest64[Min64Direction].xstep;
		FeaturePointNow.PointNormTwo.y=ThrumTest64[Min64Direction].ystep;
		FeaturePointNow.NormTwo=Min64Direction;
		FeaturePointNow.NormTwoDis=ThrumTest64[Min64Direction].stepdistense;
		FeaturePointNow.FeaturePointType=0xff;
		return FeaturePointNow;
	}
	else if(Min32PDC>0.1)
	{
		if(ThrumTest64[Min32Direction].stepdistense>ThrumTest64[Min32Direction+32].stepdistense)
		{
			FeaturePointNow.PointNormOne.x=ThrumTest64[Min32Direction].xstep;
			FeaturePointNow.PointNormOne.y=ThrumTest64[Min32Direction].ystep;
			FeaturePointNow.NormOne=Min32Direction;
			FeaturePointNow.NormOneDis=ThrumTest64[Min32Direction].stepdistense;
			FeaturePointNow.PointNormTwo.x=ThrumTest64[Min32Direction+32].xstep;
			FeaturePointNow.PointNormTwo.y=ThrumTest64[Min32Direction+32].ystep;
			FeaturePointNow.NormTwo=Min32Direction+32;
			FeaturePointNow.NormTwoDis=ThrumTest64[Min32Direction+32].stepdistense;
		}
		else
		{
			FeaturePointNow.PointNormOne.x=ThrumTest64[Min32Direction+32].xstep;
			FeaturePointNow.PointNormOne.y=ThrumTest64[Min32Direction+32].ystep;
			FeaturePointNow.NormOne=Min32Direction+32;
			FeaturePointNow.NormOneDis=ThrumTest64[Min32Direction+32].stepdistense;
			FeaturePointNow.PointNormTwo.x=ThrumTest64[Min32Direction].xstep;
			FeaturePointNow.PointNormTwo.y=ThrumTest64[Min32Direction].ystep;
			FeaturePointNow.NormTwo=Min32Direction;
			FeaturePointNow.NormTwoDis=ThrumTest64[Min32Direction].stepdistense;

		}
		FeaturePointNow.FeaturePointType=0xf0;
		return FeaturePointNow;

	}
	/*定出法线方向和法线边界*/
	int NormOne=CircleII[64+Max32Direction+16];//法线方向1
	int NormTwo=CircleII[64+Max32Direction-16];//法线方向2
	FeaturePointNow.ThrumNormdis=ThrumTest64[NormOne].stepdistense+ThrumTest64[NormTwo].stepdistense;
	if(FeaturePointNow.ThrumNormdis<0.1)
	{
		NormOne=CircleII[64+Max32Direction+15];//法线方向1
		NormTwo=CircleII[64+Max32Direction-17];//法线方向2
		FeaturePointNow.ThrumNormdis=ThrumTest64[NormOne].stepdistense+ThrumTest64[NormTwo].stepdistense;
	}
	if(FeaturePointNow.ThrumNormdis<0.1)
	{
		NormOne=CircleII[64+Max32Direction+17];//法线方向1
		NormTwo=CircleII[64+Max32Direction-15];//法线方向2
		FeaturePointNow.ThrumNormdis=ThrumTest64[NormOne].stepdistense+ThrumTest64[NormTwo].stepdistense;
	}
	if(FeaturePointNow.ThrumNormdis<0.1)
	{
		NormOne=CircleII[64+Max32Direction+18];//法线方向1
		NormTwo=CircleII[64+Max32Direction-14];//法线方向2
		FeaturePointNow.ThrumNormdis=ThrumTest64[NormOne].stepdistense+ThrumTest64[NormTwo].stepdistense;
	}
	if(FeaturePointNow.ThrumNormdis<0.1)
	{
		NormOne=CircleII[64+Max32Direction+14];//法线方向1
		NormTwo=CircleII[64+Max32Direction-18];//法线方向2
		FeaturePointNow.ThrumNormdis=ThrumTest64[NormOne].stepdistense+ThrumTest64[NormTwo].stepdistense;
	}

	FeaturePointNow.NormOne=NormOne;
	FeaturePointNow.NormOneDis=ThrumTest64[NormOne].stepdistense;
	FeaturePointNow.PointNormOne.x=ThrumTest64[NormOne].xstep;
	FeaturePointNow.PointNormOne.y=ThrumTest64[NormOne].ystep;
	FeaturePointNow.NormTwo=NormTwo;
	FeaturePointNow.NormTwoDis=ThrumTest64[NormTwo].stepdistense;
	FeaturePointNow.PointNormTwo.x=ThrumTest64[NormTwo].xstep;
	FeaturePointNow.PointNormTwo.y=ThrumTest64[NormTwo].ystep;
	if(FeaturePointNow.ThrumDist*2<TotalPDC)
	{
		FeaturePointNow.FeaturePointType=0xf;
		return FeaturePointNow;
    }
	bool RegionSign[5]={0};
	RegionSign[1]=RegionBetweenAngleII(&ThrumTest64[0],Max32Direction,NormOne);
	RegionSign[2]=RegionBetweenAngleII(&ThrumTest64[0],NormOne,Max32Direction+32);
	RegionSign[3]=RegionBetweenAngleII(&ThrumTest64[0],Max32Direction+32,NormTwo);
	RegionSign[4]=RegionBetweenAngleII(&ThrumTest64[0],NormTwo,Max32Direction);
	RegionSign[0]=RegionSign[1]*RegionSign[2]*RegionSign[3]*RegionSign[4];
	if(FeaturePointNow.ThrumNormdis<NormThre)
	{
		FeaturePointNow.FeaturePointType=2;
		if(FeaturePointNow.ShortDis<(4*R)&&FeaturePointNow.ThrumNormdis<(FeaturePointNow.ThrumDist*0.25))//短方向到头，法线宽度小于线头长度四分之一
		{
			if((fabs(FeaturePointNow.NormOneDis-FeaturePointNow.NormTwoDis)<(R*2))&&(min(FeaturePointNow.NormOneDis,FeaturePointNow.NormTwoDis)>0.1))//取到法线中间
			{FeaturePointNow.FeaturePointType=1;}
		}
		return FeaturePointNow;
	}
	
	if(min(FeaturePointNow.NormOneDis,FeaturePointNow.NormTwoDis)>min(FeaturePointNow.ThrumDist*0.25,NormThre*0.5))//法线宽度比较宽
	{
		if(RegionSign[0])
		{FeaturePointNow.FeaturePointType=4;}
	}
   	return FeaturePointNow;
}
////////////////////////////////////////////////////////////////////////
//	函 数 名 ：FeaturePointInfo DPSGII_FeaturePointShield(unsigned char* Img_bin,int nWidth,int nHeight, int cenX, int cenY, int R,int Rout,int NormThre)
//	函数功能 ：计算Img_bin指定点的特征信息
//	作    者 ：朱宗晓
//	时    间 ：2012年09月09日
//	返 回 值 ： 指定点的特征信息StartThrumInfo StartThrumNow结构体，只返回区域点和半区域点中的特征点
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
FeaturePointInfo DPSGII_FeaturePointShield(unsigned char* Img_bin,int nWidth,int nHeight, int cenX, int cenY, int R,int Rout,int NormThre)
{
	FeaturePointInfo FeaturePointNow;
	int i=0;
	memset(&FeaturePointNow,0,sizeof(FeaturePointInfo));
	unsigned char Max32Direction=0;//最大32方向
    double Max32PDC=0.0;//最长方向贡献度
	double TotalPDC=0.0;//长度和
	double ThrumTest32[33] = {0};
	unsigned char Min64Direction=0;//最小方向
	double Min64PDC=1000.0;//最小64方向贡献度
	unsigned char Min32Direction=0;//最小方向
	double Min32PDC=1000.0;//最小32方向贡献度
	StepStrucureII ThrumTest64[65] = {0};
	for(i=1;i<33;i++)
	{
		ThrumTest64[i]=DPSGII_DPTraceR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,i);
        ThrumTest64[i+32]=DPSGII_DPTraceR64D(Img_bin,nWidth,nHeight,cenX,cenY,R,Rout,i+32);
		ThrumTest32[i]=ThrumTest64[i].stepdistense+ThrumTest64[i+32].stepdistense;
		if(ThrumTest32[i]>Max32PDC)
		{
			Max32PDC=ThrumTest32[i];
			Max32Direction=i;
		}
		if(ThrumTest32[i]<Min32PDC)
		{
			Min32PDC=ThrumTest32[i];
			Min32Direction=i;
		}
		if(ThrumTest64[i].stepdistense<Min64PDC)
		{
			Min64PDC=ThrumTest64[i].stepdistense;
			Min64Direction=i;
		}
		if(ThrumTest64[i+32].stepdistense<Min64PDC)
		{
			Min64PDC=ThrumTest64[i+32].stepdistense;
			Min64Direction=i+32;
		}
		TotalPDC+=ThrumTest64[i].stepdistense;
	}
	///*定出原点，最大直线方向，最大直线长度*/
	FeaturePointNow.FeaturePointPos.x=cenX;
	FeaturePointNow.FeaturePointPos.y=cenY;
	FeaturePointNow.ThrumDist=Max32PDC;
	FeaturePointNow.ThrumDire=Max32Direction;
	/*每个方向都有点,说明位于较宽区域，用法线边界点把最小探测区域反馈回去*/
	if(Min64PDC>0.0)
	{
		FeaturePointNow.PointNormOne.x=ThrumTest64[Min64Direction].xstep;
		FeaturePointNow.PointNormOne.y=ThrumTest64[Min64Direction].ystep;
		FeaturePointNow.NormOne=Min64Direction;
		FeaturePointNow.NormOneDis=ThrumTest64[Min64Direction].stepdistense;
		if(Min64Direction>32)
		{Min64Direction-=32;}
		else
		{Min64Direction+=32;}
		FeaturePointNow.PointNormTwo.x=ThrumTest64[Min64Direction].xstep;
		FeaturePointNow.PointNormTwo.y=ThrumTest64[Min64Direction].ystep;
		FeaturePointNow.NormTwo=Min64Direction;
		FeaturePointNow.NormTwoDis=ThrumTest64[Min64Direction].stepdistense;
		FeaturePointNow.FeaturePointType=0xff;
		return FeaturePointNow;
	}
	else if(Min32PDC>0.1)
	{
		if(ThrumTest64[Min32Direction].stepdistense>ThrumTest64[Min32Direction+32].stepdistense)
		{
			FeaturePointNow.PointNormOne.x=ThrumTest64[Min32Direction].xstep;
			FeaturePointNow.PointNormOne.y=ThrumTest64[Min32Direction].ystep;
			FeaturePointNow.NormOne=Min32Direction;
			FeaturePointNow.NormOneDis=ThrumTest64[Min32Direction].stepdistense;
			FeaturePointNow.PointNormTwo.x=ThrumTest64[Min32Direction+32].xstep;
			FeaturePointNow.PointNormTwo.y=ThrumTest64[Min32Direction+32].ystep;
			FeaturePointNow.NormTwo=Min32Direction+32;
			FeaturePointNow.NormTwoDis=ThrumTest64[Min32Direction+32].stepdistense;
		}
		else
		{
			FeaturePointNow.PointNormOne.x=ThrumTest64[Min32Direction+32].xstep;
			FeaturePointNow.PointNormOne.y=ThrumTest64[Min32Direction+32].ystep;
			FeaturePointNow.NormOne=Min32Direction+32;
			FeaturePointNow.NormOneDis=ThrumTest64[Min32Direction+32].stepdistense;
			FeaturePointNow.PointNormTwo.x=ThrumTest64[Min32Direction].xstep;
			FeaturePointNow.PointNormTwo.y=ThrumTest64[Min32Direction].ystep;
			FeaturePointNow.NormTwo=Min32Direction;
			FeaturePointNow.NormTwoDis=ThrumTest64[Min32Direction].stepdistense;

		}
		FeaturePointNow.FeaturePointType=0xf0;
		return FeaturePointNow;

	}
   	return FeaturePointNow;
}
////////////////////////////////////////////////////////////////////////
//	函 数 名 ：bool DPSGII_FeaturePointSetSign(unsigned char* Img_sign,int nWidth,int nHeight,int R,FeaturePointInfo* FeaturePointNow)
//	函数功能 ：按指定点FeaturePointNow信息填充Img_sign图
//	作    者 ：朱宗晓
//	时    间 ：2012年09月09日
//	返 回 值 ： 特征点是否属于曲线特征点，1属于，0不属于
//	入口参数说明 ：
//	1.unsigned char* Img_bin：待计算的二值图
//  2.int nWidth: 二值图宽度
//  3.int nHeight: 二值图高度
//	4.int R：二值图采样半径
//  5.FeaturePointInfo* FeaturePointNow：指定点FeaturePointNow
////////////////////////////////////////////////////////////////////////
//	历史记录：
//	编号     日期    	作者    备注
//	0	2012年09月09日	朱宗晓	创建本函数
//	////////////////////////////////////////////////////////////////////////
bool DPSGII_FeaturePointSetSign(unsigned char* Img_sign,int nWidth,int nHeight,int R,FeaturePointInfo* FeaturePointNow)
{
	int x=0;
	int y=0;
	bool FeaturePointSign=false;
	int cenX=FeaturePointNow->FeaturePointPos.x;
	int cenY=FeaturePointNow->FeaturePointPos.y;
	int NormRadii=0;
	int startX=FeaturePointNow->ThrumStart.x;
	int startY=FeaturePointNow->ThrumStart.y;
	int startDir=FeaturePointNow->ShortDir;
	int endX=FeaturePointNow->ThrumEnd.x;
	int endY=FeaturePointNow->ThrumEnd.y;
	int endDir=FeaturePointNow->LongDir;
	int normOneDir=FeaturePointNow->NormOne;
	int normOneX=FeaturePointNow->PointNormOne.x;
	int normOneY=FeaturePointNow->PointNormOne.y;
	int normTwoDir=FeaturePointNow->NormTwo;
	int normTwoX=FeaturePointNow->PointNormTwo.x;
	int normTwoY=FeaturePointNow->PointNormTwo.y;
	switch(FeaturePointNow->FeaturePointType)
	{
	case 0xff:
		FeaturePointSign=false;
		NormRadii=int(FeaturePointNow->NormOneDis+0.5);
		for(y=cenY-NormRadii;y<cenY+NormRadii;y++)
		{
			/*if(((unsigned char*)(Img_sign + nWidth*y))[x]==0)
			{break;}*/
			for(x=cenX-NormRadii;x<cenX+NormRadii;x++)
			{
				/*if(((unsigned char*)(Img_sign + nWidth*y))[x]==0)
				{break;}
				else*/
				{((unsigned char*)(Img_sign + nWidth*y))[x]=0;}
			}
		}
		break;
	case 0xf0:
		FeaturePointSign=false;
		DPSGII_SetRegionValue(Img_sign,nWidth, nHeight,cenX,cenY,normOneX,normOneY,0);
		break;
	case 0xf:
		FeaturePointSign=false;
		 while(cenX!=endX||cenY!=endY)
		{
			((unsigned char*)(Img_sign + nWidth*cenY))[cenX]=0;
			cenX=cenX+g_oDistense64D[endDir].xstep*R;
			cenY=cenY+g_oDistense64D[endDir].ystep*R;

		 }
		break;
	case 0x1:
		 while(cenX!=endX||cenY!=endY)
		{
			((unsigned char*)(Img_sign + nWidth*cenY))[cenX]=0;
			((unsigned char*)(Img_sign + nWidth*normOneY))[normOneX]=0;
			((unsigned char*)(Img_sign + nWidth*normTwoY))[normTwoX]=0;
			cenX=cenX+g_oDistense64D[endDir].xstep*R;
			cenY=cenY+g_oDistense64D[endDir].ystep*R;
			normOneX=normOneX+g_oDistense64D[endDir].xstep*R;
			normOneY=normOneY+g_oDistense64D[endDir].ystep*R;
			normTwoX=normTwoX+g_oDistense64D[endDir].xstep*R;
			normTwoY=normTwoY+g_oDistense64D[endDir].ystep*R;
		}
		FeaturePointSign=true;
		break;
	case 0x2:
		//((unsigned char*)(Img_sign + nWidth*cenY))[cenX]=0;
	/*	 while(cenX!=endX||cenY!=endY)
		{*/
			//((unsigned char*)(Img_sign + nWidth*cenY))[cenX]=0;
			//((unsigned char*)(Img_sign + nWidth*normOneY))[normOneX]=0;
			//((unsigned char*)(Img_sign + nWidth*normTwoY))[normTwoX]=0;
		/*	cenX=cenX+g_oDistense64D[endDir].xstep*R;
			cenY=cenY+g_oDistense64D[endDir].ystep*R;
			normOneX=normOneX+g_oDistense64D[endDir].xstep*R;
			normOneY=normOneY+g_oDistense64D[endDir].ystep*R;
			normTwoX=normTwoX+g_oDistense64D[endDir].xstep*R;
			normTwoY=normTwoY+g_oDistense64D[endDir].ystep*R;*/
		//}
		FeaturePointSign=true;
		break;
	case 0x3:
		//((unsigned char*)(Img_sign + nWidth*cenY))[cenX]=0;
		FeaturePointSign=true;
		break;
	case 0x4:
		NormRadii=int(min(min(FeaturePointNow->NormOneDis,FeaturePointNow->NormTwoDis),FeaturePointNow->ShortDis)+0.5);
		for(y=cenY-NormRadii;y<cenY+NormRadii;y++)
		{
			for(x=cenX-NormRadii;x<cenX+NormRadii;x++)
			{
				((unsigned char*)(Img_sign + nWidth*y))[x]=0;
			}
		}

		FeaturePointSign=true;
		break;
	default:
		break;
	}

	
	return  FeaturePointSign;
}
bool DPSGII_FeaturePointBlockArea(unsigned char* Img_sign,int nWidth,int nHeight,int R,FeaturePointInfo* FeaturePointNow)
{
	int x=0;
	int y=0;
	bool FeaturePointSign=false;
	int cenX=FeaturePointNow->FeaturePointPos.x;
	int cenY=FeaturePointNow->FeaturePointPos.y;
	int NormRadii=0;
	int startX=FeaturePointNow->ThrumStart.x;
	int startY=FeaturePointNow->ThrumStart.y;
	int startDir=FeaturePointNow->ShortDir;
	int endX=FeaturePointNow->ThrumEnd.x;
	int endY=FeaturePointNow->ThrumEnd.y;
	int endDir=FeaturePointNow->LongDir;
	int normOneDir=FeaturePointNow->NormOne;
	int normOneX=FeaturePointNow->PointNormOne.x;
	int normOneY=FeaturePointNow->PointNormOne.y;
	int normTwoDir=FeaturePointNow->NormTwo;
	int normTwoX=FeaturePointNow->PointNormTwo.x;
	int normTwoY=FeaturePointNow->PointNormTwo.y;
	switch(FeaturePointNow->FeaturePointType)
	{
	case 0xff:
		FeaturePointSign=false;
		NormRadii=int(FeaturePointNow->NormOneDis+0.5);
		for(y=cenY-NormRadii;y<cenY+NormRadii;y++)
		{
			/*if(((unsigned char*)(Img_sign + nWidth*y))[x]==0)
			{break;}*/
			for(x=cenX-NormRadii;x<cenX+NormRadii;x++)
			{
				/*if(((unsigned char*)(Img_sign + nWidth*y))[x]==0)
				{break;}
				else*/
				{((unsigned char*)(Img_sign + nWidth*y))[x]=0;}
			}
		}
		break;
	case 0xf0:
		FeaturePointSign=false;
		DPSGII_SetRegionValue(Img_sign,nWidth, nHeight,cenX,cenY,normOneX,normOneY,0);
		break;
	case 0xf:
		FeaturePointSign=false;
		/* while(cenX!=endX||cenY!=endY)
		{
			((unsigned char*)(Img_sign + nWidth*cenY))[cenX]=0;
			cenX=cenX+g_oDistense64D[endDir].xstep*R;
			cenY=cenY+g_oDistense64D[endDir].ystep*R;

		 }*/
		break;
	case 0x1:
		((unsigned char*)(Img_sign + nWidth*cenY))[cenX]=250;
	/*	 while(cenX!=endX||cenY!=endY)
		{
			((unsigned char*)(Img_sign + nWidth*cenY))[cenX]=0;
			((unsigned char*)(Img_sign + nWidth*normOneY))[normOneX]=0;
			((unsigned char*)(Img_sign + nWidth*normTwoY))[normTwoX]=0;
			cenX=cenX+g_oDistense64D[endDir].xstep*R;
			cenY=cenY+g_oDistense64D[endDir].ystep*R;
			normOneX=normOneX+g_oDistense64D[endDir].xstep*R;
			normOneY=normOneY+g_oDistense64D[endDir].ystep*R;
			normTwoX=normTwoX+g_oDistense64D[endDir].xstep*R;
			normTwoY=normTwoY+g_oDistense64D[endDir].ystep*R;
		}*/
		FeaturePointSign=false;
		break;
	case 0x2:
		((unsigned char*)(Img_sign + nWidth*cenY))[cenX]=250;
	/*	 while(cenX!=endX||cenY!=endY)
		{*/
			//((unsigned char*)(Img_sign + nWidth*cenY))[cenX]=0;
			//((unsigned char*)(Img_sign + nWidth*normOneY))[normOneX]=0;
			//((unsigned char*)(Img_sign + nWidth*normTwoY))[normTwoX]=0;
		/*	cenX=cenX+g_oDistense64D[endDir].xstep*R;
			cenY=cenY+g_oDistense64D[endDir].ystep*R;
			normOneX=normOneX+g_oDistense64D[endDir].xstep*R;
			normOneY=normOneY+g_oDistense64D[endDir].ystep*R;
			normTwoX=normTwoX+g_oDistense64D[endDir].xstep*R;
			normTwoY=normTwoY+g_oDistense64D[endDir].ystep*R;*/
		//}
		FeaturePointSign=true;
		break;
	case 0x3:
		((unsigned char*)(Img_sign + nWidth*cenY))[cenX]=250;
		FeaturePointSign=false;
		break;
	case 0x4:
		((unsigned char*)(Img_sign + nWidth*cenY))[cenX]=250;
	/*	NormRadii=int(min(min(FeaturePointNow->NormOneDis,FeaturePointNow->NormTwoDis),FeaturePointNow->ShortDis)+0.5);
		for(y=cenY-NormRadii;y<cenY+NormRadii;y++)
		{
			for(x=cenX-NormRadii;x<cenX+NormRadii;x++)
			{
				((unsigned char*)(Img_sign + nWidth*y))[x]=0;
			}
		}*/

		FeaturePointSign=false;
		break;
	default:
		break;
	}

	/*if(FeaturePointNow->FeaturePointType==2)
	{
		return true;
	}
	else 
	{
		return false;
	}*/
	return  FeaturePointSign;
}
////////////////////////////////////////////////////////////////////////
//	函 数 名 ：bool DPSGII_FeaturePointShieldSign(unsigned char* Img_sign,int nWidth,int nHeight,int R,FeaturePointInfo* FeaturePointNow)
//	函数功能 ：按指定点FeaturePointNow信息填充Img_sign图
//	作    者 ：朱宗晓
//	时    间 ：2012年09月09日
//	返 回 值 ： 特征点是否属于曲线特征点，1属于，0不属于
//	入口参数说明 ：
//	1.unsigned char* Img_bin：待计算的二值图
//  2.int nWidth: 二值图宽度
//  3.int nHeight: 二值图高度
//	4.int R：二值图采样半径
//  5.FeaturePointInfo* FeaturePointNow：指定点FeaturePointNow
////////////////////////////////////////////////////////////////////////
//	历史记录：
//	编号     日期    	作者    备注
//	0	2012年09月09日	朱宗晓	创建本函数
bool DPSGII_FeaturePointShieldSign(unsigned char* Img_sign,int nWidth,int nHeight,int R,FeaturePointInfo* FeaturePointNow)
{
	int x=0;
	int y=0;
	bool FeaturePointSign=false;
	int cenX=FeaturePointNow->FeaturePointPos.x;
	int cenY=FeaturePointNow->FeaturePointPos.y;
	int NormRadii=0;
	int startX=FeaturePointNow->ThrumStart.x;
	int startY=FeaturePointNow->ThrumStart.y;
	int startDir=FeaturePointNow->ShortDir;
	int endX=FeaturePointNow->ThrumEnd.x;
	int endY=FeaturePointNow->ThrumEnd.y;
	int endDir=FeaturePointNow->LongDir;
	int normOneDir=FeaturePointNow->NormOne;
	int normOneX=FeaturePointNow->PointNormOne.x;
	int normOneY=FeaturePointNow->PointNormOne.y;
	int normTwoDir=FeaturePointNow->NormTwo;
	int normTwoX=FeaturePointNow->PointNormTwo.x;
	int normTwoY=FeaturePointNow->PointNormTwo.y;
	switch(FeaturePointNow->FeaturePointType)
	{
	case 0xff:
		FeaturePointSign=false;
		NormRadii=int(FeaturePointNow->NormOneDis+0.5);
		for(y=cenY-NormRadii;y<cenY+NormRadii;y++)
		{
			for(x=cenX-NormRadii;x<cenX+NormRadii;x++)
			{
				{((unsigned char*)(Img_sign + nWidth*y))[x]=0;}
			}
		}
		break;
	case 0xf0:
		FeaturePointSign=false;
		DPSGII_SetRegionValue(Img_sign,nWidth, nHeight,cenX,cenY,normOneX,normOneY,0);
		break;
	
	default:
		break;
	}
	return  FeaturePointSign;
}
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
int DPSGII_FeaturePointSearch(unsigned char* Img_bin,unsigned char* Img_sign,int nWidth,int nHeight,int Rin,int Rout,int NormThre)
{
	 int y=0;
     int x=0;
	 int i=0;
	 FeaturePointNum=0;
	 bool FeaturePointSign=false;
	 int AdnateNum=0;
	// StepStrucureII RectDistriTemp; 
	 memset(FeaturePoint,0,CURVEMAXNUM*sizeof(FeaturePointInfo));//清空CurveGroup[CURVEMAXNUM]
	 for(y=(int)Rout;y<nHeight-Rout;y+=Rin)
	{
		for(x=(int)Rout;x<nWidth-Rout;x+=Rin)
		{
			if(FeaturePointNum==CURVEMAXNUM)
			{break;}
			FeaturePointSign=false;
			//DPSGII_DPAdnate8Check(Img_bin,nWidth,nHeight,x,y,Rin);//counter point in background
			if((((unsigned char*)(Img_bin + nWidth*y))[x]==0)&&(DPSGII_DPAdnate8Check(Img_bin,nWidth,nHeight,x,y,Rin)>=2)
				&&(((unsigned char*)(Img_sign + nWidth*y))[x]==255)&&(DPSGII_DPSignCheck(Img_sign,nWidth,nHeight,x,y,(Rin<<2))))
			 {
				  FeaturePoint[FeaturePointNum]=DPSGII_FeaturePointSearch64D(Img_bin,nWidth,nHeight,x,y,Rin,Rout,NormThre);
				  FeaturePointSign=DPSGII_FeaturePointSetSign(Img_sign,nWidth,nHeight,Rin,&FeaturePoint[FeaturePointNum]);
	              FeaturePointNum+=FeaturePointSign;	
			}
		}
	 }
	 return  FeaturePointNum;
}
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
void DPSGII_FeaturePointSearchShield(unsigned char* Img_bin,unsigned char* Img_sign,int nWidth,int nHeight,int Rin,int Rout,int NormThre)
{
	 int y=0;
     int x=0;
	 int i=0;
	 FeaturePointNum=0;
	 bool FeaturePointSign=false;
	 int AdnateNum=0;
	// StepStrucureII RectDistriTemp; 
	 memset(FeaturePoint,0,CURVEMAXNUM*sizeof(FeaturePointInfo));//清空CurveGroup[CURVEMAXNUM]
	 for(y=(int)Rout;y<nHeight-Rout;y+=Rin)
	{
		for(x=(int)Rout;x<nWidth-Rout;x+=Rin)
		{
			FeaturePointSign=false;
			if((((unsigned char*)(Img_bin + nWidth*y))[x]==0)&&(DPSGII_DPAdnate8Check(Img_bin,nWidth,nHeight,x,y,Rin)>=2)
				&&(((unsigned char*)(Img_sign + nWidth*y))[x]==255)&&(DPSGII_DPSignCheck(Img_sign,nWidth,nHeight,x,y,(Rin<<2))))
			 {
				  FeaturePoint[FeaturePointNum]=DPSGII_FeaturePointShield(Img_bin,nWidth,nHeight,x,y,Rin,Rout,NormThre);
				  FeaturePointSign=DPSGII_FeaturePointShieldSign(Img_sign,nWidth,nHeight,Rin,&FeaturePoint[FeaturePointNum]);
	              //FeaturePointNum+=FeaturePointSign;	
			}
		}
	 }
}
void StepStrucureQuickSort(StepStrucureII * Level,int Left,int Right, int Index,int Usednum)
{
	int i,j;
	
	double pivot;//分隔指针
	int pivotads=0;//分割位置v
	i=Left;	j=Right+1;//设置i,j分别为数组的左右指针
	StepStrucureII TempDistance;
	pivot=Level[Left].stepdistense;
	if(i<j)
	{ do
		{
			/*从左往右找比pivot大的值*/
			do
			{i++;
			}while(Level[i].stepdistense<pivot&&i<=Right);
            /*从右往左找比pivot小的值*/
			do
			{j--;
			}while(Level[j].stepdistense>pivot&&j>Left);
			if(i<j)
			{
				    TempDistance.stepdistense=Level[i].stepdistense;
					Level[i].stepdistense=Level[j].stepdistense;
					Level[j].stepdistense=TempDistance.stepdistense;
					TempDistance.xstep=Level[i].xstep;
					Level[i].xstep=Level[j].xstep;
					Level[j].xstep=TempDistance.xstep;
					TempDistance.ystep=Level[i].ystep;
					Level[i].ystep=Level[j].ystep;
					Level[j].ystep=TempDistance.ystep;
			}
		}while(i<j);
		 TempDistance.stepdistense=Level[Left].stepdistense;
		 Level[Left].stepdistense=Level[j].stepdistense;
		 Level[j].stepdistense=TempDistance.stepdistense;
		 TempDistance.xstep=Level[Left].xstep;
		 Level[Left].xstep=Level[j].xstep;
		 Level[j].xstep=TempDistance.xstep;
		 TempDistance.ystep=Level[Left].ystep;
		 Level[Left].ystep=Level[j].ystep;
		 Level[j].ystep=TempDistance.ystep;
		 if(j+1-Left>Usednum)
		 {
	//		 QuickSort(Level,Left,j-1,j,Usednum);
			StepStrucureQuickSort(Level,Left,j-1,Index,Usednum);
		 }//排序左半边
		 else if(j+1-Left==Usednum)
	//	 {QuickSort(Level,Left,j-1,j,Usednum-1);}
	     {StepStrucureQuickSort(Level,Left,j-1,Index,Usednum-1);}
		 else 
		 {
           //  QuickSort(Level,Left,j-1,j,j);//排序左半边
			  StepStrucureQuickSort(Level,Left,j-1,Index,j);
			 StepStrucureQuickSort(Level,j+1,Right,Index,Usednum-(j+1-Left));//排序右半边
		 }
		 
//		  QuickSort(Level,Left,j-1,Index,Usednum);
//		   QuickSort(Level,j+1,Right,Index,Usednum);
		
        
	}
}
////////////////////////////////////////////////////////////////////////
//	函 数 名 ：int CopyLineFromCurve()
//	函数功能 ：共线直线判断
//	作    者 ：朱宗晓
//	时    间 ：2012年09月19日
//	返 回 值 ： 共线直线条数
//	入口参数说明 ：
////////////////////////////////////////////////////////////////////////
//	历史记录：
//	编号     日期    	作者    备注
//	0	2012年09月19日	朱宗晓	创建本函数
//	////////////////////////////////////////////////////////////////////////
//int CopyLineFromCurve()
//{
//	LineNum=0;
//	int i=0;
//	int j=0;
//	CGPOINT PStart ;
//	CGPOINT PEnd ;
//	CGPOINT PStartII;
//	CGPOINT PEndII;
//	double LineDis;
//	double MinDis=10000.0;
//	int DisType=0;
//	LINE CoLine;
//	
//	double CoLineAngle=0.0;
//	ConLineNum=0;
//	if(CurveNum>0&&CurveNum<CURVEMAXNUM)
//	{
//		for(i=0;i<CurveNum;i++)
//		{
//			if(CurveGroup[i].Curvetype==1)
//			{
//				PStart.x=CurveGroup[i].CurveStart.x;
//				PStart.y=CurveGroup[i].CurveStart.y;
//				PEnd.x=CurveGroup[i].CurveEnd.x;
//				PEnd.y=CurveGroup[i].CurveEnd.y;
//				LineGroup[i]=makeline(PStart,PEnd);
//				LinePara[LineNum].xstep=i;
//				LinePara[LineNum].ystep=LineNum;
//				LinePara[LineNum].stepdistense=180-alpha(LineGroup[i])*180/PI;
//				//TRACE(_T("NO.%dCurve is LineSeg%d,Start[%d,%d],End[%d,%d],ALPHA%f,CurveDire%f\n"),LinePara[LineNum].xstep,LinePara[LineNum].ystep,CurveGroup[i].CurveStart.x,CurveGroup[i].CurveStart.y,CurveGroup[i].CurveEnd.x,CurveGroup[i].CurveEnd.y,LinePara[LineNum].stepdistense);
//				LineNum++;
//				if(LineNum==LINENUM)
//				{break;}
//
//			}
//
//		}
//		StepStrucureQuickSort(LinePara,0,LineNum-1,LineNum,LineNum);
//	
//		for(i=0;i<LineNum;i++)
//		{
//			
//			//TRACE(_T("NO.%dCurve is LineSeg%d,ALPHA%f\n"),LinePara[i].xstep,LinePara[i].ystep,LinePara[i].stepdistense);
//			j=i+1;
//			while(abs(LinePara[j].stepdistense-LinePara[i].stepdistense)<COLINEANGLE)
//			{
//				MinDis=10000.0;
//				PStart.x=CurveGroup[LinePara[i].xstep].CurveStart.x;
//				PStart.y=CurveGroup[LinePara[i].xstep].CurveStart.y;
//				PEnd.x=CurveGroup[LinePara[i].xstep].CurveEnd.x;
//				PEnd.y=CurveGroup[LinePara[i].xstep].CurveEnd.y;
//				PStartII.x=CurveGroup[LinePara[j].xstep].CurveStart.x;
//				PStartII.y=CurveGroup[LinePara[j].xstep].CurveStart.y;
//				PEndII.x=CurveGroup[LinePara[j].xstep].CurveEnd.x;
//				PEndII.y=CurveGroup[LinePara[j].xstep].CurveEnd.y;
//				LineDis=dist(PStart,PStartII);
//				if(LineDis<MinDis)
//				{
//                     MinDis=LineDis;
//					 DisType=1;
//				}
//				LineDis=dist(PStart,PEndII);
//				if(LineDis<MinDis)
//				{
//                     MinDis=LineDis;
//					 DisType=2;
//				}
//				LineDis=dist(PEnd,PStartII);
//				if(LineDis<MinDis)
//				{
//                     MinDis=LineDis;
//					 DisType=3;
//				}
//				LineDis=dist(PEnd,PEndII);
//				if(LineDis<MinDis)
//				{
//                     MinDis=LineDis;
//					 DisType=4;
//				}
//	            switch(DisType)
//				{
//				case 1://大头二头，二头不变，二尾变大头
//				PEndII.x=CurveGroup[LinePara[i].xstep].CurveStart.x;
//				PEndII.y=CurveGroup[LinePara[i].xstep].CurveStart.y;
//				break;
//				case 2://大头二尾，二尾不变，二头变大头
//				PStartII.x=CurveGroup[LinePara[i].xstep].CurveStart.x;
//				PStartII.y=CurveGroup[LinePara[i].xstep].CurveStart.y;
//				break;
//				case 3://大尾二头，二头不变，二尾变大尾
//				PEndII.x=CurveGroup[LinePara[i].xstep].CurveEnd.x;
//				PEndII.y=CurveGroup[LinePara[i].xstep].CurveEnd.y;
//				break;
//				case 4://大尾二尾，二尾不变，二头变大尾
//				PStartII.x=CurveGroup[LinePara[i].xstep].CurveEnd.x;
//				PStartII.y=CurveGroup[LinePara[i].xstep].CurveEnd.y;
//				break;
//
//				}
//	            CoLine=makeline(PStartII,PEndII);
//				CoLineAngle=180-alpha(CoLine)*180/PI;
//				if(MinDis<COLINEDIS&&abs(LinePara[i].stepdistense-CoLineAngle)<COLINEANGLE&&abs(CoLineAngle-LinePara[j].stepdistense)<COLINEANGLE)
//				{
//					
//					LineConnect[ConLineNum].ThrumStart.x=PStartII.x+0.5;
//					LineConnect[ConLineNum].ThrumStart.y=PStartII.y+0.5;
//					LineConnect[ConLineNum].ThrumEnd.x=PEndII.x+0.5;
//					LineConnect[ConLineNum].ThrumEnd.y=PEndII.y+0.5;
//					LineConnect[ConLineNum].ThrumDire=LinePara[i].xstep;
//					LineConnect[ConLineNum].ThrumCurveSeq=LinePara[j].xstep;
//					LineConnect[ConLineNum].ThrumDist=dist(PStartII,PEndII);
//					TRACE(_T("NO.%dCurve and NO.%dCurve should be connected with Dist%f!\n"),LinePara[i].xstep,LinePara[j].xstep,LineConnect[ConLineNum].ThrumDist);
//					ConLineNum++;
//					if(ConLineNum>1)
//					{
//						if((LineConnect[ConLineNum-1].ThrumStart.x==LineConnect[ConLineNum-2].ThrumStart.x)&&(LineConnect[ConLineNum-1].ThrumStart.y==LineConnect[ConLineNum-2].ThrumStart.y)
//							||(LineConnect[ConLineNum-1].ThrumEnd.x==LineConnect[ConLineNum-2].ThrumEnd.x)&&(LineConnect[ConLineNum-1].ThrumEnd.y==LineConnect[ConLineNum-2].ThrumEnd.y)
//							||(LineConnect[ConLineNum-1].ThrumStart.x==LineConnect[ConLineNum-2].ThrumEnd.x)&&(LineConnect[ConLineNum-1].ThrumStart.y==LineConnect[ConLineNum-2].ThrumEnd.y)
//							||(LineConnect[ConLineNum-1].ThrumEnd.x==LineConnect[ConLineNum-2].ThrumStart.x)&&(LineConnect[ConLineNum-1].ThrumEnd.y==LineConnect[ConLineNum-2].ThrumStart.y))
//						{
//							if(LineConnect[ConLineNum-1].ThrumDist<LineConnect[ConLineNum-2].ThrumDist)
//							{
//								LineConnect[ConLineNum-2].ThrumStart.x=LineConnect[ConLineNum-1].ThrumStart.x;
//								LineConnect[ConLineNum-2].ThrumStart.y=LineConnect[ConLineNum-1].ThrumStart.y;
//								LineConnect[ConLineNum-2].ThrumEnd.x=LineConnect[ConLineNum-1].ThrumEnd.x;
//								LineConnect[ConLineNum-2].ThrumEnd.y=LineConnect[ConLineNum-1].ThrumEnd.y;
//								LineConnect[ConLineNum-2].ThrumDire=LineConnect[ConLineNum-1].ThrumDire;
//								LineConnect[ConLineNum-2].ThrumCurveSeq=LineConnect[ConLineNum-1].ThrumCurveSeq;
//								LineConnect[ConLineNum-2].ThrumDist=LineConnect[ConLineNum-1].ThrumDist;
//							}
//							ConLineNum--;
//						}
//					}
//				}
//
//				j++;
//			}
//			//i=j;
//		
//				
//
//		}
//
//
//	}
//	return ConLineNum;
//
//}
int CopyLineFromCurve()
{
	LineNum=0;
	int i=0;
	int j=0;
	CGPOINT PStart ;
	CGPOINT PEnd ;
	CGPOINT PStartII;
	CGPOINT PEndII;
	double LineDis;
	double MinDis=10000.0;
	int DisType=0;
	LINE CoLine;
	
	double CoLineAngle=0.0;
	ConLineNum=0;
	if(CurveNum>0&&CurveNum<CURVEMAXNUM)
	{
		for(i=0;i<CurveNum;i++)
		{
			if(CurveGroup[i].Curvetype==1)
			{
				PStart.x=CurveGroup[i].CurveStart.x;
				PStart.y=CurveGroup[i].CurveStart.y;
				PEnd.x=CurveGroup[i].CurveEnd.x;
				PEnd.y=CurveGroup[i].CurveEnd.y;
				LineGroup[i]=makeline(PStart,PEnd);
				LinePara[LineNum].xstep=i;
				LinePara[LineNum].ystep=LineNum;
				LinePara[LineNum].stepdistense=180-alpha(LineGroup[i])*180/PI;
				//TRACE(_T("NO.%dCurve is LineSeg%d,Start[%d,%d],End[%d,%d],ALPHA%f,CurveDire%f\n"),LinePara[LineNum].xstep,LinePara[LineNum].ystep,CurveGroup[i].CurveStart.x,CurveGroup[i].CurveStart.y,CurveGroup[i].CurveEnd.x,CurveGroup[i].CurveEnd.y,LinePara[LineNum].stepdistense);
				LineNum++;
				if(LineNum==LINENUM)
				{break;}

			}

		}
		StepStrucureQuickSort(LinePara,0,LineNum-1,LineNum,LineNum);
	
		for(i=0;i<LineNum;i++)
		{
			
			//TRACE(_T("NO.%dCurve is LineSeg%d,ALPHA%f\n"),LinePara[i].xstep,LinePara[i].ystep,LinePara[i].stepdistense);
			j=i+1;
			while(abs(LinePara[j].stepdistense-LinePara[i].stepdistense)<COLINEANGLE)
			{
				MinDis=10000.0;
				PStart.x=CurveGroup[LinePara[i].xstep].CurveStart.x;
				PStart.y=CurveGroup[LinePara[i].xstep].CurveStart.y;
				PEnd.x=CurveGroup[LinePara[i].xstep].CurveEnd.x;
				PEnd.y=CurveGroup[LinePara[i].xstep].CurveEnd.y;
				PStartII.x=CurveGroup[LinePara[j].xstep].CurveStart.x;
				PStartII.y=CurveGroup[LinePara[j].xstep].CurveStart.y;
				PEndII.x=CurveGroup[LinePara[j].xstep].CurveEnd.x;
				PEndII.y=CurveGroup[LinePara[j].xstep].CurveEnd.y;
				LineDis=dist(PStart,PStartII);
				if(LineDis<MinDis)
				{
                     MinDis=LineDis;
					 DisType=1;
				}
				LineDis=dist(PStart,PEndII);
				if(LineDis<MinDis)
				{
                     MinDis=LineDis;
					 DisType=2;
				}
				LineDis=dist(PEnd,PStartII);
				if(LineDis<MinDis)
				{
                     MinDis=LineDis;
					 DisType=3;
				}
				LineDis=dist(PEnd,PEndII);
				if(LineDis<MinDis)
				{
                     MinDis=LineDis;
					 DisType=4;
				}
	            switch(DisType)//PStart-PEnd:远点;PStartII-PEndII:近点
				{
				case 1://大头二头，二头不变，二尾变大头
				PStart.x=PEndII.x;
				PStart.y=PEndII.y;
				PEndII.x=CurveGroup[LinePara[i].xstep].CurveStart.x;
				PEndII.y=CurveGroup[LinePara[i].xstep].CurveStart.y;
				break;
				case 2://大头二尾，二尾不变，二头变大头
                PStart.x=PStartII.x;
				PStart.y=PStartII.y;
				PStartII.x=CurveGroup[LinePara[i].xstep].CurveStart.x;
				PStartII.y=CurveGroup[LinePara[i].xstep].CurveStart.y;
				break;
				case 3://大尾二头，二头不变，二尾变大尾
				PEnd.x=PEndII.x;
				PEnd.y=PEndII.y;
				PEndII.x=CurveGroup[LinePara[i].xstep].CurveEnd.x;
				PEndII.y=CurveGroup[LinePara[i].xstep].CurveEnd.y;
				break;
				case 4://大尾二尾，二尾不变，二头变大尾
                PEnd.x=PStartII.x;
				PEnd.y=PStartII.y;
				PStartII.x=CurveGroup[LinePara[i].xstep].CurveEnd.x;
				PStartII.y=CurveGroup[LinePara[i].xstep].CurveEnd.y;
				break;

				}
				TRACE(_T("i=%d,j=%d,PStart[%d,%d],PEnd[%d,%d],PStart[%d,%d],PEnd[%d,%d]\n"),i,j,(int)PStart.x,(int)PStart.y,(int)PEnd.x,(int)PEnd.y,(int)PStartII.x,(int)PStartII.y,(int)PEndII.x,(int)PEndII.y);
				//CoLine=makeline(PStartII,PEndII);
	           //CoLine=makeline(PStart,PEnd);
				CoLineAngle=180-alpha(CoLine)*180/PI;
				if(MinDis<COLINEDIS&&abs(LinePara[i].stepdistense-CoLineAngle)<COLINEANGLE&&abs(CoLineAngle-LinePara[j].stepdistense)<COLINEANGLE)
				{
					
					LineConnect[ConLineNum].ThrumStart.x=PStartII.x+0.5;
					LineConnect[ConLineNum].ThrumStart.y=PStartII.y+0.5;
					LineConnect[ConLineNum].ThrumEnd.x=PEndII.x+0.5;
					LineConnect[ConLineNum].ThrumEnd.y=PEndII.y+0.5;
					LineConnect[ConLineNum].ThrumDire=LinePara[i].xstep;
					LineConnect[ConLineNum].ThrumCurveSeq=LinePara[j].xstep;
					LineConnect[ConLineNum].ThrumDist=dist(PStartII,PEndII);
					TRACE(_T("NO.%dCurve and NO.%dCurve should be connected with Dist%f!\n"),LinePara[i].xstep,LinePara[j].xstep,LineConnect[ConLineNum].ThrumDist);
					ConLineNum++;
					if(ConLineNum>1)
					{
						if((LineConnect[ConLineNum-1].ThrumStart.x==LineConnect[ConLineNum-2].ThrumStart.x)&&(LineConnect[ConLineNum-1].ThrumStart.y==LineConnect[ConLineNum-2].ThrumStart.y)
							||(LineConnect[ConLineNum-1].ThrumEnd.x==LineConnect[ConLineNum-2].ThrumEnd.x)&&(LineConnect[ConLineNum-1].ThrumEnd.y==LineConnect[ConLineNum-2].ThrumEnd.y)
							||(LineConnect[ConLineNum-1].ThrumStart.x==LineConnect[ConLineNum-2].ThrumEnd.x)&&(LineConnect[ConLineNum-1].ThrumStart.y==LineConnect[ConLineNum-2].ThrumEnd.y)
							||(LineConnect[ConLineNum-1].ThrumEnd.x==LineConnect[ConLineNum-2].ThrumStart.x)&&(LineConnect[ConLineNum-1].ThrumEnd.y==LineConnect[ConLineNum-2].ThrumStart.y))
						{
							if(LineConnect[ConLineNum-1].ThrumDist<LineConnect[ConLineNum-2].ThrumDist)
							{
								LineConnect[ConLineNum-2].ThrumStart.x=LineConnect[ConLineNum-1].ThrumStart.x;
								LineConnect[ConLineNum-2].ThrumStart.y=LineConnect[ConLineNum-1].ThrumStart.y;
								LineConnect[ConLineNum-2].ThrumEnd.x=LineConnect[ConLineNum-1].ThrumEnd.x;
								LineConnect[ConLineNum-2].ThrumEnd.y=LineConnect[ConLineNum-1].ThrumEnd.y;
								LineConnect[ConLineNum-2].ThrumDire=LineConnect[ConLineNum-1].ThrumDire;
								LineConnect[ConLineNum-2].ThrumCurveSeq=LineConnect[ConLineNum-1].ThrumCurveSeq;
								LineConnect[ConLineNum-2].ThrumDist=LineConnect[ConLineNum-1].ThrumDist;
							}
							ConLineNum--;
						}
					}
				}

				j++;
			}
			//i=j;
		
				

		}


	}
	return ConLineNum;

}
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
int StraightLineInfo()
{
	LineNum=0;
	int i=0;
	int j=0;
	CGPOINT PStart ;
	CGPOINT PEnd ;
	CGPOINT PStartII;
	CGPOINT PEndII;
	double LineDis;
	double LineStartDis;
	double LineEndDis;
	double MinDis=10000.0;
	double FarDis=0.0;//远点距离
	double NearDis=0.0;//近点距离
	int DisType=0;
	LINE CoLine;
	LINE CoLineII;
	
	double CoLineAngle=0.0;
	double CoLineAngleII=0.0;
	ConLineNum=0;
	ParallelLineNum=0;
	if(CurveNum>0&&CurveNum<CURVEMAXNUM)
	{
		for(i=0;i<CurveNum;i++)
		{
			if(CurveGroup[i].Curvetype==1)
			{
				PStart.x=CurveGroup[i].CurveStart.x;
				PStart.y=CurveGroup[i].CurveStart.y;
				PEnd.x=CurveGroup[i].CurveEnd.x;
				PEnd.y=CurveGroup[i].CurveEnd.y;
				LineGroup[LineNum]=makeline(PStart,PEnd);
				LineSegGroup[LineNum]=LINESEG(PStart,PEnd);
				LinePara[LineNum].xstep=i;//曲线号
				LinePara[LineNum].ystep=LineNum;
				LinePara[LineNum].stepdistense=180-alpha(LineGroup[LineNum])*180/PI;
				//TRACE(_T("NO.%dCurve is LineSeg%d,Start[%d,%d],End[%d,%d],ALPHA%f,CurveDire%f\n"),LinePara[LineNum].xstep,LinePara[LineNum].ystep,CurveGroup[i].CurveStart.x,CurveGroup[i].CurveStart.y,CurveGroup[i].CurveEnd.x,CurveGroup[i].CurveEnd.y,LinePara[LineNum].stepdistense);
				LineNum++;
				if(LineNum==LINENUM)
				{break;}

			}

		}
		StepStrucureQuickSort(LinePara,0,LineNum-1,LineNum,LineNum);
	
		for(i=0;i<LineNum;i++)
		{
			
			//TRACE(_T("NO.%dCurve is LineSeg%d,ALPHA%f\n"),LinePara[i].xstep,LinePara[i].ystep,LinePara[i].stepdistense);
			j=i+1;
			while(abs(LinePara[j].stepdistense-LinePara[i].stepdistense)<COLINEANGLE)
			{
				MinDis=10000.0;
				PStart.x=CurveGroup[LinePara[i].xstep].CurveStart.x;
				PStart.y=CurveGroup[LinePara[i].xstep].CurveStart.y;
				PEnd.x=CurveGroup[LinePara[i].xstep].CurveEnd.x;
				PEnd.y=CurveGroup[LinePara[i].xstep].CurveEnd.y;
				PStartII.x=CurveGroup[LinePara[j].xstep].CurveStart.x;
				PStartII.y=CurveGroup[LinePara[j].xstep].CurveStart.y;
				PEndII.x=CurveGroup[LinePara[j].xstep].CurveEnd.x;
				PEndII.y=CurveGroup[LinePara[j].xstep].CurveEnd.y;
				LineStartDis=ptoldist(PStartII,LineSegGroup[LinePara[i].ystep]);
				LineEndDis=ptoldist(PEndII,LineSegGroup[LinePara[i].ystep]);
				FarDis=max(LineStartDis,LineEndDis);
				NearDis=min(LineStartDis,LineEndDis);
				if(FarDis<PARALLELDIS)
				{
					
				
					LineDis=dist(PStart,PStartII);
					if(LineDis<MinDis)
					{
						 MinDis=LineDis;
						 DisType=1;
					}
					LineDis=dist(PStart,PEndII);
					if(LineDis<MinDis)
					{
						 MinDis=LineDis;
						 DisType=2;
					}
					LineDis=dist(PEnd,PStartII);
					if(LineDis<MinDis)
					{
						 MinDis=LineDis;
						 DisType=3;
					}
					LineDis=dist(PEnd,PEndII);
					if(LineDis<MinDis)
					{
						 MinDis=LineDis;
						 DisType=4;
					}
				 switch(DisType)//PStart-PEnd:远点;PStartII-PEndII:近点
				{
				case 1://大头二头，二头不变，二尾变大头
				PStart.x=PEndII.x;
				PStart.y=PEndII.y;
				PEndII.x=CurveGroup[LinePara[i].xstep].CurveStart.x;
				PEndII.y=CurveGroup[LinePara[i].xstep].CurveStart.y;
				break;
				case 2://大头二尾，二尾不变，二头变大头
                PStart.x=PStartII.x;
				PStart.y=PStartII.y;
				PStartII.x=CurveGroup[LinePara[i].xstep].CurveStart.x;
				PStartII.y=CurveGroup[LinePara[i].xstep].CurveStart.y;
				break;
				case 3://大尾二头，二头不变，二尾变大尾
				PEnd.x=PEndII.x;
				PEnd.y=PEndII.y;
				PEndII.x=CurveGroup[LinePara[i].xstep].CurveEnd.x;
				PEndII.y=CurveGroup[LinePara[i].xstep].CurveEnd.y;
				break;
				case 4://大尾二尾，二尾不变，二头变大尾
                PEnd.x=PStartII.x;
				PEnd.y=PStartII.y;
				PStartII.x=CurveGroup[LinePara[i].xstep].CurveEnd.x;
				PStartII.y=CurveGroup[LinePara[i].xstep].CurveEnd.y;
				break;

				}
				
				CoLine=makeline(PStart,PEnd);
				CoLineII=makeline(PStartII,PEndII);
				CoLineAngle=180-alpha(CoLine)*180/PI;
				CoLineAngleII=180-alpha(CoLineII)*180/PI;
				
				//TRACE(_T("Curve I=%d,Angle=%f,CurveII=%d,AngleII=%f,CoLineAngle=%f,CoLineAngleII=%f\n"),LinePara[j].xstep,LinePara[j].stepdistense,LinePara[i].xstep,LinePara[i].stepdistense,CoLineAngle,CoLineAngleII);
				TRACE(_T("%d,%d,%f,%f,%f,%f\n"),LinePara[j].xstep,LinePara[i].xstep,LinePara[j].stepdistense,LinePara[i].stepdistense,CoLineAngle,CoLineAngleII);
				//TRACE(_T("PStart[%d,%d],PEnd[%d,%d],PStartII[%d,%d],PEndII[%d,%d]\n"),(int)PStart.x,(int)PStart.y,(int)PEnd.x,(int)PEnd.y,(int)PStartII.x,(int)PStartII.y,(int)PEndII.x,(int)PEndII.y);

					//CoLineAngle=180-alpha(CoLine)*180/PI;
					if(MinDis<0.1)
					{
						TRACE(_T("NO.%dCurve's StartPoint[%d,%d] near NO.%dCurve with dist=%f\n"),LinePara[j].xstep,(int)PStartII.x,(int)PStartII.y,LinePara[i].xstep,LineStartDis);
						TRACE(_T("NO.%dCurve's EndPoint[%d,%d] near NO.%dCurve with dist=%f\n"),LinePara[j].xstep,(int)PEndII.x,(int)PEndII.y,LinePara[i].xstep,LineEndDis);

					}
					if(MinDis>0.1&&MinDis<COLINEDIS&&abs(LinePara[i].stepdistense-CoLineAngle)<COLINEANGLE&&abs(CoLineAngle-LinePara[j].stepdistense)<COLINEANGLE&&abs(LinePara[i].stepdistense-CoLineAngleII)<COLINEANGLE&&abs(CoLineAngleII-LinePara[j].stepdistense)<COLINEANGLE)
					//if(MinDis>0.1&&MinDis<COLINEDIS&&CoLineAngle<COLINEANGLE)
					{
					
						LineConnect[ConLineNum].ThrumStart.x=PStartII.x+0.5;
						LineConnect[ConLineNum].ThrumStart.y=PStartII.y+0.5;
						LineConnect[ConLineNum].ThrumEnd.x=PEndII.x+0.5;
						LineConnect[ConLineNum].ThrumEnd.y=PEndII.y+0.5;
						LineConnect[ConLineNum].ThrumDire=LinePara[i].xstep;
						LineConnect[ConLineNum].ThrumCurveSeq=LinePara[j].xstep;
						LineConnect[ConLineNum].ThrumDist=dist(PStartII,PEndII);
						LineConnect[ConLineNum].ThrumNormdis=0.0;
						LineConnect[ConLineNum].ThrumHisDire=DisType;
						//TRACE(_T("NO.%dCurve and NO.%dCurve should be connected with Dist%f!\n"),LinePara[i].xstep,LinePara[j].xstep,LineConnect[ConLineNum].ThrumDist);
						ConLineNum++;

						if(ConLineNum>1)
						{
							if((LineConnect[ConLineNum-1].ThrumStart.x==LineConnect[ConLineNum-2].ThrumStart.x)&&(LineConnect[ConLineNum-1].ThrumStart.y==LineConnect[ConLineNum-2].ThrumStart.y)
								||(LineConnect[ConLineNum-1].ThrumEnd.x==LineConnect[ConLineNum-2].ThrumEnd.x)&&(LineConnect[ConLineNum-1].ThrumEnd.y==LineConnect[ConLineNum-2].ThrumEnd.y)
								||(LineConnect[ConLineNum-1].ThrumStart.x==LineConnect[ConLineNum-2].ThrumEnd.x)&&(LineConnect[ConLineNum-1].ThrumStart.y==LineConnect[ConLineNum-2].ThrumEnd.y)
								||(LineConnect[ConLineNum-1].ThrumEnd.x==LineConnect[ConLineNum-2].ThrumStart.x)&&(LineConnect[ConLineNum-1].ThrumEnd.y==LineConnect[ConLineNum-2].ThrumStart.y))
							{
								if(LineConnect[ConLineNum-1].ThrumDist<LineConnect[ConLineNum-2].ThrumDist)
								{
									LineConnect[ConLineNum-2].ThrumStart.x=LineConnect[ConLineNum-1].ThrumStart.x;
									LineConnect[ConLineNum-2].ThrumStart.y=LineConnect[ConLineNum-1].ThrumStart.y;
									LineConnect[ConLineNum-2].ThrumEnd.x=LineConnect[ConLineNum-1].ThrumEnd.x;
									LineConnect[ConLineNum-2].ThrumEnd.y=LineConnect[ConLineNum-1].ThrumEnd.y;
									LineConnect[ConLineNum-2].ThrumDire=LineConnect[ConLineNum-1].ThrumDire;
									LineConnect[ConLineNum-2].ThrumCurveSeq=LineConnect[ConLineNum-1].ThrumCurveSeq;
									LineConnect[ConLineNum-2].ThrumDist=LineConnect[ConLineNum-1].ThrumDist;
									LineConnect[ConLineNum-2].ThrumNormdis=LineConnect[ConLineNum-1].ThrumNormdis;
									LineConnect[ConLineNum-2].ThrumHisDire=LineConnect[ConLineNum-1].ThrumHisDire;
								}
								ConLineNum--;
							}
						}
					}
				else if(NearDis>PARALLELSUB&&FarDis-NearDis<PARALLELSUB)
				{
						LineParallel[ParallelLineNum].ThrumStart.x=PStartII.x+0.5;
						LineParallel[ParallelLineNum].ThrumStart.y=PStartII.y+0.5;
						LineParallel[ParallelLineNum].ThrumEnd.x=PEndII.x+0.5;
						LineParallel[ParallelLineNum].ThrumEnd.y=PEndII.y+0.5;
						LineParallel[ParallelLineNum].ThrumDire=LinePara[i].xstep;
						LineParallel[ParallelLineNum].ThrumCurveSeq=LinePara[j].xstep;
						LineParallel[ParallelLineNum].ThrumNormdis=(FarDis+NearDis)/2;
					
						//TRACE(_T("NO.%dCurve may be paralleled with NO.%dCurve with dist=%f\n"),LineParallel[ParallelLineNum].ThrumDire,LineParallel[ParallelLineNum].ThrumCurveSeq,LineParallel[ParallelLineNum].ThrumNormdis);
						ParallelLineNum++;

				}
				}
				j++;
				if(j==LineNum)
				{break;}
			}
			//i=j;
		
				

		}


	}
	return ConLineNum;

}
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
int Parallel_Result()
{return ParallelLineNum;
}