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
		//���V���O���g����`
		friend class DesignPattern::Singleton<DirectXTKController>;
		private:
			explicit DirectXTKController( );
		public:
			~DirectXTKController( );

		//���N���X��`
		public:
			std::unique_ptr<DirectX::CommonStates>	g_pCommonStates;
			std::unique_ptr<DirectX::SpriteBatch>	g_pSpriteBatch;

			//��DirectXTK���W���[���̏�����
			void InitializeDirectXTK( );
	};
}

#endif