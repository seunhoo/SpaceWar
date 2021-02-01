#pragma once
#include <algorithm>

enum class OBJECTLIST
{
	OBJECT, // Player
	ENEMY, // Enemy
	ALLIES,
	BULLET_ENEMY,
	BULLET_ALLY,  // Player Bullet
	ITEM
};


#define ObjMgr ObjectMgr::GetInst()

class ObjectMgr : public Singleton<ObjectMgr>
{
public:

	std::list<Object*> m_Objects;
	
	//std::list<Object*> m_Enemys;
	//std::list<Object*> m_Allies; //Including Player
	//std::list<Object*> m_Bullets_Enemy;
	//std::list<Object*> m_Bullets_Ally;
	//std::list<Object*> m_Item;

	struct stLISTsort
	{
		bool operator() (const Object* pObject1, const Object* pObject2) const
		{
			if (pObject1->m_Layer < pObject2->m_Layer)
				return TRUE;

			return FALSE;
		}
	};

public:
	ObjectMgr();
	virtual ~ObjectMgr();

	
	void Release();
	void DeleteCheak();
	void Update(float time);
	void CollideCheak();
	void CollideCheak(Object * obj, std::string tag);
	void Render();




public:
	void KeepObject(Object* obj, OBJECTLIST list);
	void KeepObject(Object* obj, std::string tag);
	void RemoveObject(Object* obj);

};

