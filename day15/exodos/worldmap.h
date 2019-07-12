#pragma once
namespace WorldMap {
	struct S_OBJ
	{
		int m_nLevel;
		CHAR_INFO* m_pBackBuf;

		int m_posRegen[2]; //x,y

		int m_posKey[2];
		int m_nstatusKey;

		int m_posExit[2];
		int m_nstatusExit;

		int m_posPortal[2];

	};


	namespace utils {
		void findRegenPoint(void* pObj, int* x, int* y);
	}

	void init(void* pObj);
	int readWorldData(void* pObj, const char* szMapFile, int nLevel);
	void release(void* pObj);
	void apply(void* pObj, double fDelat);
	void draw(void* pObj);
}