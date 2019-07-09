#pragma once

struct S_GameObject {

	char* m_szName;
	int m_nDamage;
	int m_nHitPoint;
	double m_fSpeed;
	double m_fXpos, m_fYpos;
};

void initGameObject(S_GameObject* _obj, const char* szName, int nNameSize);
void releseGameObject(S_GameObject* _obj);



