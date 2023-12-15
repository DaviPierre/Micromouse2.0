run: 
	clear
	gcc -o exe main.c
	./exe

run-grafo:
	clear
	gcc -o exe grafo.c
	./exe


commit:
	git add main.c makefile
	git commit -m "Commit automático DaviPierre"
	git push