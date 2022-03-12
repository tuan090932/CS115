
// 20522113_LAB2View.cpp : implementation of the CMy20522113LAB2View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "20522113_LAB2.h"
#endif

#include "20522113_LAB2Doc.h"
#include "20522113_LAB2View.h"
#include "shape.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "CFill.h"

// CMy20522113LAB2View

IMPLEMENT_DYNCREATE(CMy20522113LAB2View, CView)

BEGIN_MESSAGE_MAP(CMy20522113LAB2View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy20522113LAB2View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMy20522113LAB2View construction/destruction

CMy20522113LAB2View::CMy20522113LAB2View() noexcept
{
	// TODO: add construction code here

}

CMy20522113LAB2View::~CMy20522113LAB2View()
{
}

BOOL CMy20522113LAB2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMy20522113LAB2View drawing

void CMy20522113LAB2View::OnDraw(CDC* pDC)
{
	CMy20522113LAB2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	shape::midpoint(pDC, 100, 100, 100, RGB(0, 255, 0));
	CFill::BoundaryFillEnhanced(pDC, 100, 100, RGB(0, 255, 0));
	//CFill::BoundaryFill(pDC, 100, 100, RGB(0, 255, 0), RGB(0, 0, 255));
}


// CMy20522113LAB2View printing


void CMy20522113LAB2View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy20522113LAB2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy20522113LAB2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy20522113LAB2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMy20522113LAB2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy20522113LAB2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy20522113LAB2View diagnostics

#ifdef _DEBUG
void CMy20522113LAB2View::AssertValid() const
{
	CView::AssertValid();
}

void CMy20522113LAB2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy20522113LAB2Doc* CMy20522113LAB2View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy20522113LAB2Doc)));
	return (CMy20522113LAB2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy20522113LAB2View message handlers
