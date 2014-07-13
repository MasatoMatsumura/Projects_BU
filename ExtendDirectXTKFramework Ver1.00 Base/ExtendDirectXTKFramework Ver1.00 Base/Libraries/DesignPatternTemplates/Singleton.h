#ifndef _DESIGNPATTERN_SINGLETON_INCLUDED_
#define _DESIGNPATTERN_SINGLETON_INCLUDED_
#include <memory>

namespace DesignPattern
{
	template<class instanceType>
	class Singleton
	{
		protected:
			//���R���X�g���N�^
			Singleton( ){ };
			//�����z�f�X�g���N�^
			virtual ~Singleton( ){ };

		private:
			//���R�s�[�R���X�g���N�^
			Singleton( std::unique_ptr<instanceType> instance ){ };
			void operator= ( std::unique_ptr<instanceType> instance ){ };

		public:
			//���C���X�^���X�̎擾�q
			static inline std::unique_ptr<instanceType>& Instance( )
			{
				static std::unique_ptr<instanceType> instance( new instanceType( ) );
				return instance;
			};
	};
};

#endif