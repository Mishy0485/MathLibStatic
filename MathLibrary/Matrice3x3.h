#pragma once
#include <iostream>

namespace Maths {
	template<typename T>
	class Matrix3 {
	protected:


		T tabMat[3][3]; // tableau qui me sert a stocker ma matrice 3x3

		T tabCofacteur[3][3]; // tableau qui stock le cofacteur de la matrice

		T det; // stock la valeur du determinant

		bool isIdentityBool = false;

	public : 
		/*
		template<typename T>
		T feur(T a, T b); // quand on l'appelle dans le main alors feur<Tflo>(1.0f, 2.0f)
		*/

		Matrix3(); // constructeur par defaut de la matrice 3x3 (matrice identité)

		void create(T u, T d, T t, T q, T c, T si, T se, T h, T n); // créé une matrice / modifie celle de base

		//Static Properties

		//void identity();
		//void zero();

		// Properties

		void decomposeProjection(); // affiche la matrice dans la console (rien a voir avec la fonction de base)
		T determinant(); // effectue le calcul du determinant
		void inverse(); // effectue le calcul de la matrice inverse
		void isIdentity(); // verifie si la matrice est identitaire
		//void lossyScale();
		//void rotation();
		void transpose(); // affiche la transposé dans la console

		// Public Methods

		void getColumn(int column); // return la colonne voulue
		void getPosition(int row, int column); // return la position d'une valeur de la matrice (pas compris quand je l'avais fait)
		void getRow(int row); // return la ligne voulue
		//void multiplyPoint();
		//void multiplyPoint3x4();
		//void multiplyVector();
		void setColumn(int columnNumber, int number1, int number2, int number3); // modifie la colonne voulue
		void setRow(int rowNumber, int number1, int number2, int number3); // modifie la ligne voulue
		//void setTRS();
		//void toString();
		//void transformPlane();
		//void validTRS();

		// Static Methods

		//void Frustum();
		//void inverse3DAffine();
		//void lookAt();
		void ortho(T left, T right, T bottom, T top, T zNear, T zFar); // crée une matrice de projection orthographique
		//void perspective();
		//void rotate();
		//void scale();
		//void translate();
		//void TRS();
	};
}

#include "Matrice3x3.inl"