#include "stdafx.h" //자주 변경되지 않는 긴 소스를 stdafx에 넣고 미리 컴파일을 해둔다.본문에 stdafx.h를 사용하여 전체 컴파일 속도를 상승시킨다.
#include "Input.h"  //키보드 키를 입력받는 헤더 파일 인거 같다.


Input::Input()
	: m_MousePosition(0.f, 0.f) //마우스의 위치
	, m_bCurrentState(false)   //
	, m_bPrevState(false)     //
	, m_ButtonDown(false)    //
{
	ZeroMemory(&m_CurrentState, sizeof(m_CurrentState));  //ZeroMemory = 메모리 영역을 0X00으로 채우는 매크로 이다.
	ZeroMemory(&m_PrevState, sizeof(m_PrevState));  //ZeroMemory = 메모리 영역을 0X00으로 채우는 매크로 이다.
}

Input::~Input()
{
}

void Input::Update()
{
	KeyBoardUpdate();
	MouseUpdate();
}

void Input::ButtonDown(bool down)
{
	m_ButtonDown = down;
}

KeyState Input::GetKey(int key)
{
	m_bPrevState = m_PrevState[key];
	m_bCurrentState = m_CurrentState[key];

	if (m_bPrevState == true && m_bCurrentState == true)
		return KeyState::PRESS;

	else if (m_bPrevState == true && m_bCurrentState == false)
		return KeyState::UP;

	else if (m_bPrevState == false && m_bCurrentState == true)
		return KeyState::DOWN;

	return KeyState::NONE;
}

void Input::KeyBoardUpdate()
{
	for (int i = 0; i < 256; i++)
	{
		m_PrevState[i] = m_CurrentState[i];
		m_CurrentState[i] = static_cast<bool>(GetAsyncKeyState(i));
	}
}

void Input::MouseUpdate()
{
	POINT position;
	GetCursorPos(&position);

	ScreenToClient(App::GetInst()->GetHwnd(), &position);

	m_MousePosition.x = static_cast<float>(position.x);
	m_MousePosition.y = static_cast<float>(position.y);
	//printf("Mouse : %f %f \n", m_MousePosition.x, m_MousePosition.y);
}