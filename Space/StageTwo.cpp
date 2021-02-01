#include "stdafx.h"
#include "StageTwo.h"
#include "Monster.h"
#include "Ranger.h"
#include "Player.h"

StageTwo::StageTwo()
	: MonsterSpawn(400)
{
	
	ObjMgr->KeepObject(new Player(), "Player");
	m_Sprite = Sprite::Create(L"Painting/BackGround.png");
	m_Sprite->SetParent(this);

	SCENE->m_Stage = Stage::STAGETWO;

	Vec2 A;
	A.x = 50;
	A.y = 1700;


	SetPosition(3500 / 2, 3500 / 2);
}

void StageTwo::Update(float time)
{
	MonsterSpawn++;
	printf("%d \n", MonsterSpawn);
	if (MonsterSpawn >= 300)
	{
		GameMgr::GetInst()->CreateEnemy(Stage::STAGETWO);
		MonsterSpawn = 0;
	}

	GameMgr::GetInst()->Update(time);
}

void StageTwo::Render()
{

	m_Sprite->Render();
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
