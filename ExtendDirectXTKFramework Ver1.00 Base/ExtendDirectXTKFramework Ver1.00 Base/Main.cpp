//===============================================================================================
//	@File		Main.cpp
//	@Brief		
//===============================================================================================
//	TODO :	�ǉ��̃C���N���[�h�t�@�C���͈ȉ��ɋL�q
//===============================================================================================
//	@brief	
//-----------------------------------------------------------------------------------------------
#include "Framework\MainFrame\MainFrame.h"
#include "Game\Scenes\TestScene.h"

//===============================================================================================
//	TODO :	�ǉ���using�f�B���N�e�B�u�͈ȉ��ɋL�q
//===============================================================================================
//	@namespace	Framework
//	@brief		ExtendDirectXTK�t���[�����[�N�̃V�X�e�����i�[����Ă�����
//-----------------------------------------------------------------------------------------------
using namespace std;
using namespace Framework;
using namespace Game;

//===============================================================================================
//	TODO :	�ǉ��̃O���[�o���ϐ��͈ȉ��ɋL�q
//===============================================================================================
//��
static unique_ptr<Scenes::TestScene>	pTestScene;

//===============================================================================================
//	TODO :	�v���O�����̎����͈ȉ��ɋL�q
//===============================================================================================

//===============================================================================================
//	@fn		int WINAPI wWinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow )
//	@brief	{	�G���g���[�|�C���g
//				�v���O�����̃��C���������s��	}
//	@return	{	int�^�i�L���X�g�j
//				WindowsOS����̃V�X�e�����b�Z�[�W�i WindowsMessage �j	}
//-----------------------------------------------------------------------------------------------
int WINAPI wWinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow )
{
	UNREFERENCED_PARAMETER( hPrevInstance );
	UNREFERENCED_PARAMETER( lpCmdLine );

	//���t���[�����[�N�̏�����
	FRAMEWORK->InitializeFramework( );

	//���Q�[���̏�����
	FRAMEWORK->InitializeGame( );

	//��Windows�̃��b�Z�[�W���󂯎�郁�b�Z���W���[���쐬
	MSG messenger = { 0 };

	//��Windows����I�����b�Z�[�W���󂯎��܂Ń��[�v����
	while( messenger.message != WM_QUIT )
	{
		if( PeekMessage( &messenger, nullptr, 0, 0, PM_REMOVE ) )
		{
			TranslateMessage( &messenger );
			DispatchMessage( &messenger );
		}
		else
		{
			//���t���[�����[�N�̎��s
			if( !FRAMEWORK->ExecuteFramework( ) ) break;
		}
	}

	//��WindowsMessage��ԋp
	return (int)messenger.wParam;
}

//===============================================================================================
//	@class	MainFrame	"MainFrame.h"
//	@fn		void InitializeGame( )
//	@brief	{	�C�j�V�����C�U
//				�Q�[���v���O�����̏������������s��	}
//	@return	{	�Ȃ�	}
//-----------------------------------------------------------------------------------------------
void MainFrame::InitializeGame( )
{
	pTestScene.reset( new Scenes::TestScene( ) );
	pTestScene->Initialize( );
}

//===============================================================================================
//	@class	MainFrame	"MainFrame.h"
//	@fn		ExecuteFramework( )
//	@brief	{	�t���[�����[�N�S�̂̍X�V�������s��	}
//	@return	{	bool�^�̃����o�ϐ�
//				�v���O�������I�����邩�ǂ����̃t���O��Ԃ�	
//-----------------------------------------------------------------------------------------------
bool MainFrame::ExecuteFramework( )
{
	//���X�V����
	this->UpdateFramework( );

	//���`�揈��
	this->DrawFramework( );

	//���l�̕ԋp
	return this->FLG_Execute;
}

//===============================================================================================
//	@class	MainFrame	"MainFrame.h"
//	@fn		void UpdateFramework( )
//	@brief	{	�A�b�v�f�[�^
//				�Q�[���{�̂̍X�V�������s��	}
//	@return	{	�Ȃ�	}
//-----------------------------------------------------------------------------------------------
void MainFrame::UpdateFramework( )
{
	pTestScene->Update( this->FLG_Execute );
}

//===============================================================================================
//	@class	MainFrame	"MainFrame.h"
//	@fn		DrawFramework( )
//	@brief	{	�����_���[
//				�v���O�����S�̂̕`�揈�����s��	}
//	@return	{	�Ȃ�	}
//-----------------------------------------------------------------------------------------------
void MainFrame::DrawFramework( )
{
	// ��ʂ̃N���A
	float ClearColor[ 4 ] = { 0.0f, 0.0f, 0.2f, 1.0f }; // red, green, blue, alpha
	D3DDEVICES->pImmediateContext->ClearRenderTargetView( D3DDEVICES->s_pRenderTargetView, ClearColor );
	// �[�x�X�e���V���o�b�t�@�̃N���A
	D3DDEVICES->pImmediateContext->ClearDepthStencilView( D3DDEVICES->s_pDepthStencilView, D3D11_CLEAR_DEPTH, 1.0f, 0 );


	//	TODO :	�ǉ��̕`�揈���͈ȉ�
	DXTKCONTROLLER->DrawDefaultSpriteBegin( );
	pTestScene->Draw( );
	DXTKCONTROLLER->DrawSpriteEnd( );
	//	TODO :	�ǉ��̕`�揈���͈ȏ�


	// �o�b�N�o�b�t�@�ƃt�����g�o�b�t�@�����ւ���i��ʂ̃��t���b�V�����[�g�ɍ��킹��j
	D3DDEVICES->s_pSwapChain->Present( 0, 0 );
}