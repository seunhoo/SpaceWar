#pragma once

enum class ENEMYTYPE
{
	WARRIOR,
	WARRIOR2,
	RANGER,
	RANGER2,
};
class Monster : public Object
{
public:

	Vec2 m_Dir;
	

	Animation* m_State;
	Animation* m_Warrior;
	Animation* m_Warrior2;
	Animation* m_Ranger;
	Animation* m_Ranger2;

	Sprite* m_MiniMapMonster;


	ENEMYTYPE m_Etype;
	
	int MonsterHp;

	float AttackDelay;
	float cX, cY;
	float StartTime;
	bool closePlayer;
	bool timeCheck;
	bool shot;
	bool BossPassItem;

    /*Animation* m_MonsterAni;*/
public:
	Monster(Vec2 Pos, ENEMYTYPE Etype);
	~Monster();
	
	void Update(float time);
	void Render();
	void Move(float time);
	void OnCollision(Object* other);
	void OnCollision(Object* obj, std::string tag);
	void Attack(float time);
};

