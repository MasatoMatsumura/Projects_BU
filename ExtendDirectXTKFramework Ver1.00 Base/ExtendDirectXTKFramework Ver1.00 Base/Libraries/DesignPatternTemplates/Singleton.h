//======================================================================
//	@headerfile	Singleton.h
//	@brief		シングルトンパターンのテンプレートクラス
//	@author		Masato Matsumura
//
//	@version	1.00
//	@since		FrameworkVer1.00( 2014/07/10 )
//	@date		2014/07/10
//======================================================================
//	@brief	インクルードガード
//----------------------------------------------------------------------
#ifndef _DESIGNPATTERN_SINGLETON_INCLUDED_
#define _DESIGNPATTERN_SINGLETON_INCLUDED_



namespace DesignPattern
{
//======================================================================
//	@class	DesignPattern::Singleton "Singleton.h"
//	@brief	{
//				シングルトンパターンのテンプレートクラス
//				使用する際は以下のようにクラスを定義
//					class Type : public DesignPattern::Singleton<Type>
//					[
//						friend class DesignPattern::Singleton<Type>;
//						private:
//							Type( );
//						public:
//							~Type( );
//					];
//			}
//======================================================================
	template<class instanceType> class Singleton
	{
		protected:
			//■コンストラクタ
			Singleton( ){ };
			//■仮想デストラクタ
			virtual ~Singleton( ){ };

		private:
			//■コピーコンストラクタ
			Singleton( std::unique_ptr<instanceType> instance ){ };
			void operator= ( std::unique_ptr<instanceType> instance ){ };

		public:
			//■インスタンスの取得子
			static inline std::unique_ptr<instanceType>& Instance( )
			{
				static std::unique_ptr<instanceType> instance( new instanceType( ) );
				return instance;
			};
	};
};

#endif