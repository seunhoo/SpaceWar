#include "stdafx.h" //���� ������� �ʴ� �� �ҽ��� stdafx�� �ְ� �̸� �������� �صд�.������ stdafx.h�� ����Ͽ� ��ü ������ �ӵ��� ��½�Ų��.
#include "TextFont.h" // �ؽ�Ʈ ��Ʈ �ִ°�?
#include "App.h" // ���ø����̼�/>????????????????????????????????????????????????????????????????????????????????????????????

const float FRAME_RATE = 200.0f;      //const : ���� ����� �ڷ��� �յڿ� ���Ǿ� ����� ����
const float MIN_FRAME_RATE = 10.0f;     // ""
const float MIN_FRAME_TIME = 1.0f / FRAME_RATE;  // ""
const float MAX_FRAME_TIME = 1.0f / MIN_FRAME_RATE;  // ""

App::App() //�𸣰ڴ�!
{
}


App::~App()
{
}
bool App::Init(int width, int height, bool windowMode)//bool ���� ������ true �� false �� ���� ���� ������. 
                                                     //if, while ���ǹ����� true �� ���� �Ǿ� �ش� ���ǹ��� �ش��ϴ� ���๮�� ����ȴ�.
{
	m_Width = width;          //����
	m_Height = height;       //����
	m_WindowMode = windowMode; //����

	if (!_CreateWindow()) //�����쳪 ��Ʈ���� �����ϴ� �Լ�
		return false;

	if (!_CreateRenderer()) //����Ʈ �����Լ�
		return false;

	Time = 0.0f;
	CurrentTime = GetTickCount64();
	return true;
}

void App::Run() //���� ������� �ʰ� ���� �����忡�� ǥ�� ���ø����̼� �޽��� ������ �����ϱ� �����մϴ�.
{
	MSG msg; //�޽��� ������ �� ���� �Լ� ȣ��� �̷���� ������ ��ü ������ while������ �ο��� �ִ�
	ZeroMemory(&msg, sizeof(MSG)); //ZeroMemory = �޸� ������ 0X00���� ä��� ��ũ�� �̴�.
	srand(time(NULL));

	while (msg.message != WM_QUIT)//msg.message �� IRC���� IRC�� ����� �ٸ� ����ڿ��� ������� �޽����� ������ ������� ���ȴ�.
	{                             // WM_QUIT �� ���� ���α׷��� �����϶�� ��ȣ�̴�. 

		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) //PeekMessage �޽����� ������, ��� ��� ����
													// PM_REMOVE�޽��� ť���� �޽����� ���� ��κ��� ���� �޽���ť���� �޽����� �����Ѵ�.
		{
			TranslateMessage(&msg); //TranslateMessage �Լ��� ���޵� �޽����� WM_KEYDOWN������ ������ Ű�� ����Ű����            //�˻��� ���� ������ ���� ��� WM_CHAR �޽����� ����� �޽��� ť�� �����̴� ������ �Ѵ�.
			DispatchMessage(&msg); //DispatchMessage�Լ��� ���� �޽����� ������ ���ν����� �߼��ϴ� ������ �Ѵ�.
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

			//printf("%f %f\n", frameTime, Time); //���!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
			//Renderer::GetInst()->Begin();       //������Ʈ ������ �����Ѵ�.
			//SceneDirector::GetInst()->Update(frameTime,Time); //���� �� ����
			//SceneDirector::GetInst()->Render();               // ���� �� ������������������������
			//Renderer::GetInst()->End();          //������Ʈ ������ �����Ѵ�.
			
				
			
			if (GetAsyncKeyState(VK_ESCAPE)) //VK_ESCAPE �� ���ǵǾ��ִ� ����Ű �ڵ����������̴�.
			{
				ObjectMgr::GetInst()->Release(); //ObjectMgr �� �𸣰�ek.
				App::GetInst()->Release();          //App ���ø����̼� ������Ʈ�� ���̿��� �������� ������� ����� �� �ְ� ���ִ� ���� ���� Ŭ������ ����
			}


		}
	}

}

void App::Release()     //�Լ� ����? +�߰� App ������ ����
{
	FreeConsole();      //�� �ַܼκ��� ȣ�� ���μ����� �и��մϴ�.
	Renderer::GetInst()->Release();  //������Ʈ ������ �����Ѵ�.
	TextFont::GetInst()->Release();  //�ؽ�Ʈ ��Ʈ����?
}

LRESULT App::WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) //LRESULT�� ��ȯ�� �� �ϳ��̴�. 32bit signed �������̴�.
                  //HWND �������� �ڵ��� ���Ѵ�. UNIT �𸣰��� WPARAM �Ķ������ ���� ��. LPARAM �� ������ ���� ������ �� ����Ѵ�.
{
	switch (Msg)// switch!!
	{
	case WM_DESTROY: //�����찡 �ı��� �� �� �޽����� ���޵ȴ�.;;
		PostQuitMessage(0);
		break;
	case WM_LBUTTONDOWN:  //�۾� ���� ���ο��� ���콺 ���� ��ư�� ���� �� �� �޽����� �޽��� ť�� �ٿ�����.
		//���콺�� ĸó�Ǿ� ������ ĸó�� ������� �޽����� ���޵Ǹ� �׷��� ������ ���콺 Ŀ�� �Ʒ��� ������� ���޵ȴ�. 
		//��� �޽��� �߿� ���� ���� ���� �� �ִ� �޽����̹Ƿ� �ǽ����̳� ������ �׽�Ʈ������ ���� ���ȴ�.
		INPUT->ButtonDown(true); // ����ڷκ��� �����͸� �޾Ƶ��̱� ���� ���� ���ʷ� �ϴ� ���� ��ȣ���� ����
		break;

	case WM_LBUTTONUP: //���콺 ���� ��ư�� ������ �̺�Ʈ�� �ߵ��Ѵ�.
		INPUT->ButtonDown(false); //����ڰ� �Է��� ���� ������ �����ϴ� �Լ�
		break;
	}

	return DefWindowProc(hWnd, Msg, wParam, lParam);//�� �Լ��� ������ ���ν����� ó������ ���� �޽����� ����Ʈ ó���� �Ѵ�. 
	                                               //WndProc�� ���ϴ� �޽����� ó���ϰ� �ڽ���ó������ ���� �޽����� �� �Լ����� �����Ͽ� ����Ʈ ó���� �ϵ��� �� �־�� �Ѵ�.
}

bool App::_CreateWindow() //bool  ������ true �� false �� ���� ���� ������. 
                         //if, while ���ǹ����� true �� ���� �Ǿ� �ش� ���ǹ��� �ش��ϴ� ���๮�� ����ȴ�.
{	WNDCLASS wc = {};   /*��� ������� ������ Ŭ������ ������� �Ͽ� ��������� ������ Ŭ������ ������� �������� �������� Ư���� �����Ѵ�.*/
	wc.lpszClassName = L"Space"; 
	wc.hCursor = LoadCursor(0, IDC_ARROW);// hCursor �����찡 �⺻������ ����� Ŀ���� �����ϸ� LoadCursor �Լ��� Ŀ���� �о���� �Լ��̴�.
	wc.lpfnWndProc = WndProc;//windProc�� �޽��� ó�� �Լ��̴�. �޽����� �߻��� �� ���α׷��� ������ ó���ϴ� ���� �ϸ� WinMain �Լ��ʹ� ������ WndProc�̶�� �̸����� �����Ѵ�.

	RegisterClass(&wc);//������ Ŭ������ ����Ѵ�. ������ Ŭ������ ������ �������� ���� ���� Ư���� ������ ����ü�̸� CreateWindow �Լ��������츦 �����ϱ� ���� 
	                  //������ Ŭ������ �ݵ�� ��ϵǾ� �־�� �Ѵ�. WNDCLASS ����ü�� ������ �� �� ����ü�� ���ϴ¼Ӽ��� �����ϰ� RegisterClass �Լ��� ������ Ŭ������ ����Ѵ�

	DWORD Style = 0;  // dword �� �ڷ����� �ϳ���
	
	                 //CPU�� �ѹ��� ó���� �� �ִ� �������� ũ�� ������ WORD ��� �Ѵ�.



	if (m_WindowMode)
		Style = WS_OVERLAPPEDWINDOW; //�̷��� ������ �� �ٽ� ���α׷��� �����Ű�� ���� ��ũ�� �ٰ� �޸� �����찡 ���������. 
	else
		Style = WS_POPUP | WS_EX_TOPMOST; //�˾� �����츦 �����. WS_CHILD�� �Բ� ���� ����.
	                                     //��� �����캸�� ���������� ���� �ִ� �����츦 �����.��Ȱ��ȭ���µ� �ٸ������쿡 �������� �ʴ´�.
	HWND hWnd = CreateWindow(wc.lpszClassName, wc.lpszClassName, Style, 0, 0, m_Width, m_Height, 0, 0, 0, 0); //�����쳪 ��Ʈ���� �����ϴ� �Լ�
	if (hWnd)
		m_Hwnd = hWnd;
	else
		return false; //�ǵ����� ����

	ShowWindow(m_Hwnd, SW_SHOWDEFAULT);//�ʱ⿡ ������ �������� Flag���� ���� ����;


	return true;
}

bool App::_CreateRenderer() //bool ���� ������ true �� false �� ���� ���� ������. 
                           //if, while ���ǹ����� true �� ���� �Ǿ� �ش� ���ǹ��� �ش��ϴ� ���๮�� ����ȴ�.
{
	if (!(Renderer::GetInst()->Init(m_Width, m_Height, m_WindowMode))) //������Ʈ ������ �����Ѵ�.
		return false;

	return true;
}
