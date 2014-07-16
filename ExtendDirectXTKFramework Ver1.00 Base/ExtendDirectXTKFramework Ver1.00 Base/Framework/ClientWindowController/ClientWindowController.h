//======================================================================
//	@headerfile	ClientWindowController.h
//	@brief		クライアントウィンドウの制御クラス
//	@author		Masato Matsumura
//
//	@version	1.00
//	@since		FrameworkVer1.00( 2014/07/10 )
//	@date		2014/07/10
//======================================================================
//	@brief	インクルードガード
//----------------------------------------------------------------------
#ifndef _FRAMEWORK_CLIENTWINDOWCONTROLLER_INCLUDED_
#define _FRAMEWORK_CLIENTWINDOWCONTROLLER_INCLUDED_

//======================================================================
//	@brief	インクルードファイルは以降に記述
//----------------------------------------------------------------------
#include "../Common/FrameworkCommon.h"

//======================================================================
//	@brief	マクロ定義は以降に記述
//----------------------------------------------------------------------
//■取得子の省略マクロ
//▼クライアントウィンドウ制御クラス【Framework::ClientWindowController】
#define CLIENTWINDOWCONTROLLER	( Framework::ClientWindowController::Instance( ) )



namespace Framework
{
//======================================================================
//	@class	Framework::ClientWindowController	"ClientWindowController.h"
//	@brief	クライアントウィンドウの制御クラス
//======================================================================
	class ClientWindowController : public DesignPattern::Singleton<ClientWindowController>
	{
		//■シングルトン定義
		friend class DesignPattern::Singleton<ClientWindowController>;
		private:
			//■コンストラクタ
			explicit ClientWindowController( );
		public:
			//■デストラクタ
			~ClientWindowController( );

		//■クラス定義
		public:
			//■ウィンドウの作成
			ATOM RegisterClass( );
			//■ウィンドウの初期化
			int InitializeWindow( );
			//■ウィンドウプロシージャ
			static LRESULT CALLBACK WindowProcedure( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam );
	};
};

#endif