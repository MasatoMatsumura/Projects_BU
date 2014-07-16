//======================================================================
//	@headerfile	MainFrame.h
//	@brief		フレームワークの本体クラス
//	@author		Masato Matsumura
//
//	@version	1.00
//	@since		FrameworkVer1.00( 2014/07/10 )
//	@date		2014/07/10
//======================================================================
//	@brief	インクルードガード
//----------------------------------------------------------------------
#ifndef _FRAMEWORK_MAINFRAME_INCLUDED_
#define _FRAMEWORK_MAINFRAME_INCLUDED_

//======================================================================
//	@brief	インクルードファイルは以降に記述
//----------------------------------------------------------------------
//■フレームワークの共通データ
#include "../Common/FrameworkCommon.h"
//■クライアントウィンドウの制御クラス定義
#include "../ClientWindowController/ClientWindowController.h"
//■デバイスの制御クラス定義
#include "../DeviceController/DeviceController.h"
//■DirectXTKの制御クラス定義
#include "../DirectXTKController/DirectXTKController.h"

//======================================================================
//	@brief	マクロ定義は以降に記述
//----------------------------------------------------------------------
//■取得子の省略マクロ
//▼フレームワークの本体【Framework::MainFrame】
#define FRAMEWORK	( Framework::MainFrame::Instance( ) )



namespace Framework
{
//======================================================================
//	@class	Framework::MainFrame "MainFrame.h"
//	@brief	フレームワークの本体クラス
//======================================================================
	class MainFrame : public DesignPattern::Singleton<MainFrame>
	{
		//■シングルトン定義
		friend class DesignPattern::Singleton<MainFrame>;
		private:
			//■コンストラクタ
			explicit MainFrame( );
		public:
			//■デストラクタ
			~MainFrame( );

		//■クラス定義
		private:
			//■変数定義
			//▼フレームワークの更新を続行するためのフラグ
			bool FLG_Execute;

		public:
			//■フレームワークの初期化
			void InitializeFramework( );
			//■ゲームの初期化
			void InitializeGame( );
			//■フレームワークの実行
			bool ExecuteFramework( );
			//■フレームワークのアップデート
			void UpdateFramework( );
			//■フレームワークの描画
			void DrawFramework( );
	};
};

#endif