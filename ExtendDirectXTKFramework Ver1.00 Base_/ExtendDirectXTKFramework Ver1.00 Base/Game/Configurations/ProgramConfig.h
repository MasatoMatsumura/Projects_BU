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
//	TODO :	追加のインクルードファイルは以下に記述
//----------------------------------------------------------------------
#include "Singleton.h"

namespace Game
{
	namespace Config
	{
		namespace ProgramConfig
		{
			//==========================================================
			//	@Brief	クライアントウィンドウに関する設定
			//	TODO :	クライアントウィンドウに関する設定は以下に記述
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