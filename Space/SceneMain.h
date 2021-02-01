#pragma once
class SceneMain : public Object
{
private:
	std::list<Object*> m_Buttons;

	Sprite* m_MainMenu;
	Sprite* m_StartButton;
	Sprite* m_ExplainButton;

public:
	SceneMain();
	~SceneMain();

	TextFont* m_Font1;
	void Update(float time);
	void Render();

};

