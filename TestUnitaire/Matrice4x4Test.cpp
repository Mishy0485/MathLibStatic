#include "CppUnitTest.h"
#include "Matrice4x4.h"
#include "Vector3D.h"



using namespace Maths;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace TestUnitaire
{
    TEST_CLASS(TestMath4)
    {
    public:


        TEST_METHOD(TestConstructeur)
        {
            Matrix4<float> m;
            for (int i = 0; i < 4; ++i)
                for (int j = 0; j < 4; ++j)
                    Assert::AreEqual(0.0f, m.at(i, j));
        }
        TEST_METHOD(TestIdentity4x4)
        {
            Matrix4<float> m = Matrix4<float>::identity4x4();
            for (int i = 0; i < 4; ++i)
                for (int j = 0; j < 4; ++j)
                    Assert::AreEqual(i == j ? 1.0f : 0.0f, m.at(i, j));

        }
        TEST_METHOD(TestZero4x4)
        {
            Matrix4<float> m = Matrix4<float>::zero4x4();
            for (int i = 0; i < 4; ++i)
                for (int j = 0; j < 4; ++j)
                    Assert::AreEqual(0.0f, m.at(i, j));
        }

        TEST_METHOD(TestPrintMatrix4x4)
        {
            Matrix4<float> m{
            1, 2, 3, 4,
            5, 6, 7, 8,
            2, 6, 4, 8,
            3, 1, 1, 2
            };
            float det = m.determinant4x4();
            Assert::AreEqual(72.0f, det, 0.0001f);
        }
        TEST_METHOD(TestDeterminant4x4)
        {
            Matrix4<float> m(1, 2, 3, 4,
                5, 6, 7, 8,
                2, 6, 4, 8,
                3, 1, 1, 2);
            float det = m.determinant4x4();
            Assert::AreEqual(72.0f, det, 0.0001f);
        }
        TEST_METHOD(TestInverse4x4)
        {
            Matrix4<float> m(4, 7, 2, 0,
                3, 6, 1, 0,
                2, 5, 3, 0,
                0, 0, 0, 1);

            std::array<float, 16> invArray = m.inverse4x4();

            Matrix4<float> inv;
            for (int i = 0; i < 4; ++i)
                for (int j = 0; j < 4; ++j)
                    inv.at(i, j) = invArray[i * 4 + j];

            Matrix4<float> result = m * inv;

            Assert::IsTrue(result.isIdentity4x4());
        }
        TEST_METHOD(TestIsIdentity4x4)
        {
            Matrix4<float> m = Matrix4<float>::identity4x4();
            Assert::IsTrue(m.isIdentity4x4());

            m.at(0, 1) = 5.0f;
            Assert::IsFalse(m.isIdentity4x4());
        }

        TEST_METHOD(TestTranspose4x4)
        {
            Matrix4<float> m = {
                1, 2, 3, 4,
                5, 6, 7, 8,
                9, 10, 11, 12,
                13, 14, 15, 16
            };

            auto t = m.transpose4x4(m);

   
            Assert::AreEqual(m.at(1, 0), t[1 * 4 + 0]);
            Assert::AreEqual(m.at(2, 3), t[2 * 4 + 3]);
            Assert::AreEqual(m.at(0, 0), t[0 * 4 + 0]);
            Assert::AreEqual(m.at(3, 3), t[3 * 4 + 3]);
        }


        TEST_METHOD(TestGetColumn4x4)
        {
            Matrix4<float> m = {
                   1, 2, 3, 4,
                   5, 6, 7, 8,
                   9, 10, 11, 12,
                   13, 14, 15, 16
            };

            std::stringstream buffer;
            std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

            m.getColumn4x4(2);

            std::cout.rdbuf(oldCout);

            std::string output = buffer.str();
            std::string expected = "3 7 11 15 \n";
            Assert::AreEqual(expected, output);
        }


        TEST_METHOD(TestGetRow4x4)
        {
            Matrix4<float> m = {
        1, 2, 3, 4,
        5, 6, 7, 8,
        9, 10, 11, 12,
        13, 14, 15, 16
            };

            std::stringstream buffer;
            std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

            m.getRow4x4(1);

            std::cout.rdbuf(oldCout);

            std::string output = buffer.str();
            std::string expected = "5 6 7 8 \n"; 
            Assert::AreEqual(expected, output);
        }
        TEST_METHOD(TestMultiplyPoint4x4)
        {
            Matrix4<float> A = Matrix4<float>::identity4x4();
            Matrix4<float> B = {
                1, 2, 3, 4,
                5, 6, 7, 8,
                9, 10, 11, 12,
                13, 14, 15, 16
            };
            Matrix4<float> result = A * B;
            for (int i = 0; i < 4; ++i)
                for (int j = 0; j < 4; ++j)
                    Assert::AreEqual(B.at(i, j), result.at(i, j));
        }

        TEST_METHOD(TestSetColumn4x4)
        {
            Matrix4<float> m = Matrix4<float>::zero4x4();
            m.setColumn4x4(1, 1, 2, 3, 4);
            Assert::AreEqual(1.0f, m.at(0, 1));
            Assert::AreEqual(2.0f, m.at(1, 1));
            Assert::AreEqual(3.0f, m.at(2, 1));
            Assert::AreEqual(4.0f, m.at(3, 1));
        }


        TEST_METHOD(TestScale4x4)
        {
            Vct3D<float> scale(2, 3, 4);
            Matrix4<float> s = Matrix4<float>::scale4x4(scale);
            Assert::AreEqual(2.0f, s.at(0, 0));
            Assert::AreEqual(3.0f, s.at(1, 1));
            Assert::AreEqual(4.0f, s.at(2, 2));
        }


        TEST_METHOD(TestTranslate4x4)
        {
            Vct3D<float> pos(5, -3, 2);
            Matrix4<float> t = Matrix4<float>::translate4x4(pos);
            Assert::AreEqual(5.0f, t.at(0, 3));
            Assert::AreEqual(-3.0f, t.at(1, 3));
            Assert::AreEqual(2.0f, t.at(2, 3));
        }


        TEST_METHOD(TestTRS4x4noRota)
        {
           
            Vct3D<float> pos(1.0f, 2.0f, 3.0f);
            Vct3D<float> rot(0.0f, 0.0f, 0.0f);
            Vct3D<float> scale(2.0f, 2.0f, 2.0f);

            Matrix4<float> m = Matrix4<float>::TRS4x4(pos, rot, scale);

           
            Assert::AreEqual(2.0f, m.at(0, 0), 1e-5f);
            Assert::AreEqual(2.0f, m.at(1, 1), 1e-5f);
            Assert::AreEqual(2.0f, m.at(2, 2), 1e-5f);
            
            Assert::AreEqual(1.0f, m.at(0, 3), 1e-5f);
            Assert::AreEqual(2.0f, m.at(1, 3), 1e-5f);
            Assert::AreEqual(3.0f, m.at(2, 3), 1e-5f);
           
            Assert::AreEqual(1.0f, m.at(3, 3), 1e-5f);
        }
        TEST_METHOD(TestTRS4x4_Rota)
        {
            Vct3D<float> pos(0.0f, 0.0f, 0.0f);

            const float pi = 3.14159265358979f;
            Vct3D<float> rot(0.0f, 0.0f, pi / 2.0f);
            Vct3D<float> scale(1.0f, 1.0f, 1.0f);

            Matrix4<float> m = Matrix4<float>::TRS4x4(pos, rot, scale);

            Assert::AreEqual(0.0f, m.at(0, 0), 1e-4f);
            Assert::AreEqual(-1.0f, m.at(0, 1), 1e-4f);
            Assert::AreEqual(1.0f, m.at(1, 0), 1e-4f);
            Assert::AreEqual(0.0f, m.at(1, 1), 1e-4f);
            Assert::AreEqual(1.0f, m.at(2, 2), 1e-4f);
            Assert::AreEqual(1.0f, m.at(3, 3), 1e-4f);
        }

        TEST_METHOD(TestOperatorMultiplication)
        {
            Matrix4<float> a = Matrix4<float>::identity4x4();
            Matrix4<float> b = Matrix4<float>::identity4x4();
            Matrix4<float> c = a * b;
            Assert::IsTrue(c.isIdentity4x4());
        }


        TEST_METHOD(TestValidTRS4x4)
        {
            Vct3D<float> t(1, 2, 3);
            Vct3D<float> r(0, 0, 0);
            Vct3D<float> s(1, 1, 1);

            Matrix4<float> m = Matrix4<float>::TRS4x4(t, r, s);
            Assert::IsTrue(m.validTRS4x4());
        }


        TEST_METHOD(TestLookAt4x4)
        {
            Vct3D<float> from(0, 0, 0);
            Vct3D<float> to(0, 0, 1);
            Vct3D<float> up(0, 1, 0);

            Matrix4<float> view = Matrix4<float>::lookAt4x4(from, to, up);
            Assert::IsFalse(view.isIdentity4x4());
        }


        TEST_METHOD(TestOrtho4x4)
        {
            Matrix4<float> m = Matrix4<float>::ortho4x4(-1, 1, -1, 1, 0.1f, 10.0f);
            Assert::AreEqual(1.0f, m.at(0, 0), 0.001f);
            Assert::AreEqual(1.0f, m.at(1, 1), 0.001f);
        }


        TEST_METHOD(TestPerspective4x4)
        {
            Vct3D<float> from(0, 0, 0);
            Vct3D<float> to(0, 0, 1);
            Vct3D<float> up(0, 1, 0);
            Matrix4<float> view = Matrix4<float>::lookAt4x4(from, to, up);
            Assert::IsFalse(view.isIdentity4x4());

            Matrix4<float> persp = Matrix4<float>::perspective4x4(60.0f, 1.0f, 0.1f, 100.0f);
            Assert::AreNotEqual(0.0f, persp.at(0, 0));
        }
        TEST_METHOD(TestRotate4x4)
        {
            float angle = 3.14159265f / 2.0f;

            Quat<float> q;
            q.Angle(angle, 0.0f, 0.0f, 1.0f); 


            Matrix4<float> r = Matrix4<float>::rotate4x4(q);

            Assert::AreEqual(0.0f, r.at(0, 0), 0.0001f);
            Assert::AreEqual(-1.0f, r.at(0, 1), 0.0001f);
            Assert::AreEqual(1.0f, r.at(1, 0), 0.0001f);
            Assert::AreEqual(0.0f, r.at(1, 1), 0.0001f);
            Assert::AreEqual(1.0f, r.at(2, 2), 0.0001f);
            Assert::AreEqual(1.0f, r.at(3, 3), 0.0001f);

            Vct3D<float> v(1, 0, 0);
            Vct3D<float> vRot = r.multiplyVector4x4(v);

            Assert::AreEqual(0.0f, vRot.GetX(), 0.001f);
            Assert::AreEqual(1.0f, vRot.GetY(), 0.001f);
            Assert::AreEqual(0.0f, vRot.GetZ(), 0.001f);
        }

        TEST_METHOD(TestSetRow4x4)
        {
            Matrix4<float> m = Matrix4<float>::zero4x4();
            m.setRow4x4(0, 1, 2, 3, 4);
            Assert::AreEqual(1.0f, m.at(0, 0));
            Assert::AreEqual(2.0f, m.at(0, 1));
            Assert::AreEqual(3.0f, m.at(0, 2));
            Assert::AreEqual(4.0f, m.at(0, 3));
        }
        TEST_METHOD(TestSetTRS4x4)
        {
            Vct3D<float> t(1, 2, 3);
            Vct3D<float> r(0, 0, 0);
            Vct3D<float> s(2, 2, 2);

            Matrix4<float> m = Matrix4<float>::setTRS4x4(t, r, s);

            
            Assert::AreEqual(2.0f, m.at(0, 0));
            Assert::AreEqual(2.0f, m.at(1, 1));
            Assert::AreEqual(2.0f, m.at(2, 2));

           
            Assert::AreEqual(1.0f, m.at(0, 3));
            Assert::AreEqual(2.0f, m.at(1, 3));
            Assert::AreEqual(3.0f, m.at(2, 3));
        }
        TEST_METHOD(TestMultiplyPoint3x4_4x4)
        {
            Matrix4<float> m = Matrix4<float>::translate4x4(1, 2, 3);
            Vct3D<float> v(1, 1, 1);
            Vct3D<float> p = m.multiplyPoint3x4_4x4(v);

            Assert::AreEqual(2.0f, p.GetX());
            Assert::AreEqual(3.0f, p.GetY());
            Assert::AreEqual(4.0f, p.GetZ());
        }
        TEST_METHOD(TestMultiplyVector4x4)
        {
            Matrix4<float> m = Matrix4<float>::scale4x4(2, 2, 2);
            Vct3D<float> v(1, 1, 1);
            Vct3D<float> res = m.multiplyVector4x4(v);
            Assert::AreEqual(2.0f, res.GetX());
            Assert::AreEqual(2.0f, res.GetY());
            Assert::AreEqual(2.0f, res.GetZ());
        }
        TEST_METHOD(TestMultiplyMatrix4x4)
        {
            Matrix4<float> A = Matrix4<float>::identity4x4();
            Matrix4<float> B = Matrix4<float>::scale4x4(2, 3, 4);
            Matrix4<float> result = A * B;
            Assert::AreEqual(2.0f, result.at(0, 0));
            Assert::AreEqual(3.0f, result.at(1, 1));
            Assert::AreEqual(4.0f, result.at(2, 2));
        }
        TEST_METHOD(TestAt)
        {
            Matrix4<float> m = Matrix4<float>::identity4x4();
            m.at(0, 1) = 5.0f;
            Assert::AreEqual(5.0f, m.at(0, 1));
        }
        TEST_METHOD(TestLossyScale4x4)
        {
            Matrix4<float> m = Matrix4<float>::scale4x4(2, 3, 4);
            Vct3D<float> scale = m.lossyScale4x4();
            Assert::AreEqual(2.0f, scale.GetX());
            Assert::AreEqual(3.0f, scale.GetY());
            Assert::AreEqual(4.0f, scale.GetZ());
        }
    };
}