#include<bits/stdc++.h>
using namespace std;
void display(struct node *tree);
void search_node(struct node *tree);
void create(unsigned long long int ph,char* name);
void insert();
void search_no(struct node *tree,char* n) ;
void search_person(char* person);
struct node* minValueNode(struct node* node);
void write(struct node* tree);
struct node* deleteNode(struct node* root, unsigned long long int key);

struct node
{   unsigned long long int ph;
    char name[20];
    struct node* l;
    struct node* r;
}*root = NULL,*temp = NULL;

int a = 0;
unsigned long long int p = 0;
FILE *f;

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
    printf("%s - %llu",tree->name,tree->ph);
    if(tree->l != NULL)
        printf("  (L:%s - %llu)",tree->l->name,tree->l->ph);
    if(tree->r != NULL)
        printf("  (R:%s - %llu)",tree->r->name,tree->r->ph);
    printf("\n");
    display(tree->l);
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

//used to write final bst into file.
int productlist()
{
	printf("\nCompany Name-Samsung\t  Prodct Id - 1  \t Product Name - Laptop     \n");
	printf("\nCompany Name - Sony  \t  Prodct Id - 2  \t Product Name - Phone     \n");
	printf("\n\nCompany Name - Vivo  \t  Prodct Id - 3  \t Product Name - i-pad    \n");
	printf("\n\nCompany Name - Lenovo  \t  Prodct Id - 4  \t Product Name - Smart Phone    \n");
	printf("\n\nCompany Name - Dell  \t  Prodct Id - 5  \t Product Name - Tablet    \n");
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


int main()
{
printf("\n\t\t\t\t\t\t\t\t\tWelcome to Mega Store\n\n");
	int c;
	load();
	while(1)
	{	printf("\n\n\tChoose Options:\t");
		printf("\n\n1. Search Products By Company Name  2. Ordered Products     3.Cancel Order     4. Display Order All Products   5.Display All the Product List   6. Exit \n");
		printf("\n\n\nEnter your option:\t");
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
						printf("\Product not Found!!\n");
				}
				break;

			case 2:
				unsigned long long int t_ph;
				printf("\nEnter Product's name:\t");
				scanf("%s",&person);
				printf("\nEnter Product's Id:\t");
				scanf("%llu",&t_ph);
				create(t_ph,person);
				if (root == NULL)
					root = temp;
		    	else
					search_node(root);
				break;

			case 3:
				//a = 0;char person[20];
				printf("\nEnter Any Product Name to be deleted:\t");
				scanf("%s",&person);
				search_person(person);
				if(root != NULL){
					if(p!=0)
						{	root = deleteNode(root,p);		}
					else
						printf("\nThis Product '%s' doesn't exist\n",person);
				}
				break;

			case 4:
				if(root!= NULL)
				{
					printf("\n\t\tALL THE ORDERED PRODUCT - \n\n");
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





