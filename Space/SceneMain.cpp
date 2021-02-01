#include "stdafx.h"  //���� ������� �ʴ� �� �ҽ��� stdafx�� �ְ� �̸� �������� �صд�.������ stdafx.h�� ����Ͽ� ��ü ������ �ӵ��� ��½�Ų��.
#include "Monster.h"
#include "SceneMain.h"
#include "BossStage.h"
#include "ExPlainScene.h"
#include "NewStage.h"
#include"NextStage.h"

SceneMain::SceneMain()
{
	m_MainMenu = Sprite::Create(L"Painting/BackGround/Tjaspdlf.png");
	m_MainMenu->SetPosition(1920 / 2, 1080 / 2);

	m_StartButton = Sprite::Create(L"Painting/BackGround/NewStage.png");
	m_StartButton->SetPosition(600, 1010);
	m_Buttons.push_back(m_StartButton);

	m_ExplainButton = Sprite::Create(L"Painting/BackGround/tjfaudqjxms.png");
	m_ExplainButton->SetPosition(1500, 1010);
	m_Buttons.push_back(m_ExplainButton);


	//SoundMgr::GetInst()->Play(L"BackGround.wav", true);
}

SceneMain::~SceneMain()
{
}

void SceneMain::Update(float time)
{
	int num = 1;
	for (auto& iter : m_Buttons)
	{
		if (CollisionMgr::GetInst()->MouseWithBoxCollide(iter->m_Collision) && INPUT->GetButtonDown())
		{
			if (num == 1)
			{
				SceneDirector::GetInst()->ChangeScene(new NewStage());
			}
			if (num == 2)
			{
				SceneDirector::GetInst()->ChangeScene(new ExPlainScene());
			}
		}
		num++;
	}
	/*if (CollisionMgr::GetInst()->MouseWithBoxCollide(m_StartButton->m_Collision) && INPUT->GetButtonDown())
	{
		SceneDirector::GetInst()->ChangeScene(new NewStage());
	}

	if (CollisionMgr::GetInst()->MouseWithBoxCollide(m_ExplainButton->m_Collision) && INPUT->GetButtonDown())
	{
		SceneDirector::GetInst()->ChangeScene(new ExPlainScene());
	}*/
}

void SceneMain::Render()
{
	m_MainMenu->Render();
	m_StartButton->Render();

	m_ExplainButton->Render();
}
