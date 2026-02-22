# 🧮 Librairie Mathématique C++ — Vecteurs, Matrices, Quaternions & Démo SFML 3.0.2
## 📘 Présentation

Ce projet est une librairie mathématique complète en C++, conçue pour offrir une base solide en calcul vectoriel, matriciel et quaternionique, appliquée aux transformations 2D et 3D.

Elle a été développée dans une optique d’apprentissage approfondi du C++ moderne (C++17) et d’expérimentation autour de la 3D, tout en intégrant un projet de démonstration SFML 3.0.2 (type Pong) exploitant la librairie pour la gestion des calculs géométriques et physiques.

## 👨‍💻 Auteurs

**Maxime Luhat**  —  **Game Developer Student**

**Quentin Lopes**  —  **Student in Game Development**

## 🖥️ Environnement et Prérequis

Langage : C++17 ou supérieur

Bibliothèque graphique : SFML 3.0.2

IDE conseillé : Visual Studio 2022 (ou CMake)

Tests unitaires : Microsoft CppUnitTest

## ⚙️ Structure de la Librairie
### 📦 Namespace : Maths

Toutes les classes sont regroupées sous le namespace Maths, garantissant une organisation claire, modulaire et réutilisable dans tout projet nécessitant des calculs mathématiques.

### 🧭 Classe Vct2D<T> — Vecteurs 2D

Opérations arithmétiques : +, -, *, /, Dot

Calculs géométriques : magnitude, sqrMagnitude, Angle, Distance

Interpolations : LerpClamp, LerpUnClamp, MoveTowards

Outils : ClampMagnitude, Reflect, Perpendicular, Scale, SignedAngle

Manipulations : up(), down(), left(), right(), zero(), one(), positiveInfinity(), negativeInfinity()

Conversions : ToString(), opérateur ==, accès indexé operator[]

### 🧭 Classe Vct3D<T> — Vecteurs 3D

Opérations arithmétiques : +, -, *, /, Dot, Cross

Calculs : magnitude, sqrMagnitude, Angle, Distance

Interpolations : LerpClamp, LerpUnClamp, MoveTowards

Outils : ClampMagnitude, Reflect, Project, ProjectPlane, OrthoNormalise, SignedAngle

Manipulations : up(), down(), forward(), back(), zero(), one()

Conversions : toString(), opérateur ==, accès indexé operator[]

### 🔄 Classe Quat<T> — Quaternions

Représentation et manipulation de rotations 3D sans gimbal lock

Fonctions clés :

Dot, Cross, Magnitude, Normalize, Inverse

FromToRotation, RotateTowards, LookRotation

Lerp, Slerp, LerpUnclamped, SlerpUnclamped

ToAngleAxis, AngleAxis, EulerAngles

Permet une gestion complète des rotations tridimensionnelles.

### 🧮 Classe Matrix3<Tflo, Tint> — Matrices 3x3

Calculs : determinant, inverse, transpose

Manipulations : setRow, setColumn, rotation, scale, translate

Outils : isIdentity, validTRS, Frustum, ortho, perspective

Sert de base pour les transformations linéaires en 3D

### 🧮 Classe Matrix4<T> — Matrices 4x4

Création de matrices standards :
identity4x4, zero4x4, translate4x4, scale4x4, rotate4x4

Transformations avancées :
TRS4x4, lookAt4x4, perspective4x4, ortho4x4

Calculs et vérifications :
determinant4x4, inverse4x4, transpose4x4, validTRS4x4

Opérations :
multiplyMatrix4x4, multiplyVector4x4, multiplyPoint4x4

Compatible avec les classes Vct3D et Quat.

## 🧪 Tests unitaires

Tous les modules (Vecteurs, Matrices, Quaternions) sont couverts par des tests unitaires Microsoft CppUnitTest, garantissant :

la stabilité,

la cohérence,

et la fiabilité des calculs dans toutes les conditions d’utilisation.

## 🎮 Démo SFML — Pong Mathématique

Un mini-jeu Pong a été développé avec SFML 3.0.2 pour illustrer l’utilisation concrète de la librairie.

Tous les calculs de mouvements, de collisions et de rebonds reposent sur les classes Vct2D et Vct3D, démontrant la modularité et la robustesse de la librairie dans un contexte applicatif réel.

🔧 Compatible avec la nouvelle architecture SFML 3.0.2 (remplacement des sf::RenderWindow, gestion modernisée des événements et textures, etc.).

## 🧩 Objectifs pédagogiques

Approfondir la programmation orientée objet en C++

Comprendre et implémenter les fondements mathématiques 2D / 3D

Utiliser des templates génériques et des assertions statiques (static_assert)

Concevoir un code modulaire, réutilisable et testé

Intégrer une logique mathématique à une application interactive (SFML 3.0.2)

## 🧠 Technologies et paradigmes utilisés

C++17 moderne : RAII, templates, exceptions, assertions statiques

Programmation mathématique : géométrie, trigonométrie, interpolation, normalisation

SFML 3.0.2 : rendu 2D, gestion du temps, entrées et affichage modernisés

Microsoft CppUnitTest : validation unitaire et fiabilité

Architecture claire : séparation logique entre Maths et Demo
  
## 📂 Structure du projet
  
📁 Maths-Library  
┣ 📂 include  
┃ ┣ 📜 Vector2D.h / Vector2D.inl  
┃ ┣ 📜 Vector3D.h / Vector3D.inl  
┃ ┣ 📜 Quaternions.h / Quaternions.inl  
┃ ┣ 📜 Matrice3x3.h / Matrice3x3.inl  
┃ ┣ 📜 Matrice4x4.h / Matrice4x4.inl  
┃ ┣ 📜 MathsLib.h  
  
📁 Pong  
┃ ┣ 📜 Game.h / Game.cpp  
┃ ┣ 📜 Ball.h / Ball.cpp  
┃ ┣ 📜 Player.h / Player.cpp  
┃ ┣ 📜 Map.h / Map.cpp  
┃ ┣ 📜 Main.cpp (démo SFML Pong)  
  
📁TestUnitaire  
┃ ┣ 📜 Vct2DTest.cpp  
┃ ┣ 📜 Vct3DTest.cpp  
┃ ┣ 📜 Matrice3x3Test.cpp  
┃ ┣ 📜 QuatTest.cpp  
┃ ┣📜 Matrice4x4Test.cpp  
  
📜 README.md  
📜 CMakeLists.txt
