#include "MainFrame.h"

using namespace std;
using namespace Framework;

MainFrame::MainFrame( )
{
}

MainFrame::~MainFrame( )
{
}

void MainFrame::InitializeFramework( )
{
	//���N���C�A���g�E�B���h�E�̍쐬�E�o�^
	CLIENTWINDOWCONTROLLER->InitializeWindow( );

	//���f�o�C�X�̏�����
	DEVICECONTROLLER->InitializeDevice( );

	//��DirectXTK���W���[���̏�����
	DXTKCONTROLLER->InitializeDirectXTK( );
}