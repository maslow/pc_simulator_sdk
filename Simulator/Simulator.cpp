// Simulator.cpp : 定义 DLL 应用程序的导出函数。
//
#include "stdafx.h"
#include "Simulator.h"
#include <iostream>
using namespace std;
namespace logain
{
	/************************************************************************/
	/*	                     鼠标模拟操作                                   */
	/************************************************************************/
	EXPORT void MoveTo(long dx, long dy)
	{
		//屏幕最大逻辑尺度
		const double MAX_SCREEN = 65535.00;

		//当前屏幕最大尺度，像素
		int cxScreen = GetSystemMetrics(SM_CXSCREEN);
		int cyScreen = GetSystemMetrics(SM_CYSCREEN);

		//逻辑尺度与像素尺度比率
		double kwidth = MAX_SCREEN / (double)cxScreen;
		double kheight = MAX_SCREEN / (double)cyScreen;

		//初始化INPUT结构体
		INPUT input;
		input.type = INPUT_MOUSE;					 //类型为鼠标输入
		input.mi.dx = (long)(dx * kwidth); //鼠标目的坐标
		input.mi.dy = (long)(dy * kheight);
		input.mi.dwFlags = MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE; //“绝对坐标”|“鼠标移动”
		input.mi.dwExtraInfo = GetMessageExtraInfo();								//默认
		input.mi.time = 0;
		input.mi.mouseData = 0;

		//初始化SendInput各参数
		int cbsize = sizeof(input); //INPUT结构大小
		UINT nInputs = 1;						//事件个数

		UINT nresult = SendInput(nInputs, &input, cbsize);
		if (nresult == 0)
			::MessageBox(NULL, L"鼠标绝对移动操作失败,可能被未知程序屏蔽，请联系作者!", L"不好意思", 0);
	}

	EXPORT void MoveR(long rx, long ry)
	{
		//初始化INPUT结构体
		INPUT input;
		input.type = INPUT_MOUSE; //类型为鼠标输入
		input.mi.dx = rx;					//鼠标目的坐标
		input.mi.dy = ry;
		input.mi.dwFlags = MOUSEEVENTF_MOVE;					//“鼠标移动”
		input.mi.dwExtraInfo = GetMessageExtraInfo(); //默认
		input.mi.time = 0;
		input.mi.mouseData = 0;

		//初始化SendInput各参数
		int cbsize = sizeof(input); //INPUT结构大小
		UINT nInputs = 1;						//事件个数

		UINT nresult = SendInput(nInputs, &input, cbsize);
		if (nresult == 0)
			::MessageBox(NULL, L"鼠标相对移动操作失败,可能被未知程序屏蔽，请联系作者!", L"不好意思", 0);
	}

	EXPORT void MouseLeftDown(void)
	{
		//初始化INPUT结构体
		INPUT input;
		input.type = INPUT_MOUSE;											//类型为鼠标输入
		input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;			//“鼠标左键按下”
		input.mi.dwExtraInfo = GetMessageExtraInfo(); //默认
		input.mi.time = 0;
		input.mi.mouseData = 0;

		//初始化SendInput各参数
		int cbsize = sizeof(input); //INPUT结构大小
		UINT nInputs = 1;						//事件个数

		UINT nresult = SendInput(nInputs, &input, cbsize);
		if (nresult == 0)
			::MessageBox(NULL, L"鼠标操作失败,可能被未知程序屏蔽，请联系作者!", L"不好意思", 0);
	}

	EXPORT void MouseLeftUp(void)
	{
		//初始化INPUT结构体
		INPUT input;
		input.type = INPUT_MOUSE;											//类型为鼠标输入
		input.mi.dwFlags = MOUSEEVENTF_LEFTUP;				//“鼠标左键按下”
		input.mi.dwExtraInfo = GetMessageExtraInfo(); //默认
		input.mi.time = 0;
		input.mi.mouseData = 0;

		//初始化SendInput各参数
		int cbsize = sizeof(input); //INPUT结构大小
		UINT nInputs = 1;						//事件个数

		UINT nresult = SendInput(nInputs, &input, cbsize);
		if (nresult == 0)
			::MessageBox(NULL, L"鼠标操作失败,可能被未知程序屏蔽，请联系作者!", L"不好意思", 0);
	}

	EXPORT void LeftClick(void)
	{
		MouseLeftDown();
		MouseLeftUp();
	}

	EXPORT void LeftDblClick(void)
	{
		LeftClick();
		LeftClick();
	}

	EXPORT void MouseRightDown(void)
	{
		//初始化INPUT结构体
		INPUT input;
		input.type = INPUT_MOUSE;											//类型为鼠标输入
		input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;			//“鼠标左键按下”
		input.mi.dwExtraInfo = GetMessageExtraInfo(); //默认
		input.mi.time = 0;
		input.mi.mouseData = 0;

		//初始化SendInput各参数
		int cbsize = sizeof(input); //INPUT结构大小
		UINT nInputs = 1;						//事件个数

		UINT nresult = SendInput(nInputs, &input, cbsize);
		if (nresult == 0)
			::MessageBox(NULL, L"鼠标操作失败,可能被未知程序屏蔽，请联系作者!", L"不好意思", 0);
	}

	EXPORT void MouseRightUp(void)
	{
		//初始化INPUT结构体
		INPUT input;
		input.type = INPUT_MOUSE;											//类型为鼠标输入
		input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;				//“鼠标左键按下”
		input.mi.dwExtraInfo = GetMessageExtraInfo(); //默认
		input.mi.time = 0;
		input.mi.mouseData = 0;

		//初始化SendInput各参数
		int cbsize = sizeof(input); //INPUT结构大小
		UINT nInputs = 1;						//事件个数

		UINT nresult = SendInput(nInputs, &input, cbsize);
		if (nresult == 0)
			::MessageBox(NULL, L"鼠标操作失败,可能被未知程序屏蔽，请联系作者!", L"不好意思", 0);
	}

	EXPORT void RightClick(void)
	{
		MouseRightDown();
		MouseRightUp();
	}

	/************************************************************************/
	/*			             键盘模拟操作                                   */
	/************************************************************************/
	EXPORT void KeyDown(WORD wVk)
	{
		//初始化INPUT结构体
		INPUT input;
		input.type = INPUT_KEYBOARD;
		input.ki.wVk = wVk;
		input.ki.dwFlags = KEYEVENTF_EXTENDEDKEY;
		input.ki.wScan = 0;
		input.ki.time = 0;
		input.ki.dwExtraInfo = GetMessageExtraInfo();

		int cbsize = sizeof(input);
		UINT nInputs = 1;

		UINT nresult = SendInput(nInputs, &input, cbsize);
		if (nresult == 0)
			::MessageBox(NULL, L"键盘操作失败,可能被未知程序屏蔽，请联系作者!", L"不好意思", 0);
	}

	EXPORT void KeyUp(WORD wVk)
	{
		//初始化INPUT结构体
		INPUT input;
		input.type = INPUT_KEYBOARD;
		input.ki.wVk = wVk;
		input.ki.dwFlags = KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP;
		input.ki.wScan = 0;
		input.ki.time = 0;
		input.ki.dwExtraInfo = GetMessageExtraInfo();

		int cbsize = sizeof(input);
		UINT nInputs = 1;

		UINT nresult = SendInput(nInputs, &input, cbsize);
		if (nresult == 0)
			::MessageBox(NULL, L"键盘操作失败,可能被未知程序屏蔽，请联系作者!", L"不好意思", 0);
	}

	EXPORT void KeyPress(WORD wVk)
	{
		KeyDown(wVk);
		KeyUp(wVk);
	}

	/************************************************************************/
	/*                        窗口操作                                      */
	/************************************************************************/

	HWND hwndFound = NULL; //窗口句柄查找结果
	//窗口枚举过程函数
	BOOL WINAPI EnumWindowsProc(HWND hwnd, LPARAM lParam)
	{
		if (!IsWindowVisible(hwnd))
			return true;
		wchar_t wndText[MAX_C_STR];
		GetWindowText(hwnd, wndText, MAX_C_STR);
		if (wcscmp(wndText, (wchar_t *)lParam) >= 0)
		{
			hwndFound = hwnd;
			return FALSE;
		}

		return true;
	}

	//查找指定窗口
	HWND FindWindowEx(wchar_t *strText)
	{
		if (wcslen(strText) <= 0)
			return NULL;
		EnumWindows((WNDENUMPROC)EnumWindowsProc, (LPARAM)strText);

		return hwndFound;
	}

	//移动窗口
	EXPORT void MoveWindow(HWND hwnd, int dx, int dy)
	{
		RECT rect;
		GetWindowRect(hwnd, &rect);
		int nWidth = rect.right - rect.left;
		int nHeight = rect.bottom - rect.top;
		::MoveWindow(hwnd, dx, dy, nWidth, nHeight, FALSE);
	}
	//激活窗口
	EXPORT void ActiveWindow(HWND hwnd)
	{
		SetForegroundWindow(hwnd);
	}
	/************************************************************************/
	/*                        图形图像系列                                  */
	/************************************************************************/
	//屏幕找图
	EXPORT void FindPic(int originx, int originy, int width, int height, wchar_t *pszPathName, double similar, int &coordinatex, int &coordinatey)
	{
		/*说明*/
		/*此屏幕找图函数在全屏找到子图并返回该子图的坐标*/
		/*程序分为三个部分：1、加载位图文件 */
		/*					2、截屏			*/
		/*					3、循环找图     */

		//初始化输出坐标
		coordinatex = -1;
		coordinatey = -1;
		/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@ 加 载 位 图 文 件@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/
		//输入位图变量
		BITMAPFILEHEADER bitmapFileHeader;		//位图文件头
		BITMAPINFOHEADER bitmapInfoHeaderImg; //位图信息头
		BYTE *pDataImg = NULL;								//位图图像数据

		int nWidthImg;			 //位图宽度
		int nHeightImg;			 //位图高度
		int nBitCountImg;		 //位图位深度
		int nPixelImg;			 //位图每像素字节数
		DWORD dwLineByteImg; //位图每行字节数

		HANDLE hfile;			 //文件句柄
		BOOL bSuccessRead; //读取文件结果
		DWORD dwSizeRead;	 //读取文件数据大小
		//打开文件
		hfile = CreateFile(pszPathName,
											 GENERIC_READ,
											 FILE_SHARE_READ,
											 NULL,
											 OPEN_EXISTING,
											 FILE_FLAG_SEQUENTIAL_SCAN,
											 NULL);
		if (hfile == INVALID_HANDLE_VALUE)
			return;
		//读取位图文件头数据
		bSuccessRead = ReadFile(hfile,
														(LPVOID)&bitmapFileHeader,
														sizeof(BITMAPFILEHEADER),
														&dwSizeRead,
														NULL);
		if (!bSuccessRead || dwSizeRead != sizeof(BITMAPFILEHEADER))
			return;
		if (bitmapFileHeader.bfType != 0x4D42)
			return; //判断是否为BMP文件
		//读取位图信息头数据
		bSuccessRead = ReadFile(hfile,
														(LPVOID)&bitmapInfoHeaderImg,
														sizeof(BITMAPINFOHEADER),
														&dwSizeRead,
														NULL);
		if (!bSuccessRead || dwSizeRead != sizeof(BITMAPINFOHEADER))
			return;
		//为位图信息变量赋值
		if (bitmapInfoHeaderImg.biBitCount < 24)
			return;																										//判断是否为真彩图
		nWidthImg = bitmapInfoHeaderImg.biWidth;										//位图宽度
		nHeightImg = bitmapInfoHeaderImg.biHeight;									//位图高度
		nBitCountImg = bitmapInfoHeaderImg.biBitCount;							//每像素位数
		nPixelImg = nBitCountImg / 8;																//每行字节数
		dwLineByteImg = (nWidthImg * nBitCountImg / 8 + 3) / 4 * 4; //计算位图行字节数
		pDataImg = new unsigned char[dwLineByteImg * nHeightImg];		//为位图像素数据分配空间
		//读取位图像素数据
		bSuccessRead = ReadFile(hfile,
														(LPVOID)pDataImg,
														dwLineByteImg * nHeightImg,
														&dwSizeRead,
														NULL);
		if (!bSuccessRead || pDataImg == NULL)
			return;

		//释放资源
		CloseHandle(hfile); //关闭文件句柄

		/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ 截 屏 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/
		BITMAPINFOHEADER bitmapInfoHeaderScr; //位图信息文结构
		BYTE *lpdata = NULL;									//图像像素数据
		int nBitCountScr;											//位图位深度
		int nWidthScr;												//位图宽度
		int nHeightScr;												//位图高度
		int nPixelScr;												//每像素字节数
		DWORD dwLineByteScr;									//每行字节数
		int nScrx, nScry;											//屏幕尺寸，像素

		HDC hdc;																												 //桌面DC
		HDC memdc;																											 //与桌面兼容DC
		HBITMAP hbitmap, holdbitmap;																		 //桌面位图句柄
		BITMAP bitmap;																									 //桌面位图对象
		int nResult;																										 //函数执行结果
		nScrx = GetSystemMetrics(SM_CXSCREEN);													 //获取屏幕宽度
		nScry = GetSystemMetrics(SM_CYSCREEN);													 //获取屏幕高度
		hdc = GetDC(NULL);																							 //获取桌面DC
		memdc = CreateCompatibleDC(hdc);																 //创建与桌面兼容DC
		hbitmap = CreateCompatibleBitmap(hdc, nScrx, nScry);						 //创建桌面兼容位图句柄
		holdbitmap = (HBITMAP)SelectObject(memdc, hbitmap);							 //将空位图句柄选入兼容DC
		nResult = BitBlt(memdc, 0, 0, nScrx, nScry, hdc, 0, 0, SRCCOPY); //将桌面图像复制到兼容DC
		if (nResult == 0)
			return;
		hbitmap = (HBITMAP)SelectObject(memdc, holdbitmap); //得到桌面位图句柄
		//::MessageBox(NULL,L"good!",NULL,0);
		if (hbitmap == NULL)
			return;
		//通过桌面位图句柄获取位图对象(BITMAP)
		nResult = GetObject(hbitmap,
												sizeof(BITMAP),
												&bitmap);
		if (nResult == 0)
			return;
		//为位图信息变量赋值
		nWidthScr = bitmap.bmWidth;																	//位图宽度
		nHeightScr = bitmap.bmHeight;																//位图高度
		nBitCountScr = bitmap.bmBitsPixel;													//位图位深度
		nPixelScr = nBitCountScr / 8;																//位图每像素字节数
		dwLineByteScr = (nWidthScr * nBitCountScr / 8 + 3) / 4 * 4; //位图每行字节数
		lpdata = new unsigned char[dwLineByteScr * nHeightScr];			//为屏幕图像数据分配空间
		if (lpdata == NULL)
			return;
		//填充位图信息头结构
		bitmapInfoHeaderScr.biSize = sizeof(BITMAPINFOHEADER); //结构大小，字节
		bitmapInfoHeaderScr.biWidth = nWidthScr;							 //宽度
		bitmapInfoHeaderScr.biHeight = nHeightScr;						 //高度
		bitmapInfoHeaderScr.biPlanes = 1;											 //位平面，为1
		bitmapInfoHeaderScr.biBitCount = nBitCountScr;				 //位深度
		bitmapInfoHeaderScr.biCompression = BI_RGB;						 //压缩方式
		//获取DIB
		nResult = GetDIBits(hdc,
												hbitmap,
												0,
												nHeightScr,
												lpdata,
												(BITMAPINFO *)&bitmapInfoHeaderScr,
												DIB_RGB_COLORS);
		if (nResult == 0 || lpdata == NULL)
			return;

		//释放资源
		ReleaseDC(NULL, hdc);
		DeleteDC(memdc);
		DeleteObject(hbitmap);
		DeleteObject(holdbitmap);

		/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ 找 图 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/
		//判断数据合法性
		if (originx <= 0)
			originx = 0;
		if (originy <= 0)
			originy = 0;
		if (width >= nScrx)
			width = nScrx;
		if (height >= nScry)
			height = nScry;

		//调整相似度
		if (similar <= 0)
			similar = 0.1;
		if (similar > 1)
			similar = 1.0;
		int nSimilar = (int)(similar * 100 / 10);

		//循环变量
		int i, j, m, n, flag;		 //屏幕位图行、列指针; 输入位图行、列指针;  标志变量
		int nR, nG, nB;					 //屏幕图像像素颜色分量
		int nRed, nGreen, nBlue; //输入图像像素颜色分量
		int nSameNot, nSame;		 //相同像素点与不同像素点计数器

		//从左上角开始扫描
		for (i = nHeightScr - 1 - originy; i >= nHeightScr - originy - height; i--)
		{ //大图行扫描

			for (j = originx; j < width; j++) //大图列扫描
			{
				nSameNot = 0;
				nSame = 0;
				flag = 0;
				for (m = nHeightImg - 1; m >= 0; m--) //小图行扫描
				{
					for (n = 0; n < nWidthImg; n++) //小图列扫描
					{
						//屏幕图像像素颜色分量
						nB = *(lpdata + (i - (nHeightImg - m - 1)) * dwLineByteScr + (j + n) * nPixelScr + 2);
						nG = *(lpdata + (i - (nHeightImg - m - 1)) * dwLineByteScr + (j + n) * nPixelScr + 1);
						nR = *(lpdata + (i - (nHeightImg - m - 1)) * dwLineByteScr + (j + n) * nPixelScr + 0);

						//输入图像像素颜色分量
						nBlue = *(pDataImg + m * dwLineByteImg + n * nPixelImg + 2);
						nGreen = *(pDataImg + m * dwLineByteImg + n * nPixelImg + 1);
						nRed = *(pDataImg + m * dwLineByteImg + n * nPixelImg + 0);

						if (nB == nBlue && nG == nGreen && nRed == nR)
						{					 //如果颜色相同
							nSame++; //相同像素点+1
							if (nSame >= nHeightImg * nWidthImg * nSimilar / 10)
							{ //如果相同像素点大于指定范围
								coordinatex = j;
								coordinatey = nHeightScr - i - 1 - m; //赋值：小图左上角坐标
								//释放空间并返回
								delete[] lpdata;
								delete[] pDataImg;
								return;
							}
							flag = 1;
						}
						else
						{
							//不同像素点数+1
							nSameNot++;
							//如果不相等数超出相似度范围，则跳出
							if (nSameNot >= (10 - nSimilar) * nWidthImg * nHeightImg / 10)
							{
								flag = 0;
								break;
							}
							//如果第一行全不相等，则跳出
							if (nSameNot >= nWidthImg * (10 - nSimilar) / 10 && m == nHeightImg - 1 && n == nSameNot - 1)
							{
								flag = 0;
								break;
							}
						}
					} //for n
					if (flag == 0)
						break; //如果标志符为0，则进行下一个（大图像素点）判断
				}					 //for m
			}						 //for j

		} //for i
		delete[] lpdata;
		delete[] pDataImg;
		return;
	} //FindPic Function end.

	//全屏找图
	EXPORT void FindPicFullScreen(wchar_t *pszPathName, double similar, int &coordinatex, int &coordinatey)
	{
		//当前屏幕最大尺度，像素
		int cxScreen = GetSystemMetrics(SM_CXSCREEN);
		int cyScreen = GetSystemMetrics(SM_CYSCREEN);
		//调用区域找图函数
		FindPic(0, 0, cxScreen, cyScreen, pszPathName, similar, coordinatex, coordinatey);
	}

	//截屏
	EXPORT void CaptureScreen(wchar_t *pszPathName)
	{
		/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@截 屏@@@@@@@@@@@@@@@@@@@@@@@@@@*/
		//获取桌面DC及尺寸
		HDC hdc = GetDC(NULL);
		int nScrx = GetDeviceCaps(hdc, HORZRES);
		int nScry = GetDeviceCaps(hdc, VERTRES);
		//创建兼容内存DC
		HDC memdc = CreateCompatibleDC(hdc);
		//得到桌面位图
		HBITMAP hbitmap, holdbitmap;
		hbitmap = CreateCompatibleBitmap(hdc, nScrx, nScry);	 //创建桌面兼容位图
		holdbitmap = (HBITMAP)SelectObject(memdc, hbitmap);		 //将空位图选入内存DC
		BitBlt(memdc, 0, 0, nScrx, nScry, hdc, 0, 0, SRCCOPY); //将桌面复制到内存DC
		hbitmap = (HBITMAP)SelectObject(memdc, holdbitmap);		 //返回桌面位图
		//释放资源
		DeleteDC(memdc);
		DeleteObject(holdbitmap);
		//用位图句柄填充位图结构
		BITMAP bitmap;
		int nresult = GetObject(hbitmap, sizeof(BITMAP), &bitmap);
		if (nresult == 0)
			goto ret;
		//为屏幕图像数据分配空间
		int nLineByte = (bitmap.bmWidth * bitmap.bmBitsPixel / 8 + 3) / 4 * 4;
		LPBYTE lpdata = new unsigned char[nLineByte * bitmap.bmHeight];
		if (!lpdata)
			goto ret;
		//填充位图信息头结构
		BITMAPINFOHEADER *pbitmapInfoHeader = new BITMAPINFOHEADER;
		if (pbitmapInfoHeader == NULL)
			goto ret;
		pbitmapInfoHeader->biSize = sizeof(BITMAPINFOHEADER);
		pbitmapInfoHeader->biWidth = bitmap.bmWidth;
		pbitmapInfoHeader->biHeight = bitmap.bmHeight;
		pbitmapInfoHeader->biPlanes = 1;
		pbitmapInfoHeader->biBitCount = bitmap.bmBitsPixel;
		pbitmapInfoHeader->biCompression = BI_RGB;
		pbitmapInfoHeader->biSizeImage = 0;
		pbitmapInfoHeader->biXPelsPerMeter = 0;
		pbitmapInfoHeader->biYPelsPerMeter = 0;
		pbitmapInfoHeader->biClrImportant = 0;
		pbitmapInfoHeader->biClrUsed = 0;
		//构造位图文件头
		BITMAPFILEHEADER bitmapFileHeader;
		bitmapFileHeader.bfType = 0x4d42;
		bitmapFileHeader.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + nLineByte * bitmap.bmHeight;
		bitmapFileHeader.bfReserved1 = 0;
		bitmapFileHeader.bfReserved2 = 0;
		bitmapFileHeader.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

		//获取DIB
		nresult = GetDIBits(hdc, hbitmap, 0, bitmap.bmHeight, lpdata, (BITMAPINFO *)pbitmapInfoHeader, DIB_RGB_COLORS);
		ReleaseDC(NULL, hdc);
		DeleteObject(hbitmap);
		if (nresult == 0)
			goto ret;
		//写入文件
		HANDLE hFile;
		hFile = CreateFile(pszPathName,
											 GENERIC_WRITE,
											 FILE_SHARE_WRITE,
											 NULL,
											 CREATE_ALWAYS,
											 FILE_ATTRIBUTE_NORMAL,
											 NULL);
		if (hFile == NULL)
			goto ret;
		DWORD dwSizeWrited = 0;
		if (!WriteFile(hFile, (LPCVOID)&bitmapFileHeader, sizeof(BITMAPFILEHEADER), &dwSizeWrited, NULL) || dwSizeWrited != sizeof(BITMAPFILEHEADER))

			goto ret;
		if (!WriteFile(hFile, (LPCVOID)pbitmapInfoHeader, sizeof(BITMAPINFOHEADER), &dwSizeWrited, NULL) || dwSizeWrited != sizeof(BITMAPINFOHEADER))
			goto ret;
		if (!WriteFile(hFile, (LPCVOID)lpdata, nLineByte * bitmap.bmHeight, &dwSizeWrited, NULL) || dwSizeWrited != nLineByte * bitmap.bmHeight)
			goto ret;
	ret:
		if (lpdata != NULL)
			delete[] lpdata;
		if (pbitmapInfoHeader != NULL)
			delete pbitmapInfoHeader;
		if (hFile != NULL)
			CloseHandle(hFile);
		return;
	}

	//加载位图
	EXPORT void LoadBMP(wchar_t *pszFileName, BYTE *&lpdata, BITMAPINFOHEADER *&pbitmapInfoHeader)
	{
		BITMAPFILEHEADER bitmapFileHeader; //位图文件头
		HANDLE hfile;											 //文件句柄
		BOOL bSuccessRead;								 //读取文件结果
		DWORD dwSizeRead;									 //读取文件数据大小
		DWORD dwWidth;										 //位图宽度
		DWORD dwHeight;										 //位图高度
		DWORD dwBitCount;									 //位图位深度
		DWORD dwLineBytes;								 //位图行字节数
		//打开文件
		hfile = CreateFile(pszFileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_FLAG_SEQUENTIAL_SCAN, NULL);
		if (hfile == INVALID_HANDLE_VALUE)
			return;
		//读取位图文件头数据
		bSuccessRead = ReadFile(hfile, (LPVOID)&bitmapFileHeader, sizeof(BITMAPFILEHEADER), &dwSizeRead, NULL);
		if (!bSuccessRead || dwSizeRead != sizeof(BITMAPFILEHEADER))
		{
			CloseHandle(hfile);
			return;
		}
		//判断是否为BMP文件
		if (bitmapFileHeader.bfType != 0x4D42)
		{
			CloseHandle(hfile);
			return;
		}
		//读取位图信息头数据
		pbitmapInfoHeader = new BITMAPINFOHEADER;
		bSuccessRead = ReadFile(hfile, (LPVOID)pbitmapInfoHeader, sizeof(BITMAPINFOHEADER), &dwSizeRead, NULL);
		if (!bSuccessRead || dwSizeRead != sizeof(BITMAPINFOHEADER))
		{
			CloseHandle(hfile);
			delete pbitmapInfoHeader;
			return;
		}
		//判断是否为真彩图
		if (pbitmapInfoHeader->biBitCount < 24)
		{
			CloseHandle(hfile);
			delete pbitmapInfoHeader;
			return;
		}
		//初始位图信息变量
		dwWidth = pbitmapInfoHeader->biWidth;
		dwHeight = pbitmapInfoHeader->biWidth;
		dwBitCount = pbitmapInfoHeader->biBitCount;
		//计算位图行字节数
		dwLineBytes = (dwWidth * dwBitCount / 8 + 3) / 4 * 4;
		//为位图像素数据分配空间
		lpdata = new unsigned char[dwLineBytes * dwHeight];
		//读取位图像素数据
		bSuccessRead = ReadFile(hfile, (LPVOID)lpdata, dwLineBytes * dwHeight, &dwSizeRead, NULL);
		if (!bSuccessRead)
		{
			CloseHandle(hfile);
			delete pbitmapInfoHeader;
			if (!lpdata)
				delete[] lpdata;
			return;
		}
	}
	/************************************************************************/
	/*                             系统操作系列		                        */
	/************************************************************************/
	EXPORT void ExitWindowsSys()
	{
		//////////////////////////////////////////////////////////////////////////
		HANDLE htoken;				//进程标志句柄
		TOKEN_PRIVILEGES tkp; //标志-权限结构
		BOOL bResult;					//函数返回结果
		//打开当前进程的进程标志
		bResult = OpenProcessToken(GetCurrentProcess(),
															 TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY,
															 &htoken);
		if (!bResult)
			return;
		//填充TOKEN_PRIVILEGES结构
		tkp.PrivilegeCount = 1;															 //操作权限个数
		tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED; //权限操作类型
		//根据权限名称获得权限LUID
		bResult = LookupPrivilegeValue(NULL,
																	 SE_SHUTDOWN_NAME,
																	 &tkp.Privileges[0].Luid);
		if (!bResult)
			return;
		//修改当前进程权限
		bResult = AdjustTokenPrivileges(htoken,
																		FALSE,
																		&tkp,
																		0,
																		NULL,
																		NULL);
		if (!bResult)
			return;
		//关机
		ExitWindowsEx(EWX_SHUTDOWN, 0);
	}
}
