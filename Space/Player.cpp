#include "stdafx.h"  //자주 변경되지 않는 긴 소스를 stdafx에 넣고 미리 컴파일을 해둔다.본문에 stdafx.h를 사용하여 전체 컴파일 속도를 상승시킨다.
#include "Bullet.h"
#include "RipleBullet.h"
#include "Player.h"
#include "DeathScene.h"
#include "SniperBullet.h"
#include "JunkRatBullet.h"
#include "StageTwo.h"
#include "NextStage.h"
#include "BossStage.h"
#include "NewStage.h"
#include "GameMgr.h"
#include "NextStageTwo.h"
#include "InvisibleEnemy.h"

Player::Player()
	: m_Gun(Gun::RIPLE)
	, m_MaxRipleBullet(40)
	, m_MaxSniperBullet(5)
	, m_MaxJunkRatBullet(3)
	, m_RipleBullet(40)
	, m_SniperBullet(5)
	, m_JunkRatBullet(5)
	, m_NoneBullet(999)
	, m_MaxNoneBullet(999)
	, RipleDelay(0.07f)
	, SniperDelay(1.f)
	, JunkRatDelay(1.f)
	, NoneDelay(0.5f)
	, MiniMapPlayerSpeed(3.f)
	, m_ifShot(false)
	, m_Attacked(false)
	, HavePass(true)
	, HaveBossPass(true)
	, ItemRiple(false)
	, ItemJunkRat(false)
	, ItemSniper(false)	
	, ItemHeal(false)
	, ItemGOD(false)
	, m_Atk(false)
	, AtkCheck(false)
	, AlphaCheck(false)
	, StageOneCheck(false)
	
	, AtkTime(0.f)
	
	, Speed(7.f)
	, PlayerHp(5)
{ 
	

	m_State = new Animation();
	m_State->SetParent(this);

	m_MoveState = new Animation();
	m_MoveState->Init(2, true);
	m_MoveState->AddContinueFrame(L"Painting/Player", 1, 5);
	m_MoveState->SetParent(this);

	

	
	m_Riple = new Animation();
	m_Riple->Init(4, true);
	m_Riple->AddContinueFrame(L"Painting/Animation/MonsterDie", 0, 5);
	m_Riple->SetParent(this);

	m_Sniper = new Animation();
	m_Sniper->Init(4, true);
	m_Sniper->AddContinueFrame(L"Painting/Animation/MonsterDie", 0, 5);
	m_Sniper->SetParent(this);

	m_JunkRat = new Animation();
	m_JunkRat->Init(4, true);
	m_JunkRat->AddContinueFrame(L"Painting/Animation/MonsterDie", 0, 5);
	m_JunkRat->SetParent(this);

	m_Warning = new Animation();
	m_Warning->Init(1, true);
	m_Warning->AddContinueFrame(L"Painting/Attack/Attack", 0, 5);
	m_Warning->SetPosition(m_Position.x, m_Position.y);

	
	m_MiniMapPlayer = Sprite::Create(L"Painting/MiniMapPlayer.png");
	m_MiniMapPlayer->SetParent(this);
	m_MiniMapPlayer->SetPosition(1700, 920);


	m_GunState = Sprite::Create(L"Painting/Attack/Gun.png");
	m_GunState->SetPosition(200, 100);


	m_RipleState = Sprite::Create(L"Painting/Attack/Riple.png");
	m_RipleState->SetPosition(200, 100);

	m_SniperState = Sprite::Create(L"Painting/Attack/Sniper.png");
	m_SniperState->SetPosition(200, 100);

	
	m_JunkRatState = Sprite::Create(L"Painting/Attack/JunkRat.png");
	m_JunkRatState->SetPosition(200, 100);

	m_NoneState = Sprite::Create(L"Painting/Attack/Gun.png");
	m_NoneState->SetPosition(200, 100);

	m_PassBlock = Sprite::Create(L"Painting/PassBlock2.png");
	m_PassBlock->SetPosition(550, 100);

	m_Pass = Sprite::Create(L"Painting/Pass2.png");


	m_MiniMap = Sprite::Create(L"Painting/MiniMap2.png");
	m_MiniMap->SetPosition(1695, 900);

	m_HealBlock = Sprite::Create(L"Painting/HealBlock.png");
	m_HealBlock->SetPosition(100, 250);

	m_Heal = Sprite::Create(L"Painting/Attack/Heal.png");
	m_Heal->SetPosition(100, 250);


	m_Player = Sprite::Create(L"Painting/Attack/Attack0.png");
	m_Player->SetParent(this);


	m_Speed = 4.f;

	SetPosition(1920 / 2, 1080 / 2);
	m_State = m_MoveState;

	if (SceneDirector::GetInst()->m_Stage == Stage::STAGEONE)
	{
		PointPos.x = 1920 / 2;
		PointPos.y = 1080 / 2;
	}
	

	
}

Player::~Player()
{
}

void Player::Update(float time)
{


	if (PlayerHp <= 0)	
	{
		SCENE->ChangeScene(new DeathScene);
	}



	if (m_Atk == true)
	{
		if (AtkCheck == false)
		{
			AtkTime = time;
			AtkCheck = true;
			m_Speed *= 3;
		}

		if (time - AtkTime >= 1)
		{
			m_Atk = false;
			AtkCheck = false;
			m_Speed /= 3;
			m_State->A = 255;
		}

		if (A >= 255)
		{
			AlphaCheck = false;
		}
		if (A <= 0)
		{
			AlphaCheck = true;
		}
		if (AlphaCheck == true)
		{
			m_State->A++;
		}
		else if (AlphaCheck == false)
		{
			m_State->A--;
		}
	}

	m_Move = false;
	m_mMove = false;

	Vec2 A = GETPOS();
	Vec2 A1 = m_Position;

	if (m_ifShot == false)
	{
		Move(time);
	}

	Vec2 B = GETPOS();
	Vec2 B1 = m_Position;
	A -= B;
	A1 -= B1;

	if ((m_mMove == true || m_Move == true) && m_ifShot == false)
	{
		m_State->Update(time);
		m_State = m_MoveState;

		if (m_Move == true && m_mMove == true)
		{
			if (m_xMove == true)
			{
				m_Rotation = atan2(-A1.x, -A.y);
			}
			else
			{
				m_Rotation = atan2(A.x, A1.y);
			}
		}
		else if (m_Move == true && m_mMove == false)
		{
			m_Rotation = atan2(-A1.x, A1.y);
		}
		else
		{
			m_Rotation = atan2(A.x,- A.y);
		}
	}
	else if (m_ifShot == false)
	{
		m_State->SetFrame(0);
	}
	else
	{
		m_State->Update(time);
	}
	if (m_Attacked == true)
	{
		m_Warning->Update(time);
	}
	
	Shot(time);
	UseItem(time);
	
	ObjMgr->CollideCheak(this, "MonsterBullet");
	ObjMgr->CollideCheak(this, "HealItem");
	ObjMgr->CollideCheak(this, "SniperItem");
	ObjMgr->CollideCheak(this, "JunkRatItem");
	ObjMgr->CollideCheak(this, "RipleItem");
	ObjMgr->CollideCheak(this, "PassItem");
	ObjMgr->CollideCheak(this, "BossPass");
	ObjMgr->CollideCheak(this, "Monster");
	ObjMgr->CollideCheak(this, "Boss");
	ObjMgr->CollideCheak(this, "BossBullet");

}

void Player::Render()
{
	
	m_MoveState->Render();

	m_HealBlock->Render();
	m_MiniMap->Render();
	m_State->Render();
	m_MiniMapPlayer->Render();
	/*m_Player->Render();*/


	if (m_Gun == Gun::RIPLE)
	{
		m_GunState = m_RipleState;
	}
	if (m_Gun == Gun::SNIPER)
	{
		m_GunState = m_SniperState;
	}
	if (m_Gun == Gun::JUNKRAT)
	{
		m_GunState = m_JunkRatState;
	}
	if (m_Gun == Gun::NONE)
	{
		m_GunState = m_NoneState;
	}

	if (PlayerHp >= 5)
		m_HPbar = Sprite::Create(L"Painting/Font/5.png");
	else if (PlayerHp == 4)
		m_HPbar = Sprite::Create(L"Painting/Font/4.png");
	else if (PlayerHp == 3)
		m_HPbar = Sprite::Create(L"Painting/Font/3.png");
	else if (PlayerHp == 2)
		m_HPbar = Sprite::Create(L"Painting/Font/2.png");
	else if (PlayerHp == 1)
		m_HPbar = Sprite::Create(L"Painting/Font/1.png");

	m_HPbar->SetPosition(110, 100);
	m_HPbar->Render();

	m_GunState->SetPosition(200, 100);
	m_GunState->Render();

	if (m_Attacked == true)
	{
		m_Warning->Render();
	}
	if (m_Warning->m_CurrentFrame == 4)
	{
		m_Attacked = false;
		m_Warning->SetFrame(0);
	}



	m_PassBlock->Render();

	if (HavePass == true)
	{
		m_Pass->SetPosition(550, 100);
		m_Pass->Render();
	}

	if (ItemHeal == true)
	{
		m_Heal->Render();
	}
	


	

	

	TCHAR szMaxBullet[32] = L"";
	TCHAR szBullet[32] = L"";
	TCHAR szHP[32] = L"";

	int m_Bullet = 0;
	int m_MaxBullet = 0;

	if (m_Gun == Gun::RIPLE)
	{
		m_Bullet = m_RipleBullet;
		m_MaxBullet = m_MaxRipleBullet;

	}
	if (m_Gun == Gun::SNIPER)
	{
		m_Bullet = m_SniperBullet;
		m_MaxBullet = m_MaxSniperBullet;
	}
	if (m_Gun == Gun::JUNKRAT)
	{
		m_Bullet = m_JunkRatBullet;
		m_MaxBullet = m_MaxJunkRatBullet;
	}
	if (m_Gun == Gun::NONE)
	{
		m_Bullet = m_NoneBullet;
		m_MaxBullet = m_MaxNoneBullet;
	}
	printf("%d \n", m_Bullet);

	wsprintf(szBullet, L" %d ", m_Bullet);
	wsprintf(szMaxBullet, L"/ %d ", m_MaxBullet);
	wsprintf(szHP, L"HP :");
	Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
	Matrix matFont;

	D3DXMatrixTranslation(&matFont, 0, 80, 0);
	Renderer::GetInst()->GetSprite()->SetTransform(&matFont);
	Renderer::GetInst()->GetBulletFont()->DrawTextW(Renderer::GetInst()->GetSprite(), szHP, 32, NULL, NULL, D3DCOLOR_ARGB(255, 255, 242, 6));

	D3DXMatrixTranslation(&matFont, 280, 80, 0);
	Renderer::GetInst()->GetSprite()->SetTransform(&matFont);
	Renderer::GetInst()->GetBulletFont()->DrawTextW(Renderer::GetInst()->GetSprite(), szBullet, 32, NULL, NULL, D3DCOLOR_ARGB(255, 255, 242, 6));

	D3DXMatrixTranslation(&matFont, 360, 80, 0);
	Renderer::GetInst()->GetSprite()->SetTransform(&matFont);
	Renderer::GetInst()->GetBulletFont()->DrawTextW(Renderer::GetInst()->GetSprite(), szMaxBullet, 32, NULL, NULL, D3DCOLOR_ARGB(255, 255, 242, 6));
	Renderer::GetInst()->GetSprite()->End();

	SetRect(&m_Collision, m_Position.x - m_Size.x / 2, m_Position.y - m_Size.x / 2, m_Position.x + m_Size.x / 2, m_Position.y + m_Size.x / 2);


}

void Player::Shot(float time)
{
	static float StartTime = time;

	if (m_RipleBullet <= 0 || m_SniperBullet <= 0 || m_JunkRatBullet <= 0)
	{
		m_Gun = Gun::NONE;
		
	}

	if (INPUT->GetButtonDown() && time - StartTime >= NoneDelay && m_Gun == Gun::NONE)
	{
		m_State = m_Riple;
		m_State->SetFrame(0);
		m_ifShot = true;

		Vec2 A;
		A = m_Position;
		A -= INPUT->GetMousePos();
		m_Rotation = atan2(-A.x, A.y);
		
		
		ObjMgr->KeepObject(new Bullet(m_Position, m_Rotation), "NoneBullet");

		A -= INPUT->GetMousePos();

		m_NoneBullet--;

		StartTime = time;
	}

	if (INPUT->GetButtonDown() && time - StartTime >= RipleDelay && m_Gun == Gun::RIPLE)
	{
		m_State = m_Riple;
		m_State->SetFrame(0);
		m_ifShot = true;

		Vec2 A;
		A = m_Position;
		A -= INPUT->GetMousePos();
		m_Rotation = atan2(-A.x, A.y);

		ObjMgr->KeepObject(new RipleBullet(m_Position, m_Rotation), "RipleBullet");

		A -= INPUT->GetMousePos();

		m_RipleBullet--;

		StartTime = time;

	}
	if (INPUT->GetButtonDown() && time - StartTime >= SniperDelay&& m_Gun == Gun::SNIPER)
	{
		m_State = m_Sniper;
		m_State->SetFrame(0);
		m_ifShot = true;

		Vec2 A;
		A = m_Position;
		A -= INPUT->GetMousePos();
		m_Rotation = atan2(-A.x, A.y);

		ObjMgr->KeepObject(new SniperBullet(m_Position, m_Rotation), "SniperBullet");

		A -= INPUT->GetMousePos();


		m_SniperBullet--;

		StartTime = time;
	}

	if (INPUT->GetButtonDown()&& time - StartTime >= JunkRatDelay && m_Gun == Gun::JUNKRAT)
	{
		m_State = m_JunkRat;
		m_State->SetFrame(0);
		m_ifShot = true;



		ObjMgr->KeepObject(new JunkRatBullet(m_Position), "JunkRatBullet");
		m_JunkRatBullet--;

		StartTime = time;
	}

	if ((m_State == m_Riple && m_State->m_CurrentFrame == 3) ||
		(m_State == m_Sniper && m_State->m_CurrentFrame == 1) ||
		(m_State == m_JunkRat && m_State->m_CurrentFrame == 1))
	{
		m_State = m_MoveState;
		m_ifShot = false;
	}
}

void Player::Move(float time)
{
		if (INPUT->GetKey('W') == KeyState::PRESS)
		{
			Vec2 A, B, C;
			A = m_Position;
			B.x = m_Position.x + cos(m_Rotation);
			B.y = m_Position.y + sin(m_Rotation);

			A -= B;
			D3DXVec2Normalize(&C, &A);

			Translate(Speed * -C.x, Speed * -C.y);

			

			Vec2 D, E, F;
			D = m_MiniMapPlayer->m_Position;
			E.x = m_MiniMapPlayer->m_Position.x + cos(m_Rotation);
			E.y = m_MiniMapPlayer->m_Position.y + sin(m_Rotation);

			D -= E;
			D3DXVec2Normalize(&F, &D);

			m_MiniMapPlayer->Translate(MiniMapPlayerSpeed * -F.x, MiniMapPlayerSpeed * -F.y);
		}
	
	if (INPUT->GetKey('D') == KeyState::PRESS)
	{
		m_Rotation += 0.08;
		m_MiniMapPlayer->m_Rotation += 0.08;
	}


		if (INPUT->GetKey('S') == KeyState::PRESS)
		{
			Vec2 A, B, C;
			A = m_Position;
			B.x = m_Position.x - cos(m_Rotation);
			B.y = m_Position.y - sin(m_Rotation);

			A -= B;
			D3DXVec2Normalize(&C, &A);

			Translate(Speed * -C.x, Speed * -C.y);
			

			Vec2 D, E, F;
			D = m_MiniMapPlayer->m_Position;
			E.x = m_MiniMapPlayer->m_Position.x - cos(m_Rotation);
			E.y = m_MiniMapPlayer->m_Position.y - sin(m_Rotation);

			D -= E;
			D3DXVec2Normalize(&F, &D);
			
			m_MiniMapPlayer->Translate(MiniMapPlayerSpeed * -F.x, MiniMapPlayerSpeed * -F.y);

		}

		if (INPUT->GetKey('A') == KeyState::PRESS)
		{
			m_Rotation -= 0.08;

			m_MiniMapPlayer->m_Rotation -= 0.08;
		}



}

void Player::UseItem(float time)
{

	if (INPUT->GetKey(VK_TAB) == KeyState::DOWN && HavePass == true && StageOneCheck == false)
	{
			SCENE->ChangeScene(new NextStage());
			HavePass = false;
			StageOneCheck = true;
	}
	if (INPUT->GetKey(VK_TAB) == KeyState::DOWN && HaveBossPass == true && StageOneCheck == true)
	{
			SCENE->ChangeScene(new NextStageTwo());
			HaveBossPass = false;
			
	}

	if (ItemHeal == true)
	{
		if (INPUT->GetKey('E') == KeyState::DOWN)
		{
			PlayerHp += 3;
			if (PlayerHp > 5)
			{
				PlayerHp = 5;
			}
			ItemHeal = false;
		}
	}
}

void Player::OnCollision(Object* obj, std::string tag)
{

	if (tag == "Boss")
	{
		printf("1123123232323 \n");
		PlayerHp--;
	}
	if (tag == "Monster")
	{
		PlayerHp--;
	}

	if (tag == "MonsterBullet")
	{
		printf("123123\n");
		PlayerHp--;
	}

	if (tag == "BossShot")
	{
		printf("12312232323 \n");
		PlayerHp--;
	}


	if (tag == "PassItem")
	{
		HavePass = true;
	}
	if (tag == "BossPass")
	{
		HaveBossPass = true;
	}
	if (tag == "HealItem")
	{
		ItemHeal = true;
	}

	if (tag == "RipleItem")
	{
		m_Gun = Gun::RIPLE;

		m_MaxRipleBullet = 40;
		m_RipleBullet = 40;


		m_MaxJunkRatBullet = 5;
		m_JunkRatBullet = 5;


		m_MaxSniperBullet = 5;
		m_SniperBullet = 5;

		
	}
	if (tag == "SniperItem")
	{
		m_Gun = Gun::SNIPER;

		m_MaxSniperBullet = 5;
		m_SniperBullet = 5;

		m_MaxRipleBullet = 40;
		m_RipleBullet = 40;


		m_MaxJunkRatBullet = 5;
		m_JunkRatBullet = 5;
		
	}
	if (tag == "JunkRatItem")
	{
		m_Gun = Gun::JUNKRAT;

		m_MaxJunkRatBullet = 5;
		m_JunkRatBullet = 5;

		m_MaxRipleBullet = 40;
		m_RipleBullet = 40;


		m_MaxSniperBullet = 5;
		m_SniperBullet = 5;
	
	}
	

	
	
}



