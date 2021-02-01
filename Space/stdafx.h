#pragma once

#define _USE_MATH_DEFINES
#define SAFE_DELETE(x) if(x) {delete x; x = NULL;}
#define Vec2 D3DXVECTOR2
#define Matrix D3DXMATRIX
#define Nor D3DXVec2Normalize

template<class T>
inline void SafeDelete(T*& x);

#include<Windows.h>
#include<stdio.h>
#include<iostream>
#include<d3d9.h>
#include<d3dx9.h>
//#include<dsound.h>
#include<map>
#include<list>
#include<ctime>
#include<vector>
#include<string>
#include<sstream>
#include<cmath>
#include<mmsystem.h>
#include<algorithm>
//
#include"Singleton.h"
#include"Input.h"
#include"Renderer.h"
#include"App.h"
#include"Object.h"
#include"ObjectMgr.h"
#include"CollisionMgr.h"
#include"SceneDirector.h"
#include"TextFont.h"
#include"SoundMgr.h"
#include"Sprite.h"
#include"Animation.h"
#include"Player.h"
#include"GameMgr.h"
#include"RankMgr.h"
//

template<class T>
inline void SafeDelete(T*& x)
{
	
	delete x;
	x = static_cast<T*>(0);
};