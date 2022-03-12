
// 20522113_LAB2View.h : interface of the CMy20522113LAB2View class
//

#pragma once


class CMy20522113LAB2View : public CView
{
protected: // create from serialization only
	CMy20522113LAB2View() noexcept;
	DECLARE_DYNCREATE(CMy20522113LAB2View)

// Attributes
public:
	CMy20522113LAB2Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CMy20522113LAB2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in 20522113_LAB2View.cpp
inline CMy20522113LAB2Doc* CMy20522113LAB2View::GetDocument() const
   { return reinterpret_cast<CMy20522113LAB2Doc*>(m_pDocument); }
#endif

