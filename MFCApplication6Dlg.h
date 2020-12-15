
// MFCApplication6Dlg.h: 헤더 파일
//

#pragma once


// CMFCApplication6Dlg 대화 상자
class CMFCApplication6Dlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCApplication6Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	enum FourOP m_selectedOP;
	int m_nFirstOperand;
	int m_nSecondOperand;
	float m_nResult;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION6_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	
	CString m_EditValue;   // 계산기의 화면을 멤버 변수로 추가
	
	
	afx_msg void OnBnClickedButton16();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton13();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton15();
	afx_msg void OnBnClickedButton18();
	
	
	
};

enum FourOP {           // 어떤 연산자 버튼을 눌렀는지 구분하게 해주는 열거형 자료형
	PLUS = 1001,
	MINUS,
	MULTIPLY,
	DIVIDE,
	NONE
};

