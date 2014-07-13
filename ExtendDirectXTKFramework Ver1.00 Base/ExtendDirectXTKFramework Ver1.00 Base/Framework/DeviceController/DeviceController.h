#ifndef _FRAMEWORK_DEVICECONTROLLER_INCLUDED_
#define _FRAMEWORK_DEVICECONTROLLER_INCLUDED_
#include "../Common/FrameworkCommon.h"

#define DEVICECONTROLLER	( Framework::DeviceController::Instance( ) )

namespace Framework
{
	class DeviceController : public DesignPattern::Singleton<DeviceController>
	{
		//���V���O���g����`
		friend DesignPattern::Singleton<DeviceController>;
		private:
			//���R���X�g���N�^
			explicit DeviceController( );
		public:
			//���f�X�g���N�^
			~DeviceController( );

		//���N���X��`
		private:
			//���o�b�N�o�b�t�@�̃t�H�[�}�b�g
			static const DXGI_FORMAT BACKBUFFER_FORMAT = DXGI_FORMAT_R8G8B8A8_UNORM;
			//���[�x�o�b�t�@�̃t�H�[�}�b�g
			static const DXGI_FORMAT DEPTHBUFFER_FORMAT = DXGI_FORMAT_D24_UNORM_S8_UINT;
			
		public:
			//���f�o�C�X�̏�����
			HRESULT InitializeDevice( );
			//���o�b�N�o�b�t�@�̍쐬
			BOOL CreateBackBuffer( );
			//���o�b�N�o�b�t�@�̃��T�C�Y����
			void ResizeBackBuffer( );
	};
};

#endif