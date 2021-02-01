#include"stdafx.h"  //���� ������� �ʴ� �� �ҽ��� stdafx�� �ְ� �̸� �������� �صд�.������ stdafx.h�� ����Ͽ� ��ü ������ �ӵ��� ��½�Ų��.
#include"Sprite.h"
#include"Texture.h"  
#include"ResourceMgr.h" //������ �� ����� Javascript�� ���ڵ��ؾ��ϴ��� ���θ� ��Ÿ���ϴ�. 

Sprite::Sprite() //Rectangular entity + Texture = Sprite �� �ȴ�?!
	: m_pSp(Renderer::GetInst()->GetSprite()) 
{
	m_pSp->AddRef();
	SetRect(&m_Rect, 0, 0, 0, 0);
}

Sprite::~Sprite() //sprite ��ü�� �̵��ϰ� ��Ʈ�ѵǾ�����!!!! sprite��ü�� �ڱ��� �Ӽ��� ����, ��ġ, ������, ������� �ٲ㼭 ��Ʈ�Ѱ����� 2d�̹����� �� �Ҽ� �ִ�
{
}

bool Sprite::Init(std::wstring fileName)
//�����ڵ� ȯ��� ��Ƽ���� ȯ���� �Բ� �����ϴ� ������ ȯ�濡�� ����ϴ� ��쿡 ���� ��Ƽ����Ʈ ��Ʈ���� ����ϱ⵵ �ϰ�, �����ڵ� ��Ʈ���� ����ϱ⵵ �մϴ�.
//�� ��, std::string �� �̿��Ͽ� ���� �����ϰ� ��ȣ ��ȯ�� �����մϴ�.
{
	m_Texture = ResourceMgr::GetInst()->CreateTextureFromFile(fileName);
	if (m_Texture)
	{
		m_Size = m_Texture->GetSize();
		SetRect(&m_Rect, 0, 0, static_cast<int>(m_Size.x), static_cast<int>(m_Size.y)); //static cast : �������� ��ȯ ������ Ÿ���� ��ȯ�Ѵ�. (static_cast<�ٲٷ��� �ϴ� Ÿ��>(���);
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

	m_pSp->Begin(D3DXSPRITE_ALPHABLEND); //��������Ʈ�� ���̷�Ʈ �������� 2D�̹����� �׸��� ���ϰ� ���ִ� �������̽� �Դϴ�.
	m_pSp->SetTransform(&GetMatrix());
	m_pSp->Draw(m_Texture->GetTexture(), &m_Rect, &D3DXVECTOR3(m_Size.x / 2, m_Size.y / 2, 0), 0, D3DCOLOR_ARGB(255, 255, 255, 255));
	m_pSp->End();
}
//���̷�Ʈ3D�� ����ũ�μ���Ʈ�� Direct3D�� ����ũ�μ���Ʈ�� DirectX API���� 3���� �׷��Ƚ� ����� ����� ����ϴ� �κ��̴�. ����ũ�μ���Ʈ�� ������ � ü��
//���� 95 �̻� ������ �۵��ϸ�, �����ڽ� �� �����ڽ� 360 ���� �ܼ��� �׷��� API�� ���ǰ� �ִ�. ���̷�Ʈ3D�� ����ѿ����� �ϴ� API�δ� OpenGL�� ������
//������ ������ ���� �ٸ� ������� ������ �ִ�.
