#include "stdafx.h"
#include "JunkRatBullet.h"

JunkRatBullet::JunkRatBullet(Vec2 Pos)
	: PrevDistance(10000)
{
	m_Sprite = Sprite::Create(L"Painting/Attack/MonsterBullet2.png");
	m_Sprite->SetParent(this);

	m_Atk = 10.f;
	m_Speed = 9.f;

	SetPosition(Pos.x, Pos.y);
}

JunkRatBullet::~JunkRatBullet()
{

}

void JunkRatBullet::Update(float Time)
{
	ObjMgr->CollideCheak(this, "Monster");
	ObjMgr->CollideCheak(this, "Boss");

	Vec2 A = m_Position;
	
	Vec2 B, C;

	PrevDistance = 10000;

	for (auto iter = ObjMgr->m_Objects.begin(); iter != ObjMgr->m_Objects.end(); ++iter)
	{
		if ((*iter)->m_Tag == "Monster")
		{
			float distance = std::sqrt(double(((*iter)->m_Position.x - m_Position.x) * ((*iter)->m_Position.x - m_Position.x) +
				((*iter)->m_Position.y - m_Position.y) * ((*iter)->m_Position.y - m_Position.y)));

			if (PrevDistance > distance)
			{
				PrevDistance = distance;
				B = (*iter)->m_Position;
			}
		}
	}

	C = B - A;
	A -= B;

	m_Rotation = atan2(C.y, C.x);
	D3DXVec2Normalize(&m_Dir, &A);
	Move(Time);
}

void JunkRatBullet::Move(int Time)
{
	Translate(-m_Dir.x * m_Speed, -m_Dir.y * m_Speed);
}

void JunkRatBullet::Render()
{
	m_Sprite->Render();
}

void JunkRatBullet::OnCollision(Object* obj, std::string tag)
{
	ObjMgr->RemoveObject(this);
}
