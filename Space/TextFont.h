#pragma once
//Write to Render()
class TextFont : public Singleton<TextFont>
{
	LPD3DXFONT m_Font;
public:
	TextFont();
	~TextFont();

	void Init(int w, UINT h, bool italic);
	void Print(LPCWSTR str, int x, int y, int r, int g, int b);
	void Remove();
	void Release();
};



