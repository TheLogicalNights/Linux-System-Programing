buid:
	cc File.c -o File
	cc Process.c -o Process

run:
	./Process ${ARGS} 

help:
	@echo Use : \<make build\> to build project
	@echo Use : \<make ARGS=\"file_name\" run\> to execute project  
	@echo Use : \<make help\> for help
	@echo Use : \<make clean\> remove executable
	
clean:
	rm Process
	rm File
