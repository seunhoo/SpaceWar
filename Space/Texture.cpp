#include "stdafx.h"  //자주 변경되지 않는 긴 소스를 stdafx에 넣고 미리 컴파일을 해둔다.본문에 stdafx.h를 사용하여 전체 컴파일 속도를 상승시킨다.
#include "Texture.h" //텍스쳐는 일반적으로 이미지가 3D 모델을 장식하는 데 사용되지만 실제로는 여러 종류의 데이터를 저장하는 데 사용 될 수 있다.
					 //GPU에 대량의 데이터를 저장하는 데 사용할 수 있는 1D,2D 및 3D 텍스쳐를 가질 수 있습ㄴ디ㅏ. 
					 //텍스쳐의 다른 용도의 예는 지형 정보를 저장하는 것입ㄴ디ㅏ. 원칙은 일반적으로 모든 종류의 텍스쳐에 적용이 된다.


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
	HRESULT hr; //HRESULT는 함수의 호출 결과를 나타내는 32비트의 값을 표현하며 함수가 성공적으로 호출된 경우 S_OK를 리턴하는 등의 정보를 제공해준다.
	hr = D3DXCreateTextureFromFileEx(m_pDev, fileName.c_str(), D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2, 1, 0,
		//D3DXCreateTextureFromFileEx 파일을 기본으로 해 텍스처를 생성 한다. 이것은,D3DXCreateTextureFromFile 의 상위의 함수이다.
		//
		D3DFMT_A8R8G8B8, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT, 0, 0, 0, &m_pTexture);

	if FAILED(hr)
	{
		MessageBox(0, L"텍스쳐 생성 실패", 0, MB_OK);
		return false;
	}

	D3DSURFACE_DESC desc;
	m_pTexture->GetLevelDesc(0, &desc);

	m_Size.x = static_cast<float>(desc.Width);
	m_Size.y = static_cast<float>(desc.Height);

	return true;
}
