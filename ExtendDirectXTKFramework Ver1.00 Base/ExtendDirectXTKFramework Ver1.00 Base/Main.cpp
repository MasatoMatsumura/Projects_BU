//===============================================================================================
//	@File		Main.cpp
//	@Brief		
//===============================================================================================
//	TODO :	追加のインクルードファイルは以下に記述
//===============================================================================================
//	@brief	
//-----------------------------------------------------------------------------------------------
#include "Framework\MainFrame\MainFrame.h"
#include "Game\Scenes\TestScene.h"

//===============================================================================================
//	TODO :	追加のusingディレクティブは以下に記述
//===============================================================================================
//	@namespace	Framework
//	@brief		ExtendDirectXTKフレームワークのシステムが格納されている空間
//-----------------------------------------------------------------------------------------------
using namespace std;
using namespace Framework;
using namespace Game;

//===============================================================================================
//	TODO :	追加のグローバル変数は以下に記述
//===============================================================================================
//■
static unique_ptr<Scenes::TestScene>	pTestScene;

//===============================================================================================
//	TODO :	プログラムの実装は以下に記述
//===============================================================================================

//===============================================================================================
//	@fn		int WINAPI wWinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow )
//	@brief	{	エントリーポイント
//				プログラムのメイン処理を行う	}
//	@return	{	int型（キャスト）
//				WindowsOSからのシステムメッセージ（ WindowsMessage ）	}
//-----------------------------------------------------------------------------------------------
int WINAPI wWinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow )
{
	UNREFERENCED_PARAMETER( hPrevInstance );
	UNREFERENCED_PARAMETER( lpCmdLine );

	//■フレームワークの初期化
	FRAMEWORK->InitializeFramework( );

	//■ゲームの初期化
	FRAMEWORK->InitializeGame( );

	//■Windowsのメッセージを受け取るメッセンジャーを作成
	MSG messenger = { 0 };

	//■Windowsから終了メッセージを受け取るまでループする
	while( messenger.message != WM_QUIT )
	{
		if( PeekMessage( &messenger, nullptr, 0, 0, PM_REMOVE ) )
		{
			TranslateMessage( &messenger );
			DispatchMessage( &messenger );
		}
		else
		{
			//■フレームワークの実行
			if( !FRAMEWORK->ExecuteFramework( ) ) break;
		}
	}

	//■WindowsMessageを返却
	return (int)messenger.wParam;
}

//===============================================================================================
//	@class	MainFrame	"MainFrame.h"
//	@fn		void InitializeGame( )
//	@brief	{	イニシャライザ
//				ゲームプログラムの初期化処理を行う	}
//	@return	{	なし	}
//-----------------------------------------------------------------------------------------------
void MainFrame::InitializeGame( )
{
	pTestScene.reset( new Scenes::TestScene( ) );
	pTestScene->Initialize( );
}

//===============================================================================================
//	@class	MainFrame	"MainFrame.h"
//	@fn		ExecuteFramework( )
//	@brief	{	フレームワーク全体の更新処理を行う	}
//	@return	{	bool型のメンバ変数
//				プログラムを終了するかどうかのフラグを返す	
//-----------------------------------------------------------------------------------------------
bool MainFrame::ExecuteFramework( )
{
	//■更新処理
	this->UpdateFramework( );

	//■描画処理
	this->DrawFramework( );

	//■値の返却
	return this->FLG_Execute;
}

//===============================================================================================
//	@class	MainFrame	"MainFrame.h"
//	@fn		void UpdateFramework( )
//	@brief	{	アップデータ
//				ゲーム本体の更新処理を行う	}
//	@return	{	なし	}
//-----------------------------------------------------------------------------------------------
void MainFrame::UpdateFramework( )
{
	pTestScene->Update( this->FLG_Execute );
}

//===============================================================================================
//	@class	MainFrame	"MainFrame.h"
//	@fn		DrawFramework( )
//	@brief	{	レンダラー
//				プログラム全体の描画処理を行う	}
//	@return	{	なし	}
//-----------------------------------------------------------------------------------------------
void MainFrame::DrawFramework( )
{
	// 画面のクリア
	float ClearColor[ 4 ] = { 0.0f, 0.0f, 0.2f, 1.0f }; // red, green, blue, alpha
	D3DDEVICES->pImmediateContext->ClearRenderTargetView( D3DDEVICES->s_pRenderTargetView, ClearColor );
	// 深度ステンシルバッファのクリア
	D3DDEVICES->pImmediateContext->ClearDepthStencilView( D3DDEVICES->s_pDepthStencilView, D3D11_CLEAR_DEPTH, 1.0f, 0 );


	//	TODO :	追加の描画処理は以下
	DXTKCONTROLLER->DrawDefaultSpriteBegin( );
	pTestScene->Draw( );
	DXTKCONTROLLER->DrawSpriteEnd( );
	//	TODO :	追加の描画処理は以上


	// バックバッファとフロントバッファを入れ替える（画面のリフレッシュレートに合わせる）
	D3DDEVICES->s_pSwapChain->Present( 0, 0 );
}