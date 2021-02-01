#include "stdafx.h"
#include "NextStage.h"
#include "Monster.h"
#include "Boss.h"
#include "BossStage.h"
#include "StageTwo.h"

NextStage::NextStage() 
	: Clear(false)
	, StageCheck(false)
{

	m_NextStage = Sprite::Create(L"Painting/BackGround/NextStage.png");
	m_NextStage->SetPosition(400, 800);

	m_MonsterDeathScene = Sprite::Create(L"Painting/BackGround/StageClear.png");
	m_MonsterDeathScene->SetPosition(1980 / 2, 560);
}
NextStage::~NextStage()
{
}

void NextStage::Update(float time)
{
    if (CollisionMgr::GetInst()->MouseWithBoxCollide(m_NextStage->m_Collision) && INPUT->GetButtonDown())
	{
		StageCheck = true;
		SceneDirector::GetInst()->ChangeScene(new StageTwo());
			   
		if (StageCheck == true)
		{
			SceneDirector::GetInst()->ChangeScene(new BossStage());
		}
	}
	if (Clear == false)
	{
		ObjectMgr::GetInst()->Release();
		Clear = true;
	}

}

void NextStage::Render()
{
	m_MonsterDeathScene->Render();
	m_NextStage->Render();
}


