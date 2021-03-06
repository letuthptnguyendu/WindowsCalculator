
// MFCCalculatorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCCalculator.h"
#include "MFCCalculatorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCCalculatorDlg dialog
CMFCCalculatorDlg::CMFCCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCCALCULATOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RST, &CMFCCalculatorDlg::OnBnClickedRst)
	ON_BN_CLICKED(IDC_ADD, &CMFCCalculatorDlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_SUB, &CMFCCalculatorDlg::OnBnClickedSub)
	ON_BN_CLICKED(IDC_MUL, &CMFCCalculatorDlg::OnBnClickedMul)
	ON_BN_CLICKED(IDC_DIV, &CMFCCalculatorDlg::OnBnClickedDiv)
	ON_BN_CLICKED(IDC_0, &CMFCCalculatorDlg::OnBnClicked0)
	ON_BN_CLICKED(IDC_1, &CMFCCalculatorDlg::OnBnClicked1)
	ON_BN_CLICKED(IDC_2, &CMFCCalculatorDlg::OnBnClicked2)
	ON_BN_CLICKED(IDC_3, &CMFCCalculatorDlg::OnBnClicked3)
	ON_BN_CLICKED(IDC_4, &CMFCCalculatorDlg::OnBnClicked4)
	ON_BN_CLICKED(IDC_5, &CMFCCalculatorDlg::OnBnClicked5)
	ON_BN_CLICKED(IDC_6, &CMFCCalculatorDlg::OnBnClicked6)
	ON_BN_CLICKED(IDC_7, &CMFCCalculatorDlg::OnBnClicked7)
	ON_BN_CLICKED(IDC_8, &CMFCCalculatorDlg::OnBnClicked8)
	ON_BN_CLICKED(IDC_9, &CMFCCalculatorDlg::OnBnClicked9)
	ON_BN_CLICKED(IDC_A, &CMFCCalculatorDlg::OnBnClickedA)
	ON_BN_CLICKED(IDC_B, &CMFCCalculatorDlg::OnBnClickedB)
	ON_BN_CLICKED(IDC_C, &CMFCCalculatorDlg::OnBnClickedC)
	ON_BN_CLICKED(IDC_D, &CMFCCalculatorDlg::OnBnClickedD)
	ON_BN_CLICKED(IDC_E, &CMFCCalculatorDlg::OnBnClickedE)
	ON_BN_CLICKED(IDC_F, &CMFCCalculatorDlg::OnBnClickedF)
	ON_BN_CLICKED(IDC_OR, &CMFCCalculatorDlg::OnBnClickedOr)
	ON_BN_CLICKED(IDC_AND, &CMFCCalculatorDlg::OnBnClickedAnd)
	ON_BN_CLICKED(IDC_XOR, &CMFCCalculatorDlg::OnBnClickedXor)
	ON_BN_CLICKED(IDC_NOT, &CMFCCalculatorDlg::OnBnClickedNot)
	ON_BN_CLICKED(IDC_ShR, &CMFCCalculatorDlg::OnBnClickedShr)
	ON_BN_CLICKED(IDC_ShL, &CMFCCalculatorDlg::OnBnClickedShl)
	ON_BN_CLICKED(IDC_RADIOHEX, &CMFCCalculatorDlg::OnBnClickedRadiohex)
	ON_BN_CLICKED(IDC_RADIODEC, &CMFCCalculatorDlg::OnBnClickedRadiodec)
	ON_BN_CLICKED(IDC_RADIOBIN, &CMFCCalculatorDlg::OnBnClickedRadiobin)
END_MESSAGE_MAP()

// CMFCCalculatorDlg message handlers


BOOL CMFCCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();


	//disable 3boxes show dec, hex, bin
	GetDlgItem(IDC_SHOWDEC)->ModifyStyle(0, WS_DISABLED);
	GetDlgItem(IDC_SHOWHEX)->ModifyStyle(0, WS_DISABLED);
	//GetDlgItem(IDC_SHOWBIN)->ModifyStyle(0, WS_DISABLED);

	
	//set check dec
	CButton* pButton = (CButton*)GetDlgItem(IDC_RADIODEC);
	pButton->SetCheck(true);

	// font SHOW
	m_Font.CreatePointFont(230, _T("Arial"));
	GetDlgItem(IDC_SHOW)->SetFont(&m_Font);

	// disable hex
	btnDisDEC();





	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCCalculatorDlg::btnDisDEC() {
	CWnd* A_btn = GetDlgItem(IDC_A);
	CWnd* B_btn = GetDlgItem(IDC_B);
	CWnd* C_btn = GetDlgItem(IDC_C);
	CWnd* D_btn = GetDlgItem(IDC_D);
	CWnd* E_btn = GetDlgItem(IDC_E);
	CWnd* F_btn = GetDlgItem(IDC_F);

	A_btn->EnableWindow(FALSE);
	B_btn->EnableWindow(FALSE);
	C_btn->EnableWindow(FALSE);
	D_btn->EnableWindow(FALSE);
	E_btn->EnableWindow(FALSE);
	F_btn->EnableWindow(FALSE);
}
void CMFCCalculatorDlg::btnDisBIN() {
	btnDisDEC();

	CWnd* b_btn = GetDlgItem(IDC_2);
	CWnd* c_btn = GetDlgItem(IDC_3);
	CWnd* d_btn = GetDlgItem(IDC_4);
	CWnd* e_btn = GetDlgItem(IDC_5);
	CWnd* f_btn = GetDlgItem(IDC_6);
	CWnd* g_btn = GetDlgItem(IDC_7);
	CWnd* h_btn = GetDlgItem(IDC_8);
	CWnd* i_btn = GetDlgItem(IDC_9);

	b_btn->EnableWindow(FALSE);
	c_btn->EnableWindow(FALSE);
	d_btn->EnableWindow(FALSE);
	e_btn->EnableWindow(FALSE);
	f_btn->EnableWindow(FALSE);
	g_btn->EnableWindow(FALSE);
	h_btn->EnableWindow(FALSE);
	i_btn->EnableWindow(FALSE);
}
void CMFCCalculatorDlg::btnEnDEC() {
	CWnd* b_btn = GetDlgItem(IDC_2);
	CWnd* c_btn = GetDlgItem(IDC_3);
	CWnd* d_btn = GetDlgItem(IDC_4);
	CWnd* e_btn = GetDlgItem(IDC_5);
	CWnd* f_btn = GetDlgItem(IDC_6);
	CWnd* g_btn = GetDlgItem(IDC_7);
	CWnd* h_btn = GetDlgItem(IDC_8);
	CWnd* i_btn = GetDlgItem(IDC_9);

	b_btn->EnableWindow(TRUE);
	c_btn->EnableWindow(TRUE);
	d_btn->EnableWindow(TRUE);
	e_btn->EnableWindow(TRUE);
	f_btn->EnableWindow(TRUE);
	g_btn->EnableWindow(TRUE);
	h_btn->EnableWindow(TRUE);
	i_btn->EnableWindow(TRUE);
}
void CMFCCalculatorDlg::btnEnHEX() {
	btnEnDEC();

	CWnd* A_btn = GetDlgItem(IDC_A);
	CWnd* B_btn = GetDlgItem(IDC_B);
	CWnd* C_btn = GetDlgItem(IDC_C);
	CWnd* D_btn = GetDlgItem(IDC_D);
	CWnd* E_btn = GetDlgItem(IDC_E);
	CWnd* F_btn = GetDlgItem(IDC_F);

	A_btn->EnableWindow(TRUE);
	B_btn->EnableWindow(TRUE);
	C_btn->EnableWindow(TRUE);
	D_btn->EnableWindow(TRUE);
	E_btn->EnableWindow(TRUE);
	F_btn->EnableWindow(TRUE);
}

void CMFCCalculatorDlg::OnBnClickedRst()
{
	if (db == false) {	//1st time press '='
		qint2 = { 0, 0, 0, 0 };

		//get input 2
		getFromSHOWX(heso, snd_num);

		if (snd_num == "") {
			snd_num = "0";
		}

		CStringToQInt(snd_num, heso, qint2);
	}

	// main processing
	switch (ope) {
	case 0:
		qintResult = qint2;
		break;
	case 1:
		qintResult = qint1 + qint2;
		break;
	case 2:
		qintResult = qint1 - qint2;
		break;
	case 3:
		qintResult = qint1 * qint2;
		break;
	case 4:
		qintResult = qint1 / qint2;
		break;
	case 5:
		qintResult = qint1 & qint2;
		break;
	case 6:
		qintResult = qint1 | qint2;
		break;
	case 7:
		qintResult = qint1 ^ qint2;
		break;
	case 8:
		qintResult = !qint2;
		break;
	case 9:
		qintResult = qint1 << qint2;
		break;
	case 10:
		qintResult = qint1 >> qint2;
		break;
	default:
		break;
	}

	//view
	CString temp;
	GetDlgItemText(IDC_SHOW, temp);
	if (db == true) {	//press '=' more than 1 time
		switch (ope) {
		case 1:
			SetDlgItemText(IDC_SHOW, fst_num + L" + " + snd_num);
			break;
		case 2:
			SetDlgItemText(IDC_SHOW, fst_num + L" - " + snd_num);
			break;
		case 3:
			SetDlgItemText(IDC_SHOW, fst_num + L" * " + snd_num);
			break;
		case 4:
			SetDlgItemText(IDC_SHOW, fst_num + L" / " + snd_num);
			break;
		case 7:
			SetDlgItemText(IDC_SHOW, fst_num + L" XOR " + snd_num);
			break;
		case 9:
			SetDlgItemText(IDC_SHOW, fst_num + L" << " + snd_num);
			break;
		case 10:
			SetDlgItemText(IDC_SHOW, fst_num + L" >> " + snd_num);
			break;
		default:
			break;
		}
	}
	else {	// db = false
		SetDlgItemText(IDC_SHOW, temp + snd_num);
	}

	// view - init the results and set in result boxes
	CString result_cs_dec(getValue(qintResult).c_str());
	CString result_cs_bin(decToBin(qintResult).c_str());
	CString result_cs_hex(decToHex(qintResult).c_str());
	if (result_cs_dec == L"0") {
		result_cs_hex = L"0";
		result_cs_bin = L"0";
	}
	SetDlgItemText(IDC_SHOWDEC, result_cs_dec);
	SetDlgItemText(IDC_SHOWHEX, result_cs_hex);
	SetDlgItemText(IDC_SHOWBIN, result_cs_bin);

	//result -> qint1, thao tac voi qint2
	qint1 = qintResult;
	fst_num = result_cs_dec;

	//change double click
	db = true;
}

void CMFCCalculatorDlg::process2operand(int ope) {
	qint1 = { 0, 0, 0, 0 };

	//get input...
	getFromSHOWX(heso, fst_num);

	if (fst_num == L"") {
		fst_num = L"0";
	}
	//... and convert to QInt
	CStringToQInt(fst_num, heso, qint1);

	switch (ope) {
	case 1:
		SetDlgItemText(IDC_SHOW, fst_num + L" + ");//add in SHOW(history) box
		break;
	case 2:
		SetDlgItemText(IDC_SHOW, fst_num + L" - ");//add in SHOW(history) box
		break;
	case 3:
		SetDlgItemText(IDC_SHOW, fst_num + L" * "); //add in SHOW(history) box
		break;

	case 4:
		SetDlgItemText(IDC_SHOW, fst_num + L" / "); //add in SHOW(history) box
		break;

	case 5:
		SetDlgItemText(IDC_SHOW, fst_num + L" AND ");//add in SHOW(history) box
		break;
	case 6:
		SetDlgItemText(IDC_SHOW, fst_num + L" OR ");//add in SHOW(history) box
		break;
	case 7:
		SetDlgItemText(IDC_SHOW, fst_num + L" XOR "); //add in SHOW(history) box
		break;

	case 9:
		SetDlgItemText(IDC_SHOW, fst_num + L" << "); //add in SHOW(history) box
		break;
	case 10:
		SetDlgItemText(IDC_SHOW, fst_num + L" >> "); //add in SHOW(history) box
		break;
	default: break;
	}

	emptyInputBoxes();
	db = false;
}
void CMFCCalculatorDlg::OnBnClickedAdd()
{
	ope = 1;
	process2operand(ope);
}
void CMFCCalculatorDlg::OnBnClickedSub()
{
	CString cs;
	getFromSHOWX(heso, cs);
	if (cs == "" || cs[cs.GetLength()-1] =='-') {
		cs += '-';
		if (heso == 10) {
			SetDlgItemText(IDC_SHOWDEC, cs);
		}
		else if (heso == 2) {
			SetDlgItemText(IDC_SHOWBIN, cs);
		}
		else if (heso == 16) {
			SetDlgItemText(IDC_SHOWHEX, cs);
		}
	}
	else {
		ope = 2;
		process2operand(ope);
	}
}
void CMFCCalculatorDlg::OnBnClickedMul()
{
	ope = 3;
	process2operand(ope);
}
void CMFCCalculatorDlg::OnBnClickedDiv()
{
	ope = 4;
	process2operand(ope);
}

//onpress BS, ESC
void CMFCCalculatorDlg::OnPressBS() {
	//get input...
	getFromSHOWX(heso, fst_num);

	if (fst_num == L"") {
		fst_num = L"0";
	}

	fst_num.Delete(fst_num.GetLength() - 1);


	if (heso == 10) {
		SetDlgItemText(IDC_SHOWDEC, fst_num);
	}
	else if (heso == 2) {
		SetDlgItemText(IDC_SHOWBIN, fst_num);
	}
	else if (heso == 16) {
		SetDlgItemText(IDC_SHOWHEX, fst_num);
	}
}
void CMFCCalculatorDlg::OnPressESC() {
	db = false;
	ope = 0;

	qint1 = { 0, 0, 0, 0 };
	qint2 = { 0, 0, 0, 0 };
	fst_num = "";
	snd_num = "";

	SetDlgItemText(IDC_SHOW, L"");
	emptyInputBoxes();
}

void CMFCCalculatorDlg::getFromSHOWX(int heso, CString &cs) {
	if (heso == 10) {
		GetDlgItemText(IDC_SHOWDEC, cs);
	}
	else if (heso == 2) {
		GetDlgItemText(IDC_SHOWBIN, cs);
	}
	else if (heso == 16) {
		GetDlgItemText(IDC_SHOWHEX, cs);
	}
}
void CMFCCalculatorDlg::CStringToQInt(CString cs, int heso, QInt &qint2) {
	// CString to string
	CT2CA pszConvertedAnsiString(cs);
	string strStd(pszConvertedAnsiString);

	//assign value (string) to QInt
	if (heso == 2) {
		qint2 = binToDec(strStd);
	}
	else if (heso == 16) {
		qint2 = hexToDec(strStd);
	}
	else if (heso == 10) {
		scanQInt(strStd, qint2);
	}
}
//check radio
void CMFCCalculatorDlg::OnBnClickedRadiohex()
{
	qint1 = { 0, 0, 0, 0 };
	qint2 = { 0, 0, 0, 0 };
	fst_num = "0";
	snd_num = "0";
	SetDlgItemText(IDC_SHOW, L"");
	if (heso != 16) { btnEnHEX(); }
	emptyInputBoxes();
	heso = 16;
}
void CMFCCalculatorDlg::OnBnClickedRadiodec()
{
	qint1 = { 0, 0, 0, 0 };
	qint2 = { 0, 0, 0, 0 };
	fst_num = "0";
	snd_num = "0";
	SetDlgItemText(IDC_SHOW, L"");
	if (heso == 2) { btnEnDEC(); }
	else { btnDisDEC(); }
	emptyInputBoxes();
	heso = 10;
}
void CMFCCalculatorDlg::OnBnClickedRadiobin()
{
	qint1 = { 0, 0, 0, 0 };
	qint2 = { 0, 0, 0, 0 };
	fst_num = "0";
	snd_num = "0";
	SetDlgItemText(IDC_SHOW, L"");
	if (heso!=2) btnDisBIN();
	emptyInputBoxes();
	heso = 2;
}

//btn event
void CMFCCalculatorDlg::setInputBtn(int heso, char key) {
	CString temp;
	int pos;
	char hex_ch[16] = { '0', '1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };

	//get value of hexCh
	for (int i = 0; i < 16; i++) {
		if (hex_ch[i] == key) {
			pos = i;
			break;
		}
	}

	if (heso == 10 && pos < 10) {
		GetDlgItemText(IDC_SHOWDEC, temp);
		temp += hex_ch[pos];
		SetDlgItemText(IDC_SHOWDEC, temp);
	}
	else if (heso == 2 && pos < 2) {
		GetDlgItemText(IDC_SHOWBIN, temp);
		temp += hex_ch[pos];
		SetDlgItemText(IDC_SHOWBIN, temp);
	}
	else if (heso == 16) {
		GetDlgItemText(IDC_SHOWHEX, temp);
		temp += hex_ch[pos];
		SetDlgItemText(IDC_SHOWHEX, temp);
	}
}
//digit
void CMFCCalculatorDlg::OnBnClicked0()
{
	setInputBtn(heso, '0');
}
void CMFCCalculatorDlg::OnBnClicked1()
{
	setInputBtn(heso, '1');
}
void CMFCCalculatorDlg::OnBnClicked2()
{
	setInputBtn(heso, '2');
}
void CMFCCalculatorDlg::OnBnClicked3()
{
	setInputBtn(heso, '3');
}
void CMFCCalculatorDlg::OnBnClicked4()
{
	setInputBtn(heso, '4');
}
void CMFCCalculatorDlg::OnBnClicked5()
{
	setInputBtn(heso, '5');
}
void CMFCCalculatorDlg::OnBnClicked6()
{
	setInputBtn(heso, '6');
}
void CMFCCalculatorDlg::OnBnClicked7()
{
	setInputBtn(heso, '7');
}
void CMFCCalculatorDlg::OnBnClicked8()
{
	setInputBtn(heso, '8');
}
void CMFCCalculatorDlg::OnBnClicked9()
{
	setInputBtn(heso, '9');
}
//hex char
void CMFCCalculatorDlg::OnBnClickedA()
{
	setInputBtn(heso, 'A');
}
void CMFCCalculatorDlg::OnBnClickedB()
{
	setInputBtn(heso, 'B');
}
void CMFCCalculatorDlg::OnBnClickedC()
{
	setInputBtn(heso, 'C');
}
void CMFCCalculatorDlg::OnBnClickedD()
{
	setInputBtn(heso, 'D');
}
void CMFCCalculatorDlg::OnBnClickedE()
{
	setInputBtn(heso, 'E');
}
void CMFCCalculatorDlg::OnBnClickedF()
{
	setInputBtn(heso, 'F');
}

//bit
void CMFCCalculatorDlg::OnBnClickedAnd()
{
	ope = 5;	//and
	process2operand(ope);
}
void CMFCCalculatorDlg::OnBnClickedOr()
{
	ope = 6;	//or
	process2operand(ope);
}
void CMFCCalculatorDlg::OnBnClickedXor()
{

	ope = 7;	//xor
	process2operand(ope);
}
void CMFCCalculatorDlg::OnBnClickedNot()
{
	SetDlgItemText(IDC_SHOW, L"NOT "); //add in SHOW(history) box

	emptyInputBoxes();

	ope = 8;	//not
	db = false;
}
void CMFCCalculatorDlg::OnBnClickedShr()
{
	ope = 10;	//shift right
	process2operand(ope);
}
void CMFCCalculatorDlg::OnBnClickedShl()
{
	ope = 9;	//shift left
	process2operand(ope);
}

void CMFCCalculatorDlg::emptyInputBoxes() {
	//empty the input
	SetDlgItemText(IDC_SHOWDEC, L"");
	SetDlgItemText(IDC_SHOWBIN, L"");
	SetDlgItemText(IDC_SHOWHEX, L"");
}

//lock the ENTER key???
void CMFCCalculatorDlg::OnOK(void)
{
	CWnd* pWnd = GetFocus();
	if (GetDlgItem(IDOK) == pWnd)
	{
		CDialog::OnOK();
		return;
	}

	// Enter key was hit -> do whatever you want
}

BOOL CMFCCalculatorDlg::PreTranslateMessage(MSG *pMsg)
{
	int x = (int)pMsg->wParam;

	if (pMsg->message == WM_KEYDOWN)
	{
		switch (x) {
		case 0x30:
		case VK_NUMPAD0:
			OnBnClicked0();
			break;
		case 0x31:
		case VK_NUMPAD1:
			OnBnClicked1();
			break;
		case 0x32:
		case VK_NUMPAD2:
			OnBnClicked2();
			break;
		case 0x33:
		case VK_NUMPAD3:
			OnBnClicked3();
			break;
		case 0x34:
		case VK_NUMPAD4:
			OnBnClicked4();
			break;
		case 0x35:
		case VK_NUMPAD5:
			OnBnClicked5();
			break;
		case 0x36:
		case VK_NUMPAD6:
			OnBnClicked6();
			break;
		case 0x37:
		case VK_NUMPAD7:
			OnBnClicked7();
			break;
		case 0x38:
		case VK_NUMPAD8:
			OnBnClicked8();
			break;
		case 0x39:
		case VK_NUMPAD9:
			OnBnClicked9();
			break;

			//handle the operation event
		case VK_ADD:
			OnBnClickedAdd();
			break;
		case VK_SUBTRACT:
			OnBnClickedSub();
			break;
		case VK_DIVIDE:
			OnBnClickedDiv();
			break;
		case VK_MULTIPLY:
			OnBnClickedMul();
			break;
		case VK_RETURN:
			OnBnClickedRst();
			return true;

		case 0x41:
			OnBnClickedA();
			break;
		case 0x42:
			OnBnClickedB();
			break;
		case 0x43:
			OnBnClickedC();
			break;
		case 0x44:
			OnBnClickedD();
			break;
		case 0x45:
			OnBnClickedE();
			break;
		case 0x46:
			OnBnClickedF();
			break;

		case VK_BACK:
			OnPressBS();
			return true;

			//handle the ESC key
		case VK_ESCAPE:
		case VK_CANCEL:
			::DispatchMessage(pMsg);
			OnPressESC();
			return true;
		default:
			break;
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}
