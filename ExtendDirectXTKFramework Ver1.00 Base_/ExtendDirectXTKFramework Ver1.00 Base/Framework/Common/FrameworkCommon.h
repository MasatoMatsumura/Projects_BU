#ifndef _FRAMEWORK_FRAMEWORKCOMMON_INCLUDED_
#define _FRAMEWORK_FRAMEWORKCOMMON_INCLUDED_
//#include <memory>
//#include <tchar.h>
//#include <string>
//#include <windows.h>
//#include <d3d11.h>
#include "Singleton.h"

#define FRAMEWORKCOMMON		( Framework::CommonDatas::Instance( ) )
#define WINAPIDATA			( Framework::CommonDatas::WinAPIData::Instance( ) )
#define D3DDEVICES			( Framework::CommonDatas::Devices::Instance( ) )

namespace Framework
{
	class CommonDatas : public DesignPattern::Singleton<CommonDatas>
	{
		//■シングルトン定義
		friend class DesignPattern::Singleton<CommonDatas>;
		private:
			//■コンストラクタ
			explicit CommonDatas( );
		public:
			//■デストラクタ
			~CommonDatas( );

		//■クラス定義
		public:
			//■データクラス
			//▼WinAPI用グローバルデータ
			class WinAPIData : public DesignPattern::Singleton<WinAPIData>
			{
				//■シングルトン定義
				friend class DesignPattern::Singleton<WinAPIData>;
				private:
					//■コンストラクタ
					explicit WinAPIData( );

				public:
					//■デストラクタ
					~WinAPIData( );
					//■データ
					static const int CLIENT_WIDTH = 640;
					static const int CLIENT_HEIGHT = 480;

					HWND hWnd;					// ウィンドウハンドル
					HINSTANCE hInstance;			// インスタンスハンドル
					int nCmdShow;				// 表示状態
					std::wstring szWindowClass;	// メインウィンドウクラス名
					std::wstring szTitle;			// タイトルバーのテキスト
					std::wstring szIcon;			// アイコン
					std::wstring szMiniIcon;		// ミニアイコン
					int nScreenWidth;			// フルスクリーン幅
					int nScreenHeight;			// フルスクリーン高
					int nWidth;					// ウィンドウ幅
					int nHeight;					// ウィンドウ高
					int nClientWidth;			// デフォルトで指定されているウィンドウ幅
					int nClientHeight;			// デフォルトで指定されているウィンドウ高
					bool bFullScreen;			// フルスクリーンかどうか
			};
			//▼グローバルデバイス
			class Devices : public DesignPattern::Singleton<Devices>
			{
				//■シングルトン定義
				friend DesignPattern::Singleton<Devices>;
				private:
					explicit Devices( );

				//■クラス定義
				private:
				public:
					//■デストラクタ
					~Devices( );
					//■データ
					ID3D11Device*			pd3dDevice;
					ID3D11DeviceContext*	pImmediateContext;

					D3D_DRIVER_TYPE			s_driverType;
					D3D_FEATURE_LEVEL		s_featureLevel;
					IDXGISwapChain*			s_pSwapChain;
					ID3D11RenderTargetView*	s_pRenderTargetView;
					ID3D11Texture2D*		s_pDepthStencil;
					ID3D11DepthStencilView*	s_pDepthStencilView;
					IDXGIDevice1*			s_pDXGIDevice;
					IDXGIAdapter*			s_pDXGIAdapter;
					IDXGIFactory*			s_pDXGIFactory;
					DXGI_SAMPLE_DESC		s_SampleDesc;
			};
	};
};

#endif