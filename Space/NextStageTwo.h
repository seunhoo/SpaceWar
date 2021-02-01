#pragma once
class NextStageTwo : public Object
{
private:
	Sprite* m_NextStage;
	Sprite* m_MonsterDeathScene;

	bool Clear;

public:
	NextStageTwo();
	~NextStageTwo();

	void Update(float time);
	void Render();

};

