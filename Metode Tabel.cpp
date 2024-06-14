#include <iostream>
#include <cmath>
#include <array>

float fungsi (float x)
{
    float f;
    ///////////////////////////
    //f = (x*exp(-x))+1;//input persamaan
    f = sin(x)-x + (0.5*3.14159265);
    ///////////////////////////
    return f;
}

void fungsi_range (float *batas_bawah, float *batas_atas)
{
    float rentang, nilai_max, nilai_min;
    std::array <float,10> mat;
    std::array <float,10> mat_x;
    std::array <float,10> mat_inv;

    rentang = (*batas_atas - *batas_bawah)/10;
    //perhitungan fungsi berdasarkan batas yang telah ditentukan
    for(int i = 0; i <= 10; i ++)
        {
            mat_x[i] = *batas_bawah;
            std::cout << "nilai input : " <<*batas_bawah << ", ";
            mat[i] = fungsi(*batas_bawah);
            std::cout << "nilai output : " << mat[i] << std::endl;
            std::cout << std::endl;
            *batas_bawah += rentang;
        }

    //invers hasil untuk sortir batas baru
    for(int i = 0; i <= 10; i ++)
        {
            mat_inv[i] = 1/mat[i];
        }

    //menentukan batas atas dan bawah baru
    for (int i = 0; i <= 10; i ++)
        {
            if(nilai_max < mat_inv[i])
            {
                nilai_max = mat_inv[i];
                *batas_atas = mat_x[i];
            }
            else if (nilai_min > mat_inv[i])
            {
                nilai_min = mat_inv[i];
                *batas_bawah = mat_x[i];
            }
        }
}

int main()
{
    float batas_bawah_initial, batas_atas_initial, residual;
    int iterasi;
    ///////////////////////////////////////////////////////////
    batas_bawah_initial = -500; //input batas bawah
    batas_atas_initial = 500; // input batas atas
    iterasi = 20; //input jumlah iterasi
    residual = 0.000001;//residual
    ///////////////////////////////////////////////////////////
    for(int i = 1; i <= iterasi; i ++)
    {
        std::cout << "iterasi ke : " << i << std::endl;
        fungsi_range (&batas_bawah_initial, &batas_atas_initial);
        if (fungsi(batas_atas_initial) < 0 || fungsi(batas_bawah_initial) > 0)
        {
            std::cout << "batas atas : " << batas_atas_initial << ", error : " << fungsi(batas_atas_initial) << std::endl;
            std::cout << "batas bawah : " << batas_bawah_initial << ", error : " << fungsi(batas_bawah_initial) << std::endl;
            std::cout << "solusi berhenti, batas diluar range penyelesaian";
            break;
        }
        else if ((fungsi(batas_atas_initial)-fungsi(batas_bawah_initial))/2 < residual)
        {
            std::cout << "batas atas : " << batas_atas_initial << ", error : " << fungsi(batas_atas_initial) << std::endl;
            std::cout << "batas bawah : " << batas_bawah_initial << ", error : " << fungsi(batas_bawah_initial) << std::endl;
            std::cout << "nilai x : " <<  (batas_atas_initial + batas_bawah_initial)/2 << std::endl;
            std::cout << "solusi konvergen";
            break;
        }
        else
        {
            std::cout << "batas atas : " << batas_atas_initial << ", error : " << fungsi(batas_atas_initial) << std::endl;
            std::cout << "batas bawah : " << batas_bawah_initial << ", error : " << fungsi(batas_bawah_initial) << std::endl;
            std::cout << std::endl;
        }
    }

    return 0;
}

