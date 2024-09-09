# compilation : 
```
gcc compromising.c -o compromising -g -std=c99
```

what is the value on $eax at the end of the last call of other_compromising_function ?

answer : 
$eax = -6

soit on mets le flag étant FSIIECTF{-6}, ou alors on fait un petit script qui demande la réponse et renvoie le flag (protégé je suppose jsp comment on ferait ca)


# writeup : 

grâce a gdb :

```
gdb compromising 
disassemble main 
```

il faut comprendre qu'il y a 258 appels a other_compromising_function.

```
disassemble other_compromising_function    # on voit que il y a ~82 lignes dans la fonction 
break other_compromising_function:81 
run 
```

ici on arrive au premier appel : 
```gdb 
Starting program: /home/dziga/cyber/challenges_creation/test  
[Thread debugging using libthread_db enabled] 
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1". 
 
Breakpoint 2, other_compromising_function (x=-104 '\230') at test.c:12  
12	    x = (x + rand())%255; 
```
on continue les 257 appels restants : 

```
c 257
```

on est au dernier appel, on voit directement que x = -6 
(mais on sait pas forcément que c'est le $eax) 
donc on peut aussi faire :  
```
(gdb) p $eax
$1 = -6
```
ce qui donne la solution 




