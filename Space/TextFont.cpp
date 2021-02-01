#include "stdafx.h"  //���� ������� �ʴ� �� �ҽ��� stdafx�� �ְ� �̸� �������� �صд�.������ stdafx.h�� ����Ͽ� ��ü ������ �ӵ��� ��½�Ų��.
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
		DEFAULT_CHARSET, OUT_CHARACTER_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"�������", &m_Font);
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


