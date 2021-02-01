#include "stdafx.h"
#include "SniperBullet.h"

SniperBullet::SniperBullet(Vec2 Pos, float rotate)
	: delay (0)
{
	m_Sprite = Sprite::Create(L"Painting/Attack/BossBullet0.png");

	m_Sprite->SetParent(this);

	SetPosition2(Pos);
	m_Rotation = rotate;
	m_Speed = 100.f;

	Vec2 A, B;
	A = m_Position;
	B = INPUT->GetMousePos();
	A -= B;
	D3DXVec2Normalize(&m_Dir, &A);
}

void SniperBullet::Update(float time)
{
	ObjMgr->CollideCheak(this, "Monster");

	delay++;

	if (delay >= 30)
	{
		ObjMgr->RemoveObject(this);
	}
	if (m_Position.x >= 1920 || m_Position.x <= 0 || m_Position.y <= 0 || m_Position.y >= 1080)
	{
		ObjMgr->RemoveObject(this);
	}
	Move(time);
}

void SniperBullet::Render()
{
	m_Sprite->Render();
}

void SniperBullet::Move(float time)
{
	Translate(-m_Dir.x * m_Speed, -m_Dir.y * m_Speed);
}

void SniperBullet::OnCollision(Object* obj, std::string tag)
{
}
