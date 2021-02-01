#include"stdafx.h"  //자주 변경되지 않는 긴 소스를 stdafx에 넣고 미리 컴파일을 해둔다.본문에 stdafx.h를 사용하여 전체 컴파일 속도를 상승시킨다.
#include"Sprite.h"
#include"Texture.h"  
#include"ResourceMgr.h" //렌더링 할 출력을 Javascript로 인코딩해야하는지 여부를 나타냅니다. 

Sprite::Sprite() //Rectangular entity + Texture = Sprite 가 된다?!
	: m_pSp(Renderer::GetInst()->GetSprite()) 
{
	m_pSp->AddRef();
	SetRect(&m_Rect, 0, 0, 0, 0);
}

Sprite::~Sprite() //sprite 객체는 이동하고 컨트롤되어진다!!!! sprite객체는 자기의 속성인 각도, 위치, 스케일, 색상등을 바꿔서 컨트롤가능한 2d이미지라 말 할수 있다
{
}

bool Sprite::Init(std::wstring fileName)
//유니코드 환경과 멀티바이 환경이 함께 동작하는 윈도우 환경에선 사용하는 경우에 따라 멀티바이트 스트링을 사용하기도 하고, 유니코드 스트링을 사용하기도 합니다.
//이 때, std::string 을 이용하여 아주 간단하게 상호 변환이 가능합니다.
{
	m_Texture = ResourceMgr::GetInst()->CreateTextureFromFile(fileName);
	if (m_Texture)
	{
		m_Size = m_Texture->GetSize();
		SetRect(&m_Rect, 0, 0, static_cast<int>(m_Size.x), static_cast<int>(m_Size.y)); //static cast : 논리적으로 변환 가능한 타입을 변환한다. (static_cast<바꾸려고 하는 타입>(대상);
		return true;
	}
	else
		return false;
}

void Sprite::SetRectSize(float x, float y)
{
	SetRect(&m_Rect, 0, 0, static_cast<int>(m_Size.x / x), static_cast<int>(m_Size.y / y));
}


Sprite* Sprite::Create(std::wstring fileName)
{
	auto sprite = new (std::nothrow) Sprite();
	if (sprite && sprite->Init(fileName))
	{
		return sprite;
	}
	else
	{
		SafeDelete(sprite);
		return nullptr;
	}
}

void Sprite::Render()
{
	if (m_Parent)
	{
		SetRect(&m_Parent->m_Collision,
			static_cast<int>(m_Parent->m_Position.x - m_Size.x / 2),
			static_cast<int>(m_Parent->m_Position.y - m_Size.y / 2),
			static_cast<int>(m_Parent->m_Position.x + m_Size.x / 2),
			static_cast<int>(m_Parent->m_Position.y + m_Size.y / 2));
		
	}
	else
	{
		m_Collision.left = static_cast<long>(m_Position.x - m_Size.x / 2);
		m_Collision.right = static_cast<long>(m_Position.x + m_Size.x / 2);

		m_Collision.top = static_cast<long>(m_Position.y - m_Size.y / 2);
		m_Collision.bottom = static_cast<long>(m_Position.y + m_Size.y / 2);

	}

	if (m_Visible == false)
		return;

	m_pSp->Begin(D3DXSPRITE_ALPHABLEND); //스프라이트는 다이렉트 엑스에서 2D이미지를 그리기 편하게 해주는 인터페이스 입니다.
	m_pSp->SetTransform(&GetMatrix());
	m_pSp->Draw(m_Texture->GetTexture(), &m_Rect, &D3DXVECTOR3(m_Size.x / 2, m_Size.y / 2, 0), 0, D3DCOLOR_ARGB(255, 255, 255, 255));
	m_pSp->End();
}
//다이렉트3D는 마이크로소프트의 Direct3D는 마이크로소프트의 DirectX API에서 3차원 그래픽스 연산과 출력을 담당하는 부분이다. 마이크로소프트이 윈도우 운영 체제
//윈도 95 이상 에서만 작동하며, 엑스박스 와 엑스박스 360 게임 콘솔의 그래픽 API로 사용되고 있다. 다이렉트3D와 비슷한역할을 하는 API로는 OpenGL이 있으며
//역할은 같지만 서로 다른 장단점을 가지고 있다.
