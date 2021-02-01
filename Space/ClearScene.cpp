#include "stdafx.h"
#include "ClearScene.h"
#include "SceneMain.h"

ClearScene::ClearScene() : Clear(false)
{
	m_ClearScene = Sprite::Create(L"Painting/BackGround/GameClear.png");
	m_ClearScene->SetParent(this);
	SetPosition(1920 / 2, 1080 / 2);

	m_SelectScene = Sprite::Create(L"Painting/BackGround/GotoMainMenu.png");
	m_SelectScene->SetPosition(1580, 800);
}

ClearScene::~ClearScene()
{
}

void ClearScene::Update(float time)
{
	if (CollisionMgr::GetInst()->MouseWithBoxCollide(m_SelectScene->m_Collision) && INPUT->GetButtonDown())
	{
		SceneDirector::GetInst()->ChangeScene(new SceneMain());
	}
	if (!Clear) 
	{
		ObjectMgr::GetInst()->Release();
		Clear = true;
	}
}

void ClearScene::Render()
{
	m_SelectScene->Render();
	m_ClearScene->Render();
}

void ClearScene::OnCollision(Object* other)
{

}