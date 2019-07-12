#pragma once
namespace PlayerObject {
	struct S_OBJ
	{
		char m_szName[64];
		double m_fXpos, m_fYpos; //위치정보
		double m_fSpeed;
		void* m_pMap;
		int m_nStatus_HaveKey;
	};

	void init(void* pObj, void* pMap);
	void release(void* pObj);
	void apply(void* pObj, double fDelat);
	void draw(void* pObj);
}