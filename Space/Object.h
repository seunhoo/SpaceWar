#pragma once //컴파일러에게 해당 헤더 파일이 한번만 빌드되도록 한다. 해당 헤더파일이 여러번 include 되는 것을 막아준다. 여러곳에서 include 되면 그때마가 각각 정의가 추가되어 중첩되는 경우가 생기기 때문이다. 즉 중복된 내용이 여러번 빌드되는 것을 막기 위해 #pragma once를 사용한다


enum class ITEM
{
	NONE,
	RIPLE,
	SNIPER,
	JUNKRAT,
	PASS,
	REGENERATION,
	SKILL,
	SPEED,
	BULLETRELOAD
};
class Object  //Object 객체는 객체의 가장 기본적인 형태를 가지고 있는 객체이다. 다시 말해서 아무것도 상속받지 않는 순수한 객체다. 자바스크립트에서는 값을 저장하는 기본적인 단위로 Object를 사용한다. 
{
public:
	LPDIRECT3DDEVICE9 m_pDev;  //LPDIRECT3D9는  Device를 생성할 객체 변수이고 LPDIRECT3DDEVICE9는 랜더링에 사용될 Device입니다.
	Object* m_Parent;
	RECT m_Collision;
	ITEM m_ItemType;

	Matrix m_wMat;   
	Vec2 m_Position;
	Vec2 m_Scale;
	Vec2 m_Size;
	float m_Rotation;

	bool m_Destroy;


	bool m_Visible;

	int m_Layer;


	float m_Speed;

	int m_Hp;
	int m_Atk;

	std::string m_Tag;

public:
	int A;
	int R;
	int G;
	int B;
	Object();
	~Object();

	Matrix GetMatrix();

public:
	virtual void Update(float time);
	virtual void Render();
	virtual void OnCollision(Object* other, std::string tag);
	virtual void Mode(float time);

public:
	void Translate(float x, float y);
	void SetScale(float x, float y);
	void SetPosition(float x, float y);
	void SetPosition2(Vec2 Pos);
	void Rotate(float r);
	void SetDestroy(bool destroy) { m_Destroy = destroy; }
	void SetParent(Object* parent);
public:
	bool GetDestroy() { return m_Destroy; }
};