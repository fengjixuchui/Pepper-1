#pragma once
#include "PepperListHeader.h"

class CPepperList : public CMFCListCtrl
{
public:
	DECLARE_DYNAMIC(CPepperList)
	CPepperList();
	virtual ~CPepperList() { m_fontList.DeleteObject(); m_vecToolTips.clear(); };
	virtual CMFCHeaderCtrl& GetHeaderCtrl() { return m_PepperListHeader; }
	virtual void InitHeader();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnHdnDividerdblclick(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	void SetItemToolTip(int nItem, int nSubitem, const std::wstring& TooltipText, const std::wstring& ToolTipCaption = TEXT(""));
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
protected:
	DECLARE_MESSAGE_MAP()
private:
	CPepperListHeader m_PepperListHeader;
	CFont m_fontList;
	std::vector<std::tuple<int/*Item*/, int/*subItem*/, std::wstring/*tip text*/, std::wstring/*caption text*/>> m_vecToolTips { };
	bool m_fToolTip = false;
	HWND m_hwndToolTip { };
	TOOLINFO m_ti { };
	bool m_fToolTipShow = false;
	LVHITTESTINFO m_curSubItem { };
	COLORREF m_colorListToolTipSubitem { }, m_colorListSelected { };
	bool HasToolTip(int iItem, int iSubItem, std::wstring& TipText, std::wstring& TipCaption);
	bool HasToolTip(int iItem, int iSubItem);
};