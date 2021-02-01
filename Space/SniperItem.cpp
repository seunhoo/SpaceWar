#include "stdafx.h"
#include "SniperItem.h"

SniperItem::SniperItem(Vec2 Pos)
{
	m_Sprite = Sprite::Create(L"Painting/Attack/Sniper.png");
	m_Sprite->SetParent(this);

	m_ItemType = ITEM::SNIPER;


	SetPosition2(Pos);
}

void SniperItem::Update(float time)
{
	ObjMgr->CollideCheak(this, "Player");
}

void SniperItem::Render()
{
	m_Sprite->Render();
}

void SniperItem::OnCollision(Object* obj, std::string tag)
{
	if (tag == "Player")
	{
		ObjMgr->RemoveObject(this);
	}
}
