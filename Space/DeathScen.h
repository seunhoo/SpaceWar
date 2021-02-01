#pragma once

class DeathScene : public Object
{
private:
	Sprite* m_DeathScene;


public:
	DeathScene();
	~DeathScene();

	void Update(float delatatime, float time);
	void Render();
	void OnCollision(Object* other);
};

