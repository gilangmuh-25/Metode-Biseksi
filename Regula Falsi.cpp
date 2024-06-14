#include <iostream>
#include <cmath>

float fungsi (float x)
{
    float f;
    /////////////////////////////
    //f = (x*exp(-x))+1;//fungsi persamaan
    f = pow(x,2)-(5*x)+4;//fungsi persamaan
    /////////////////////////////
    return f;
}

void iterasi(float *batas_bawah_iterasi, float *batas_atas_iterasi, float konvergen, int iterasi)
{
    float f_a, f_b, c_, f_c, error;

    //nilai awal iterasi
    f_a = fungsi (*batas_atas_iterasi);
    f_b = fungsi (*batas_bawah_iterasi);


    //looping iterasi
    for (int i = 1; i <= iterasi; i ++)
    {
        std::cout << "iterasi ke : " << i << std::endl;
        std::cout << "nilai batas bawah : " << *batas_bawah_iterasi << std::endl;
        std::cout << "nilai batas atas : " << *batas_atas_iterasi << std::endl;
        std::cout << "nilai fa : " << f_a << std::endl;
        std::cout << "nilai fb : " << f_b << std::endl;
        if (f_a * f_b <0)
        {
            c_ = (((*batas_atas_iterasi)*(f_b))-((*batas_bawah_iterasi)*(f_a)))/((f_b)-(f_a));
            f_c = fungsi (c_);
        }
        else
        {
            std::cout << "Ubah Batas" << std::endl;
            break;
        }
        std::cout << std::endl;
        //menghitung error iterasi
        error = std::abs((f_c));
        std::cout << "nilai c : " << c_ << ", nilai f(c) :" << f_c << ", error :" << error << std::endl;
        std::cout << std::endl;

        if (error < konvergen)
        {
            std::cout << "solusi konvergen" << std::endl;
            break;
        }
        //update nilai x dan fx baru
        else
        {
            if (f_c * f_a > 0)
            {
                *batas_atas_iterasi = c_;
            }
            else if (f_c * f_b > 0)
            {
                *batas_bawah_iterasi = c_;
            }
        }
        f_a = fungsi (*batas_atas_iterasi);
        f_b = fungsi (*batas_bawah_iterasi);
    }
}

int main()
{
    float batas_bawah, batas_atas, konvergen;
    int jumlah_iterasi;
    //////////////////////////////////////
    batas_bawah = 2;// input batas bawah
    batas_atas = 5;// input batas atas
    jumlah_iterasi = 100;// jumlah iterasi
    konvergen = 0.001;// residual konvergen
    //////////////////////////////////////

    iterasi(&batas_bawah, &batas_atas, konvergen, jumlah_iterasi);

    return 0;
}
