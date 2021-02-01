#include "stdafx.h"  //���� ������� �ʴ� �� �ҽ��� stdafx�� �ְ� �̸� �������� �صд�.������ stdafx.h�� ����Ͽ� ��ü ������ �ӵ��� ��½�Ų��.
#include "Texture.h" //�ؽ��Ĵ� �Ϲ������� �̹����� 3D ���� ����ϴ� �� �������� �����δ� ���� ������ �����͸� �����ϴ� �� ��� �� �� �ִ�.
					 //GPU�� �뷮�� �����͸� �����ϴ� �� ����� �� �ִ� 1D,2D �� 3D �ؽ��ĸ� ���� �� �ֽ�����. 
					 //�ؽ����� �ٸ� �뵵�� ���� ���� ������ �����ϴ� ���Ԥ���. ��Ģ�� �Ϲ������� ��� ������ �ؽ��Ŀ� ������ �ȴ�.


Texture::Texture()
	: m_pDev(Renderer::GetInst()->GetDevice())
	, m_pTexture(0)
{
	m_pDev->AddRef();
}


Texture::~Texture()
{
}

bool Texture::Init(std::wstring fileName)
{
	HRESULT hr; //HRESULT�� �Լ��� ȣ�� ����� ��Ÿ���� 32��Ʈ�� ���� ǥ���ϸ� �Լ��� ���������� ȣ��� ��� S_OK�� �����ϴ� ���� ������ �������ش�.
	hr = D3DXCreateTextureFromFileEx(m_pDev, fileName.c_str(), D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2, 1, 0,
		//D3DXCreateTextureFromFileEx ������ �⺻���� �� �ؽ�ó�� ���� �Ѵ�. �̰���,D3DXCreateTextureFromFile �� ������ �Լ��̴�.
		//
		D3DFMT_A8R8G8B8, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT, 0, 0, 0, &m_pTexture);

	if FAILED(hr)
	{
		MessageBox(0, L"�ؽ��� ���� ����", 0, MB_OK);
		return false;
	}

	D3DSURFACE_DESC desc;
	m_pTexture->GetLevelDesc(0, &desc);

	m_Size.x = static_cast<float>(desc.Width);
	m_Size.y = static_cast<float>(desc.Height);

	return true;
}
