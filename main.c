#include <stdio.h>
#include <string.h>

struct SHOP {
    char name[50];
    char contact[12];
};

struct CLOTHING {
    char name[20];
    char code[6];
    char year[5];
    struct SHOP shop;
    struct PRICE
    {
        char currency[4];
        float amount;
    }price;
    union SIZE
    {
        int digit;
        char letter;
        char word[10];
    }size;
    int sizetype;
};

struct SHOP available_shops[1000];
struct CLOTHING available_clothing[1000];
int shopCount = 0; 
int clothesCount = 0;

void showShops();
void showDetails(int option);
void showClothes(int option);
void addClothing();

int main() {
    struct SHOP shop_1, shop_2;
    strcpy(shop_1.name, "Vince's Couture");
    strcpy(shop_1.contact, "0541344662");
    strcpy(shop_2.name, "Sharons's Couture");
    strcpy(shop_2.contact, "0602561234");

    available_shops[0] = shop_1;
    available_shops[1] = shop_2;
    shopCount = 2;

    struct CLOTHING item_1,item_2,item_3,item_4;
    strcpy(item_1.name, "Tank Top");
    strcpy(item_1.code, "xy123");
    strcpy(item_1.year, "2019");
    item_1.shop = shop_1;
    strcpy(item_1.price.currency, "USD");
    item_1.price.amount = 150.00;
    strcpy(item_1.size.word, "Large");
    item_1.sizetype = 2;
    
    strcpy(item_2.name, "Booty Shorts");
    strcpy(item_2.code, "ab789");
    strcpy(item_2.year, "2023");
    item_2.shop = shop_1;
    strcpy(item_2.price.currency, "GHC");
    item_2.price.amount = 50.00;
    item_2.size.letter = 'M';
    item_2.sizetype = 1;

    strcpy(item_3.name, "Hoodie");
    strcpy(item_3.code, "gf567");
    strcpy(item_3.year, "2021");
    item_3.shop = shop_2;
    strcpy(item_3.price.currency, "EUR");
    item_3.price.amount = 10.00;
    item_3.size.letter =  'L';
    item_3.sizetype = 1;

    strcpy(item_4.name, "Sweat Pants");
    strcpy(item_4.code, "we345");
    strcpy(item_4.year, "2020");
    item_4.shop = shop_2;
    strcpy(item_4.price.currency, "USD");
    item_4.price.amount = 50.00;
    item_4.size.digit = 50;
    item_4.sizetype = 0;

    available_clothing[0] = item_1;
    available_clothing[1] = item_2;
    available_clothing[2] = item_3;
    available_clothing[3] = item_4;

    clothesCount = 4;


    int looping = 0;
    do {
        printf("\nCLOTHING MALL\n\n1 - Visit Shop\t2 - Add Clothing\t3 - Exit\n");
        int option;
        fflush(stdin);
        scanf(" %d", &looping);
        switch (looping)
        {
        case 1:
            showShops();
            scanf(" %d", &option);
            showDetails(option - 1);
            showClothes(option - 1);
            break;
        case 2: 
            addClothing();
            break;
        case 3:
            looping = 0;
            printf("\nThanks for shopping :)");
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    } while (looping > 0);


    return 0;
}

void showShops() {
    printf("\n\nAVAILABLE SHOPS\n");
    for (int i = 0; i < shopCount; i++) {
        printf("\n%d - %s", i + 1, available_shops[i].name);
    }
    printf("\n\nSelect shop to visit: ");
}

void showDetails(int option) {
    printf("\n\nSHOP %d\n\n", option + 1);
    printf("NAME : %s\nCONTACT : %s", available_shops[option].name, available_shops[option].contact);
}

void showClothes(int option) {
    printf("\n\nAVAILABLE CLOTHING\n\n");
    for (int i = 0; i < clothesCount; i++)
    {
        if (strcmp(available_clothing[i].shop.name,available_shops[option].name) == 0) {
            printf("ITEM NAME: %s\n", available_clothing[i].name);
            printf("ITEM CODE: %s\n", available_clothing[i].code);
            printf("YEAR OF PRODUCTION: %s\n", available_clothing[i].year);
            printf("ITEM PRICE: %s %.2f\n", available_clothing[i].price.currency,available_clothing[i].price.amount);
            printf("ITEM SIZE : ");
            switch (available_clothing[i].sizetype)
            {
            case 0:
                printf("%d\n\n", available_clothing[i].size.digit);
                break;
            case 1:
                printf("%c\n\n", available_clothing[i].size.letter);
                break;
            case 2:
                printf("%s\n\n", available_clothing[i].size.word);
                break;
            
            default:
                printf("UNAVAILABLE\n\n");
                break;
            }
        }
    }
    
}

//Add a new clothing item
void addClothing() {
    char name[50], code[6], year[5], currency[4], letter, word[20];
    int digit, amount, sizetype, option, item_no, looping = 0;
    do {printf("\nNumber of items to add: ");
    fflush(stdin);
    scanf(" %d", &item_no);

    for (int i = 0; i < item_no; i++) {
    printf("\n\nUPDATE CLOTHING INVENTORY\n\n");
    printf("Enter item name: ");
    fflush(stdin);
    scanf(" %s", &name);
    strcpy(available_clothing[clothesCount + i].name, name);
    printf("\n\nEnter item code: ");
    fflush(stdin);
    scanf(" %s", &code);
    strcpy(available_clothing[clothesCount + i].code, code);
    printf("\n\nYear of Production: ");
    fflush(stdin);
    scanf(" %s", &year);
    strcpy(available_clothing[clothesCount + i].year, year);
    printf("\n\nEnter price (amount): ");
    fflush(stdin);
    scanf(" %f", &amount);
    available_clothing[clothesCount + i].price.amount = amount;
    printf("\n\nEnter Currency (Eg. USD, GHC): ");
    fflush(stdin);
    scanf(" %s", &currency);
    strcpy(available_clothing[clothesCount + i].price.currency, currency);

    do {printf("\n\nSelect size type\n1 - Digit\n2 - Letter\n3 - Words\n\nYour choice: ");
    fflush(stdin);
    scanf(" %d", &sizetype);
    available_clothing[clothesCount + i].sizetype = sizetype - 1;
    switch (sizetype)
    {
    case 1:
        printf("\n\nEnter item size (Digit): ");
        scanf(" %d", &digit);
        available_clothing[clothesCount + i].size.digit = digit;
        break;
    case 2:
        printf("\n\nEnter item size (Letter): ");
        scanf(" %c", &letter);
        available_clothing[clothesCount + i].size.letter = letter;
        break;
    case 3:
        printf("\n\nEnter item size (Words): ");
        scanf(" %s", &word);
        strcpy(available_clothing[clothesCount + i].size.word, word);
        break;
    
    default:
        printf("Invalid option");
        looping = 2;
        break;
    }} while (looping == 2);
    
    do {printf("\n\nSelect shop\n\n1 - Vince's Couture\n2 - Sharon's Couture\n\nYour choice: ");
    fflush(stdin);
    scanf(" %d", &option);
    switch (option)
    {
    case 1:
        available_clothing[clothesCount + i].shop = available_shops[option - 1];
        break;
    case 2:
        available_clothing[clothesCount + i].shop = available_shops[option - 1];
        break;
    
    default:
        printf("\n\nInvalid option");
        looping = 2;
        break;
    }} while (looping == 2);

    clothesCount += 1;
    printf("\n\nInventory updated. Available clothes: %d", clothesCount);
    }
    printf("\n\nItems added successfully\n");

    do {printf("\n\nAdd more items?\n\n1 - YES\n2 - NO\n\nYour choice: ");
    fflush(stdin);
    scanf(" %d", &option);
    switch (option)
    {
    case 1:
        printf("\nAlright! Let's do this again...");
        looping = 1;
        break;
    case 2:
        printf("\nExiting...");
        looping = 0;
        break;
    default:
        printf("\nInvalid option");
        looping = 2;
        break;
    }} while (looping == 2);
    } while(looping == 1);
}