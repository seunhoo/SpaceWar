#pragma once
class ClearScene : public Object
{
private:

	Sprite* m_ClearScene;
	Sprite* m_SelectScene;

	bool Clear;

public:
	ClearScene();
	~ClearScene();

	void Update(float time);
	void Render();
	void OnCollision(Object* other);
};

