#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
#include<string>
#include<windows.h>
#include<mysql.h>
using namespace std;
int productlist();
void display(struct node *tree);
void search_node(struct node *tree);
void create(unsigned long long int ph,char* name);
void insert();
void search_no(struct node *tree,char* n) ;
void search_person(char* person);
struct node* minValueNode(struct node* node);
void write(struct node* tree);
struct node* deleteNode(struct node* root, unsigned long long int key);
string customer_name,email,phones;

struct node
{   unsigned long long int ph;
    char name[20];
    struct node* l;
    struct node* r;
}*root = NULL,*temp = NULL;

int a = 0;
unsigned long long int p = 0;
FILE *f;
int glo1=0,glo2=0;
void create(unsigned long long int ph,char* name)
{
    temp = (struct node *)malloc(sizeof(struct node));
    if(temp == NULL)
    {
        printf ("\nOut of memory!!! (create_node)\n");
        exit(0);
    }
    temp->ph = ph;
	strcpy(temp->name,name);
	temp->l = NULL;
    temp->r = NULL;
}

// used for finding a correct position to store a new node

void search_node(struct node *tree)

{	if((temp->ph > tree->ph) && (tree->r != NULL))
		search_node(tree->r);

	else if((temp->ph > tree->ph) && (tree->r == NULL))
		tree->r = temp;

	else if((temp->ph < tree->ph) && (tree->l != NULL))
		search_node(tree->l);

	else if((temp->ph < tree->ph)  && (tree->l == NULL))
		tree->l = temp;
}

void load()
{	unsigned long long int ph;
	char name[20];
	size_t size;
    f = fopen("input.txt","r");
    if (f== NULL)
    {   printf("can not open file \n");
	    return;
    }
    fseek(f, 0, SEEK_END);
    size = ftell(f);
   	fclose(f);

   	f = fopen("input.txt","r");
	if (size != 0)
    {
	    while(!feof(f)){
		    fscanf(f,"%s",&name);
		    fscanf(f,"%llu",&ph);
		    create(ph,name);
		    if (root == NULL)
				root = temp;
		    else
				search_node(root);
		}
	}
 	fclose(f);
}

void display(struct node *tree)
{


    if (tree == NULL)
        return;
    printf("%s ---- %llu",tree->name,tree->ph);
    if(tree->l != NULL)
    cout<<endl;
    if(tree->r != NULL)
    printf("\n");
    display(tree->l);
    printf("\n");
    display(tree->r);
}

// used for searching a person's number given his name.

void search_no(struct node *tree,char* n)
{
	if(tree!=NULL){
	if(strcmp(tree->name,n)==0)
		{	a=1;	p = tree->ph;	return;		}
	search_no(tree->l,n);
	search_no(tree->r,n);
	}
}

// used for searching a person exists or not.

void search_person(char* person)
{		if(root!=NULL)
		{	search_no(root,person);
			if(a==0)
				{ p = 0;}
		}
		else
			{	printf("\nTree is Empty!!\n");	return; }
}


struct node* minValueNode(struct node* node)
{
    struct node* current = node;
    while (current->l != NULL)			/* loop down to find the leftmost leaf */
        current = current->l;
    return current;
}




void write(struct node* tree)
{	if(tree != NULL)
  {
      fprintf(f, "%s\n%llu\n", tree->name,tree->ph);
	  write(tree->l);
      write(tree->r);
   }
}

struct node* deleteNode(struct node* root, unsigned long long int key)
{   if (root == NULL) return root;
    if (key < root->ph)
        root->l = deleteNode(root->l, key);
    else if (key > root->ph)
        root->r = deleteNode(root->r, key);
    else
    {	// node with only one child or no child
        if (root->l == NULL)
        {   struct node *tmp = root->r;
            free(root);
            return tmp;
        }
        else if (root->r == NULL)
        {   struct node *tmp = root->l;
            free(root);
            return tmp;
        }
        struct node* tmp = minValueNode(root->r);				// node with two children: Get the inorder successor (smallest in the right subtree)
        root->ph = tmp->ph;										// Copy the inorder successor's content to this node
        strcpy(root->name,tmp->name);
        root->r = deleteNode(root->r, tmp->ph);					// Delete the inorder successor
    }
    return root;
}


int connection(string name,string id)
{
    string phone,pp;

     MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES *res;
    int qstate;

       conn = mysql_init(0);
    if(conn)
        cout<<endl<<endl;
    else
        cout<<"conn object problem: "<<mysql_error(conn);

    conn = mysql_real_connect(conn,"localhost","root","","megastore",0,NULL,0);

    if(conn)
    {
        phone = phones;

        string query="insert into mcafy(id,name,phone,customer_name,email) values('"+id+"','"+name+"','"+phone+"','"+customer_name+"','"+email+"')";


        const char* q = query.c_str();


        qstate = mysql_query(conn,q);

        if(!qstate)
            cout<<"\n"<<endl;
        else

            cout<<"\nquery problem: "<<mysql_error(conn)<<endl<<endl;

        qstate = mysql_query(conn,"select * from mcafy");
    }
    else
    {
        cout<<"connection problem:\t "<<mysql_error(conn)<<endl;

}

    mysql_close(conn);

    return 0;

}

string  gets(int n)
{
	ostringstream s;
	s<<n;
	string ss = s.str() ;
	return ss;
}




int pro[10];
string stl[10];


int main()
{
    cout<<""<<endl<<"\t\t\t\t\t\t\t|\t\t\t\t\t\t|";
printf("\n\t\t\t\t\t\t\t\t\tWELCOME TO MEGA STORE\t\t\t\t\t\t\t\t\t\t\t\t|\t\t\t\t\t\t\t|\t");
printf("\n\t\t\t\t\t\t\t\t-------------------------------------");
printf("\n\t\t\t\t\t\t\t\t-------------------------------------");
cout<<endl;
string sii,em,phhp;;
    cout<<"\t\t1)Enter Name:\t "<<endl<<endl;
    cin>>sii;
 customer_name = sii;
    cout<<"\t\t2)Enter Email: \t"<<endl<<endl;
    cin>>em;
cout<<"Enter Your Phone Number: \t"<<endl<<endl;
    cin>>phhp;
    phones =phhp;
 email = em;
cout<<endl<<endl;


string st;
string s= "-";
	for(int i=0;i<55;i++)
	{
		cout<<s<<"  ";
	}
	cout<<endl<<endl;
 cout<<""<<endl<<"\t\t\t\t\t\t\t|\t\t\t\t\t\t|";
printf("\n\t\t\t\t\t\t\t\t\tWELCOME TO MEGA STORE\t\t\t\t\t\t\t\t\t\t\t\t|\t\t\t\t\t\t\t|\t");
printf("\n\t\t\t\t\t\t\t\t-------------------------------------");
printf("\n\t\t\t\t\t\t\t\t-------------------------------------");
cout<<endl<<endl;
	int c;
	load();
	while(1)
	{	printf("\n\nChoose Options:\t\n");
	printf("---------------\n\n");
		printf(" \n\n\n\t\t ---(1).Search Product \t\t ---(4). Ordered List \n\n\t\t ---(2).Order Product \t\t ---(5).Products \n\n\t\t ---(3).Cancel Order \t\t ---(6). Exit \n");
		printf("\n\n\nEnter your option:\t\t");
		scanf("%d",&c);
		char person[20];
		a = 0;
		switch(c)
		{	case 1:

				printf("\nEnter Product Name to be searched:\t");
				scanf("%s",&person);
				search_person(person);
				if(root != NULL){
					if(p!=0)
						printf("\n\n\t Product Name :  \t%s\n\t  Product Id: \t\t%llu\n\n",person,p);
					else
						printf("\n\n\t\t\t\t\tProduct not Found!!\n\n");
				}
				break;

			case 2:
				unsigned long long int t_ph;
				printf("\n\nEnter Product's name:\t");
				scanf("%s",&person);
				printf("\n\nEnter Product's Id:\t");
				scanf("%llu",&t_ph);
                st = gets(t_ph);
                connection(person,st);
				create(t_ph,person);
				if (root == NULL)
					root = temp;
		    	else
					search_node(root);
					printf("\n\n\tThankyou ,Product Successfully Added \n");

				break;

			case 3:
				//a = 0;char person[20];
				printf("\n\nEnter Product Name to be deleted:\t");
				scanf("%s",&person);
				search_person(person);
				if(root != NULL){
					if(p!=0)
						{	root = deleteNode(root,p);
						printf("\n\n\tProduct deleted");
							}
					else
						printf("\n\nThis Product '%s' doesn't exist\n\n",person);
				}
				break;

			case 4:
				if(root!= NULL)
				{

					printf("\n\t\t\t\tALL THE ORDERED PRODUCT - \n\n");
					cout<<endl<<endl;
					                printf("PRODUCT NAME  ----  PRODUCT ID\n--------------------------------\n\n ");
					                cout<<endl;
					display(root);


				}
				else printf("\nThere are No Product Id in Store\n");
				break;

			case 5:
				productlist();
				break;

			case 6:
				f = fopen("input.txt", "w");
				if (f == NULL)
				{	printf("Error opening file!\n"); exit(1);	}
				printf("\nWriting to File...\n\nExiting.....");
				write(root);
				fclose(f);
				exit(0);
			default:
				printf("\nPlease Choose a correct option\n");

		}
	}

}


//used to write final bst into file.
int productlist()
{
    int n;
    string st;
unsigned long long int t_ph;
char person[20];
    printf("\nId\t\t\t\t\t\t\t-----Category of Different Type of Company-----\n\n");
    cout<<endl<<endl<<endl;
    printf("1)  TECHNOLOGY\n");
    printf("2)  GROCERY STORE\n");
    printf("3)  GENERRAL STRORE\n");
    printf("4)  GARGMENTS STROE\n");
    printf("\n\nEnter Id:\n\t ");
        cin>>n;
    if(n==1)
    {

    printf("\nId)\tCompany Name\n\n");
	printf("1)\tSony\n");
	printf("2)\tLenovo\n");
	printf("3)\tDell\n");
	printf("4)\tMicromax\n");
	printf("5)\tI-ball\n");
	printf("6)\tSamsung \n\n");
	printf("\n Enter Id For Choose Company \n ");
	int nm1;
	cin>>nm1;
    if(nm1==1)
    {
    printf("\n(Product Id)\tProducts\tCheck Avalability\tPrice Range \t\t\tType \t\n\n");
    printf("\n1)\t\tLaptop\t\tAVAILABLE\t\t10000Rs - 40000Rs\t\tVAIO® Duo 13 and VAIO® Pro 11(White or Silver and Black)+ 1Year Seller Warranty \n");
    printf("\n2)\t\tMobile\t\tAVAILABLE\t\t5000Rs - 50000Rs\t\tXperia™ Z and Xperia™ ZL(White or Black and Gold)+ 10 Months Seller Warranty\n");
    printf("\n3)\t\tTablet\t\tAVAILABLE\t\t5000Rs - 20000Rs\t\tXperia™ Tablet Z(White)+5 Months Seller Warranty \n");
    printf("\n4)\t\tHeadphone\tAVAILABLE\t\t1000Rs - 8000Rs\t\t\tSony MDR-ZX110 On-Ear Stereo Headphones (Black and White)+3 Months Seller Warranty \n");
    printf("\n5)\t\tBluetooth\tAVAILABLE\t\t1000Rs - 4000Rs\t\t\tSony SBH54 Black Stereo Bluetooth(Black)+2 Months Seller Warranty \n");
    printf("\n6)\t\tCamera\t\tAVAILABLE\t\t10000Rs - 50000Rs\t\tPMW-F5 and PMW-F55 CineAlta™ Cameras(White and Gold or Silver)+ 12 Months Seller Warranty\n\n");
    int idd;

    printf("Enter Product Budget In the Mentioned  Range\n\n");
    int fil1;
    cin>>fil1;
    if(fil1>=20000 && fil1<=30000)
    {

        printf("Enter Product Id:  \n");
        cin>>t_ph;

        pro[glo1] =t_ph;
        glo1++;
        printf("Enter Product Name:  \n");
        cin>>person;

        stl[glo2] = person ;
        glo2++;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
					root = temp;
		    	else
					search_node(root);

        printf("Successfully Added Product\n\n");
    }
    else if(fil1>=30000 && fil1<=40000)
    {
    printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
					root = temp;
		    	else
					search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>=10000 && fil1<=20000)
    {
       printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
					root = temp;
		    	else
					search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>=1000 && fil1<=5000)
    {
   printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
					root = temp;
		    	else
					search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>100 && fil1<=2000)
    {
       printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
        if (root == NULL)
        root = temp;
		else
		search_node(root);

        printf("Successfully Added Product\n\n");

    }

    }

    else if(nm1==2)
    {
    printf("\n(Product Id)\tProducts\tCheck Avalability\tPrice Range \t\t\tType \t\n\n");
    printf("\n1)\t\tLaptop\t\tAVAILABLE\t\t10000Rs - 40000Rs\t\t(White or Silver and Black)+ 1Year Seller Warranty \n");
    printf("\n2)\t\tMobile\t\tAVAILABLE\t\t5000Rs - 50000Rs\t\t(White or Black and Gold)+ 10 Months Seller Warranty\n");
    printf("\n3)\t\tTablet\t\tAVAILABLE\t\t5000Rs - 20000Rs\t\t(White)+5 Months Seller Warranty \n");
    printf("\n4)\t\tHeadphone\tAVAILABLE\t\t1000Rs - 8000Rs\t\t\tOn-Ear Stereo Headphones (Black and White)+3 Months Seller Warranty \n");
    printf("\n5)\t\tBluetooth\tAVAILABLE\t\t1000Rs - 4000Rs\t\t\tBlack Stereo Bluetooth(Black)+2 Months Seller Warranty \n");
    printf("\n6)\t\tCamera\t\tAVAILABLE\t\t10000Rs - 50000Rs\t\tPMW-F5 and PMW-F55 CineAlta™ Cameras(White and Gold or Silver)+ 12 Months Seller Warranty\n\n");

    printf("Enter Product Budget In the Mentioned  Range\n\n");
    int fil1;
    cin>>fil1;
    if(fil1>=20000 && fil1<=30000)
    {
        printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");
    }
    else if(fil1>=30000 && fil1<=40000)
    {
    printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
        if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>=10000 && fil1<=20000)
    {
       printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
        if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>=1000 && fil1<=5000)
    {
   printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
        if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>100 && fil1<=2000)
    {
       printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
        if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }


    }
   else if(nm1==3)
   {

    printf("\n(Product Id)\tProducts\tCheck Avalability\tPrice Range \t\t\tType \t\n\n");
    printf("\n1)\t\tLaptop\t\tAVAILABLE\t\t10000Rs - 40000Rs\t\tVAIO® Duo 13 and VAIO® Pro 11(White or Silver and Black)+ 1Year Seller Warranty \n");
    printf("\n2)\t\tMobile\t\tAVAILABLE\t\t5000Rs - 50000Rs\t\tZL(White or Black and Gold)+ 10 Months Seller Warranty\n");
    printf("\n3)\t\tTablet\t\tAVAILABLE\t\t5000Rs - 20000Rs\t\tTablet 1.11 Z(White)+5 Months Seller Warranty \n");
    printf("\n4)\t\tHeadphone\tAVAILABLE\t\t1000Rs - 8000Rs\t\t\tMDR-ZX110 On-Ear Stereo Headphones (Black and White)+3 Months Seller Warranty \n");
    printf("\n5)\t\tBluetooth\tAVAILABLE\t\t1000Rs - 4000Rs\t\t\tSBH54 Black Stereo Bluetooth(Black)+2 Months Seller Warranty \n");
    printf("\n6)\t\tCamera\t\tAVAILABLE\t\t10000Rs - 50000Rs\t\tPMW-F5 and PMW-F55 CineAlta™ Cameras(White and Gold or Silver)+ 12 Months Seller Warranty\n\n");

    printf("Enter Product Budget In the Mentioned  Range\n\n");
    int fil1;
    cin>>fil1;
    if(fil1>=20000 && fil1<=30000)
    {
        printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
        if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");
    }
    else if(fil1>=30000 && fil1<=40000)
    {
    printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
        if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>=10000 && fil1<=20000)
    {
       printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
        if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>=1000 && fil1<=5000)
    {
   printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>100 && fil1<=2000)
    {
       printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }

   }

   else if(nm1==4)
   {

    printf("\n(Product Id)\tProducts\tCheck Avalability\tPrice Range \t\t\tType \t\n\n");
    printf("\n1)\t\tLaptop\t\tAVAILABLE\t\t10000Rs - 40000Rs\t\tVAIO® Duo 13 and VAIO® Pro 11(White or Silver and Black)+ 1Year Seller Warranty \n");
    printf("\n2)\t\tMobile\t\tAVAILABLE\t\t5000Rs - 50000Rs\t\tXperia™ Z and Xperia™ ZL(White or Black and Gold)+ 10 Months Seller Warranty\n");
    printf("\n3)\t\tTablet\t\tAVAILABLE\t\t5000Rs - 20000Rs\t\tXperia™ Tablet Z(White)+5 Months Seller Warranty \n");
    printf("\n4)\t\tHeadphone\tAVAILABLE\t\t1000Rs - 8000Rs\t\t\tSony MDR-ZX110 On-Ear Stereo Headphones (Black and White)+3 Months Seller Warranty \n");
    printf("\n5)\t\tBluetooth\tAVAILABLE\t\t1000Rs - 4000Rs\t\t\tSony SBH54 Black Stereo Bluetooth(Black)+2 Months Seller Warranty \n");
    printf("\n6)\t\tCamera\t\tAVAILABLE\t\t10000Rs - 50000Rs\t\tPMW-F5 and PMW-F55 CineAlta™ Cameras(White and Gold or Silver)+ 12 Months Seller Warranty\n\n");

    printf("Enter Product Budget In the Mentioned  Range\n\n");
    int fil1;
    cin>>fil1;
    if(fil1>=20000 && fil1<=30000)
    {
        printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");
    }
    else if(fil1>=30000 && fil1<=40000)
    {
    printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>=10000 && fil1<=20000)
    {
       printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>=1000 && fil1<=5000)
    {
   printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>100 && fil1<=2000)
    {
       printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }

   }

   else if(nm1==5)
   {
    printf("\n(Product Id)\tProducts\tCheck Avalability\tPrice Range \t\t\tType \t\n\n");
    printf("\n1)\t\tLaptop\t\tAVAILABLE\t\t10000Rs - 40000Rs\t\tVAIO® Duo 13 and VAIO® Pro 11(White or Silver and Black)+ 1Year Seller Warranty \n");
    printf("\n2)\t\tMobile\t\tAVAILABLE\t\t5000Rs - 50000Rs\t\tXperia™ Z and Xperia™ ZL(White or Black and Gold)+ 10 Months Seller Warranty\n");
    printf("\n3)\t\tTablet\t\tAVAILABLE\t\t5000Rs - 20000Rs\t\tXperia™ Tablet Z(White)+5 Months Seller Warranty \n");
    printf("\n4)\t\tHeadphone\tAVAILABLE\t\t1000Rs - 8000Rs\t\t\tSony MDR-ZX110 On-Ear Stereo Headphones (Black and White)+3 Months Seller Warranty \n");
    printf("\n5)\t\tBluetooth\tAVAILABLE\t\t1000Rs - 4000Rs\t\t\tSony SBH54 Black Stereo Bluetooth(Black)+2 Months Seller Warranty \n");
    printf("\n6)\t\tCamera\t\tAVAILABLE\t\t10000Rs - 50000Rs\t\tPMW-F5 and PMW-F55 CineAlta™ Cameras(White and Gold or Silver)+ 12 Months Seller Warranty\n\n");

    printf("Enter Product Budget In the Mentioned  Range\n\n");
    int fil1;
    cin>>fil1;
    if(fil1>=20000 && fil1<=30000)
    {
        printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");
    }
    else if(fil1>=30000 && fil1<=40000)
    {
    printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>=10000 && fil1<=20000)
    {
       printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>=1000 && fil1<=5000)
    {
   printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>100 && fil1<=2000)
    {
       printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }


   }
   else if(nm1==6)
   {

    printf("\n(Product Id)\tProducts\tCheck Avalability\tPrice Range \t\t\tType \t\n\n");
    printf("\n1)\t\tLaptop\t\tAVAILABLE\t\t10000Rs - 40000Rs\t\tVAIO® Duo 13 and VAIO® Pro 11(White or Silver and Black)+ 1Year Seller Warranty \n");
    printf("\n2)\t\tMobile\t\tAVAILABLE\t\t5000Rs - 50000Rs\t\tXperia™ Z and Xperia™ ZL(White or Black and Gold)+ 10 Months Seller Warranty\n");
    printf("\n3)\t\tTablet\t\tAVAILABLE\t\t5000Rs - 20000Rs\t\tXperia™ Tablet Z(White)+5 Months Seller Warranty \n");
    printf("\n4)\t\tHeadphone\tAVAILABLE\t\t1000Rs - 8000Rs\t\t\tSony MDR-ZX110 On-Ear Stereo Headphones (Black and White)+3 Months Seller Warranty \n");
    printf("\n5)\t\tBluetooth\tAVAILABLE\t\t1000Rs - 4000Rs\t\t\tSony SBH54 Black Stereo Bluetooth(Black)+2 Months Seller Warranty \n");
    printf("\n6)\t\tCamera\t\tAVAILABLE\t\t10000Rs - 50000Rs\t\tPMW-F5 and PMW-F55 CineAlta™ Cameras(White and Gold or Silver)+ 12 Months Seller Warranty\n\n");

    printf("Enter Product Budget In the Mentioned  Range\n\n");
    int fil1;
    cin>>fil1;
    if(fil1>=20000 && fil1<=30000)
    {
        printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");
    }
    else if(fil1>=30000 && fil1<=40000)
    {
    printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>=10000 && fil1<=20000)
    {
       printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>=1000 && fil1<=5000)
    {
   printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>100 && fil1<=2000)
    {
       printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
   }
   else
   {
       printf("\n\nSorry Pleas Enter valid key\n");
   }

   //end of the loope

    }

    //second store options
    else if(n==2)
    {

    printf("\nId)\tCompany Name\n\n");
	printf("1)Acme Fresh Market\n");
	printf("2)Affiliated Foods\n");
	printf("3)AppleTree Markets\n");
	printf("4)Arden Group Markets\n");
	printf("5)Bottom Dollar Food\n");
	printf("6)Bristol Farms\n\n");
	printf("\n Enter Id For Choose Company \nn");
	int nm2;
	cin>>nm2;
    if(nm2==1)
    {
    printf("\n(Product Id)\tProducts\tCheck Avalability\tPrice Range \t\t\tQuality \t\n\n");
    printf("\n1)\t\tSugar \t\tAVAILABLE\t\t100Rs - 4000Rs\t\t\tFresh \n");
    printf("\n2)\t\tGrains\t\tAVAILABLE\t\t50Rs - 500Rs\t\t\tOriginal\n");
    printf("\n3)\t\tVegetables\tAVAILABLE\t\t50Rs - 200Rs\t\t\tFresh \n");
    printf("\n4)\t\tDairy\t\tAVAILABLE\t\t100Rs - 300Rs\t\t\tFresh \n");
    printf("\n5)\t\tNuts And Seeds\tAVAILABLE\t\t200Rs - 1000Rs\t\t\tFresh\n");
    printf("\n6)\t\tFruits\t\tAVAILABLE\t\t40Rs - 500Rs\t\t\tFresh\n\n");
 printf("Enter Product Budget In the Mentioned  Range\n\n");
    int fil1;
    cin>>fil1;
    if(fil1>=20 && fil1<=300)
    {
        printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");
    }
    else if(fil1>=100 && fil1<=1000)
    {
    printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>=10 && fil1<=200)
    {
       printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>=10 && fil1<=500)
    {
   printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>400 && fil1<=1000)
    {
       printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    }
    else if(nm2==2)
    {
    printf("\n(Product Id)\tProducts\tCheck Avalability\tPrice Range \t\t\tQuality \t\n\n");
    printf("\n1)\t\tSugar \t\tAVAILABLE\t\t100Rs - 4000Rs\t\t\tFresh \n");
    printf("\n2)\t\tGrains\t\tAVAILABLE\t\t50Rs - 500Rs\t\t\tOriginal\n");
    printf("\n3)\t\tVegetables\tAVAILABLE\t\t50Rs - 200Rs\t\t\tFresh \n");
    printf("\n4)\t\tDairy\t\tAVAILABLE\t\t100Rs - 300Rs\t\t\tFresh \n");
    printf("\n5)\t\tNuts And Seeds\tAVAILABLE\t\t200Rs - 1000Rs\t\t\tFresh\n");
    printf("\n6)\t\tFruits\t\tAVAILABLE\t\t40Rs - 500Rs\t\t\tFresh\n\n");
 printf("Enter Product Budget In the Mentioned  Range\n\n");
    int fil1;
    cin>>fil1;
    if(fil1>=200 && fil1<=3000)
    {
        printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");
    }
    else if(fil1>=20 && fil1<=400)
    {
    printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>=100 && fil1<=700)
    {
       printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>=50 && fil1<=500)
    {
   printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>100 && fil1<=2000)
    {
       printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }

    }
   else if(nm2==3)
   {

    printf("\n(Product Id)\tProducts\tCheck Avalability\tPrice Range \t\t\tQuality \t\n\n");
    printf("\n1)\t\tSugar \t\tAVAILABLE\t\t100Rs - 4000Rs\t\t\tFresh \n");
    printf("\n2)\t\tGrains\t\tAVAILABLE\t\t50Rs - 500Rs\t\t\tOriginal\n");
    printf("\n3)\t\tVegetables\tAVAILABLE\t\t50Rs - 200Rs\t\t\tFresh \n");
    printf("\n4)\t\tDairy\t\tAVAILABLE\t\t100Rs - 300Rs\t\t\tFresh \n");
    printf("\n5)\t\tNuts And Seeds\tAVAILABLE\t\t200Rs - 1000Rs\t\t\tFresh\n");
    printf("\n6)\t\tFruits\t\tAVAILABLE\t\t40Rs - 500Rs\t\t\tFresh\n\n");
 printf("Enter Product Budget In the Mentioned  Range\n\n");
    int fil1;
    cin>>fil1;
    if(fil1>=200 && fil1<=300)
    {
        printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");
    }
    else if(fil1>=100 && fil1<=400)
    {
    printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>=100 && fil1<=500)
    {
       printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>=100 && fil1<=500)
    {
   printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>100 && fil1<=900)
    {
       printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }

   }

   else if(nm2==4)
   {

    printf("\n(Product Id)\tProducts\tCheck Avalability\tPrice Range \t\t\tQuality \t\n\n");
    printf("\n1)\t\tSugar \t\tAVAILABLE\t\t100Rs - 4000Rs\t\t\tFresh \n");
    printf("\n2)\t\tGrains\t\tAVAILABLE\t\t50Rs - 500Rs\t\t\tOriginal\n");
    printf("\n3)\t\tVegetables\tAVAILABLE\t\t50Rs - 200Rs\t\t\tFresh \n");
    printf("\n4)\t\tDairy\t\tAVAILABLE\t\t100Rs - 300Rs\t\t\tFresh \n");
    printf("\n5)\t\tNuts And Seeds\tAVAILABLE\t\t200Rs - 1000Rs\t\t\tFresh\n");
    printf("\n6)\t\tFruits\t\tAVAILABLE\t\t40Rs - 500Rs\t\t\tFresh\n\n");
 printf("Enter Product Budget In the Mentioned  Range\n\n");
    int fil1;
    cin>>fil1;
    if(fil1>=100 && fil1<=900)
    {
        printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");
    }
    else if(fil1>=300 && fil1<=900)
    {
    printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>=100 && fil1<=2000)
    {
       printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>=100 && fil1<=500)
    {
   printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>100 && fil1<=2000)
    {
       printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
   }

   else if(nm2==5)
   {

    printf("\n(Product Id)\tProducts\tCheck Avalability\tPrice Range \t\t\tQuality \t\n\n");
    printf("\n1)\t\tSugar \t\tAVAILABLE\t\t100Rs - 4000Rs\t\t\tFresh \n");
    printf("\n2)\t\tGrains\t\tAVAILABLE\t\t50Rs - 500Rs\t\t\tOriginal\n");
    printf("\n3)\t\tVegetables\tAVAILABLE\t\t50Rs - 200Rs\t\t\tFresh \n");
    printf("\n4)\t\tDairy\t\tAVAILABLE\t\t100Rs - 300Rs\t\t\tFresh \n");
    printf("\n5)\t\tNuts And Seeds\tAVAILABLE\t\t200Rs - 1000Rs\t\t\tFresh\n");
    printf("\n6)\t\tFruits\t\tAVAILABLE\t\t40Rs - 500Rs\t\t\tFresh\n\n");
 printf("Enter Product Budget In the Mentioned  Range\n\n");
    int fil1;
    cin>>fil1;
    if(fil1>=200 && fil1<=600)
    {
        printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");
    }
    else if(fil1>=000 && fil1<=4000)
    {
    printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>=100 && fil1<=2000)
    {
       printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>=100 && fil1<=500)
    {
   printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>100 && fil1<=2000)
    {
       printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
   }
   else if(nm2==6)
   {

    printf("\n(Product Id)\tProducts\tCheck Avalability\tPrice Range \t\t\tQuality \t\n\n");
    printf("\n1)\t\tSugar \t\tAVAILABLE\t\t100Rs - 4000Rs\t\t\tFresh \n");
    printf("\n2)\t\tGrains\t\tAVAILABLE\t\t50Rs - 500Rs\t\t\tOriginal\n");
    printf("\n3)\t\tVegetables\tAVAILABLE\t\t50Rs - 200Rs\t\t\tFresh \n");
    printf("\n4)\t\tDairy\t\tAVAILABLE\t\t100Rs - 300Rs\t\t\tFresh \n");
    printf("\n5)\t\tNuts And Seeds\tAVAILABLE\t\t200Rs - 1000Rs\t\t\tFresh\n");
    printf("\n6)\t\tFruits\t\tAVAILABLE\t\t40Rs - 500Rs\t\t\tFresh\n\n");
 printf("Enter Product Budget In the Mentioned  Range\n\n");
    int fil1;
    cin>>fil1;
    if(fil1>=20 && fil1<=300)
    {
        printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");
    }
    else if(fil1>=30 && fil1<=4000)
    {
    printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>=100 && fil1<=2000)
    {
       printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>=100 && fil1<=5000)
    {
   printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>100 && fil1<=2000)
    {
       printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }

   }
   else if(nm2==7)
   {

    printf("\n(Product Id)\tProducts\tCheck Avalability\tPrice Range \t\t\tQuality \t\n\n");
    printf("\n1)\t\tSugar \t\tAVAILABLE\t\t100Rs - 4000Rs\t\t\tFresh \n");
    printf("\n2)\t\tGrains\t\tAVAILABLE\t\t50Rs - 500Rs\t\t\tOriginal\n");
    printf("\n3)\t\tVegetables\tAVAILABLE\t\t50Rs - 200Rs\t\t\tFresh \n");
    printf("\n4)\t\tDairy\t\tAVAILABLE\t\t100Rs - 300Rs\t\t\tFresh \n");
    printf("\n5)\t\tNuts And Seeds\tAVAILABLE\t\t200Rs - 1000Rs\t\t\tFresh\n");
    printf("\n6)\t\tFruits\t\tAVAILABLE\t\t40Rs - 500Rs\t\t\tFresh\n\n");
 printf("Enter Product Budget In the Mentioned  Range\n\n");
    int fil1;
    cin>>fil1;
    if(fil1>=200 && fil1<=3000)
    {
        printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");
    }
    else if(fil1>=100 && fil1<=4000)
    {
    printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>=100 && fil1<=2000)
    {
       printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>=50 && fil1<=500)
    {
   printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>100 && fil1<=2000)
    {
       printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }

   }
   else if(nm2==8)
   {

    printf("\n(Product Id)\tProducts\tCheck Avalability\tPrice Range \t\t\tQuality \t\n\n");
    printf("\n1)\t\tSugar \t\tAVAILABLE\t\t100Rs - 4000Rs\t\t\tFresh \n");
    printf("\n2)\t\tGrains\t\tAVAILABLE\t\t50Rs - 500Rs\t\t\tOriginal\n");
    printf("\n3)\t\tVegetables\tAVAILABLE\t\t50Rs - 200Rs\t\t\tFresh \n");
    printf("\n4)\t\tDairy\t\tAVAILABLE\t\t100Rs - 300Rs\t\t\tFresh \n");
    printf("\n5)\t\tNuts And Seeds\tAVAILABLE\t\t200Rs - 1000Rs\t\t\tFresh\n");
    printf("\n6)\t\tFruits\t\tAVAILABLE\t\t40Rs - 500Rs\t\t\tFresh\n\n");
 printf("Enter Product Budget In the Mentioned  Range\n\n");
    int fil1;
    cin>>fil1;
    if(fil1>=200 && fil1<=3000)
    {
        printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");
    }
    else if(fil1>=30 && fil1<=400)
    {
    printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>=10 && fil1<=3000)
    {
       printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>=100 && fil1<=500)
    {
   printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>100 && fil1<=2000)
    {
       printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }

   }
   else if(nm2==9)
    {

    printf("\n(Product Id)\tProducts\tCheck Avalability\tPrice Range \t\t\tQuality \t\n\n");
    printf("\n1)\t\tSugar \t\tAVAILABLE\t\t100Rs - 4000Rs\t\t\tFresh \n");
    printf("\n2)\t\tGrains\t\tAVAILABLE\t\t50Rs - 500Rs\t\t\tOriginal\n");
    printf("\n3)\t\tVegetables\tAVAILABLE\t\t50Rs - 200Rs\t\t\tFresh \n");
    printf("\n4)\t\tDairy\t\tAVAILABLE\t\t100Rs - 300Rs\t\t\tFresh \n");
    printf("\n5)\t\tNuts And Seeds\tAVAILABLE\t\t200Rs - 1000Rs\t\t\tFresh\n");
    printf("\n6)\t\tFruits\t\tAVAILABLE\t\t40Rs - 500Rs\t\t\tFresh\n\n");
 printf("Enter Product Budget In the Mentioned  Range\n\n");
    int fil1;
    cin>>fil1;
    if(fil1>=20 && fil1<=300)
    {
        printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");
    }
    else if(fil1>=300 && fil1<=4000)
    {
    printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>=100 && fil1<=2000)
    {
       printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>=100 && fil1<=5000)
    {
   printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>100 && fil1<=2000)
    {
       printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
   }
   else
   {
       printf("\n\nSorry Pleas Enter valid key\n");
   }

//end of the second  else if loop
    }

    //start 3 else if loop
    else if(n==3)
    {

    printf("\nId)\tCompany Name\n\n");
	printf("1)\tRaw\n");
	printf("2)\tWalmart\n");
	printf("3)\tTreasure\n");
	printf("4)\tLux\n");
	printf("\n Enter Id For Choose Company \n ");
	int nm3;
	cin>>nm3;
    if(nm3==1)
    {
    printf("\n(Product Id)\tProducts\tCheck Avalability\tPrice Range \t\t\tQuality \t\n\n");
    printf("\n1)\t\tSoap And Shampoo  AVAILABLE\t\t100Rs - 4000Rs\t\t\tFresh \n");
    printf("\n2)\t\tBooks\t\tAVAILABLE\t\t50Rs - 500Rs\t\t\tOriginal\n");
    printf("\n3)\t\tSpray\t\tAVAILABLE\t\t50Rs - 200Rs\t\t\tFresh \n");
    printf("\n4)\t\tGifts\t\tAVAILABLE\t\t100Rs - 300Rs\t\t\tFresh \n");
    printf("Enter Product Budget In the Mentioned  Range\n\n");
    int fil1;
    cin>>fil1;
    if(fil1>=200 && fil1<=3000)
    {
        printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");
    }
    else if(fil1>=20 && fil1<=400)
    {
    printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>=100 && fil1<=700)
    {
       printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>=50 && fil1<=500)
    {
   printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>100 && fil1<=2000)
    {
       printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }


    }
    else if(nm3==2)
    {

   printf("\n(Product Id)\tProducts\tCheck Avalability\tPrice Range \t\t\tQuality \t\n\n");
    printf("\n1)\t\tSoap And Shampoo  AVAILABLE\t\t100Rs - 4000Rs\t\t\tFresh \n");
    printf("\n2)\t\tBooks\t\tAVAILABLE\t\t50Rs - 500Rs\t\t\tOriginal\n");
    printf("\n3)\t\tSpray\t\tAVAILABLE\t\t50Rs - 200Rs\t\t\tFresh \n");
    printf("\n4)\t\tGifts\t\tAVAILABLE\t\t100Rs - 300Rs\t\t\tFresh \n");
    printf("Enter Product Budget In the Mentioned  Range\n\n");
    int fil1;
    cin>>fil1;
    if(fil1>=200 && fil1<=3000)
    {
        printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");
    }
    else if(fil1>=20 && fil1<=400)
    {
    printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>=100 && fil1<=700)
    {
       printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>=50 && fil1<=500)
    {
   printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>100 && fil1<=2000)
    {
       printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }



    }
   else if(nm3==3)
   {
    printf("\n(Product Id)\tProducts\tCheck Avalability\tPrice Range \t\t\tQuality \t\n\n");
    printf("\n1)\t\tSoap And Shampoo  AVAILABLE\t\t100Rs - 4000Rs\t\t\tFresh \n");
    printf("\n2)\t\tBooks\t\tAVAILABLE\t\t50Rs - 500Rs\t\t\tOriginal\n");
    printf("\n3)\t\tSpray\t\tAVAILABLE\t\t50Rs - 200Rs\t\t\tFresh \n");
    printf("\n4)\t\tGifts\t\tAVAILABLE\t\t100Rs - 300Rs\t\t\tFresh \n");
    printf("Enter Product Budget In the Mentioned  Range\n\n");
    int fil1;
    cin>>fil1;
    if(fil1>=200 && fil1<=3000)
    {
        printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");
    }
    else if(fil1>=20 && fil1<=400)
    {
    printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>=100 && fil1<=700)
    {
       printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>=50 && fil1<=500)
    {
   printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>100 && fil1<=2000)
    {
       printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }


   }

   else if(nm3==4)
   {
    printf("\n(Product Id)\tProducts\tCheck Avalability\tPrice Range \t\t\tQuality \t\n\n");
    printf("\n1)\t\tSoap And Shampoo  AVAILABLE\t\t100Rs - 4000Rs\t\t\tFresh \n");
    printf("\n2)\t\tBooks\t\tAVAILABLE\t\t50Rs - 500Rs\t\t\tOriginal\n");
    printf("\n3)\t\tSpray\t\tAVAILABLE\t\t50Rs - 200Rs\t\t\tFresh \n");
    printf("\n4)\t\tGifts\t\tAVAILABLE\t\t100Rs - 300Rs\t\t\tFresh \n");
    printf("Enter Product Budget In the Mentioned  Range\n\n");
    int fil1;
    cin>>fil1;
    if(fil1>=200 && fil1<=3000)
    {
        printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");
    }
    else if(fil1>=20 && fil1<=400)
    {
    printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>=100 && fil1<=700)
    {
       printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>=50 && fil1<=500)
    {
   printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>100 && fil1<=2000)
    {
       printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }


   }

   else if(nm3==5)
   {
    printf("\n(Product Id)\tProducts\tCheck Avalability\tPrice Range \t\t\tQuality \t\n\n");
    printf("\n1)\t\tSoap And Shampoo  AVAILABLE\t\t100Rs - 4000Rs\t\t\tFresh \n");
    printf("\n2)\t\tBooks\t\tAVAILABLE\t\t50Rs - 500Rs\t\t\tOriginal\n");
    printf("\n3)\t\tSpray\t\tAVAILABLE\t\t50Rs - 200Rs\t\t\tFresh \n");
    printf("\n4)\t\tGifts\t\tAVAILABLE\t\t100Rs - 300Rs\t\t\tFresh \n");
    printf("Enter Product Budget In the Mentioned  Range\n\n");
    int fil1;
    cin>>fil1;
    if(fil1>=200 && fil1<=3000)
    {
        printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");
    }
    else if(fil1>=20 && fil1<=400)
    {
    printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>=100 && fil1<=700)
    {
       printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>=50 && fil1<=500)
    {
   printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>100 && fil1<=2000)
    {
       printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }


   }
   else if(nm3==6)
   {
    printf("\n(Product Id)\tProducts\tCheck Avalability\tPrice Range \t\t\tQuality \t\n\n");
    printf("\n1)\t\tSoap And Shampoo  AVAILABLE\t\t100Rs - 4000Rs\t\t\tFresh \n");
    printf("\n2)\t\tBooks\t\tAVAILABLE\t\t50Rs - 500Rs\t\t\tOriginal\n");
    printf("\n3)\t\tSpray\t\tAVAILABLE\t\t50Rs - 200Rs\t\t\tFresh \n");
    printf("\n4)\t\tGifts\t\tAVAILABLE\t\t100Rs - 300Rs\t\t\tFresh \n");
    printf("Enter Product Budget In the Mentioned  Range\n\n");
    int fil1;
    cin>>fil1;
    if(fil1>=200 && fil1<=3000)
    {
        printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");
    }
    else if(fil1>=20 && fil1<=400)
    {
    printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>=100 && fil1<=700)
    {
       printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>=50 && fil1<=500)
    {
   printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>100 && fil1<=2000)
    {
       printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }


   }
   else if(nm3==7)
   {
   printf("\n(Product Id)\tProducts\tCheck Avalability\tPrice Range \t\t\tQuality \t\n\n");
    printf("\n1)\t\tSoap And Shampoo  AVAILABLE\t\t100Rs - 4000Rs\t\t\tFresh \n");
    printf("\n2)\t\tBooks\t\tAVAILABLE\t\t50Rs - 500Rs\t\t\tOriginal\n");
    printf("\n3)\t\tSpray\t\tAVAILABLE\t\t50Rs - 200Rs\t\t\tFresh \n");
    printf("\n4)\t\tGifts\t\tAVAILABLE\t\t100Rs - 300Rs\t\t\tFresh \n");
    printf("Enter Product Budget In the Mentioned  Range\n\n");
    int fil1;
    cin>>fil1;
    if(fil1>=200 && fil1<=3000)
    {
        printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");
    }
    else if(fil1>=20 && fil1<=400)
    {
    printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>=100 && fil1<=700)
    {
       printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>=50 && fil1<=500)
    {
   printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>100 && fil1<=2000)
    {
       printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }


   }
   else if(nm3==8)
   {
    printf("\n(Product Id)\tProducts\tCheck Avalability\tPrice Range \t\t\tQuality \t\n\n");
    printf("\n1)\t\tSoap And Shampoo  AVAILABLE\t\t100Rs - 4000Rs\t\t\tFresh \n");
    printf("\n2)\t\tBooks\t\tAVAILABLE\t\t50Rs - 500Rs\t\t\tOriginal\n");
    printf("\n3)\t\tSpray\t\tAVAILABLE\t\t50Rs - 200Rs\t\t\tFresh \n");
    printf("\n4)\t\tGifts\t\tAVAILABLE\t\t100Rs - 300Rs\t\t\tFresh \n");
    printf("Enter Product Budget In the Mentioned  Range\n\n");
    int fil1;
    cin>>fil1;
    if(fil1>=200 && fil1<=3000)
    {
        printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");
    }
    else if(fil1>=20 && fil1<=400)
    {
    printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>=100 && fil1<=700)
    {
       printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>=50 && fil1<=500)
    {
   printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>100 && fil1<=2000)
    {
       printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }


   }
   else if(nm3==9)
    {
   printf("\n(Product Id)\tProducts\tCheck Avalability\tPrice Range \t\t\tQuality \t\n\n");
    printf("\n1)\t\tSoap And Shampoo  AVAILABLE\t\t100Rs - 4000Rs\t\t\tFresh \n");
    printf("\n2)\t\tBooks\t\tAVAILABLE\t\t50Rs - 500Rs\t\t\tOriginal\n");
    printf("\n3)\t\tSpray\t\tAVAILABLE\t\t50Rs - 200Rs\t\t\tFresh \n");
    printf("\n4)\t\tGifts\t\tAVAILABLE\t\t100Rs - 300Rs\t\t\tFresh \n");
    printf("Enter Product Budget In the Mentioned  Range\n\n");
    int fil1;
    cin>>fil1;
    if(fil1>=200 && fil1<=3000)
    {
        printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");
    }
    else if(fil1>=20 && fil1<=400)
    {
    printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>=100 && fil1<=700)
    {
       printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>=50 && fil1<=500)
    {
   printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }
    else if(fil1>100 && fil1<=2000)
    {
       printf("Enter Product Id:  \n");
        cin>>t_ph;
        printf("Enter Product Name:  \n");
        cin>>person;
        st = gets(t_ph);
        connection(person,st);
		create(t_ph,person);
		if (root == NULL)
        root = temp;
		else
		search_node(root);
        printf("Successfully Added Product\n\n");

    }

   }
   else
   {
       printf("\n\nSorry Pleas Enter valid key\n");
   }


// end of the third else if  loop
    }

    else if(n==4)
    {
    printf("\nId)\tCompany Name\n\n");
	printf("1)\tSoap And Shampoo\n");
	printf("2)\tBooks\n");
	printf("3)\tGifts\n");
	printf("4)\tSpray\n");
	printf("5)\t\n");
	printf("6)\tGodrej\n");
	printf("7)\tMicromax\n");
	printf("8)\tI-ball\n");
	printf("9)\tSamsung \n\n");
	printf("\n Enter Id For Choose Company \n ");
	int nm4;
	cin>>nm4;
    if(nm4==1)
    {


    }
    else if(nm4==2)
    {


    }
   else if(nm4==3)
   {


   }

   else if(nm4==4)
   {


   }

   else if(nm4==5)
   {


   }
   else if(nm4==6)
   {


   }
   else if(nm4==7)
   {


   }
   else if(nm4==8)
   {


   }
   else if(nm4==9)
    {

   }
   else
   {
       printf("\n\nSorry Pleas Enter valid key\n");
   }

    }

    else if(n==5)
    {
    printf("\nId)\tCompany Name\n\n");
	printf("1)\tSony\n");
	printf("2)\tVivo\n");
	printf("3)\tLenovo\n");
	printf("4)\tDell\n");
	printf("5)\tJ-bell\n");
	printf("6)\tGodrej\n");
	printf("7)\tMicromax\n");
	printf("8)\tI-ball\n");
	printf("9)\tSamsung \n\n");
	printf("\n Enter Id For Choose Company \n ");
	int nm5;
	cin>>nm5;
    if(nm5==1)
    {


    }
    else if(nm5==2)
    {


    }
   else if(nm5==3)
   {


   }

   else if(nm5==4)
   {


   }

   else if(nm5==5)
   {


   }
   else if(nm5==6)
   {


   }
   else if(nm5==7)
   {


   }
   else if(nm5==8)
   {


   }
   else if(nm5==9)
    {

   }
   else
   {
       printf("\n\nSorry Pleas Enter valid key\n");
   }

//end of the third else if loop

   // end of the 6 else if loop
    }



}



