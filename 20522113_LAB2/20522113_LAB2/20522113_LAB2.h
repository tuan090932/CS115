
// 20522113_LAB2.h : main header file for the 20522113_LAB2 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMy20522113LAB2App:
// See 20522113_LAB2.cpp for the implementation of this class
//

class CMy20522113LAB2App : public CWinAppEx
{
public:
	CMy20522113LAB2App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy20522113LAB2App theApp;
