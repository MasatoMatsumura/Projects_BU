//======================================================================
//	@headerfile	ProgramConfig.h
//	@Brief		�v���O�����S�̂Ɋւ���ݒ���s��
//	@Author		MasatoMatsumura
//
//	@Version	1.00
//	@Since		FrameworkVer1.00( 2014/07/10 )
//	@date		2014/07/10
//======================================================================
//	@brief	�C���N���[�h�K�[�h
//----------------------------------------------------------------------
#ifndef _GAME_PROGRAMCONFIG_INCLUDED_
#define _GAME_PROGRAMCONFIG_INCLUDED_

//======================================================================
//	TODO :	�ǉ��̃C���N���[�h�t�@�C���͈ȉ��ɋL�q
//----------------------------------------------------------------------
#include "Singleton.h"

namespace Game
{
	namespace Config
	{
		namespace ProgramConfig
		{
			//==========================================================
			//	@Brief	�N���C�A���g�E�B���h�E�Ɋւ���ݒ�
			//	TODO :	�N���C�A���g�E�B���h�E�Ɋւ���ݒ�͈ȉ��ɋL�q
			//==========================================================
			namespace ClientWindow
			{
				//���N���C�A���g�E�B���h�E�̃^�C�g���o�[�ɕ\������e�L�X�g
				static const wchar_t* WINDOWTITLE = L"�^�C�g���o�[";
				//���v���O�����̃A�C�R��
				//�@���g�p���Ȃ��̂ł���Ζ��L��
				static const wchar_t* WINDOWICON = L"";
				static const wchar_t* WINDOWMINIICON = L"";
			};
		};
	};
};

#endif