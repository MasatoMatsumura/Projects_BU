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
//	@brief	�C���N���[�h�t�@�C���͈ȍ~�ɋL�q
//----------------------------------------------------------------------
#include "Singleton.h"



namespace Game
{
	namespace Config
	{
//======================================================================
//	@namespace	Game::Config::ProgramConfig
//	@brief		�v���O�����S�̂̐ݒ肪�L�q����Ă��閼�O���
//======================================================================
		namespace ProgramConfig
		{
			//==========================================================
			//	@namespace	Game::Config::ProgramConfig::ClientWindow
			//	@brief		�N���C�A���g�E�B���h�E�Ɋւ���ݒ肪�L�q����Ă��閼�O���
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