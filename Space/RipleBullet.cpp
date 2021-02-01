#include "stdafx.h"
#include "RipleBullet.h"

RipleBullet::RipleBullet(Vec2 Pos, float rotate)
{
	m_Sprite = Sprite::Create(L"Painting/Attack/MonsterBullet1.png");
	m_Sprite->SetParent(this);

	SetPosition2(Pos);
	m_Rotation = rotate;
	m_Speed = 43.f;

	Vec2 A, B;
	A = m_Position;
	B = INPUT->GetMousePos();
	A -= B;
	D3DXVec2Normalize(&m_Dir, &A);
}

void RipleBullet::Update(float time)
{

	ObjMgr->CollideCheak(this, "Monster");
	ObjMgr->CollideCheak(this, "Boss");

	if (m_Position.x >= 1920 || m_Position.x <= 0 || m_Position.y <= 0 || m_Position.y >= 1080)
	{
		ObjMgr->RemoveObject(this);
	}

	Move(time);
}

void RipleBullet::Render()
{
	m_Sprite->Render();
}

void RipleBullet::Move(float time)
{

	Translate(-m_Dir.x * m_Speed, -m_Dir.y * m_Speed);
}

void RipleBullet::OnCollision(Object* other)
{
}

void RipleBullet::OnCollision(Object* obj, std::string tag)
{

	if (tag == "Monster")
	{
		ObjMgr->RemoveObject(this);
	}
	if (tag == "Boss")
	{
		ObjMgr->RemoveObject(this);
	}
}
