#include "stdafx.h"
#include "BossStage.h"
#include "Boss.h"

BossStage::BossStage()
	: MonsterSpawn(6000)
{
	ObjectMgr::GetInst()->KeepObject(new Player(), "Player");

	SceneDirector::GetInst()->m_Stage = Stage::STAGETHREE;
	SetPosition(3500 / 2, 3500 / 2);
}

BossStage::~BossStage()
{
}

void BossStage::Update(float time)
{
	MonsterSpawn++;
	if (MonsterSpawn >= 6000)
	{
		GameMgr::GetInst()->CreateEnemy(Stage::STAGETHREE);
		MonsterSpawn = 0;
	}


	if (INPUT->GetKey(VK_ESCAPE) == KeyState::DOWN)
	{
		App::GetInst()->Release();
		exit(0);
	}
	///*MonsterSpawn++;

	//if (MonsterSpawn >= 150)
	//{
	//	GameMgr::GetInst()->CreateEnemy(Stage::STAGETWO);
	//	MonsterSpawn = 0;
	//}
	//if (MonsterSpawn >= 200)
	//{
	//	GameMgr::GetInst()->CreateEnemy(Stage::STAGEONE);
	//	*/MonsterSpawn = 0;
	//}

	GameMgr::GetInst()->Update(time);

}

void BossStage::Render()
{
	GameMgr::GetInst()->Render();

	TCHAR szScore[32] = L"12";
	int Score = RankMgr::GetInst()->GetScore();
	wsprintf(szScore, L"%d", Score);

	Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
	Matrix matFont;

	D3DXMatrixTranslation(&matFont, 1920 / 2 - 25, 50, 0);
	Renderer::GetInst()->GetSprite()->SetTransform(&matFont);
	Renderer::GetInst()->GetFont()->DrawTextW(Renderer::GetInst()->GetSprite(), szScore, 32, NULL, NULL, D3DCOLOR_ARGB(255, 219, 152, 39));
	Renderer::GetInst()->GetSprite()->End();
}
