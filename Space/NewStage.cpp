#include "stdafx.h"
#include "Player.h"
#include "NewStage.h"
#include "Monster.h"
#include "NextStage.h"

NewStage::NewStage() 
	: MonsterSpawn(10)
{
	ObjMgr->KeepObject(new Player(), "Player");

	m_BackGround = Sprite::Create(L"Painting/SpaceBackGround.png");
	m_BackGround->SetParent(this);

	SceneDirector::GetInst()->m_Stage = Stage::STAGEONE;
	SetPosition(3500 / 2, 3500 / 2);
}


void NewStage::Update(float time)
{
	printf("%d  \n", MonsterSpawn);
	MonsterSpawn++;
	if (MonsterSpawn >= 130)
	{
		GameMgr::GetInst()->CreateEnemy(Stage::STAGEONE);
		GameMgr::GetInst()->ReSet();
		MonsterSpawn = 0;
	}

	if (INPUT->GetKey(VK_ESCAPE) == KeyState::DOWN)
	{
		App::GetInst()->Release();
		exit(0);
	}

	RECT rect;
	if (INPUT->GetKey(VK_TAB) == KeyState::DOWN && ((Player*)ObjMgr->m_Objects.front())->HavePass)
	{
		SCENE->ChangeScene(new NextStage());
	}
	GameMgr::GetInst()->Update(time);
}

void NewStage::Render()
{
	m_BackGround->Render();
	GameMgr::GetInst()->Render();

	TCHAR szScore[32] = L"";
	int Score = RankMgr::GetInst()->GetScore();
	wsprintf(szScore, L"%d", Score);

	Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
	Matrix matFont;

	D3DXMatrixTranslation(&matFont, 1920 / 2 - 25, 50, 0);
	Renderer::GetInst()->GetSprite()->SetTransform(&matFont);
	Renderer::GetInst()->GetFont()->DrawTextW(Renderer::GetInst()->GetSprite(), szScore, 32, NULL, NULL, D3DCOLOR_ARGB(255, 219, 152, 39));
	Renderer::GetInst()->GetSprite()->End();
	

}
