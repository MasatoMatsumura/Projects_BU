#ifndef _DESIGNPATTERN_SINGLETON_INCLUDED_
#define _DESIGNPATTERN_SINGLETON_INCLUDED_
#include <memory>

namespace DesignPattern
{
	template<class instanceType>
	class Singleton
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