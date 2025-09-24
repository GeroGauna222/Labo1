# Clase: Introducción práctica a **Git** (formato `.md`)

> Nivel: principiantes (ideal para estudiantes que programan en C u otros lenguajes)  
> Duración sugerida: 2–3 horas con práctica guiada

---

## 1) ¿Qué es Git?

**Git** es un *sistema de control de versiones distribuido*. Te permite:
- Registrar la historia de tu código (**commits**).
- Volver a estados anteriores (**checkout/restore**).
- Trabajar en paralelo con ramas (**branches**).
- Colaborar con otros usando repositorios remotos (**GitHub, GitLab, etc.**).

**Distribuido** significa que *cada* copia del repo contiene la historia completa: podés trabajar sin internet y sincronizar después.

---

## 2) Conceptos clave (mapa mental)

- **Repositorio (repo)**: carpeta con un subdirectorio oculto `.git` que guarda todo el historial.
- **Staging Area (índice)**: “zona de preparación” antes de confirmar cambios.
- **Commit**: “foto” del proyecto + un mensaje descriptivo.
- **Rama (branch)**: línea de tiempo independiente (ej. `main`, `dev`, `feature/x`).
- **HEAD**: puntero a tu rama o commit actual.
- **Remoto (remote)**: versión hospedada del repo (ej. `origin` en GitHub).
- **Merge / Rebase**: integrar cambios entre ramas (fusionar / reescribir base).
- **.gitignore**: archivo que lista lo que Git **no** debe rastrear (builds, binarios, etc.).

```
Trabajo → (git add) → Staging → (git commit) → Historial de la rama
```

---

## 3) Instalación y configuración inicial

1. **Instalá Git** (Windows/Mac/Linux).  
2. Configurá tu identidad (una sola vez por máquina):
```bash
git config --global user.name "Tu Nombre"
git config --global user.email "tu.email@example.com"
git config --global init.defaultBranch main    # rama principal = main
git config --global core.autocrlf input        # recomendado en macOS/Linux
# En Windows podés usar: true (según equipo/proyecto)
```
3. Ver configuración:
```bash
git config --list
```

---

## 4) Flujo básico en local

### Crear o clonar
```bash
git init                           # Inicializa un repo en la carpeta actual
git clone <url>                    # Clona un repo remoto
```

### Estado, agregar y confirmar
```bash
git status                         # Ver qué cambió
git add archivo.c                  # Pasa archivo al staging
git add .                          # Pasa todo lo modificado al staging (con cuidado)
git commit -m "feat: agrega función suma()"
```

### Ver historial y diferencias
```bash
git log --oneline --graph --decorate --all
git diff                           # Cambios no staged
git diff --staged                  # Cambios staged vs último commit
```

### Recuperar archivos
```bash
git restore archivo.c              # Descarta cambios no staged
git restore --staged archivo.c     # Saca del staging
# Volver a un archivo de un commit previo:
git checkout <commit> -- archivo.c
```

---

## 5) Ramas y fusiones

### Crear, listar y cambiar
```bash
git branch                         # Lista ramas
git branch feature/algo            # Crea rama
git switch feature/algo            # Cambia a la rama (Git >= 2.23)
# (Alternativa clásica) git checkout feature/algo
```

### Mezclar ramas (merge)
```bash
git switch main
git merge feature/algo             # Fusiona cambios de feature/algo en main
```

Si hay **conflictos**:
1. Git marca archivos en conflicto (`<<<<<<<`, `=======`, `>>>>>>>`).
2. Editá, resolvé y probá.
3. `git add` los archivos resueltos.
4. `git commit` para finalizar el merge.

### Rebase (opcional, más avanzado)
```bash
git switch feature/algo
git rebase main                    # Reordena commits de feature sobre main
```
> **Regla de oro**: Rebase en ramas personales; evitá rebase sobre ramas compartidas.

---

## 6) Remotos: sincronización

### Agregar y consultar remotos
```bash
git remote add origin <url>
git remote -v
```

### Traer cambios
```bash
git fetch origin                   # Actualiza referencias remotas
git pull                           # = fetch + merge (de tu rama remota)
git pull --rebase                  # fetch + rebase (historial más lineal)
```

### Publicar cambios
```bash
git push -u origin main            # Sube main (y fija upstream)
git push                           # En adelante, push sin especificar remoto/rama
```

---

## 7) `.gitignore` (muy importante)

Ejemplo para **C** y proyectos con binarios/builds:
```
# Compilación C
*.o
*.obj
*.out
*.exe
*.dll
*.so
*.a
*.lib

# Carpetas típicas de build
/build/
/bin/
/obj/

# IDE/editores
.vscode/
*.code-workspace
*.swp
*.swo

# Code::Blocks (común en 1er año)
*.depend
*.layout
*.cbp.*
*.cbTemp
```
> Guardá esto en un archivo llamado `.gitignore` en la raíz del repo.

---

## 8) Etiquetas (tags) y versiones

```bash
git tag v1.0.0                     # tag ligero
git tag -a v1.0.0 -m "Primera versión"   # tag anotado
git push origin v1.0.0
git tag                            # listar
```

---

## 9) Deshacer y recuperar (seguro)

### Enmendar el último commit
```bash
git commit --amend                 # Cambia mensaje / agrega archivos olvidados
```

### Revertir (crea commit inverso, seguro en ramas compartidas)
```bash
git revert <commit>
```

### Reset (reescribe historia local — ¡cuidado!)
```bash
git reset --soft <commit>          # Mantiene cambios en staging
git reset --mixed <commit>         # Por defecto: saca del staging, deja cambios en el working dir
git reset --hard <commit>          # Borra todo hasta ese commit (irrecuperable si no conocés reflog)
```

### Stash (guardar cambios “en el bolsillo”)
```bash
git stash                          # Guarda cambios sucios
git stash list
git stash apply                    # Aplica pero conserva en la lista
git stash pop                      # Aplica y remueve de la lista
```

### Reflog (salvavidas)
```bash
git reflog                         # Muestra por dónde estuvo HEAD
# Podés recuperar commits “perdidos” si conocés su hash desde reflog
```

---

## 10) Buenas prácticas

- Commits **pequeños y atómicos**: una idea por commit.
- Mensajes con convención:
  - `feat: agrega validación de entrada`
  - `fix: corrige overflow en suma`
  - `docs: actualiza README`
  - `refactor: renombra funciones`
- Usá ramas por tarea/feature: `feature/calculo_rms`, `fix/overflow-int`.
- No commitees binarios ni secretos (contraseñas, tokens).
- Revisá con `git status` antes de cada commit.
- `pull --rebase` para evitar “commits de merge” triviales.

---

## 11) Git en proyectos de **C** (ejemplo mini flujo)

1. **Inicialización**
   ```bash
   git init
   echo "# Proyecto C: Calculadora" > README.md
   echo -e "*.o\n/build/\n*.exe" > .gitignore
   git add .
   git commit -m "chore: init proyecto C"
   ```

2. **Nueva funcionalidad**
   ```bash
   git switch -c feature/suma
   # editá suma.c, main.c
   git add suma.c main.c
   git commit -m "feat: agrega función suma() y pruebas básicas"
   ```

3. **Volver a main e integrar**
   ```bash
   git switch main
   git pull --rebase                 # si trabajás con remoto
   git merge feature/suma
   git push
   ```

---

## 12) Ejercicios propuestos (paso a paso)

1. **Mi primer repo**
   - Creá un repo local con `git init`.
   - Agregá `hola.c` que imprima “Hola Git”.
   - Hacé `add` y `commit` con un mensaje claro.
   - Mirá el historial con `git log --oneline`.

2. **Ramas**
   - Creá `feature/saludo-usuario`, modificá `hola.c` para pedir el nombre.
   - Commit.
   - Volvé a `main` y hacé un `merge`.
   - Simulá un conflicto editando la misma línea en `main` y en `feature/…`, resolvelo.

3. **Remotos**
   - Creá un repo vacío en GitHub/GitLab.
   - `git remote add origin <url>` y `git push -u origin main`.
   - Hacé cambios, `commit` y `push`.
   - Probá `git pull --rebase` después de cambiar algo directamente en el remoto (edición web).

4. **Stash y reflog**
   - Modificá 2 archivos, `git stash`.
   - Cambiá de rama y volvé; aplicá el stash.
   - Forzá un problema con `reset --hard` y recuperá con `git reflog`.

---

## 13) Solución de problemas comunes

- **`fatal: not a git repository`**  
  Estás fuera del repo. Andá a la carpeta correcta o corré `git init`.

- **`detached HEAD`**  
  Chequeaste un commit específico. Volvé a una rama: `git switch main`.

- **Conflictos de merge**  
  Editá archivos marcados `<<<<<<<`, resolvé y `git add` + `git commit`.

- **`non-fast-forward` al hacer push**  
  Tu remoto tiene commits nuevos. Hacé `git pull --rebase` y luego `git push`.

- **Archivos ignorados que ya están trackeados**  
  Agregá al `.gitignore`, luego:
  ```bash
  git rm -r --cached .
  git add .
  git commit -m "chore: aplica .gitignore"
  ```

---

## 14) Estrategias de ramas (resumen)

- **Trunk-Based** (simple): todos trabajan sobre `main` + ramas cortas por feature (merge rápido).
- **Git Flow** (más formal): `main`, `develop`, `feature/*`, `release/*`, `hotfix/*`.  
  Útil en equipos grandes; más ceremonia.

Para cursos/proyectos chicos, **Trunk-Based** con `feature/*` suele ser suficiente.

---

## 15) Hooks (extra)

Hooks viven en `.git/hooks/` y permiten automatizar tareas (formateo de código, tests) antes de un commit/push.  
Ej.: `pre-commit` para correr `clang-format` o tests unitarios.

---

## 16) Chuleta (cheat sheet)

```bash
# Inicio
git init | git clone <url>

# Estado e historial
git status
git log --oneline --graph --decorate --all
git diff [--staged]

# Staging y commits
git add <file> | git add .
git commit -m "mensaje"

# Ramas
git branch
git switch -c feature/x
git switch main
git merge feature/x

# Remotos
git remote -v
git push -u origin main
git pull --rebase

# Deshacer/recuperar
git commit --amend
git revert <commit>
git reset --soft|--mixed|--hard <commit>
git stash / git stash pop
git reflog

# Etiquetas
git tag -a v1.0.0 -m "release inicial"
git push origin v1.0.0
```

---

## 17) Glosario rápido

- **Commit**: confirmación de cambios con mensaje.  
- **Branch**: línea de trabajo paralela.  
- **Merge**: fusionar ramas.  
- **Rebase**: reescribir base de commits (historial lineal).  
- **Remote**: servidor con una copia del repo.  
- **HEAD**: “dónde estás parado” en el historial.  
- **Stash**: guardar cambios temporales.

---

## 18) Sugerencias para evaluación (ideas)

- Entregar un repo con:  
  - `README.md` con instrucciones.  
  - Al menos 2 ramas de features y sus merges.  
  - Uso de `.gitignore` correcto.  
  - Historial limpio (mensajes claros, commits pequeños).  
  - Un **tag** de versión (ej. `v0.1.0`).  

---

### Apéndice: ejemplo de **mensaje de commit** claro

```
feat(calculadora): agrega operación de multiplicación

- Implementa multiplicar(a, b) en calc.c
- Agrega pruebas en tests_calc.c
- Actualiza README con ejemplos de uso

Refs: #12
```

---

> **Tip final:** Practicá *mucho* con un repo de prueba. Rompé cosas (a propósito), mirá `git status`, `git log`, `git reflog` y vas a entender Git de verdad.
