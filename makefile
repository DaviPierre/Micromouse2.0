run: 
	clear
	gcc -o exe main.c
	./exe

run-grafo:
	clear
	gcc -o exe grafo.c
	./exe

run-grafo2:
	clear
	gcc -o exe main2.c
	./exe

commit:
	git add .
	git commit -m "Commit automático"
	git push