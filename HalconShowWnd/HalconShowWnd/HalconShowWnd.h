// HalconShowWnd.h : HalconShowWnd DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CHalconShowWndApp
// �йش���ʵ�ֵ���Ϣ������� HalconShowWnd.cpp
//

class CHalconShowDlg : public CDialogEx
{
public:
    enum {IDD= IDD_DIALOG1};
    CHalconShowDlg(CWnd* pParent=NULL);

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
