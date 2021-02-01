#pragma once //�����Ϸ����� �ش� ��� ������ �ѹ��� ����ǵ��� �Ѵ�. �ش� ��������� ������ include �Ǵ� ���� �����ش�. ���������� include �Ǹ� �׶����� ���� ���ǰ� �߰��Ǿ� ��ø�Ǵ� ��찡 ����� �����̴�. �� �ߺ��� ������ ������ ����Ǵ� ���� ���� ���� #pragma once�� ����Ѵ�

class Renderer : public Singleton<Renderer>
{
private:
	LPDIRECT3D9 m_pD3D; //Direct3D�� �ʱ�ȭ �ϱ� ���ؼ� �׷���ī�� ������ ���÷��� ������ �о���� ��ü�� ���ȴ�.(�� �ڷ������� LPDIRECT3D9�� ���ȴ�.)
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
