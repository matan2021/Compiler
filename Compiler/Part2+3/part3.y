%{
	#define _GNU_SOURCE
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "lex.yy.c"
	

	typedef enum {false,true}bool;
	typedef struct node
	{
		char *token;
		struct node *left;
		struct node *right;
		char *code;
		char *var;
		char *label;
		char *truelabel;
		char *falselabel;
		int sum;

	} node;

	typedef struct Arguments
	{
		char * name;
		char * type;
		char * len;
	}Arguments;

    typedef struct Function 
	{
        char * name;
		struct Arguments * args;
        char *returnType; 
		int countArgs;
		int findreturn;
    } Function;
	

	typedef struct Varaiables
	{	int isArg;
		char *name;
		char *value;
		char *type;
		char * len;
	}Varaiable;

		typedef struct code
	{	
		int place;
		char *name;
		Varaiable * var;
		int countvar;
		int countfunc;
		Function ** func;
		struct code * nextLVL;
		struct code * beforeLVL;
	}code;
	char * exprtype(node *,code*);
	Arguments * makeArgs(node *,int *);
	void addFunc(char * name,Arguments * args,node *returnType,int countArgs,code*);
	void addvar(Arguments * args,int,int,code * CODEscope);
	code* makeCode(char *);
	node* makeNode(char* token, node *left, node *right);
	void Printtree(node *tree);
	void printTabs(int n);
	int yylex();
	int yyerror(char *e);
	void push(code* from,char*);
	int printlevel=0;
	code* mycode=NULL;
	static node* myroot=NULL;
	code* lastCode(code * codey);
	static int scope=0;
	void CheckSyntax(node *tree,code * scope);
	char* findfunc(node * tree,code * CODEscope,int* count);
	char *findvar(node * tree,code * CODEscope);
	Arguments * callfuncargs(code *,node *tree,int * count);
	int flagMain=false;
	
		//part 3
	
	int POPParams(Arguments * args,int count);
	void addCode(node* node,char *code,char *var,char *label,char *truelabel,char *falselabel);
	void addCode2(node* node,char *code,char *var,char *label,char *truelabel,char *falselabel);
	char* freshVar();
	char* freshLabel();
	char* gen(char*,char*,char*,char*,char*);
	char* mystrcat(char*des,char*src);

	char *replaceWord(const char *s, const char *oldW, const char *newW);
	char * mkspace(char *label);
	void calc3AC(node * tree);
	static int t=0;
	static int l=0;
	static int line=0;


	
	
%}
%union
{
    struct node *node;
    char *string;
}

%token <string> COMMENT WHILE IF ELSE FOR RETURN DO 
%token <string> BOOL STRING CHARPTR CHAR INT INTPTR PROCEDUR
%token <string> AND ADDRESS EQL ASSINGMENT OR LENGTH GREATEREQL GREATER LESSEQL LESS NOTEQL NOT
%token <string> DIVISION PLUS MINUS MULTI VARIABLE
%token <string> STRING_LTL REAL_LTL CHAR_LTL NULLL
%token <string> MAIN IDENTIFIER SEMICOLON COMMA OPENPAREN CLOSEPAREN OPENBRACKET CLOSEBRACKET OPENBRACE CLOSEBRACE
%token <string> DECIMAL_LTL HEX_LTL BOOLTRUE BOOLFALSE REAL REALPTR FUNCTION COLON DEREFRENCE 

%left PLUS MINUS RETURN
%left MULTI DIVISION
%left EQL NOTEQL LESS LESSEQL GREATEREQL GREATER OR AND
%left SEMICOLON 
%right NOT CLOSEBRACE

%nonassoc IDENTIFIER 
%nonassoc OPENPAREN
%nonassoc IF
%nonassoc ELSE 

%type <node> address_expr address_exprs stmnts stmnt_block derefrence_expr expr_list call_func 
%type <node> expr lhs assmnt_stmnt new_block 
%type <node> stmnt type_pro type_id var_id declear var_id_str paren_expr 
%type <node> pro_body para_list para_pro procedure procedures
%type <node> the_main program project declears 
%%

//main project
project: cmmnt program { myroot=$2;
					 	 CheckSyntax($2,mycode);
					 	 calc3AC($2);
						}; 

program: procedures the_main {$$=makeNode("CODE",$1,$2);}

//comments
cmmnt: cmmnt COMMENT| ;

//this is the main program
the_main: type_pro MAIN OPENPAREN CLOSEPAREN OPENBRACE pro_body CLOSEBRACE
	{ $$=makeNode("main",makeNode("Return",$1,NULL),$6);
	t=0;}
	| FUNCTION MAIN OPENPAREN CLOSEPAREN OPENBRACE pro_body CLOSEBRACE
	{ $$=makeNode("main",NULL,$6);
	  t=0;}	

//functions
procedures: procedures procedure {$$=makeNode("procedures",$1,$2);} | {$$=NULL;};

//function
procedure: type_pro IDENTIFIER OPENPAREN para_pro CLOSEPAREN OPENBRACE pro_body CLOSEBRACE
	   { $$=makeNode("func",makeNode($2,makeNode("ARGS",$4,NULL)
	   ,makeNode("Return",$1,NULL)),$7);
	   t=0;}
	   | FUNCTION IDENTIFIER OPENPAREN para_pro CLOSEPAREN OPENBRACE pro_body CLOSEBRACE
	   { $$=makeNode("func",makeNode($2,makeNode("ARGS",$4,NULL),NULL),$7);t=0;};

//list of parameter for function or not
para_pro: para_list {$$=$1;} | {$$=NULL;};

//list of parameter
para_list: type_id var_id {$$=makeNode("(",$1,makeNode("",$2,makeNode(")",NULL,NULL)));}
	 | para_list SEMICOLON cmmnt para_list
	   {$$=makeNode("",$1,makeNode("",$4,NULL));};

//Procedure body
pro_body: cmmnt procedures declears stmnts
	  { $$=makeNode("BODY", makeNode("",$2,NULL),makeNode("",$3,makeNode("",$4,NULL)));};

//list of declears
declears: declears declear {$$=makeNode("",$1,$2);} | {$$=NULL;};

//declaration of varibals
declear: VARIABLE type_id var_id cmmnt SEMICOLON cmmnt
	 { $$=makeNode("var", $2 ,$3);}
	| STRING var_id_str SEMICOLON {$$=$2;};

//list of id
var_id: IDENTIFIER COMMA var_id {$$=makeNode($1, makeNode(",", $3, NULL),NULL);}
	| IDENTIFIER 		{$$=makeNode($1, NULL, NULL);} 
	| assmnt_stmnt 		{$$=makeNode("",$1,NULL);};

//declare string
var_id_str: IDENTIFIER OPENBRACKET expr CLOSEBRACKET 
	    {$$=makeNode("var", makeNode("string",makeNode("",$3,NULL), NULL),
		 makeNode($1,NULL,NULL));}
	  | IDENTIFIER OPENBRACKET expr CLOSEBRACKET COMMA var_id_str
	    {$$=makeNode("", makeNode("var", makeNode("string",makeNode("",$3,NULL), NULL), makeNode($1,NULL,NULL)), $6);}
	  | assmnt_stmnt {$$=makeNode("",$1,NULL);};

//types without string
type_id: BOOL {$$=makeNode("boolean", NULL, NULL);}
	| CHAR {$$=makeNode("char", NULL, NULL);}
	| INT {$$=makeNode("int", NULL, NULL);}
	| REAL {$$=makeNode("real", NULL, NULL);}
	| INTPTR {$$=makeNode("int*", NULL, NULL);}
	| CHARPTR {$$=makeNode("char*", NULL, NULL);}
	| REALPTR {$$=makeNode("real*", NULL, NULL);};

//type for returning from a function
type_pro: BOOL {$$=makeNode("boolean", NULL, NULL);}
	| CHAR {$$=makeNode("char", NULL, NULL);}
	| INT {$$=makeNode("int", NULL, NULL);}
	| REAL {$$=makeNode("real", NULL, NULL);}
	| INTPTR {$$=makeNode("int*", NULL, NULL);}
	| CHARPTR {$$=makeNode("char*", NULL, NULL);}
	| REALPTR {$$=makeNode("real*", NULL, NULL);};
	

//Statments
stmnts: stmnts stmnt
		{ $$=makeNode("stmnts",$1,$2);
		  if(strcmp($2->token, "if") == 0||strcmp($2->token, "for") == 0||strcmp($2->token, "if-else") == 0||
		  strcmp($2->token, "while") == 0||strcmp($2->token, "do") == 0){ if($$->sum==0) {addCode($2,NULL,NULL,freshLabel(),NULL,NULL); $$->sum=1;}}}
		| {$$=NULL;};

//stmnt_block
stmnt_block: stmnt 
			 { $$=$1;
			   if(strcmp($1->token, "if") == 0||strcmp($1->token, "for") == 0||strcmp($1->token, "if-else") == 0||
			   strcmp($1->token, "while") == 0||strcmp($1->token, "do") == 0) addCode($1,NULL,NULL,freshLabel(),NULL,NULL);}
			| declear {$$=$1;}
			| procedure {$$=$1;}
			| SEMICOLON  {$$=makeNode("",NULL,NULL);};

//new block in stmnts
new_block: OPENBRACE procedures cmmnt declears stmnts CLOSEBRACE cmmnt
	{ $$=makeNode("{",$2,
						makeNode("", $4,
										makeNode("", $5,
														makeNode("}",NULL,NULL))));};

//Statment
stmnt: IF OPENPAREN expr CLOSEPAREN stmnt_block 
	{ $$=makeNode("if",
	  makeNode("(", $3, 
	  makeNode(")",NULL,NULL)),$5);
	  addCode($3,NULL,NULL,NULL,freshLabel(),NULL);
	}%prec IF
	| IF OPENPAREN expr CLOSEPAREN stmnt_block ELSE stmnt_block  
	{ $$=makeNode("if-else",
	  makeNode("(", $3, 
	  makeNode(")",NULL,NULL)),
	  makeNode("",$5,
	  makeNode("",$7,NULL)));
	  addCode($3,NULL,NULL,NULL,freshLabel(),NULL);
	  addCode($3,NULL,NULL,NULL,NULL,freshLabel());}
	| WHILE cmmnt OPENPAREN  expr CLOSEPAREN  stmnt_block  
	{ $$=makeNode("while",
	  makeNode("(", $4, 
	  makeNode(")",NULL,NULL)),$6);
	  addCode($$,NULL,NULL,NULL,freshLabel(),NULL);
	  addCode($$,NULL,NULL,NULL,NULL,freshLabel());}
	| FOR cmmnt OPENPAREN assmnt_stmnt SEMICOLON expr SEMICOLON assmnt_stmnt CLOSEPAREN stmnt_block 
	{ $$= makeNode("for",
		makeNode("(",
		makeNode("",$4,$6),
		makeNode("",$8,
		makeNode(")",NULL,NULL))),$10);
		addCode($$,NULL,NULL,NULL,freshLabel(),NULL);
		addCode($$,NULL,NULL,NULL,NULL,freshLabel());	}
	| DO stmnt_block WHILE cmmnt OPENPAREN expr CLOSEPAREN SEMICOLON
	{ $$=makeNode("do",
		makeNode("(",$6,
		makeNode(")",NULL,NULL)),$2);
		addCode($$,NULL,NULL,NULL,freshLabel(),NULL);
	    //addCode($$,NULL,NULL,NULL,NULL,freshLabel());
	    }
	| assmnt_stmnt SEMICOLON cmmnt {$$=makeNode("",$1,NULL);}
	| expr SEMICOLON cmmnt {$$=$1;}
	| RETURN expr SEMICOLON cmmnt {$$=makeNode("return",$2,NULL);}
	| new_block {$$=$1;};

//assiment statment
assmnt_stmnt: lhs ASSINGMENT expr { $$=makeNode("=",$1,$3);};

//lefd hand side id
lhs: IDENTIFIER OPENBRACKET expr CLOSEBRACKET 
	{ $$=makeNode($1, makeNode("[",$3,makeNode("]",NULL,NULL)), NULL);} 
	| IDENTIFIER {$$=makeNode($1,NULL,NULL);}
	| address_expr {$$=$1;}
	| derefrence_expr{$$=$1;};
	
//Expresion
expr: OPENPAREN expr CLOSEPAREN {$$=makeNode("(",$2,makeNode(")",NULL,NULL));}
	//bool oper
	| expr EQL expr {$$=makeNode("==",$1,$3);}
	| expr NOTEQL expr {$$=makeNode("!=",$1,$3);}
	| expr GREATEREQL expr {$$=makeNode(">=",$1,$3);}
	| expr GREATER expr {$$=makeNode(">",$1,$3);}
	| expr LESSEQL expr {$$=makeNode("<=",$1,$3);}
	| expr LESS expr {$$=makeNode("<",$1,$3);}
	| expr AND expr {$$=makeNode("&&",$1,$3); addCode($1,NULL,NULL,NULL,freshLabel(),NULL);}
	| expr OR expr {$$=makeNode("||",$1,$3); addCode($1,NULL,NULL,NULL,NULL,freshLabel());}
	//aritmetical operator
	| expr PLUS expr {$$=makeNode("+",$1,$3);}
	| expr MINUS expr {$$=makeNode("-",$1,$3);}
	| expr MULTI expr {$$=makeNode("*",$1,$3);}
	| expr DIVISION expr {$$=makeNode("/",$1,$3);}
	//not operator
	| NOT expr {$$=makeNode("!",$2,NULL);}
	| BOOLFALSE {$$=makeNode($1,makeNode("BOOLEAN", NULL, NULL),NULL);}
	| BOOLTRUE {$$=makeNode($1,makeNode("BOOLEAN", NULL, NULL),NULL);}
	| address_exprs {$$=$1;}
	| derefrence_expr {$$=$1;}
	| call_func {$$=$1;}
	| DECIMAL_LTL {$$=makeNode($1,makeNode("INT",NULL,NULL),NULL);}
	| HEX_LTL {$$=makeNode($1,makeNode("HEX", NULL, NULL),NULL);}
	| CHAR_LTL {$$=makeNode($1,makeNode("CHAR", NULL, NULL),NULL);}
	| REAL_LTL {$$=makeNode($1,makeNode("REAL", NULL, NULL),NULL);}
	| STRING_LTL {$$=makeNode($1,makeNode("STRING", NULL, NULL),NULL);}
	| LENGTH IDENTIFIER LENGTH 
	{
		$$=makeNode("|",
		makeNode($2,NULL,NULL),
		makeNode("|",NULL,NULL));
	}
	| IDENTIFIER OPENBRACKET expr CLOSEBRACKET 
	{$$=makeNode("[",$3,makeNode("]",NULL,NULL));}
	| IDENTIFIER {$$=makeNode($1,NULL,NULL);}
	| NULLL {$$=makeNode("null",NULL,NULL);};


//address expression like &id
address_exprs:ADDRESS address_exprs {$$=makeNode($1,$2,NULL);} | address_expr {$$=$1;};

address_expr: ADDRESS IDENTIFIER {$$=makeNode("&",makeNode($2,NULL,NULL),NULL);}
	| ADDRESS OPENPAREN IDENTIFIER CLOSEPAREN {$$=makeNode("&",makeNode("(",makeNode($3,NULL,NULL),NULL),makeNode(")",NULL,NULL));}
	| ADDRESS IDENTIFIER OPENBRACKET expr CLOSEBRACKET 
	{ $$=makeNode("&", makeNode($2,NULL,NULL), makeNode("[",$4,makeNode("]",NULL,NULL)));}
	| ADDRESS OPENPAREN IDENTIFIER OPENBRACKET expr CLOSEBRACKET CLOSEPAREN 
	{ $$=makeNode("&",
	  				  makeNode("(",makeNode($3,NULL,NULL),makeNode("[",$5,NULL)), 
	  															makeNode("]",NULL,makeNode(")",NULL,NULL)));};

//value expression like *id
derefrence_expr: MULTI expr {$$=makeNode("^",makeNode("(",$2,NULL),makeNode(")",NULL,NULL));};

//list of expreession
expr_list: expr COMMA expr_list {$$=makeNode("expr_list",$1,makeNode(",",$3,NULL));} 
	 | expr {$$=makeNode("expr_list",$1,NULL);} | {$$=NULL;};

paren_expr:OPENPAREN expr_list CLOSEPAREN {$$=$2;};

//call func rul 
call_func: IDENTIFIER paren_expr {$$=makeNode("Call func",makeNode($1,NULL,NULL),makeNode("ARGS",$2,NULL));} ;

%%



int main()
{
	FILE * f=fopen("out3AC.txt","w+");
	int x= yyparse();
	if(x==0)
	{
		//printf("syntax and Semantics are valid\n"); 
		Printtree(myroot);
		fprintf(f,"%s",myroot->code);
		// printf("%s",myroot->code);
	}
	fclose(f);
	return x;	
}
Arguments * callfuncargs(code * CODEscope,node *tree,int * count)
{
	Arguments *arr=NULL,ar[50];
	char* type,*len;
	while(tree!=NULL)
	{
		ar[(*count)++].type=exprtype(tree->left,CODEscope);
		if(tree->right!=NULL)
			tree=tree->right->left;
		else
			tree=NULL;
	}
	arr=(Arguments*)malloc(sizeof(Arguments)*(*count));
	for(int i=0;i<*count;i++)
		arr[i].type=ar[i].type;
	return arr;
}
char* findfunc(node * tree,code * CODEscope,int * countParams)
{
	code*temp=CODEscope;
	Arguments* args;
	int find=false,flag=true;
	while(temp!=NULL)
	{
		for(int i=0;i<temp->countfunc;i++)
			if(strcmp(tree->left->token,temp->func[i]->name)==0)
			{
				find=true;
				flag=true;
				int count=0;
				args=callfuncargs(CODEscope,tree->right->left,&count);
				if(count==temp->func[i]->countArgs)
				{
					for(int j=0,t=count-1;j<count;j++,t--)
				{
					//printf("%s %s %s",args[j].type,temp->func[i]->args[t].type, temp->func[i]->args[t].name);
					if(strcmp(args[j].type,temp->func[i]->args[t].type)!=0)
						flag=false;
					}
					if(flag==true)
					{	if(countParams!= NULL)
							*countParams = POPParams(args,count);
						return temp->func[i]->returnType;
					}	
				}
			}
		temp=temp->beforeLVL;
	}
	printf("ERORR,func %s not find call in scope %s in func/proc %s\n",tree->left->token,CODEscope->name,mycode->func[mycode->countfunc-1]->name);
	if(find==true)
		printf("but find func with same name but other args\n");
	exit(1);
}
char *findvar(node * tree,code * CODEscope)
{
	code*temp=CODEscope;
	while(temp!=NULL)
	{
		for(int i=0;i<temp->countvar;i++)
		if(strcmp(tree->token,temp->var[i].name)==0)
		{
			if(tree->left!=NULL && strcmp(tree->left->token,"[")==0)
			{
				if(strcmp(temp->var[i].type,"string")==0)
					if(strcmp(exprtype(tree->left->left,CODEscope),"int")==0)
						return "char";
					else
					{
						printf("ERORR, index in string can be only int (<string>[<int>])in scope %s in func/proc %s\n",CODEscope->name,mycode->func[mycode->countfunc-1]->name);
						exit(1);
					}
				else
				{
					printf("ERORR,you can use index only on string type (<string>[<int>]) in scope %s in func/proc %s\n",CODEscope->name,mycode->func[mycode->countfunc-1]->name);
					exit(1);
				}
			}
			else
				return temp->var[i].type;
		}
		temp=temp->beforeLVL;
	}
	printf("ERORR,var %s not find in scope %s in func/proc %s\n ",tree->token,CODEscope->name,mycode->func[mycode->countfunc-1]->name);
	exit(1);
}
char * exprtype(node * tree,code* CODEscope){
	char* msg=(char*)malloc(sizeof(char)*7);
	msg="";
	if(strcmp(tree->token,"null")==0)
		msg="NULL";
	else
	if(tree->left!=NULL){
		if(strcmp(tree->left->token,"INT")==0)
			msg= "int";
		if(strcmp(tree->left->token,"HEX")==0)
			msg= "hex";
		if(strcmp(tree->left->token,"CHAR")==0)
			msg= "char";
		if(strcmp(tree->left->token,"REAL")==0)
			msg= "real";
		if(strcmp(tree->left->token,"STRING")==0)
			msg= "string";
		if(strcmp(tree->left->token,"BOOLEAN")==0)
			msg= "boolean";
		if(strcmp(tree->token,"-")==0||strcmp(tree->token,"+")==0)
		{
			if((strcmp(exprtype(tree->left,CODEscope),"int")==0||strcmp(exprtype(tree->left,CODEscope),"real")==0)&&(strcmp(exprtype(tree->right,CODEscope),"int")==0||strcmp(exprtype(tree->right,CODEscope),"real")==0))
			{
				if(strcmp(exprtype(tree->left,CODEscope),exprtype(tree->right,CODEscope))==0&&strcmp(exprtype(tree->left,CODEscope),"int")==0)
					msg="int";
				else
					msg="real";
			}
			if(strcmp(exprtype(tree->left,CODEscope),"int")==0&&(strcmp(exprtype(tree->right,CODEscope),"char*")==0||strcmp(exprtype(tree->right,CODEscope),"int*")==0||strcmp(exprtype(tree->right,CODEscope),"real*")==0)){
				msg=exprtype(tree->right,CODEscope);
			}
			else if(strcmp(exprtype(tree->right,CODEscope),"int")==0&&(strcmp(exprtype(tree->left,CODEscope),"char*")==0||strcmp(exprtype(tree->left,CODEscope),"int*")==0||strcmp(exprtype(tree->left,CODEscope),"real*")==0)){
				msg=exprtype(tree->left,CODEscope);
			}
			else if(strcmp(msg,"")==0)
			{
				printf("ERORR, you cant do %s between %s and %s",tree->token,exprtype(tree->left,CODEscope),exprtype(tree->right,CODEscope));
				printf(" in func/proc %s\n",mycode->func[mycode->countfunc-1]->name);
				exit(1);
			}
		}
		if(strcmp(tree->token,"*")==0||strcmp(tree->token,"/")==0)
		{
			if((strcmp(exprtype(tree->left,CODEscope),"int")==0||strcmp(exprtype(tree->left,CODEscope),"real")==0)&&(strcmp(exprtype(tree->right,CODEscope),"int")==0||strcmp(exprtype(tree->right,CODEscope),"real")==0))
			{
				if(strcmp(exprtype(tree->left,CODEscope),exprtype(tree->right,CODEscope))==0&&strcmp(exprtype(tree->left,CODEscope),"int")==0)
					msg="int";
				else
					msg="real";
			}
			else
			{
				printf("ERORR, you cant do %s between %s and %s",tree->token,exprtype(tree->left,CODEscope),exprtype(tree->right,CODEscope));
				printf(" in func/proc %s\n",mycode->func[mycode->countfunc-1]->name);
				exit(1);
			}
		}
		if(strcmp(tree->token,"&&")==0||strcmp(tree->token,"||")==0)
		{
			if(strcmp(exprtype(tree->left,CODEscope),exprtype(tree->right,CODEscope))==0&&strcmp(exprtype(tree->right,CODEscope),"boolean")==0)
				msg="boolean";
			else{
				printf("ERORR, you cant do %s between %s and %s",tree->token,exprtype(tree->left,CODEscope),exprtype(tree->right,CODEscope));
				printf(" in func/proc %s\n",mycode->func[mycode->countfunc-1]->name);
				exit(1);
			}
		}
		if(strcmp(tree->token,">=")==0||strcmp(tree->token,">")==0||strcmp(tree->token,"<=")==0||strcmp(tree->token,"<")==0)
		{
			if((strcmp(exprtype(tree->left,CODEscope),"int")==0||strcmp(exprtype(tree->left,CODEscope),"real")==0)&&(strcmp(exprtype(tree->right,CODEscope),"int")==0||strcmp(exprtype(tree->right,CODEscope),"real")==0))
				msg="boolean";
			else{
				printf("ERORR, you cant do %s between %s and %s in func/proc %s\n",tree->token,exprtype(tree->left,CODEscope),exprtype(tree->right,CODEscope),mycode->func[mycode->countfunc-1]->name);
				exit(1);
			}
		}
				if(strcmp(tree->token,"==")==0||strcmp(tree->token,"!=")==0)
		{
			if(strcmp(exprtype(tree->left,CODEscope),exprtype(tree->right,CODEscope))==0 && strcmp(exprtype(tree->right,CODEscope),"string")!=0)
				msg="boolean";
			else{
				printf("ERORR, you cant do %s between %s and %s in func/proc %s\n",tree->token,exprtype(tree->left,CODEscope),exprtype(tree->right,CODEscope),mycode->func[mycode->countfunc-1]->name);
				exit(1);
			}
			
		}
		if(strcmp(tree->token,"|")==0){
			if(strcmp(exprtype(tree->left,CODEscope),"string")==0){
				msg="int";
			}
			else{
				printf("ERORR, you need to use string type in func/proc %s",mycode->func[mycode->countfunc-1]->name);
				exit(1);
			}
		}
		if(strcmp(tree->token,"!")==0){
			if(strcmp(exprtype(tree->left,CODEscope),"boolean")==0)
				msg="boolean";
			else{
			printf("ERORR, you need to use boolean type");
			exit(1);
			}
		}
		if(strcmp(tree->token,"&")==0)
		{
			if(strcmp(tree->left->token,"(")==0)
				msg=exprtype(tree->left->left,CODEscope);
			else
				msg=exprtype(tree->left,CODEscope);
			if(strcmp(msg,"char")==0)
				msg="char*";
			else if(strcmp(msg,"int")==0)
				msg="int*";
			else if(strcmp(msg,"real")==0)
				msg="real*";
			else
			{
				printf("ERORR, you cant do %s on %s \n",tree->token,msg);
				exit(1);
			}
		}
		if(strcmp(tree->token,"^")==0)
		{
			if(strcmp(tree->left->token,"(")==0)
				msg=exprtype(tree->left->left,CODEscope);
			else
				msg=exprtype(tree->left,CODEscope);
			
			if(strcmp(msg,"char*")==0)
				msg="char";
			else if(strcmp(msg,"int*")==0)
				msg="int";
			else if(strcmp(msg,"real*")==0)
				msg="real";
			else
			{
				printf("ERORR, you cant do %s on %s \n",tree->token,msg);
				exit(1);
			}
		}
		if(strcmp(tree->token,"(")==0)
			msg=exprtype(tree->left,CODEscope);
		if(strcmp(tree->token,"Call func")==0)
			msg=findfunc(tree,CODEscope,NULL);
	}
	if(strcmp(msg,"")==0)
		msg=findvar(tree,CODEscope);
	return msg;
}
void push(code* from,char* name)
{
	code * point;
	if(mycode==NULL)
		mycode=makeCode(name);
	else{
		point=mycode;
		while(point->nextLVL!=NULL)
			point=point->nextLVL;
		point->nextLVL=makeCode(name);
		point->nextLVL->beforeLVL=from;
	}
}
code* makeCode(char* name)
{	
	code *newlvl = (code*)malloc(sizeof(code));
	newlvl->place=++scope;
	newlvl->name=name;
	newlvl->var=NULL;
	newlvl->countvar=0;
	newlvl->func=NULL;
	newlvl->countfunc=0;
	newlvl->nextLVL=NULL;
	newlvl->beforeLVL=NULL;
	return newlvl;
}
void addvar(Arguments * args,int countvars,int isArg,code * CODEscope){
	if(countvars==0)
		return;
	Varaiable* temp;
	code * codey=CODEscope;
	for(int i=0;i<countvars;i++)
		for(int j=0;j<countvars;j++)
			if(i!=j && strcmp(args[j].name,args[i].name)==0 )
			{
				printf("sorry you can't some vars %s in one declear",args[i].name);
				code * t=codey->beforeLVL;
				while(t->beforeLVL!=NULL && t->beforeLVL->countfunc==0)
					t=t->beforeLVL;
				if(t->func!=NULL)
				printf(",in func %s\n",t->func[t->countfunc-1]->name);
					else
				printf("\n");
				exit(1);
			}
	if(codey->var==NULL)
		codey->var=(Varaiable*) malloc(sizeof(Varaiable)*countvars);
	else
	{
		temp=codey->var;
		codey->var=(Varaiable*) malloc(sizeof(Varaiable)*(codey->countvar+countvars));
		for(int i=0;i<codey->countvar;i++)
		{
			for(int j=0;j<countvars;j++)
			{
				if(strcmp(temp[i].name,args[j].name)==0 )
				{
					printf("sorry you can't some var %s in some scope",temp[i].name);
					code * t=codey->beforeLVL;
					while(t->beforeLVL!=NULL && t->beforeLVL->countfunc==0)
						t=t->beforeLVL;
					if(t->func!=NULL)
					printf(",in func %s\n",t->func[t->countfunc-1]->name);
					else
					printf("\n");
					exit(1);
				}
			}
			codey->var[i]=temp[i];	
		}
	}
	for(int j=0;j<countvars;j++)
	{
		codey->var[codey->countvar].name=args[j].name;
		codey->var[codey->countvar].value=NULL;
		codey->var[codey->countvar].isArg=isArg;
		codey->var[codey->countvar].len=args[j].len;
		codey->var[(codey->countvar)++].type=args[j].type;
	}
}
void addFunc(char * name,Arguments * args,node *returnType,int countArgs,code * CODEscope){
	Function** temp;
	code * codey=CODEscope;
	for(int i=0;i<countArgs;i++)
		for(int j=0;j<countArgs;j++)
			if(i!=j && strcmp(args[j].name,args[i].name)==0 )
			{
			printf("sorry you can't same Arguments %s in func %s\n",args[i].name,name);
			exit(1);
			}
	if(codey->func==NULL)
		codey->func=(Function**) malloc(sizeof(Function*));
	else
	{
		temp=codey->func;
		codey->func=(Function**) malloc(sizeof(Function*)*(codey->countfunc+1));
		for(int i=0;i<codey->countfunc;i++)
		{
				if(strcmp(temp[i]->name,name)==0 )
				{
					printf("sorry you can't same func %s in same scope \n",temp[i]->name);
					exit(1);
				}
				codey->func[i]=temp[i];
		}
	}
		codey->func[codey->countfunc]=(Function*) malloc(sizeof(Function));
		codey->func[codey->countfunc]->name=name;
		codey->func[codey->countfunc]->args=args;
		if(returnType==NULL)
			codey->func[codey->countfunc]->returnType=NULL;
		else
		{
			if(strcmp(returnType->token,"string")==0)
			{
				printf("ERORR,return type func %s cant be string\n",name);
				exit(1);
			}
			codey->func[codey->countfunc]->returnType=returnType->token;
		}
		codey->func[codey->countfunc]->countArgs=countArgs;
		codey->func[codey->countfunc]->findreturn=false;
		++(codey->countfunc); 
}
Arguments * makeArgs(node *tree,int *count){
	Arguments  *arr=NULL,ar[50];
	char* type,*len;
	if(tree!=NULL)
	{
		node * temp1=tree,*temp=tree;
		do{
			if(strcmp(temp1->token, "")==0)
			{
				temp=temp1->right->left;
				temp1=temp1->left;	
				if(strcmp(temp->token, "(")==0||strcmp(temp->token, "var")==0)
				{
				type=temp->left->token;
				if(temp->left->left!=NULL)
					len=temp->left->left->left->token;
					node * treee;
					treee=temp->right->left;
				do{
					ar[*count].name=treee->token;
					ar[*count].type=type;
					ar[*count].len=len;
					(*count)++;
				if(treee->left==NULL)
					treee=NULL;
				else
					treee=treee->left->left;
				} while(treee!=NULL);
			}
		}
		} while(strcmp(temp1->token, "(")!=0&&strcmp(temp->token, "var")!=0);
			temp=temp1;
			if(strcmp(temp->token, "(")==0||strcmp(temp->token, "var")==0)
			{
				type=temp->left->token;
				node * treee;
				if(strcmp(temp->token, "var")==0)
				treee=temp->right;
				else
				treee=temp->right->left;
				if(temp->left->left!=NULL)
				len=temp->left->left->left->token;
				do{
					ar[*count].name=treee->token;
					ar[*count].type=type;
					ar[*count].len=len;
					(*count)++;
					if(treee->left==NULL)
						treee=NULL;
					else
						treee=treee->left->left;
				} while(treee!=NULL);
			}
			arr=(Arguments*)malloc(sizeof(Arguments)*(*count));
			for(int i=0;i<*count;i++)
			{
				arr[i].name=ar[i].name;
				arr[i].type=ar[i].type;
			}
	}
	return arr;
}
node* makeNode (char *token, node *left, node *right)
{
	node *newnode = (node*)malloc(sizeof(node));
	newnode->left=left;
	newnode->right=right;
	newnode->token=token;
	newnode->code=NULL;
	newnode->var=NULL;
	newnode->label=NULL;
	newnode->truelabel=NULL;
	newnode->falselabel=NULL;
	newnode->sum=0;
	return newnode;
}
void printTabs(int n)
{
	for(int i=0;i<n/9;i++)
		printf("   ");
}
void Printtree(node* tree)
{
	int flag = 4;
	printTabs(printlevel); 
	if(strcmp(tree->token, "var") == 0){
		printf("(DECLARE ");
		flag=2;	
	} else if(strcmp(tree->token, "if") == 0){
		printf("(IF\n");
		flag = 1;
	} else if(strcmp(tree->token, "while") == 0){
		printf("(WHILE\n");
		flag = 1;	
	} else if(strcmp(tree->token, "for") == 0){
		printf("(FOR\n");
		flag = 1;	
	} else if(strcmp(tree->token, "func") == 0){
		printf("(%s \n\t",tree->token);
		flag= 2;
        } else if(strcmp(tree->token, "Call func") == 0){
		printf("(%s \n",tree->token);
		flag= 1;	
	} else if(strcmp(tree->token, "CODE") == 0){
		printf("(%s \n",tree->token);
		flag= 2;
	} else if(strcmp(tree->token, "BODY") == 0){
		if(tree->left)
			printf("(%s \n",tree->token);
		else
			flag =1;
        } else if(strcmp(tree->token, "ARGS") == 0){
		printf("(ARGS ");
		if(tree->left)
		{
			flag = 2;
			printf("\n\t");
		}
		else
			printf(" NONE)\n"); 
	} else if(strcmp(tree->token, "if-else") == 0){
		printf("\n(IF-ELSE ");
		flag = 2;
	} else if(strcmp(tree->token, "return") == 0){
		printf("(RET ");
		flag = 2;   
	} else if(strcmp(tree->token, "{") == 0)
                printf("(BLOCK\n");
	else if(strcmp(tree->token, "}") == 0)
                flag =2;           
        else if(strcmp(tree->token, "") == 0||strcmp(tree->token, "BOOLEAN") == 0||strcmp(tree->token, "STRING") == 0||strcmp(tree->token, "REAL") == 0||strcmp(tree->token, "CHAR") == 0||strcmp(tree->token, "INT") == 0||strcmp(tree->token, "HEX") == 0);
	else if(strcmp(tree->token, "(") == 0)
		printf("(");
	else if(strcmp(tree->token, "\n") == 0)
		printf("\n");
	else if(strcmp(tree->token, ")") == 0)
		printf(")\n");
	else if(strcmp(tree->token, ",") == 0)
		printf(",");
	else if(strcmp(tree->token, ";") == 0)
		printf("\n");
	else if(strcmp(tree->token, "&&") == 0 ||
		strcmp(tree->token, "/") == 0 || 
		strcmp(tree->token, "=") == 0 || 
		strcmp(tree->token, "==") == 0 || 
		strcmp(tree->token, ">") == 0 || 
		strcmp(tree->token, ">=") == 0 || 
		strcmp(tree->token, "<") == 0 || 
		strcmp(tree->token, "<=") == 0 || 
		strcmp(tree->token, "-") == 0 || 
		strcmp(tree->token, "!") == 0 || 
		strcmp(tree->token, "!=") == 0 || 
		strcmp(tree->token, "||") == 0 || 
		strcmp(tree->token, "+") == 0 || 
		strcmp(tree->token, "*") == 0 || 
		strcmp(tree->token, "&") == 0 || 
		strcmp(tree->token, "|") == 0 || 
		strcmp(tree->token, ",") == 0 ){
			printf("(%s",tree->token);
			flag=2;
			if(strcmp(tree->token, "=") == 0)
				flag=1;	
	} else if(strcmp(tree->token, "^") == 0 ){
			printf("(*");
			flag=2;
	}else if(strcmp(tree->token, "procedures") == 0 || strcmp(tree->token, "stmnts") == 0|| strcmp(tree->token, "Return") == 0|| strcmp(tree->token, "expr_list") == 0){
			printf(" ");
	}
	else {
		if(tree && (!tree->left && !tree->right)||strcmp(tree->token, "main") == 0)
			printf("%s ", tree->token);
		else
            printf("%s", tree->token);
	}
	if (tree->left){
		printlevel++;
		Printtree(tree->left);
		printlevel--;
	}
	if (tree->right) {
		printlevel++;
		Printtree(tree->right);
		printlevel--;
	}
	if(flag == 2)
		printf(")\n");
	if(flag == 1)
		printf(")");
	if(flag == 0)
		printf("\n)");
}
int yyerror(char *e)
{
	int yydebug=1; 
	fflush(stdout);
	fprintf(stderr,"Error %s at line %d\n" ,e,yylineno);
	fprintf(stderr, "does not accept '%s'\n",yytext);
	return 0;
}
code* lastCode(code * codey)
{
	code * CODEscope=codey;
	if(CODEscope!=NULL)
	while(CODEscope->nextLVL!=NULL)
		CODEscope=CODEscope->nextLVL;
	return CODEscope;
}
void CheckSyntax(node *tree,code * CODEscope)
{
	if(tree){
		if(strcmp(tree->token, "CODE") == 0)
		{
			push(NULL,tree->token);
			if (tree->left) 
				CheckSyntax(tree->left,mycode);
			if (tree->right)
				CheckSyntax(tree->right,mycode);
			scope--;
			return;
		}
		
		if(strcmp(tree->token,"main")==0)
		{
			if(flagMain==true && strcmp(CODEscope->name,"CODE")==0)
			{
				printf("main needs to be one and only\n");
				exit(1);
			}
			flagMain=true;
			if(tree->left)
				addFunc(tree->token,NULL,tree->left->left,0,CODEscope);
			else		
				addFunc(tree->token,NULL,NULL,0,CODEscope);
		
			push(CODEscope,tree->token);
			if (tree->left) 
				CheckSyntax(tree->left,lastCode( CODEscope->nextLVL));
			if (tree->right)
				CheckSyntax(tree->right,lastCode( CODEscope->nextLVL));
			scope--;
			return;
		}

		if(strcmp(tree->token, "func") == 0 )
		{
			int count=0;
			Arguments * arg=makeArgs(tree->left->left->left,&count);
			if (tree->left->right)
				addFunc(tree->left->token,arg,tree->left->right->left,count,CODEscope);
			else
				addFunc(tree->left->token,arg,NULL,count,CODEscope);
			push(CODEscope,tree->token);
			addvar(arg,count,1,lastCode(CODEscope));
			if (tree->left) 
				CheckSyntax(tree->left,lastCode( CODEscope->nextLVL));
			if (tree->right)
				CheckSyntax(tree->right,lastCode( CODEscope->nextLVL));
			scope--;		
			return;
		}



		if(strcmp(tree->token, "=") == 0)
		{
			if(!(strcmp(exprtype(tree->right,CODEscope),"NULL")==0&& (strcmp(exprtype(tree->left,CODEscope),"real*")==0||strcmp(exprtype(tree->left,CODEscope),"int*")==0||strcmp(exprtype(tree->left,CODEscope),"char*")==0)))
				if(strcmp(exprtype(tree->left,CODEscope),exprtype(tree->right,CODEscope))!=0)
				{
					printf("ERORR, can't do = between %s and %s\n",exprtype(tree->left,CODEscope),exprtype(tree->right,CODEscope));
					exit(1);
				}
		}

		else if(strcmp(tree->token, "var") == 0)
		{
			int countvar=0;
			Arguments * var=makeArgs(tree,&countvar);
			addvar(var,countvar,0,CODEscope);
		}
		else if(strcmp(tree->token, "Call func") == 0)
		{
			int count=0;
			findfunc(tree,CODEscope,&count);
			tree->sum=count;
		}

	if(strcmp(tree->token, "for") == 0){
		if(strcmp(exprtype(tree->left->left->right,CODEscope),"boolean")!=0)
		{
			printf("ERORR, in for expr most be type boolean\n");
			exit(1);
		}
		CheckSyntax(tree->left->left->left,CODEscope);
		CheckSyntax(tree->left->right->left,CODEscope);
		if(strcmp(tree->right->token,"{")!=0)
		{
			push(CODEscope,tree->token);
			if (tree->left) 
				CheckSyntax(tree->left,lastCode( CODEscope->nextLVL));
			if (tree->right)
				CheckSyntax(tree->right,lastCode( CODEscope->nextLVL));
			scope--;
			return;
		}}


	if(strcmp(tree->token, "while") == 0) {
		if(strcmp(exprtype(tree->left->left,CODEscope),"boolean")!=0)
		{
			printf("ERORR, in %s expr most be type boolean\n",tree->token);
			exit(1);
		}
		if(strcmp(tree->right->token,"{")!=0)
		{
			push(CODEscope,tree->token);
			if (tree->left) 
				CheckSyntax(tree->left,lastCode( CODEscope->nextLVL));
			if (tree->right)
				CheckSyntax(tree->right,lastCode( CODEscope->nextLVL));
			scope--;
			return;
		}
	}


	if(strcmp(tree->token, "do") == 0) {
		if(strcmp(exprtype(tree->left->left,CODEscope),"boolean")!=0)
		{
			printf("ERORR, in %s expr most be type boolean\n",tree->token);
			exit(1);
		}
		if(strcmp(tree->right->token,"{")!=0)
		{
			push(CODEscope,tree->token);
			if (tree->left) 
				CheckSyntax(tree->left,lastCode( CODEscope->nextLVL));
			if (tree->right)
				CheckSyntax(tree->right,lastCode( CODEscope->nextLVL));
			scope--;
			return;
		}
	}
	if(strcmp(tree->token, "if") == 0 )
	{
		if(strcmp(exprtype(tree->left->left,CODEscope),"boolean")!=0)
		{
			printf("ERORR, in if expr most be type boolean\n");
			exit(1);
		}

		if(strcmp(tree->right->token,"{")!=0)
		{
			push(CODEscope,tree->token);
			if (tree->left) 
				CheckSyntax(tree->left,lastCode( CODEscope->nextLVL));
			if (tree->right)
				CheckSyntax(tree->right,lastCode( CODEscope->nextLVL));
		scope--;
			return;
		}


	}

	if(strcmp(tree->token,"if-else") == 0)
	{
		if(strcmp(exprtype(tree->left->left,CODEscope),"boolean")!=0)
		{
			printf("ERORR, in if expr most be type boolean\n");
			exit(1);
		}
		if(strcmp(tree->right->left->token,"{")!=0)
			{
				push(CODEscope,tree->token);
				if(tree->right)
					CheckSyntax(tree->right->left,lastCode( CODEscope->nextLVL));
				scope--;
				push(CODEscope,tree->token);
				if(tree->right->right)
					CheckSyntax(tree->right->right->left,lastCode( CODEscope->nextLVL));
				scope--;
				return;
			}
	
	}
	if(strcmp(tree->token, "return") == 0)
	{
		code * temp= CODEscope;
		int flag=true;
		while(strcmp(temp->name,"func")!=0 && strcmp(temp->name,"main")!=0 && strcmp(temp->name,"CODE")!=0)
		{
			temp=temp->beforeLVL;
			flag=false;
		}
		if(flag==false)
		{
			if(strcmp(exprtype(tree->left,CODEscope),temp->beforeLVL->func[temp->beforeLVL->countfunc-1]->returnType))
			{
				printf("ERORR,wrong type of return in func %s \n",temp->beforeLVL->func[temp->beforeLVL->countfunc-1]->name);
				printf("%s ,%s %s\n",exprtype(tree->left,CODEscope),temp->beforeLVL->func[temp->beforeLVL->countfunc-1]->returnType,temp->beforeLVL->func[temp->beforeLVL->countfunc-1]->name);
				exit(1);
			}
		}
		else{
			if(temp->beforeLVL->func[temp->beforeLVL->countfunc-1]->returnType!=NULL){
				if(strcmp(exprtype(tree->left,CODEscope),temp->beforeLVL->func[temp->beforeLVL->countfunc-1]->returnType)==0){
					temp->beforeLVL->func[temp->beforeLVL->countfunc-1]->findreturn=true;
				}
				else{
					printf("ERORR,invalid return type in func %s \n",temp->beforeLVL->func[temp->beforeLVL->countfunc-1]->name);
					exit(1);
				}
			}
			else
			{
				printf("ERORR,return cant be in proc %s\n",temp->beforeLVL->func[temp->beforeLVL->countfunc-1]->name);
				exit(1);
			}  
		}
	}else if(strcmp(tree->token, "{") == 0)
	{
		push(CODEscope,tree->token);
		if (tree->left) 
			CheckSyntax(tree->left,lastCode( CODEscope->nextLVL));
		if (tree->right)
			CheckSyntax(tree->right,lastCode( CODEscope->nextLVL));
			scope--;
		return;			
	}
	if (tree->left) 
		CheckSyntax(tree->left,CODEscope);
	if (tree->right)
		CheckSyntax(tree->right,CODEscope);
}
}


int POPParams(Arguments * args,int count){
	int size=0;
	for(int i =0;i<count;i++)
	{
		if(strcmp(args[i].type,"int")==0)
			size += 4;
		else if(strcmp(args[i].type,"char")==0)
			size += 1;
		else if(strcmp(args[i].type,"real")==0)
			size += 8;
		else if(strcmp(args[i].type,"string")==0)
			size += atoi(args[i].len);
		else if(strcmp(args[i].type,"boolean")==0)
			size += 4;
		else if(strcmp(args[i].type,"int*")==0)
			size += 4;
		else if(strcmp(args[i].type,"char*")==0)
			size += 4;
		else if(strcmp(args[i].type,"real*")==0)
			size += 4;
	}
	return size;
}

void addCode(node* node,char *code,char *var,char *label,char *truelabel,char *falselabel)
	{
		if(code!=NULL){
		node->code=(char*)malloc(sizeof(char)*(1+strlen(code)));
		strcpy(node->code,code);
		}
		else if(node->code==NULL)
		{
		node->code=(char*)malloc(sizeof(char)*2);
		strcpy(node->code,"");
		}
		if(var!=NULL){
		node->var=(char*)malloc(sizeof(char)*(1+strlen(var)));
		strcpy(node->var,var);
		}
		else if(node->var==NULL)
		{
		node->var=(char*)malloc(sizeof(char)*2);
		strcpy(node->var,"");
		}
		if(label!=NULL&& node->label==NULL){
		node->label=(char*)malloc(sizeof(char)*(1+strlen(label)));
		strcpy(node->label,label);
		}
		if(truelabel!=NULL && node->truelabel==NULL){
		node->truelabel=(char*)malloc(sizeof(char)*(1+strlen(truelabel)));
		strcpy(node->truelabel,truelabel);
		}
		if(falselabel!=NULL && node->falselabel==NULL){
		node->falselabel=(char*)malloc(sizeof(char)*(1+strlen(falselabel)));
		strcpy(node->falselabel,falselabel);
		}

	}



void addCode2(node* node,char *code,char *var,char *label,char *truelabel,char *falselabel)
	{
		if(code!=NULL){
		node->code=(char*)malloc(sizeof(char)*(1+strlen(code)));
		strcpy(node->code,code);
		}
		else if(node->code==NULL)
		{
		node->code=(char*)malloc(sizeof(char)*2);
		strcpy(node->code,"");
		}

		if(var!=NULL){
		node->var=(char*)malloc(sizeof(char)*(1+strlen(var)));
		strcpy(node->var,var);
		}
		else if(node->var==NULL)
		{
		node->var=(char*)malloc(sizeof(char)*2);
		strcpy(node->var,"");
		}

		if(label!=NULL){
		node->label=(char*)malloc(sizeof(char)*(1+strlen(label)));
		strcpy(node->label,label);
		}

		if(truelabel!=NULL){
		node->truelabel=(char*)malloc(sizeof(char)*(1+strlen(truelabel)));
		strcpy(node->truelabel,truelabel);
		}
		
		if(falselabel!=NULL && node->falselabel==NULL){
		node->falselabel=(char*)malloc(sizeof(char)*(1+strlen(falselabel)));
		strcpy(node->falselabel,falselabel);
		}

	}
char* freshVar()
	{
		char* x;
		asprintf(&x,"t%d",t++);
		return x;
	}
char* freshLabel()
	{
		char* x;
		asprintf(&x,"L%d",l++);
		return x;
	}
char* gen(char*s1,char*s2,char*s3,char*s4,char*s5)
	{
		char* x;
		asprintf(&x,"%s %s %s %s %s\n",s1,s2,s3,s4,s5);
		return x;
	}
	
char* mystrcat(char*des,char*src){
		char* tamp=des;
		char* num;
		asprintf(&num,"%d ",line++);
		if(src!=NULL){
			if(des==NULL){
				des=(char*)malloc((strlen(src)+1)*sizeof(char));
				strcpy(des,src);
				return des;
			}
		des=(char*)malloc((strlen(des)+strlen(src)+1+strlen(num))*sizeof(char));
		if(tamp!=NULL){
		strcat(des,tamp);
		}
		if(src!=NULL)
		{
		strcat(des,src);
		}
		}
		return des;
	}
char *replaceWord(const char *s, const char *oldW, const char *newW) 
{ 
    char *result; 
    int i, cnt = 0; 
    int newWlen = strlen(newW); 
    int oldWlen = strlen(oldW); 
  
    // Counting the number of times old word 
    // occur in the string 
    for (i = 0; s[i] != '\0'; i++) 
    { 
        if (strstr(&s[i], oldW) == &s[i]) 
        { 
            cnt++; 
  
            // Jumping to index after the old word. 
            i += oldWlen - 1; 
        } 
    } 
  
    // Making new string of enough length 
    result = (char *)malloc(i + cnt * (newWlen - oldWlen) + 1); 
  
    i = 0; 
    while (*s) 
    { 
        // compare the substring with the result 
        if (strstr(s, oldW) == s) 
        { 
            strcpy(&result[i], newW); 
            i += newWlen; 
            s += oldWlen; 
        } 
        else
            result[i++] = *s++; 
    } 
  
    result[i] = '\0'; 
    return result; 
} 

 
char * mkspace(char *label)
{
	char * msg;
	char x=' ';
	int len = strlen(mystrcat(label,"\0"));
	if(label==NULL || !strcmp(label,""))
		msg="";
	else
		{
		asprintf(&msg,"%c",x);
		while(len<5){
			asprintf(&msg,"%c%s",x,msg);
			len++;
		}
		asprintf(&label,"%s: ",mystrcat(label,"\0"));
		msg=mystrcat(msg,label);
		}
		return msg;
}


void calc3AC(node * tree)
{ 
	
	
	if(strcmp(tree->token, "=") == 0 )
	{ if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
	   addCode(tree,mystrcat(tree->right->code,gen(tree->left->var,"=",tree->right->var,"","")),NULL,NULL,NULL,NULL); 
	   return;  
	}
	else if(strcmp(tree->token, "if") == 0)
	{ 
		if(tree->left->left)
		addCode(tree->left->left,NULL,NULL,NULL,NULL,tree->label);
		if(tree->right)
		addCode2(tree->right,NULL,NULL,tree->label,NULL,NULL);
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		addCode(tree,mystrcat(tree->left->left->code,mystrcat(mkspace(tree->left->left->label),mystrcat(mkspace(tree->left->left->truelabel),mystrcat(tree->right->code,mkspace(tree->truelabel))))),NULL,NULL,NULL,NULL);
		return;
	}
else if(strcmp(tree->token, "if-else") == 0)
	{ 
		if(tree->right->left)
		addCode(tree->right->left,NULL,NULL,tree->label,NULL,NULL);			
		if(tree->right->right->left)
		addCode2(tree->right->right->left,NULL,NULL,tree->label,NULL,tree->label);
		if(tree->right->left)
		addCode2(tree->right->left,NULL,NULL,tree->label,NULL,tree->label);
		
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		addCode(tree,mystrcat(mystrcat(tree->left->left->code,mystrcat(mkspace(tree->left->left->truelabel),tree->right->left->code))
		,mystrcat(mystrcat("goto ",mystrcat(mystrcat(tree->label,"\n"),mystrcat(mkspace(tree->left->left->falselabel),tree->right->right->left->code))),mkspace(tree->label))),NULL,NULL,NULL,NULL);
	return;
	}
	else if(strcmp(tree->token, "while") == 0)
	{ 
		if(tree->left->left)
			addCode(tree->left->left,NULL,NULL,NULL,tree->falselabel,tree->label);
		if(tree->right)
			addCode2(tree->right,NULL,NULL,tree->label,NULL,NULL);
		
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
			
			addCode(tree,mystrcat(mystrcat(mystrcat( mkspace(tree->truelabel),tree->left->left->code),mkspace(tree->falselabel)),
				mystrcat(tree->right->code,mystrcat(mystrcat("\tgoto ",mystrcat(tree->truelabel,"\n")),mkspace(tree->label)))),NULL,NULL,NULL,NULL);
		return ;
	}
		else if(strcmp(tree->token, "do") == 0)
	{ 

		if(tree->left->left)
			addCode(tree->left->left,NULL,NULL,NULL,tree->truelabel,NULL);
		if(tree->right)
			addCode2(tree->right,NULL,NULL,NULL,NULL,NULL);
		
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
			
			addCode(tree,mystrcat( mkspace(tree->truelabel),
				mystrcat(tree->right->code,mkspace(mystrcat("\t",tree->left->left->code)))),NULL,NULL,NULL,NULL);
		return ;
	}
	else if(strcmp(tree->token, "stmnts") == 0)
	{ 
		
		if(tree->right!=NULL)
			if(strcmp(tree->right->token, "for") == 0||strcmp(tree->right->token, "if-else") == 0||strcmp(tree->right->token, "while") == 0)
				addCode2(tree->right,NULL,NULL,tree->label,NULL,NULL);
        if(tree->right!=NULL && tree->left!=NULL)
        if(strcmp(tree->left->right->token, "if") == 0||strcmp(tree->left->right->token, "for") == 0||strcmp(tree->left->right->token, "if-else") == 0||strcmp(tree->left->right->token, "while") == 0)
				addCode2(tree->right,NULL,NULL,NULL,tree->left->right->label,NULL);
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);

			if(tree->right!=NULL && tree->left!=NULL)
                if((strcmp(tree->right->token, "while") == 0||strcmp(tree->right->token, "for") == 0||strcmp(tree->right->token, "if-else") == 0)&&(strcmp(tree->left->right->token, "if") == 0||strcmp(tree->left->right->token, "for") == 0||strcmp(tree->left->right->token, "if-else") == 0||strcmp(tree->left->right->token, "while") == 0))
                    addCode(tree,mystrcat(tree->left->code,&tree->right->code[8]),NULL,NULL,NULL,NULL);
                    else
					addCode(tree,mystrcat(tree->left->code,tree->right->code),NULL,NULL,NULL,NULL);
			else if(tree->right!=NULL)
            {
                if(strcmp(tree->right->token, "for") == 0||strcmp(tree->right->token, "if-else") == 0||strcmp(tree->right->token, "while") == 0)
                    addCode(tree,tree->right->code,NULL,NULL,NULL,NULL);
                    else        
				    addCode(tree,mystrcat(tree->right->code ,mkspace(tree->right->label)),NULL,NULL,NULL,NULL);
            }else
				addCode(tree,"",NULL,NULL,NULL,NULL);
			
	return;
		
	}
	else if(strcmp(tree->token, "for") == 0)
	{ 
		if(tree->left->left->right)
			addCode(tree->left->left->right,NULL,NULL,NULL,tree->falselabel,tree->label);
		if(tree->right)
			addCode2(tree->right,NULL,NULL,tree->label,NULL,NULL);
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
					addCode(tree,	
		mystrcat(mystrcat(mystrcat(tree->left->left->left->code, mkspace(tree->truelabel)),tree->left->left->right->code),
		mystrcat(mystrcat(mystrcat(mkspace(tree->falselabel),tree->right->code),tree->left->right->left->code),mystrcat("\tgoto ",mystrcat(tree->truelabel,mystrcat("\n",mkspace(tree->label)))))),NULL,NULL,NULL,NULL);
	}
    
	else if(strcmp(tree->token, "func") == 0)
	{
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		char*x; asprintf(&x," %s:\n",tree->left->token);addCode(tree,mystrcat(x,tree->right->code),NULL,NULL,NULL,NULL);
		
		return;
	}
		else if(strcmp(tree->token, "expr_list") == 0)
	{
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
			if(tree->right==NULL)
				addCode(tree,mystrcat(tree->left->code,mystrcat("PushParam ",mystrcat(tree->left->var,"\n"))),NULL,NULL,NULL,NULL);
			else
				addCode(tree,mystrcat(mystrcat(tree->left->code,mystrcat("PushParam ",mystrcat(tree->left->var,"\n"))),tree->right->left->code),NULL,NULL,NULL,NULL);
	}	
	else if(strcmp(tree->token, "Call func") == 0)
	{ 

		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		char * x,*parm=(char*)malloc(sizeof(char));
		if(tree->right->left==NULL)
			strcpy(parm,"");
		else
			parm=tree->right->left->code;
		addCode(tree,NULL,freshVar(),NULL,NULL,NULL);
		asprintf(&x,"%s%s = LCALL %s\n‪\tPopParams %d‬‬‬‬\n",parm,tree->var,tree->left->token,tree->sum);
		addCode(tree,x,NULL,NULL,NULL,NULL);
		return;
	}
	else if(strcmp(tree->token, "CODE") == 0)
	{ if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		 if(tree->left)
			addCode(tree,mystrcat(tree->left->code,tree->right->code),NULL,NULL,NULL,NULL);
		else
			addCode(tree,tree->right->code,NULL,NULL,NULL,NULL);
		tree->code=replaceWord(tree->code, "\n\n", "\n") ;
		char x='a',*y,*z;

		while (x<='z')
		{
			asprintf(&y,"\n%c",x);
			asprintf(&z,"\n\t%c",x);
			tree->code=replaceWord(tree->code, y, z) ;
			x++;
		}
		x='A';
				while (x<='Z')
		{
			asprintf(&y,"\n%c",x);
			asprintf(&z,"\n\t%c",x);
			tree->code=replaceWord(tree->code, y, z) ;
			x++;
		}
		return;
	}
    else if(strcmp(tree->token, "BODY") == 0)
	{ 
		
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		if(tree->right->right->left){
		
			if(tree->right->right->left->code[strlen(mystrcat(tree->right->right->left->code,"\0"))-2]==':')
				addCode(tree,mystrcat(mystrcat("\tBeginFunc‬‬\n",tree->right->right->left->code),"EndFunc\n"),NULL,NULL,NULL,NULL);
			else
				addCode(tree,mystrcat(mystrcat("\tBeginFunc‬‬\n",tree->right->right->left->code),"\tEndFunc\n"),NULL,NULL,NULL,NULL);
		}
		else
			 addCode(tree,mystrcat("\tBeginFunc‬‬\n","\tEndFunc\n"),NULL,NULL,NULL,NULL);
		
		return;
	}
    else if(strcmp(tree->token, "main") == 0)
	{ 
		 
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		
		addCode(tree,mystrcat(" main:\n",tree->right->code),NULL,NULL,NULL,NULL);
          return;   
    } 
	else if(strcmp(tree->token, "procedures") == 0)
	{ if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		if(tree->left!=NULL) addCode(tree,mystrcat(tree->left->code,tree->right->code),NULL,NULL,NULL,NULL);
		else addCode(tree,tree->right->code,NULL,NULL,NULL,NULL);
    return;
	}        
	else if(strcmp(tree->token, "return") == 0)
	{
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		addCode(tree,mystrcat(tree->left->code,gen("return",tree->left->var,"","","")),NULL,NULL,NULL,NULL);
		return;
	}
	else if(strcmp(tree->token, "{") == 0)
	{ 
		if(tree->right->right->left) addCode(tree,NULL,NULL,tree->right->right->left->label,tree->right->right->left->truelabel,tree->right->right->left->falselabel); 
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		if(tree->right->right->left) addCode(tree,tree->right->right->left->code,tree->right->right->left->var,NULL,NULL,NULL); 
		return;			
	}
	else if(strcmp(tree->token, "}") == 0)
	{ if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
                      
                      
    }
	else if(strcmp(tree->token, "assmnt_stmnt") == 0)
	{ if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
                     addCode(tree,tree->left->code,tree->left->var,tree->left->label,tree->left->truelabel,tree->left->falselabel); 
					 return;
                      
    }
	
    else if(strcmp(tree->token, "+") == 0 || 
            strcmp(tree->token, "*") == 0 || 
            strcmp(tree->token, "-") == 0 || 
            strcmp(tree->token, "/") == 0 )
	{ 
		
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		addCode(tree,NULL,freshVar(),NULL,NULL,NULL);
		addCode(tree,mystrcat(mystrcat(tree->left->code,tree->right->code),gen(tree->var,"=",tree->left->var,tree->token,tree->right->var)),NULL,NULL,NULL,NULL);
    return;}
    
	else if(strcmp(tree->token, "&") == 0)
	{ 
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
				if((tree->left->left == NULL))
				addCode(tree,"",mystrcat("&",(tree->left->token)),NULL,NULL,NULL);
			else if(strcmp(tree->left->left->token,"[")==0)
					{
						char *x,*fv1,*fv2;
						asprintf(&fv1,"%s",freshVar()); 
						asprintf(&fv2,"%s",freshVar());
						asprintf(&x,"\t%s = &%s\n\t%s = %s + %s\n",fv1,tree->left->token,fv2,fv1,tree->left->left->left->var);
						addCode(tree,mystrcat(tree->left->left->left->code,x),fv2,NULL,NULL,NULL);
					}
				else if (tree->left->left->left==NULL)
				addCode(tree,"",mystrcat("&",(tree->left->left->token)),NULL,NULL,NULL);
			else
			{
				char *x,*fv1,*fv2;
				asprintf(&fv1,"%s",freshVar());
				asprintf(&fv2,"%s",freshVar()); 
				asprintf(&x,"\t%s = &%s\n\t%s = %s + %s\n",fv1,tree->left->left->token,fv2,fv1,tree->left->left->left->left->var); 
				addCode(tree,mystrcat(tree->left->left->left->left->code,x),fv2,NULL,NULL,NULL);
			}
			
			

	return;}
	else if(strcmp(tree->token, "^") == 0 )
	{ 
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
			if((tree->left->left == NULL))
				addCode(tree,"",mystrcat("*",(tree->left->token)),NULL,NULL,NULL);
			else
			{
				addCode(tree,"",mystrcat("*",(tree->left->left->token)),NULL,NULL,NULL);
			}
			
	return;}
	else if(strcmp(tree->token, "==") == 0 || 
			strcmp(tree->token, ">") == 0 || 
			strcmp(tree->token, ">=") == 0 || 
			strcmp(tree->token, "<") == 0 || 
			strcmp(tree->token, "<=") == 0 || 
			strcmp(tree->token, "!=") == 0) 
	{ 

		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
				addCode(tree,mystrcat(mystrcat(tree->left->code,tree->right->code),mystrcat(gen("if",tree->left->var,tree->token,tree->right->var,mystrcat("goto ",mystrcat(tree->truelabel,"\n")))
				,mystrcat("\tgoto ",mystrcat(tree->falselabel,"\n")))),NULL,NULL,NULL,NULL);

				
	return;}
	else if(strcmp(tree->token, "(") == 0)
	{
			addCode(tree->left,NULL,NULL,NULL,tree->truelabel,tree->falselabel);
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		addCode(tree,tree->left->code,tree->left->var,NULL,NULL,NULL);
	return;}
	else if(strcmp(tree->token, "!") == 0)
	{ 
		addCode(tree->left,NULL,NULL,NULL,tree->truelabel,tree->falselabel);
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
				
		 addCode(tree,tree->left->code,NULL,NULL,NULL,NULL);
		
	return;}
	else if(strcmp(tree->token, "||") == 0) 
	{
		addCode(tree->left,NULL,NULL,NULL,tree->truelabel,NULL);
		addCode(tree->right,NULL,NULL,NULL,tree->truelabel,tree->falselabel);
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		addCode(tree,mystrcat(tree->left->code,mystrcat(mkspace(tree->left->falselabel),tree->right->code)),NULL,NULL,NULL,NULL);
	return;}
	else if(strcmp(tree->token, "&&") == 0 )
	{
		
		addCode(tree->left,NULL,NULL,NULL,NULL,tree->falselabel);
		addCode(tree->right,NULL,NULL,NULL,tree->truelabel,tree->falselabel);
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
			addCode(tree,mystrcat(tree->left->code,mystrcat(mkspace(tree->left->truelabel),tree->right->code)),NULL,NULL,NULL,NULL);
	return;}
	else if(strcmp(tree->token, "null") == 0 )
	{ 
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		addCode(tree,"",tree->token,NULL,NULL,NULL);
	return;}	
	else if(strcmp(tree->token, "solovar") == 0 )
	{ 
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
			if(tree->left->left==NULL)
				addCode(tree,"",tree->left->token,NULL,NULL,NULL);
			else
			{
				char *x,*fv1,*fv2; asprintf(&fv1,"%s",freshVar()); asprintf(&fv2,"%s",freshVar()); asprintf(&x,"\t%s = &%s\n\t%s = %s + %s\n",fv1,tree->left->token,fv2,fv1,tree->left->left->left->var); addCode(tree,mystrcat(tree->left->left->left->code,x),mystrcat("*",fv2),NULL,NULL,NULL);
			}
			
	return;}
	else if((tree->left!=NULL)&&
			(strcmp(tree->left->token,"INT")==0||
			strcmp(tree->left->token,"HEX")==0||
			strcmp(tree->left->token,"CHAR")==0||
			strcmp(tree->left->token,"REAL")==0||
			strcmp(tree->left->token,"STRING")==0||
			strcmp(tree->left->token,"BOOLEAN")==0))
			{

			if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
			if(strcmp(tree->left->token,"STRING")==0)
			addCode(tree,"",tree->token,NULL,NULL,NULL);
			else
			if(strcmp(tree->left->token,"BOOLEAN")==0)
			{
			if(strcmp(tree->token,"true")==0 && tree->truelabel!=NULL)	
			addCode(tree,mystrcat("goto ",mystrcat(tree->truelabel,"\n")),tree->token,NULL,NULL,NULL);
			else if(strcmp(tree->token,"false")==0 && tree->falselabel!=NULL)
			addCode(tree,mystrcat("goto ",mystrcat(tree->falselabel,"\n")),tree->token,NULL,NULL,NULL);
			else
			addCode(tree,tree->token,tree->token,NULL,NULL,NULL);
			}
			else
			addCode(tree,"",tree->token,NULL,NULL,NULL);
			return;}
	else if(strcmp(tree->token, "") == 0||strcmp(tree->token, " ") == 0)
	{
		
		if(tree->left)
		//if(tree->left->label==NULL&&tree->left->truelabel&&tree->left->falselabel==NULL)
		addCode(tree->left,NULL,NULL,tree->label,tree->truelabel,tree->falselabel);
		if(tree->right)
			//if(tree->right->label==NULL&&tree->right->truelabel&&tree->right->falselabel==NULL)
		addCode(tree->right,NULL,NULL,tree->label,tree->truelabel,tree->falselabel);
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		if(tree->left && tree->right)
			addCode(tree,mystrcat(tree->left->code,tree->right->code),tree->right->var,NULL,NULL,NULL);
		else if(tree->left)
			addCode(tree,tree->left->code,tree->left->var,NULL,NULL,NULL);	
		else if(tree->right)
			addCode(tree,tree->right->code,tree->right->var,NULL,NULL,NULL);	
	return;
	}
	else
	{
	if (tree->left) 
		calc3AC(tree->left);
	
	if (tree->right)
		calc3AC(tree->right);
addCode(tree,"",tree->token,NULL,NULL,NULL);
	return;}
	if (tree->left) 
		calc3AC(tree->left);
	
	if (tree->right)
		calc3AC(tree->right);
}
