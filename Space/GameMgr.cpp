#include "stdafx.h"
#include "Monster.h"
#include "Player.h"
#include "Boss.h"
#include "GameMgr.h"
#include "NextStage.h"


GameMgr::GameMgr() 
	: GameClear(false)
	, Check(false)
	, StartTime(0.f)
	, MonsterSpawn(0)
{
}

void GameMgr::CreateEnemy(Stage stage)
{
	if (stage == Stage::STAGEONE)
	{
				for (int i = 0; i <= 1; i++)
				{
					int random = rand() % 2 + 1;
					Vec2 ePos;
					ePos.x = rand() % 1920;
					ePos.y = rand() % 1080;
					printf("%f %f \n", ePos.x, ePos.y);
					if (random == 1)
					{
						ObjMgr->KeepObject(new Monster(ePos, ENEMYTYPE::WARRIOR), "Monster");
					}
					else
					{
						ObjMgr->KeepObject(new Monster(ePos, ENEMYTYPE::WARRIOR2), "Monster");
					}
				}
		
		

	}
	else if (stage == Stage::STAGETWO)
	{
		for (int i = 0; i <= 2; i++)
		{
			int random = rand() % 2 + 1;
			Vec2 ePos;
			ePos.x = rand() % 1920;
			ePos.y = rand() % 1080;
			printf("%f %f \n", ePos.x, ePos.y);
			if (random == 1)
			{
				ObjMgr->KeepObject(new Monster(ePos, ENEMYTYPE::RANGER), "Monster");
			}
			else
			{
				ObjMgr->KeepObject(new Monster(ePos, ENEMYTYPE::RANGER2), "Monster");
			}
		}

		

	}
	else if (stage == Stage::STAGETHREE)
	{
		Vec2 ePos;
		ePos.x = rand() % 1920;
		ePos.y = rand() & 1080;

		ObjMgr->KeepObject(new Boss(ePos), "Boss");
	}
}

void GameMgr::CreateEffect(std::wstring fileName, Vec2 Pos, int first, int second)
{
	Animation* iter = new Animation();
	iter->Init(3, true);
	iter->AddContinueFrame(fileName, first, second);
	iter->SetPosition2(Pos);
	iter->m_Scale.x *= 1.5f;
	iter->m_Scale.y *= 1.5f;

	m_Effects.push_back(iter);
}

void GameMgr::CreateEffect(std::wstring fileName, int first, int second)
{
	Animation* iter = new Animation();
	iter->Init(3, true);
	iter->AddContinueFrame(fileName, first, second);
	iter->SetPosition2(((Player*)ObjMgr->m_Objects.front())->m_Position);
	iter->m_Scale.x *= 1.5f;
	iter->m_Scale.y *= 1.5f;

	m_Hill.push_back(iter);
}

void GameMgr::Update(float time)
{

	if (GameClear)
	{
		if (Check == false)
		{
			StartTime = time;
			Check = true;
		}

		if (time - StartTime >= 2)
		{
			SCENE->ChangeScene(new NextStage());
		}
	}
	for (auto iter = m_Effects.begin(); iter != m_Effects.end();)
	{
		if ((*iter)->m_CurrentFrame == (*iter)->m_LastFrame)
		{
			Object* temp = (*iter);
			iter = m_Effects.erase(iter);
			SAFE_DELETE(temp);
		}
		else
		{
			++iter;
		}
	}
	for (auto iter = m_Hill.begin(); iter != m_Hill.end();)
	{
		if ((*iter)->m_CurrentFrame == (*iter)->m_LastFrame)
		{
			Object* temp = (*iter);
			iter = m_Hill.erase(iter);
			SAFE_DELETE(temp);
		}
		else
		{

			++iter;
		}
	}

	for (auto& iter : m_Effects)
	{
		iter->Update(time);
	}
	for (auto& iter : m_Hill)
	{
		iter->Update(time);
	}


}

void GameMgr::Render()
{
	for (auto& iter : m_Effects)
	{
		iter->Render();

	}
	for (auto& iter : m_Hill)
	{
		iter->SetPosition2(((Player*)ObjMgr->m_Objects.front())->m_Position);
		iter->Render();
	}
}

void GameMgr::ReSet()
{
	GameClear = false;
	Check = false;
	StartTime = 0.f;
}
