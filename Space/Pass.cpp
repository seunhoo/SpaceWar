#include "stdafx.h"
#include "Player.h"
#include "Pass.h"

Pass::Pass(Vec2 Pos)
{
	m_Sprite = Sprite::Create(L"Painting/Pass.png");
	m_Sprite->SetParent(this);
	SetPosition2(Pos);

}

void Pass::Update(float time)
{
	ObjMgr->CollideCheak(this, "Player");

}

void Pass::Render()
{
	m_Sprite->Render();
	
}

void Pass::OnCollision(Object* obj, std::string tag)
{
	if (tag == "Player")
	{
		ObjMgr->RemoveObject(this);
	}
}

