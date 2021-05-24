// COpenCVTestDlg.cpp: 구현 파일
//

#include "pch.h"
#include "BitmapCV.h"
#include "COpenCVTestDlg.h"
#include "afxdialogex.h"


// COpenCVTestDlg 대화 상자

IMPLEMENT_DYNAMIC(COpenCVTestDlg, CDialogEx)

COpenCVTestDlg::COpenCVTestDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

COpenCVTestDlg::~COpenCVTestDlg()
{
}

void COpenCVTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PC_VIEW, m_pcview);
	DDX_Control(pDX, IDC_CHECK1, m_check);
}


BEGIN_MESSAGE_MAP(COpenCVTestDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_IMAGELOAD, &COpenCVTestDlg::OnBnClickedBtnImageload)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_CHECK1, &COpenCVTestDlg::OnBnClickedCheck1)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_STN_CLICKED(IDC_PC_VIEW, &COpenCVTestDlg::OnStnClickedPcView)
	ON_BN_CLICKED(IDC_BTN_MASKEDIMG, &COpenCVTestDlg::OnBnClickedBtnMaskedimg)
	ON_BN_CLICKED(IDC_BTN_MASKEDIMG2, &COpenCVTestDlg::OnBnClickedBtnMaskedimg2)
END_MESSAGE_MAP()


// COpenCVTestDlg 메시지 처리기


void COpenCVTestDlg::CreateBitmapInfo(int w, int h, int bpp)
{
	if (m_pBitmapInfo != NULL)
	{
		delete m_pBitmapInfo;
		m_pBitmapInfo = NULL;
	}

	if (bpp == 8)
		m_pBitmapInfo = (BITMAPINFO *) new BYTE[sizeof(BITMAPINFO) + 255 * sizeof(RGBQUAD)];
	else // 24 or 32bit
		m_pBitmapInfo = (BITMAPINFO *) new BYTE[sizeof(BITMAPINFO)];

	m_pBitmapInfo->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	m_pBitmapInfo->bmiHeader.biPlanes = 1;
	m_pBitmapInfo->bmiHeader.biBitCount = bpp;
	m_pBitmapInfo->bmiHeader.biCompression = BI_RGB;
	m_pBitmapInfo->bmiHeader.biSizeImage = 0;
	m_pBitmapInfo->bmiHeader.biXPelsPerMeter = 0;
	m_pBitmapInfo->bmiHeader.biYPelsPerMeter = 0;
	m_pBitmapInfo->bmiHeader.biClrUsed = 0;
	m_pBitmapInfo->bmiHeader.biClrImportant = 0;

	if (bpp == 8)
	{
		for (int i = 0; i < 256; i++)
		{
			m_pBitmapInfo->bmiColors[i].rgbBlue = (BYTE)i;
			m_pBitmapInfo->bmiColors[i].rgbGreen = (BYTE)i;
			m_pBitmapInfo->bmiColors[i].rgbRed = (BYTE)i;
			m_pBitmapInfo->bmiColors[i].rgbReserved = 0;
		}
	}

	m_pBitmapInfo->bmiHeader.biWidth = w;
	m_pBitmapInfo->bmiHeader.biHeight = -h;
}


void COpenCVTestDlg::DrawImage()
{
	CClientDC dc(GetDlgItem(IDC_PC_VIEW));

	CRect rect;
	GetDlgItem(IDC_PC_VIEW)->GetClientRect(&rect);
	
	SetStretchBltMode(dc.GetSafeHdc(), COLORONCOLOR);
	StretchDIBits(dc.GetSafeHdc(), 0, 0, m_matImage.cols, m_matImage.rows, 0, 0,
		m_matImage.cols, m_matImage.rows, m_matImage.data, m_pBitmapInfo, DIB_RGB_COLORS, SRCCOPY);
}


void COpenCVTestDlg::OnBnClickedBtnImageload()
{
	CFileDialog fileDlg(TRUE, NULL, NULL, OFN_READONLY, _T("image file(*.jpg;*.bmp;*.png;)|*.jpg;*.bmp;*.png;|All Files(*.*)|*.*||"));
	if (fileDlg.DoModal() == IDOK)
	{
		CString path = fileDlg.GetPathName();

		CT2CA pszString(path);
		std::string strPath(pszString);

		m_matImage = imread(strPath, cv::IMREAD_COLOR);

		CreateBitmapInfo(m_matImage.cols, m_matImage.rows, m_matImage.channels() * 8);

		DrawImage();
	}
}





void COpenCVTestDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.

}


void COpenCVTestDlg::OnBnClickedCheck1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void COpenCVTestDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	BOOL chk;
	chk = m_check.GetCheck();

	if (chk == 1) { //체크 되어있으면 1 아니면 0
		//CDC* p = m_pcview.GetWindowDC();
		SetCapture();
		m_ptPrev = point;
	}
	CDialogEx::OnLButtonDown(nFlags, point);
}


void COpenCVTestDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	BOOL chk;
	chk = m_check.GetCheck();

	if (chk == 1) { //체크 되어있으면 1 아니면 0
		ReleaseCapture();
	}
	CDialogEx::OnLButtonUp(nFlags, point);
}


void COpenCVTestDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	BOOL chk;
	chk = m_check.GetCheck();

	if (chk == 1) { //체크 되어있으면 1 아니면 0
		if (!(nFlags & MK_LBUTTON))
			return;

		CDC* p = m_pcview.GetWindowDC();
		//CClientDC dc(this);
		CPen mypen(PS_SOLID, 35, RGB(0, 0, 0));
		CPen *oldpen = p->SelectObject(&mypen);
		p->MoveTo(m_ptPrev); //이전 좌표에서
		p->LineTo(point); //현재 좌표까지 선을 그린다. 
		m_ptPrev = point;				  // 직선 끝점의 좌표를 갱신한다. 
	}
	CDialogEx::OnMouseMove(nFlags, point);
}


void COpenCVTestDlg::OnStnClickedPcView()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void COpenCVTestDlg::OnBnClickedBtnMaskedimg()
{
	int i, j;

	CImage Image;
	int cx = m_matImage.cols;
	int cy = m_matImage.rows;
	int cbpp = m_matImage.channels() * 8;
	Image.Create( cx, cy, cbpp);


	CDC* DC = m_pcview.GetWindowDC();
	CDC* pDC = CDC::FromHandle(Image.GetDC());
	pDC->BitBlt(0, 0, cx, cy, DC, 0, 0, SRCCOPY);
	Image.ReleaseDC();

	Image.Save(TEXT("masked.bmp"), Gdiplus::ImageFormatBMP);

	m_masked_img1 = imread("masked.bmp", cv::IMREAD_COLOR);//cv::IMREAD_UNCHANGED
	int w = m_masked_img1.cols;
	int h = m_masked_img1.rows;
	int c = m_masked_img1.channels();
	for (int i = 0; i < w*h*c; i++) {
		if (m_masked_img1.data[i] != 0)
			m_masked_img1.data[i] = 255;
	}
	cv::bitwise_not(m_masked_img1, m_masked_img2);
}


void COpenCVTestDlg::OnBnClickedBtnMaskedimg2()
{

	cv::bitwise_and(m_masked_img1, m_matImage, temp1);
	cv::imwrite("masked3.bmp", temp1);

	CFile File;
	CFileDialog OpenDlg(TRUE);
	AfxMessageBox("합성할 영상을 입력하시오");
	if (OpenDlg.DoModal() == IDOK) { // 합성할 영상을 입력
		CString path = OpenDlg.GetPathName();

		CT2CA pszString(path);
		std::string strPath(pszString);
		m_backgroundImage = imread(strPath, cv::IMREAD_COLOR);
		cv::bitwise_and(m_masked_img2, m_backgroundImage, temp2);
	}
	cv::bitwise_or(temp1, temp2, outputImage);
	cv::imwrite("output.bmp", outputImage);
}

