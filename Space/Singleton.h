#pragma once

template<class T>

//c ++에서 클래스 T를 사용하는 장점 중 하나는 데이터 형식이 다른 함수(예 : int main)에 
//정의되어있는 경우 함수에서 데이터 형식을 재정의하는 시간을 줄이는 것입니다.

class Singleton  //싱글톤 패턴은 단 하나의 인스턴스를 생성해 사용하는 디자인 패턴이다.                                     
{
private:
	static T* m_Instance;

public:
	Singleton() {}
	~Singleton() {}

	static T* GetInst()
	{
		if (m_Instance == NULL)
			m_Instance = new T();

		return m_Instance;
	}

};

template<class T>
T* Singleton<T>::m_Instance = 0;