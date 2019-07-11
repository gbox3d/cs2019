#pragma once
namespace WorldMap {
	struct S_OBJ
	{
		int m_nLevel;
		CHAR_INFO* m_pBackBuf;
	};

	void init(void* pObj);

	void release(void* pObj);

	void apply(void* pObj, double fDelat);

	void draw(void* pObj);
}