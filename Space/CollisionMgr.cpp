#include "stdafx.h"  //���� ������� �ʴ� �� �ҽ��� stdafx�� �ְ� �̸� �������� �صд�.������ stdafx.h�� ����Ͽ� ��ü ������ �ӵ��� ��½�Ų��.
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
