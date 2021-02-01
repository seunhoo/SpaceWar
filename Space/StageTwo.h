#pragma once
class StageTwo : public Object
{
private:
	Sprite* m_Sprite;

	int MonsterSpawn;

public:
	StageTwo();

	void Update(float time);
	void Render();
};

