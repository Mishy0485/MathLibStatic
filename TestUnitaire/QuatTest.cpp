#include "CppUnitTest.h"
#include "Quaternions.h"
#include "Vector3D.h"
#include <cmath>
#include <iostream>

using namespace Maths;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestUnitaire
{
    
    TEST_CLASS(TestQuaternions)
    {
    public:
        TEST_METHOD(TestConstructor)
        {
            Quat<float> q(1, 2, 3, 4);
            Assert::AreEqual(1.0f, q.GetW());
            Assert::AreEqual(2.0f, q.GetX());
            Assert::AreEqual(3.0f, q.GetY());
            Assert::AreEqual(4.0f, q.GetZ());

        }

        TEST_METHOD(TestSettersGetters)
        {
            Quat<float> q(0, 0, 0, 0);
            q.SetW(1); q.SetX(2); q.SetY(3); q.SetZ(4);
            Assert::AreEqual(1.0f, q.GetW());
            Assert::AreEqual(2.0f, q.GetX());
            Assert::AreEqual(3.0f, q.GetY());
            Assert::AreEqual(4.0f, q.GetZ());


        }
        TEST_METHOD(TestNormalization)
        {
            Quat<float> q(1, 2, 3, 4);
            Quat<float> n = q.normalized();
            float mag = std::sqrt(n.GetW() * n.GetW() + n.GetX() * n.GetX() + n.GetY() * n.GetY() + n.GetZ() * n.GetZ());
            Assert::AreEqual(1.0f, mag, 0.0001f);
        }

        TEST_METHOD(TestDot)
        {
            Quat<float> a(1, 0, 0, 0);
            Quat<float> b(0, 1, 0, 0);
            Assert::AreEqual(0.0f, a.Dot(b));
        }


        TEST_METHOD(TestMultiplication)
        {
            Quat<float> a(1, 0, 1, 0);
            Quat<float> b(1, 0.5f, 0.5f, 0.75f);
            Quat<float> result = a * b;
            Assert::AreEqual(0.5f, result.GetW(), 0.0001f);
        
        }
        TEST_METHOD(TestEquality)
        {
            Quat<float> a(1, 2, 3, 4);
            Quat<float> b(1, 2, 3, 4);
            Assert::IsTrue(a == b);
        }
        TEST_METHOD(TestLerp)
        {
            Quat<float> a(1, 0, 0, 0);
            Quat<float> b(0, 1, 0, 0);
            Quat<float> mid = a.Lerp(b, 0.5f);
            Assert::IsTrue(mid.GetW() > 0 && mid.GetX() > 0); // juste une v�rif simple
        }
        TEST_METHOD(TestSlerp)
        {
            Quat<float> a(1, 0, 0, 0);
            Quat<float> b(0, 1, 0, 0);
            Quat<float> mid = a.Slerp(b, 0.5f);
            Assert::IsTrue(mid.GetW() > 0 && mid.GetX() > 0);
        }
        TEST_METHOD(TestInverse)
        {

            Quat<float> q(1, 2, 3, 4);
            Quat<float> original = q; // Sauvegarde avant inversion
            q.Inverse();              // q devient son inverse

            // Produit q_original * q_inverse = identité
            Quat<float> identity = original * q;

            // Un quaternion identité a w = 1, x = y = z = 0
            Assert::AreEqual(1.0f, identity.GetW(), 0.0001f);
            Assert::AreEqual(0.0f, identity.GetX(), 0.0001f);
            Assert::AreEqual(0.0f, identity.GetY(), 0.0001f);
            Assert::AreEqual(0.0f, identity.GetZ(), 0.0001f);

        }
        TEST_METHOD(TestAngleAxis)
        {
            Quat<float> q(1, 0, 0, 0);
            Quat<float> axis;
            float angle;
            q.ToAngleAxis(angle, axis);
            Assert::AreEqual(0.0f, angle, 0.0001f);
        }
        TEST_METHOD(TestFromToRotation)
        {

            Quat<float> from(0, 1, 0, 0); // Vecteur Y
            Quat<float> to(0, 0, 0, 1);   // Vecteur Z

            from.setFromToRotation(to); // 'from' devient une rotation vers 'to'

            std::cout << "Result = (" << from.GetW() << ", " << from.GetX() << ", "
                << from.GetY() << ", " << from.GetZ() << ")\n";

            // Si tu veux tester un minimum de cohérence :
            Assert::IsTrue(std::abs(from.GetW()) <= 1.0f);
        }

        TEST_METHOD(TestRotateTowards)
        {
            Quat<float> a(1, 0, 0, 0);
            Quat<float> b(0, 1, 0, 0);
            a.RotateTowards(b, 45.0f);
            Assert::IsTrue(a.GetX() != 0 || a.GetY() != 0);
        }
        TEST_METHOD(TestLookRotation)
        {
            Quat<float> forward(0, 0, 1, 0);
            Quat<float> up(0, 1, 0, 0);
            Quat<float> q;
            q.LookRotation(forward, up);
            Assert::IsTrue(q.GetX() != 0 || q.GetY() != 0 || q.GetZ() != 0);
        }
        TEST_METHOD(TestEulerAngles)
        {
            Quat<float> q(1, 0, 0, 0);
            float pitch, yaw, roll;
            q.EuleurAngles(pitch, yaw, roll);
            Assert::AreEqual(0.0f, pitch, 0.0001f);
            Assert::AreEqual(0.0f, yaw, 0.0001f);
            Assert::AreEqual(0.0f, roll, 0.0001f);
        }


    
    };
}
