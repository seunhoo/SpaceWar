#pragma once
class Pass : public Object
{
private:
	Sprite* m_Sprite;
	Sprite* m_PassBlock;

public:
	Pass(Vec2 Pos);

	void Update(float time);
	void Render();

	void OnCollision(Object* obj, std::string tag);
};

