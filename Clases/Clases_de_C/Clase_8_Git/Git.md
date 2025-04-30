# GIT
A la hora de programar, no sólo es importante el saber lo que uno está haciendo, el trabajo en equipo es importantiiiiisimo en este mundo 
(pocos son capaces de armar grandes aplicaciones solos). Uno tiene que saber acoplarse en un equipo de trabajo, y la comunicación a la hora de trabajar es fundamental. 
*Hoy en día*, no existe programador que no sepa trabajar con Git, pero esto es porque es una herramienta vital a la hora del trabajo grupal.

Imaginemos una app: un **chatbot**. Va a tener que haber programadores backend, frontend, algún FullStack, especialistas en Data Science, si es posible un arquitecto de software (dios quiera), y así podemos seguir...

Toooooda esta gente va a trabajar sobre un mismo proyecto, pero... cómo es esto posible? Gracias a **Git**

![image](https://github.com/user-attachments/assets/8f4359df-b5f7-4970-8113-ee4338caea8b)


*Git es una herramienta de **control de versiones** que te permite llevar un registro de todos los cambios que se hacen en el código*. 
Te permite volver atrás en el tiempo, y trabajar en equipo sin sobrescribir el trabajo ajeno mientras mantiene un historial claro de qué se hizo, cuándo y por quién (buchón **MAL**). 
Imaginémoslo como una máquina del tiempo para tus proyectos. 

Ojota, no lo pensemos como una linea de tiempo así recta y linda, es muchisisisimo más complejo (bue tampoco tanto). 
La imagen mental es la de un arbol: hay un código que es el principal, el *tronco*, a este se le llama **origin**; y de este salen ramas, las *branches*. 


# Instalación y configuración inicial

Descargamos Git desde [https://git-scm.com.](https://git-scm.com/downloads).

Usamos Git Bash (en Windows, viene con la descarga), Bourne Again SHell, en lugar del cmd de Windows. Con este podemos ejecutar comandos de git y de Linux. 
Si estas usando mac, el terminal común esta bien.

ahora... empecemos a jugar

escribimos en el terminal *git --version*, nos va a tener que aparecer la version, así sabemos que todo esta funcionando.

entonces, pasamos a configurar nuestra cuenta

antes, vamos a tirar un *git config -h*, la de h es de help, aiuda. Acá nos va a contar git lo que trae, qué podemos configurar, para los curiosos. 

Para los menos curiosos, directamente vayamos al punto:

```bash
git config --global user.name "Tu Nombre"
git config --global user.email "tu@email.com"
git config --global core.autocrlf #true si es windows, input si es mac 
```

ya configurado todo escribamos *pwd* y toquemos enter, este comando me va a decir dónde estoy parado en el sistema, y tendría que aparecerte
una ubicación */c/Users/algo*, por ejemplo. Si yo quisiera ahora moverme a otra carpeta adentro de este directorio 'algo' uso *ls* y enter para ver 
las carpetas que hay aca adentro, y despues, suponete que tengo esta carpeta algo_adentro_de_algo, entonces *cd algo_adentro_de_algo*. 
Ahora si haces de vuelta un pwd vas a leer */c/Users/algo/algo_adentro_de_algo*. Y si quiero vooooolver para atras un paso? *cd ..*

Ok, nos sabemos mover!!! Genial. Ahora creemos algo acá adentro:

```bash
mkdir workspace # creas una carpeta en donde estas, con 'rm nombre_de_archivo' borras algo
ls # la ves
cd workspace # te moves para esa carpeta
mkdir tucarpetadetrabajo # creas otra adentro
cd tucarpetadetrabajo # te metes ahi
git init # inicializaste un repositorio!!!
ls # no te va a aparecer nada, es una carpeta oculta el .git, por eso el . al ppio
ls -a # ahora la ves existia te dije; el . representa la carpeta misma, el .. el retroceso que ya vimos
cd .git
ls -a
cd ..
```

Ya sabemos entonces crear un repositorio, perfecto... qué es un repositorio? 

Un repositorio es el lugar donde vive tu proyecto: archivos, historial de cambios, configuraciones, etc. 
Podés tenerlo localmente (en tu computadora) o remotamente (como en GitHub, GitLab o Azure DevOps).

Vemos tambien en el bash que se lee en la derecha *(main)* ahora. Esta es la **branch** en la que estás parado. 
Supongamos que queremos crear otra rama, existe el comando *git checkout .b rama_nueva*. Con este creamos la rama ahora vas a ver que estas en (rama_nueva). 
Quiero volver a main? *git checkout main* y listo. Vas a ver que cada rama evoluciona a su ritmo, esto lo vamos a poder ver de maneras más visuales con lo que vamos a ir aprendiendo. 
Basicamente, lo que tiene esto de las ramas, es que **uno puede tener varias versiones de un mismo codigo**. 

# Ciclo básico de trabajo en Git

> Working Directory, Staging Area y Commits

- Working Directory: donde trabajás tus archivos. Esto es en local, en **tu** carpeta de **tu** compu, nadie se entera de qué haces acá

- Staging Area (o "stage"): área temporal donde preparás los archivos que querés guardar, no estan subidos, pero es como un paso previo a que llegue al repo. 
>> Lo que subamos aca lo podemos sacar si nos arrepentimos, y nunca se subió, nadie sabe nada. para llevar cambios a este punto se usa el comando *git add* seguido
del archivo que se cambió, o de un . lo que indica que todos los cambios los quiero llevar al stage. lo mismo, si quiero eliminar un archivo *git rm*.

>> Si me arrepenti entonces tengo el *git restore --staged <file>*

Si haces un *git status* podrías ver todos los archivos que se encuentran en stage, los que no estan comprometidos, etc. El status lo que hace es comparar lo que hay en el repo, 
en el stage y en tu carpeta de trabajo local.

- Commit: registra definitivamente esos cambios que estan esperando en stage en el repositorio, y va con un mensaje informativo asociado, "fixing bugs and cleaning code", por ejemplo.
Para hacer esto, *git commit -m "mensaje"*

Algunos comandos para visualizar los cambios desde el terminal que son un poco más amenos a la vista son *git diff*, *git diff --staged* y *git status -s*. 
Después tambien tenemos *git log*, cuya función es mostrar un historial de todos los commits hechos sobre esa rama en la que estamos parados. Si tengo varias ramas 
voy a poder ver el avance de cada rama. Si hice cambios en rama_nueva y quiero que mi main ahora sea igual a esa rama, parado en main tendré que hacer un *git merge rama_nueva*

**Todo esto sucede adentro de la carpeta que tiene en ella la .git, recordemos**

Hiciste el commit, okey, esto para un repo local alcanza. Pero ahora... supongamos lo obvio: que tu trabajo queres subirlo a la nube, en un repo remoto de (por ejemplo) GitHub. Necesito llevar este commit al servidor

# GitHub

GitHub es un lugar donde se hospeda el control de versiones de Git. Así como esta GitHub tenemos GitLab, BitBucket y otros. Pero bueno... GitHub es de Microsoft... 
y se volvió un tipo de CV del programador.

Creamos una cuenta, con nombre de usuario etc. Una vez lsito esto, ya en la cuenta vemos 3 opciones, una es *Learn hoe to use GitHub*. Pueden ir por ese camino si quieren, 
hoy vamos a empezar con un *Create a new repository*. Acá nos va a dar unas opciones: ponemos nombre, descripcion, si es publico/privado, bueno. 
El *Initialize this repo with*, y te muestra 3 cosas: README, .gitignore y license

### .gitignore
### README
### License

## Asociando el Repo
Ya pasando a la proxima etapa, nos va a mostrar una pantalla con varias cosas, entre ellas una URL, esta es la dirección del Repo. Nosotros lo que queremos hacer es comunicar 
el repo remoto que tenemos recién creado con el local, esto se logra vía la URL. Es más, el mismo GitHub te dá indicaciones de cómo hacerlo.

```bash
git remote add origin "URL"
```

## git push
![image](https://github.com/user-attachments/assets/94e75246-d489-4b3a-af1b-27f7d3ef75c2)

Ya asociamos los repos, perfecto, pero... no tiene nada el de GitHub... por qué? Porque aunque esté asociado, todos los commits guardados en local, 
no fueron subidos al servidor donde se hospeda el repo, en este caso GitHub. Para hacerlo se debe usar un comando que van a cansarse ded escuchar: *git push*

## git pull

## git clone

## Branches a fondo

![image](https://github.com/user-attachments/assets/124145fc-ad8d-4239-a1d3-9fe777dd0257)
