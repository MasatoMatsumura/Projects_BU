//======================================================================
//	@headerfile	ClientWindowController.h
//	@brief		クライアントウィンドウの制御クラス
//	@author		MasatoMatsumura
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
//	TODO :	追加のインクルードファイルは以下に記述
//----------------------------------------------------------------------
#include "../Common/FrameworkCommon.h"

//======================================================================
//	TODO :	追加のマクロの定義は以下に記述
//----------------------------------------------------------------------
//■インスタンス呼び出しの為の省略マクロ
#define CLIENTWINDOWCONTROLLER	( Framework::ClientWindowController::Instance( ) )

namespace Framework
{
	//==================================================================
	//	@class	ClientWindowController	"ClientWindowController.h"
	//	@brief	クライアントウィンドウの制御クラス
	//==================================================================
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
			//==========================================================
			//	TODO :	追加のメソッドは以下に記述
			//==========================================================
			//■ウィンドウの作成
			ATOM RegisterClass( );
			//■ウィンドウの初期化
			int InitializeWindow( );
			//■ウィンドウプロシージャ
			static LRESULT CALLBACK WindowProcedure( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam );
	};
};

#endif