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


	void init(void *pObj)
	{
		WorldMap::S_OBJ* ptrThis = (WorldMap::S_OBJ*)pObj;

		ptrThis->m_pBackBuf = TGE::CreateScreenBuffer();
		
		
	}

	int readWorldData(void* pObj,const char* szMapFile,int nLevel)
	{
		WorldMap::S_OBJ* ptrThis = (WorldMap::S_OBJ*)pObj;
		if (TGE::loadBufferBinary(ptrThis->m_pBackBuf, szMapFile) != 0)
		{
			return -1;
		}

		//멥데이터 분석 
		for (int i = 0; i < 2000; i++)
		{
			if (ptrThis->m_pBackBuf[i].Attributes == 64) { // 시작위치 

				ptrThis->m_posRegen[0] = i % 80;
				ptrThis->m_posRegen[1] = i / 80;
				ptrThis->m_pBackBuf[i].Attributes = 0x00;
			}
			else if (ptrThis->m_pBackBuf[i].Attributes == 160) { // 열쇠
				ptrThis->m_posKey[0] = i % 80;
				ptrThis->m_posKey[1] = i / 80;
				ptrThis->m_nstatusKey = 1;
				ptrThis->m_pBackBuf[i].Attributes = 0x00;
			}
			else if (ptrThis->m_pBackBuf[i].Attributes == 192) { //비상구
				ptrThis->m_posExit[0] = i % 80;
				ptrThis->m_posExit[1] = i / 80;
				ptrThis->m_nstatusExit = 1;
				ptrThis->m_pBackBuf[i].Attributes = 0x00;
			}
			else if (ptrThis->m_pBackBuf[i].Attributes == 128) { //포탈
				ptrThis->m_posPortal[0] = i % 80;
				ptrThis->m_posPortal[1] = i / 80;
				//ptrThis->m_pBackBuf[i].Attributes = 0x00;
			}
		}

		ptrThis->m_nLevel = nLevel;

		return 0;
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