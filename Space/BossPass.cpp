#include "stdafx.h"
#include "Player.h"
#include "BossPass.h"

BossPass::BossPass(Vec2 Pos)
{
	m_Sprite = Sprite::Create(L"Painting/BossPass.png");
	m_Sprite->SetParent(this);

	m_ItemType = ITEM::PASS;

	SetPosition2(Pos);
}

void BossPass::Update(float time)
{
	ObjMgr->CollideCheak(this,"Player");
}

void BossPass::Render()
{
	m_Sprite->Render();
}

void BossPass::OnCollision(Object* obj, std::string tag)
{
	if (tag == "Player")
	{
		ObjMgr->RemoveObject(this);
	}
}
