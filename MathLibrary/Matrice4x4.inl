#pragma once
#include "Matrice4x4.h"

template<typename T>
Maths::Matrix4<T>::Matrix4(T u, T d, T t, T q, T c, T si, T se, T h, T n, T di, T on, T dou, T tre, T qua, T qui, T sei)
{
	this->tabMat = { 
		u, d, t, q,
		c, si, se, h,
		n, di, on, dou,
		tre, qua, qui, sei
	};


	std::cout << "Matrice cree : " << std::endl << std::endl;

	printMatrix4x4();
}

template<typename T>
Maths::Matrix4<T>::Matrix4()
{
	tabMat.fill(static_cast<T>(0));
}

#pragma region Static Properties

template<typename T>
Maths::Matrix4<T> Maths::Matrix4<T>::identity4x4()
{
		Matrix4 matrix; 
		matrix.tabMat = { 
			1, 0, 0, 0,
			0, 1, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		};

		std::cout << "Matrice Identite : " << std::endl << std::endl;

		
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j)
				std::cout << matrix.tabMat[i * 4 + j] << " ";
			std::cout << std::endl;
		}

		std::cout << std::endl;

		return matrix;
}

template<typename T>
Maths::Matrix4<T> Maths::Matrix4<T>::zero4x4()
{
	Matrix4<T> matrix;
	matrix.tabMat = {
		0,0,0,0,
		0,0,0,0,
		0,0,0,0,
		0,0,0,0
	};

	std::cout << "Matrice zero : " << std::endl << std::endl;

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j)
			std::cout << matrix.tabMat[i * 4 + j] << " ";
		std::cout << std::endl;
	}

	std::cout << std::endl;

	return matrix;
}

#pragma endregion Static Properties
#pragma region Properties

template<typename T>
void Maths::Matrix4<T>::printMatrix4x4() const
{
	// Afficher la matrice
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j)
			std::cout << this->tabMat[i * 4 + j] << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}


template<typename T>
T Maths::Matrix4<T>::determinant4x4() const
{
	// det(A) = tabMat[0][0] * C1.1 - tabMat[0][1] * C1.2 + tabMat[0][2] * C1.3 - tabMat[0][3] * C1.4;

	// C1.1 = +1 * M1.1, C1.2 = -1 * M1.2...

	// M1.1 = determinant comme en 3x3

	// decomposition pour miuex comprendre car on dirait que c'est nimp mais nan ca va

	/* si tu prend un schema de matrice en
	* 
	a00 a01 a02 a03
	a10 a11 a12 a13
	a20 a21 a22 a23
	a30 a31 a32 a33
	*
	*/

	// this->tabMat[1 * 4 + 1] regarde juste le 1 dans 1 * 4 et le +1 ca fais a11 

	// si on prend this->tabMat[3 * 4 + 2] c'est le numero en a32 et si on prend this->tabMat[3 * 4 + 3] c'est le num en a33


	// logique en tableau que j'avais fais au début :
	/*
	tabDet[0][0] =
		tabMat[1][1] * ((tabMat[2][2] * tabMat[3][3]) - (tabMat[2][3] * tabMat[3][2]))
		- tabMat[1][2] * ((tabMat[2][1] * tabMat[3][3]) - (tabMat[2][3] * tabMat[3][1])) +
		tabMat[1][3] * ((tabMat[2][1] * tabMat[3][2]) - (tabMat[2][2] * tabMat[3][1]));

	tabDet[0][1] =
		tabMat[1][0] * ((tabMat[2][2] * tabMat[3][3]) - (tabMat[2][3] * tabMat[3][2]))
		- tabMat[1][2] * ((tabMat[2][0] * tabMat[3][3]) - (tabMat[2][3] * tabMat[3][0])) +
		tabMat[1][3] * ((tabMat[2][0] * tabMat[3][2]) - (tabMat[2][2] * tabMat[3][0]));

	tabDet[0][2] =
		tabMat[1][0] * ((tabMat[2][1] * tabMat[3][3]) - (tabMat[2][3] * tabMat[3][1]))
		- tabMat[1][1] * ((tabMat[2][0] * tabMat[3][3]) - (tabMat[2][3] * tabMat[3][0])) +
		tabMat[1][3] * ((tabMat[2][0] * tabMat[3][1]) - (tabMat[2][1] * tabMat[3][0]));

	tabDet[0][3] =
		tabMat[1][0] * ((tabMat[2][1] * tabMat[3][2]) - (tabMat[2][2] * tabMat[3][1]))
		- tabMat[1][1] * ((tabMat[2][0] * tabMat[3][2]) - (tabMat[2][2] * tabMat[3][0])) +
		tabMat[1][2] * ((tabMat[2][0] * tabMat[3][1]) - (tabMat[2][1] * tabMat[3][0]));

	det = tabMat[0][0] * tabDet[0][0] - tabMat[0][1] * tabDet[0][1] + tabMat[0][2] * tabDet[0][2] - tabMat[0][3] * tabDet[0][3];
	*/

	//std::cout << "Determinant : " << det << std::endl << std::endl;
	const auto& m = this->tabMat;

	return
		m[0] * (m[5] * (m[10] * m[15] - m[11] * m[14])
			- m[6] * (m[9] * m[15] - m[11] * m[13])
			+ m[7] * (m[9] * m[14] - m[10] * m[13]))
		- m[1] * (m[4] * (m[10] * m[15] - m[11] * m[14])
			- m[6] * (m[8] * m[15] - m[11] * m[12])
			+ m[7] * (m[8] * m[14] - m[10] * m[12]))
		+ m[2] * (m[4] * (m[9] * m[15] - m[11] * m[13])
			- m[5] * (m[8] * m[15] - m[11] * m[12])
			+ m[7] * (m[8] * m[13] - m[9] * m[12]))
		- m[3] * (m[4] * (m[9] * m[14] - m[10] * m[13])
			- m[5] * (m[8] * m[14] - m[10] * m[12])
			+ m[6] * (m[8] * m[13] - m[9] * m[12]));
}

template<typename T>
std::array<T,16> Maths::Matrix4<T>::inverse4x4()
{

	// calcul des cofacteurs en tableau
	/*
	tabCofacteur[0][0] = tabMat[1][1] * ((tabMat[2][2] * tabMat[3][3]) - (tabMat[2][3] * tabMat[3][2])) - tabMat[1][2] * ((tabMat[2][1] * tabMat[3][3]) - (tabMat[2][3] * tabMat[3][1])) + tabMat[1][3] * ((tabMat[2][1] * tabMat[3][2]) - (tabMat[2][2] * tabMat[3][1]));

	tabCofacteur[0][1] = -1 * (tabMat[1][0] * ((tabMat[2][2] * tabMat[3][3]) - (tabMat[2][3] * tabMat[3][2])) - tabMat[1][2] * ((tabMat[2][0] * tabMat[3][3]) - (tabMat[2][3] * tabMat[3][0])) + tabMat[1][3] * ((tabMat[2][0] * tabMat[3][2]) - (tabMat[2][2] * tabMat[3][0])));

	tabCofacteur[0][2] = tabMat[1][0] * ((tabMat[2][1] * tabMat[3][3]) - (tabMat[2][3] * tabMat[3][1])) - tabMat[1][1] * ((tabMat[2][0] * tabMat[3][3]) - (tabMat[2][3] * tabMat[3][0])) + tabMat[1][3] * ((tabMat[2][0] * tabMat[3][1]) - (tabMat[2][1] * tabMat[3][0]));

	tabCofacteur[0][3] = -1 * (tabMat[1][0] * ((tabMat[2][1] * tabMat[3][2]) - (tabMat[2][2] * tabMat[3][1])) - tabMat[1][1] * ((tabMat[2][0] * tabMat[3][2]) - (tabMat[2][2] * tabMat[3][0])) + tabMat[1][2] * ((tabMat[2][0] * tabMat[3][1]) - (tabMat[2][1] * tabMat[3][0])));


	tabCofacteur[1][0] = -1 * (tabMat[0][1] * ((tabMat[2][2] * tabMat[3][3]) - (tabMat[2][3] * tabMat[3][2])) - tabMat[0][2] * ((tabMat[2][1] * tabMat[3][3]) - (tabMat[2][3] * tabMat[3][1])) + tabMat[0][3] * ((tabMat[2][1] * tabMat[3][2]) - (tabMat[2][2] * tabMat[3][1])));

	tabCofacteur[1][1] = tabMat[0][0] * ((tabMat[2][2] * tabMat[3][3]) - (tabMat[2][3] * tabMat[3][2])) - tabMat[0][2] * ((tabMat[2][0] * tabMat[3][3]) - (tabMat[2][3] * tabMat[3][0])) + tabMat[0][3] * ((tabMat[2][0] * tabMat[3][2]) - (tabMat[2][2] * tabMat[3][0]));

	tabCofacteur[1][2] = -1 * (tabMat[0][0] * ((tabMat[2][1] * tabMat[3][3]) - (tabMat[2][3] * tabMat[3][1])) - tabMat[0][1] * ((tabMat[2][0] * tabMat[3][3]) - (tabMat[2][3] * tabMat[3][0])) + tabMat[0][3] * ((tabMat[2][0] * tabMat[3][1]) - (tabMat[2][1] * tabMat[3][0])));

	tabCofacteur[1][3] = tabMat[0][0] * ((tabMat[2][1] * tabMat[3][2]) - (tabMat[2][2] * tabMat[3][1])) - tabMat[0][1] * ((tabMat[2][0] * tabMat[3][2]) - (tabMat[2][2] * tabMat[3][0])) + tabMat[0][2] * ((tabMat[2][0] * tabMat[3][1]) - (tabMat[2][1] * tabMat[3][0]));


	tabCofacteur[2][0] = tabMat[0][1] * ((tabMat[1][2] * tabMat[3][3]) - (tabMat[1][3] * tabMat[3][2])) - tabMat[0][2] * ((tabMat[1][1] * tabMat[3][3]) - (tabMat[1][3] * tabMat[3][1])) + tabMat[0][3] * ((tabMat[1][1] * tabMat[3][2]) - (tabMat[1][2] * tabMat[3][1]));

	tabCofacteur[2][1] = -1 * (tabMat[0][0] * ((tabMat[1][2] * tabMat[3][3]) - (tabMat[1][3] * tabMat[3][2])) - tabMat[0][2] * ((tabMat[1][0] * tabMat[3][3]) - (tabMat[1][3] * tabMat[3][0])) + tabMat[0][3] * ((tabMat[1][0] * tabMat[3][2]) - (tabMat[1][2] * tabMat[3][0])));

	tabCofacteur[2][2] = tabMat[0][0] * ((tabMat[1][1] * tabMat[3][3]) - (tabMat[1][3] * tabMat[3][1])) - tabMat[0][1] * ((tabMat[1][0] * tabMat[3][3]) - (tabMat[1][3] * tabMat[3][0])) + tabMat[0][3] * ((tabMat[1][0] * tabMat[3][1]) - (tabMat[1][1] * tabMat[3][0]));

	tabCofacteur[2][3] = -1 * (tabMat[0][0] * ((tabMat[1][1] * tabMat[3][2]) - (tabMat[1][2] * tabMat[3][1])) - tabMat[0][1] * ((tabMat[1][0] * tabMat[3][2]) - (tabMat[1][2] * tabMat[3][0])) + tabMat[0][2] * ((tabMat[1][0] * tabMat[3][1]) - (tabMat[1][1] * tabMat[3][0])));


	tabCofacteur[3][0] = -1 * (tabMat[0][1] * ((tabMat[1][2] * tabMat[2][3]) - (tabMat[1][3] * tabMat[2][2])) - tabMat[0][2] * ((tabMat[1][1] * tabMat[2][3]) - (tabMat[1][3] * tabMat[2][1])) + tabMat[0][3] * ((tabMat[1][1] * tabMat[2][2]) - (tabMat[1][2] * tabMat[2][1])));

	tabCofacteur[3][1] = tabMat[0][0] * ((tabMat[1][2] * tabMat[2][3]) - (tabMat[1][3] * tabMat[2][2])) - tabMat[0][2] * ((tabMat[1][0] * tabMat[2][3]) - (tabMat[1][3] * tabMat[2][0])) + tabMat[0][3] * ((tabMat[1][0] * tabMat[2][2]) - (tabMat[1][2] * tabMat[2][0]));

	tabCofacteur[3][2] = -1 * (tabMat[0][0] * ((tabMat[1][1] * tabMat[2][3]) - (tabMat[1][3] * tabMat[2][1])) - tabMat[0][1] * ((tabMat[1][0] * tabMat[2][3]) - (tabMat[1][3] * tabMat[2][0])) + tabMat[0][3] * ((tabMat[1][0] * tabMat[2][1]) - (tabMat[1][1] * tabMat[2][0])));

	tabCofacteur[3][3] = tabMat[0][0] * ((tabMat[1][1] * tabMat[2][2]) - (tabMat[1][2] * tabMat[2][1])) - tabMat[0][1] * ((tabMat[1][0] * tabMat[2][2]) - (tabMat[1][2] * tabMat[2][0])) + tabMat[0][2] * ((tabMat[1][0] * tabMat[2][1]) - (tabMat[1][1] * tabMat[2][0]));
	*/

	// calcul des cofacteurs en this et arrays


	// transposé en tableau
	/*
	tabCofacteur[0][0]; tabCofacteur[1][0]; tabCofacteur[2][0]; tabCofacteur[3][0];

	tabCofacteur[0][1]; tabCofacteur[1][1]; tabCofacteur[2][1]; tabCofacteur[3][1];

	tabCofacteur[0][2]; tabCofacteur[1][2]; tabCofacteur[2][2]; tabCofacteur[3][2];

	tabCofacteur[0][3]; tabCofacteur[1][3]; tabCofacteur[2][3]; tabCofacteur[3][3];
	*/
	// division par determinant en tableau
	/*
	tabCofacteur[0][0] = tabCofacteur[0][0] / det;
	tabCofacteur[0][1] = tabCofacteur[0][1] / det;
	tabCofacteur[0][2] = tabCofacteur[0][2] / det;
	tabCofacteur[0][3] = tabCofacteur[0][3] / det;

	tabCofacteur[1][0] = tabCofacteur[1][0] / det;
	tabCofacteur[1][1] = tabCofacteur[1][1] / det;
	tabCofacteur[1][2] = tabCofacteur[1][2] / det;
	tabCofacteur[1][3] = tabCofacteur[1][3] / det;

	tabCofacteur[2][0] = tabCofacteur[2][0] / det;
	tabCofacteur[2][1] = tabCofacteur[2][1] / det;
	tabCofacteur[2][2] = tabCofacteur[2][2] / det;
	tabCofacteur[2][3] = tabCofacteur[2][3] / det;

	tabCofacteur[3][0] = tabCofacteur[3][0] / det;
	tabCofacteur[3][1] = tabCofacteur[3][1] / det;
	tabCofacteur[3][2] = tabCofacteur[3][2] / det;
	tabCofacteur[3][3] = tabCofacteur[3][3] / det;
	*/

	// division determinant 

	/*
	std::cout << "Matrice inverse : " << std::endl << std::endl;
	std::cout << tabCofacteur[0][0] << ", " << tabCofacteur[1][0] << ", " << tabCofacteur[2][0] << ", " << tabCofacteur[3][0] << ", " << std::endl;
	std::cout << tabCofacteur[0][1] << ", " << tabCofacteur[1][1] << ", " << tabCofacteur[2][1] << ", " << tabCofacteur[3][1] << ", " << std::endl;
	std::cout << tabCofacteur[0][2] << ", " << tabCofacteur[1][2] << ", " << tabCofacteur[2][2] << ", " << tabCofacteur[3][2] << ", " << std::endl;
	std::cout << tabCofacteur[0][3] << ", " << tabCofacteur[1][3] << ", " << tabCofacteur[2][3] << ", " << tabCofacteur[3][3] << ", " << std::endl << std::endl;
	*/
	const auto& m = this->tabMat;
	T det = this->determinant4x4();
	if (std::abs(det) < 1e-6) {
		std::cout << "La matrice n'est pas inversible." << std::endl;
		return std::array<T, 16>{};
	}

	std::array<T, 16> cof;

	cof[0] = m[5] * (m[10] * m[15] - m[11] * m[14]) - m[6] * (m[9] * m[15] - m[11] * m[13]) + m[7] * (m[9] * m[14] - m[10] * m[13]);
	cof[1] = -(m[4] * (m[10] * m[15] - m[11] * m[14]) - m[6] * (m[8] * m[15] - m[11] * m[12]) + m[7] * (m[8] * m[14] - m[10] * m[12]));
	cof[2] = m[4] * (m[9] * m[15] - m[11] * m[13]) - m[5] * (m[8] * m[15] - m[11] * m[12]) + m[7] * (m[8] * m[13] - m[9] * m[12]);
	cof[3] = -(m[4] * (m[9] * m[14] - m[10] * m[13]) - m[5] * (m[8] * m[14] - m[10] * m[12]) + m[6] * (m[8] * m[13] - m[9] * m[12]));

	cof[4] = -(m[1] * (m[10] * m[15] - m[11] * m[14]) - m[2] * (m[9] * m[15] - m[11] * m[13]) + m[3] * (m[9] * m[14] - m[10] * m[13]));
	cof[5] = m[0] * (m[10] * m[15] - m[11] * m[14]) - m[2] * (m[8] * m[15] - m[11] * m[12]) + m[3] * (m[8] * m[14] - m[10] * m[12]);
	cof[6] = -(m[0] * (m[9] * m[15] - m[11] * m[13]) - m[1] * (m[8] * m[15] - m[11] * m[12]) + m[3] * (m[8] * m[13] - m[9] * m[12]));
	cof[7] = m[0] * (m[9] * m[14] - m[10] * m[13]) - m[1] * (m[8] * m[14] - m[10] * m[12]) + m[2] * (m[8] * m[13] - m[9] * m[12]);

	cof[8] = m[1] * (m[6] * m[15] - m[7] * m[14]) - m[2] * (m[5] * m[15] - m[7] * m[13]) + m[3] * (m[5] * m[14] - m[6] * m[13]);
	cof[9] = -(m[0] * (m[6] * m[15] - m[7] * m[14]) - m[2] * (m[4] * m[15] - m[7] * m[12]) + m[3] * (m[4] * m[14] - m[6] * m[12]));
	cof[10] = m[0] * (m[5] * m[15] - m[7] * m[13]) - m[1] * (m[4] * m[15] - m[7] * m[12]) + m[3] * (m[4] * m[13] - m[5] * m[12]);
	cof[11] = -(m[0] * (m[5] * m[14] - m[6] * m[13]) - m[1] * (m[4] * m[14] - m[6] * m[12]) + m[2] * (m[4] * m[13] - m[5] * m[12]));

	cof[12] = -(m[1] * (m[6] * m[11] - m[7] * m[10]) - m[2] * (m[5] * m[11] - m[7] * m[9]) + m[3] * (m[5] * m[10] - m[6] * m[9]));
	cof[13] = m[0] * (m[6] * m[11] - m[7] * m[10]) - m[2] * (m[4] * m[11] - m[7] * m[8]) + m[3] * (m[4] * m[10] - m[6] * m[8]);
	cof[14] = -(m[0] * (m[5] * m[11] - m[7] * m[9]) - m[1] * (m[4] * m[11] - m[7] * m[8]) + m[3] * (m[4] * m[9] - m[5] * m[8]));
	cof[15] = m[0] * (m[5] * m[10] - m[6] * m[9]) - m[1] * (m[4] * m[10] - m[6] * m[8]) + m[2] * (m[4] * m[9] - m[5] * m[8]);

	std::array<T, 16> inverse;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			inverse[i * 4 + j] = cof[j * 4 + i] / det;
		}
	}

	return inverse;
}

template<typename T>
bool Maths::Matrix4<T>::isIdentity4x4()
{
	const T eps = 1e-5;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == j) {
				if (std::abs(tabMat[i * 4 + j] - T(1)) > eps) return false;
			}
			else {
				if (std::abs(tabMat[i * 4 + j]) > eps) return false;
			}
		}
	}
	return true;
}


template<typename T>
T& Maths::Matrix4<T>::at(int r, int c)  {
	return tabMat[r * 4 + c];
}

template<typename T>
Maths::Vct3D<T> Maths::Matrix4<T>::lossyScale4x4()
{
	/*On prend les 3 colonnes de la matrice.
	  On calcule leur longueur.
	  Si le déterminant est négatif, un axe est inversé.
	  Cela donne l’échelle approximative (d’où “lossy”).*/

	// ensuite on va faire en sorte de créé une bébé fonction qui va permettre de 
	// calculer la longueur d'un vecteur 3D grace au [] qui créé une fonction comme
	// si on créé un float dans la fonction.

	auto length = [](T x, T y, T z) { // le [] s'appelle lambda
		return std::sqrt(x * x + y * y + z * z);  // norme = √(x² + y² + z²)
	};

	// ca permet de ne pas créé des fonctions qu'on réutilisera pas.

	Maths::Vct3D<T> scale; // avec ce vecteur, on va stocker les valeurs d'échelles (x,y,z)

	// Chaque colonne correspond à un axe (X, Y, Z) transformé par la matrice.

	// Colonne 0 → axe X transformé → sa longueur donne l’échelle sur X
	// si on regarde sans la fonction at et length, on a :
	scale.SetX(std::sqrt(
		(tabMat[0 * 4 + 0]) * (tabMat[0 * 4 + 0]) + // at(0,0)
		(tabMat[1 * 4 + 0]) * (tabMat[1 * 4 + 0]) + // at(1,0)
		(tabMat[2 * 4 + 0]) * (tabMat[2 * 4 + 0]))	// at(2,0)
	);

	// Colonne 1 → axe Y transformé → sa longueur donne l’échelle sur Y
	scale.SetY(length(at(0, 1), at(1, 1), at(2, 1)));

	// Colonne 2 → axe Z transformé → sa longueur donne l’échelle sur Z
	scale.SetZ(length(at(0, 2), at(1, 2), at(2, 2)));

	// donc avec les at et lenght c'est vachement plus simple et rapido :)

	// calcul du determinant
	T det =
		at(0, 0) * (at(1, 1) * at(2, 2) - at(1, 2) * at(2, 1)) -
		at(0, 1) * (at(1, 0) * at(2, 2) - at(1, 2) * at(2, 0)) +
		at(0, 2) * (at(1, 0) * at(2, 1) - at(1, 1) * at(2, 0));

	// si le determinant est négatif alors on inverse le signe d'un axe
	// c'est a dire que ca va faire un genre d'effet miroir chelou
	if (det < 0)
		scale.SetX(-scale.GetX());

	std::cout << "Scale : " << scale.GetX() << ", " << scale.GetY() << ", " << scale.GetZ() << std::endl << std::endl;

	// enfin on retourne le vecteur de ses morts et paf ca fais des chocapics
	return scale;
}

template<typename T>
Maths::Matrix4<T> Maths::Matrix4<T>::rotation4x4(T angleX, T angleY, T angleZ)
{
	T radX = angleX * deg2rad;
	T radY = angleY * deg2rad;
	T radZ = angleZ * deg2rad;

	Matrix4 rotX, rotY, rotZ;

	// on va commencer par l'axe X 
	rotX.at(1, 1) = cos(radX);
	rotX.at(1, 2) = -sin(radX);
	rotX.at(2, 1) = sin(radX);
	rotX.at(2, 2) = cos(radX);

	rotY.at(0, 0) = cos(radY);
	rotY.at(0, 2) = -sin(radY);
	rotY.at(2, 0) = sin(radY);
	rotY.at(2, 2) = cos(radY);

	rotZ.at(0, 0) = cos(radZ);
	rotZ.at(0, 1) = -sin(radZ);
	rotZ.at(1, 0) = sin(radZ);
	rotZ.at(1, 1) = cos(radZ);

	// normalement l'opérator est censé marcher inshallah
	return rotX * rotY * rotZ;
}

template<typename T>
std::array<T, 16> Maths::Matrix4<T>::transpose4x4(Maths::Matrix4<T> feur)
{   /*
	std::cout << "Transpose : " << std::endl << std::endl;
	std::cout << tabMat[0][0] << ", " << tabMat[1][0] << ", " << tabMat[2][0] << ", " << tabMat[3][0] << ", " << std::endl;
	std::cout << tabMat[0][1] << ", " << tabMat[1][1] << ", " << tabMat[2][1] << ", " << tabMat[3][1] << ", " << std::endl;
	std::cout << tabMat[0][2] << ", " << tabMat[1][2] << ", " << tabMat[2][2] << ", " << tabMat[3][2] << ", " << std::endl;
	std::cout << tabMat[0][3] << ", " << tabMat[1][3] << ", " << tabMat[2][3] << ", " << tabMat[3][3] << ", " << std::endl << std::endl;
	*/

	std::array<T, 16> transpo;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			transpo[i * 4 + j] = feur.tabMat[j * 4 + i];
		}
	}

	this->tabMat = transpo;

	std::cout << "Transpose : " << std::endl << std::endl;

	printMatrix4x4();

	return this->tabMat;
}
#pragma endregion Properties
#pragma region Publics Methods

template<typename T>
void Maths::Matrix4<T>::getColumn4x4(T column)
{
	if (column < 0 || column > 3) {
		std::cout << "Un mauvais numero a ete entre, il faut un numero entre 0 et 3.\n";
		return;
	}

	std::cout
		<< this->tabMat[column] << " "
		<< this->tabMat[column + 4] << " "
		<< this->tabMat[column + 8] << " "
		<< this->tabMat[column + 12] << " \n";
}

template<typename T>
Maths::Vct3D<T> Maths::Matrix4<T>::getPosition4x4() const
{
	return Maths::Vct3D<T> (tabMat[12], tabMat[13], tabMat[14]);
}

template<typename T>
void Maths::Matrix4<T>::getRow4x4(T row)
{
	if (row < 0 || row > 3) {
		std::cout << "Un mauvais numero a ete entre, il faut un numero entre 0 et 3.\n";
		return;
	}

	int index = row * 4;

	std::cout
		<< this->tabMat[index] << " "
		<< this->tabMat[index + 1] << " "
		<< this->tabMat[index + 2] << " "
		<< this->tabMat[index + 3] << " \n";
}

template<typename T>
Maths::Vct3D<T> Maths::Matrix4<T>::multiplyPoint4x4(Maths::Vct3D<T>& vect)
{
	// en tableau
	/*
	float resultX = tabMat[0][0] * vect.GetX() + tabMat[0][1] * vect.GetY() + tabMat[0][2] * vect.GetZ() + tabMat[0][3];
	float resultY = tabMat[1][0] * vect.GetX() + tabMat[1][1] * vect.GetY() + tabMat[1][2] * vect.GetZ() + tabMat[1][3];
	float resultZ = tabMat[2][0] * vect.GetX() + tabMat[2][1] * vect.GetY() + tabMat[2][2] * vect.GetZ() + tabMat[2][3];
	float resultW = tabMat[3][0] * vect.GetX() + tabMat[3][1] * vect.GetY() + tabMat[3][2] * vect.GetZ() + tabMat[3][3];

	if (resultW != 0.0f && resultW != 1.0f)
	{
		resultX /= resultW;
		resultY /= resultW;
		resultZ /= resultW;
	}

	std::cout << resultX << " " << resultY << " " << resultZ << std::endl << std::endl;
	*/

	const auto& m = this->tabMat;

	T x = vect.GetX();
	T y = vect.GetY();
	T z = vect.GetZ();

	T resultX = m[0 * 4 + 0] * x + m[0 * 4 + 1] * y + m[0 * 4 + 2] * z + m[0 * 4 + 3];
	T resultY = m[1 * 4 + 0] * x + m[1 * 4 + 1] * y + m[1 * 4 + 2] * z + m[1 * 4 + 3];
	T resultZ = m[2 * 4 + 0] * x + m[2 * 4 + 1] * y + m[2 * 4 + 2] * z + m[2 * 4 + 3];
	T resultW = 1;

	if (resultW != 0 && resultW != 1) {
		resultX /= resultW;
		resultY /= resultW;
		resultZ /= resultW;
	}

	vector3D.SetVector3D(resultX, resultY, resultZ);

	std::cout << "Multiplication de la matrice" << std::endl << std::endl;

	std::cout << resultX << " " << resultY << " " << resultZ << std::endl << std::endl;

	return vector3D;
}

template<typename T>
Maths::Vct3D<T> Maths::Matrix4<T>::multiplyPoint3x4_4x4(const Maths::Vct3D<T>& vect)
{
	T x = vect.GetX();
	T y = vect.GetY();
	T z = vect.GetZ();

	T resultX = at(0, 0) * x + at(0, 1) * y + at(0, 2) * z + at(0, 3);
	T resultY = at(1, 0) * x + at(1, 1) * y + at(1, 2) * z + at(1, 3);
	T resultZ = at(2, 0) * x + at(2, 1) * y + at(2, 2) * z + at(2, 3);

	return Vct3D<T>(resultX, resultY, resultZ);

}

template<typename T>
Maths::Vct3D<T> Maths::Matrix4<T>::multiplyVector4x4(Maths::Vct3D<T>& vect)
{
	T x = vect.GetX();
	T y = vect.GetY();
	T z = vect.GetZ();

	// ici on utilise la meme méthode qu'avant : index = row ∗ 4  +col

	T resultX = at(0,0) * x + at(0,1) * y + at(0,2) * z + at(0,3);
	T resultY = at(1,0) * x + at(1,1) * y + at(1,2) * z + at(1,3);
	T resultZ = at(2,0) * x + at(2,1) * y + at(2,2) * z + at(2,3);
	T resultW = at(3,0) * x + at(3,1) * y + at(3,2) * z + at(3,3);

	// normalisation si besoin
	if (resultW != 0 && resultW != 1) {
		resultX /= resultW;
		resultY /= resultW;
		resultZ /= resultW;
	}

	vector3D.SetVector3D(resultX, resultY, resultZ);

	std::cout << "Multiplication de la matrice" << std::endl << std::endl;
	std::cout << resultX << " " << resultY << " " << resultZ << std::endl << std::endl;

	return vector3D;
}

template<typename T>
Maths::Matrix4<T> Maths::Matrix4<T>::multiplyMatrix4x4(Matrix4<T>& A, Matrix4<T>& B)
{
	Matrix4 result{}; // initialise tous les éléments à zéro

	for (int row = 0; row < 4; ++row) {
		for (int col = 0; col < 4; ++col) {
			for (int i = 0; i < 4; ++i) {
				result.tabMat[row, col] += A.tabMat[row, i] * B.tabMat[i, col];
			}
		}
	}

	return result;
}

template<typename T>
void Maths::Matrix4<T>::setColumn4x4(T columnNumber, T number1, T number2, T number3, T number4)
{
	int col = static_cast<int>(columnNumber);

	if (col < 0 || col > 3) {
		
		return;
	}

	
	this->tabMat[0 * 4 + col] = number1;
	this->tabMat[1 * 4 + col] = number2;
	this->tabMat[2 * 4 + col] = number3;
	this->tabMat[3 * 4 + col] = number4;
}

template<typename T>
void Maths::Matrix4<T>::setRow4x4(T rowNumber, T number1, T number2, T number3, T number4)
{
	int row = static_cast<int>(rowNumber);

	if (row < 0 || row > 3) {
	
		return;
	}

	
	this->tabMat[row * 4 + 0] = number1;
	this->tabMat[row * 4 + 1] = number2;
	this->tabMat[row * 4 + 2] = number3;
	this->tabMat[row * 4 + 3] = number4;
}

template<typename T>
Maths::Matrix4<T> Maths::Matrix4<T>::setTRS4x4(const Maths::Vct3D<T>& translation, const Maths::Vct3D<T>& rotationEulerDeg, const Maths::Vct3D<T>& scale)
		{
	
	constexpr T deg2rad = static_cast<T>(3.14159265358979323846 / 180.0);
	T rx = rotationEulerDeg.GetX() * deg2rad;
	T ry = rotationEulerDeg.GetY() * deg2rad;
	T rz = rotationEulerDeg.GetZ() * deg2rad;

	
	Matrix4<T> result = Matrix4<T>::identity4x4();

	
	result.at(0, 0) = scale.GetX();
	result.at(1, 1) = scale.GetY();
	result.at(2, 2) = scale.GetZ();

	Matrix4<T> rotX = Matrix4<T>::identity4x4();
	rotX.at(1, 1) = std::cos(rx); rotX.at(1, 2) = -std::sin(rx);
	rotX.at(2, 1) = std::sin(rx); rotX.at(2, 2) = std::cos(rx);

	Matrix4<T> rotY = Matrix4<T>::identity4x4();
	rotY.at(0, 0) = std::cos(ry); rotY.at(0, 2) = std::sin(ry);
	rotY.at(2, 0) = -std::sin(ry); rotY.at(2, 2) = std::cos(ry);

	Matrix4<T> rotZ = Matrix4<T>::identity4x4();
	rotZ.at(0, 0) = std::cos(rz); rotZ.at(0, 1) = -std::sin(rz);
	rotZ.at(1, 0) = std::sin(rz); rotZ.at(1, 1) = std::cos(rz);


	result = rotZ * (rotY * (rotX * result));

	
	result.at(0, 3) = translation.GetX();
	result.at(1, 3) = translation.GetY();
	result.at(2, 3) = translation.GetZ();

	return result;
}

template<typename T>
std::string Maths::Matrix4<T>::toString4x4()
{
	// en std
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j)
			std::cout << this->tabMat[i * 4 + j] << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl << std::endl;

	// convertit en string
	std::ostringstream ss; // permet d'écrire une string comme si c'était un cout
	ss << std::fixed << std::setprecision(3); // 3 chiffres après la virgule

	ss << "Matrice 4x4 :" << std::endl;
	for (int i = 0; i < 4; ++i) {
		ss << "| ";
		for (int j = 0; j < 4; ++j) {
			ss << std::setw(8) << this->tabMat[i * 4 + j] << " ";
		}
		ss << "|" << std::endl;
	}
	
	return ss.str();
}

template<typename T>
bool Maths::Matrix4<T>::validTRS4x4()
{
	const T EPS = 1e-6;

	
	T x0 = at(0, 0), x1 = at(1, 0), x2 = at(2, 0);
	T y0 = at(0, 1), y1 = at(1, 1), y2 = at(2, 1);
	T z0 = at(0, 2), z1 = at(1, 2), z2 = at(2, 2);

	
	auto length = [](T a, T b, T c) { return std::sqrt(a * a + b * b + c * c); };

	if (length(x0, x1, x2) < EPS) return false;
	if (length(y0, y1, y2) < EPS) return false;
	if (length(z0, z1, z2) < EPS) return false;

	
	auto dot = [](T a0, T a1, T a2, T b0, T b1, T b2) { return a0 * b0 + a1 * b1 + a2 * b2; };

	if (std::abs(dot(x0, x1, x2, y0, y1, y2)) > EPS) return false;
	if (std::abs(dot(x0, x1, x2, z0, z1, z2)) > EPS) return false;
	if (std::abs(dot(y0, y1, y2, z0, z1, z2)) > EPS) return false;

	if (std::abs(at(3, 0)) > EPS || std::abs(at(3, 1)) > EPS ||
		std::abs(at(3, 2)) > EPS || std::abs(at(3, 3) - 1) > EPS)
		return false;

	
	return true;
}
#pragma endregion Publics Methods
#pragma region Static Methods
// ici j'ai full chat gpt et j'avoue que j'ai rien compris
template<typename T> 
Maths::Matrix4<T> Maths::Matrix4<T>::lookAt4x4(Maths::Vct3D<T>& from, Maths::Vct3D<T>& to, Maths::Vct3D<T>& up)
{
	// forward = direction vers la cible
	Maths::Vct3D<T> forward = (to - from).Normalized();

	// right = perpendiculaire à forward et up
	Maths::Vct3D<T> right = up.Cross(up, forward).Normalized();

	// upCorrected = vecteur up corrigé (orthogonal)
	Maths::Vct3D<T> upCorrected = forward.Cross(forward, right);

	// --- Création de la matrice LookAt ---
	Matrix4<T> result;

	// colonne 0 → axe droit (X)
	result.tabMat[0] = right.GetX();
	result.tabMat[1] = right.GetY();
	result.tabMat[2] = right.GetZ();
	result.tabMat[3] = 0;

	// colonne 1 → axe up (Y)
	result.tabMat[4] = upCorrected.GetX();
	result.tabMat[5] = upCorrected.GetY();
	result.tabMat[6] = upCorrected.GetZ();
	result.tabMat[7] = 0;

	// colonne 2 → -forward (Z)
	result.tabMat[8] = -forward.GetX();
	result.tabMat[9] = -forward.GetY();
	result.tabMat[10] = -forward.GetZ();
	result.tabMat[11] = 0;

	// colonne 3 → translation
	result.tabMat[12] = -right.Dot(from);
	result.tabMat[13] = -upCorrected.Dot(from);
	result.tabMat[14] = forward.Dot(from); // note le signe selon convention
	result.tabMat[15] = 1;

	return result;
}

template<typename T>
Maths::Matrix4<T> Maths::Matrix4<T>::ortho4x4(T left, T right, T bottom, T top, T zNear, T zFar)
{
	Matrix4 matrix;

	matrix.tabMat[0] = 2 / (right - left);
	matrix.tabMat[1] = 0;
	matrix.tabMat[2] = 0;
	matrix.tabMat[3] = 0;
	matrix.tabMat[4] = 0;
	matrix.tabMat[5] = 2 / (top - bottom);
	matrix.tabMat[6] = 0;
	matrix.tabMat[7] = 0;
	matrix.tabMat[8] = 0;
	matrix.tabMat[9] = 0;
	matrix.tabMat[10] = -2 / (zFar - zNear);
	matrix.tabMat[11] = 0;
	matrix.tabMat[12] = -(right + left) / (right - left);
	matrix.tabMat[13] = -(top + bottom) / (top - bottom);
	matrix.tabMat[14] = -(zFar + zNear) / (zFar - zNear);
	matrix.tabMat[15] = -1;

	std::cout << "Matrice Orthonormée : " << std::endl << std::endl;

	// Afficher la matrice
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j)
			std::cout << matrix.tabMat[i * 4 + j] << " ";
		std::cout << std::endl;
	}

	std::cout << std::endl;

	return matrix;
}

template<typename T>
Maths::Matrix4<T> Maths::Matrix4<T>::perspective4x4(T fovY, T aspect, T near, T far) {

	Matrix4<T> result;

	// Calcul du facteur f = 1 / tan(fov/2)
	T f = 1 / std::tan(fovY * 0.5);

	// Mise à zéro de la matrice
	for (int i = 0; i < 16; ++i) result.tabMat[i] = 0;

	// Remplissage des éléments
	result.tabMat[0] = f / aspect;  // m00
	result.tabMat[5] = f;           // m11
	result.tabMat[10] = (far + near) / (near - far);  // m22
	result.tabMat[11] = -1;          // m23
	result.tabMat[14] = (2 * far * near) / (near - far); // m32
	result.tabMat[15] = 0;           // m33

	return result;
}

template<typename T>
Maths::Matrix4<T> Maths::Matrix4<T>::rotate4x4(const Maths::Quat<T>& q)
{
	Matrix4<T> mat;

	const T x = q.GetX();
	const T y = q.GetY();
	const T z = q.GetZ();
	const T w = q.GetW();

	const T xx = x * x;
	const T yy = y * y;
	const T zz = z * z;
	const T xy = x * y;
	const T xz = x * z;
	const T yz = y * z;
	const T wx = w * x;
	const T wy = w * y;
	const T wz = w * z;

	mat.tabMat[0] = static_cast<T>(1) - static_cast<T>(2) * (yy + zz);
	mat.tabMat[1] = static_cast<T>(2) * (xy - wz);
	mat.tabMat[2] = static_cast<T>(2) * (xz + wy);
	mat.tabMat[3] = static_cast<T>(0);

	mat.tabMat[4] = static_cast<T>(2) * (xy + wz);
	mat.tabMat[5] = static_cast<T>(1) - static_cast<T>(2) * (xx + zz);
	mat.tabMat[6] = static_cast<T>(2) * (yz - wx);
	mat.tabMat[7] = static_cast<T>(0);

	mat.tabMat[8] = static_cast<T>(2) * (xz - wy);
	mat.tabMat[9] = static_cast<T>(2) * (yz + wx);
	mat.tabMat[10] = static_cast<T>(1) - static_cast<T>(2) * (xx + yy);
	mat.tabMat[11] = static_cast<T>(0);

	mat.tabMat[12] = static_cast<T>(0);
	mat.tabMat[13] = static_cast<T>(0);
	mat.tabMat[14] = static_cast<T>(0);
	mat.tabMat[15] = static_cast<T>(1);

	return mat;
}

template<typename T>
Maths::Matrix4<T> Maths::Matrix4<T>::scale4x4(T x, T y, T z)
{
	Matrix4 result = identity4x4();
	result.at(0, 0) = x;
	result.at(1, 1) = y;
	result.at(2, 2) = z;
	return result;
}


template<typename T>
Maths::Matrix4<T> Maths::Matrix4<T>::scale4x4(const Maths::Vct3D<T>& s)
{
	return scale4x4(s.GetX(), s.GetY(), s.GetZ());
}

template<typename T>
Maths::Matrix4<T> Maths::Matrix4<T>::translate4x4(T tx, T ty, T tz)
{
	Matrix4 result = identity4x4();
	result.at(0, 3) = tx;
	result.at(1, 3) = ty;
	result.at(2, 3) = tz;
	result.at(3, 3) = 1;
	return result;
}

template<typename T>
Maths::Matrix4<T> Maths::Matrix4<T>::translate4x4(const Maths::Vct3D<T>& t)
{
	Matrix4<T> result = Matrix4<T>::identity4x4();

	result.at(0, 3) = t.GetX();
	result.at(1, 3) = t.GetY();
	result.at(2, 3) = t.GetZ();

	return result;
}

template<typename T>
Maths::Matrix4<T> Maths::Matrix4<T>::TRS4x4(
	const Maths::Vct3D<T>& position,
	const Maths::Vct3D<T>& rotationEuler,
	const Maths::Vct3D<T>& scale)
{
	Matrix4<T> S = Matrix4<T>::scale4x4(scale);

	T cx = std::cos(rotationEuler.GetX()), sx = std::sin(rotationEuler.GetX());
	T cy = std::cos(rotationEuler.GetY()), sy = std::sin(rotationEuler.GetY());
	T cz = std::cos(rotationEuler.GetZ()), sz = std::sin(rotationEuler.GetZ());

	Matrix4<T> Rx, Ry, Rz;

	
	Rx.tabMat[0] = 1; Rx.tabMat[5] = cx; Rx.tabMat[6] = -sx; Rx.tabMat[9] = sx; Rx.tabMat[10] = cx; Rx.tabMat[15] = 1;

	
	Ry.tabMat[0] = cy; Ry.tabMat[2] = sy; Ry.tabMat[5] = 1; Ry.tabMat[8] = -sy; Ry.tabMat[10] = cy; Ry.tabMat[15] = 1;

	
	Rz.tabMat[0] = cz; Rz.tabMat[1] = -sz; Rz.tabMat[4] = sz; Rz.tabMat[5] = cz; Rz.tabMat[10] = 1; Rz.tabMat[15] = 1;

	Matrix4<T> R = Rz * Ry * Rx;
	Matrix4<T> Trans = Matrix4<T>::translate4x4(position);
	Matrix4<T> TRS = Trans * (R * S);

	return TRS;
}

template<typename T>
Maths::Matrix4<T> Maths::Matrix4<T>::operator*(const Matrix4<T>& other) const
{
	Matrix4<T> result;

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			result.tabMat[i * 4 + j] = static_cast<T>(0);
			for (int k = 0; k < 4; ++k) {
				result.tabMat[i * 4 + j] += tabMat[i * 4 + k] * other.tabMat[k * 4 + j];
			}
		}
	}

	return result;
}

#pragma endregion Static Methods