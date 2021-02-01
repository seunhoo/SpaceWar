#pragma once
enum WindowMode //enum 사용자 정의 자료형이며 enum 은 열거형이다. WindowMode 는 창모드?
{
	FULL,
	WINDOW
};

class TextFont;
class App : public Singleton<App> //Singleton 오직 한 개의 인스턴스만을 갖도록 보장
{
private:
	int m_Width; //int 변수 선언
	int m_Height;
	bool m_WindowMode;

	HWND m_Hwnd; //핸들 윈도우 약자, 윈도우의 핸들번호를 저장해서 사용, 하나의 프로그램에서 많은양의 윈도우를 띄울 수 있다. 윈도우창의 번호들로 구분한다.

public:
	App();
	~App();
	private:
	bool _CreateWindow();
	bool _CreateRenderer();
 //bool  오로지 true 나 false 두 가지 값만 가진다. 
 //if, while 조건문에서 true 면 참이 되어 해당 조건문에 해당하는 실행문이 수행된다.
//모든 윈도우는 윈도우 클래스를 기반으로 하여 만들어지며 윈도우 클래스는 만들어질 윈도우의 여러가지 특성을 정의한다.

public:
	int Mode; 
	bool Init(int width, int height, bool windowMode);
	void Run();
	void Release();

public:
	LARGE_INTEGER   //공용체 부호있는 64비트 정수 값을 나타낸다.
		timeStart,  //시작
		timeEnd,    //끝
		timerFreq;  //프리퀄?
	float           //부동 소수점 숫자 정수와 마찬가ㅣㅈ로c cc++은 이러한 자료형의 크기를 지정하지만 정의하지 않는다
		frameTime,
		fps;
	DWORD sleepTime; //WORD 나 DWORD 는 비슷한듯(?) /WORD 는 CPU가 처리할 수 있는 하나의 단위 이다.

	__int64           //부호 있는 64비트 정수를 나타낸다.
		time2, time1; 

	float
		Time
		, CurrentTime
		, NewTime
		, FrameTime
		, DeltaTime;

public:
	HWND GetHwnd() { //핸들 윈도우 약자, 윈도우의 핸들번호를 저장해서 사용, 하나의 프로그램에서 많은양의 윈도우를 띄울 수 있다. 윈도우창의 번호들로 구분한다.
		return m_Hwnd;
	}

private:
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam); //검색을 했는데 무슨소린지 모르겠음.
	
};

