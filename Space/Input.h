#pragma once
enum class KeyState //Ű�� ���¸� �����ϴ� ����� ����
{
	DOWN, //Ű���� ������
	UP,   //Ű���� ����
	PRESS,//�������ֱ�
	NONE // �ƹ� ���� �ƴҶ�
};
#define INPUT Input::GetInst()    //#define �� Ư�� ���� �̸��� ���̰ų� �ڵ带 �����Ͽ� �Լ� ���·� ���� �� �ִ�. 
class Input : public Singleton<Input> //singleton �ڿ��� ���������� ������ �� �ִ� Ŭ����, �ڱ��ڽ��� �޴� �Լ��� �ϳ� ���� �̸� ����� �ξ��� �ڱ� �ڽ� ��ü�� ��ȯ�ϴ� Ŭ����
{
	int m_CurrentState[256];
	int m_PrevState[256];

	bool m_bCurrentState;
	bool m_bPrevState;

	Vec2 m_MousePosition; //vec(n): n���� float Ÿ�� ��Ҹ� ������ �⺻���� vector
	bool m_ButtonDown;

public:
	Input();
	~Input();

	void Update();
	void ButtonDown(bool down);
	KeyState GetKey(int key); //Ű�� ���¸� �����ϴ� ����� ����
	Vec2 GetMousePos() { return m_MousePosition; } 
	bool GetButtonDown() { return m_ButtonDown; }

private:
	void KeyBoardUpdate();
	void MouseUpdate();
};

