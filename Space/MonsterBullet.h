#pragma once
class MonsterBullet : public Object
{
private:
	Sprite* m_MonsterBullet;
	Vec2 m_Dir;
	float m_Speed;

public:
	MonsterBullet(Vec2 Pos, float rotation);
	

	void Update(float time);
	void Render();
	void Move(float time);
	void OnCollision(Object* obj, std::string tag);
	
};

