#ifndef _EXTENDLIBRARY_EXTENDTEXTURE_INCLUDED_
#define _EXTENDLIBRARY_EXTENDTEXTURE_INCLUDED_
#include "ExtendLibraryTypeDefines.h"

namespace ExtendLibrary
{
	namespace RenderingLibrary
	{
		class ExtendTexture
		{
			//■クラス定義
			private:
				int					m_TextureID;
				textureFileName_t	m_TextureFileName;

				DirectX::SimpleMath::Vector2	m_LocalPosition;
				DirectX::SimpleMath::Vector2	m_TextureSize;
				DirectX::SimpleMath::Vector2	m_CenterPosition;
				float	m_DEG_Rotation;

			public:
				//■コンストラクタ
			explicit ExtendTexture( textureFileName_t textureFileName = nullptr );
				//■デストラクタ
				~ExtendTexture( );

				void Initialize( );
				void Initialize( textureFileName_t textureFileName, DirectX::SimpleMath::Vector2 localPosition, DirectX::SimpleMath::Vector2 textureSize, DirectX::SimpleMath::Vector2 centerPosition, float DEG_Rotation );
				void Initialize( DirectX::SimpleMath::Vector2 localPosition, DirectX::SimpleMath::Vector2 textureSize, DirectX::SimpleMath::Vector2 centerPosition, float DEG_Rotation );

				void SetLocalPosition( DirectX::SimpleMath::Vector2 newLocalPosition );
				void AddLocalPosition( DirectX::SimpleMath::Vector2 velocityAddLocalPosition );

				void Draw( DirectX::SimpleMath::Vector2 position );
		};
	};
};

#endif