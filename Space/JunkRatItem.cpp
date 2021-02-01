#include "stdafx.h"
#include "JunkRatItem.h"

JunkRatItem::JunkRatItem(Vec2 Pos)
{
	m_Sprite = Sprite::Create(L"Painting/Attack/JunkRat.png");
	m_Sprite->SetParent(this);

	m_ItemType = ITEM::JUNKRAT;

	SetPosition2(Pos);
}

void JunkRatItem::Update(float time)
{
	ObjMgr->CollideCheak(this, "Player");
}

void JunkRatItem::Render()
{
	m_Sprite->Render();
}

void JunkRatItem::OnCollision(Object* obj, std::string tag)
{
	if (tag == "Player")
	{
		ObjMgr->RemoveObject(this);
    }
}
