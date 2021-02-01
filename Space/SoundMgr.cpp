#include "stdafx.h"  //자주 변경되지 않는 긴 소스를 stdafx에 넣고 미리 컴파일을 해둔다.본문에 stdafx.h를 사용하여 전체 컴파일 속도를 상승시킨다.
#include "SoundMgr.h"


SoundMgr::SoundMgr()
{
}


SoundMgr::~SoundMgr()
{
}

void SoundMgr::Play(const WCHAR* pFileName, bool loop)
{
	WCHAR szFullPath[256] = L"../Sound/";
	lstrcatW(szFullPath, pFileName);

	if (!loop)
	{
		sndPlaySoundW(szFullPath, SND_ASYNC | SND_NOSTOP);
	}
	else if (loop)
	{
		sndPlaySoundW(szFullPath, SND_ASYNC | SND_LOOP | SND_NOSTOP);
	}
}

void SoundMgr::Stop()
{
	sndPlaySoundW(nullptr, SND_ASYNC);
}