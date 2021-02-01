#include "stdafx.h"
#include "DeathScene.h"
#include "SceneMain.h"	

DeathScene::DeathScene() : Die(false)
{
	
	m_DeathScene = Sprite::Create(L"Painting/BackGround/Gameover.png");
	m_DeathScene->SetPosition(1920 / 2, 540);

	m_SelectScene = Sprite::Create(L"Painting/BackGround/GotoMainMenu.png");
	m_SelectScene->SetPosition(1580, 800);
	
}
DeathScene::~DeathScene()
{

}

void DeathScene::Update(float time)
{
	
	if (CollisionMgr::GetInst()->MouseWithBoxCollide(m_SelectScene->m_Collision) && INPUT->GetButtonDown())
	{
		SceneDirector::GetInst()->ChangeScene(new SceneMain());
	}
	if (!Die)
	{
		ObjectMgr::GetInst()->Release();
		Die = true;
	}
}

void DeathScene::Render()
{
	m_SelectScene->Render();
	m_DeathScene->Render();
}

