#ifndef _FRAMEWORK_DEVICECONTROLLER_INCLUDED_
#define _FRAMEWORK_DEVICECONTROLLER_INCLUDED_
#include "../Common/FrameworkCommon.h"

#define DEVICECONTROLLER	( Framework::DeviceController::Instance( ) )

namespace Framework
{
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