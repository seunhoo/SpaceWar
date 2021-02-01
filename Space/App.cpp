#include "stdafx.h" //자주 변경되지 않는 긴 소스를 stdafx에 넣고 미리 컴파일을 해둔다.본문에 stdafx.h를 사용하여 전체 컴파일 속도를 상승시킨다.
#include "TextFont.h" // 텍스트 폰트 넣는거?
#include "App.h" // 어플리케이션/>????????????????????????????????????????????????????????????????????????????????????????????

const float FRAME_RATE = 200.0f;      //const : 변수 선언시 자료형 앞뒤에 사용되어 상수로 선언
const float MIN_FRAME_RATE = 10.0f;     // ""
const float MIN_FRAME_TIME = 1.0f / FRAME_RATE;  // ""
const float MAX_FRAME_TIME = 1.0f / MIN_FRAME_RATE;  // ""

App::App() //모르겠다!
{
}


App::~App()
{
}
bool App::Init(int width, int height, bool windowMode)//bool 형은 오로지 true 나 false 두 가지 값만 가진다. 
                                                     //if, while 조건문에서 true 면 참이 되어 해당 조건문에 해당하는 실행문이 수행된다.
{
	m_Width = width;          //변수
	m_Height = height;       //변수
	m_WindowMode = windowMode; //변수

	if (!_CreateWindow()) //윈도우나 컨트롤을 생성하는 함수
		return false;

	if (!_CreateRenderer()) //디폴트 가상함수
		return false;

	Time = 0.0f;
	CurrentTime = GetTickCount64();
	return true;
}

void App::Run() //폼을 사용하지 않고 현재 스레드에서 표준 애플리케이션 메시지 루프를 실행하기 시작합니다.
{
	MSG msg; //메시지 루프는 세 개의 함수 호출로 이루어져 있으며 전체 루프는 while문으로 싸여져 있다
	ZeroMemory(&msg, sizeof(MSG)); //ZeroMemory = 메모리 영역을 0X00으로 채우는 매크로 이다.
	srand(time(NULL));

	while (msg.message != WM_QUIT)//msg.message 는 IRC에서 IRC에 연결된 다른 사용자에게 비공개로 메시지를 보내는 명령으로 사용된다.
	{                             // WM_QUIT 는 응용 프로그램을 종료하라는 신호이다. 

		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) //PeekMessage 메시지를 얻어오고, 계속 제어를 원함
													// PM_REMOVE메시지 큐에서 메시지를 제거 대부분의 경우는 메시지큐에서 메시지를 제거한다.
		{
			TranslateMessage(&msg); //TranslateMessage 함수는 전달된 메시지가 WM_KEYDOWN인지와 눌려진 키가 문자키인지            //검사해 보고 조건이 맞을 경우 WM_CHAR 메시지를 만들어 메시지 큐에 덧붙이는 역할을 한다.
			DispatchMessage(&msg); //DispatchMessage함수는 읽은 메시지를 윈도우 프로시져로 발송하는 역할을 한다.
		}
		else
		{

			NewTime = GetTickCount64();
			FrameTime = NewTime - CurrentTime;
			CurrentTime = NewTime;

			DeltaTime = FrameTime / 1000.0f;
			Renderer::GetInst()->Begin();
			SceneDirector::GetInst()->Update(Time);
			Time += DeltaTime;
			SceneDirector::GetInst()->Render();
			Renderer::GetInst()->End();

			//printf("%f %f\n", frameTime, Time); //출력!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
			//Renderer::GetInst()->Begin();       //컴포넌트 모양새를 정의한다.
			//SceneDirector::GetInst()->Update(frameTime,Time); //다중 씬 편집
			//SceneDirector::GetInst()->Render();               // 다중 씬 펴어어어어어어어언지지지지지지입
			//Renderer::GetInst()->End();          //컴포넌트 모양새를 정의한다.
			
				
			
			if (GetAsyncKeyState(VK_ESCAPE)) //VK_ESCAPE 는 정의되어있는 가상키 코드으으으으이다.
			{
				ObjectMgr::GetInst()->Release(); //ObjectMgr 은 모르겠ek.
				App::GetInst()->Release();          //App 어플리케이션 컴포넌트들 사이에서 공동으로 멤버들을 사용할 수 있게 해주는 편리한 공유 클래스를 제공
			}


		}
	}

}

void App::Release()     //함수 선언? +추가 App 설명은 위에
{
	FreeConsole();      //그 콘솔로부터 호출 프로세스를 분리합니다.
	Renderer::GetInst()->Release();  //컴포넌트 모양새를 정의한다.
	TextFont::GetInst()->Release();  //텍스트 폰트설정?
}

LRESULT App::WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) //LRESULT는 반환형 중 하나이다. 32bit signed 정수형이다.
                  //HWND 윈도우의 핸들을 말한다. UNIT 모르겠음 WPARAM 파라미터의 줄임 말. LPARAM 은 포인터 값을 전달할 때 사용한다.
{
	switch (Msg)// switch!!
	{
	case WM_DESTROY: //윈도우가 파괴될 때 이 메시지가 전달된다.;;
		PostQuitMessage(0);
		break;
	case WM_LBUTTONDOWN:  //작업 영역 내부에서 마우스 왼쪽 버튼을 누를 때 이 메시지가 메시지 큐에 붙여진다.
		//마우스가 캡처되어 있으면 캡처한 윈도우로 메시지가 전달되며 그렇지 않으면 마우스 커서 아래의 윈도우로 전달된다. 
		//모든 메시지 중에 가장 쉽게 받을 수 있는 메시지이므로 실습용이나 간단한 테스트용으로 많이 사용된다.
		INPUT->ButtonDown(true); // 사용자로부터 데이터를 받아들이기 위한 웹을 기초로 하는 폼의 상호적인 제어
		break;

	case WM_LBUTTONUP: //마우스 좌측 버튼을 놓으면 이벤트가 발동한다.
		INPUT->ButtonDown(false); //사용자가 입력한 값을 변수에 저장하는 함수
		break;
	}

	return DefWindowProc(hWnd, Msg, wParam, lParam);//이 함수는 윈도우 프로시저가 처리하지 않은 메시지의 디폴트 처리를 한다. 
	                                               //WndProc은 원하는 메시지를 처리하고 자신이처리하지 않은 메시지는 이 함수에게 전달하여 디폴트 처리를 하도록 해 주어야 한다.
}

bool App::_CreateWindow() //bool  오로지 true 나 false 두 가지 값만 가진다. 
                         //if, while 조건문에서 true 면 참이 되어 해당 조건문에 해당하는 실행문이 수행된다.
{	WNDCLASS wc = {};   /*모든 윈도우는 윈도우 클래스를 기반으로 하여 만들어지며 윈도우 클래스는 만들어질 윈도우의 여러가지 특성을 정의한다.*/
	wc.lpszClassName = L"Space"; 
	wc.hCursor = LoadCursor(0, IDC_ARROW);// hCursor 윈도우가 기본적으로 사용할 커서를 지정하며 LoadCursor 함수는 커서를 읽어오는 함수이다.
	wc.lpfnWndProc = WndProc;//windProc은 메시지 처리 함수이다. 메시지가 발생할 때 프로그램의 반응을 처리하는 일을 하며 WinMain 함수와는 별도로 WndProc이라는 이름으로 존재한다.

	RegisterClass(&wc);//윈도우 클래스를 등록한다. 윈도우 클래스는 생성될 윈도우의 여러 가지 특성을 가지는 구조체이며 CreateWindow 함수로윈도우를 생성하기 전에 
	                  //윈도우 클래스가 반드시 등록되어 있어야 한다. WNDCLASS 구조체를 선언한 후 이 구조체에 원하는속성을 설정하고 RegisterClass 함수로 윈도우 클래스를 등록한다

	DWORD Style = 0;  // dword 는 자료형중 하나로
	
	                 //CPU가 한번에 처리할 수 있는 데이터의 크기 단위를 WORD 라고 한다.



	if (m_WindowMode)
		Style = WS_OVERLAPPEDWINDOW; //이렇게 변경한 후 다시 프로그램을 실행시키면 수직 스크롤 바가 달린 윈도우가 만들어진다. 
	else
		Style = WS_POPUP | WS_EX_TOPMOST; //팝업 윈도우를 만든다. WS_CHILD와 함께 쓸수 없다.
	                                     //모든 윈도우보다 수직적으로 위에 있는 윈도우를 만든다.비활성화상태도 다른윈도우에 가려지지 않는다.
	HWND hWnd = CreateWindow(wc.lpszClassName, wc.lpszClassName, Style, 0, 0, m_Width, m_Height, 0, 0, 0, 0); //윈도우나 컨트롤을 생성하는 함수
	if (hWnd)
		m_Hwnd = hWnd;
	else
		return false; //되돌리기 실패

	ShowWindow(m_Hwnd, SW_SHOWDEFAULT);//초기에 윈도우 생성시의 Flag값에 따라 결정;


	return true;
}

bool App::_CreateRenderer() //bool 형은 오로지 true 나 false 두 가지 값만 가진다. 
                           //if, while 조건문에서 true 면 참이 되어 해당 조건문에 해당하는 실행문이 수행된다.
{
	if (!(Renderer::GetInst()->Init(m_Width, m_Height, m_WindowMode))) //컴포넌트 모양새를 정의한다.
		return false;

	return true;
}
