
#pragma once

class DeathScene : public Object
{
private:
	Sprite* m_DeathScene;
	Sprite* m_SelectScene;
	bool Die;

public:
	DeathScene();
	~DeathScene();

	void Update( float time);
	void Render();
};

