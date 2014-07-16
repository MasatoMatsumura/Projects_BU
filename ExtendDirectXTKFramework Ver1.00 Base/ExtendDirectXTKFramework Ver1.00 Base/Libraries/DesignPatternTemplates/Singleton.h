//======================================================================
//	@headerfile	Singleton.h
//	@brief		�V���O���g���p�^�[���̃e���v���[�g�N���X
//	@author		Masato Matsumura
//
//	@version	1.00
//	@since		FrameworkVer1.00( 2014/07/10 )
//	@date		2014/07/10
//======================================================================
//	@brief	�C���N���[�h�K�[�h
//----------------------------------------------------------------------
#ifndef _DESIGNPATTERN_SINGLETON_INCLUDED_
#define _DESIGNPATTERN_SINGLETON_INCLUDED_



namespace DesignPattern
{
//======================================================================
//	@class	DesignPattern::Singleton "Singleton.h"
//	@brief	{
//				�V���O���g���p�^�[���̃e���v���[�g�N���X
//				�g�p����ۂ͈ȉ��̂悤�ɃN���X���`
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