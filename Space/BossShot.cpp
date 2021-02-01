#include "stdafx.h"
#include "BossShot.h"
#include "BossBullet.h"
#include "InvisibleEnemy.h"
#include "Boss.h"

BossShot::BossShot(Vec2 Pos, float rotation,Vec2 Dir)
	: AtkTime(0)
	, BulletSpeed(400)
{
	m_Sprite = Sprite::Create(L"Painting/Enemy/Attack2/CBossBullet.png");
	m_Sprite->SetParent(this);

	SetPosition2(Pos);
	m_Rotation = rotation;

	m_Dir = Dir;
	
	
	
	//Vec2 A, B;
	//A = m_Position;
	//B = ((Player*)ObjMgr->m_Objects.front())->m_Position;

	//Object* obj = ((BossBullet*)ObjMgr->m_Objects.front());

	//A -= B;
	//D3DXVec2Normalize(&m_Dir, &A);

	

}

void BossShot::Update(float time)
{

	ObjMgr->CollideCheak(this, "Player");
	AtkTime++;

	if (AtkTime >= 10)
	{
		ObjMgr->RemoveObject(this);
		AtkTime = 0;
	}

	Move(time);
}

void BossShot::Render()
{
	m_Sprite->Render();
}

void BossShot::Move(float time)
{
	Translate(-m_Dir.x * BulletSpeed, -m_Dir.y * BulletSpeed);
}

void BossShot::OnCollision(Object* obj, std::string tag)
{
	ObjMgr->RemoveObject(this);
}
