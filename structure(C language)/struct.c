#include <stdio.h>
#include <stdlib.h>

// membuat struct
struct mahasiswa 
{
	char *name;
	char *address;
	int age;
};

struct x{ // 0bytes
	int b; // 4bytes
	int *a; // 8bytes
	void *p; // 8bytes
};

void main()
{
	// how much data does struct take?
	printf("struct size %ld bytes\n",sizeof(struct x));

	// stack memory allocation
	// struct mahasiswa mhs1;

	// heap memory allocation
	struct mahasiswa *mhs1;
	mhs1 = malloc(sizeof(struct mahasiswa));



// declareing stack structure
	// mhs1.name = "Bambang";
	// mhs1.address = "Surabaya";
	//mhs1.age = 23;

    // printf("## Mahasiswa 2 ##\n");
    // printf("Nama: %s\n", mhs2.name);
    // printf("Alamat: %s\n", mhs2.address);
    // printf("Umur: %d\n", mhs2.age);

	/*
	declareing heap structure
	we asssigning value using -> because it's a pointer type
	same as accesing value.
	*/
	mhs1->name = "Dian";
	mhs1->address = "matram";
	mhs1->age = 22;

    printf("## Mahasiswa 1 ## accesing with arrow\n");
    printf("Nama: %s\n", mhs1->name);
    printf("Alamat: %s\n", mhs1->address);
    printf("Umur: %d\n\n", mhs1->age);

    printf("## Mahasiswa 1 ## accesing with dot\n");
    printf("Nama: %s\n", (*mhs1).name);
    printf("Alamat: %s\n", (*mhs1).address);
    printf("Umur: %d\n", (*mhs1).age);
}
