#pragma once
class BossStage : public Object
{
private:
	
	int MonsterSpawn;

public:

	BossStage();
	~BossStage();

	void Update(float time);
	void Render();

};

