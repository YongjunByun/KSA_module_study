#pragma once


// COpenCVTestDlg 대화 상자
#include <opencv2/core/mat.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>
#include "opencv2/highgui.hpp"
#include "opencv2/core.hpp"
class COpenCVTestDlg : public CDialogEx
{
	DECLARE_DYNAMIC(COpenCVTestDlg)

public:
	COpenCVTestDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~COpenCVTestDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	cv::Mat m_matImage; // 이미지 정보를 담고 있는 객체.
	cv::Mat m_backgroundImage;
	cv::Mat m_masked_img1;
	cv::Mat m_masked_img2;
	cv::Mat temp1;
	cv::Mat temp2;
	cv::Mat outputImage;
	BITMAPINFO* m_pBitmapInfo;; // Bitmap 정보를 담고 있는 구조체.


	void CreateBitmapInfo(int w, int h, int bpp); // Bitmap 정보를 생성하는 함수.
	void DrawImage(); // 그리는 작업을 수행하는 함수.
	afx_msg void OnBnClickedBtnImageload();
	afx_msg void OnPaint();
	CStatic m_pcview;
	afx_msg void OnBnClickedCheck1();
	CButton m_check;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	CPoint m_ptPrev;
	afx_msg void OnStnClickedPcView();
	afx_msg void OnBnClickedBtnMaskedimg();
	afx_msg void OnBnClickedBtnMaskedimg2();
};
