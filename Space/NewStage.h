#pragma once
class NewStage : public Object
{
private:
	Sprite* m_Sprite;
	Sprite* m_BackGround;

	int MonsterSpawn;

public:

	NewStage();
	

	void Update( float time);
	void Render();
};

