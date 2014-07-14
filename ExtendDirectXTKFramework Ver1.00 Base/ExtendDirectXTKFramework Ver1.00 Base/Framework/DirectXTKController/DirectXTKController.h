#ifndef _FRAMEWORK_DIRECTXTKCONTROLLER_INCLUDED_
#define _FRAMEWORK_DIRECTXTKCONTROLLER_INCLUDED_
#include <CommonStates.h>
#include <SpriteBatch.h>
#include "../Common/FrameworkCommon.h"

#define DXTKCONTROLLER	( Framework::DirectXTKController::Instance( ) )

namespace Framework
{
	class DirectXTKController : public DesignPattern::Singleton<DirectXTKController>
	{
		//■シングルトン定義
		friend class DesignPattern::Singleton<DirectXTKController>;
		private:
			explicit DirectXTKController( );
		public:
			~DirectXTKController( );

		//■クラス定義
		public:
			std::unique_ptr<DirectX::CommonStates>	g_pCommonStates;
			std::unique_ptr<DirectX::SpriteBatch>	g_pSpriteBatch;

			//■DirectXTKモジュールの初期化
			void InitializeDirectXTK( );
	};
}

#endif