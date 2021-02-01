#include "stdafx.h"
#include "Ranger.h"
#include "MonsterBullet.h"

Ranger::Ranger(Vec2 Pos, float rotate)
	: StartTime(0)
	, EndTime(0)
	, MonsterBulletDelay(0)
	, RangerHp(3)
{
	m_Sprite = Sprite::Create(L"Painting/Enemy/Ranger0.png");
	m_Sprite->SetParent(this);


	int randomX = rand() % 1920;

	int randomY = rand() % 1080;

	SetPosition(randomX, randomY);
	
}

void Ranger::Update(float time)
{
	MonsterBulletDelay++;
	StartTime--;

	if (StartTime <= -30)
	{
		Move(time);
		if (StartTime <= -60)
		{
			StartTime = 0;
		}
	}
	else
	{
		Attack(time);
	}
}

void Ranger::Move(float time)
{

	Vec2 pPos, mPos, Dir;
	pPos = ((Player*)ObjMgr->m_Objects.front())->m_Position;
	mPos = m_Position;
	mPos -= pPos;
	m_Rotation = atan2(-mPos.x, mPos.y);
	D3DXVec2Normalize(&Dir, &mPos);
	Translate(-Dir.x * m_Speed, -Dir.y * m_Speed);
}

void Ranger::Attack(float time)
{
	Vec2 pPos, mPos;
	pPos = ((Player*)ObjMgr->m_Objects.front())->m_Position;
	mPos = m_Position;
	mPos -= pPos;
	m_Rotation = atan2(-mPos.x, mPos.y);

	if(MonsterBulletDelay >= 4)
	ObjMgr->KeepObject(new MonsterBullet(m_Position, m_Rotation), OBJECTLIST::BULLET_ENEMY);

}

void Ranger::Render()
{

	m_Sprite->Render();
}

void Ranger::OnCollision()
{
	RangerHp--;
}
