#include "stdafx.h"  //자주 변경되지 않는 긴 소스를 stdafx에 넣고 미리 컴파일을 해둔다.본문에 stdafx.h를 사용하여 전체 컴파일 속도를 상승시킨다.
#include "CollisionMgr.h"

bool CollisionMgr::MouseWithBoxCollide(RECT rect)
{
	Vec2 Mouse = INPUT->GetMousePos();

	if (rect.left <= Mouse.x && Mouse.x <= rect.right)
	{
		if (rect.top <= Mouse.y && Mouse.y <= rect.bottom)
			return true;
	}

	return false;
}
