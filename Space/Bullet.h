#pragma once
class Bullet : public Object
{
private:
	Sprite* m_Sprite;
	Vec2 m_Dir;

public:
	Bullet(Vec2 Pos, float rotate);

	void Update(float time);
	void Render();
	void Move(float time);
	void OnCollision(Object* obj, std::string tag);

	
};

