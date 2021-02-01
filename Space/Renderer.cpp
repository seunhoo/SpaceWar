#include "stdafx.h" //���� ������� �ʴ� �� �ҽ��� stdafx�� �ְ� �̸� �������� �صд�.������ stdafx.h�� ����Ͽ� ��ü ������ �ӵ��� ��½�Ų��.
#include "Renderer.h" // ������


Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}

void Renderer::Release()
{

	m_pD3D->Release();
	m_pDevice->Release();
	m_pSprite->Release();
	m_pFont->Release();
}

bool Renderer::Init(int width, int height, bool windowMode)
{
	m_pD3D = Direct3DCreate9(D3D_SDK_VERSION); //�� �Ķ������ ���� D3D_SDK_VERSION �� �ƴϸ� �ȵȴ�.

	D3DPRESENT_PARAMETERS pp = {}; //���������̼� �Ķ���͸� ����Ѵ�.
	pp.BackBufferWidth = width;
	pp.BackBufferHeight = height;
	pp.BackBufferFormat = D3DFMT_A8R8G8B8;
	pp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	pp.Windowed = windowMode;

	HRESULT hr = m_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, App::GetInst()->GetHwnd(), //HRESULT�� �Լ��� ȣ�� ����� ��Ÿ���� 32��Ʈ�� ���� ǥ���ϸ� 
																																																																																																																																																					 //�Լ��� ���������� ȣ��� ��� S_OK�� �����ϴ� ���� ������ �������ش�.
		D3DCREATE_SOFTWARE_VERTEXPROCESSING, &pp, &m_pDevice); //D3DCREATE_MIXED_VERTEX_PROCESSING�� ����� ��쿡�� �ϵ���� ���Ӱ� ����Ʈ���� ������ �����߿� ��ȯ�� �� �ִ�.

	if FAILED(hr)
		return false;

	D3DXCreateSprite(m_pDevice, &m_pSprite);

	D3DXFONT_DESC fontInfo;

	ZeroMemory(&fontInfo, sizeof(D3DXFONT_DESC));
	fontInfo.Width = 50.f;
	fontInfo.Height = 100.f;
	fontInfo.Weight = FW_NORMAL;
	fontInfo.CharSet = HANGUL_CHARSET;
	lstrcpy(fontInfo.FaceName, L"���� ���");
	D3DXCreateFontIndirect(m_pDevice, &fontInfo, &m_pFont);

	ZeroMemory(&fontInfo, sizeof(D3DXFONT_DESC));
	fontInfo.Width = 20.f;
	fontInfo.Height = 40.f;
	fontInfo.Weight = FW_NORMAL;
	fontInfo.CharSet = HANGUL_CHARSET;
	lstrcpy(fontInfo.FaceName, L"���� ���");
	D3DXCreateFontIndirect(m_pDevice, &fontInfo, &m_bFont);

	return true;
}

LPD3DXFONT Renderer::GetFont()
{
	return m_pFont;
}

LPD3DXFONT Renderer::GetBulletFont()
{
	return m_bFont;
}

void Renderer::Begin()
{
	m_pDevice->BeginScene();
	m_pDevice->Clear(0, 0, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.f, 0);
	//D3DCLEAR_TARGET ����Ʈ �Ǵ� ����Ʈ���� ���簢�� ��Ʈ�� ������ RGBA ���� Ŭ���� ��, ���� ���۸� Ŭ���� ��, ���ٽ� ���۸� �����Ѵ�.(?)
	//D3DCOLOR_XRGB �Ϲ������� ������ ����, ����, ��� �� �Ķ� ���� ��Ҹ� ��Ÿ���� 4 ����Ʈ ���Դϴ�. �ֵ� �� ��⸦ ��Ÿ�� ���� �ֽ��ϴ�.
}

void Renderer::End()
{
	m_pDevice->EndScene();
	m_pDevice->Present(0, 0, 0, 0);
}
