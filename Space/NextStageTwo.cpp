#include "stdafx.h"
#include "NextStageTwo.h"
#include "Monster.h"
#include "Boss.h"
#include "BossStage.h"
#include "StageTwo.h"

NextStageTwo::NextStageTwo()
	: Clear(false)
{

	m_NextStage = Sprite::Create(L"Painting/BackGround/NextStage.png");
	m_NextStage->SetPosition(400, 800);

	m_MonsterDeathScene = Sprite::Create(L"Painting/BackGround/StageClear.png");
	m_MonsterDeathScene->SetPosition(1980 / 2, 560);
}
NextStageTwo::~NextStageTwo()
{
}

void NextStageTwo::Update(float time)
{
	if (CollisionMgr::GetInst()->MouseWithBoxCollide(m_NextStage->m_Collision) && INPUT->GetButtonDown())
	{
		SceneDirector::GetInst()->ChangeScene(new BossStage());
	}
	if (Clear == false)
	{
		ObjectMgr::GetInst()->Release();
		Clear = true;
	}

}

void NextStageTwo::Render()
{
	m_MonsterDeathScene->Render();
	m_NextStage->Render();
}


