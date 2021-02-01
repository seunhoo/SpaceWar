#include "stdafx.h"
#include "InvisibleEnemy.h"

InvisibleEnemy::InvisibleEnemy(Vec2 Pos, float rotation)
{
	m_Sprite = Sprite::Create(L"Painting/Enemy/InvisibleEnemy.png");
	m_Sprite->SetParent(this);

	SetPosition2(Pos);
}

void InvisibleEnemy::Update(float time)
{

	KillTime++;
	if (KillTime >= 120)
	{
		ObjMgr->RemoveObject(this);
	}

	ObjMgr->CollideCheak(this, "BossShot");
}

void InvisibleEnemy::Render()
{
	m_Sprite->Render();
}

void InvisibleEnemy::OnCollision(Object* obj, std::string tag)
{
	ObjMgr->RemoveObject(this);
}
