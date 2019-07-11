#include "..\..\..\cstudy\engine\tge.h"
#include "worldmap.h"

namespace WorldMap {
	
	void init(void *pObj)
	{
		WorldMap::S_OBJ* ptrThis = (WorldMap::S_OBJ*)pObj;

		ptrThis->m_pBackBuf = TGE::CreateScreenBuffer();
		TGE::loadBufferBinary(ptrThis->m_pBackBuf, "../res/level1.map");
		
		ptrThis->m_nLevel = 0;
	}

	void release(void* pObj)
	{
		WorldMap::S_OBJ* ptrThis = (WorldMap::S_OBJ*)pObj;
		free(ptrThis->m_pBackBuf);
	}

	void apply(void* pObj,double fDelat)
	{

	}

	void draw(void* pObj)
	{
		WorldMap::S_OBJ* ptrThis = (WorldMap::S_OBJ*)pObj;

		TGE::copyScreenBuffer(TGE::g_chiBuffer, ptrThis->m_pBackBuf);

	}
}