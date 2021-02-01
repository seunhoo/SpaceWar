#pragma once
class ItemMgr : public Singleton<ItemMgr>
{
private:
	std::list<Object*>m_Itemlist;

public:
	void CreateItem(ITEM itemtype, Vec2 Pos);
};

