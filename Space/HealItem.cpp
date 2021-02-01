#include "stdafx.h"
#include "HealItem.h"

HealItem::HealItem(Vec2 Pos)
{
	m_Sprite = Sprite::Create(L"Painting/Attack/Heal.png");
	m_Sprite->SetParent(this);

	m_ItemType = ITEM::REGENERATION;

	SetPosition2(Pos);

}

void HealItem::Update(float time)
{
	ObjMgr->CollideCheak(this, "Player");
}

void HealItem::Render()
{
	
	m_Sprite->Render();
}

void HealItem::OnCollision(Object* obj, std::string tag)
{
	if (tag == "Player")
	{
		ObjMgr->RemoveObject(this);
	}
}
