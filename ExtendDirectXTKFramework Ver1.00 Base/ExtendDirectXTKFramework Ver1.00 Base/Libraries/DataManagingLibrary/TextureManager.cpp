#include "TextureManager.h"
#include "Framework\Common\FrameworkCommon.h"

using namespace std;
using namespace ExtendLibrary;
using namespace ExtendLibrary::DataManagingLibrary;

TextureManager::TextureManager( ) : m_NUM_LoadedTextures( 0 )
{

}

TextureManager::~TextureManager( )
{

}

textureID_t TextureManager::Load_Texture( textureFileName_t fileName )
{
	if( fileName == nullptr ) return 0;

	auto newEntryID = ++this->m_NUM_LoadedTextures;

	if( this->m_TextureMap.find( fileName ) == this->m_TextureMap.end( ) )
	{
		this->m_TextureMap[ fileName ] = std::make_unique<ID3D11ShaderResourceView*>( );
		DirectX::CreateWICTextureFromFile( D3DDEVICES->pd3dDevice, D3DDEVICES->pImmediateContext, fileName, nullptr, reinterpret_cast<ID3D11ShaderResourceView**>( this->m_TextureMap[ fileName ].get( ) ) );

		if( this->m_TextureMap[ fileName ].get( ) == nullptr )
		{
			this->m_TextureMap.erase( fileName );
			this->m_NUM_LoadedTextures--;
			return 0;
		}
	}

	this->m_TextureIDLink.push_back( fileName );

	return newEntryID;
}

ID3D11ShaderResourceView* TextureManager::Get_Texture( textureID_t getTextureID )
{
	if( getTextureID == 0 ) return nullptr;

	return reinterpret_cast<ID3D11ShaderResourceView*>( this->m_TextureMap[ this->m_TextureIDLink[ getTextureID ] ].get( ) );
}