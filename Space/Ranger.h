#pragma once
class Ranger : public Object
{
private:
	Sprite* m_Sprite;


	int StartTime;

	int EndTime;

	int MonsterBulletDelay;

	int RangerHp;

public:
	Ranger(Vec2 Pos, float rotate);

	void Update(float time);

	void Move(float time);

	void Attack(float time);

	void Render();

	void OnCollision();
};

