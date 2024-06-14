#include <iostream>
#include <cmath>

float fungsi (float x)
{
    float f;
    /////////////////////////////
    f = (x*exp(-x))+1;//fungsi persamaan
    /////////////////////////////
    return f;
}

void iterasi(float *batas_bawah_iterasi, float *batas_atas_iterasi, float *x_iterasi, float konvergen, int iterasi)
{
    float f_a, f_x, error;

    //nilai awal iterasi
    f_a = fungsi (*batas_bawah_iterasi);
    f_x = fungsi (*x_iterasi);

    //looping iterasi
    for (int i = 1; i <= iterasi; i ++)
    {
        std::cout << "iterasi ke : " << i << std::endl;
        std::cout << "nilai batas bawah : " << *batas_bawah_iterasi << std::endl;
        std::cout << "nilai batas atas : " << *batas_atas_iterasi << std::endl;
        std::cout << "nilai x : " << *x_iterasi <<  std::endl;
        std::cout << "nilai fx : " << f_x << std::endl;
        std::cout << "nilai fa : " << f_a << std::endl;
        if (f_x * f_a <0)
        {
            *batas_atas_iterasi = *x_iterasi;
            f_x = fungsi (*batas_atas_iterasi);
        }
        else
        {
            *batas_bawah_iterasi = *x_iterasi;
            f_a = fungsi (*batas_bawah_iterasi);
        }
        std::cout << std::endl;
        //menghitung error iterasi
        error = std::abs((*x_iterasi-((*batas_bawah_iterasi+*batas_atas_iterasi)/2))/(*x_iterasi));
        std::cout << "nilai x : " << *x_iterasi << ", error :" << error << std::endl;
        std::cout << std::endl;

        if (error < konvergen)
        {
            std::cout << "solusi konvergen" << std::endl;
            break;
        }
        //update nilai x dan fx baru
        else
        {
            *x_iterasi = (*batas_bawah_iterasi+*batas_atas_iterasi)/2;
            f_x = fungsi (*x_iterasi);
        }
    }
}

int main()
{
    float batas_bawah, batas_atas, x_init, konvergen;
    int jumlah_iterasi;
    //////////////////////////////////////
    batas_bawah = -57;// input batas bawah
    batas_atas = 84;// input batas atas
    jumlah_iterasi = 100;// jumlah iterasi
    konvergen = 0.000000001;// residual konvergen
    //////////////////////////////////////
    x_init = (batas_atas + batas_bawah)/2;
    iterasi(&batas_bawah, &batas_atas, &x_init, konvergen, jumlah_iterasi);

    return 0;
}
