#include "stdafx.h"
#include "Boss.h"
#include "BossBullet.h"
#include "ClearScene.h"
#include "MonsterBullet.h"
#include "BossShot.h"

Boss::Boss(Vec2 Pos)
	: ShotDelay(200)
	, ShotCheck(false)
	, ShotTime(false)
{

	m_State = Sprite::Create(L"Painting/Enemy/ABoss0.png");
	m_State->SetParent(this);

	m_BossHp = 500;
	m_Speed = 0.8f;
	SetPosition2(Pos);

	/*Vec2 A, B;
	A = m_Position;
	B = ((Player*)ObjMgr->m_Objects.front())->m_Position;

	Object* obj = ((Player*)ObjMgr->m_Objects.front());
	this;

	A -= B;
	D3DXVec2Normalize(&m_Dir, &A);*/

}

Boss::~Boss()
{
}

void Boss::Update(float time)
{
	ObjMgr->CollideCheak(this, "Player");
	ObjMgr->CollideCheak(this, "JunkRatBullet");
	ObjMgr->CollideCheak(this, "SniperBullet");
	ObjMgr->CollideCheak(this, "NoneBullet");
	ObjMgr->CollideCheak(this, "RipleBullet");

	AtkDelay++;
	ShotTime++;

	/*if (ShotTime >= 290)
	{
		Shot(time);
		ShotTime = 0;
	}*/
	if (AtkDelay >= ShotDelay)
	{

		Atk(time);

		if (AtkDelay >= ShotDelay )
		{
			AtkDelay = 0;
			/*ShotDelay -= 50;*/
		}
		if (ShotDelay <= 30)
		{
			ShotDelay = 200;
		}

		/*ShotDelay -= 50;

		AtkDelay = 0;

		ShotCheck = true;

		Atk(time);

		ShotTime = true;

		if (ShotTime == true)
		{
			ShotCheck = false;

			Atk(time);

			ShotCheck = true;

			ShotTime = false;
		}
		if(ShotDelay <= -50)
		{
			ShotDelay = 200;
		}*/

	}
	else
	{
		Move(time);
	}

	

	if (m_BossHp <= 0)
	{
		ObjMgr->RemoveObject(this);
		RankMgr::GetInst()->AddScore(3000);
		GameMgr::GetInst()->CreateEffect(L"Painting/Animation/MonsterDie", m_Position, 0, 5);
		/*GameMgr::GetInst()->GameClear = true;*/

		SCENE->ChangeScene(new ClearScene());
	}
}

void Boss::Render()
{
	m_State->Render();
	m_State->R = 255;
	m_State->G = 255;
	m_State->B = 255;

}

void Boss::Move(float time)
{
	Vec2 pPos, mPos, Dir;
	pPos = ((Player*)ObjMgr->m_Objects.front())->m_Position;
	mPos = m_Position;
	mPos -= pPos;
	m_Rotation = atan2(-mPos.x, mPos.y);
	D3DXVec2Normalize(&Dir, &mPos);
	Translate(-Dir.x * m_Speed, -Dir.y * m_Speed);
}

void Boss::Atk(float time)
{
	
		Vec2 pPos, mPos;
		pPos = ((Player*)ObjMgr->m_Objects.front())->m_Position;
		mPos = m_Position;
		mPos -= pPos;
		m_Rotation = atan2(-mPos.x, mPos.y);

		ObjMgr->KeepObject(new BossBullet(m_Position, m_Rotation), "BossTrigger");	
	

		

		

}

void Boss::Shot(float time)
{	
}

void Boss::OnCollision(Object* obj, std::string tag)
{

	if (tag == "Player")
	{

	}
	if (tag == "NoneBullet")
	{
		m_BossHp -= 6;
	}
	if (tag == "SniperBullet")
	{
		m_BossHp -= 50;
	}
	if (tag == "RipleBullet")
	{
		m_BossHp -= 5;
	}
	if (tag == "JunkRatBullet")
	{
		m_BossHp -= 80;
	}
}
