#pragma once
class ExPlainScene : public Object
{
private:

	Sprite* m_Explain;
	Sprite* m_dlcksdn;

public:
	ExPlainScene();

	void Update(float time);
	void Move(float time);
	void Render();

};

