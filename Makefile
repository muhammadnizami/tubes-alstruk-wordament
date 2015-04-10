bin/Wordament: obj obj/arraymengecil.o obj/game.o obj/jam.o obj/main.o obj/mainmenu.o obj/mesinkar1.o obj/mesinkata1.o obj/multilistv5.o obj/prepmenu.o obj/priority_queue.o obj/queuelist.o obj/tanggal.o obj/waktu.o obj/score.o obj/_string.o obj/point.o obj/stackkar.o obj/stackpoint.o obj/matchar.o obj/matbool.o obj/statusboard.o obj/set.o
	gcc obj/arraymengecil.o obj/game.o obj/jam.o obj/main.o obj/mainmenu.o obj/mesinkar1.o obj/mesinkata1.o obj/multilistv5.o obj/prepmenu.o obj/priority_queue.o obj/queuelist.o obj/tanggal.o obj/waktu.o obj/score.o obj/_string.o obj/point.o obj/stackkar.o obj/stackpoint.o obj/matchar.o obj/matbool.o obj/statusboard.o obj/set.o -lm -o bin/Wordament

obj:
	mkdir obj

obj/arraymengecil.o: obj src/ADT\ Array\ Terurut\ Mengecil/arraymengecil.c src/ADT\ Array\ Terurut\ Mengecil/arraymengecil.h
	gcc -c src/ADT\ Array\ Terurut\ Mengecil/arraymengecil.c -o obj/arraymengecil.o

obj/game.o: obj src/game.c src/game.h
	gcc -c src/game.c -o obj/game.o

obj/jam.o: obj src/ADT\ Jam\ +\ Tanggal/jam.c src/ADT\ Jam\ +\ Tanggal/jam.h
	gcc -c src/ADT\ Jam\ +\ Tanggal/jam.c -o obj/jam.o

obj/main.o: obj src/main.c
	gcc -c src/main.c -o obj/main.o

obj/mainmenu.o: obj src/mainmenu.c src/mainmenu.h
	gcc -c src/mainmenu.c -o obj/mainmenu.o

obj/mesinkar1.o: obj src/ADT\ Mesin\ Kata/mesinkar1.c src/ADT\ Mesin\ Kata/mesinkar1.h
	gcc -c src/ADT\ Mesin\ Kata/mesinkar1.c -o obj/mesinkar1.o

obj/mesinkata1.o: obj src/ADT\ Mesin\ Kata/mesinkata1.c src/ADT\ Mesin\ Kata/mesinkata1.h
	gcc -c src/ADT\ Mesin\ Kata/mesinkata1.c -o obj/mesinkata1.o

obj/multilistv5.o: obj src/ADT\ Multi\ List/multilistv5.c src/ADT\ Multi\ List/multilistv5.h
	gcc -c src/ADT\ Multi\ List/multilistv5.c -o obj/multilistv5.o

obj/prepmenu.o: obj src/prepmenu.c src/prepmenu.h
	gcc -c src/prepmenu.c -o obj/prepmenu.o

obj/priority_queue.o: obj src/ADT\ Priority\ Queue/priority_queue.c src/ADT\ Priority\ Queue/priority_queue.h
	gcc -c src/ADT\ Priority\ Queue/priority_queue.c -o obj/priority_queue.o

obj/queuelist.o: obj src/ADT\ Queue/queuelist.c src/ADT\ Queue/queuelist.h
	gcc -c src/ADT\ Queue/queuelist.c -o obj/queuelist.o

obj/tanggal.o: obj src/ADT\ Jam\ +\ Tanggal/tanggal.c src/ADT\ Jam\ +\ Tanggal/tanggal.h
	gcc -c src/ADT\ Jam\ +\ Tanggal/tanggal.c -o obj/tanggal.o

obj/waktu.o: obj src/ADT\ Jam\ +\ Tanggal/waktu.c src/ADT\ Jam\ +\ Tanggal/waktu.h
	gcc -c src/ADT\ Jam\ +\ Tanggal/waktu.c -o obj/waktu.o

obj/score.o: obj src/ADT\ Map/score.c src/ADT\ Map/score.h
	gcc -c src/ADT\ Map/score.c -o obj/score.o

obj/_string.o: obj src/String/_string.c src/String/_string.h
	gcc -c src/String/_string.c -o obj/_string.o

obj/point.o: obj src/ADT\ Point/point.c src/ADT\ Point/point.h
	gcc -c src/ADT\ Point/point.c -o obj/point.o

obj/stackkar.o: obj src/ADT\ Stack/stackkar.c src/ADT\ Stack/stackkar.h
	gcc -c src/ADT\ Stack/stackkar.c -o obj/stackkar.o

obj/stackpoint.o: obj src/ADT\ Stack/stackpoint.c src/ADT\ Stack/stackpoint.h
	gcc -c src/ADT\ Stack/stackpoint.c -o obj/stackpoint.o

obj/matchar.o: obj src/ADT\ Matriks/matchar.c src/ADT\ Matriks/matchar.h
	gcc -c src/ADT\ Matriks/matchar.c -o obj/matchar.o

obj/matbool.o: obj src/ADT\ Matriks/matbool.c src/ADT\ Matriks/matbool.h
	gcc -c src/ADT\ Matriks/matbool.c -o obj/matbool.o

obj/statusboard.o: obj src/statusboard.c src/statusboard.h
	gcc -c src/statusboard.c -o obj/statusboard.o

obj/set.o: obj src//ADT\ Set/set.c src//ADT\ Set/set.h
	gcc -c src//ADT\ Set/set.c -o obj/set.o
