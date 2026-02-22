#pragma once
#include <iostream>
#include <algorithm>
#include "Vector2D.h"


namespace Maths { //Vct correspond à vecteur 

	template <typename T>
	class Vct3D {
	private:
		T x = 0;
		T y = 0;
		T z = 0;

		static_assert(std::is_arithmetic_v<T>);

	public:
		//Contructeur de classe
		Vct3D(T x , T y , T z) : x(x),y(y),z(z) {}
		Vct3D() : x(0), y(0), z(0) {}
		~Vct3D() {}

		//Getter X
		T GetX() const { return x; }

		//Getter Y
		T GetY() const { return y; }

		//Getter Z
		T GetZ() const { return z; }

		//Setteur X
		T SetX(T xi) { return x = xi; }

		//Setteur Y
		T SetY(T yi) { return y = yi; }

		//Setteur Z
		T SetZ(T zi) { return z = zi; }

		// Setteur Vect

		void SetVector3D(T x, T y,T z);
		

		//Méthode

		//change la position en bas
		void down();


		void back();


		void foward();

		//change la position en haut
		void up();

		//change la position à gauche
		void left();

		//change la position à droite
		void right();

		//change la position en  1 1
		void one();

		//change la pos à moins l'infini
		void nega_tiveInfinity();

		//change la pos à plus l'infini
		void positiveInfinity();

		//change la pos à 0 0
		void zero();

		//magnitude vecteur
		T magnitude() const;

		//sqrt de la magnitude
		T sqrMagnitude() const;

		//normalized = vecteur divisé par sa magnitude en modifiant le vecteur d'origine
		void normalized();

		//Normalized = vecteur divisé par sa magnitude sans modifier le vecteur d'origine
		Vct3D<T> Normalized() const;

		bool Equal(const Vct3D<T>& other) const;

		//Permet de changer la valeur  index
		void thisInt(T i, int index);

		//Equals compare deux vecteurs et verifie s'ils sont égaux
		bool operator==(const Vct3D<T>& other) const;


		// Transforme en string le vecteur
		void toString() const;

		//Calcule l'angle entre deux vecteurs en degrés
		T Angle(const Vct3D<T>& other) const;
		
		//limite la longueur du vecteur à maxLength
		Vct3D<T> ClampMagnitude(const Vct3D<T>& ,T maxLength);


		//Calcule la distance entre deux vecteurs
		T Distance(const Vct3D<T>& other) const;

		//Calcule le produit scalaire entre deux vecteurs
		T Dot(const Vct3D<T>& other) const;

		//Interpole linéairement entre deux vecteurs en fonction de t avec une limite entre 0 et 1
		Vct3D<T> LerpClamp(const Vct3D<T>& target, T t) const;


		//Interpole linéairement entre deux vecteurs en fonction de t sans limite
		Vct3D<T> LerpUnClamp(const Vct3D<T>& target, T t) const;


		//renvoie le vecteur maximum entre deux vecteurs
		Vct3D<T> Max(const Vct3D<T>& other) const;


		//renvoie le vecteur minimum entre deux vecteurs
		Vct3D<T> Min(const Vct3D<T>& other) const;

		//Déplace un vecteur vers une cible
		Vct3D<T> MoveTowards(Vct3D<T> target, T maxDistanceDelta) const;

		//Renvoie le vecteur réfléchi par rapport à un vecteur normalisé
		Vct3D<T> Reflect(const Vct3D<T>& vct_normaliser) const;

		//Multiplie chaque composante du vecteur par l'autre vecteur sans modifier le vecteur d'origine
		Vct3D<T> Scale(const Vct3D<T>& other) const;

		//Calcule l'angle signé entre deux vecteurs en degrés , c'est à dire en tenant compte du sens
		T SignedAngle(Vct3D<T>& other) const;

		void OrthoNormalise(Vct3D<T>& b, Vct3D<T>& c);

		Vct3D<T> Projet(const Vct3D<T>& onto) const;

		Vct3D<T> Projet_Plan(const Vct3D<T>& planeNormal) const;

		/*MathsVct2D::Vct2D Transfo2D(const Vct3D<T>& vct_transfo) const;*/

		Vct3D<T> Cross(const Maths::Vct3D<T>& a, const Maths::Vct3D<T>& b);

		Vct3D<T> AddVector(const Vct3D<T>& a,const Vct3D<T>& b);

		// multiplication par un scalaire
		Vct3D<T> operator*(T scal) const {
			return Vct3D<T>(x * scal, y * scal, z * scal);
		}


		// Addition de vecteurs
		Vct3D<T> operator+(const Vct3D<T>& other) const {
			return Vct3D<T>(x + other.x, y + other.y, z + other.z);
		}

		// Soustraction de vecteurs
		Vct3D<T> operator-(const Vct3D<T>& other) const {
			return Vct3D<T>(x - other.x, y - other.y, z - other.z);
		}

		// Division par un scalaire
		Vct3D<T> operator/(T scal) const {
			if (scal != 0) {
				return Vct3D<T>(x / scal, y / scal, z / scal);
			}
			else {
				throw std::runtime_error("division par 0");
				
			}
		}

		//affiche la position x et y
		T& operator[](int index) {
			switch (index)
			{
			case 0:
				return x;

			case 1: 
				return y;

			case 2:
				return z;

			default:
				throw std::runtime_error("index ivalide") ;
			}
		}
	};
};
#include "Vector3D.inl"
