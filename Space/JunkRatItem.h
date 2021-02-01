#pragma once
class JunkRatItem : public Object
{
private:
	Sprite* m_Sprite;
	bool Item;

public:

	JunkRatItem(Vec2 Pos);

	void Update(float time);
	void Render();
	void OnCollision(Object* obj, std::string tag);

};

