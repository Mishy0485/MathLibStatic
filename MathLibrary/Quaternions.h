#pragma once
#include <numbers>
#include <cmath>
#include <type_traits>
#include <stdexcept>
#include <limits>
#include <algorithm>
#include "Vector3D.h"

namespace Maths {

	template <typename T>
	class Quat {


	private:

		T w;
		T x;
		T y;
		T z;

		static_assert(std::is_arithmetic_v<T>);

	protected:


	public:

		// Ajout Julia
		static constexpr T PI = static_cast<T>(3.14159265358979323846);


		//Constructeur/ Destructeur de classe
		Quat(T w, T x, T y, T z) : w(w), x(x), y(y), z(z) {}
		Quat() : w(1), x(0), y(0), z(0) {}

		~Quat() {}


		//Getter W
		T GetW() const { return w; }

		//Getter X
		T GetX() const { return x; }

		//Getter Y
		T GetY() const { return y; }

		//Getter Z
		T GetZ() const { return z; }

		//Setter W
		void SetW(T W) { w = W; }

		//Setter X
		void SetX(T X) { x = X; }

		//Setter Y
		void SetY(T Y) { y = Y; }

		//Setter Z
		void SetZ(T Z) { z = Z; }


		//M�thode Quat

		//Setter Quat
		void SetQuat(T w, T x, T y, T z) { SetW(w); SetX(x); SetY(y); SetZ(z); }

		//Convertit le quaternion en angles d�Euler
		void EuleurAngles(T& pitch, T& yaw, T& roll) const;

		// Retourne une version normalis�e 
		Maths::Quat<T> normalized() const;

		// Cr�e un quaternion qui repr�sente la rotation
		void setFromToRotation(const Quat<T>& to);

		// Cr�e un quaternion pour orienter un objet 
		void SetLookRotation(const Quat<T>& forward, const Quat<T>& up);

		//Convertit le quaternion en un angle et un axe de rotation
		void ToAngleAxis(T& angle, Quat<T>& axis) const;

		// Cr�e un quaternion � partir d�un angle et d�un axe de rotation
		void AngleAxis(T angle, const Quat<T>& axis);

		// D�finit le quaternion � partir d�un angle et des composantes de l'axe
		void Angle(T angle, T x, T y, T z);

		// Calcule le produit scalaire (dot product) entre deux quaternions
		T Dot(const Quat<T>& b);

		// Interpolation sph�rique entre deux quaternions
		Quat<T> Slerp(const Quat<T>& b, T t);
	
		// Interpolation lin�aire entre deux quaternions
		Maths::Quat <T> Lerp( const Quat<T>& b, T t);

		// Cr�e un quaternion qui fait la rotation de "from" vers "to"
		void FromToRotation(const Quat<T>& to);

		// Inverse le quaternion
		void Inverse();

		// Interpolation lin�aire non restreinte entre deux quaternions
		Maths::Quat<T> LerpUnclamped(const Quat<T>& b, T t);

		// Interpolation sph�rique non restreinte entre deux quaternions
		Quat<T> SlerpUnclamped(const Quat<T>& b, T t);

		// Cr�e un quaternion pour orienter un objet
		void LookRotation(const Quat<T>& forward, const Quat<T>& up);

		// Fait tourner le quaternion vers un autre quaternion avec une limite d'angle
		void RotateTowards(const Quat<T>& to, T maxDegreesDelta);

		//  Normalise ce quaternion pour qu�il ait une magnitude de 1
		void Normalize();

		//V�rifie si deux quaternions sont �gaux
		bool Equals(const Quat<T>& q) const;

		T Magnitude() const;

		Quat<T> Cross(const Quat<T>& b) const;


		Quat<T> operator*(const Quat<T>& q) const {
			return Quat<T>(
				w * q.w - x * q.x - y * q.y - z * q.z,
				w * q.x + x * q.w + y * q.z - z * q.y,
				w * q.y - x * q.z + y * q.w + z * q.x,
				w * q.z + x * q.y - y * q.x + z * q.w
			);
		}
		bool operator==(const Quat<T>& q) const {
			return w == q.w && x == q.x && y == q.y && z == q.z;
		}

		
	};


	// finir quaternions , faire tout les test unitaire et faire une documentation rapide


}
#include "Quaternions.inl"