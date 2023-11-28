# so_long_v3

## Maps
* Les fichiers de maps seront lu de maniere classique (que des `0` et `1`) si seul la map est donée en parametre.
* Si un deuxieme argument est donné apres la map, celui ci indique le nombre de caracteres utilisés pour représenter une case. Ci ce deuxieme parametre est entré, alors les nombres seront aussi lu en hexadecimal (`00` -> `ff`). Ceuls certains cas sont differents: Le joueur, les coins et l'exit. Ces cases ci seront représentés de la maniere suivante: `xP` (player) / `xC` (coins) / `xE` (exit)
