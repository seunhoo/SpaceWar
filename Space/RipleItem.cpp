#include "stdafx.h"
#include "Player.h"
#include "RipleItem.h"

RipleItem::RipleItem(Vec2 Pos)
{
	m_Sprite = Sprite::Create(L"Painting/Attack/Riple.png");
	m_Sprite->SetParent(this);

	m_ItemType = ITEM::RIPLE;


	SetPosition2(Pos);
}

void RipleItem::Update(float time)
{
	ObjMgr->CollideCheak(this, "Player");
}

void RipleItem::Render()
{
	m_Sprite->Render();
}

void RipleItem::OnCollision(Object* obj, std::string tag)
{
	if (tag == "Player")
	{
		ObjMgr->RemoveObject(this);
	}
}
