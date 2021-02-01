#pragma once
class BossPass : public Object
{
private:

	Sprite* m_Sprite;

public:

	BossPass(Vec2 Pos);
	
	void Update(float time);
	void Render();

	void OnCollision(Object* obj, std::string tag);

};

