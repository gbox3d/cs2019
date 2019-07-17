#pragma once

namespace BulletObject {
	struct S_OBJ {
		irr::core::vector2df m_pos;
		irr::f32 m_fAngle;
		irr::f32 m_fSpeed;
		int m_nFsm;
	};

	inline void init(void *pThis)
	{
		BulletObject::S_OBJ* pthis = (BulletObject::S_OBJ*)pThis;
		pthis->m_nFsm = 0;
		pthis->m_fAngle = 0;
		pthis->m_fSpeed = 0;
	}
	inline void apply(void* pThis, double fDelta)
	{
		BulletObject::S_OBJ* pthis = (BulletObject::S_OBJ*)pThis;

		switch (pthis->m_nFsm)
		{
		case 0:	//sleep		
			break;
		case 10:
		{
			irr::core::vector2df _vDir(1, 0); //���� ���� 

			_vDir.rotateBy(pthis->m_fAngle);

			pthis->m_pos += _vDir * (fDelta * pthis->m_fSpeed);

			if (pthis->m_pos.getLength() > 256)
			{
				pthis->m_nFsm = 0;
			}
		}	
			break;
		default:
			break;
		}


	}
	inline void render(void* pThis,Gdiplus::Graphics *pGrp)
	{
		BulletObject::S_OBJ* pthis = (BulletObject::S_OBJ*)pThis;
		SolidBrush _brush(Color(255, 0, 0));
		GraphicsState _gs = pGrp->Save();
		
		pGrp->TranslateTransform(pthis->m_pos.X, pthis->m_pos.Y);
		pGrp->FillEllipse(&_brush, -8, -8, 16, 16);

		pGrp->Restore(_gs);
	}


}