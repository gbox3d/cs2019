#include "..\..\..\cstudy\engine\tge.h"
#include "worldmap.h"

namespace WorldMap {

	namespace utils {
		void findRegenPoint(void* pObj, int* x, int* y)
		{
			WorldMap::S_OBJ* ptrThis = (WorldMap::S_OBJ*)pObj;

			for (int i = 0; i < 2000; i++)
			{
				if (ptrThis->m_pBackBuf[i].Attributes == 64) {

					*y = i / 80;
					*x = i % 80;

					break;
				}
			}
		}
	}


	void init(void *pObj,const char *szMapFile)
	{
		WorldMap::S_OBJ* ptrThis = (WorldMap::S_OBJ*)pObj;

		ptrThis->m_pBackBuf = TGE::CreateScreenBuffer();
		TGE::loadBufferBinary(ptrThis->m_pBackBuf, szMapFile);

		//멥데이터 분석 
		for (int i = 0; i < 2000; i++)
		{
			if (ptrThis->m_pBackBuf[i].Attributes == 64) {

				ptrThis->m_posRegen[0] = i % 80;
				ptrThis->m_posRegen[1] = i / 80;
				ptrThis->m_pBackBuf[i].Attributes = 0x00;				
			}
			else if (ptrThis->m_pBackBuf[i].Attributes == 160) {
				ptrThis->m_posKey[0] = i % 80;
				ptrThis->m_posKey[1] = i / 80;
				ptrThis->m_nstatusKey = 1;
				ptrThis->m_pBackBuf[i].Attributes = 0x00;
			}
			else if (ptrThis->m_pBackBuf[i].Attributes == 192) {
				ptrThis->m_posExit[0] = i % 80;
				ptrThis->m_posExit[1] = i / 80;
				ptrThis->m_nstatusExit = 1;
				ptrThis->m_pBackBuf[i].Attributes = 0x00;
			}
		}
		
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

		TGE::copyScreenBuffer(TGE::g_chiBuffer, ptrThis->m_pBackBuf); //배경..
		
		//열쇠
		if (ptrThis->m_nstatusKey == 1) {
			TGE::setCharacter(TGE::g_chiBuffer,
				ptrThis->m_posKey[0], ptrThis->m_posKey[1],
				0x0020,
				0x00a0
			);
		}
		//비상구 
		if (ptrThis->m_nstatusExit == 1) {
			TGE::setCharacter(TGE::g_chiBuffer,
				ptrThis->m_posExit[0], ptrThis->m_posExit[1],
				0x0020,
				192
			);
		}

	}
}