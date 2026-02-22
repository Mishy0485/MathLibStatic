#pragma once
#include <iostream>
#include "Vector3D.h"
#include "Quaternions.h"
#include <array>
#include <sstream>
#include <iomanip>

namespace Maths {
	template<typename T>
	class Matrix4 {
	protected:

		std::array<T, 16> tabMat; // array qui me permet de stocker ma matrice facilement

		Maths::Vct3D<T> vector3D; 

		T det; // resultat du determinant

		float deg2rad = 3.14159265f / 180.f; // valeur qui permet de convertir les degrés en radiant pour les calculs a base de rotation

	public:

		Matrix4(); // constructeur par défaut matrice 4x4
		Matrix4(T u, T d, T t, T q, T c, T si, T se, T h, T n, T di, T on, T dou, T tre, T qua, T qui, T sei); // constructeur qui permet de créer la matrice qu'on veut

#pragma region Static Properties

		static Matrix4 identity4x4(); // return la matrice identité
		static Matrix4 zero4x4(); // return la matrice 0

#pragma endregion Static Properties

#pragma region Properties

		//void decomposeProjection4x4(); // impossible sans une classe Frustrum

		void printMatrix4x4() const; // affiche directement la matrice dans la console

		T determinant4x4() const; // effectue le calcul du determinant de la matrice dans le tabMat

		std::array<T,16> inverse4x4(); // effectue le calcul de l'inverse de la matrice dans le tabMat

		bool isIdentity4x4(); // return true si la matrice est identitaire

		T& at(int r, int c); // petite fonction qui permet de raccourcir l'appelle de l'array

		Maths::Vct3D<T> lossyScale4x4(); // chat gpt m'a expliqué j'avoue pas avoir tout compris

		Matrix4<T> rotation4x4(T angleX, T angleY, T angleZ); // Tente d'obtenir une rotation à partir de cette matrice

		std::array<T, 16> transpose4x4(Maths::Matrix4<T> feur); // donne la transposé de la matrice entrée en parametre

#pragma endregion Properties

#pragma region Publics Methods

		void getColumn4x4(T column); // recup une colonne

		Maths::Vct3D<T> getPosition4x4() const; // on recup les infos du vecteur

		void getRow4x4(T row); // recup une ligne

		Maths::Vct3D<T> multiplyPoint4x4(Maths::Vct3D<T>& vector); // Multiplie un point par la matrice

		Maths::Vct3D<T> multiplyPoint3x4_4x4(const Vct3D<T>& vector); // Variante pour une multiplication d’un vecteur 3D par une matrice 4x4

		Maths::Vct3D<T> multiplyVector4x4(Maths::Vct3D<T>& vector); // Multiplie un vecteur directionnel par la matrice 

		Matrix4<T> multiplyMatrix4x4(Matrix4<T>& A, Matrix4<T>& B); // Multiplie deux matrices 4x4 entre elles et retourne le résultat

		void setColumn4x4(T columnNumber, T number1, T number2, T number3, T number4); // Définit une colonne spécifique de la matrice

		void setRow4x4(T rowNumber, T number1, T number2, T number3, T number4); // Définit une ligne spécifique de la matrice

		static Matrix4<T> setTRS4x4(const Vct3D<T>& translation, const Vct3D<T>& rotationEulerDeg, const Vct3D<T>& scale); // Crée une matrice de transformation à partir de la translation, la rotation (Euler angles) et l'échelle

		std::string toString4x4(); // Affiche la matrice sous forme de chaîne de caractères

		//void transformPlane4x4(); pas possible rip

		bool validTRS4x4(); // Vérifie la validité d'une transformation TRS (Translation, Rotation, Scale)

#pragma endregion Publics Methods

#pragma region Static Methods

		//void Frustum4x4();
		//void inverse3DAffine4x4();

		
		static Matrix4 lookAt4x4(Maths::Vct3D<T>& from, Maths::Vct3D<T>& to, Maths::Vct3D<T>& up); // Crée une matrice de vue à partir d’une position, d’une cible et d’un vecteur up

		static Matrix4<T> ortho4x4(T left, T right, T bottom, T top, T zNear, T zFar); // Crée une matrice de projection orthographique

		static Matrix4<T> perspective4x4(T fovY, T aspect, T near, T far); // Crée une matrice de projection en perspective

		static Matrix4<T> rotate4x4(const Maths::Quat<T>& q); // Crée une matrice de rotation à partir d’un quaternion

		static Matrix4<T> scale4x4(T sx, T sy, T sz); // Crée une matrice d’échelle à partir de trois valeurs

		static Matrix4<T> scale4x4(const Maths::Vct3D<T>& s); // Crée une matrice d’échelle à partir d’un vecteur

		static Matrix4<T> translate4x4(T tx, T ty, T tz); // Crée une matrice de translation à partir de trois valeurs

		static Matrix4<T> translate4x4(const Maths::Vct3D<T>& t); // Crée une matrice de translation à partir d’un vecteur

		static Matrix4<T> TRS4x4(const Maths::Vct3D<T>& position, const Maths::Vct3D<T>& rotationEuler, const Maths::Vct3D<T>& scale); // Crée une matrice complète TRS à partir de position, rotation (Euler), et échelle

#pragma endregion Static Methods

		Matrix4<T> operator*(const Matrix4<T>& other) const; // Surcharge de l'opérateur * pour la multiplication entre matrices
	};
};

#include "Matrice4x4.inl"