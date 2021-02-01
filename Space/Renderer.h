#pragma once //컴파일러에게 해당 헤더 파일이 한번만 빌드되도록 한다. 해당 헤더파일이 여러번 include 되는 것을 막아준다. 여러곳에서 include 되면 그때마가 각각 정의가 추가되어 중첩되는 경우가 생기기 때문이다. 즉 중복된 내용이 여러번 빌드되는 것을 막기 위해 #pragma once를 사용한다

class Renderer : public Singleton<Renderer>
{
private:
	LPDIRECT3D9 m_pD3D; //Direct3D를 초기화 하기 위해선 그래픽카드 정보와 디스플레이 정보를 읽어오는 개체가 사용된다.(이 자료형으로 LPDIRECT3D9이 사용된다.)
	LPDIRECT3DDEVICE9 m_pDevice;
	LPD3DXSPRITE m_pSprite;
	LPD3DXFONT m_pFont;
	LPD3DXFONT m_bFont;

public:
	Renderer();
	~Renderer();

	void Release();
	bool Init(int width, int height, bool windowMode);

	LPDIRECT3DDEVICE9 GetDevice() {
		return m_pDevice;
	}
	LPD3DXSPRITE GetSprite() {
		return m_pSprite;
	}

	LPD3DXFONT GetFont();

	LPD3DXFONT GetBulletFont();
public:
	void Begin();
	void End();
};
