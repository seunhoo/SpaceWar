#pragma once
class CollisionMgr : public Singleton<CollisionMgr>
{
public:

	bool MouseWithBoxCollide(RECT rect);

};

