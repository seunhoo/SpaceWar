#include "stdafx.h"  //자주 변경되지 않는 긴 소스를 stdafx에 넣고 미리 컴파일을 해둔다.본문에 stdafx.h를 사용하여 전체 컴파일 속도를 상승시킨다.
#include "Animation.h"  //애니매이션 입력

Animation::Animation()   //애니매이션 선언?
	: m_AutoPlay(0)
	, m_CurrentFrame(0)
	, m_Delay(0)
	, m_FrameCount(0)
{
}

Animation::~Animation() //애니매이션
{
}

void Animation::AddFrame(std::wstring fileName) //애니매이션 이미지를 만드는거 같다.
{
	auto sprite = Sprite::Create(fileName);
	sprite->SetParent(this);   //this 는 변수 같은 것은 아니고 객체의 주소를 컴파일러에게 보이지 않게(몰래) 전달하는 주소라고 볼 수 있ㅏㄷ.
	m_Anim.push_back(sprite);
}

void Animation::AddContinueFrame(std::wstring fileName, int firstFrame, int lastFrame) //애니메이션 프레임 연결?
{
	m_LastFrame = lastFrame - 1;
	if (firstFrame > lastFrame)  //첫 프레임이 마지막 프레임 보다 많으면 실행!!
	{
		for (int i = firstFrame; i >= lastFrame; i--)  // 첫 프레임이 마지막 프레임 보다 많으면 하나씩 줄임
		{
			auto sprite = Sprite::Create(fileName.c_str() + std::to_wstring(i) + L".png"); //auto 키워드를 사용하면 초깃값의 형식에 맟춰 선언하는 인스턴스(변수)의 형식이 '자동'으로 결정된다. 

			sprite->SetParent(this);
			m_Size = sprite->m_Size;
			if (sprite)
				m_Anim.push_back(sprite); //뒤로 밀기?
		}
	}
	else
	{
		for (int i = firstFrame; i <= lastFrame; i++) //첫 프레임이 마지막 프레임 보다 적으면 하나씩 올림
		{
			auto sprite = Sprite::Create(fileName.c_str() + std::to_wstring(i) + L".png");//auto 키워드를 사용하면 초깃값의 형식에 맟춰 선언하는 인스턴스(변수)의 형식이 '자동'으로 결정된다. 

			sprite->SetParent(this);
			m_Size = sprite->m_Size;
			if (sprite)
				m_Anim.push_back(sprite);
		}
	}

}
void Animation::Init(int delay, bool play) 
{
	m_Delay = delay;
	m_AutoPlay = play;
}

void Animation::Update(float time)
{
	m_FrameCount++;

	if (m_AutoPlay == true)
		if (m_FrameCount > m_Delay)
		{
			m_CurrentFrame++;
			m_FrameCount = 0;
		}

	if (m_CurrentFrame > m_Anim.size() - 1)
	{
		m_CurrentFrame = 0;
	}

	m_Anim.at(m_CurrentFrame)->Update(time);
}

void Animation::Render()
{
	if (m_Parent)
	{
		SetRect(&m_Parent->m_Collision, m_Parent->m_Position.x - m_Size.x / 2, m_Parent->m_Position.y - m_Size.y / 2,
			m_Parent->m_Position.x + m_Size.x / 2, m_Parent->m_Position.y + m_Size.y / 2);

		m_Parent->m_Size = m_Size;
	}
	else
	{
		SetRect(&m_Collision, m_Position.x - m_Size.x / 2, m_Position.y - m_Size.y / 2,
			m_Position.x + m_Size.x / 2, m_Position.y + m_Size.y / 2);

	}

	m_Anim.at(m_CurrentFrame)->R = R;
	m_Anim.at(m_CurrentFrame)->G = G;
	m_Anim.at(m_CurrentFrame)->B = B;
	m_Anim.at(m_CurrentFrame)->Render();
}