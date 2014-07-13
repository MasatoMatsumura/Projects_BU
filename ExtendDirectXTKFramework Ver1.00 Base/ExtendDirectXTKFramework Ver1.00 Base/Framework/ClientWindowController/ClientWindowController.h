//======================================================================
//	@headerfile	ClientWindowController.h
//	@brief		�N���C�A���g�E�B���h�E�̐���N���X
//	@author		MasatoMatsumura
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
//	TODO :	�ǉ��̃C���N���[�h�t�@�C���͈ȉ��ɋL�q
//----------------------------------------------------------------------
#include "../Common/FrameworkCommon.h"

//======================================================================
//	TODO :	�ǉ��̃}�N���̒�`�͈ȉ��ɋL�q
//----------------------------------------------------------------------
//���C���X�^���X�Ăяo���ׂ̈̏ȗ��}�N��
#define CLIENTWINDOWCONTROLLER	( Framework::ClientWindowController::Instance( ) )

namespace Framework
{
	//==================================================================
	//	@class	ClientWindowController	"ClientWindowController.h"
	//	@brief	�N���C�A���g�E�B���h�E�̐���N���X
	//==================================================================
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
			//==========================================================
			//	TODO :	�ǉ��̃��\�b�h�͈ȉ��ɋL�q
			//==========================================================
			//���E�B���h�E�̍쐬
			ATOM RegisterClass( );
			//���E�B���h�E�̏�����
			int InitializeWindow( );
			//���E�B���h�E�v���V�[�W��
			static LRESULT CALLBACK WindowProcedure( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam );
	};
};

#endif