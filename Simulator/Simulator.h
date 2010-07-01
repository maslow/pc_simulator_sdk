
#ifdef __cplusplus
#define EXPORT extern "C" __declspec(dllexport)
#else
#define EXPORT __declspec(dllexport)
#endif

#define MAX_C_STR 255
namespace logain
{

	/**************************鼠标操作系列******************************/
	//鼠标绝对移动
	EXPORT void MoveTo(long, long);
	//鼠标相对移动
	EXPORT void MoveR(long, long);
	//鼠标左键操作
	EXPORT void MouseLeftDown(void);
	EXPORT void MouseLeftUp(void);
	EXPORT void LeftClick(void);
	EXPORT void LeftDblClick(void);
	//鼠标右键操作
	EXPORT void MouseRightDown(void);
	EXPORT void MouseRightUp(void);
	EXPORT void RightClick(void);

	///************************键盘按键操作系列**************************/
	EXPORT void KeyDown(WORD);	//键盘按下
	EXPORT void KeyUp(WORD);		//键盘弹起
	EXPORT void KeyPress(WORD); //按键

	/**************************窗口操作系列******************************/
	EXPORT HWND FindWindowEx(wchar_t *);		//根据窗口名称得到窗口句柄
	EXPORT void MoveWindow(HWND, int, int); //移动窗口
	EXPORT void ActiveWindow(HWND);					//激活窗口

	/**************************图像操作系列******************************/
	//屏幕区域找图
	EXPORT void FindPic(int, int, int, int, wchar_t *, double, int &, int &);
	//全屏找图
	EXPORT void FindPicFullScreen(wchar_t *, double, int &, int &);
	//截屏
	//EXPORT		void  CaptureScreen(BYTE* &,BITMAPINFOHEADER* &);
	EXPORT void CaptureScreen(wchar_t *);
	//加载位图文件
	EXPORT void LoadBMP(wchar_t *, BYTE *&, BITMAPINFOHEADER *&);
	/**************************系统操作系列*******************************/
	EXPORT void ExitWindowsSys();

	/**************************全局变量***********************************/
	EXPORT const wchar_t pszVersion[MAX_C_STR] = L"1.0";
	EXPORT const wchar_t pszAuthorEn[MAX_C_STR] = L"Logain";
	EXPORT const wchar_t pszDate[MAX_C_STR] = L"2011/7/19";
}