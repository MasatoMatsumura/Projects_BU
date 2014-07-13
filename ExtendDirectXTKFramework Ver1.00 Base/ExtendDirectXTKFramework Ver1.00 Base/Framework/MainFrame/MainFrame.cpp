#include "MainFrame.h"

using namespace std;
using namespace Framework;

MainFrame::MainFrame( )
{
}

MainFrame::~MainFrame( )
{
}

void MainFrame::InitializeFramework( )
{
	//■クライアントウィンドウの作成・登録
	CLIENTWINDOWCONTROLLER->InitializeWindow( );

	//■デバイスの初期化
	DEVICECONTROLLER->InitializeDevice( );

	//■DirectXTKモジュールの初期化
	DXTKCONTROLLER->InitializeDirectXTK( );
}