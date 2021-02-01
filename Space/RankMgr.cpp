#include "stdafx.h"
#include "RankMgr.h"

RankMgr::RankMgr()
{
}

RankMgr::~RankMgr()
{
}

void RankMgr::ReserScore()
{
	m_Score = 0;
}

void RankMgr::KeepUse(User* user)
{
	m_Users.push_back(user);
}

void RankMgr::SetRank()
{
	m_Users.sort(stLISTsort());
}
