#pragma once
class BossShot : public Object
{
private:

	Sprite* m_Sprite;

	int AtkTime;

	int BulletSpeed;

	Vec2 m_Dir;

	Vec2 A, B;

public:
	BossShot(Vec2 Pos, float rotation, Vec2 Dir);
	
	void Update(float time);
	void Render();
	void Move(float time);
	void OnCollision(Object* obj, std::string tag);
};

