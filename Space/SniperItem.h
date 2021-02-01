#pragma once
class SniperItem : public Object
{
private:

	Sprite* m_Sprite;

	bool Item;

public:

	SniperItem(Vec2 Pos);

	void Update(float time);
	void Render();
	void OnCollision(Object* obj, std::string tag);

};

