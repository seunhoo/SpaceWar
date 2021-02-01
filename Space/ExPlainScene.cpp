#include "stdafx.h"
#include "ExPlainScene.h"
#include "SceneMain.h"

ExPlainScene::ExPlainScene()
{
	m_Explain = Sprite::Create(L"Painting/BackGround/tjfaud.png");
	m_Explain->SetPosition(1920 / 2, 1080 / 2);

	m_dlcksdn = Sprite::Create(L"Painting/BackGround/GotoMainMenu.png");
	m_dlcksdn->SetPosition(1500, 800);
}

void ExPlainScene::Update(float time)
{
	if (CollisionMgr::GetInst()->MouseWithBoxCollide(m_dlcksdn->m_Collision) && INPUT->GetButtonDown())
	{

		SceneDirector::GetInst()->ChangeScene(new SceneMain());
	}
}

void ExPlainScene::Render()
{
	m_Explain->Render();
	m_dlcksdn->Render();
}
