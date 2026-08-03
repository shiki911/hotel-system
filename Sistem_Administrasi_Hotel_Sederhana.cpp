/*
README
The Current Results is basically our team's resort to finish this sooner.
And we hope so with our souls :D

Team =
- DS [Leader] 
- A
- SL (shiki911)

Tugas Besar Praktikum Daspro

- To look Syntax -
1. Enum = Basically data type that stores 1,2 or 3, to some letters. Let's say enum State status = SUCCES. then I can do if (status == SUCEES);
2. Ternary = if, but shorter. Goes like printf(" %s " (umur == 18) ? "Dewasa" : "Anak-Anak"); Dewasa is the umur is (or true) 18 and Anak-anak is false (bellow)
3. typedef = buch of variable packed into a single row
4. #define = A way to store a number (const) without Variable
5. sprintf = the same as printf, but instead of showing. It saves it into a variablle, ex sprintf(var, "911 %s", (year == 2001) ? "GET OU-" : "Yearly);
6. Input validation (the heck is cek != 1 and cek = scanf("%d", input).
	= So, the Cek is a variable that cek the input, which is scanf. It checks if the input is int. Which resulting in 1, and 0 if not. Thus Cek != 1
7. Special value = 3 (Sarapan, Which contains "NONE") 

Account admin (preset) :
username : admin
passcode : 123

note from the coder(s) :
"Yeah we know this code isn't anywhere near good,
Especially our way on using enum. Which only flags (hope for now tho).
So, We hope that you'd give a full feedback. We are OPEN for any feedbacks!"

*/

//Deklrasi Idk
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

//enum
enum State {
	SUCCESS,
	FAILED
};

enum Bool {
	YA,
	TIDAK,
	KELUAR,
	FASILITAS,
	SARAPAN
};

enum Room_Type {
	STANDARD,
	DELUXE,
	ULTRA_PRO
};

enum Room_State {
	EMPTY,
	BOOKED,
	MAINTENANCE,
	NOT_MAINTENANCE,
	IN_USE
};

enum Payment {
	NOT_PAID,
	PAID,
	NO_ORDER
};

//Fungsi Prototype
void header(int opsi); // Tulisan Header per opsi
void garis(); // =======
void clr_layar(); // clr
void point(); // >
void kosong(); //Space
void klik_enter(); //Klik Enter untuk kembali;
void list_kamar(int show); //List kamar
void is_system(); //Tulisan sistem bewarna hijau
void processing(int value); //Loading tiap input
void TitikTitik(); //...

int sistem_input_int (int min, int max, char *msg); // Sistem Input integer yang akan mengembalikan angka jika benar, dan ulang jika salah

void status_kamar (int room_no, enum Room_State stat); //Fungsi status kamar
void tipe_kamar (int room_no, enum Room_Type type); //Fungsi tipe kamar
void bayar_kamar (int room_no, enum Payment duid); //Fungsi toggle status bayar kamar

void set_warna(int warna); //Warna

void login(enum State status); //Status login, berhasil atau gagal

void auto_kamar(); //Kamar Otomatis Jalan Coding
void auto_admin(); //Tambah Admin awal
void auto_fasilitas(); //Pengisian Data Fasilitas
void auto_tier_sarapan(); //Pengisian Data Tier Sarapan

int menu_a(); //Menu awal

// Opsi 1
void booking();
void identitas();
void struk();
void set_kamar(int no_kamar, int malam, enum Room_State otw);
void extra_none(int no_kamar);
int opsi_kamar();
int input_malam();

// Opsi 4
void sistem_fasilitas();
void menu_fasilitas();
void sistem_sarapan(int room_no);
void sistem_fasilitas2(int room_no);
void pilih_fasilitas(int nomor_fasilitas);
void pilih_sarapan(int nomor_tier);
int tampil_ruang();
int opsi();
int sarapan(int room_no);
int fasilitas(int room_no);
int pilih_kamar();

// Opsi 5
void pembayaran_system();
void pembayaran();
void reset_order();

// Opsi 6
void admin_system();

void admin_1();
void set_maintenance();
void unset_maintenance();

void admin_2();
int tambah_kamar();
void penambahan(int kamar, int tipe);

void admin_3();

void admin_4();

int admin_menu();
int admin_log();

// Define
#define MAX_KAMAR 100 //Maksimal Kamar
#define MAX_KONSUMER 999 //Maksimal Konsumer

// Struct Kamar
typedef struct {
	int bayar; //0, 1 dan 2
	int harga; //Harga
	int pilih; //Akan Menjadi 1 Ketika dipilih
	int malam; //Malam
	int nomor; //int Kamar
	int pass_kamar; //Passcode untuk isi kamar
	char tipe[100]; //STANDARD, DELUXE, ULTRA  PRO (Fudge U Apple)
	char status[100]; //EMPTY, BOOKED, MAINTENANCE
	char status_uang[100]; //-, NOT PAID, PAID
	bool kosong; //Apakah kamar kosong
	bool maintenance; //Apakah kamar Maintenance
} kamar;

typedef struct{
	bool pil_fasilitas[4];
	int fasilitas_;
	int tier_sarapan;
} pilih;

// Struct Fasilitas
typedef struct {
	char nama[50]; //Nama Fasilitas
	int harga; //Harga per nambah Fasilitas
	bool pilih;
} fasilitasi;

// Struct Tier Sarapan
typedef struct {
	char tier[50]; //Nama Tier Sarapan
	int harga; //Harga Tier sarapan
	bool pilih;
} sarapani;

// Struct Kostumer
typedef struct {
	int pesanan;
	int fasilitas;
	int harga_tamu; //Harga yang dipakai ketika dibayar oleh tamu
	bool memesan;
	
	int id_konsumer;
} pesanan;

typedef struct {
	char nama[100];
	char nik[99];
	char hp[99];
	bool privasi;
} costumer;

// Struct Admin
typedef struct {
	char username[100];
	int passcode;
} admin;

//Variable Global - 1
kamar daftar_kamar[MAX_KAMAR]; //Array Struct
costumer data_konsumer[MAX_KONSUMER]; //Array Struct
pilih extra_kamar[MAX_KAMAR];
fasilitasi data_fasilitasi[5]; //Array Struct
sarapani data_sarapani[5];
pesanan dipilih; //Pesanan kostumer
admin detail;  //detail admin
int jumlah_konsumer = 0; //Jumlah konsumer
int jumlah_kamar = 0; //Jumlah kamar
int pil_pes[MAX_KAMAR]; //Pilihan Pesanan
int pil_fas[MAX_KAMAR];
bool no_fas;
int pil_tier;

//Fungsi Utama
//Guess I was the one who made the whole system
int main (){
	//Otomatis Buat Kamar 5
	auto_kamar();
	
	//Otomatis tambah admin awal
	auto_admin();
	
	//Otomastis tambah data fasiitas
	auto_fasilitas();
	
	//Otomatis tambah data sarapan
	auto_tier_sarapan();
	
	while (true) {
		
		int pilihan = menu_a();
	
		switch(pilihan){
			case 1 :  //Booking
				processing(1);
				booking();
				break;
			case 2 : //Waiting List
				processing(1);
				list_kamar(2);
				break;
			case 3 : //Status Kamar
				processing(1);
				list_kamar(3);
				break;
			case 4 : //Pelayanan & Fasilitas
				processing(1);
				sistem_fasilitas();
				break;
			case 5 : //Pembayaran & Checkout
				processing(1);
				pembayaran_system();
				break;
			case 6 : //Manajemen (Admin)
				int log;
				enum State kondisi;
				
				processing(1);
				
				log = admin_log();
				
				kondisi = (log == 1) ? SUCCESS : FAILED; //Ternary
				
				if (kondisi == SUCCESS){
					admin_system();
				} else {
					clr_layar();
						
					is_system();
						
					printf("REVERTING TO MENU ");
					TitikTitik();
				}
				break;
			case 0 :
				processing(1);
				printf("Sampai Jumpa Lagi!");
				Sleep(2000);
				klik_enter();
				break;
		}
	}
	
	return 0;	
}

//Menu Awal
int menu_a(){
	int pilihan;
	char not_valid[50] = "";
	
	do {
		clr_layar();
		
		header(1);
		kosong();
		
		printf(" 1. Booking Kamar\n");
		printf(" 2. Waiting List\n");
		printf(" 3. Status Kamar\n");
		printf(" 4. Pelayanan & Fasilitas\n");
		printf(" 5. Pembayaran & Checkout\n");
		printf(" 6. Manajemen (ADMIN ONLY)\n");
		printf(" 0. Keluar\n");
		kosong();
		garis();
		kosong();
		
		printf("%s", not_valid);
		
		printf(" Masukan pilihan Anda :\n");
		point();
		
		pilihan = sistem_input_int (0, 6, not_valid);
	} while (pilihan < 0 || pilihan > 6);
	
	clr_layar();
	return pilihan; 
}

// Case 1 (Booking Kamar) :
int opsi_kamar(){
	int pilihan;
	bool dipakai = false;
	char not_valid[50] = "";
	
	do {
		header(6);
		
		printf("%s",not_valid);
				
		printf(" Silahkan pilih Kamar yang akan dipakai :\n");
		
		point();
		pilihan = sistem_input_int (0, jumlah_kamar, not_valid);
		
		if (pilihan == 0) return 0;
			
		if (pilihan < 1 || pilihan > jumlah_kamar){
			dipakai = true;
		} else if (!daftar_kamar[pilihan - 1].kosong){
			sprintf(not_valid, " Kamar sudah diBooking\n Silahkan Pilih lagi\n");
			dipakai = true;
		} else if (daftar_kamar[pilihan - 1].maintenance){
			sprintf(not_valid, " Kamar sedang Maintenance\n Silahkan Pilih lagi\n");
			dipakai = true;
		} else {
			dipakai = false;
		}
	} while (pilihan < 0 || pilihan > jumlah_kamar || dipakai == true);
	
	return pilihan;
}

void booking(){
	char kunci = 'y';
	int pilihan;
	int malam;
	int i;
	
	do {
		do {
			do {
				clr_layar();
			
				pilihan = opsi_kamar();
			
				if (pilihan == 0){
					break;
				}
			
				clr_layar();
				processing(2);
			
				
				do {
					kunci = 'y';
					
					garis();
					printf("\tKamar yang dipilih : %d\n",daftar_kamar[pilihan - 1].nomor);
					garis();
		
					kosong();
					if ((kunci != 'Y' && kunci != 'y') && (kunci != 'T' && kunci != 't')){
						printf(" Tidak Valid, Masukan Lagi\n");
					}
					
					printf(" Yakin memilih Kamar ini? (Y/T) :\n");
					point();
					scanf(" %c",&kunci);
					
					clr_layar();
				} while ((kunci != 'Y' && kunci != 'y') && (kunci != 'T' && kunci != 't'));
				
				if (kunci == 'T' || kunci == 't'){
					processing(4);
				}		
			} while (kunci == 'T' || kunci == 't');
		
			if (pilihan == 0){
				break;
			}
		
			processing(3);
			
			malam = input_malam();
			
			set_kamar(pilihan - 1, malam, BOOKED);
	
			dipilih.pesanan++;
			pil_pes[dipilih.pesanan - 1] = pilihan - 1;
			
			processing(5);
		
			kunci = 'y';
		
			garis();
			printf("\tBERHASIL!\n");
			printf(" Pesanan Anda telah dimasukan ke Sistem\n");
			garis();
			kosong();
			
			do {
				if ((kunci != 'Y' && kunci != 'y') && (kunci != 'T' && kunci != 't')){
					printf(" Tidak Valid, Masukan Lagi\n");
				}
				
				printf(" Tambah pesanan? (Y/T) :\n");
				point();
				scanf(" %c",&kunci);
			} while ((kunci != 'Y' && kunci != 'y') && (kunci != 'T' && kunci != 't'));
		} while (pilihan == 0);
	} while ((kunci == 'Y' || kunci == 'y') && pilihan != 0);
	
	clr_layar();
	
	if (pilihan != 0){
		header(3);
	
		if (dipilih.pesanan > 1){
			for(i = 0; i < dipilih.pesanan; i++){
				printf(" %02d. Kamar : %d\n",i + 1, daftar_kamar[pil_pes[i]].nomor);
				printf("     Malam : %03d\n\n",i + 1, daftar_kamar[pil_pes[i]].malam);
				extra_none (pil_pes[i]);
				
			}
		} else {
			printf(" Kamar : %d\n",daftar_kamar[pil_pes[0]].nomor);
			printf(" Malam : %03d\n\n",daftar_kamar[pil_pes[0]].malam);	
			extra_none (pil_pes[0]);		
		}
		
		dipilih.memesan = true;
	
		klik_enter();
	}
	
	clr_layar();
	processing(0); 
}

void extra_none (int no_kamar){
	no_fas = true;
	
    extra_kamar[no_kamar].tier_sarapan = 3;
    

    for (int e = 0; e < 4; e++) {
        extra_kamar[no_kamar].pil_fasilitas[e] = false;
    }
}

int input_malam (){
	char not_valid [50] = "";
	int malam;
	int cek;
	
	do {
		clr_layar();
		
		garis();
		printf(" Kamar siap diBooking\n");
		garis();
	
		kosong();
		
		printf("%s",not_valid);
		
		printf(" Berapa malam :\n");
		
		point();
		cek = scanf("%d",&malam);	
		
		if (cek != 1){
			sprintf(not_valid, " Harap masukan nomor\n Silahkan pilih lagi\n");
			while(getchar() != '\n');
		} else if (malam <= 0) {
			sprintf(not_valid, " Malam tidak bisa kurang atau sama dari 0\n");
		}
	} while (malam <= 0 || cek != 1);
	
	return malam;
}

void identitas(){
	char privasi = 'y';
	jumlah_konsumer++;
	
	dipilih.id_konsumer = jumlah_konsumer;
	
	printf(" Masukan Identitas Pemesan\n");
	
	kosong();
	
	printf(" Masukan Nama Anda :\n");
	point();
	
	scanf("%99s", data_konsumer[dipilih.id_konsumer].nama);
	
	kosong();
	
	printf(" Masukan NIK Anda :\n");
	point();
	scanf("%s", data_konsumer[dipilih.id_konsumer].nik);
	kosong();
	
	printf(" Masukan int Hp Anda :\n");
	point();
	scanf("%s", data_konsumer[dipilih.id_konsumer].hp);
	kosong();
	
	do {
		if ((privasi != 'Y' && privasi != 'y') && (privasi != 'T' && privasi != 't')){
			printf("Tidak Valid, Masukan lagi\n");
		}
	
		printf(" Jaminan Privasi? (Y/T) :\n");
		point();
		scanf(" %c",&privasi);
	} while ((privasi != 'Y' && privasi != 'y') && (privasi != 'T' && privasi != 't'));
	
	if(privasi == 'Y' || privasi == 'y'){
		data_konsumer[dipilih.id_konsumer].privasi = true;
		is_system();
		printf("MODE PRIVASI DINYALAKAN\n");
	} else {
		data_konsumer[dipilih.id_konsumer].privasi = false;
		is_system();
		printf("MODE PRIVASI TIDAK DINYALAKAN\n");
	}
}

void set_kamar(int no_kamar, int malam, enum Room_State otw) {
	if (otw == BOOKED){
		daftar_kamar[no_kamar].pilih = 1;
		strcpy(daftar_kamar[no_kamar].status, "BOOKED");
		daftar_kamar[no_kamar].malam = malam;
		daftar_kamar[no_kamar].kosong = false;
		dipilih.harga_tamu = (daftar_kamar[no_kamar].harga * malam) + dipilih.harga_tamu;
		bayar_kamar(no_kamar, NOT_PAID);		
	}
}

//Case 2 & 3 (List Kamar) :
//Made By : ANDREAN
void list_kamar(int show){
	switch (show){
		case 1 :
			garis();
			printf("  NO    KAMAR     TIPE     HARGA     STATUS\n");
			garis();
			kosong();
	
			for (int i = 0; i < jumlah_kamar; i++){
				if (strcmp(daftar_kamar[i].tipe, "STANDARD") == 0){
					printf("  %02d     %d    %s   $ %d     %s\n",i + 1, daftar_kamar[i].nomor, daftar_kamar[i].tipe, daftar_kamar[i].harga, daftar_kamar[i].status);
				} else if (strcmp(daftar_kamar[i].tipe, "DELUXE") == 0){
					printf("  %02d     %d     %s    $ %d     %s\n",i + 1, daftar_kamar[i].nomor, daftar_kamar[i].tipe, daftar_kamar[i].harga, daftar_kamar[i].status);
				} else {
					printf("  %02d     %d   %s  $ %d     %s\n",i + 1, daftar_kamar[i].nomor, daftar_kamar[i].tipe, daftar_kamar[i].harga, daftar_kamar[i].status);
				}
			}
			
			break;
			
		case 2 :
			garis();
			printf("  NO    KAMAR     TIPE     MALAM     STATUS\n");
			garis();
			kosong();
	
			for (int i = 0; i < jumlah_kamar; i++){
				char malam_str[100];
			
				if (daftar_kamar[i].malam == 0){
					sprintf(malam_str, " - ");
				} else {
					sprintf(malam_str, "%03d", daftar_kamar[i].malam);
				}
			
				if (strcmp(daftar_kamar[i].tipe, "STANDARD") == 0){
					printf("  %02d     %d    %s    %s      %s\n",i + 1, daftar_kamar[i].nomor, daftar_kamar[i].tipe, malam_str, daftar_kamar[i].status);
				} else if (strcmp(daftar_kamar[i].tipe, "DELUXE") == 0){
					printf("  %02d     %d     %s     %s      %s\n",i + 1, daftar_kamar[i].nomor, daftar_kamar[i].tipe, malam_str, daftar_kamar[i].status);
				} else {
					printf("  %02d     %d   %s   %s      %s\n",i + 1, daftar_kamar[i].nomor, daftar_kamar[i].tipe, malam_str, daftar_kamar[i].status);
				}
			}
		
			kosong();
			garis();
			kosong();
			klik_enter();
			break;
			
		case 3 :
			printf("===============================================================\n");
			printf("  NO    KAMAR     TIPE     MALAM     STATUS      PAID STATUS\n");
			printf("===============================================================\n");
			kosong();
	
			for (int i = 0; i < jumlah_kamar; i++){
				char malam_str[100];
			
				if (daftar_kamar[i].malam == 0){
					sprintf(malam_str, " - ");
				} else {
					sprintf(malam_str, "%03d", daftar_kamar[i].malam);
				}
			
				if (strcmp(daftar_kamar[i].tipe, "STANDARD") == 0){
					printf("  %02d     %d    %s    %s      %s",i + 1, daftar_kamar[i].nomor, daftar_kamar[i].tipe, malam_str, daftar_kamar[i].status);
				} else if (strcmp(daftar_kamar[i].tipe, "DELUXE") == 0){
					printf("  %02d     %d     %s     %s      %s",i + 1, daftar_kamar[i].nomor, daftar_kamar[i].tipe, malam_str, daftar_kamar[i].status);
				} else {
					printf("  %02d     %d   %s   %s      %s",i + 1, daftar_kamar[i].nomor, daftar_kamar[i].tipe, malam_str, daftar_kamar[i].status);
				}
				
				if (daftar_kamar[i].bayar == 0) {
					printf("        %s\n",daftar_kamar[i].status_uang);
				} else if (daftar_kamar[i].bayar == 1){
					printf("        %s\n",daftar_kamar[i].status_uang);
				} else if (daftar_kamar[i].bayar == 2){
					printf("        %s\n",daftar_kamar[i].status_uang);
				}  
			}
			
		
			kosong();
			printf("===============================================================\n");
			kosong();
			klik_enter();
			break;
			
	}
}

//Case 4 (Fasilitas dan Sarapan) :
void sistem_fasilitas(){
	header(5);
	
	if (dipilih.memesan == true){
		menu_fasilitas();
	} else {
		printf(" Anda belum memesan\n");
		printf(" Silahkan memesan terlebih dahulu.\n");
		klik_enter();
	}	
}

void menu_fasilitas(){
	enum Bool pilihan;
	int tampilan;
	int kamar_aktif;
	
	clr_layar();
	header(5);
	
	printf(" DETAIL :\n");
	printf(" Tempatmu untuk mengecek, mengganti\n");
	printf(" dan menambah :\n");
	printf(" Fasilitas & Sarapan\n");
	
	kosong();
	garis();
	kosong();
	
	tampilan = (tampil_ruang() == 0) ? YA : TIDAK;
	
	if (tampilan == YA){
		kamar_aktif = pil_pes[0];	
	} else if (tampilan == TIDAK){
		kamar_aktif = pilih_kamar();
	}
	
	int index = opsi();
	if (index == 0) return;
	
	if (index == 1){
		pilihan = FASILITAS;
	} else if (index == 2){
		pilihan = SARAPAN;
	}
		
	processing(1);
		
	if (pilihan == FASILITAS) {
		sistem_fasilitas2(kamar_aktif);
	} else if (pilihan == SARAPAN) {
		sistem_sarapan(kamar_aktif);
	}		
}

int tampil_ruang(){
	printf(" Kamar yang Anda pesan :\n");
	
	if (dipilih.pesanan > 1){
		return 1;
	} else {
		printf(" %d\n",daftar_kamar[pil_pes[0]].nomor);
		printf(" Klik Enter untuk menlanjutkan\n");
		point();
		getch();
		
		processing(1);
		return 0;
	}
}

int pilih_kamar(){
	int i;
	int pilihan;
	int indx_kamar;
	char not_valid[50] = "";
	
	do {
		for(int i = 0; i < dipilih.pesanan; i++){
			printf(" %02d. %d\n",i + 1, daftar_kamar[pil_pes[i]].nomor);
		}
	
		kosong();
		garis();
		kosong();
	
		printf("%s",not_valid);
	
		printf(" Pilih kamar :\n");
		point();
		pilihan = sistem_input_int(1, dipilih.pesanan, not_valid);
	} while (pilihan < 1 || pilihan > dipilih.pesanan);
	
	indx_kamar = pil_pes[pilihan - 1];
	
	printf("Yang dipilih : Kamar - %d",daftar_kamar[indx_kamar].nomor);
	getch();
	
	return indx_kamar;
}

int opsi(){
	int pilihan;
	char not_valid[50] = "";
	
	do {
		clr_layar();
		header(5);
	
		printf(" Silakan pilih\n");
		printf(" 1. Fasilitas\n");
		printf(" 2. Sarapan\n");
		printf(" 0. Keluar\n");
		kosong();
	
		garis();
		kosong();
		
		printf("%s", not_valid);
		
		printf(" Masukan pilihan Anda :\n");
		
		point();
		pilihan = sistem_input_int(0, 2, not_valid);
		
		if (pilihan == 0) return 0;
	} while (pilihan < 0 || pilihan > 2);
		
	return pilihan;		
}

void sistem_fasilitas2(int room_no){
	int fasil = 0;
	int i;
	char kunci = 'y';
	char not_valid[50] = "";
	
	do {
		fasil = fasilitas(room_no);
		
		if (fasil == 0) return;
		
		pil_fas [dipilih.fasilitas] = fasil - 1;
		dipilih.fasilitas++;
		
		extra_kamar[room_no].pil_fasilitas[fasil - 1] = true;
		
		if (dipilih.fasilitas > 1){
			printf("Fasilitas =\n");
			for (i = 0; i < dipilih.fasilitas; i++){
				printf(" %02d. %s\n", i + 1, data_fasilitasi[pil_fas[i]].nama);
			}			
		} else {
			printf("Fasilitas = %s\n", data_fasilitasi[pil_fas[0]].nama);
		}
		
		dipilih.harga_tamu = dipilih.harga_tamu + data_fasilitasi[fasil - 1].harga;
		
		no_fas = false;		
		
		printf("%s", not_valid);
		
		printf(" Apakah mau menambah Fasilitas (Y/T) :\n");
		point();
		scanf(" %c", &kunci);
		
		if ((kunci != 'Y' && kunci != 'y') && (kunci != 'T' && kunci != 't')){
			sprintf(not_valid, " Input Tidak valid\n Masukan Lagi\n");
		}
	} while (kunci == 'Y' || kunci == 'y');
	
	processing(0);
}

int fasilitas(int room_no){
	int pilihan;
	char not_valid[50] = "";
	
	do {
		clr_layar();
		
		garis();
		printf("\t Penambahan Fasilitas\n");
		garis();
		kosong();
	
		printf(" 1. Alat Mandi ($35) = %s\n",(extra_kamar[room_no].pil_fasilitas[0]) ? "IN USE" : "NOT USE");
		printf(" 2. Alat Tidur ($50) = %s\n",(extra_kamar[room_no].pil_fasilitas[1]) ? "IN USE" : "NOT USE");
		printf(" 3. Menja      ($25) = %s\n",(extra_kamar[room_no].pil_fasilitas[2]) ? "IN USE" : "NOT USE");
		printf(" 4. Kursi      ($20) = %s\n",(extra_kamar[room_no].pil_fasilitas[3]) ? "IN USE" : "NOT USE");
		kosong();
		printf(" 0. Kembali\n");
		
		kosong();
		printf(" Additional Charges will be applied.\n");
	
		kosong();
		garis();
		kosong();
		
		printf("%s", not_valid);
	
		printf(" Masukan pilihan Anda :\n");
		point();
		
		pilihan = sistem_input_int(0, 4, not_valid);
		
		if (pilihan == 0) break;
		
		if (extra_kamar[room_no].pil_fasilitas[pilihan - 1]){
			sprintf(not_valid, " Sudah dipilih\n Silahkan pilih yang lain\n");
		}
	} while (pilihan < 0 || pilihan > 4|| extra_kamar[room_no].pil_fasilitas[pilihan - 1]);
	
	processing(1);
	
	return pilihan;
}

void sistem_sarapan(int room_no){
	int sara;
	
	sara = sarapan(room_no);
	sara = sara - 1;
	
	printf("Sarapan yang Anda pilih :\n");
	printf("%s\n",data_sarapani[sara].tier);
	
	pil_tier = sara;
	
	extra_kamar[room_no].tier_sarapan = sara;
	dipilih.harga_tamu = dipilih.harga_tamu + data_sarapani[sara].harga;
	
	klik_enter();
}

int sarapan(int room_no){
	int pilihan;
	char not_valid[50] = "";
	
	do {
		clr_layar();
		
		garis();
		printf("\t Penambahan SARAPAN\n");
		garis();
		kosong();
	
		printf(" 1. Basic Tier    ($20) \n");
		printf(" 2. Metal Tier    ($40)\n");
		printf(" 3. Premium Tier  ($60)\n");
		printf(" 0. Kembali\n");
		
		kosong();
		printf(" Additional Charges will be applied.\n");
	
		kosong();
		garis();
		kosong();
		
		printf("%s", not_valid);
	
		printf(" Masukan pilihan Anda :\n");
		point();
		
		pilihan = sistem_input_int(0, 3, not_valid);
		
		if (pilihan == 0) break;
	} while (pilihan < 0 || pilihan > 3);
	
	processing(1);
	
	return pilihan;
}

//Case 5 (Pembayaran) :
void pembayaran_system(){
	header(4);
	
	if (dipilih.memesan == true){
		identitas();
		pembayaran();
	} else {
		printf(" Anda belum memesan\n");
		printf(" Silahkan memesan terlebih dahulu.\n");
		klik_enter();
	}
}

void pembayaran(){
	int i;
	
	processing(6);
	
	header (5);
	
	printf(" Nama    : %s\n",data_konsumer[dipilih.id_konsumer].nama);
	printf(" NIK     : %s\n",data_konsumer[dipilih.id_konsumer].nik);
	printf(" No Hp   : %s\n",data_konsumer[dipilih.id_konsumer].hp);
	printf(" Privasi : %s\n",(data_konsumer[dipilih.id_konsumer].privasi == true) ? "Ya" : "Tidak" );
	
	kosong();
	printf(" Kamar yang dipilih :\n");
	kosong();
	
	if (dipilih.pesanan > 1){
		for(i = 0; i < dipilih.pesanan; i++){
			printf(" %02d. Kamar : %d\n",i + 1, daftar_kamar[pil_pes[i]].nomor);
			printf("     Malam : %03d\n\n",daftar_kamar[pil_pes[i]].malam);
			printf("     Harga : $%d\n",daftar_kamar[pil_pes[i]].harga);
		}
	} else {
		printf("   Kamar : %d\n",daftar_kamar[pil_pes[0]].nomor);
		printf("   Malam : %03d\n",daftar_kamar[pil_pes[0]].malam);	
		printf("   Harga : $%d\n",daftar_kamar[pil_pes[0]].harga);
	}
	
	kosong();
	garis();
	printf("\t EXTRA MENU\n");
	garis();
	kosong();
	
	if (dipilih.pesanan > 1){
		printf(" Tier Sarapan :\n");
		
		for(int i = 0; i < dipilih.pesanan; i++){
			int room = pil_pes[i];
			int tier = extra_kamar[room].tier_sarapan;
			
			printf(" %02d. Kamar %d : %s\n", i + 1, daftar_kamar[room].nomor, data_sarapani[tier].tier);
			printf("     Harga     : $%03d\n", data_sarapani[tier].harga);
		}
	} else {
		int room = pil_pes[0];
		int tier = extra_kamar[room].tier_sarapan;
		
		printf(" Tier Sarapan : %s\n",data_sarapani[tier].tier);
		printf(" Harga        : $%03d\n",data_sarapani[tier].harga);		
	}

	kosong();
	
	if (!no_fas){	
		if (dipilih.fasilitas > 1){
			printf(" Fasilitas :\n");
			for (int i = 0; i < dipilih.fasilitas; i++){
				printf(" %02d.       : %s\n", i + 1, data_fasilitasi[pil_fas[i]].nama);
				printf("           : $%02d\n", data_fasilitasi[pil_fas[i]].harga);
			}			
		} else {		
			printf(" Fasilitas    : %s\n", data_fasilitasi[pil_fas[0]].nama);
			printf(" Harga        : $%02d\n", data_fasilitasi[pil_fas[0]].harga);
		}
	} else {
		printf(" Fasilitas    : NONE\n");
		printf(" Harga        : $00\n");
	}
		
	kosong();
	garis();
	kosong();
	
	printf(" Harga Total  : $%d\n",dipilih.harga_tamu);
	
	kosong();
	garis();
	kosong();
	
	printf("Klik Enter untuk membayar :\n");
	point();
	getch();
	
	is_system();
	printf("Membayar ");
	TitikTitik();
	
	printf("[");
	set_warna(10);
	printf("SUCCESS");
	set_warna(7);
	printf("] Pesanan telah dibayar\n");
	
	struk();
	
	reset_order();
	
	klik_enter();	
}

void struk(){
	is_system();
	printf("Memproses Struk ");
	TitikTitik();
	
	FILE *struk = fopen ("struk.txt","w");
	
	if (!struk) { printf("Error creating struk file.\n"); return; }
	
	fprintf (struk, "========================================\n");
	
	fprintf (struk, "\tSTRUK ANDA\n");
	
	fprintf (struk, "========================================\n");
	
	if (data_konsumer[dipilih.id_konsumer].privasi) {
		int len = strlen(data_konsumer[dipilih.id_konsumer].nama);
		
		fprintf (struk, " Nama    : %c", data_konsumer[dipilih.id_konsumer].nama[0]);
			
		for (int i = 0; i < len - 1; i++){
			fprintf (struk, "*");
		}
			
		fprintf (struk, "%c\n",data_konsumer[dipilih.id_konsumer].nama[len - 1]);	
		
		fprintf (struk, " NIK     : REDACTED\n");
		fprintf (struk, " No Hp   : REDACTED\n");
	} else {
		fprintf (struk, " Nama    : %s\n",data_konsumer[dipilih.id_konsumer].nama);
		fprintf (struk, " NIK     : %s\n",data_konsumer[dipilih.id_konsumer].nik);
		fprintf (struk, " No Hp   : %s\n",data_konsumer[dipilih.id_konsumer].hp);
	}
	
	fprintf (struk, "\n");
	fprintf (struk, " Kamar yang dipilih :\n");
	fprintf (struk, "\n");
	
	if (dipilih.pesanan > 1){
		for(int i = 0; i < dipilih.pesanan; i++){
			fprintf(struk, " %02d. Kamar : %d\n",i + 1, daftar_kamar[pil_pes[i]].nomor);
			fprintf(struk, "     Malam : %03d\n\n",i + 1, daftar_kamar[pil_pes[i]].malam);
			fprintf(struk, "     Harga : $%d\n",daftar_kamar[pil_pes[i]].harga);
		}
	} else {
		fprintf(struk, "   Kamar : %d\n",daftar_kamar[pil_pes[0]].nomor);
		fprintf(struk, "   Malam : %03d\n",daftar_kamar[pil_pes[0]].malam);	
		fprintf(struk, "   Harga : $%d\n",daftar_kamar[pil_pes[0]].harga);
	}
	
	fprintf (struk, "\n");
	fprintf (struk, "========================================\n");
	fprintf (struk, "\t EXTRA MENU\n");
	fprintf (struk, "========================================\n");
	fprintf (struk, "\n");
	
	if (dipilih.pesanan > 1){
		fprintf(struk, " Tier Sarapan :\n");
		
		for(int i = 0; i < dipilih.pesanan; i++){
			int room = pil_pes[i];
			int tier = extra_kamar[room].tier_sarapan;
			
			fprintf (struk, " %02d. Kamar %d : %s\n", i + 1, daftar_kamar[room].nomor, data_sarapani[tier].tier);
			fprintf (struk, "     Harga     : $%03d\n", data_sarapani[tier].harga);
		}
	} else {
		int room = pil_pes[0];
		int tier = extra_kamar[room].tier_sarapan;
		
		fprintf(struk, " Tier Sarapan : %s\n",data_sarapani[tier].tier);
		fprintf(struk, " Harga        : $%03d\n",data_sarapani[tier].harga);		
	}

	fprintf(struk, "\n");
	
	if (!no_fas){	
		if (dipilih.fasilitas > 1){
			fprintf (struk, " Fasilitas :\n");
			for (int i = 0; i < dipilih.fasilitas; i++){
				fprintf (struk, " %02d.       : %s\n", i + 1, data_fasilitasi[pil_fas[i]].nama);
				fprintf (struk, "           : $%02d\n", data_fasilitasi[pil_fas[i]].harga);
			}			
		} else {		
			fprintf (struk, " Fasilitas    : %s\n", data_fasilitasi[pil_fas[0]].nama);
			fprintf (struk, " Harga        : $%02d\n", data_fasilitasi[pil_fas[0]].harga);
		}
	} else {
		fprintf (struk, " Fasilitas    : NONE\n");
		fprintf (struk, " Harga        : $00\n");
	}
		
	fprintf (struk, "\n");
	fprintf (struk, "========================================\n");
	fprintf (struk, "\n");
	
	fprintf (struk, " Harga Total  : $%d\n",dipilih.harga_tamu);
	
	fprintf (struk, "\n");
	fprintf (struk, "========================================\n");
	fprintf (struk, "\n");
	
	fprintf (struk, "\t Telah dibayar Lunas !\n");
	fprintf (struk, "\t Terimakasih telah memilih\n");
	fprintf (struk, "\t HOTEL E\n");
	
	fprintf (struk, "\n");
	fprintf (struk, "========================================\n");
	
	is_system();
	printf("Struk telah dibuat\n");
	
	fclose(struk);
}

void reset_order(){
    for(int i=0; i<dipilih.pesanan; i++){
        int room = pil_pes[i];
        pil_pes[i] = 0;
        pil_fas[i] = 0;
        extra_kamar[room].tier_sarapan = 3;
        for(int j=0; j<4; j++){
            extra_kamar[room].pil_fasilitas[j] = false;
        }
    }
    dipilih.pesanan = 0;
    dipilih.fasilitas = 0;
    dipilih.memesan = false;
    dipilih.harga_tamu = 0;
}

//Case 6 (Admin) :
// Made by OUR LEADER, DIMAS
void login(enum State status){
	if (status == FAILED){
		printf("[");
	
		set_warna(12);
		printf("FAILED");
	
		set_warna(7);
		printf("] Login Gagal");
	
		getch();
	} else {
		printf("[");
	
		set_warna(10);
		printf("SUCCESS");
	
		set_warna(7);
		printf("] Login Berhasil");
	
		getch();	
	}
}

int admin_log(){
	char nama[100];
	int code;
	int attempt = 0;
	int sisa = 3;
	
	do {
		if (sisa == 0){		
			break;
		}
		
		clr_layar();
		
		header(2);
		
		if (attempt > 0){
			printf(" Username atau Passcode salah\n");
			printf(" Petunjuk : ");
			
			if (strcmp(nama, detail.username) != 0 && code != detail.passcode){
				printf("username & passcode\n");
			} else if (code != detail.passcode){
				printf("passcode\n");
			} else if (strcmp(nama, detail.username) != 0){
				printf("username\n");
			}
		}
		
		printf(" Masukan Admin (username) :\n");
		point();
		scanf("%s",nama);
		
		printf(" Sisa percobaan salah passcode = %02d\n",sisa);
		printf(" Masukan Passcode :\n");
		point();
		scanf("%d",&code);
		
		kosong();
		is_system();
		
		printf("Membandingkan username dan password");
		TitikTitik();
		
		if (strcmp(nama, detail.username) != 0 || code != detail.passcode){
			login(FAILED);
		}
		
		attempt++;
		
		if(code != detail.passcode){
			sisa--;
		}
	} while (strcmp(nama, detail.username) != 0 || code != detail.passcode);
	
	if (sisa != 0){
		login(SUCCESS);
		return 1;
	} else {
		return 0;
	}
}

void admin_system(){
	int pilihan;

	do {
		pilihan = admin_menu();		
		
		switch (pilihan) {
			case 1 :
				admin_1(); // Maintenance Kamar
				break;
			case 2 :
				admin_2(); // Tambah Kamar
				break;
			case 3 :
				admin_3(); // Ubah Kamar
				break;
			case 4 :
				admin_4(); // Ubah Username dan Password
				break;
			case 0 : // Log out
				is_system();
				printf("Logging out ");
				TitikTitik();
				
				is_system();
				printf("Log out Succesfull");
				getch();
		}
	} while (pilihan != 0);
}

int admin_menu(){
	int pilih;
	char not_valid[50] = "";
	
	do {
		header(7);
		
		printf("%s",not_valid);
					
		printf(" Pilih Opsi :\n");
		
		point();
		pilih = sistem_input_int (0, 4, not_valid);
	} while(pilih < 0 || pilih > 4);
	
	processing(1);
	
	return pilih;
}

//Opsi admin 1 (Maitenace kamar)
void admin_1(){
	int pilihan;
	char not_valid[50] = "";
	
	do {
		clr_layar();
		
		garis();
		printf("\t Maintenance\n");
		garis();
		
		kosong();
		printf(" 1. Set-Maintenance\n");
		printf(" 2. UnSet-Maintenance\n");
		kosong();
		
		printf(" Silahkan pilih :\n");
		
		pilihan = sistem_input_int(1, 2, not_valid);
	} while (pilihan < 1 || pilihan > 2);
	
	switch (pilihan){
		case 1 :
			set_maintenance();
			break;
		case 2 :
			unset_maintenance();
			break;
	}
}

void set_maintenance(){
	int pilihan;
	char not_valid[50];
	
	do {
		clr_layar();
		
		list_kamar(1);
		
		kosong();
		printf(" 0. Kembali\n");
		kosong();
	
		garis();
		kosong();
	
		printf("%s",not_valid);
		
		printf("Kamar Mana yang akan Maintenance :\n");
		
		point();
		
		pilihan = sistem_input_int(0, jumlah_kamar, not_valid);
		
		if (pilihan == 0) break;
		
		if (daftar_kamar[pilihan-1].maintenance){
			sprintf(not_valid, "Kamar sudah di Maintenance\n Silahkan pilih lagi\n");
		}
	} while (pilihan < 1 || pilihan > jumlah_kamar || daftar_kamar[pilihan-1].maintenance);
	
	if (pilihan != 0){
	is_system();
	printf("Memproses ");
	TitikTitik();
	
	status_kamar(pilihan - 1, MAINTENANCE);
	
	is_system();
	printf("Kamar %d telah diberikan status 'MAINTENANCE'",daftar_kamar[pilihan-1].nomor);
	} else {
		klik_enter();
	}	
}

void unset_maintenance(){
	int pilihan;
	char not_valid[50];	
	
	do {
		clr_layar();
		
		list_kamar(1);
		
		kosong();
		printf(" 0. Kembali\n");
		kosong();		
	
		garis();
		kosong();
		
		printf("%s",not_valid);
	
		printf("Kamar Mana yang akan Un-Maintenance :\n");
		point();
		
		pilihan = sistem_input_int(0, jumlah_kamar, not_valid);
		
		if (pilihan == 0) break;
		
		if (!daftar_kamar[pilihan-1].maintenance){
			sprintf(not_valid, "Kamar sudah di Maintenance\n Silahkan pilih lagi\n");
		}
	} while (pilihan < 1 || pilihan > jumlah_kamar || !daftar_kamar[pilihan-1].maintenance);
	
	if (pilihan != 0){
	is_system();
	printf("Memproses ");
	TitikTitik();
	
	status_kamar(pilihan - 1, NOT_MAINTENANCE);
	
	is_system();
	printf("Kamar %d telah dikeluarkan dari status 'MAINTENANCE'",daftar_kamar[pilihan-1].nomor);
	} else {
		klik_enter();
	}
}

//Opsi admin 2 (Penambahan kamar) :
void admin_2(){
	int kamar;
	int tipe;
	char not_valid[50];
	
	kamar = tambah_kamar();
	
	processing(1);
	
	do {
		clr_layar();
		
		printf(" Tipe Kamar :\n");
		printf(" 1. Standard\n");
		printf(" 2. Deluxe\n");
		printf(" 3. Ultra Pro\n");
		kosong();
		
		printf("%s",not_valid);
		
		printf(" Pilih Tipe :\n");
		point();
		
		tipe = sistem_input_int(1, 3, not_valid);
	} while (tipe < 1 || tipe > 3);
	
	is_system();
	printf("Membuat Kamar ");
	TitikTitik();
	
	penambahan(kamar, tipe);
}

int tambah_kamar(){
	int kamar;
	int cek;
	char not_valid[50] = "";
	
	do {
		clr_layar();
		
		garis();
		printf("\tTAMBAH KAMAR\n");
		garis();
		kosong();
		
		printf(" Kamar saat ini : %d\n",jumlah_kamar);
	
		printf("%s",not_valid);
		
		printf(" Berapa Kamar :\n");
		point();
		cek = scanf("%d", &kamar);
		
		if (cek != 1){
			sprintf(not_valid, " Harap masukan nomor\n Silahkan masukan lagi\n");
			while(getchar() != '\n');
		} else if (kamar <= 0){
			sprintf(not_valid, " Tidak bisa kurang dari 0\n Silahkan masukan lagi\n");
		} else if (kamar + jumlah_kamar > MAX_KAMAR){
			sprintf(not_valid, "Tidak bisa lebih dari batas maksimal\n Silahkan masukan lagi\n");
		}
	} while (cek != 1 || kamar <= 0 || kamar + jumlah_kamar > MAX_KAMAR);
	
	return kamar;
}

void penambahan (int kamar, int tipe){
	int kamari;
	int i;
	enum Room_Type type;
	
	if (tipe == 1){
		type = STANDARD;
	} else if (tipe == 2){
		type = DELUXE;
	} else if (tipe == 3){
		type = ULTRA_PRO;
	}
	
	for (i = 0; i < kamar; i++) {
		int no;
		int in;
		
		in = (i + jumlah_kamar - 1) + 1;
		no = 100 + in;
		
		daftar_kamar[in].nomor = no;
		tipe_kamar (in, type);
		daftar_kamar[in].pilih = 0;
		daftar_kamar[in].malam = 0;
		strcpy(daftar_kamar[in].status, "EMPTY");
		strcpy(daftar_kamar[in].status_uang, "-");
		daftar_kamar[in].bayar = 0;
		daftar_kamar[in].kosong = true;
		daftar_kamar[in].maintenance = false;
	}
	
	jumlah_kamar = jumlah_kamar + kamar;
	
	is_system();
	printf("Berhasil Menambah Kamar\n");
	is_system();
	klik_enter();
}

//Opsi admin 3 (Perubahan kamar)
void admin_3(){
	int pilihan;
	int ubah;
	int kamar = 0;
	int tipe;
	char not_valid[50] = "";
	char not_valid2[50] = "";
	
	int i;
	bool sama = false;
	
	do {
		do {
			clr_layar();
			
			list_kamar(1);
			
			kosong();
			printf(" 0. Kembali\n");
			kosong();
			
			garis();
			kosong();
			
			printf("%s",not_valid);
			printf(" Kamar Mana yang akan diubah :\n");
			
			point();
			pilihan = sistem_input_int(0, jumlah_kamar, not_valid);
			
			if(pilihan == 0) break;
			
		} while (pilihan < 0 || pilihan > jumlah_kamar);
		
		processing(1);
		
		if (pilihan != 0){
			do {
				clr_layar();
				
				garis();
				printf(" Data Kamar Saat ini :\n");
				printf(" Nama      : %d\n",daftar_kamar[pilihan - 1].nomor);
				printf(" Tipe      : %s\n",daftar_kamar[pilihan - 1].tipe);
				printf(" Harga     : %d\n",daftar_kamar[pilihan - 1].harga);
				printf(" Status    : %s\n",daftar_kamar[pilihan - 1].status);
				kosong();
				
				printf(" 1. Lanjutkan\n");
				printf(" 0. Batal");
		
				kosong();
				garis();
				kosong();
				
				printf("%s",not_valid2);
				
				printf(" Data yang akan diubah = Tipe Kamar\n");
				printf(" Silahkan pilih :\n");
			
				point();
				ubah = sistem_input_int(0, 1, not_valid2);
			} while (ubah < 0 || ubah > 1);
		} else {
			processing(0);
		}
		
		processing(1);
		
		switch (ubah){
			case 1 :				
				do {
					printf("Ganti Tipe\n");
					kosong();
					printf(" 1. Standard\n");
					printf(" 2. Deluxe\n");
					printf(" 3. Ultra Pro\n");
					kosong();
					
					printf(" Masukan pilihan :\n");
					point();
					scanf("%d",&tipe);
				} while (tipe < 0 || tipe > 3);
				
				switch (tipe){
					case 1 :
						tipe_kamar(pilihan -1, STANDARD);
						break;
					case 2 :
						tipe_kamar(pilihan -1, DELUXE);
						break;
					case 3 :
						tipe_kamar(pilihan -1, ULTRA_PRO);
						break;											
				}
				
				is_system();
				printf("Tipe kamar telah diubah.");
				getch();
				break;
			case 2 :
				processing(0);
				break;
		}
	} while (ubah == 0);
}

// Opsi admin 4 (Perubahan user dan passcode)
void admin_4(){
	char n_user[100];
	int n_pass;
	
	garis();
	printf("\tPerubahan Detail Admin\n");
	garis();
	kosong();
	
	printf(" Masukan Username Baru :\n");
	point();
	scanf("%s",n_user);
	
	printf(" Masukan Passcode Baru :\n");
	point();
	scanf("%d",&n_pass);
	
	is_system();
	printf("Memproses ");
	TitikTitik();
	
	strcpy(detail.username, n_user);
	detail.passcode = n_pass;
	
	is_system();
	printf("Username & Password telah diganti");
}

//Kamar Enum
void status_kamar(int room_no, enum Room_State state){
	if (state == MAINTENANCE){
		daftar_kamar[room_no].maintenance = true;
		strcpy(daftar_kamar[room_no].status, "MAINTENANCE");	
	} else if (state == NOT_MAINTENANCE){
		daftar_kamar[room_no].maintenance = false;
		strcpy(daftar_kamar[room_no].status, "EMPTY");		
	} else if (state == BOOKED){
		daftar_kamar[room_no].maintenance = false;
		strcpy(daftar_kamar[room_no].status, "BOOKED");
		daftar_kamar[room_no].kosong = false;		
	}
}

void tipe_kamar(int room_no, enum Room_Type type){
	if (type == STANDARD){
		daftar_kamar[room_no].harga = 100;
		strcpy(daftar_kamar[room_no].tipe, "STANDARD");
	} else if (type == DELUXE){
		daftar_kamar[room_no].harga = 150;
		strcpy(daftar_kamar[room_no].tipe, "DELUXE");		
	} else if (type == ULTRA_PRO){
		daftar_kamar[room_no].harga = 200;
		strcpy(daftar_kamar[room_no].tipe, "ULTRA  PRO");			
	}	
}

void bayar_kamar(int room_no, enum Payment duid){
	if (duid == PAID){
		strcpy(daftar_kamar[room_no].status_uang, "PAID");
	} else if (duid == NOT_PAID){
		strcpy(daftar_kamar[room_no].status_uang, "NOT PAID");
	} else if (duid == NO_ORDER){
		strcpy(daftar_kamar[room_no].status_uang, "NOT BOOKED");
	}
}

//Data-data yang dipakai dalam coding
void auto_kamar(){
	for(int i = 0; i < 2; i++){
		int no;
		no = 100 + i;
		daftar_kamar[i].nomor = no;
		daftar_kamar[i].harga = 100;
		daftar_kamar[i].pilih = 0;
		daftar_kamar[i].malam = 0;
		strcpy(daftar_kamar[i].tipe, "STANDARD");
		strcpy(daftar_kamar[i].status, "EMPTY");
		strcpy(daftar_kamar[i].status_uang, "-");
		daftar_kamar[i].bayar = 0;
		daftar_kamar[i].kosong = true;
		daftar_kamar[i].maintenance = false;
		bayar_kamar(i, NO_ORDER);		
	}
	
	for(int i = 2; i < 4; i++){
		int no;
		no = 100 + i;
		daftar_kamar[i].nomor = no;
		daftar_kamar[i].harga = 150;
		daftar_kamar[i].pilih = 0;
		daftar_kamar[i].malam = 0;
		strcpy(daftar_kamar[i].tipe, "DELUXE");
		strcpy(daftar_kamar[i].status, "EMPTY");
		strcpy(daftar_kamar[i].status_uang, "-");
		daftar_kamar[i].bayar = 0;
		daftar_kamar[i].kosong = true;
		daftar_kamar[i].maintenance = false;
		bayar_kamar(i, NO_ORDER);	
	}
	
	daftar_kamar[4].nomor = 104;
	daftar_kamar[4].harga = 200;
	daftar_kamar[4].pilih = 0;
	daftar_kamar[4].malam = 0;
	strcpy(daftar_kamar[4].tipe, "ULTRA  PRO");
	strcpy(daftar_kamar[4].status, "EMPTY");
	strcpy(daftar_kamar[4].status_uang, "-");
	daftar_kamar[4].bayar = 0;
	daftar_kamar[4].kosong = true;
	daftar_kamar[4].maintenance = false;
	bayar_kamar(4, NO_ORDER);	
	
	dipilih.harga_tamu = 0;
	dipilih.memesan = false;
	dipilih.pesanan = 0;
	
	jumlah_kamar = 5;
}

void auto_admin(){
	strcpy(detail.username, "admin");
	detail.passcode = 123;
}

void auto_fasilitas(){
	strcpy(data_fasilitasi[0].nama, "Alat Mandi");
	data_fasilitasi[0].harga = 35;
	data_fasilitasi[0].pilih = false;
	
	strcpy(data_fasilitasi[1].nama, "Alat Tidur");
	data_fasilitasi[1].harga = 50;
	data_fasilitasi[1].pilih = false;
	
	strcpy(data_fasilitasi[2].nama, "Meja");
	data_fasilitasi[2].harga = 25;
	data_fasilitasi[2].pilih = false;
	
	strcpy(data_fasilitasi[3].nama, "Kursi");
	data_fasilitasi[3].harga = 20;
	data_fasilitasi[3].pilih = false;
	
	strcpy(data_fasilitasi[4].nama, "None");
	data_fasilitasi[4].harga = 0;
	data_fasilitasi[4].pilih = false;	
}

void auto_tier_sarapan(){
	strcpy(data_sarapani[0].tier, "Basic Tier");
	data_sarapani[0].harga = 20;
	
	strcpy(data_sarapani[1].tier, "Metal Tier");
	data_sarapani[1].harga = 40;
	
	strcpy(data_sarapani[2].tier, "Premium Tier");
	data_sarapani[2].harga = 60;
	
	strcpy(data_sarapani[3].tier, "None");
	data_sarapani[3].harga = 0;
}

//Sistem Input (Auto Bug Fixing)
int sistem_input_int (int min, int max, char *msg){
	char extra[50] = "";
	int input;
	int cek;
	
	do {
		cek = scanf("%d", &input);
		
		if(cek != 1){
			sprintf(msg, " Harap masukan nomor\n Silahkan pilih lagi\n");
			while(getchar() != '\n');
			return -1;
		} if (input < min || input > max){
			sprintf(msg, " Pilihan tidak valid\n Silakan pilih lagi\n");
			return -1;
		}
	} while (input < min || input > max || cek != 1);
	
	return input;
}

//Tulisan-tulisan
void header(int opsi){
	switch (opsi){
		case 1 : //Void menu_a
			garis();
			printf("   \tSelamat Datang di Hotel E\n");
			garis();
			printf(" Dimana kenyamanan Anda adalah Prioritas Kami\n");
			garis();
			break;
		case 2 : //Void admin_log
			garis();
			printf("\t AKSES MANAJEMEN HOTEL\n");
			garis();
			kosong();
			break;	
		case 3 :
			garis();
			printf("\t KAMAR YANG DIPESAN\n");
			garis();
			kosong();
			break;
		case 4 :
			garis();
			printf("\t Pembayaran & Checkout\n");
			garis();
			kosong();
			break;
		case 5 :
			garis();
			printf("\t Fasilitas Kamar\n");
			garis();
			kosong();
			break;
		case 6 : // Void opsi kamar
			clr_layar();
		
			list_kamar(1);
			kosong();
		
			printf(" 0. Keluar\n");
			kosong();
			garis();
			kosong();
			break;
		case 7 : // Header Menu Admin
		clr_layar();
		
		garis();
		
		printf("\tSELAMAT DATANG ADMIN\n");
		printf("Pilih Opsi-Opsi dibawah ini\n");
	
		garis();
		kosong();
	
		printf(" 1. Maintenace Kamar\n");
		printf(" 2. Tambah Kamar\n");
		printf(" 3. Ubah Kamar\n");
		printf(" 4. Ubah username & passcode\n");
		printf(" 0. Log off\n");
	
		kosong();
		garis();
		kosong();
		break;
				
	}
}

void garis(){
	printf("==============================================\n");
}

void clr_layar(){
	system("cls");
}

void point(){
	printf(" > ");
}

void kosong(){
	printf(" \n");
}

void klik_enter(){
	printf(" Klik Enter untuk kembali\n");
	point();
	getch();
}

void processing(int value){
	is_system();
	
	switch (value){
		case 0 :
			printf("Mengembalikan ");
			break;
		case 1 :
			printf("Memproses Pilihan ");
			break;
		case 2 :
			printf("Memilih Kamar ");
			break;
		case 3 :
			printf("Mengunci Pilihan ");
			break;
		case 4 :
			printf("Membatalkan ");
			break;
		case 5 :
			printf("Memfinalisasi Pilihan ");
			TitikTitik();
			is_system();
			printf("Membuat status kamar ");
			TitikTitik();
			is_system();
			printf("Membuat pesanan ");
			break;
		case 6 :
			printf("Mengambil data pesanan");
			break;
	}
	
	TitikTitik();
	clr_layar();
}

void TitikTitik(){
	printf(".");Sleep(500);
	printf(".");Sleep(500);
	printf(".\n");Sleep(500);
}

void set_warna(int warna) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), warna);
}

void is_system(){
	printf("[");
	
	set_warna(10);
	printf("SYSTEM");
	
	set_warna(7);
	printf("] ");
}
