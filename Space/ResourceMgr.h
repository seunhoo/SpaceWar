#pragma once

class Texture;
class ResourceMgr : public Singleton<ResourceMgr>
{
private:
	std::map<std::wstring, Texture*> m_TextureMap; //STL 함수 종류 반복자 

public:
	ResourceMgr();
	~ResourceMgr();

	Texture* CreateTextureFromFile(std::wstring fileName);

};

