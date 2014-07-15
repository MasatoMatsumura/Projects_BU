#ifndef _GAME_TESTSCENE_INCLUDED_
#define _GAME_TESTSCENE_INCLUDED_
#include "Singleton.h"
#include "SceneBase.h"
#include "Libraries\RenderingLibrary\ExtendTexture\ExtendTexture.h"

namespace Game
{
	namespace Scenes
	{
		static const wchar_t*	TEXTUREFILENAME = L"./Resources/Graphics/test.jpg";
		class TestScene : public Utilities::SceneBase
		{
			//Å°ÉNÉâÉXíËã`
			private:
				std::unique_ptr<ExtendLibrary::RenderingLibrary::ExtendTexture>	m_pBackGround;

			public:
				explicit TestScene( );
				~TestScene( );

				void Initialize( ) override;
				void Update( bool& FLG_Execute ) override;
				void Draw( ) override;
		};
	};
};

#endif