# EJERCICIO 1: CINE AUTOMATIZADO
Un mini cine de barrio necesita un sistema para llevar el control de sus ventas
semanales.
Cada día, se pueden vender entradas para películas con distintos precios según el tipo de entrada:
- Entrada común: $1500
- Entrada 3D: $2500
- Entrada VIP: $4000

El programa debe funcionar durante 7 días y permitir:
- Registrar ventas del día (máximo 50 por día)
- Mostrar la recaudación por cada tipo de entrada hasta el momento
- Finalizar el día y pasar al siguiente. Todos los días se vende POR LO MENOS una entrada (no existe día sin ventas, la señora de la verdulería va todos los días sin falta a ver alguna peli!), así que ningún día se puede finalizar hasta que haya una venta

Al finalizar la semana se debe mostrar:
- Día con mayor recaudación.
- Total de entradas vendidas por tipo.
- Total recaudado semanalmente.

### Extra
El cine tiene la siguiente promo: todo aquel que compre una entrada VIP, se lleva un número aleatorio entre 1 y 1000 (incluidos) de rifa, al final de la semana se rifa un
 boleto dorado de cine, que les brinda acceso ilimitado a cualquier película. 
 Recordá: 
 - no pueden repetirse las rifas, no puede haber dos personas con el boleto '28' por ejemplo
 - Se rifa al finalizar la semana
 - Se decide al ganador aleatoriamente, no hace falta que haya ganador, pero se tiene que informar si alguien ganó o si tocó un boleto sin dueño.

---

# EJERCICIO 2: DUELISTA VIRTUAL LA LEYENDA DE AANG
Crear un juego en consola donde el usuario se enfrente a la computadora en un duelo de tipo la Leyenda de Aang
Cada jugador lanza un hechizo aleatorio: fuego, agua, viento, tierra, aire.
Reglas:
- Tierra vence a agua.
- Agua vence a fuego.
- Fuego vence a aire.
- Aire vence a tierra.
El juego consta de 5 rondas o hasta que alguien gane 3 duelos; se deben mostrar:
- Total de duelos ganados por el usuario.
- Total de victorias de la computadora.
- Cantidad de empates.
- Quién ganó en total.

---

# EJERCICIO 3: DECODIFICADOR INTERGALÁCTICO
ET volvió con nuevos mensajes cifrados, pero esta vez usa un cifrado distinto:
Cada letra es reemplazada por su anterior en el abecedario (z -> y, b -> a, a -> z, etc.). Pero además ET ya no lee minúsculas, aprendió mayúsculas y se olvidó las minusc, así que todo el mensaje debe pasarse a
mayúscula. Por otro lado , lo que esta cifrado como comas se decodifica como espacios, y lo cifrado como espacios se decodifica a la letra 'b' (es decir c->b, ' '->b y ','->' ').
El programa debe:
- Leer una palabra o frase.
- Transformar cada letra a su letra anterior (a -> z) y cumplir las otras dos reglas extra.
- Mostrar el mensaje decodificado.
