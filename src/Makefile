LesCaentractes: $(OBJ_DIR)/mainPilote.o $(OBJ_DIR)/track/track.o $(OBJ_DIR)/dijkstra/dijkstra.o $(OBJ_DIR)/utils/utils.o $(OBJ_DIR)/utils/list.o $(OBJ_DIR)/utils/array.o $(OBJ_DIR)/dijkstra/speed.o $(OBJ_DIR)/utils/follow_line.o
	$(CC) $^ -o $(BIN_DIR)/$@ -lm
	cp $(BIN_DIR)/$@ ../GrandPrix2023_4.0.3/drivers/
	
$(BIN_DIR)/prog: $(OBJ_DIR)/main.o $(OBJ_DIR)/track/track.o $(OBJ_DIR)/dijkstra/dijkstra.o $(OBJ_DIR)/utils/utils.o $(OBJ_DIR)/utils/list.o $(OBJ_DIR)/utils/array.o $(OBJ_DIR)/dijkstra/speed.o $(OBJ_DIR)/utils/follow_line.o
	$(CC) $^ -o $@ -lm

$(OBJ_DIR)/main.o: src/main.c
	$(CC) -g  $(CPPFLAGS) $< -o $@ -c

$(OBJ_DIR)/mainPilote.o: src/mainPilote.c
	$(CC) $(CFLAGS)  $(CPPFLAGS) $< -o $@ -c
