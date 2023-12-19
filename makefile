run: 
	clear
	gcc -o exe main.c
	./exe

run-grafo:
	clear
	gcc -o exe grafo.c
	./exe


commit:
	git add .
	git status
	git commit -m "Commit automático DaviPierre"
	git push