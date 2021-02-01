#pragma once
class Boss : public Object
{
private:
	Sprite* m_State;
	Sprite* m_NomalState;
	Sprite* m_AtkState;


	int m_BossHp;
	float m_Speed;

	int AtkDelay;
	int ShotDelay;
	int ShotTime;


	int MovedDelay;
	
	bool AtkCheck;
	bool ShotCheck;
	

public:
	Boss(Vec2 Pos);
	~Boss();
	


	void Update(float time);
	void Render();
	void Move(float time);
	void Atk(float time);
	void Shot(float time);

	void OnCollision(Object* obj, std::string tag);

};

