#pragma once
class RipleItem : public Object
{
private:
	
	Sprite* m_Sprite;

public:
	RipleItem(Vec2 Pos);
	
	bool Item;

	void Update(float time);
	void Render();
	void OnCollision(Object* obj, std::string tag);

};

