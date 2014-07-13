//===============================================================================================
//	@file		ClientWindowController.cpp
//	@brief		�N���C�A���g�E�B���h�E�̐���N���X�����R�[�h
//	@author		MasatoMatsumura
//
//	@version	1.00
//	@since		FrameworkVer1.00( 2014/07/10 )
//	@date		2014/07/10
//===============================================================================================
//	TODO :	�ǉ��̃C���N���[�h�t�@�C���͈ȉ��ɋL�q
//-----------------------------------------------------------------------------------------------
//��ClientWindowController�̒�`�ǂݍ���
#include "ClientWindowController.h"
//��DeviceController�̒�`�ǂݍ���
#include "../DeviceController/DeviceController.h"

//===============================================================================================
//	TODO :	�ǉ���using�f�B���N�e�B�u�͈ȉ��ɋL�q
//-----------------------------------------------------------------------------------------------
using namespace Framework;

//===============================================================================================
//	TODO :	ClientWindowController�N���X�̎����͈ȉ��ɋL�q
//===============================================================================================

//===============================================================================================
//	@class	ClientWindowController	"ClientWindowController.h"
//	@fn		ClientWindowController
//	@Brief	�N���C�A���g�E�B���h�E�̐���N���X�̏��������s��
//-----------------------------------------------------------------------------------------------
ClientWindowController::ClientWindowController( )
{
}

//===============================================================================================
//	@class	ClientWindowController	"ClientWindowController.h"
//	@fn		~ClientWindowController
//	@Brief	{	�f�X�g���N�^
//				�N���C�A���g�E�B���h�E�̐���N���X�̏I���������s��	}
//-----------------------------------------------------------------------------------------------
ClientWindowController::~ClientWindowController( )
{
}

//===============================================================================================
//	@class	ClientWindowController	"ClientWindowController.h"
//	@fn		InitializeWindow
//	@Brief	{	�C�j�V�����C�U
//				�E�B���h�E�N���X��ݒ�A�o�^���ăN���C�A���g�E�B���h�E���쐬����	}
//	@return	������\��S_OK�萔��Ԃ�
//-----------------------------------------------------------------------------------------------
int ClientWindowController::InitializeWindow( )
{
	//���E�C���h�E�N���X�̓o�^
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof( WNDCLASSEX );
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = this->WindowProcedure;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = WINAPIDATA->hInstance;
	wcex.hIcon = LoadIcon( WINAPIDATA->hInstance, (LPCTSTR)NULL );
	wcex.hCursor = LoadCursor( NULL, IDC_ARROW );
	wcex.hbrBackground = (HBRUSH)( COLOR_WINDOW + 1 );
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = WINAPIDATA->szWindowClass.c_str( );

	wcex.hIconSm = LoadIcon( wcex.hInstance, (LPCTSTR)NULL );
	if( !RegisterClassEx( &wcex ) )
		return E_FAIL;

	// �E�C���h�E�̍쐬
	RECT rc = { 0, 0, WINAPIDATA->CLIENT_WIDTH, WINAPIDATA->CLIENT_HEIGHT };
	AdjustWindowRect( &rc, WS_OVERLAPPEDWINDOW, FALSE );
	WINAPIDATA->nWidth = rc.right - rc.left;
	WINAPIDATA->nHeight = rc.bottom - rc.top;
	WINAPIDATA->hWnd = CreateWindow( WINAPIDATA->szWindowClass.c_str( ), WINAPIDATA->szTitle.c_str( ),
		WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX & ~WS_THICKFRAME,	// �ő剻�{�^�������ƃE�C���h�E�T�C�Y��ύX�ł��Ȃ��悤�ɐݒ�
		CW_USEDEFAULT, CW_USEDEFAULT, WINAPIDATA->nWidth, WINAPIDATA->nHeight, NULL, NULL, WINAPIDATA->hInstance,
		NULL );
	if( !WINAPIDATA->hWnd )
		return E_FAIL;

	ShowWindow( WINAPIDATA->hWnd, WINAPIDATA->nCmdShow );

	return S_OK;
}

//===============================================================================================
//	@class	ClientWindowController	"ClientWindowController.h"
//	@fn		LRESULT CALLBACK WindowProcedure( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
//	@Brief	{	�E�B���h�E�v���V�[�W��
//				WindowsOS�̃V�X�e�����b�Z�[�W�i WindowsMessage �j����K�����������s��	}
//	@return	{	LRESULT�^
//				�ʏ펞��0��ԋp���A��O����DefWindowProc( )�֐��̖߂�l��Ԃ�	}
//-----------------------------------------------------------------------------------------------
LRESULT CALLBACK ClientWindowController::WindowProcedure( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
{
	switch( message )
	{
		case WM_KEYDOWN:				// �L�[��������
			if( wParam == VK_ESCAPE )
				// [ESC]�L�[
				PostQuitMessage( 0 );			// �A�v���P�[�V�����̏I��

		case WM_DESTROY:
			PostQuitMessage( 0 );
			break;

		case WM_SIZE:
			DEVICECONTROLLER->ResizeBackBuffer( );
			break;

		default:
			return DefWindowProc( hWnd, message, wParam, lParam );
	}

	return 0;
}