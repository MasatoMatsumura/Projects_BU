//======================================================================
//	@headerfile	DirectXTKController.h
//	@brief		DirectXTK�̐���N���X
//	@author		Masato Matsumura
//
//	@version	1.00
//	@since		FrameworkVer1.00( 2014/07/10 )
//	@date		2014/07/10
//======================================================================
//	@brief	�C���N���[�h�K�[�h
//----------------------------------------------------------------------
#ifndef _FRAMEWORK_DIRECTXTKCONTROLLER_INCLUDED_
#define _FRAMEWORK_DIRECTXTKCONTROLLER_INCLUDED_

//======================================================================
//	@brief	�C���N���[�h�t�@�C���͈ȍ~�ɋL�q
//----------------------------------------------------------------------
#include "../Common/FrameworkCommon.h"

//======================================================================
//	@brief	�}�N���̒�`�͈ȍ~�ɋL�q
//----------------------------------------------------------------------
//���擾�q�̏ȗ��}�N��
//��DirectXTK�̐���N���X�yFramework::DirectXTKController�z
#define DXTKCONTROLLER	( Framework::DirectXTKController::Instance( ) )

namespace Framework
{
//======================================================================
//	@classs	Framework::DirectXTKController "DirectXTKController.h"
//	@brief	DirectXTK�̐���N���X
//======================================================================
	class DirectXTKController : public DesignPattern::Singleton<DirectXTKController>
	{
		//���V���O���g����`
		friend class DesignPattern::Singleton<DirectXTKController>;
		private:
			explicit DirectXTKController( );
		public:
			~DirectXTKController( );

		//���N���X��`
		public:
			//��DirectXTK���W���[���̏�����
			void InitializeDirectXTK( );
	};
};

#endif