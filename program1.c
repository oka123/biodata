#include <stdio.h>
#include <stdlib.h>

float evaluateExpression(const char* expression) {
    float result = 0;
    char operator = '+';
    char* end;

    while (*expression) {
        float number = strtof(expression, &end); // Mengambil angka dari string
        if (expression == end) {
            break; // Tidak ada angka yang ditemukan
        }

        // Lakukan operasi berdasarkan operator sebelumnya
        switch (operator) {
            case '+':
                result += number;
                break;
            case '-':
                result -= number;
                break;
            case '*':
                result *= number;
                break;
            case '/':
                result /= number;
                break;
        }

        // Update operator
        operator = *end;
        expression = end + 1; // Lanjutkan ke karakter berikutnya
    }

    return result;
}

// Fungsi untuk meminta input nilai dengan validasi
void inputNilai(char* jenis, float* nilai) {
    char input[100];
    printf("Input Nilai %s (misal: 60+1): \n", jenis);
    while (1) {
        fgets(input, sizeof(input), stdin); // Membaca input sebagai string
        *nilai = evaluateExpression(input); // Evaluasi ekspresi
        if (*nilai >= 0 && *nilai <= 100) {
            break; // Input valid
        } else {
            printf("Input salah, silahkan coba lagi\n");
        }
    }
}

int main() {
    char ulang;
    do {
        float tugas, uts, uas, total, rata;
        printf("Program Nilai \n===========\n");

        // Meminta input untuk Tugas, UTS, dan UAS
        inputNilai("Tugas", &tugas);
        inputNilai("UTS", &uts);
        inputNilai("UAS", &uas);

        printf("\n");

        // Menghitung total dan rata-rata
        total = tugas + uts + uas;
        printf("Total Nilai: %.2f \n", total);
        rata = (tugas + uts + uas) / 3;
        printf("Rataan: %.2f\n", rata);
        
        printf("Apakah ingin mengulang program? (y/t): ");
        scanf(" %c", &ulang);
        getchar(); // Menghapus newline dari input sebelumnya
    } while (ulang == 'y');
    
    return 0;
}