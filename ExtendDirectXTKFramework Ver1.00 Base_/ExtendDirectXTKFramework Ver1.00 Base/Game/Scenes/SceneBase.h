#ifndef _GAME_SCENEBASE_INCLUDED_
#define _GAME_SCENEBASE_INCLUDED_
#include "GameTypeDefines.h"
#include "Singleton.h"

namespace Game
{
	namespace Utilities
	{
		class SceneBase
		{
			//■クラス定義
			private:
				Config::TypeDefines::sceneID_t		m_SceneID;
				Config::TypeDefines::attribute_t	m_Attribute;

			public:
				explicit SceneBase( ){ };
				virtual ~SceneBase( ){ };

				virtual void Initialize( ) = 0;
				virtual void Update( bool& FLG_Execute ) = 0;
				virtual void Draw( ) = 0;
		};
	};
};

#endif