#include<bits/stdc++.h>
using namespace std;


// ================= STRUCTURES ===================
struct CustomerInvoice
{
    char CstName[100];
    char mobileNum[11];
};

struct CstProductInfo
{
    char productName[200];
    int Qty;
    int price;
};

struct productList
{
    char productName[200];
    char companyName[200];
    char woodName[200];
    int Qty;
    int price;

};

struct employeeInfo
{
    char name[200];
    char mobile[200];
    char Position[200];
};


struct reg
{
    char name[50];
    char pass[10];
};

// ====================== FUNCTION INITIALIZATION ======================
void createInvoice();
void printCustomerInvoices();
void addNewProducts();
void productList();
void productOption();
void totalSale();
void addNewEmployee();
void viewEmployeeList();
void employeeInfo();
void option();
void regis();
void login();


// ======================== MAIN FUNCTION ============================
int main()
{
    int opt,a;
    printf("\t\t===========================================================\n\n");
    printf("\t\t============ FURNITURE SHOP MANAGEMENT SYSTEM =============\n\n");
    printf("\t\t===========================================================\n");
    while(opt!=3)
    {
        printf("1.LOGIN\n2.UPDATE LOGIN INFO\n3.EXIT\n\n");
        printf("Enter any option: ");
        scanf("%d",&opt);
        if(opt==2)
        {
            printf("\nSECURITY PIN: ");
            scanf("%d",&a);
            if(a==2003)
            {
                regis();
            }
        }
        else if(opt==1)
        {
            login();
        }
        else if(opt==3)
        {
            system("CLS");
            printf("\n\n\t\t******** Thank You **********\n\n");
        }
        else
        {
            printf("\nINVALID INPUT!\n");
        }
    }

}

// =========== FUNCTION DECLARATION ==============
void createInvoice()
{
    FILE *fp;
    FILE *fp1;
    fp = fopen("customer_invoice.txt","a");
    fp1= fopen("totalSale.txt","a");
    int total;
    struct CustomerInvoice user;
    fflush(stdin);
    system("cls");
    printf("\t\t===========================================================\n\n");
    printf("\t\t============ FURNITURE SHOP MANAGEMENT SYSTEM =============\n\n");
    printf("\t\t===========================================================\n");
    cout << "Customer Name: ";
    cin.getline(user.CstName,200);
    fflush(stdin);
    cout << endl;
    cout << "Mobile Number: ";
    cin >> user.mobileNum;
    fflush(stdin);
    fprintf(fp,"\nCustomer Name: %s\nCustomer Mobile Number: %s",user.CstName,user.mobileNum);
    cout << "Enter number of varients: ";
    cin >> total;

    struct CstProductInfo prd;
    int totalPrice=0;
    fprintf(fp,"\n\nProduct Name\t\tQuantity\t\tProduct Price");

    for(int i=0; i<total; i++)
    {
        fflush(stdin);
        cout << "Enter Product Name: " << endl;
        cin.getline(prd.productName,200);
        fflush(stdin);
        cout << "Enter Quantity: " << endl;
        cin >> prd.Qty;
        fflush(stdin);
        cout << "Enter Price: "<< endl;
        cin >> prd.price;
        fflush(stdin);
        totalPrice += prd.price * prd.Qty;
        fflush(stdin);
        fprintf(fp,"\n%s\t\t%d\t\t\t%dTk",prd.productName,prd.Qty,prd.price);
        fprintf(fp1,"\n%s\t\t%d\t\t%d",prd.productName,prd.Qty,prd.price);
    }
    system("cls");
    printf("\t\t===========================================================\n\n");
    printf("\t\t============ FURNITURE SHOP MANAGEMENT SYSTEM =============\n\n");
    printf("\t\t===========================================================\n");
    printf("\nInvoice is Created Successfully!");
    fprintf(fp,"\n\nTotal Price: \t\t\t\t\t%dTk\n\n",totalPrice);
    fprintf(fp,"\n-------------------------------------------------------------------------------------\n\n");
    fclose(fp);
    fclose(fp1);



}

void printCustomerInvoices()
{
    FILE *file;
    char ch[10000];
    file = fopen("customer_invoice.txt","r");
    system("CLS");
    printf("\n");
    while(!feof(file))
    {
        fgets(ch,10000,file);
        printf("%s",ch);
    }
    fclose(file);
}




void addNewProducts()
{
    FILE *file;
    file = fopen("product_info.txt","a");
    struct productList prd;
    fflush(stdin);
    printf("Enter Product Name: ");
    cin.getline(prd.productName,200);
    fflush(stdin);
    printf("Enter Company Name: ");
    cin.getline(prd.companyName,200);
    fflush(stdin);
    printf("Enter Material Name: ");
    cin.getline(prd.woodName,200);
    fflush(stdin);
    printf("Enter Price: ");
    cin >> prd.price;
    fflush(stdin);
    printf("Enter Qty: ");
    cin >> prd.Qty;
    fflush(stdin);
    fprintf(file,"\n%s\t\t\t%s\t\t\t%s\t\t\t%d\t\t%d",prd.productName,prd.companyName,prd.woodName,prd.price,prd.Qty);
    fclose(file);
}

void productList()
{
    FILE *file;
    char ch[2000];
    file = fopen("product_info.txt","r");
    system("CLS");
    printf("\n");
    while(!feof(file))
    {
        fgets(ch,2000,file);
        printf("%s",ch);
    }
    fclose(file);
}




void productOption()
{
    int opt;
    system("cls");
    printf("\t\t===========================================================\n\n");
    printf("\t\t============ FURNITURE SHOP MANAGEMENT SYSTEM =============\n\n");
    printf("\t\t===========================================================\n");
    printf("\n1. Add New Products");
    printf("\n2. View All Products");
    printf("\nEnter your choice: ");
    cin >> opt;
    switch(opt)
    {
    case 1:
        addNewProducts();
        break;
    case 2:
        productList();
        break;
    default:
        cout << "Invalid Input!"<< endl;

    }
}

void totalSale()
{
    FILE *file;
    char ch[2000];
    file = fopen("totalSale.txt","r");
    system("CLS");
    printf("\n");
    while(!feof(file))
    {
        fgets(ch,2000,file);
        printf("%s",ch);
    }
    fclose(file);
}

void addNewEmployee()
{
    struct employeeInfo em;
    FILE *fp;
    fp = fopen("employee_info.txt","a");
    fflush(stdin);
    printf("\nEnter the Employee Name: ");
    cin.getline(em.name,200);
    fflush(stdin);
    printf("\nEnter the Mobile Number: ");
    cin >> em.mobile;
    fflush(stdin);
    printf("\nEnter Position: ");
    cin.getline(em.Position,200);
    fflush(stdin);
    fprintf(fp,"\n%s\t\t%s\t\t%s",em.name,em.mobile,em.Position);
    fclose(fp);
}

void viewEmployeeList()
{
    FILE *file;
    char ch[2000];
    file = fopen("employee_info.txt","r");
    system("CLS");
    printf("\n");
    while(!feof(file))
    {
        fgets(ch,2000,file);
        printf("%s",ch);
    }
    fclose(file);
}

void employeeInfo()
{
    int opt;
    system("cls");

    printf("\t\t===========================================================\n\n");
    printf("\t\t============ FURNITURE SHOP MANAGEMENT SYSTEM =============\n\n");
    printf("\t\t===========================================================\n");
    printf("\n\n1. Add New Employee Info");
    printf("\n2. View Employee List");
    printf("\nEnter your choice: ");
    cin >> opt;
    switch(opt)
    {
    case 1:
        addNewEmployee();
        break;
    case 2:
        viewEmployeeList();
        break;
    default:
        cout << "Invalid Input!" << endl;
    }

}


void option()
{
    int opt;
    do
    {
        printf("\n\n1. Create Invoice\n");
        printf("2. Customer Invoices\n");
        printf("3. Products\n");
        printf("4. Total Sell\n");
        printf("5. Employee Info\n");
        printf("6. Log Out\n");

        printf("Enter Your Choice: ");
        cin >> opt;
        switch(opt)
        {
        case 1:
            createInvoice();
            break;

        case 2:
            printCustomerInvoices();
            break;
        case 3:
            productOption();
            break;
        case 4:
            totalSale();
            break;
        case 5:
            employeeInfo();
            break;
        case 6:
            break;
        default:
            cout << "Invalid Input!"<< endl;
        };
    }
    while(opt!=6);
    system("CLS");

    printf("\t\t===========================================================\n\n");
    printf("\t\t============ FURNITURE SHOP MANAGEMENT SYSTEM =============\n\n");
    printf("\t\t===========================================================\n");
    printf("\nLogged Out Successfully!\n");
}



void regis()
{

    system("CLS");
    printf("\t\t===========================================================\n\n");
    printf("\t\t============ FURNITURE SHOP MANAGEMENT SYSTEM =============\n\n");
    printf("\t\t===========================================================\n");
    FILE *file;
    file = fopen("login_info.txt","w");
    struct reg person;
    if(file==NULL)
    {
        printf("\t\tERROR!");
    }
    else
    {
        printf("\nUser Name: ");
        scanf("%s",&person.name);
        printf("\nPassword: ");
        scanf("%s",&person.pass);
        fwrite(&person,sizeof(person),1,file);
        system("CLS");
        printf("\t\t===========================================================\n\n");
        printf("\t\t============ FURNITURE SHOP MANAGEMENT SYSTEM =============\n\n");
        printf("\t\t===========================================================\n");
        printf("\nInformation Updated Successfully!\n");
        fclose(file);
    }


}
void login()
{
    char uname[20];
    char lpass[10];
    FILE *file;
    file = fopen("login_info.txt","r");
    struct reg person;
    printf("\nUser Name: ");
    scanf("%s",&uname);
    printf("\nPassword: ");
    scanf("%s",&lpass);
    while(fread(&person,sizeof(person),1,file))
    {
        if(strcmp(uname,person.name)==0 && strcmp(lpass,person.pass)==0)
        {
            system("CLS");
            printf("\t\t===========================================================\n\n");
            printf("\t\t============ FURNITURE SHOP MANAGEMENT SYSTEM =============\n\n");
            printf("\t\t===========================================================\n");
            printf("\n ******** LOGIN SUCCESSFUL! *******");
            printf("\nPlease, choose any option: ");
            option();
        }
        else
        {
            system("CLS");
            printf("\t\t===========================================================\n\n");
            printf("\t\t============ FURNITURE SHOP MANAGEMENT SYSTEM =============\n\n");
            printf("\t\t===========================================================\n");
            printf("\nWRONG INFO!");
            printf("\nPlease, enter correct informations");
            login();
        }
    }

}











