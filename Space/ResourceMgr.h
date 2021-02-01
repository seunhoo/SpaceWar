#pragma once

class Texture;
class ResourceMgr : public Singleton<ResourceMgr>
{
private:
	std::map<std::wstring, Texture*> m_TextureMap; //STL �Լ� ���� �ݺ��� 

public:
	ResourceMgr();
	~ResourceMgr();

	Texture* CreateTextureFromFile(std::wstring fileName);

};

