#include "stdafx.h" //자주 변경되지 않는 긴 소스를 stdafx에 넣고 미리 컴파일을 해둔다.본문에 stdafx.h를 사용하여 전체 컴파일 속도를 상승시킨다.
#include "Renderer.h" // 렌더러


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
	m_pD3D = Direct3DCreate9(D3D_SDK_VERSION); //이 파라미터의 값은 D3D_SDK_VERSION 가 아니면 안된다.

	D3DPRESENT_PARAMETERS pp = {}; //프레젠테이션 파라미터를 기술한다.
	pp.BackBufferWidth = width;
	pp.BackBufferHeight = height;
	pp.BackBufferFormat = D3DFMT_A8R8G8B8;
	pp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	pp.Windowed = windowMode;

	HRESULT hr = m_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, App::GetInst()->GetHwnd(), //HRESULT는 함수의 호출 결과를 나타내는 32비트의 값을 표현하며 
																																																																																																																																																					 //함수가 성공적으로 호출된 경우 S_OK를 리턴하는 등의 정보를 제공해준다.
		D3DCREATE_SOFTWARE_VERTEXPROCESSING, &pp, &m_pDevice); //D3DCREATE_MIXED_VERTEX_PROCESSING을 사용할 경우에는 하드웨어 가속과 소프트웨어 가속을 실행중에 전환할 수 있다.

	if FAILED(hr)
		return false;

	D3DXCreateSprite(m_pDevice, &m_pSprite);

	D3DXFONT_DESC fontInfo;

	ZeroMemory(&fontInfo, sizeof(D3DXFONT_DESC));
	fontInfo.Width = 50.f;
	fontInfo.Height = 100.f;
	fontInfo.Weight = FW_NORMAL;
	fontInfo.CharSet = HANGUL_CHARSET;
	lstrcpy(fontInfo.FaceName, L"맑은 고딕");
	D3DXCreateFontIndirect(m_pDevice, &fontInfo, &m_pFont);

	ZeroMemory(&fontInfo, sizeof(D3DXFONT_DESC));
	fontInfo.Width = 20.f;
	fontInfo.Height = 40.f;
	fontInfo.Weight = FW_NORMAL;
	fontInfo.CharSet = HANGUL_CHARSET;
	lstrcpy(fontInfo.FaceName, L"맑은 고딕");
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
	//D3DCLEAR_TARGET 뷰포트 또는 뷰포트내의 직사각형 세트를 지정한 RGBA 색에 클리어 해, 깊이 버퍼를 클리어 해, 스텐실 버퍼를 삭제한다.(?)
	//D3DCOLOR_XRGB 일반적으로 색상의 알파, 빨강, 녹색 및 파랑 구성 요소를 나타내는 4 바이트 값입니다. 휘도 및 밝기를 나타낼 수도 있습니다.
}

void Renderer::End()
{
	m_pDevice->EndScene();
	m_pDevice->Present(0, 0, 0, 0);
}
