#pragma once
class RipleBullet : public Object
{
private:
	Sprite* m_Sprite;
	Vec2 m_Dir;

public:
	RipleBullet(Vec2 Pos, float rotate);

	void Update(float time);
	void Render();
	void Move(float time);
	void OnCollision(Object* other);
	void OnCollision(Object* obj, std::string tag);
};

