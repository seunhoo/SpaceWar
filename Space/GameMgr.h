#pragma once
class GameMgr : public Singleton<GameMgr>
{
public:
	std::list<Animation*> m_Effects;
	std::list<Animation*> m_Hill;


	int MonsterSpawn;
	bool GameClear;
	bool Check;
	float StartTime;

public:
	GameMgr();

	void CreateEnemy(Stage stage);
	void CreateEffect(std::wstring fileName, Vec2 Pos, int first, int second);
	void CreateEffect(std::wstring fileName, int first, int second);
	void Update(float time);
	void Render();
	void ReSet();
};

