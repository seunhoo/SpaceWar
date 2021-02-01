#pragma once

enum class Gun
{
	RIPLE,
	SNIPER,
	JUNKRAT,
	NONE
};
class Player : public Object
{
private:
	Vec2 m_Dir;

	Animation* m_State;
	Animation* m_MoveState;
	Animation* m_Riple;
	Animation* m_Sniper;
	Animation* m_JunkRat;

	Animation* m_Warning;

	Sprite* m_Player;
	Sprite* m_MiniMapPlayer;
	Sprite* m_HPbar;
	Sprite* m_GunState;
	Sprite* m_RipleState;
	Sprite* m_SniperState;
	Sprite* m_JunkRatState;
	Sprite* m_NoneState;
	Sprite* m_PassBlock;
	Sprite* m_Pass;
	Sprite* m_HealBlock;
	Sprite* m_Heal;
	Sprite* m_MiniMap;

	Vec2 PointPos;

	

	

	float Speed;

	float RipleDelay;

	float SniperDelay;

	float JunkRatDelay;

	float NoneDelay;

	bool m_Attacked;
	/*Animation* m_PlayerAni;*/
public:
	
	Gun m_Gun;

	int m_RipleBullet;
	int m_MaxRipleBullet;
	int m_SniperBullet;
	int m_MaxSniperBullet;
	int m_JunkRatBullet;
	int m_MaxJunkRatBullet;
	int m_NoneBullet;
	int m_MaxNoneBullet;
	int m_InvisibleEnemySpawnTime;


	int PlayerHp;

	int PrevDistance;
	int MiniMapPlayerSpeed;

	bool HavePass;
	bool HaveBossPass;
	bool ItemRiple;
	bool ItemSniper;
	bool ItemJunkRat;
	bool ItemHeal;
	bool ItemGOD;
	bool m_Move;
	bool m_mMove;
	bool m_xMove;
	bool m_yMove;
	bool m_ifShot;
	bool StageOneCheck;
	bool StageTwoCheck;


	bool m_Atk;
	bool AtkCheck;
	bool AlphaCheck;

	bool m_DamagedCheck;
	int m_DamageTime;

	float AtkTime;


	

public:


	Player();
	~Player();

	void Update(float time);
	void Render();
	void Shot(float time);
	void Move(float time);
	void UseItem(float time);
	void OnCollision(Object* obj, std::string tag);

};


