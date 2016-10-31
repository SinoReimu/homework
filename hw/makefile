ENTER_POINT = hw
FILE = hw
RES_DIR = no
G = g++

Default:
	@echo "[HINT] compiling..."
	@$(G) array.cpp do.cpp -o hw
	@echo "[COMPILE] compile finished"

run:
ifeq ("$(FILE)", "$(wildcard $(FILE))")
	@./hw
else
	@echo "[ERROR] hw不存在，正在调用make编译"
	@make
	@echo "[HINT] 编译完成，正在启动"
	@make run
	@echo -e "\n\n"
endif
