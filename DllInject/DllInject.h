// DllInject.h : PROJECT_NAME 应用程序的主头文件
#pragma once
#include "resource.h"		// 主符号
#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

// CDllInjectApp:
// 有关此类的实现，请参阅 DllInject.cpp
class CDllInjectApp : public CWinApp
{
public:
	CDllInjectApp();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern CDllInjectApp theApp;