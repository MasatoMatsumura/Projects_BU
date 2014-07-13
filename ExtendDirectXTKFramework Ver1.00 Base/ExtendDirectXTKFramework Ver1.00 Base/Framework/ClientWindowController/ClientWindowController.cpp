//===============================================================================================
//	@file		ClientWindowController.cpp
//	@brief		クライアントウィンドウの制御クラス実装コード
//	@author		MasatoMatsumura
//
//	@version	1.00
//	@since		FrameworkVer1.00( 2014/07/10 )
//	@date		2014/07/10
//===============================================================================================
//	TODO :	追加のインクルードファイルは以下に記述
//-----------------------------------------------------------------------------------------------
//■ClientWindowControllerの定義読み込み
#include "ClientWindowController.h"
//■DeviceControllerの定義読み込み
#include "../DeviceController/DeviceController.h"

//===============================================================================================
//	TODO :	追加のusingディレクティブは以下に記述
//-----------------------------------------------------------------------------------------------
using namespace Framework;

//===============================================================================================
//	TODO :	ClientWindowControllerクラスの実装は以下に記述
//===============================================================================================

//===============================================================================================
//	@class	ClientWindowController	"ClientWindowController.h"
//	@fn		ClientWindowController
//	@Brief	クライアントウィンドウの制御クラスの初期化を行う
//-----------------------------------------------------------------------------------------------
ClientWindowController::ClientWindowController( )
{
}

//===============================================================================================
//	@class	ClientWindowController	"ClientWindowController.h"
//	@fn		~ClientWindowController
//	@Brief	{	デストラクタ
//				クライアントウィンドウの制御クラスの終了処理を行う	}
//-----------------------------------------------------------------------------------------------
ClientWindowController::~ClientWindowController( )
{
}

//===============================================================================================
//	@class	ClientWindowController	"ClientWindowController.h"
//	@fn		InitializeWindow
//	@Brief	{	イニシャライザ
//				ウィンドウクラスを設定、登録してクライアントウィンドウを作成する	}
//	@return	成功を表すS_OK定数を返す
//-----------------------------------------------------------------------------------------------
int ClientWindowController::InitializeWindow( )
{
	//■ウインドウクラスの登録
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof( WNDCLASSEX );
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = this->WindowProcedure;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = WINAPIDATA->hInstance;
	wcex.hIcon = LoadIcon( WINAPIDATA->hInstance, (LPCTSTR)NULL );
	wcex.hCursor = LoadCursor( NULL, IDC_ARROW );
	wcex.hbrBackground = (HBRUSH)( COLOR_WINDOW + 1 );
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = WINAPIDATA->szWindowClass.c_str( );

	wcex.hIconSm = LoadIcon( wcex.hInstance, (LPCTSTR)NULL );
	if( !RegisterClassEx( &wcex ) )
		return E_FAIL;

	// ウインドウの作成
	RECT rc = { 0, 0, WINAPIDATA->CLIENT_WIDTH, WINAPIDATA->CLIENT_HEIGHT };
	AdjustWindowRect( &rc, WS_OVERLAPPEDWINDOW, FALSE );
	WINAPIDATA->nWidth = rc.right - rc.left;
	WINAPIDATA->nHeight = rc.bottom - rc.top;
	WINAPIDATA->hWnd = CreateWindow( WINAPIDATA->szWindowClass.c_str( ), WINAPIDATA->szTitle.c_str( ),
		WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX & ~WS_THICKFRAME,	// 最大化ボタン無効とウインドウサイズを変更できないように設定
		CW_USEDEFAULT, CW_USEDEFAULT, WINAPIDATA->nWidth, WINAPIDATA->nHeight, NULL, NULL, WINAPIDATA->hInstance,
		NULL );
	if( !WINAPIDATA->hWnd )
		return E_FAIL;

	ShowWindow( WINAPIDATA->hWnd, WINAPIDATA->nCmdShow );

	return S_OK;
}

//===============================================================================================
//	@class	ClientWindowController	"ClientWindowController.h"
//	@fn		LRESULT CALLBACK WindowProcedure( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
//	@Brief	{	ウィンドウプロシージャ
//				WindowsOSのシステムメッセージ（ WindowsMessage ）から適した処理を行う	}
//	@return	{	LRESULT型
//				通常時は0を返却し、例外時にDefWindowProc( )関数の戻り値を返す	}
//-----------------------------------------------------------------------------------------------
LRESULT CALLBACK ClientWindowController::WindowProcedure( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
{
	switch( message )
	{
		case WM_KEYDOWN:				// キー押し下げ
			if( wParam == VK_ESCAPE )
				// [ESC]キー
				PostQuitMessage( 0 );			// アプリケーションの終了

		case WM_DESTROY:
			PostQuitMessage( 0 );
			break;

		case WM_SIZE:
			DEVICECONTROLLER->ResizeBackBuffer( );
			break;

		default:
			return DefWindowProc( hWnd, message, wParam, lParam );
	}

	return 0;
}