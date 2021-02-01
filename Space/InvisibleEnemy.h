#pragma once
class InvisibleEnemy : public Object
{
private:

	Sprite* m_Sprite;

	int KillTime;

public:
	InvisibleEnemy(Vec2 Pos, float rotation);

	void Update(float time);
	void Render();
	void OnCollision(Object* obj, std::string tag);

};

