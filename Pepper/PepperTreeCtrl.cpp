#include "stdafx.h"
#include "PepperTreeCtrl.h"

IMPLEMENT_DYNAMIC(CPepperTreeCtrl, CTreeCtrl)

BEGIN_MESSAGE_MAP(CPepperTreeCtrl, CTreeCtrl)
	ON_WM_KILLFOCUS()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

void CPepperTreeCtrl::OnKillFocus(CWnd* pNewWnd)
{
	//	CTreeCtrl::OnKillFocus(pNewWnd);
}

void CPepperTreeCtrl::OnLButtonDown(UINT nFlags, CPoint point)
{
	SetFocus();

	CTreeCtrl::OnLButtonDown(nFlags, point);
}