#pragma once
enum class KeyState //키의 상태를 정의하는 상수를 지정
{
	DOWN, //키보드 누르기
	UP,   //키보드 때기
	PRESS,//누르고있기
	NONE // 아무 상태 아닐때
};
#define INPUT Input::GetInst()    //#define 은 특정 값에 이름을 붙이거나 코드를 조합하여 함수 형태로 만들 수 있다. 
class Input : public Singleton<Input> //singleton 자원을 지속적으로 관리할 수 있는 클래스, 자기자신을 받는 함수를 하나 만들어서 미리 만들어 두었던 자기 자신 객체를 반환하는 클래스
{
	int m_CurrentState[256];
	int m_PrevState[256];

	bool m_bCurrentState;
	bool m_bPrevState;

	Vec2 m_MousePosition; //vec(n): n개의 float 타입 요소를 가지는 기본적인 vector
	bool m_ButtonDown;

public:
	Input();
	~Input();

	void Update();
	void ButtonDown(bool down);
	KeyState GetKey(int key); //키의 상태를 정의하는 상수를 지정
	Vec2 GetMousePos() { return m_MousePosition; } 
	bool GetButtonDown() { return m_ButtonDown; }

private:
	void KeyBoardUpdate();
	void MouseUpdate();
};

