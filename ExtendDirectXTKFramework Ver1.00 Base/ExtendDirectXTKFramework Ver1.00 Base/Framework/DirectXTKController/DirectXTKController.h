//======================================================================
//	@headerfile	DirectXTKController.h
//	@brief		DirectXTKの制御クラス
//	@author		Masato Matsumura
//
//	@version	1.00
//	@since		FrameworkVer1.00( 2014/07/10 )
//	@date		2014/07/10
//======================================================================
//	@brief	インクルードガード
//----------------------------------------------------------------------
#ifndef _FRAMEWORK_DIRECTXTKCONTROLLER_INCLUDED_
#define _FRAMEWORK_DIRECTXTKCONTROLLER_INCLUDED_

//======================================================================
//	@brief	インクルードファイルは以降に記述
//----------------------------------------------------------------------
#include "../Common/FrameworkCommon.h"

//======================================================================
//	@brief	マクロの定義は以降に記述
//----------------------------------------------------------------------
//■取得子の省略マクロ
//▼DirectXTKの制御クラス【Framework::DirectXTKController】
#define DXTKCONTROLLER	( Framework::DirectXTKController::Instance( ) )

namespace Framework
{
//======================================================================
//	@classs	Framework::DirectXTKController "DirectXTKController.h"
//	@brief	DirectXTKの制御クラス
//======================================================================
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
			//■DirectXTKモジュールの初期化
			void InitializeDirectXTK( );
	};
};

#endif