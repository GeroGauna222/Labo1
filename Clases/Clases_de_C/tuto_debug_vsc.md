# Tutorial de Debugging para archivo .c en VSCode con gcc

<img width="1915" height="1198" alt="Captura de pantalla 2025-10-04 083355" src="https://github.com/user-attachments/assets/25e05b23-9391-4ecf-883c-4e2b2653505f" />

*Suponiendo que ya tienen compilador funcionando...*

> Tenes VSCode con la extension instalada de C/C++ (desde el apartado **Extensiones** de VSCode) 

### Windows

```bash
gcc -v
gdb -v
```

<img width="1475" height="861" alt="imagen" src="https://github.com/user-attachments/assets/fb653314-698f-4d10-afd3-01f71a1cb4c9" />

Estan? Ahora que esten en tu path, $env:PATH en terminal Powershell, y tendrías que ver listada la ruta a gcc

### Mac

```bash
uname -m
xcode-select --install      # instalar para CommandLineTools (CLT)
xcode-select -p             # muestra la ruta (debería existir)
sudo xcodebuild -license    # aceptar licencia si te pide
which lldb
lldb --version

# (recomendado) Clang
which clang
clang --version

# (sino) GCC:
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
brew install gcc                        # instala gcc-14 (o la versión vigente)
which gcc-14                            # Apple Silicon: /opt/homebrew/bin/gcc-14
gcc-14 --version
```

No tengo Mac yo (Gero), por lo que esto lo resolví leyendo foros y demás... pero se supone que de esta manera es la más conveniente vía Mac
- uname es para el prox paso... si dice arm64 o x86_64 es lo que importa
- XCode es para tener el clang y LLDB
- Revisa si te aparece lldb... lo usarías en ambas alternativas
- El otro es un gestor de paquetes: Homebrew que se supone es de lo más usado en Mac. Lo usamos despues con brew para instalar gcc-14
- Si usan Clang y no gcc esto no lo hagan, no va a hacer falta
- En caso de usar Clang hace solo el chequeo de que lo tenes!!

---

### Ctrl + Shift + P --> C/C++ Config

**Win**:
- Compiler Path: el que tenes en path (de gcc)
- IntelliSense Mode: Windows-gcc-x64

**Mac**
- Compiler Path: el que tenes en path (gcc o clang)
- IntelliSense Mode:
  - uname -m te dio una respuesta: arm64 tenes un Apple Silicon (M1 M2 etc), x86_64 tenes un Intel
    - GCC: macos-gcc-arm64 (Apple Silicon) o macos-gcc-x64 (Intel)
    - Clang: macos-clang-x64 o macos-clang-arm64


<img width="1623" height="712" alt="imagen" src="https://github.com/user-attachments/assets/d9d0a682-b30a-4b2f-8182-80b6e271c9f5" />

Ahora proba poner un *breakpoint* (puntito rojo, haces click al lado del numero de line)

<img width="389" height="379" alt="Captura de pantalla 2025-10-04 083528" src="https://github.com/user-attachments/assets/b021a14d-98cb-4e84-844d-21f2b9199dc0" />

Anda a C/C++: Debug

<img width="503" height="265" alt="Captura de pantalla 2025-10-04 083638" src="https://github.com/user-attachments/assets/238aaba6-5fff-4417-bb05-93085209ecc6" />

Te va a crear una carpeta output (tiene el programa .exe) y desde terminal vas a poder ingresar datos (si en tu codigo pedis scanf getchar etc)

Vas a ver una barrita con unas opciones, esta **step over**, **continue**, **step out**, **stop**

<img width="1919" height="1143" alt="Captura de pantalla 2025-10-04 093415" src="https://github.com/user-attachments/assets/d81cedb8-233f-44a4-8a91-f5ce72ae112a" />

Nada... si vas al panel de la izquierda y vas al bichito tenes watches y variables... empezá a jugar!
