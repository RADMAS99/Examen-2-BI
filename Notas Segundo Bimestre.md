# Clase C++
# APUNTES 2do Bimestre 

## **Doncumento funcional para futuros, deberes, proyectos, examens,etc.**
![](../Imagenes/waifu.png)
&nbsp;
## **MENUS**
**Switch:**
Ayuda identificar la secuencia que quiero ejercutar algo

**do:**
Ayuda a repetir cada rato, genera una opcion infinita
en pocas palabras un bucle infinito

Asi que usaremos **while | do | for**
```c
cin.clear();  //Para limpiar la consola y que se recupere en caso que se ingrese variables incorrectas. En el segmento en el que se quedo colgado// Def: Limpiar siclo de instrucciones.
```
Esto ayuda a que nuestro programa no se cuelge, por que para examen tenemos que tener cuidado o sera -0.3 Puntos.

No hay que combinar C con C++ por que mixturas y sera mas complicado encontrar el problema del codigo.

Para generar un procedimiento insertamos:
```c
void menuopcion (int opcion)
{
cout <<"\n\t\t------MENU-----" 
         <<"\n0.Salir" 
         <<"\n1.Pares"
         <<"\n2.Impares" 
         <<"\n3.Signos"
         <<"\t Ingrese Opcion:"<< endl;
            cin>>opcion;
            cin.clear(); //Para limpiar la consola y que se recupere en caso que se ingrese variables incorrectas
            //flush (Aplicacmos libreria de limpeado de parametros)
            
            return opcion;
}
```
En la elaboracion del menu de opciones para poder gerar un bucle al utilizar **do o do-while** solo evalua true o false 
1.**true** da vueltas y vueltas
2.**false**sale o salta

Encambio si utilizamos **for (;;)** este genera un bucle infinito sin condiciones algunas que tengamos que poner tomando en cuenta que en el main se tiene que ingresar un **return 0;** para que vuelva a generar nuestras condiciones establecidad hasta que finalize en el programa del menu que estamos armando.

##Menu do y swicht##
```c
#include <iostream>

using namespace std;

  void menuProce (int &opcion){
    opcion=0;
    cout <<"\n\t\t------MENU-----" << endl
         <<"\n1.Salir"             << endl
         <<"\n2.Pares"             << endl
         <<"\n3.Impares"           << endl 
         <<"\n4.Signos"            << endl
         <<"\n5.Signos Cambiado"   << endl
         <<"\n\n\t Ingrese Opcion:" ;
            cin>>opcion;
            cin.clear(); 
            fflush(stdin);
}

    void doMain(){

    int opcion;{
    do
    {
        menuProce(opcion);
        switch (opcion)
        {
        case 1: exit(0);
            break;
        case 2: cout<<"Seleccionaste Pares";
            break;
        case 3: cout<<"Seleccionaste Impares";
            break;
        case 4: cout<<"Seleccionaste Signos";
            break;
        default:cout<<"Intenta de nuevo";
            break;
        }
         cout << endl << "Press any key to continue...";
        getchar();
       
       }while (true);
        
    }
    }    
    int main()
    {
        doMain();

        return 0;
    }
```
##Menu for(;;)##
```c
#include <iostream>

using namespace std;

  void menuProce (int &opcion){
    opcion=0;
    cout <<"\n\t\t------MENU-----" << endl
         <<"\n1.Salir"             << endl
         <<"\n2.Pares"             << endl
         <<"\n3.Impares"           << endl 
         <<"\n4.Signos"            << endl
         <<"\n5.Signos Cambiado"   << endl
         <<"\n\n\t Ingrese Opcion:" ;
            cin>>opcion;
            cin.clear(); 
            fflush(stdin);
}

    void doMain(){

    int opcion;{
    for (;;)
    {
         menuProce(opcion);
        switch (opcion)
        {
        case 1: exit(0);
            break;
        case 2: cout<<"Seleccionaste Pares";
            break;
        case 3: cout<<"Seleccionaste Impares";
            break;
        case 4: cout<<"Seleccionaste Signos";
            break;
        default:cout<<"Intenta de nuevo";
            break;
        }
         cout << endl << "Press any key to continue...";
        getchar();
       
       
    }
    }     
    
    }    
    int main()
    {
        doMain();

        return 0;
    }
```

Tip: Para realizar este tipo de procesos o menus es recomendable utilizar la funcion y el do es mas comodo 
```c
int menuoFun (){
    int opcion=0;
    cout <<"\n\t\t------MENU-----" << endl
         <<"\n1.Salir"             << endl
         <<"\n2.Pares"             << endl
         <<"\n3.Impares"           << endl 
         <<"\n4.Signos"            << endl
         <<"\n5.Signos Cambiado"   << endl
         <<"\n\n\t Ingrese Opcion:" ;
            cin>>opcion;
            cin.clear(); 
            fflush(stdin);

            return opcion;
}
```
Y el do-while
```c
 void doMain(){

    int opcion;{
    do
    {
        menuProce(opcion);
        switch (opcion)
        {
        case 1: exit(0);
            break;
        case 2: cout<<"Seleccionaste Pares";
            break;
        case 3: cout<<"Seleccionaste Impares";
            break;
        case 4: cout<<"Seleccionaste Signos";
            break;
        default:cout<<"Intenta de nuevo";
            break;
        }
         cout << endl << "Press any key to continue...";
        getchar();
       
       }while (true);
        
    }
    }
```
# **Archivos** 
El almacenamiento de informacion es la percistencia de datos y se utilizara [files]     
Forma de guardar txt,binario, json, etc...

```C
          string //(Escribe)
PEPE--->  fstream //(Tipo de dato de leer el archivo)(Lee)
```        
```
app=agragado               ]
int=modo lectura           ] 
out=escribe y sobreescribe ]---->ios_base (Palabra reserbada para abrir archivo)

eof=(hasta el ultima lectura del archivo y ahi termina)

crr=(Imprimir consola error)
```

Tenemos que tener en cuenta que para crear o leer el archivo como recomendacion creamos una carpeta adicional en el Workshop para poder direccionar el archivo *.txt que queramos leer o crear.

![datafiles](../Imagenes/Uno.png)
&nbsp;

### **Crear Archivo y Escribir Archivo**

*Aqui esta el codigo para Escribir cualquier Archivo al igual que puede crear un archivo en blanco sin comentamos el if
 
```C            
#include<iostream>
#include<fstream>
using namespace std;

void CrearArchivo (string pathFile){  // datefiles//listalumnos.txt
    string s;
    fstream f;

        cout <<"Escribiendo un archivo: "<< endl;
        f.open(pathFile, ios_base::app);

    if (f.is_open())
    {
       f <<"pepe lucho"<< endl;
       f <<"ana"<< endl;
       do
       {
        cout <<"(N Para salir) O escribe un nombre";
        cin>>s;
        if (s!="N")
            f <<s<<endl;
        
       } while (s!="N");
       
    }    
        
        f.close();
}
    int main(){
    CrearArchivo ("datafiles/Lista2Alumnos.txt"); // Aqui tenemos que tener en cuenta la direcion que seria "CARPETA CREADA/Nombre archivo *.txt creado"
    return 0;
}
```
Lo que hace esta codigo es del archivo que lee ingrasa nueva informacion sin borrar la anterior 
&nbsp;

# **LeerArchivo**

Con este procedimiento podemos solo Leer el archivo y podriamos implementar algo mas para que lo que esta en el documenta pueda imprimirlo en pantalla pero se presentara en otro codigo mas tarde.

```C
void LeerArchivo(string pathFile){
    string s;
    fstream f;
    f.open(pathFile, ios_base::in);
    if (!f.is_open())
    
        cout<<"Error de abrir el archivo."<<endl;
        else
        do
        {
            getline(f,s);
            cout<<s<<endl;
        } while (!f.eof());
    f.close();           
}

    int main(){
        LeerArchivo("datafiles/listadeAlumnos.txt");
    return 0;
}
```
&nbsp;
# **Matriz y strings conteo**

Ensta misma clase se examino dos codigos que a futuro tuvo que implementarse en el examen para darle un plus en caso de llegar a completar todo o como complemento

```c
void Matriz(int fc){

    int n=0;
    //int m[fc];
    int m[]={1,2,3,4,5};
    string hi="Hola pelad@s";
    string s;

    int len = sizeof(hi); 
    for (int i = 0; i < len; i++)
    {
        cout<<hi[i];
        usleep(90000);
    }
}
```
Consola 
![Lectura](../Imagenes/Dos.png)
**Lee caracter por caracter** y cuenta hasta el espacio, aparte tiene un linea donde esta el "usleep(9000);" que ayuda a que imprima con una velocidad lenta en pantalla.

Nota: Tenemos que utilizar esta libreria para poder implementar el "usleep(9000);" sin esta libreria no funcionara y nos dara error en esa linea de codigo 
```c
#include <unistd.h>
```

&nbsp;

Y finalmente la **barra de carga**
```c
void Loading()
{ 
    int ind =0;
    string c= "\\|/-|"; 
    for(int i=0; i<= 100; i++)
    {   
        //updateBar(i);
        if(i % 4 ==0)
            ind =0;
        cout    << "\r" << c[ind++]   
                << " " << i << "%";
        usleep(90000);
    }
}
```
Consola 
![](../Imagenes/tres.png)


Lo que hace es que va cargardo secuencialmente y el caracter que esta al principio va alternadose con otro caracter dando la ilusion que el caracter "/" esta girando.

&nbsp;
# **ESTRUCTURAS** 

Las estructuras son una forma de definir nuevos tipos de datos que pueden contener una o más variables de diferentes tipos. Para definir una estructura en C++, se utiliza la palabra clave struct seguida del nombre de la estructura y una lista de sus miembros entre llaves. Por ejemplo:

```C
struct Persona
{
    int edad;
    char nombre[20];
    float altura;
};
```
En este ejemplo, se define una estructura llamada Persona con tres miembros: edad de tipo entero, nombre de tipo char (un arreglo de caracteres con tamaño 20) y altura de tipo flotante.

Una vez definida la estructura, se pueden crear objetos de ella. Para hacerlo, se utiliza el nombre de la estructura seguido del nombre del objeto y se inicializan sus miembros entre llaves. Por ejemplo:

```c
Persona p1 = {25, "Juan", 1.80};
```
En este ejemplo, se crea un objeto de tipo Persona llamado p1 y se inicializan sus miembros con los valores 25, "Juan" y 1.80, respectivamente.

También se pueden acceder y modificar los miembros de un objeto de estructura utilizando el operador punto .. Por ejemplo:

```C
cout << p1.nombre << endl; // Imprime el valor del campo nombre del objeto p1.
p1.edad = 26; // Modifica el valor del campo edad del objeto p1.
```
&nbsp;
**EJERCICIO EN CLASE:**

```c
#include <iostream> 

using namespace std; 

struct Alumno // Define una estructura llamada Alumno con tres campos: id, edad y nombre.
{
    int id;
    int edad;
    char nombre[20];
};

int main()
{
    Alumno a1 = {1, 10, "pepe"}; // Crea un objeto de tipo Alumno llamado a1 e inicializa sus campos con los valores 1, 10 y "pepe", respectivamente.
    Alumno a2 = {6, 20, "luis"}; // Crea otro objeto de tipo Alumno llamado a2 e inicializa sus campos con los valores 6, 20 y "luis", respectivamente.
    Alumno list[] = {{1, 10, "pepe"}, {6, 20, "luis"}}; // Crea un arreglo de objetos de tipo Alumno llamado list con dos elementos, inicializados con los valores correspondientes.

    cout << endl << "[+]" 
        << endl << "-" << "id: " << a1.id 
        << endl << "-" << "edad: " << a1.edad 
        << endl << "-" << "nombre: " << a1.nombre; 

    for (int i = 0; i < 2; i++) // Inicia un bucle que itera dos veces.
    {
        cout << endl << "[+]" 
            << endl << "-" << "id: " << list[i].id 
            << endl << "-" << "edad: " << list[i].edad /
            << endl << "-" << "nombre: " << list[i].nombre;
    }
    
    return 0; 
```
Consola 
![](../Imagenes/Siete.png)

&nbsp;

# **PUNTEROS**

Los punteros en C++ son una característica avanzada del lenguaje que permiten a los programadores trabajar con direcciones de memoria. Un puntero es una variable que almacena la dirección de memoria de otra variable.

En C++, puedes crear un puntero usando el operador *. Por ejemplo, para crear un puntero a un entero llamado ptr, puedes usar la siguiente sintaxis:

```C
int* ptr;
```
Esta sintaxis declara una variable llamada ptr que es un puntero a un entero. Para asignar una dirección de memoria a un puntero, puedes utilizar el operador &. Por ejemplo, para asignar la dirección de memoria de una variable x a ptr, puedes usar la siguiente sintaxis:

```C
int x = 10;
int* ptr = &x;
```
Esta sintaxis asigna la dirección de memoria de x a ptr. Ahora, puedes acceder al valor de x a través de ptr utilizando el operador de indirección *. Por ejemplo:

```C
cout << *ptr << endl; // imprime el valor de x, que es 10
```
También puedes crear punteros a otros tipos de datos, como char, float, double, structs y clases. Además, puedes utilizar los punteros para pasar argumentos por referencia a funciones o para asignar memoria dinámicamente. Sin embargo, debes tener cuidado al trabajar con punteros, ya que pueden generar errores de segmentación si no se usan correctamente.

&nbsp;
**Ejemplo : Punteros**

```C
int main(){
    int i=10;
    int ii=20;
    new int(5); // dar un nuevo entero que crea un espacio de memoria pero no da referencia y no puede usar...
    cout << "i="<< i <<endl;

    // Declaración de un puntero 'pi' que apunta a la dirección de memoria de la variable 'i'
    int *pi;
    pi=&i;
    *pi=0;// Cambiar el valor de la variable 'i' a través del puntero 'pi'
    cout <<"i="<<i<< endl;

    pi=&ii;// Cambiar el puntero 'pi' para que apunte a la dirección de memoria de la variable 'ii'
    *pi=0;// Cambiar el valor de la variable 'ii' a través del puntero 'pi'

    cout<<"i="<<ii<< endl;
    cout <<"Ref_ii="<<ii<<endl;
    cout <<"*pi="<<*pi<<endl;

    return 0;
}
```
Consola
![punteros](../Imagenes/Cinco.png)
Este código utiliza punteros para acceder y modificar el valor de las variables i e ii. También se muestra cómo imprimir los valores de una variable y de un puntero. 

&nbsp;
**EJERCICIO CLASES :Memoria Punteros**
```c
    #include <iostream>

    using namespace std;
```
Para los punteros solo se utiliza la librerios iostream 

```c
int **crearMatrizMalloc(int f, int c)
{  
    int **m=NULL;
    m = (int **) malloc(f*sizeof(int *));
    for (int i = 0; i < f; i++)
        m[i] = (int *) malloc(c*sizeof(int));
        
    return m;
}
```
Esta es una función para crear una matriz utilizando la función malloc de C. Toma como parámetros el número de filas y columnas y devuelve un puntero a un puntero de enteros (un puntero a una matriz de enteros).

```c
int **crearMatrizCalloc(int f, int c)
{
    int **m=NULL;
    m = (int **) calloc(f, sizeof(int *));
    for (int i = 0; i < f; i++)
        m[i] = (int *) calloc(c, sizeof(int));
        
    return m;
}
```

Esta es una función para crear una matriz utilizando la función calloc de C. Toma como parámetros el número de filas y columnas y devuelve un puntero a un puntero de enteros (un puntero a una matriz de enteros). La diferencia con la función anterior es que la función calloc inicializa los elementos de la matriz a 0.


```c
int **crearMatrizNew(int f, int c)
{   
    int **m=NULL;
    m = new int*[f];
    for (int i = 0; i < f; i++)
        m[i] = new int[c];

    return m;
}
```
Esta es una función para crear una matriz utilizando el operador new de C++. Toma como parámetros el número de filas y columnas y devuelve un puntero a un puntero de enteros (un puntero a una matriz de enteros).

```c
void showMatriz(int **pd, int f,int c)
{
    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < c; j++)
            cout<< pd[i][j] <<"\t";   
        cout<< endl;
    }
}
```
Esta es una función para mostrar la matriz. Toma como parámetros un puntero a un puntero de enteros (la matriz), el número de filas y columnas.

```c
int main()
{
    int f = 0, c = 0;
    int **pd=NULL;

    cout<<"Ingresa fila y columnas de la matriz : ";
    cin>> f >> c;
    
    pd = crearMatrizNew(f,c);

    for (int i = 0; i < f; i++)
        for (int j = 0; j < c; j++)
            pd[i][j] = rand() % 10;  // genera randomicos hasta 10
        
    showMatriz(pd,f,c);
    return 0;
}
```
En la función principal, se pide al usuario que ingrese el número de filas y columnas de la matriz. Luego, se crea una matriz utilizando la función crearMatrizNew y se inicializa con números aleatorios utilizando la función rand(). Finalmente, se muestra la matriz utilizando la función showMatriz.

&nbsp;
Consola
![MemoriaMatrizas](../Imagenes/Seis.png)
Aqui podemos ver que en la consola va a pedir el Nro de Filas y Columnas para gerar numeros aleatorios del 0 al 9 de este modo podremos genrar cualquier matriz alterna sin necesidad de tener que pedir al usuario que llene cada an y am de la matriz de ser el caso.

&nbsp;

# **COLAS**
Explicacion de las colas

Para ello, se puede crear una estructura que represente la cola, indicando su tamaño máximo y los índices correspondientes al primer y último elemento de la cola:

```c
struct Cola {
    int tamanoMaximo;
    int* elementos;
    int primerIndice;
    int ultimoIndice;
};
```
En este ejemplo, tamanoMaximo indica el tamaño máximo de la cola, elementos es un puntero al arreglo que almacena los elementos de la cola, primerIndice es el índice del primer elemento de la cola y ultimoIndice es el índice del último elemento de la cola.

Luego, se puede implementar una función para inicializar la cola:

```c
void inicializarCola(Cola* cola, int tamano) {
    cola->tamanoMaximo = tamano;
    cola->elementos = new int[tamano];
    cola->primerIndice = 0;
    cola->ultimoIndice = -1;
}
```
En este procedimiento, se asigna el tamaño máximo de la cola, se reserva memoria para el arreglo que almacena los elementos, se establece el índice del primer elemento en 0 y el índice del último elemento en -1, indicando que la cola está vacía.

Para insertar un elemento en la cola, se puede implementar la función encolar:

```c
void encolar(Cola* cola, int elemento) {
    if (cola->ultimoIndice == cola->tamanoMaximo - 1) {
        std::cout << "La cola esta llena" << std::endl;
    } else {
        cola->ultimoIndice++;
        cola->elementos[cola->ultimoIndice] = elemento;
    }
}
```
En este procedimiento, se verifica si la cola está llena. Si no lo está, se incrementa el índice del último elemento y se inserta el elemento en el arreglo correspondiente.

Para eliminar un elemento de la cola, se puede implementar la función desencolar:

```c
void desencolar(Cola* cola) {
    if (cola->primerIndice > cola->ultimoIndice) {
        std::cout << "La cola esta vacia" << std::endl;
    } else {
        cola->primerIndice++;
    }
}
```
En este procedimiento, se verifica si la cola está vacía. Si no lo está, se incrementa el índice del primer elemento, indicando que se ha eliminado ese elemento de la cola.

Para acceder al primer elemento de la cola, se puede implementar la función verPrimerElemento:

```c
int verPrimerElemento(Cola* cola) {
    if (cola->primerIndice > cola->ultimoIndice) {
        std::cout << "La cola esta vacia" << std::endl;
        return -1;
    } else {
        return cola->elementos[cola->primerIndice];
    }
}
```
En esta función, se verifica si la cola está vacía. Si no lo está, se retorna el primer elemento de la cola.

**EJERCICIO EN CLASE: ENCOLAR,DESENCOLAR, MOSTRAR COLA ETC**
```C
#include <iostream>
using namespace std;

struct nodo              //  [ # ]>-->
{
    int nro;
    struct nodo *sgte;
};

struct cola             //  <--< >-->   
{
    nodo *delante;
    nodo *atras  ;
};

// El procedimiento encolar agrega un nuevo elemento al final de la cola
void encolar( struct cola &q, int valor )
{
     struct nodo *aux = new(struct nodo);  // se crea un nuevo nodo dinámicamente
     
     aux->nro = valor;  // se establece el valor del nodo
     aux->sgte = NULL;  // el nodo creado apunta al siguiente nodo con un puntero NULL
     
     // Si la cola está vacía, se establece el nodo creado como el primer nodo
     if( q.delante == NULL)
         q.delante = aux;   
     else
         // Si la cola no está vacía, se establece el puntero siguiente del último nodo
         (q.atras)->sgte = aux;
     // se establece el último nodo como el nodo recién creado
     q.atras = aux;        
}

// El procedimiento desencolar elimina el elemento del frente de la cola y devuelve su valor
int desencolar( struct cola &q )
{
     int num ;  // se almacena el valor del nodo a eliminar
     struct nodo *aux ;  // se utiliza un puntero auxiliar para eliminar el nodo
     
     aux = q.delante;      // aux apunta al inicio de la cola
     num = aux->nro;  // se obtiene el valor del primer nodo
     q.delante = (q.delante)->sgte;  // se establece el siguiente nodo como el primer nodo
     delete(aux);          // se libera la memoria del nodo eliminado
     
     return num;  // se devuelve el valor del nodo eliminado
}

// El procedimiento muestraCola imprime los elementos de la cola
void muestraCola( struct cola q )
{
     struct nodo *aux;
     aux = q.delante;
         
     while( aux != NULL )
     {
            cout<<"   "<< aux->nro ;
            aux = aux->sgte;
     }    
}

// El procedimiento vaciaCola elimina todos los elementos de la cola
void vaciaCola( struct cola &q)
{
     struct nodo *aux;
     
     while( q.delante != NULL)
     {
            aux = q.delante;
            q.delante = aux->sgte;
            delete(aux);
     }
     q.delante = NULL;
     q.atras   = NULL;
}

// La funcion menu muestra las opciones de la cola y devuelve la opción seleccionada
int menu()
{
    int op=0;
    system("cls");  // se limpia la pantalla
    cout<< endl <<"[...] COLAS          "
        << endl <<"  0.  SALIR          "
        << endl <<"  1.  ENCOLAR        "
        << endl <<"  2.  DESENCOLAR     "
        << endl <<"  3.  MOSTRAR COLA   "
        << endl <<"  4.  VACIAR COLA    "
        << endl <<"  5.  SALIR          "
        << endl <<"\n INGRESE OPCION:   ";
    cin>> op;  
    return op;
}
int main()
{
    struct cola q;
    q.delante = NULL;
    q.atras   = NULL;
   
    int dato;  // numero a encolar
    int x ;    // numero que devuelve la funcon pop
   
    system("color 0b");
    do
    {
        switch( menu() )
        {
            case 0: exit(0); 
            case 1:
                    cout<< "\n NUMERO A ENCOLAR: "; cin>> dato;
                    encolar( q, dato );
                    cout<<"\n\n\t\tNumero " << dato << " encolado...\n\n";
                    break;
            case 2:
                    x = desencolar( q );
                    cout<<"\n\n\t\tNumero "<< x <<" desencolado...\n\n";
                    break;
            case 3:
                    cout << "\n\n MOSTRANDO COLA\n\n";
                    if(q.delante!=NULL) muestraCola( q );
                    else   cout<<"\n\n\tCola vacia...!"<<endl;
                    break;
            case 4:
                    vaciaCola( q );
                    cout<<"\n\n\t\tHecho...\n\n";
                    break;
         }
        cout<<endl<<endl;
        system("pause");  
    }while(true);
    return 0;
}
```
Consola
![](../Imagenes/COLA%201.png)
Aqui encolamos el 7-8-2

![](../Imagenes/COLA%202.png)
Y aqui desencolamos y como vemos desencolo el 7 asi es como funcionana las colas, el primero en entrar es el primero en salir.

&nbsp;

&nbsp;
# **PILAS**
Una pila es una estructura de datos lineal que sigue una regla LIFO (Last In, First Out), lo que significa que el último elemento en entrar es el primero en salir.

En C++, una pila se puede implementar usando un arreglo o una lista enlazada. La operación principal en una pila es "push" (para agregar un elemento) y "pop" (para eliminar un elemento). 

EJERCICIO EN CLASE: PILAS 
```C
#include <iostream>
using namespace std;

// Definición de la estructura nodo
struct nodo{
    int nro;
    struct nodo *sgte;
};

// Definición de un tipo de dato puntero a un nodo
typedef nodo *ptrPila;

// Procedimiento para apilar un valor en la pila
void push(ptrPila &p, int valor) {      
    ptrPila aux = new(struct nodo);  // Creamos un nuevo nodo en memoria dinámica
    aux->nro = valor;                // Asignamos el valor al nuevo nodo

    aux->sgte = p;                   // El siguiente del nuevo nodo será la pila actual
    p = aux;                         // Actualizamos la pila con el nuevo nodo

    cout << "<< apilado >> " << endl; // Mensaje de confirmación
}

// Procedimiento para desapilar un valor de la pila
void pop(ptrPila &p) {
    ptrPila aux;

    aux = p;                         // Nodo auxiliar que apunta al inicio de la pila
    cout << "<< desapilado >> " << aux->nro << endl; // Mostramos el valor desapilado

    p = aux->sgte;                   // Actualizamos la pila eliminando el primer nodo
    delete(aux);                     // Liberamos la memoria del nodo eliminado
}

// Procedimiento para mostrar los valores de la pila
void mostrar_pila(ptrPila p) {
    ptrPila aux;
    aux = p;                         // Nodo auxiliar que apunta al inicio de la pila

    while(aux != NULL) {             // Recorremos la pila mientras haya nodos
        cout << "\t" << aux->nro << endl;  // Mostramos el valor del nodo
        aux = aux->sgte;             // Apuntamos al siguiente nodo
    }
}

// Procedimiento para eliminar todos los nodos de la pila
void destruir_pila(ptrPila &p) {
    ptrPila aux;

    while(p != NULL) {               // Mientras haya nodos en la pila
        aux = p;                     // Nodo auxiliar que apunta al inicio de la pila
        p = aux->sgte;               // Actualizamos la pila eliminando el primer nodo
        cout << "despachando: " << aux->nro << "\t"; // Mostramos el valor del nodo eliminado
        delete(aux);                 // Liberamos la memoria del nodo eliminado
    }

    cout << "\n\n\t\t Pila despachada...\n\n"; // Mensaje de confirmación
}

// Función para mostrar el menú de opciones y obtener la opción elegida
int menu() {
    int op;
    cout << endl;
    cout << " 1. APILAR                                " << endl;
    cout << " 2. DESAPILAR                             " << endl;
    cout << " 3. ELIMINAR PILA                         " << endl;
    cout << " 4. SALIR                                 " << endl;
    cout << "\n INGRESE OPCION: ";
    cin >> op;
    if(op == 4) exit(0);             // Salimos del programa si la opción es 4
    return op;                        // Devolvemos la opción elegida
}

int main() {
    ptrPila p = NULL;                 // Creamos una pila vacía
   

    int valor;
    int op;
   
    do
    {
        cout<<"\n\n    FUNCIONALIDAD PILA : \n";
        if(p==NULL)
            cout<<"\t << vacia >> ";
        else
            mostrar_pila( p );
        switch(menu())
        {
            case 1: cout<< "\n NUMERO A APILAR: "; cin>> valor;
                    push( p, valor );
                    break;
            case 2: pop( p );
                    break;
            case 3: destruir_pila( p );
                    break;
         }
    }while(op!=5);
    return 0;
}
```
Consola 

![pila](../Imagenes/Pila.png)

Como podemos ver en el impresion de consola ingresamos primero el 2 luego el 3 y al final el 5 

Y cuando desapilamos el primero en salir fue el 5 y ese numero fue el ultimo en ingresar. Asi que el codigo de Pila funciona excelente.

&nbsp;

&nbsp;

# **LISTAS**
En C++, una lista es una estructura de datos lineal que almacena una colección de elementos enlazados entre sí mediante punteros. Cada elemento, llamado nodo, consta de un valor y un puntero que apunta al siguiente nodo de la lista.

En clases se analizo 3 tipos de listas 

**1. Listas convencionales:**
Una lista convencional es una estructura de datos lineal que almacena elementos y tiene un puntero al siguiente elemento. No tiene ordenamiento ni clasificación de elementos, pero se pueden agregar o eliminar elementos y recorrer la lista en orden lineal.

**2. Listas ordenadas:**
Las listas ordenadas son estructuras de datos lineales similares a las listas convencionales, pero con la diferencia de que los elementos están ordenados en algún criterio específico, como orden ascendente o descendente. Al agregar un elemento a la lista ordenada, se inserta en su posición correspondiente según el orden definido, lo que significa que la lista siempre está en orden y puede ser recorrida de forma más eficiente.

**3. Listas circulares:**
Las listas circulares son un tipo especial de lista en la que el último elemento de la lista está conectado al primer elemento, creando así un bucle cerrado. Esto permite recorrer la lista en un ciclo continuo. Pueden ser convencionales o ordenadas, lo que significa que pueden o no tener algún tipo de ordenamiento o clasificación de los elementos.

**EJERCICIO EN CLASE: LISTA ORDENADA** 
```C
// Ordenamiento de burbuja en una lista de numeros : lista enlazada simple
#include <iostream>
#include <stdlib.h>
using namespace std;

// Definición de la estructura de un nodo de la lista enlazada simple
struct nodo{
       int nro;        // en este caso es un numero entero
       struct nodo *sgte;
};

typedef struct nodo *Tlista;// Definición del tipo de datos Tlista como un puntero a un nodo
Tlista inicio, fin;// Declaración de los punteros inicio y fin de la lista enlazada

// Procedimiento para generar una lista de n números aleatorios
void generarLista(Tlista &inicio, Tlista &fin, int n) 
{
     Tlista q, t;

     // Genera n nodos y los agrega a la lista enlazada
     for(int i = 0; i < n; i++)
     {
         // Creación del nuevo nodo
         q = new(struct nodo);
         q->nro = rand() % 51; // Genera un número aleatorio entre 0 y 50
         
         // Agrega el nodo al final de la lista
         if(inicio == NULL)
         {
              // Si la lista está vacía, el nuevo nodo es el inicio y el fin
              q->sgte = inicio;
              inicio = q;
              fin = q;          
         }
         else
         {
              // Si la lista ya tiene elementos, se agrega el nuevo nodo al final
              q->sgte = fin->sgte;
              fin->sgte = q;
              fin = q;
         }
     }
     cout << "\n\n\tLista de numeros generados... " << endl;
}

// Procedimiento para mostrar los elementos de la lista
void mostrarLista(Tlista inicio)
{
     // Recorre la lista y muestra cada elemento
     while(inicio != NULL)
     {
          cout << "  " << inicio->nro ;
          inicio = inicio->sgte;
     }
}

// Procedimiento para ordenar la lista enlazada con el algoritmo de ordenamiento de burbuja
void ordenarLista(Tlista lista)
{
     Tlista actual, siguiente;
     int t;
     
     // Recorre la lista y compara los elementos adyacentes para intercambiarlos si es necesario
     actual = lista;
     while(actual->sgte != NULL)
     {
          siguiente = actual->sgte;
          while(siguiente != NULL)
          {
               if(actual->nro > siguiente->nro)
               {
                    t = siguiente->nro;
                    siguiente->nro = actual->nro;
                    actual->nro = t;          
               }
               siguiente = siguiente->sgte;                    
          }    
          actual = actual->sgte;
          siguiente = actual->sgte;
     }
     cout << "\n\n\tLista ordenada..." << endl;
}


void menu()
{
    cout << "\n\t\tORDENAMIENTO BURBUJA EN LISTA ENLAZADA SIMPLE\n\n";
    cout << " 1. GENERAR NUMEROS                  " << endl;
    cout << " 2. MOSTRAR NUMEROS                  " << endl;
    cout << " 3. ORDENAR NUMEROS                  " << endl;
    cout << " 4. SALIR                            " << endl;
    cout << "\n INGRESE OPCION: ";
}

/*                        Funcion Principal
------------------------------------------------------------------*/
int main()
{
    inicio = NULL;
    fin    = NULL;
    
    int op;     // opcion del menu
    int num;   // elemenento a ingresar

    do
    {
        menu();  cin>> op;
        switch(op)
        {      
            case 1:
                 cout<< "\n Cantidad de numeros: "; cin>> num;
                 generarLista( inicio, fin, num );
                break;
            case 2:
                 cout<<"\n\n LISTA:\n\n";
                 mostrarLista( inicio );
                break;
            case 3:
                 ordenarLista( inicio );
                break;            
        }
        cout<<endl<<endl;
    }while(op!=4);
   return 0;
}
```
Consola 
![](../Imagenes/Lista%20Ordenada.png)
![](../Imagenes/Lista%20Ordenada%202.png)

Como podemos ver genera numero aleatorios y nos presenta. Pero como es este codigo es una lista que peude ordenar de forma ordenada cualquier generacion de numeros entonces lo podra hacer como se muestra al final de la segunda imagen.

Se tendria que presentar las demas lsitas y ver como funcionana, comentarlas. Pero por tema de no alargarme en el tema solo presentare esta, ya que el documento se volvera muy largo y demasiado extenso.

# **ARBOLES BINARIOS**

Un árbol binario es una estructura de datos en la que cada nodo tiene a lo sumo dos hijos y puede tener cero, uno o dos hijos. Los nodos que no tienen hijos son hojas y el nodo sin padre en la parte superior se llama raíz. Los árboles binarios se utilizan en diferentes aplicaciones como la implementación de árboles de búsqueda binarios, la representación de expresiones matemáticas y la organización jerárquica de información.


![](../Imagenes/Arbol%202.png)

**EJERCICIO: ARBOL BINARIO DE BUSQUEDA- Recorridos por amplitud por Orden, Pre-Orden y Post-Orden**

```C 
#include <iostream>
#include <cstdlib>
using namespace std;

// definición de la estructura del nodo
struct nodo{
     int nro;
     struct nodo *izq, *der;
};

typedef struct nodo *ABB;// definición del tipo ABB como un puntero a la estructura del nodo

// función para crear un nuevo nodo con un valor determinado
ABB crearNodo(int x)
{
     ABB nuevoNodo = new(struct nodo);
     nuevoNodo->nro = x;
     nuevoNodo->izq = NULL;
     nuevoNodo->der = NULL;

     return nuevoNodo;
}

// procedimiento para insertar un valor en el árbol de manera ordenada
void insertar(ABB &arbol, int x)
{
     if(arbol==NULL) // si el árbol está vacío, crea un nuevo nodo con el valor dado
     {
           arbol = crearNodo(x);
     }
     else if(x < arbol->nro) // si el valor es menor que el nodo actual, inserta en el subárbol izquierdo
          insertar(arbol->izq, x);
     else if(x > arbol->nro) // si el valor es mayor que el nodo actual, inserta en el subárbol derecho
          insertar(arbol->der, x);
}

// procedimiento para recorrer el árbol en preorden
void preOrden(ABB arbol)
{
     if(arbol!=NULL) // si el nodo actual no es nulo, muestra su valor y recorre sus subárboles
     {
          cout << arbol->nro <<" ";
          preOrden(arbol->izq);
          preOrden(arbol->der);
     }
}

// procedimiento para recorrer el árbol en orden
void enOrden(ABB arbol)
{
     if(arbol!=NULL) // si el nodo actual no es nulo, recorre su subárbol izquierdo, muestra su valor y recorre su subárbol derecho
     {
          enOrden(arbol->izq);
          cout << arbol->nro << " ";
          enOrden(arbol->der);
     }
}

// procedimiento para recorrer el árbol en postorden
void postOrden(ABB arbol)
{
     if(arbol!=NULL) // si el nodo actual no es nulo, recorre sus subárboles y muestra su valor al final
     {
          postOrden(arbol->izq);
          postOrden(arbol->der);
          cout << arbol->nro << " ";
     }
}

// procedimiento para visualizar el árbol en la consola
void verArbol(ABB arbol, int n)
{
     if(arbol==NULL) // si el árbol está vacío, retorna
          return;

     // recorre el subárbol derecho con un nivel de indentación mayor
     verArbol(arbol->der, n+1);

     // muestra el valor del nodo actual con la indentación correspondiente
     for(int i=0; i<n; i++)
         cout<<"   ";
     cout<< arbol->nro <<endl;

     // recorre el subárbol izquierdo con un nivel de indentación mayor
     verArbol(arbol->izq, n+1);
}

// función principal del programa
int main()
{
    ABB arbol = NULL;   // crea un árbol vacío


    int n;  // numero de nodos del arbol
    int x; // elemento a insertar en cada nodo

    cout << "\n\t\t  ..[ ARBOL BINARIO DE BUSQUEDA ]..  \n\n";

    cout << " Numero de nodos del arbol:  ";
    cin >> n;
    cout << endl;

    for(int i=0; i<n; i++)
    {
        cout << " Numero del nodo " << i+1 << ": ";
        cin >> x;
        insertar( arbol, x);
    }

    cout << "\n Mostrando ABB \n\n";  verArbol( arbol, 0);
    cout << "\n Recorridos del ABB";
    cout << "\n\n En orden   :  ";   enOrden(arbol);
    cout << "\n\n Pre Orden  :  ";   preOrden(arbol);
    cout << "\n\n Post Orden :  ";   postOrden(arbol);
    cout << endl << endl;
    return 0;
}
```
Consola
![arbol_binario2](../Imagenes/Arbol%20Binario.png)

&nbsp;
# **Automatas Finitos Deterministas**
Un Automata Finito Determinista (AFD) es un modelo matemático utilizado en la teoría de la computación que consiste en un conjunto finito de estados, un conjunto finito de símbolos de entrada, una función de transición que indica cómo cambiar de un estado a otro al leer un símbolo de entrada, un estado inicial y un conjunto de estados finales que indican cuándo se ha reconocido una cadena.

La función de transición del AFD especifica para cada par estado/símbolo de entrada el estado siguiente. Esto significa que el autómata se encuentra en un estado determinado y al leer un símbolo de entrada, realiza una transición a otro estado determinado. Es llamado determinista porque sólo puede estar en un estado determinado en cualquier momento, y la función de transición es determinística, lo que significa que para un estado y un símbolo de entrada dado, siempre hay un único estado siguiente posible.

Los AFD tienen importancia en la teoría de la computación, ya que se utilizan para definir lenguajes formales, que son el conjunto de todas las cadenas que pueden ser aceptadas por un autómata finito. Además, los AFD son ampliamente utilizados en la implementación de compiladores, intérpretes y otros sistemas de software que procesan y manipulan lenguajes formales.

**EJERCICIO DE COLOCAR 25ctvs y conseguir un chocolate (Si ingresa otra moneda la maquina no lo aceptara y no lo devolvera)**
```c
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdlib.h>
#define MAX 100
using namespace std;

// Función para mostrar los estados del autómata
void MostrarEstados(vector<int> v){
    cout << "\n\n ESTADOS DEL AUTOMATA \n\n";
    for(int i=0; i<v.size(); i++){
        cout << " " << i <<"  -->  q" << v[i] << endl;
    }
}

// Función para ingresar el autómata
void IngresaAutomata(vector<int> &E, vector<char> &S, int T[MAX][MAX]){

    int numE;  // Numero de estados
    int numS;  // Numero de simbolos
    char c;

    // Generando estados
    cout << "\n Cantidad de Estados: ";
    cin >> numE;
    for(int i=0; i<numE; i++){
        E.push_back(i);  // Agregando el estado i al vector E
    }

    // Ingresando simbolos
    cout << "\n Cantidad de Simbolos: "; cin >> numS;
    cout << endl;
    for(int i=0; i<numS; i++){
        cout << "\t Simbolo " << i+1 << " : ";
        cin >> c;
        S.push_back(c);  // Agregando el símbolo c al vector S
    }
    sort(S.begin(),S.end());  // Ordenando los símbolos del vector S en orden ascendente

    // Ingresando tabla de transiciones
    cout << "\n INGRESE TABLA DE TRANSICIONES \n\n";
    for(int i=0; i<numE; i++){
        for(int j=0; j<numS; j++){
            cout << "\t T["<<i<<"]["<<j<<"] : ";
            cin >> T[i][j];  // Ingresando el valor de la transición para el estado i y símbolo j
        }
    }

    // Mostrando tabla de transiciones
    cout << "\n\n TABLA DE TRANSICIONES \n\n";
    for(int i=0; i<numE; i++){
        for(int j=0; j<numS; j++){
            cout << "\t" << T[i][j] << "  ";  // Mostrando el valor de la transición para el estado i y símbolo j
        }
        cout << endl;
    }
}


void menu(){
    cout << "\n\t\t AUTOMATA FINITO DETERMINISTA\n\n";
    cout << "\t 1. Ingresar Automata \n";
    cout << "\t 2. Verificar palabra              \n";
    cout << "\t 3. Salir                          \n";
    cout << "\t Ingrese opcion: ";
}

bool VerificarPalabra(vector<int> w, int T[MAX][MAX], int q0, vector<int>qf){

    int q, s;
    q = q0;
    bool EstadoVerificacion = false;

    // Para cada símbolo de la palabra w, se realiza una transición en el AFD
    for(int i=0; i<w.size(); i++){
        s = w[i];
        q = T[q][s];
    }

    // Se verifica si el estado final q es uno de los estados finales del AFD
    for(int i=0; i<qf.size(); i++){
        if(q==qf[i]){
            EstadoVerificacion = true;
            break;
        }
    }
    return EstadoVerificacion;
}

void ConvertirPalabra(string palabra, vector<char>S, vector<int>&w){

    int i, k=0;

    // Se convierte cada símbolo de la palabra en un número entero que representa el índice del símbolo en el vector S
    while(w.size()!=palabra.length()){
        for(i=0; i<S.size(); i++){
            if(palabra[k]==S[i]){
                w.push_back(i);
            }
        }
        k++;
    }
}
/*                  Funcion Principal
--------------------------------------------------------------*/
int main()
{
    vector<int> Estados;
    vector<char> Simbolos;
    int Transiciones[MAX][MAX];
    int q0;              // Estado inicial
    vector<int>qf;       // Estados finales
    vector<int>w;
    bool AutomataIngresado = false;  // Aun no se ha ingresado automata

    int op, temp, tam;

    do{
        menu(); cin>>op;

        switch(op){

            case 1:
                Estados.clear();
                Simbolos.clear();
                qf.clear();

                IngresaAutomata(Estados, Simbolos, Transiciones);
                MostrarEstados(Estados);

                cout << "\n Ingrese estado inicial: ";
                cin >> q0;

                cout << "\n Cuantos de estados finales hay?: ";
                cin >> tam;

                cout << endl;
                for(int i=0; i<tam; i++){
                    cout << "\t Numero de estado final: ";
                    cin >> temp;
                    qf.push_back(temp);
                }

                AutomataIngresado = true;
                break;

            case 2:

                if(AutomataIngresado){
                    string palabra;
                    w.clear();
                    bool EstadoVerificacion = false;
                    cout << "\n Ingrese palabra: ";
                    cin>> palabra;

                    ConvertirPalabra(palabra, Simbolos, w);

                    EstadoVerificacion = VerificarPalabra(w, Transiciones, q0, qf);

                    if(EstadoVerificacion){
                        cout << "\n\t Palabra aceptada \n\n";
                    }
                    else{
                        cout << "\n\t Palabra no aceptada \n\n";
                    }
                }
                else{
                   cout << "\n Automata no ingresado..! \n";
                }

                break;

            case 3:
                exit(0);

            default:
                cout << "\n\tOpcion incorrecta..!\n";
        }

        cout << "\n\n"; system("pause"); system("cls"); //Esto es para que cuando se genero algun error ya sea al ingresar un caracter que no sea un numero o algo similar, simplemente va a limpiar la consola y vovler a presentar el menu. Asi no habra ningun  bug o se caera el programa.

    }while(op!=3);
}
```
Consola 
![automata](../Imagenes/AUTOMATA.png)

Como podemos ver aqui a= 25ctvs y la plabra es aceptada osea la llegamos al estado de aceptacion en el cual la maquina podra darnos nuestro chocolate 


![automata_noaceptado](../Imagenes/AUTOMATA%202.png)

Aqui como podemos ver si utlizamos la secuencia ab= 25 + 50 ctvs no podra llegar a un estado de aceptacion por lo cual simplemente la maquina dira que no es aceptado esa convinacion y se quedara con el dinero.
