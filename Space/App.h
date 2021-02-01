#pragma once
enum WindowMode //enum ����� ���� �ڷ����̸� enum �� �������̴�. WindowMode �� â���?
{
	FULL,
	WINDOW
};

class TextFont;
class App : public Singleton<App> //Singleton ���� �� ���� �ν��Ͻ����� ������ ����
{
private:
	int m_Width; //int ���� ����
	int m_Height;
	bool m_WindowMode;

	HWND m_Hwnd; //�ڵ� ������ ����, �������� �ڵ��ȣ�� �����ؼ� ���, �ϳ��� ���α׷����� �������� �����츦 ��� �� �ִ�. ������â�� ��ȣ��� �����Ѵ�.

public:
	App();
	~App();
	private:
	bool _CreateWindow();
	bool _CreateRenderer();
 //bool  ������ true �� false �� ���� ���� ������. 
 //if, while ���ǹ����� true �� ���� �Ǿ� �ش� ���ǹ��� �ش��ϴ� ���๮�� ����ȴ�.
//��� ������� ������ Ŭ������ ������� �Ͽ� ��������� ������ Ŭ������ ������� �������� �������� Ư���� �����Ѵ�.

public:
	int Mode; 
	bool Init(int width, int height, bool windowMode);
	void Run();
	void Release();

public:
	LARGE_INTEGER   //����ü ��ȣ�ִ� 64��Ʈ ���� ���� ��Ÿ����.
		timeStart,  //����
		timeEnd,    //��
		timerFreq;  //������?
	float           //�ε� �Ҽ��� ���� ������ �������Ӥ���c cc++�� �̷��� �ڷ����� ũ�⸦ ���������� �������� �ʴ´�
		frameTime,
		fps;
	DWORD sleepTime; //WORD �� DWORD �� ����ѵ�(?) /WORD �� CPU�� ó���� �� �ִ� �ϳ��� ���� �̴�.

	__int64           //��ȣ �ִ� 64��Ʈ ������ ��Ÿ����.
		time2, time1; 

	float
		Time
		, CurrentTime
		, NewTime
		, FrameTime
		, DeltaTime;

public:
	HWND GetHwnd() { //�ڵ� ������ ����, �������� �ڵ��ȣ�� �����ؼ� ���, �ϳ��� ���α׷����� �������� �����츦 ��� �� �ִ�. ������â�� ��ȣ��� �����Ѵ�.
		return m_Hwnd;
	}

private:
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam); //�˻��� �ߴµ� �����Ҹ��� �𸣰���.
	
};

