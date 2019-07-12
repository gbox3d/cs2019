
#include "..\..\..\cstudy\engine\tge.h"
#include "playerObject.h"

namespace PlayerObject {
	void init(void* pObj, void* pMap)
	{
		PlayerObject::S_OBJ* ptrThis = (PlayerObject::S_OBJ*)pObj;
		ptrThis->m_nFSM = 0; //대기상태 
	}

	void release(void* pObj)
	{
		PlayerObject::S_OBJ* ptrThis = (PlayerObject::S_OBJ*)pObj;

	}

	void apply(void* pObj, double _fDelta)
	{
		PlayerObject::S_OBJ* ptrThis = (PlayerObject::S_OBJ*)pObj;
		switch (ptrThis->m_nFSM)
		{
		case 0: //대기상태 , stand
		{
			if (TGE::input::g_dwButtonState == 1) {
				ptrThis->m_vDestPoint = irr::core::vector2df(
					TGE::input::g_cdMousePos.X,
					TGE::input::g_cdMousePos.Y
				);
				ptrThis->m_nFSM = 10;
			}
		}
			break;
		case 10: //걷기 ,walk
		{
			irr::core::vector2df vDir =  ptrThis->m_vDestPoint - ptrThis->m_vPos;
			vDir.normalize(); //방향벡터(단위 벡터)
			
			ptrThis->m_vPos += vDir* (_fDelta * ptrThis->m_fSpeed); //1초 에 m_fSpeed 만큼 이동 

			irr::f32 fDist = (ptrThis->m_vDestPoint - ptrThis->m_vPos).getLength();
			if (fDist < 0.3 ) { //두점의 거리를 구하기
				ptrThis->m_nFSM = 0;
			}
		}
			break;
		default:
			break;
		}




	}

	void draw(void* pObj)
	{
		PlayerObject::S_OBJ* ptrThis = (PlayerObject::S_OBJ*)pObj;

		TGE::setCharacter(TGE::g_chiBuffer, (int)ptrThis->m_vPos.X,(int) ptrThis->m_vPos.Y,0x0020,0x00f0 );
		
	}
}

