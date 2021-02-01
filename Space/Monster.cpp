#include "stdafx.h"
#include "Monster.h"
#include "MonsterBullet.h"
#include "Pass.h"
#include "Boss.h"
#include "Player.h"
#include "NextStage.h"
#include "DeathScene.h"
#include "RipleItem.h"
#include "SniperItem.h"
#include "JunkRatItem.h"
#include "HealItem.h"
#include "GameMgr.h"
#include "BossPass.h"


Monster::Monster(Vec2 Pos, ENEMYTYPE Etype) 
	: AttackDelay(1.f)
	, BossPassItem(false)
	
{
	m_Tag = "Monster";
	shot = true;
	timeCheck = false;


	m_State = new Animation();
	m_State->SetParent(this);


	m_Warrior = new  Animation();
	m_Warrior->Init(3, true);
	m_Warrior->AddContinueFrame(L"Painting/Enemy/Warrior", 0, 1);
	m_Warrior->SetParent(this);

	m_Warrior2 = new  Animation();
	m_Warrior2->Init(3, true);
	m_Warrior2->AddContinueFrame(L"Painting/Enemy/Warrior", 2, 3);
	m_Warrior2->SetParent(this);

	m_Ranger =  new Animation();
	m_Ranger->Init(3, true);
	m_Ranger->AddContinueFrame(L"Painting/Enemy/Ranger", 0, 1);
	m_Ranger->SetParent(this);

	m_Ranger2 = new Animation();
	m_Ranger2->Init(3, true);
	m_Ranger2->AddContinueFrame(L"Painting/Enemy/Ranger", 2, 3);
	m_Ranger2->SetParent(this);

	//m_MiniMapMonster = Sprite::Create(L"Painting/Enemy/MiniMapMonster.png");
	//m_MiniMapMonster->SetPosition(Pos.x, Pos.y);


	switch (Etype)
	{
	case ENEMYTYPE::WARRIOR:
		m_State = m_Warrior;
		MonsterHp = 24;
		m_Speed = 1.f;
		break;

	case ENEMYTYPE::WARRIOR2:
		m_State = m_Warrior2;
		MonsterHp = 22;
		m_Speed = 1.f;

		break;
	case ENEMYTYPE::RANGER:
		m_State = m_Ranger;
		MonsterHp = 1;
		AttackDelay = 1.f;
		break;
	case ENEMYTYPE::RANGER2:
		m_State = m_Ranger2;
		MonsterHp = 1;
		AttackDelay = 5.f;
		break;
	}
	m_Etype = Etype;
	SetPosition2(Pos);
}

Monster::~Monster()
{
	

}

void Monster::Update(float time)
{

	

	ObjMgr->CollideCheak(this, "NoneBullet");
	ObjMgr->CollideCheak(this, "RipleBullet");
	ObjMgr->CollideCheak(this, "SniperBullet");
	ObjMgr->CollideCheak(this, "JunkRatBullet");


	if (MonsterHp <= 0)
	{
		ObjMgr->RemoveObject(this);

		int random = rand() % 3 + 1;


		if (random == 1)
		{
			int random2 = rand() % 1 + 1;

			if (random2 == 1)
			{

				int random3 = rand() % 5 + 1;


				if (random3 == 1)
				{
					ObjMgr->KeepObject(new RipleItem(m_Position), "RipleItem");
				}

				if (random3 == 2)
				{
					ObjMgr->KeepObject(new SniperItem(m_Position), "SniperItem");
				}

				if (random3 == 3)
				{
					ObjMgr->KeepObject(new JunkRatItem(m_Position), "JunkRatItem");
				}

				if (random3 == 5)
				{
					int random4 = rand() % 3 + 1;

					if (random4 == 1 && BossPassItem == false)
					{
						ObjMgr->KeepObject(new Pass(m_Position), "PassItem");
						BossPassItem = true;
					}

					if (random4 == 2)
					{
						ObjMgr->KeepObject(new HealItem(m_Position), "HealItem");
					}

					if(random4 == 3 && BossPassItem == true)
					{
						ObjMgr->KeepObject(new BossPass(m_Position), "BossPass");
					}
				}

			}
		}






		GameMgr::GetInst()->CreateEffect(L"Painting/Animation/MonsterDie", m_Position, 0, 5);
		RankMgr::GetInst()->AddScore(15);

	}

	
	if (timeCheck == true)
	{
		StartTime = time;
		timeCheck = true;
	}

	


	

	cX = m_Position.x - ((Player*)ObjMgr->m_Objects.front())->m_Position.x;
	cY = m_Position.y - ((Player*)ObjMgr->m_Objects.front())->m_Position.y;

	if (abs(cX) >= 10 && abs(cY) >= 10)
	{
		closePlayer = true;
	}

	if (closePlayer)
	{
		Move(time);
	}

	AttackDelay++;

	m_State->Update(time);
	
}

void Monster::Render()
{
	m_State->Render();
	//m_MiniMapMonster->Render();

	m_State->R = 255;
	m_State->G = 255;
	m_State->B = 255;
	
}

void Monster::Move(float time)
{

	if (m_Etype == ENEMYTYPE::WARRIOR)
	{
		Vec2 pPos, mPos, Dir;
		pPos = ((Player*)ObjMgr->m_Objects.front())->m_Position;
		mPos = m_Position;
		mPos -= pPos;
		m_Rotation = atan2(-mPos.x, mPos.y);
		D3DXVec2Normalize(&Dir, &mPos);
		Translate(-Dir.x * m_Speed, -Dir.y * m_Speed);
	}
	else if (m_Etype == ENEMYTYPE::WARRIOR2)
	{
		Vec2 pPos, mPos, Dir;
		pPos = ((Player*)ObjMgr->m_Objects.front())->m_Position;
		mPos = m_Position;
		mPos -= pPos;
		m_Rotation = atan2(-mPos.x, mPos.y);
		D3DXVec2Normalize(&Dir, &mPos);
		Translate(-Dir.x * m_Speed, -Dir.y * m_Speed);
	}

	else if (m_Etype == ENEMYTYPE::RANGER && time - StartTime <= 3.f)
	{

	}
	else if (m_Etype == ENEMYTYPE::RANGER2)
	{
	}
	
	if (time - StartTime > 3 && m_Etype == ENEMYTYPE::WARRIOR2)
	{
		m_State = m_Warrior2;
	
	}

	if (time - StartTime > 6 && m_Etype == ENEMYTYPE::WARRIOR2)
	{
		StartTime = time;
		m_State = m_Warrior2;
	}

	if (m_Etype == ENEMYTYPE::RANGER)
	{
		Attack(time);

	}
	if (m_Etype == ENEMYTYPE::RANGER2)
	{
		Attack(time);

	}


	
}

void Monster::OnCollision(Object* other)
{
	

	

	m_State->R = 255;
	m_State->G = 51;
	m_State->B = 0;
}

void Monster::OnCollision(Object* obj, std::string tag)
{
	if (tag == "Player")
	{

	}
	if (tag == "NoneBullet")
	{
		MonsterHp -= 6;
	}
	if (tag == "SniperBullet")
	{
		MonsterHp -= 500;
	}
	if (tag == "RipleBullet")
	{
		MonsterHp -= 5;
	}
	if (tag == "JunkRatBullet")
	{
		MonsterHp -= 100;
	}

	
}

void Monster::Attack(float time)
{
	Vec2 pPos, mPos;
	pPos = ((Player*)ObjMgr->m_Objects.front())->m_Position;
	mPos = m_Position;
	mPos -= pPos;
	m_Rotation = atan2(-mPos.x, mPos.y);

	if (AttackDelay >= 100)
	{
		ObjMgr->KeepObject(new MonsterBullet(m_Position, m_Rotation), "MonsterBullet");
		AttackDelay = 0;
	}

	if (m_State->m_CurrentFrame == 5)
	{
		shot = true;
	}

}

