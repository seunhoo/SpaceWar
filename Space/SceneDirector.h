#pragma once

enum class MoveState
{
	RIGHT,
	LEFT,
	UP,
	DOWN,
	NONE
};

enum class Stage
{
	STAGEONE,
	STAGETWO,
	STAGETHREE
};

#define MOVESCENE SceneDirector::GetInst()->MoveScene
#define SCENE SceneDirector::GetInst()
#define GETPOS SceneDirector::GetInst()->GetPos
#define GETSIZE SceneDirector::GetInst()->GetSize
#define SCENE SceneDirector::GetInst()
class SceneDirector : public Singleton<SceneDirector>
{

	Object* m_CurrentScene;

public:
	Stage m_Stage;

public:
	SceneDirector();
	~SceneDirector();

	void ChangeScene(Object* newScene);

	void Update(float time);
	void Render();

	void MoveScene(float speed, MoveState state);
	Vec2 GetPos() { return m_CurrentScene->m_Position; }
	Vec2 GetSize() { return m_CurrentScene->m_Size; }

};

