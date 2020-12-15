
// MFCApplication6Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication6.h"
#include "MFCApplication6Dlg.h"
#include "afxdialogex.h"
#include <stack>
#include <string>
#include <iostream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

class calculation {                     // 여러 숫자를 입력받아 처리하는 클래스 생성
private:
	stack<float> operand;
	stack<char> op;
	string number;

	void operation() {
		float num2 = operand.top();
		operand.pop();
		float num1 = operand.top();
		operand.pop();
		char c = op.top();
		op.pop();
		float result;
		if (c == '+')
			result = num1 + num2;
		else if (c == '-')
			result = num1 - num2;
		else if (c == '*')
			result = num1 * num2;
		else if (c == '/')
			result = num1 / num2;
		operand.push(result);
		//cout << result << " ";
	}
public:
	calculation() {
		number = "";
	}
	float calc(const string& input) {
		float result = 0;
		for (char i : input) {
			if (isdigit(i) || i == '.') {
				this->number += i;
			}
			else {
				if (this->number != "") {
					this->operand.push(atof(this->number.c_str()));
					this->number = "";
				}
				if (i == '(') {
					op.push(i);
				}
				else if (i == ')') {
					while (op.top() != '(') {
						this->operation();
					}
					op.pop();
				}
				else if (i == '+' || i == '-') {
					if (op.empty() || \
						op.top() == '+' || op.top() == '-' || op.top() == '(') {
						op.push(i);
					}
					else {
						operation();
						op.push(i);
					}
				}
				else if (i == '=') {
					while (!op.empty()) {
						operation();
					}
					result = operand.top();
				}
				else if (i == '*' || i == '/' || i == '%') {
					if (op.empty() || \
						op.top() == '+' || op.top() == '-' || op.top() == '(') {
						op.push(i);
					}
					else {
						operation();
						op.push(i);
					}
				}
			}
		}
		return result;
	}
};
// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
public:
	   // 키보드 입력을 받아서 인식
	
	
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


// CMFCApplication6Dlg 대화 상자



CMFCApplication6Dlg::CMFCApplication6Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION6_DIALOG, pParent)
	, m_EditValue(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication6Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_EditValue);
}

BEGIN_MESSAGE_MAP(CMFCApplication6Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	
	
	ON_BN_CLICKED(IDC_BUTTON16, &CMFCApplication6Dlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCApplication6Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCApplication6Dlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CMFCApplication6Dlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication6Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication6Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplication6Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication6Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication6Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication6Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON13, &CMFCApplication6Dlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON12, &CMFCApplication6Dlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON11, &CMFCApplication6Dlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON10, &CMFCApplication6Dlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON15, &CMFCApplication6Dlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON18, &CMFCApplication6Dlg::OnBnClickedButton18)
	ON_WM_KEYDOWN()
	
END_MESSAGE_MAP()


// CMFCApplication6Dlg 메시지 처리기

BOOL CMFCApplication6Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	m_selectedOP = NONE;
	m_nFirstOperand = 0;
	m_nSecondOperand = 0;


	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCApplication6Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCApplication6Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCApplication6Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}








// 각각의 계산기 버튼에 해당하는 숫자 입력

void CMFCApplication6Dlg::OnBnClickedButton16()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EditValue = m_EditValue + '0';
	UpdateData(FALSE);
}


void CMFCApplication6Dlg::OnBnClickedButton7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EditValue = m_EditValue + '1';
	UpdateData(FALSE);
}


void CMFCApplication6Dlg::OnBnClickedButton8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EditValue = m_EditValue + '2';
	UpdateData(FALSE);
}


void CMFCApplication6Dlg::OnBnClickedButton9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다..
	UpdateData(TRUE);
	m_EditValue = m_EditValue + '3';
	UpdateData(FALSE);
}


void CMFCApplication6Dlg::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EditValue = m_EditValue + '4';
	UpdateData(FALSE);
}


void CMFCApplication6Dlg::OnBnClickedButton5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EditValue = m_EditValue + '5';
	UpdateData(FALSE);
}


void CMFCApplication6Dlg::OnBnClickedButton6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EditValue = m_EditValue + '6';
	UpdateData(FALSE);
}


void CMFCApplication6Dlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EditValue = m_EditValue + '7';
	UpdateData(FALSE);
}


void CMFCApplication6Dlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EditValue = m_EditValue + '8';
	UpdateData(FALSE);
}


void CMFCApplication6Dlg::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EditValue = m_EditValue + '9';
	UpdateData(FALSE);
}




//AC버튼 
void CMFCApplication6Dlg::OnBnClickedButton18()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_nFirstOperand = 0;
	m_nSecondOperand = PLUS;
	m_nResult = 0;
	m_EditValue = ' ';
	UpdateData(FALSE);
}


//각각의 사칙 연산 기호 입력

void CMFCApplication6Dlg::OnBnClickedButton13()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EditValue = m_EditValue + '/';
	UpdateData(FALSE);

}



void CMFCApplication6Dlg::OnBnClickedButton12()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EditValue = m_EditValue + '*';
	UpdateData(FALSE);
}


void CMFCApplication6Dlg::OnBnClickedButton11()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EditValue = m_EditValue + '-';
	UpdateData(FALSE);
}


void CMFCApplication6Dlg::OnBnClickedButton10()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EditValue = m_EditValue + '+';
	UpdateData(FALSE);
}


void CMFCApplication6Dlg::OnBnClickedButton15()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EditValue = m_EditValue + '=';
	
	calculation cal;
	
	std::string str = std::string(CT2CA(m_EditValue));
	float answer = cal.calc(str);
	string s = to_string(answer);
	CString cs(s.c_str());
	m_EditValue.Format(_T("%f"), answer);
	UpdateData(FALSE);
}





