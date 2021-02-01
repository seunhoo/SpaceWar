#pragma once
class JunkRatBullet : public Object
{
private:
	Sprite* m_Sprite;

	Vec2 m_Dir;
	Vec2 PrevPorisiotn;

	float MIN_distance;
	float PrevDistance;

public:
	JunkRatBullet(Vec2 Pos);
	~JunkRatBullet();

	void Update(float Time);
	void Move(int Time);
	void Render();
	void OnCollision(Object* obj, std::string tag);
};

