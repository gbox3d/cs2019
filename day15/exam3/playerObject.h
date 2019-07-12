#pragma once
namespace PlayerObject {
	struct S_OBJ
	{
		char m_szName[64];
		irr::core::vector2df m_vPos;

		irr::core::vector2df m_vDestPoint; //이동 목표지점

		int m_nFSM;
		double m_fSpeed;
		void* m_pMap;
	};

	void init(void* pObj, void* pMap);
	void release(void* pObj);
	void apply(void* pObj, double fDelat);
	void draw(void* pObj);
}