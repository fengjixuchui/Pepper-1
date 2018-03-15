#pragma once

class CPepperDoc : public CDocument
{
public:
	virtual ~CPepperDoc() {};
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual void OnCloseDocument();
	Ilibpe* m_pLibpe { };
protected: // create from serialization only
	CPepperDoc() {};
	DECLARE_DYNCREATE(CPepperDoc)
	DECLARE_MESSAGE_MAP()
};
