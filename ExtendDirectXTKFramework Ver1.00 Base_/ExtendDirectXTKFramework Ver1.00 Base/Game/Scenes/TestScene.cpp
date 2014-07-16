#include "Framework\Common\FrameworkCommon.h"
#include "TestScene.h"

using namespace DirectX::SimpleMath;
using namespace Game;
using namespace Game::Scenes;
using namespace ExtendLibrary;
using namespace ExtendLibrary::RenderingLibrary;

TestScene::TestScene( )
{
	this->m_pBackGround.reset( new ExtendTexture( TEXTUREFILENAME ) );
}

TestScene::~TestScene( )
{
	
}

void TestScene::Initialize( )
{
	this->m_pBackGround->Initialize( Vector2( WINAPIDATA->nWidth, WINAPIDATA->nHeight ), Vector2( WINAPIDATA->nWidth, WINAPIDATA->nHeight ), Vector2( WINAPIDATA->nWidth / 2.0f, WINAPIDATA->nHeight / 2.0f ), 0.0f );
}

void TestScene::Update( bool& FLG_Execute )
{
	static int frameCount = 0;

	if( frameCount >= 3000 )
	{
		FLG_Execute = false;
	}

	frameCount++;
}

void TestScene::Draw( )
{
	this->m_pBackGround->Draw( Vector2( 0.0f, 0.0f ) );
}