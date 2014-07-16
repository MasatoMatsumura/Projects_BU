#include "FrameworkCommon.h"
#include "ProgramConfig.h"

using namespace std;
using namespace Framework;

CommonDatas::WinAPIData::WinAPIData( )
{
	//■クライアントウィンドウの各種情報を取得する
	STARTUPINFO si;
	si.dwFlags = 0;
	GetStartupInfo( &si );
	//▼ウィンドウの表示方法を取得する
	this->nCmdShow = si.dwFlags & STARTF_USESHOWWINDOW ? si.wShowWindow : SW_SHOWDEFAULT;
	//▼アプリケーションのインスタンスハンドルを取得する
	this->hInstance = GetModuleHandle( NULL );
	//▼ウィンドウモード
	this->bFullScreen = false;

	this->nScreenWidth = ::GetSystemMetrics( SM_CXSCREEN );
	this->nScreenHeight = ::GetSystemMetrics( SM_CYSCREEN );

	this->szWindowClass = L"Window01";
	this->szTitle = Game::Config::ProgramConfig::ClientWindow::WINDOWTITLE;

	this->szIcon = Game::Config::ProgramConfig::ClientWindow::WINDOWICON;
	this->szMiniIcon = Game::Config::ProgramConfig::ClientWindow::WINDOWMINIICON;
}

CommonDatas::WinAPIData::~WinAPIData( )
{
}

CommonDatas::Devices::Devices( )
{
	this->s_driverType = D3D_DRIVER_TYPE_NULL;
	this->s_featureLevel = D3D_FEATURE_LEVEL_11_0;
	this->s_pSwapChain = nullptr;
	this->s_pRenderTargetView = nullptr;
	this->s_pDepthStencil = nullptr;
	this->s_pDepthStencilView = nullptr;
	this->s_pDXGIDevice = nullptr;
	this->s_pDXGIAdapter = nullptr;
	this->s_pDXGIFactory = nullptr;
	this->s_SampleDesc = { 1, 0 };
}

CommonDatas::Devices::~Devices( )
{
	//■デバイスの解放
	if( this->pd3dDevice != nullptr )
	{
		this->pd3dDevice->Release( );
		this->pd3dDevice = nullptr;
	}
	if( this->pImmediateContext != nullptr )
	{
		this->pImmediateContext->ClearState( );
		this->pImmediateContext->Release( );
		this->pImmediateContext = nullptr;
	}

	if( this->s_pDXGIFactory != nullptr )
	{
		this->s_pDXGIFactory->Release( );
		this->s_pDXGIFactory = nullptr;
	}
	if( this->s_pDXGIAdapter != nullptr )
	{
		this->s_pDXGIAdapter->Release( );
		this->s_pDXGIAdapter = nullptr;
	}
	if( this->s_pDXGIDevice != nullptr )
	{
		this->s_pDXGIDevice->Release( );
		this->s_pDXGIDevice = nullptr;
	}
	if( this->s_pDepthStencil != nullptr )
	{
		this->s_pDepthStencil->Release( );
		this->s_pDepthStencil = nullptr;
	}
	if( this->s_pDepthStencilView != nullptr )
	{
		this->s_pDepthStencilView->Release( );
		this->s_pDepthStencilView = nullptr;
	}
	if( this->s_pRenderTargetView != nullptr )
	{
		this->s_pRenderTargetView->Release( );
		this->s_pRenderTargetView = nullptr;
	}
	if( this->s_pSwapChain != nullptr )
	{
		this->s_pSwapChain->Release( );
		this->s_pSwapChain = nullptr;
	}

}