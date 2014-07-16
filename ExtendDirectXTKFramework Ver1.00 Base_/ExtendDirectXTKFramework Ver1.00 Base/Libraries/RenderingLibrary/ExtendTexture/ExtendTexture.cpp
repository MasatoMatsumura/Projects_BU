#include "Framework\DirectXTKController\DirectXTKController.h"
#include "Libraries\DataManagingLibrary\TextureManager.h"
#include "ExtendTexture.h"

using namespace DirectX::SimpleMath;
using namespace ExtendLibrary;
using namespace ExtendLibrary::RenderingLibrary;

ExtendTexture::ExtendTexture( textureFileName_t textureFileName )
	: m_TextureID( 0 )
	, m_TextureFileName( textureFileName )
	, m_LocalPosition( Vector2( 0.0f, 0.0f ) ), m_TextureSize( Vector2( 0.0f, 0.0f ) ), m_CenterPosition( Vector2( 0.0f, 0.0f ) )
	, m_DEG_Rotation( 0.0f )
{
}

ExtendTexture::~ExtendTexture( )
{
	
}

void ExtendTexture::Initialize( )
{
	if( ( this->m_TextureID == 0 ) && ( this->m_TextureFileName != nullptr ) )
	{
		this->m_TextureID = TEXTUREMANAGER->Load_Texture( this->m_TextureFileName );
	}
	this->m_LocalPosition.x = 0.0f;
	this->m_LocalPosition.y = 0.0f;
	this->m_CenterPosition.x = this->m_TextureSize.x / 2.0f;
	this->m_CenterPosition.y = this->m_TextureSize.y / 2.0f;
	this->m_DEG_Rotation = 0.0f;
}

void ExtendTexture::Initialize( textureFileName_t textureFileName, Vector2 localPosition, Vector2 textureSize, Vector2 centerPosition, float DEG_Rotation )
{
	this->m_TextureFileName = textureFileName;
	this->Initialize( localPosition, textureSize, centerPosition, DEG_Rotation );
}

void ExtendTexture::Initialize( Vector2 localPosition, Vector2 textureSize, Vector2 centerPosition, float DEG_Rotation )
{
	if( ( this->m_TextureID == 0 ) && ( this->m_TextureFileName != nullptr ) )
	{
		this->m_TextureID = TEXTUREMANAGER->Load_Texture( this->m_TextureFileName );
	}
	this->m_LocalPosition = localPosition;
	this->m_TextureSize = textureSize;
	this->m_CenterPosition = centerPosition;
	this->m_DEG_Rotation = DEG_Rotation;
}

void ExtendTexture::SetLocalPosition( Vector2 newLocalPosition )
{
	this->m_LocalPosition = newLocalPosition;
}

void ExtendTexture::AddLocalPosition( Vector2 velocityAddLocalPosition )
{
	this->m_LocalPosition += velocityAddLocalPosition;
}

void ExtendTexture::Draw( Vector2 position )
{
	DXTKCONTROLLER->g_pSpriteBatch->Draw( TEXTUREMANAGER->Get_Texture( this->m_TextureID ), position, DirectX::Colors::White );
}