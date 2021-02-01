#include "stdafx.h" //���� ������� �ʴ� �� �ҽ��� stdafx�� �ְ� �̸� �������� �صд�.������ stdafx.h�� ����Ͽ� ��ü ������ �ӵ��� ��½�Ų��.
#include "SceneDirector.h"    //SceneDirector ����!


SceneDirector::SceneDirector() 
{
}


SceneDirector::~SceneDirector()
{
}

void SceneDirector::ChangeScene(Object* newScene)
{
	if (m_CurrentScene)
	{
		SafeDelete(m_CurrentScene);
	}

	m_CurrentScene = newScene;
}

void SceneDirector::Update(float time)
{
	Input::GetInst()->Update(); //deltaTime �� �������� �Ϸ�Ǳ���� �ɸ� �ð��� ���մϴ�. ��ǻ���� ������ �������� ���� Ŀ����.

	if (m_CurrentScene)
	{
		m_CurrentScene->Update(time);
	}
	
	ObjMgr->Update(time);

}

void SceneDirector::Render()
{
	if (m_CurrentScene)
		m_CurrentScene->Render();

	ObjMgr->Render();
}
