//======================================================================
//	@headerfile	MainFrame.h
//	@brief		�t���[�����[�N�̖{�̃N���X
//	@author		Masato Matsumura
//
//	@version	1.00
//	@since		FrameworkVer1.00( 2014/07/10 )
//	@date		2014/07/10
//======================================================================
//	@brief	�C���N���[�h�K�[�h
//----------------------------------------------------------------------
#ifndef _FRAMEWORK_MAINFRAME_INCLUDED_
#define _FRAMEWORK_MAINFRAME_INCLUDED_

//======================================================================
//	TODO :	�ǉ��̃C���N���[�h�t�@�C���͈ȉ��ɋL�q
//----------------------------------------------------------------------
//���t���[�����[�N�̋��ʃf�[�^
#include "../Common/FrameworkCommon.h"
//���N���C�A���g�E�B���h�E�̐���N���X��`
#include "../ClientWindowController/ClientWindowController.h"
//���f�o�C�X�̐���N���X��`
#include "../DeviceController/DeviceController.h"
//��DirectXTK�̐���N���X��`
#include "../DirectXTKController/DirectXTKController.h"

//======================================================================
//	TODO :	�ǉ��̃}�N���͈ȉ��ɋL�q
//----------------------------------------------------------------------
#define FRAMEWORK	( Framework::MainFrame::Instance( ) )

namespace Framework
{
	//==================================================================
	//	@class	MainFrame	"MainFrame.h"
	//	@brief	�t���[�����[�N�̖{�̃N���X
	//==================================================================
	class MainFrame : public DesignPattern::Singleton<MainFrame>
	{
		//���V���O���g����`
		friend class DesignPattern::Singleton<MainFrame>;
		private:
			//���R���X�g���N�^
			explicit MainFrame( );
		public:
			//���f�X�g���N�^
			~MainFrame( );

		//���N���X��`
		private:
			bool FLG_Execute;

		public:
			//���t���[�����[�N�̏�����
			void InitializeFramework( );
			//���Q�[���̏�����
			void InitializeGame( );
			//���t���[�����[�N�̎��s
			bool ExecuteFramework( );
			//���t���[�����[�N�̃A�b�v�f�[�g
			void UpdateFramework( );
			//���t���[�����[�N�̕`��
			void DrawFramework( );
	};
};

#endif