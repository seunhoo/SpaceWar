#include "stdafx.h"  //자주 변경되지 않는 긴 소스를 stdafx에 넣고 미리 컴파일을 해둔다.본문에 stdafx.h를 사용하여 전체 컴파일 속도를 상승시킨다.
#include "TextFont.h"

TextFont::TextFont() : m_Font(0)
{
}

TextFont::~TextFont()
{
}

void TextFont::Init(int w, UINT h, bool italic)
{
	D3DXCreateFont(Renderer::GetInst()->GetDevice(), w, h, FW_NORMAL, 1, italic,
		DEFAULT_CHARSET, OUT_CHARACTER_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"나눔고딕", &m_Font);
}

void TextFont::Print(LPCWSTR str, int x, int y, int r, int g, int b)
{
	RECT rect;
	SetRect(&rect, x, y, 0, 0);
	m_Font->DrawText(NULL, str, -1, &rect, DT_NOCLIP, D3DCOLOR_XRGB(r, g, b));
}

void TextFont::Remove()
{
	SafeDelete(m_Font);
}

void TextFont::Release()
{
	if(m_Font != nullptr)
		m_Font->Release();
}


