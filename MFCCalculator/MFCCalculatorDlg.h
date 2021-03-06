
// MFCCalculatorDlg.h : header file
//

#pragma once

#include "bit_function.h"
#include "QInt.h"
#include "base.h"

// CMFCCalculatorDlg dialog
class CMFCCalculatorDlg : public CDialogEx
{
// Construction
protected: 
	CString fst_num;
	CString snd_num;

	QInt qint1;
	QInt qint2;
	QInt qintResult;

	bool db = false;

	int heso = 10;
	int ope = 0;

	CFont m_Font;

public:
	CMFCCalculatorDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCCALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	void btnDisDEC();
	void getFromSHOWX(int heso, CString &cs);
	void CStringToQInt(CString cs, int heso, QInt &qint2);
	void emptyInputBoxes();
	void setInputBtn(int heso, char key);
	void process2operand(int ope);
	void btnDisBIN();
	void btnEnDEC();
	void btnEnHEX();
	BOOL PreTranslateMessage(MSG *pMsg);
	void OnOK(void);
	void OnPressESC();
	void OnPressBS();

public:
	afx_msg void OnBnClickedRst();
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedSub();
	afx_msg void OnBnClickedMul();
	afx_msg void OnBnClickedDiv();
	afx_msg void OnBnClicked0();
	afx_msg void OnBnClicked1();
	afx_msg void OnBnClicked2();
	afx_msg void OnBnClicked3();
	afx_msg void OnBnClicked4();
	afx_msg void OnBnClicked5();
	afx_msg void OnBnClicked6();
	afx_msg void OnBnClicked7();
	afx_msg void OnBnClicked8();
	afx_msg void OnBnClicked9();
	afx_msg void OnBnClickedA();
	afx_msg void OnBnClickedB();
	afx_msg void OnBnClickedC();
	afx_msg void OnBnClickedD();
	afx_msg void OnBnClickedE();
	afx_msg void OnBnClickedF();
	afx_msg void OnBnClickedAnd();
	afx_msg void OnBnClickedOr();
	afx_msg void OnBnClickedXor();
	afx_msg void OnBnClickedNot();
	afx_msg void OnBnClickedShr();
	afx_msg void OnBnClickedShl();
	afx_msg void OnBnClickedRadiohex();
	afx_msg void OnBnClickedRadiodec();
	afx_msg void OnBnClickedRadiobin();

};
