//Nama      : Bagas Shalahuddin Wahid
//NIM       : 16420189
//Deskripsi : Program kalkulator

#include <iostream>
#include <windows.h>

using namespace std;

float penjumlahan(float bil1, float bil2);              //Deklarasi fungsi penjumlahan
float pengurangan(float bil1, float bil2);              //Deklarasi fungsi pengurangan
float perkalian(float bil1, float bil2);                //Deklarasi fungsi perkalian
float pembagian(float bil1, float bil2);                //Deklarasi fungsi pembagian
float perpangkatan(float bil1, float bil2);             //Deklarasi fungsi perpangkatan
float integral(float bil1, float bil2);                 //Deklarasi fungsi integral tentu dengan f(x) = x^2+x+1
void salah();                                           //Menampilkan pesan jika input yang dimasukkan salah
void judul();                                           //Menampilkan judul "CALCULATOR"
void garis();                                           //Menampilkan garis pembatas
void lokasixy(int x, int y);                            //Prosedur mengubah lokasi kursor

int main(){
    //Kamus
    int input,ulangi;
    float A,B;
    double delta;
    char operasi;
    string jenisoperasi[6]  = {"PENJUMLAHAN","PENGURANGAN","PERKALIAN","PEMBAGIAN","PERPANGKATAN","INTEGRAL TENTU"};
    string bentukoperasi[5] = {"A+B","A-B","AxB","A:B","A^B"};

    //Algoritma
    programawal: //program untuk memilih operasi yang akan dilakukan
    judul();
    cout << "\t\t|\t                   Pilih jenis operasi :                         |\n"
            "\t\t|\t                                                                 |\n"
            "\t\t|\t                     [1] PENJUMLAHAN                             |\n"
            "\t\t|\t                     [2] PENGURANGAN                             |\n"        //Pemilihan operasi.
            "\t\t|\t                     [3] PERKALIAN                               |\n"
            "\t\t|\t                     [4] PEMBAGIAN                               |\n"
            "\t\t|\t                     [5] PERPANGKATAN                            |\n"
            "\t\t|\t                     [6] INTEGRAL TENTU                          |\n"
            "\t\t|\t                                                                 |\n";
    cout <<"\t\t==========================================================================\n\n";
    cout << "\n\t\t\t                   Masukkan nomer pilihan : ";
    cin >> input;
    if (input>= 1 && input <= 6){
        system ("cls");
        program1:
        judul();
        cout << "\t\t                        Anda Memilih operasi " << jenisoperasi[input-1] << "\n";
        garis();
        if (input == 6){
            lokasixy(33,10);
            cout << "Test sample : Integral dari x^2+x+1"; lokasixy(33,12); // tes sampel : y = x^2+x+1
            cout << "Masukkan batas awal  (a) : ";
            cin >> A;lokasixy(33,13);
            cout << "Masukkan batas akhir (b) : ";
            cin >> B;lokasixy(0,15);
            garis();lokasixy(20,17);
            cout << "Hasil integral tentu dari x^2+x+1 pada selang [" << A << "," << B << "] " << ": " << integral(A,B) << "\n\n";
        }else{
            lokasixy(33,10);
            cout << "Apabila fungsi " << jenisoperasi [input-1] << " dilambangkan " << bentukoperasi[input-1]; lokasixy(33,12);
            cout << "Masukkan nilai A   : ";
            cin >> A;lokasixy(33,13);
            cout << "Masukkan nilai B   : ";
            cin >> B;lokasixy(0,15);
            garis();lokasixy(33,17);
            if (input == 1){
                cout << "Hasil operasi penjumlahan  : " << penjumlahan(A,B) << "\n\n";
            }else if(input ==2){
                cout << "Hasil operasi pengurangan  : " << pengurangan(A,B) << "\n\n";
            }else if(input ==3){
                cout << "Hasil operasi perkalian    : " << perkalian(A,B) << "\n\n";
            }else if(input ==4){
                cout << "Hasil operasi pembagian    : " << pembagian(A,B) << "\n\n";
            }else if(input ==5){
                cout << "Hasil operasi perpangkatan : " << perpangkatan(A,B) << "\n\n";
            }
        }
        garis();
        ulangiprogram:
        lokasixy(33,21);
        cout << "Tekan 1 untuk mengulangi operasi terakhir ";lokasixy(33,22);
        cout << "Tekan 2 untuk kembali ke menu awal";lokasixy(36,24);
        cout << "Masukkan nomer pilihan : ";
        cin >> ulangi;
            if (ulangi == 1){
                system ("cls");
                goto program1;
            }else if (ulangi == 2){
                system ("cls");
                goto programawal;
            }else{
                salah();
                goto ulangiprogram;
            }
    }else{
        salah();
        goto programawal;
    }

return 0;
}
float penjumlahan(float bil1, float bil2){ //Realisasi fungsi penjumlahan
    float hasil;
    hasil = bil1+bil2;
return hasil;
}
float pengurangan(float bil1, float bil2){ //Realisasi fungsi pengurangan
    //Kamus Lokal
    float hasil;
    //Algoritma
    hasil = bil1-bil2;
return hasil;
}
float perkalian(float bil1, float bil2){ //Realisasi fungsi perkalian
   //Kamus Lokal
    float hasil;
    //Algoritma
    hasil = bil1*bil2;
return hasil;
}
float pembagian(float bil1, float bil2){ //Realisasi fungsi pembagian
    //Kamus Lokal
    float hasil;
    //Algoritma
    hasil = bil1/bil2;
return hasil;
}
float perpangkatan(float bil1, float bil2){ //Realisasi fungsi perpangkatan
    //Kamus Lokal
    float hasil;
    //Algoritma
    hasil = bil1;
    for(int i=1;i<bil2;i++){
        hasil=hasil*bil1;
    }
return hasil;
}
float integral(float bil1, float bil2){ //Realisasi fungsi integral tentu y = x^2+x+1
    //Kamus Lokal
    float tinggi1,tinggi2,luaspartisi,luastotal;
    int N;
    double delta =0.0000001; //delta disini dibuat mendekati nol agar perhitungan integral melalui pendekatan riemann lebih akurat
                             /*Efek negatif dari delta yang semakin kecil adalah  jika rentang semakin besar, proses loop akan dilakukan
                                lebih banyak lagi. Hal ini memungkinkan nilai perhitungan yang diperoleh, di luar batas memori */
    //Algoritma
    N = (bil2-bil1)/delta;
    luastotal = 0;
    luaspartisi = 0;

    for (int i=0; i<N; i++){
        //Batas-batas trapesium.
        tinggi1=perpangkatan(bil1,2)+bil1+1;
        tinggi2=perpangkatan((bil1+delta),2)+(bil1+delta)+1;

        //Menghitung luas
        luaspartisi = (tinggi1+tinggi2)*0.5*delta;
        luastotal = luastotal + luaspartisi;

        bil1 = bil1+delta;
    }
return luastotal;
}
void judul(){               // Realisasi prosedur menampilkan judul
    cout <<"\t\t         _________    __    ________  ____    ___  __________  ____    \n"
           "\t\t        / ____/   |  / /   / ____/ / / / /   /   |/_  __/ __ \\/ __ \\ \n"
           "\t\t       / /   / /| | / /   / /   / / / / /   / /| | / / / / / / /_/ /   \n"
           "\t\t      / /___/ ___ |/ /___/ /___/ /_/ / /___/ ___ |/ / / /_/ / _  _/    \n"
           "\t\t      \\____/_/  |_/_____/\\____/\\____/_____/_/  |_/_/  \\____/_/ |_| \n\n"
           "\t\t==========================================================================\n";
}
void salah(){               // Realisasi prosedur menampilkan input salah
    cout << "\n\t\t\t\t\t       Input Anda salah";Sleep(1000);
    system("cls");
}
void garis(){               // Realisasi prosedur menampilkan garis pembatas
    cout << "\t===========================================================================================\n";
}
void lokasixy(int x, int y){ //Realisasi prosedur mengubah posisi kursor
    COORD kordinat;
    kordinat.X = x;
    kordinat.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), kordinat);
}
