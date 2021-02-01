#include "stdafx.h"  //���� ������� �ʴ� �� �ҽ��� stdafx�� �ְ� �̸� �������� �صд�.������ stdafx.h�� ����Ͽ� ��ü ������ �ӵ��� ��½�Ų��.
#include "Object.h"


Object::Object() :
	m_pDev(Renderer::GetInst()->GetDevice())
	, m_Position(0.f, 0.f)
	, m_Rotation(0.f)
	, m_Scale(1.f, 1.f)
	, m_Destroy(0)
	, m_Parent(0)
	, m_Visible(true)
	, m_Layer(0)
	, m_Size(0.f, 0.f)
	, A(255)
	, R(255)
	, G(255)
	, B(255)
	, m_Tag("")
{
	m_ItemType = ITEM::NONE;
	m_pDev->AddRef();
	D3DXMatrixIdentity(&m_wMat);
}


Object::~Object()
{
}

Matrix  Object::GetMatrix() //�޼��� �� ������ �����ε尡 ���� �� 4x4 ��Ʈ����.(D3DXMATRIX)����
{
	D3DXMatrixTransformation2D(&m_wMat, 0, 0, &m_Scale, 0, m_Rotation, &m_Position);

	if (m_Parent)
		m_wMat *= m_Parent->GetMatrix();

	return m_wMat;
}
// ������Ʈ�� ��ġ�� ��Ÿ���°� ����
void Object::Translate(float x, float y)
{
	m_Position.x += x;
	m_Position.y += y;
}

void Object::SetScale(float x, float y)
{
	m_Scale.x = x;
	m_Scale.y = y;
}

void Object::SetPosition(float x, float y)
{
	m_Position.x = x;
	m_Position.y = y;
}

void Object::SetPosition2(Vec2 Pos)
{
	m_Position = Pos;
}



void Object::Rotate(float r)
{
	m_Rotation += r;
}

void Object::SetParent(Object* parent)
{
	m_Parent = parent;
}

void Object::Update(float time)
{
}

void Object::Render()
{
}

void Object::OnCollision(Object* other, std::string tag)
{
}

void Object::Mode(float time)
{
}
