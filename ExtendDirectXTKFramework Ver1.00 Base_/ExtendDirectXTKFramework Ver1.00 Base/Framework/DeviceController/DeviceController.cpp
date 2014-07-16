#include "DeviceController.h"

using namespace std;
using namespace Framework;

DeviceController::DeviceController( )
{
}

DeviceController::~DeviceController( )
{
}

HRESULT DeviceController::InitializeDevice( )
{
	HRESULT hr = S_OK;

#if 0
	// ウインドウのクライアント領域のサイズを取得
	RECT rc;
	GetClientRect( g_hWnd, &rc );
	UINT width = rc.right - rc.left;
	UINT height = rc.bottom - rc.top;
#endif

	UINT createDeviceFlags = 0;
#ifdef _DEBUG
	createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

	D3D_DRIVER_TYPE driverTypes[ ] =
	{
		D3D_DRIVER_TYPE_HARDWARE,
		D3D_DRIVER_TYPE_WARP,
		D3D_DRIVER_TYPE_REFERENCE,
	};
	UINT numDriverTypes = ARRAYSIZE( driverTypes );

	D3D_FEATURE_LEVEL featureLevels[ ] =
	{
		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_10_1,
		D3D_FEATURE_LEVEL_10_0,
	};
	UINT numFeatureLevels = ARRAYSIZE( featureLevels );

	// DirectX11のデバイスを作成
	for( UINT driverTypeIndex = 0; driverTypeIndex < numDriverTypes; driverTypeIndex++ )
	{
		D3DDEVICES->s_driverType = driverTypes[ driverTypeIndex ];
		hr = D3D11CreateDevice( NULL, D3DDEVICES->s_driverType, NULL, createDeviceFlags, featureLevels, numFeatureLevels,
			D3D11_SDK_VERSION, &D3DDEVICES->pd3dDevice, &D3DDEVICES->s_featureLevel, &D3DDEVICES->pImmediateContext );
		if( SUCCEEDED( hr ) )
			break;
	}

	// 使用可能なマルチサンプルを取得（サンプルのクォリティは2までに制限してあります）
	for( UINT i = 1; i <= 2; i++ ) {
		UINT Quality;
		if( SUCCEEDED( D3DDEVICES->pd3dDevice->CheckMultisampleQualityLevels( BACKBUFFER_FORMAT, i, &Quality ) ) ) {
			if( Quality > 0 ) {
				DXGI_SAMPLE_DESC Desc = { i, Quality - 1 };
				D3DDEVICES->s_SampleDesc = Desc;
			}
		}
	}

	// インターフェイス取得
	hr = D3DDEVICES->pd3dDevice->QueryInterface( __uuidof( IDXGIDevice1 ), (LPVOID*)&D3DDEVICES->s_pDXGIDevice );
	if( FAILED( hr ) ) {
		return hr;
	}
	// アダプター取得
	hr = D3DDEVICES->s_pDXGIDevice->GetAdapter( &D3DDEVICES->s_pDXGIAdapter );
	if( FAILED( hr ) ) {
		return hr;
	}
	// ファクトリー取得
	hr = D3DDEVICES->s_pDXGIAdapter->GetParent( __uuidof( IDXGIFactory ), (LPVOID*)&D3DDEVICES->s_pDXGIFactory );
	if( FAILED( hr ) ) {
		return hr;
	}

	// スワップチェインの作成
	DXGI_SWAP_CHAIN_DESC sd;
	ZeroMemory( &sd, sizeof( sd ) );
	sd.BufferCount = 1;

	sd.BufferDesc.Width = WINAPIDATA->CLIENT_WIDTH;
	sd.BufferDesc.Height = WINAPIDATA->CLIENT_HEIGHT;
	sd.BufferDesc.Format = BACKBUFFER_FORMAT;
	sd.BufferDesc.RefreshRate.Numerator = 60;
	sd.BufferDesc.RefreshRate.Denominator = 1;
	sd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	sd.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;

	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.OutputWindow = WINAPIDATA->hWnd;
	sd.SampleDesc = D3DDEVICES->s_SampleDesc;
	sd.Windowed = TRUE;
	sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;	// <-- フルスクリーン時画面解像度を切り替える

	hr = D3DDEVICES->s_pDXGIFactory->CreateSwapChain( D3DDEVICES->pd3dDevice, &sd, &D3DDEVICES->s_pSwapChain );
	if( FAILED( hr ) ) {
		return hr;
	}

	// バックバッファの作成
	hr = this->CreateBackBuffer( );
	if( FAILED( hr ) )
		return hr;

	// ビューポートの設定
	D3D11_VIEWPORT vp;
	vp.Width = (FLOAT)WINAPIDATA->CLIENT_WIDTH;
	vp.Height = (FLOAT)WINAPIDATA->CLIENT_HEIGHT;
	vp.MinDepth = 0.0f;
	vp.MaxDepth = 1.0f;
	vp.TopLeftX = 0;
	vp.TopLeftY = 0;
	D3DDEVICES->pImmediateContext->RSSetViewports( 1, &vp );

	return S_OK;
}

BOOL DeviceController::CreateBackBuffer( )
{
	HRESULT hr;

	// レンダーターゲットビューの作成
	ID3D11Texture2D* pBackBuffer = NULL;
	hr = D3DDEVICES->s_pSwapChain->GetBuffer( 0, __uuidof( ID3D11Texture2D ), (LPVOID*)&pBackBuffer );
	if( FAILED( hr ) )
		return hr;

	hr = D3DDEVICES->pd3dDevice->CreateRenderTargetView( pBackBuffer, NULL, &D3DDEVICES->s_pRenderTargetView );
	pBackBuffer->Release( );
	if( FAILED( hr ) )
		return hr;

	// 深度ステンシル用テクスチャの作成
	D3D11_TEXTURE2D_DESC descDepth;
	ZeroMemory( &descDepth, sizeof( descDepth ) );
	descDepth.Width = WINAPIDATA->CLIENT_WIDTH;
	descDepth.Height = WINAPIDATA->CLIENT_HEIGHT;
	descDepth.MipLevels = 1;
	descDepth.ArraySize = 1;
	descDepth.Format = DEPTHBUFFER_FORMAT;
	descDepth.SampleDesc = D3DDEVICES->s_SampleDesc;
	descDepth.Usage = D3D11_USAGE_DEFAULT;
	descDepth.BindFlags = D3D11_BIND_DEPTH_STENCIL;
	descDepth.CPUAccessFlags = 0;
	descDepth.MiscFlags = 0;
	hr = D3DDEVICES->pd3dDevice->CreateTexture2D( &descDepth, NULL, &D3DDEVICES->s_pDepthStencil );
	if( FAILED( hr ) )
		return hr;

	// 深度ステンシルビューの作成
	D3D11_DEPTH_STENCIL_VIEW_DESC descDSV;
	ZeroMemory( &descDSV, sizeof( descDSV ) );
	descDSV.Format = descDepth.Format;
	if( D3DDEVICES->s_SampleDesc.Count == 1 )
	{
		descDSV.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
	}
	else
	{
		descDSV.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2DMS;
	}
	descDSV.Texture2D.MipSlice = 0;
	hr = D3DDEVICES->pd3dDevice->CreateDepthStencilView( D3DDEVICES->s_pDepthStencil, &descDSV, &D3DDEVICES->s_pDepthStencilView );
	if( FAILED( hr ) )
		return hr;

	// レンダーターゲットセット
	D3DDEVICES->pImmediateContext->OMSetRenderTargets( 1, &D3DDEVICES->s_pRenderTargetView, D3DDEVICES->s_pDepthStencilView );

	return hr;
}

void DeviceController::ResizeBackBuffer( )
{
	if( ! D3DDEVICES->pImmediateContext ) return;

	D3DDEVICES->pImmediateContext->OMSetRenderTargets( 0, 0, 0 );
	if( D3DDEVICES->s_pDepthStencil )
	{
		D3DDEVICES->s_pDepthStencil->Release( );
		D3DDEVICES->s_pDepthStencil = nullptr;
	}
	if( D3DDEVICES->s_pDepthStencilView )
	{
		D3DDEVICES->s_pDepthStencilView->Release( );
		D3DDEVICES->s_pDepthStencilView = nullptr;
	}
	if( D3DDEVICES->s_pRenderTargetView )
	{
		D3DDEVICES->s_pRenderTargetView->Release( );
		D3DDEVICES->s_pRenderTargetView = nullptr;
	}
	D3DDEVICES->s_pSwapChain->ResizeBuffers( 1, WINAPIDATA->nClientWidth, WINAPIDATA->nClientHeight, BACKBUFFER_FORMAT, DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH );
	this->CreateBackBuffer( );
}