#include "stdafx.h" //자주 변경되지 않는 긴 소스를 stdafx에 넣고 미리 컴파일을 해둔다.본문에 stdafx.h를 사용하여 전체 컴파일 속도를 상승시킨다.
#include "SceneDirector.h"    //SceneDirector 포기!


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
	Input::GetInst()->Update(); //deltaTime 전 프레임이 완료되기까지 걸린 시간을 말합니다. 컴퓨터의 성능이 느릴수록 값이 커진다.

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
