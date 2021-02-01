#include "stdafx.h"  //���� ������� �ʴ� �� �ҽ��� stdafx�� �ְ� �̸� �������� �صд�.������ stdafx.h�� ����Ͽ� ��ü ������ �ӵ��� ��½�Ų��.
#include "ObjectMgr.h"



ObjectMgr::ObjectMgr()
{
}

ObjectMgr::~ObjectMgr()
{
}

void ObjectMgr::Release()
{
	for (auto& iter : m_Objects)
	{
		SAFE_DELETE(iter);
	}
	m_Objects.clear();
	
}

void ObjectMgr::DeleteCheak()
{
	for (auto iter = m_Objects.begin(); iter != m_Objects.end();)
	{
		if ((*iter)->GetDestroy())
		{
			Object* temp = (*iter);
			iter = m_Objects.erase(iter);
			SafeDelete(temp);
		}
		else
		{
			++iter;
		}
	}

	
}

void ObjectMgr::Update(float time)
{
	DeleteCheak();
	for (const auto& iter : m_Objects)
	{
		(iter)->Update(time);
	}
	CollideCheak();
}

void ObjectMgr::CollideCheak()
{
	 
	
}

void ObjectMgr::CollideCheak(Object* obj, std::string tag)
{
	for (auto& iter : m_Objects)
	{
		if (iter->m_Tag == tag)
		{
			RECT rect;
			if (IntersectRect(&rect, &obj->m_Collision, &(iter)->m_Collision))
			{
				(iter)->OnCollision(obj,obj->m_Tag);
				obj->OnCollision(iter,iter->m_Tag);
			}
		}
	}


}


void ObjectMgr::Render()
{
	m_Objects.sort(stLISTsort());
	
	

	for (const auto& iter : m_Objects)
	{
		(iter)->Render();
	}
	
	
}

void ObjectMgr::KeepObject(Object* obj, OBJECTLIST list)
{
	//switch (list)
	//{
	//case OBJECTLIST::OBJECT:
	//	m_Objects.push_back(obj);
	//	break;
	//case OBJECTLIST::ENEMY:
	//	m_Enemys.push_back(obj);
	//	break;
	//case OBJECTLIST::ALLIES:
	//	m_Allies.push_back(obj);
	//	break;
	//case OBJECTLIST::BULLET_ENEMY:
	//	m_Bullets_Enemy.push_back(obj);
	//	break;
	//case OBJECTLIST::BULLET_ALLY:
	//	m_Bullets_Ally.push_back(obj);
	//	break;
	//case OBJECTLIST::ITEM:
	//	m_Item.push_back(obj);
	//	break;

	//default:
	//	MessageBox(0, L"������Ʈ �߰� ����", 0, MB_OK);
	//	break;
	//}
}

void ObjectMgr::KeepObject(Object* obj, std::string tag)
{
	if (obj)
	{
		m_Objects.push_back(obj);
		obj->m_Tag = tag;
	}


}


void ObjectMgr::RemoveObject(Object* obj)
{
	if (obj)
		obj->SetDestroy(true);
}
