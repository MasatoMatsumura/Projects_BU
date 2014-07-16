//======================================================================
//	@headerfile	DeviceController.h
//	@brief		�e��f�o�C�X�̐���N���X
//	@author		Masato Matsumura
//
//	@version	1.00
//	@since		FrameworkVer1.00( 2014/07/10 )
//	@date		2014/07/10
//======================================================================
//	@brief	�C���N���[�h�K�[�h
//----------------------------------------------------------------------
#ifndef _FRAMEWORK_DEVICECONTROLLER_INCLUDED_
#define _FRAMEWORK_DEVICECONTROLLER_INCLUDED_

//======================================================================
//	@brief	�C���N���[�h�t�@�C���͈ȍ~�ɋL�q
//----------------------------------------------------------------------
#include "../Common/FrameworkCommon.h"

//======================================================================
//	@brief	�}�N����`�͈ȍ~�ɋL�q
//----------------------------------------------------------------------
//���擾�q�̏ȗ��}�N��
//���e��f�o�C�X�̐���N���X�yFramework::DeviceController�z
#define DEVICECONTROLLER	( Framework::DeviceController::Instance( ) )



namespace Framework
{
//======================================================================
//	@classs	Framework::DeviceController "DeviceController.h"
//	@brief	�e��f�o�C�X�̐���N���X
//======================================================================
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
			//���t�H�[�}�b�g��`
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