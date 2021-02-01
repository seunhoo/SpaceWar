#pragma once
class Texture;
class Sprite : public Object
{
	LPD3DXSPRITE m_pSp;
	Texture* m_Texture;


public:
	RECT m_Rect;
	Sprite();
	~Sprite();

public:
	bool Init(std::wstring fileName);

public:
	RECT GetRect() { return m_Rect; }
	void SetRectSize(float x, float y);

	static Sprite* Create(std::wstring fileName);
	void Render();
};