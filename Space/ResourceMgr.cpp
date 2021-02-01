#include "stdafx.h" //자주 변경되지 않는 긴 소스를 stdafx에 넣고 미리 컴파일을 해둔다.본문에 stdafx.h를 사용하여 전체 컴파일 속도를 상승시킨다.
#include "ResourceMgr.h" // ?? ?? ?? ?? ? ?? ?? ?? ?? ?? ? ? ?
#include"Texture.h" //텍스쳐헤더 파일?

ResourceMgr::ResourceMgr() // ☆☆☆   MGR은 매니저?
{
}


ResourceMgr::~ResourceMgr()
{
}

Texture* ResourceMgr::CreateTextureFromFile(std::wstring fileName)
{
	if (!(m_TextureMap.count(fileName)))
	{
		auto texture = new (std::nothrow) Texture(); //new 는 '주소를 저장할 포인터' = '할당하고 싶은 크기그이 자료형'; 이렇게 사용한다.  new를 사용하면 delete 도 사용해야한다.
		if (texture && texture->Init(fileName))
		{
			m_TextureMap[fileName] = texture; //텍스쳐 집어넣기?
		}
		else
		{
			SafeDelete(texture); //new 를 사용해서 delete를 사용한거 같다 안전하게 삭제??
			return 0;
		}
	}

	return m_TextureMap[fileName];
}
