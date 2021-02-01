#pragma once

class User
{
public:
	TCHAR m_Name[16];
	int m_Score;
};

class RankMgr : public Singleton<RankMgr>
{
public:
	std::list<User*> m_Users;

	struct stLISTsort
	{
		bool operator() (const User* pObject1, const User* pObject2) const
		{
			if (pObject1->m_Score > pObject2->m_Score)
			{
				return TRUE;
			}
			return FALSE;
		}
	};
private:
	int m_Score;

public:
	RankMgr();
	~RankMgr();

	void AddScore(int score) { m_Score += score; }
	void ReserScore();
	void KeepUse(User* user);
	void SetRank();
	int GetScore() { return m_Score; }
};

