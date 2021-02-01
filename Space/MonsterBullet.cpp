#include "stdafx.h"
#include "Player.h"
#include "MonsterBullet.h"

MonsterBullet::MonsterBullet(Vec2 Pos, float rotation)
{
	m_MonsterBullet = Sprite::Create(L"Painting/Attack/MonsterBullet1.png");
	m_MonsterBullet->SetParent(this);

	SetPosition2(Pos);
	m_Rotation = rotation;
	m_Speed = 10.f;

	Vec2 A, B;
	A = m_Position;
	B = ((Player*)ObjMgr->m_Objects.front())->m_Position;

	Object* obj = ((Player*)ObjMgr->m_Objects.front());
	this;


	A -= B;
	D3DXVec2Normalize(&m_Dir, &A);
}

void MonsterBullet::Update(float time)
{
	ObjMgr->CollideCheak(this, "Player");
	Move(time);
}

void MonsterBullet::Render()
{
	m_MonsterBullet->Render();
}

void MonsterBullet::Move(float time)
{
	Translate(-m_Dir.x * m_Speed, -m_Dir.y * m_Speed);
}

void MonsterBullet::OnCollision(Object* obj, std::string tag)
{
	ObjMgr->RemoveObject(this);
}

