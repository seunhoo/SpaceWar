#pragma once
class BossBullet : public Object
{
private:
	Sprite* m_BossBullet;
	Sprite* m_Shot;

	Vec2 m_Dir;
	int AtkTime;
	int ShotTime;

public:
	BossBullet(Vec2 Pos, float rotation);
	~BossBullet();

	void Update(float time);
	void Render();
	void Shot(float time);
	void OnCollision(Object* obj, std::string tag);
};

