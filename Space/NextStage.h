#pragma once
class NextStage : public Object
{
private:
	Sprite* m_NextStage;
	Sprite* m_MonsterDeathScene;

	bool Clear;

	bool StageCheck;

public:
	NextStage();
	~NextStage();

	void Update(float time);
	void Render();

};

