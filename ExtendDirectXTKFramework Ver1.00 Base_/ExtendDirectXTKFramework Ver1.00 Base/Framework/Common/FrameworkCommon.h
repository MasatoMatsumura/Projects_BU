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
		//���V���O���g����`
		friend class DesignPattern::Singleton<CommonDatas>;
		private:
			//���R���X�g���N�^
			explicit CommonDatas( );
		public:
			//���f�X�g���N�^
			~CommonDatas( );

		//���N���X��`
		public:
			//���f�[�^�N���X
			//��WinAPI�p�O���[�o���f�[�^
			class WinAPIData : public DesignPattern::Singleton<WinAPIData>
			{
				//���V���O���g����`
				friend class DesignPattern::Singleton<WinAPIData>;
				private:
					//���R���X�g���N�^
					explicit WinAPIData( );

				public:
					//���f�X�g���N�^
					~WinAPIData( );
					//���f�[�^
					static const int CLIENT_WIDTH = 640;
					static const int CLIENT_HEIGHT = 480;

					HWND hWnd;					// �E�B���h�E�n���h��
					HINSTANCE hInstance;			// �C���X�^���X�n���h��
					int nCmdShow;				// �\�����
					std::wstring szWindowClass;	// ���C���E�B���h�E�N���X��
					std::wstring szTitle;			// �^�C�g���o�[�̃e�L�X�g
					std::wstring szIcon;			// �A�C�R��
					std::wstring szMiniIcon;		// �~�j�A�C�R��
					int nScreenWidth;			// �t���X�N���[����
					int nScreenHeight;			// �t���X�N���[����
					int nWidth;					// �E�B���h�E��
					int nHeight;					// �E�B���h�E��
					int nClientWidth;			// �f�t�H���g�Ŏw�肳��Ă���E�B���h�E��
					int nClientHeight;			// �f�t�H���g�Ŏw�肳��Ă���E�B���h�E��
					bool bFullScreen;			// �t���X�N���[�����ǂ���
			};
			//���O���[�o���f�o�C�X
			class Devices : public DesignPattern::Singleton<Devices>
			{
				//���V���O���g����`
				friend DesignPattern::Singleton<Devices>;
				private:
					explicit Devices( );

				//���N���X��`
				private:
				public:
					//���f�X�g���N�^
					~Devices( );
					//���f�[�^
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