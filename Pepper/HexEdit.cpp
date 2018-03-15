#include "stdafx.h"
#include "HexEditView.h"
#include "HexEdit.h"

#define ID_HEX_VIEW 0x01

IMPLEMENT_DYNAMIC(CHexEdit, CWnd)

BEGIN_MESSAGE_MAP(CHexEdit, CWnd)
	ON_WM_CREATE()
	ON_WM_ERASEBKGND()
	ON_WM_SIZE()
END_MESSAGE_MAP()

BOOL CHexEdit::OnEraseBkgnd(CDC* pDC)
{
	return CWnd::OnEraseBkgnd(pDC);
}

void CHexEdit::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);

	if (m_pHexEditView)
		m_pHexEditView->SetWindowPos(this, 0, 0, cx, cy, SWP_NOACTIVATE | SWP_NOZORDER);
}

int CHexEdit::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	CRuntimeClass* pNewViewClass = RUNTIME_CLASS(CHexEditView);
	CCreateContext context;
	context.m_pNewViewClass = pNewViewClass;

	m_pHexEditView = (CHexEditView*)pNewViewClass->CreateObject();
	m_pHexEditView->CreateView(this, CRect(0, 0, 0, 0), ID_HEX_VIEW, &context, m_pFontHexEditView);
	m_pHexEditView->ShowWindow(SW_SHOW);

	return 0;
}

BOOL CHexEdit::CreateCtrl(CWnd * pParent, const RECT & rect, UINT nID, CFont* pFont)
{
	m_pFontHexEditView = pFont;

	return Create(0, 0, WS_VISIBLE | WS_CHILD, rect, pParent, nID);
}

BOOL CHexEdit::SetData(const std::vector<std::byte>* vecData)
{
	return m_pHexEditView->SetData(vecData);
}

BOOL CHexEdit::SetData(const std::string_view strData)
{
	return m_pHexEditView->SetData(strData);
}
