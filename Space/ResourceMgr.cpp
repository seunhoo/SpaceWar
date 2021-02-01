#include "stdafx.h" //���� ������� �ʴ� �� �ҽ��� stdafx�� �ְ� �̸� �������� �صд�.������ stdafx.h�� ����Ͽ� ��ü ������ �ӵ��� ��½�Ų��.
#include "ResourceMgr.h" // ?? ?? ?? ?? ? ?? ?? ?? ?? ?? ? ? ?
#include"Texture.h" //�ؽ������ ����?

ResourceMgr::ResourceMgr() // �١١�   MGR�� �Ŵ���?
{
}


ResourceMgr::~ResourceMgr()
{
}

Texture* ResourceMgr::CreateTextureFromFile(std::wstring fileName)
{
	if (!(m_TextureMap.count(fileName)))
	{
		auto texture = new (std::nothrow) Texture(); //new �� '�ּҸ� ������ ������' = '�Ҵ��ϰ� ���� ũ����� �ڷ���'; �̷��� ����Ѵ�.  new�� ����ϸ� delete �� ����ؾ��Ѵ�.
		if (texture && texture->Init(fileName))
		{
			m_TextureMap[fileName] = texture; //�ؽ��� ����ֱ�?
		}
		else
		{
			SafeDelete(texture); //new �� ����ؼ� delete�� ����Ѱ� ���� �����ϰ� ����??
			return 0;
		}
	}

	return m_TextureMap[fileName];
}
