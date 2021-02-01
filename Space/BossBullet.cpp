#include "stdafx.h"
#include "BossBullet.h"
#include "BossShot.h"
#include "InvisibleEnemy.h"


BossBullet::BossBullet(Vec2 Pos, float rotation)
	: AtkTime(0)
{
	m_BossBullet = Sprite::Create(L"Painting/Enemy/Attack/ABossAtkReady.png");
	m_BossBullet->SetParent(this);

	/*m_Shot = Sprite::Create(L"Painting/Enemy/Attack2/EBossBullet.png");
	m_Shot->SetParent(this);*/

	SetPosition2(Pos);
	m_Rotation = rotation;

	Vec2 A, B;
	A = m_Position;
	B = ((Player*)ObjMgr->m_Objects.front())->m_Position;

	Object* obj = ((Player*)ObjMgr->m_Objects.front());
	this;

	A -= B;
	D3DXVec2Normalize(&m_Dir, &A);
}

BossBullet::~BossBullet()
{
}

void BossBullet::Update(float time)
{
	AtkTime++;

	if (AtkTime >= 110)
	{
		Shot(time);
		ObjMgr->RemoveObject(this);
	}


	
}

void BossBullet::Render()
{
	m_BossBullet->Render();

	/*if (AtkTime >= 110)
	{
		m_Shot->Render();
	}*/

}

void BossBullet::Shot(float time)
{
		ObjMgr->KeepObject(new BossShot(m_Position, m_Rotation, m_Dir), "BossShot");
}

void BossBullet::OnCollision(Object* obj, std::string tag)
{
}


