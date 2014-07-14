#ifndef _EXTENDLIBRARY_TEXTUREMANAGER_INCLUDED_
#define _EXTENDLIBRARY_TEXTUREMANAGER_INCLUDED_
#include <unordered_map>
#include <vector>
#include "Singleton.h"
#include "ExtendLibraryTypeDefines.h"

#define TEXTUREMANAGER		( ExtendLibrary::DataManagingLibrary::TextureManager::Instance( ) )

namespace ExtendLibrary
{
	namespace DataManagingLibrary
	{
		class TextureManager : public DesignPattern::Singleton<TextureManager>
		{
			//■シングルトン定義
			friend class DesignPattern::Singleton<TextureManager>;
			private:
				explicit TextureManager( );
			public:
				~TextureManager( );

			//■クラス定義
			private:
				int m_NUM_LoadedTextures;
				std::unordered_map<textureFileName_t, std::unique_ptr<ID3D11ShaderResourceView*>>	m_TextureMap;
				std::vector<textureFileName_t>	m_TextureIDLink;
			public:
				textureID_t Load_Texture( textureFileName_t fileName );
				ID3D11ShaderResourceView* Get_Texture( textureID_t getTextureID );
		};
	};
};

#endif