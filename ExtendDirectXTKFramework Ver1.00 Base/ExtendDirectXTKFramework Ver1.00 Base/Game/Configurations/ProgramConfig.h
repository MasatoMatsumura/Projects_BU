//======================================================================
//	@headerfile	ProgramConfig.h
//	@Brief		プログラム全体に関する設定を行う
//	@Author		MasatoMatsumura
//
//	@Version	1.00
//	@Since		FrameworkVer1.00( 2014/07/10 )
//	@date		2014/07/10
//======================================================================
//	@brief	インクルードガード
//----------------------------------------------------------------------
#ifndef _GAME_PROGRAMCONFIG_INCLUDED_
#define _GAME_PROGRAMCONFIG_INCLUDED_

//======================================================================
//	@brief	インクルードファイルは以降に記述
//----------------------------------------------------------------------
#include "Singleton.h"



namespace Game
{
	namespace Config
	{
//======================================================================
//	@namespace	Game::Config::ProgramConfig
//	@brief		プログラム全体の設定が記述されている名前空間
//======================================================================
		namespace ProgramConfig
		{
			//==========================================================
			//	@namespace	Game::Config::ProgramConfig::ClientWindow
			//	@brief		クライアントウィンドウに関する設定が記述されている名前空間
			//==========================================================
			namespace ClientWindow
			{
				//■クライアントウィンドウのタイトルバーに表示するテキスト
				static const wchar_t* WINDOWTITLE = L"タイトルバー";
				//■プログラムのアイコン
				//　※使用しないのであれば無記入
				static const wchar_t* WINDOWICON = L"";
				static const wchar_t* WINDOWMINIICON = L"";
			};
		};
	};
};

#endif