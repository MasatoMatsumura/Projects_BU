#ifndef _GAME_TESTSCENE_INCLUDED_
#define _GAME_TESTSCENE_INCLUDED_
#include "Singleton.h"
#include "SceneBase.h"

namespace Game
{
	namespace Scenes
	{
		class TestScene : public Utilities::SceneBase
		{
			//■クラス定義
			public:
				explicit TestScene( );
				~TestScene( );

				void Initialize( ) override;
				void Update( ) override;
				void Draw( ) override;
		};
	};
};

#endif