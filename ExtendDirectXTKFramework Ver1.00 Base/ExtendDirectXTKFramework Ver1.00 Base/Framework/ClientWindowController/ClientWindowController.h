//======================================================================
//	@headerfile	ClientWindowController.h
//	@brief		�N���C�A���g�E�B���h�E�̐���N���X
//	@author		Masato Matsumura
//
//	@version	1.00
//	@since		FrameworkVer1.00( 2014/07/10 )
//	@date		2014/07/10
//======================================================================
//	@brief	�C���N���[�h�K�[�h
//----------------------------------------------------------------------
#ifndef _FRAMEWORK_CLIENTWINDOWCONTROLLER_INCLUDED_
#define _FRAMEWORK_CLIENTWINDOWCONTROLLER_INCLUDED_

//======================================================================
//	@brief	�C���N���[�h�t�@�C���͈ȍ~�ɋL�q
//----------------------------------------------------------------------
#include "../Common/FrameworkCommon.h"

//======================================================================
//	@brief	�}�N����`�͈ȍ~�ɋL�q
//----------------------------------------------------------------------
//���擾�q�̏ȗ��}�N��
//���N���C�A���g�E�B���h�E����N���X�yFramework::ClientWindowController�z
#define CLIENTWINDOWCONTROLLER	( Framework::ClientWindowController::Instance( ) )



namespace Framework
{
//======================================================================
//	@class	Framework::ClientWindowController	"ClientWindowController.h"
//	@brief	�N���C�A���g�E�B���h�E�̐���N���X
//======================================================================
	class ClientWindowController : public DesignPattern::Singleton<ClientWindowController>
	{
		//���V���O���g����`
		friend class DesignPattern::Singleton<ClientWindowController>;
		private:
			//���R���X�g���N�^
			explicit ClientWindowController( );
		public:
			//���f�X�g���N�^
			~ClientWindowController( );

		//���N���X��`
		public:
			//���E�B���h�E�̍쐬
			ATOM RegisterClass( );
			//���E�B���h�E�̏�����
			int InitializeWindow( );
			//���E�B���h�E�v���V�[�W��
			static LRESULT CALLBACK WindowProcedure( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam );
	};
};

#endif