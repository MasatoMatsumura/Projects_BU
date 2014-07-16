//======================================================================
//	@headerfile	DeviceController.h
//	@brief		各種デバイスの制御クラス
//	@author		Masato Matsumura
//
//	@version	1.00
//	@since		FrameworkVer1.00( 2014/07/10 )
//	@date		2014/07/10
//======================================================================
//	@brief	インクルードガード
//----------------------------------------------------------------------
#ifndef _FRAMEWORK_DEVICECONTROLLER_INCLUDED_
#define _FRAMEWORK_DEVICECONTROLLER_INCLUDED_

//======================================================================
//	@brief	インクルードファイルは以降に記述
//----------------------------------------------------------------------
#include "../Common/FrameworkCommon.h"

//======================================================================
//	@brief	マクロ定義は以降に記述
//----------------------------------------------------------------------
//■取得子の省略マクロ
//▼各種デバイスの制御クラス【Framework::DeviceController】
#define DEVICECONTROLLER	( Framework::DeviceController::Instance( ) )



namespace Framework
{
//======================================================================
//	@classs	Framework::DeviceController "DeviceController.h"
//	@brief	各種デバイスの制御クラス
//======================================================================
	class DeviceController : public DesignPattern::Singleton<DeviceController>
	{
		//■シングルトン定義
		friend DesignPattern::Singleton<DeviceController>;
		private:
			//■コンストラクタ
			explicit DeviceController( );
		public:
			//■デストラクタ
			~DeviceController( );

		//■クラス定義
		private:
			//■フォーマット定義
			//▼バックバッファのフォーマット
			static const DXGI_FORMAT BACKBUFFER_FORMAT = DXGI_FORMAT_R8G8B8A8_UNORM;
			//▼深度バッファのフォーマット
			static const DXGI_FORMAT DEPTHBUFFER_FORMAT = DXGI_FORMAT_D24_UNORM_S8_UINT;
			
		public:
			//■デバイスの初期化
			HRESULT InitializeDevice( );
			//■バックバッファの作成
			BOOL CreateBackBuffer( );
			//■バックバッファのリサイズ処理
			void ResizeBackBuffer( );
	};
};

#endif